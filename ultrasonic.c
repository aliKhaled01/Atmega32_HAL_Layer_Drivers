/*
 * ultrasonic.c
 *
 *  Created on: Oct 17, 2021
 *      Author: lenovo
 */
#include "ultrasonic.h"

#include <util/delay.h>

#include "GPIO.h"
static uint8 flag;
static uint8 c;
static uint8 counter1,counter2,counter;
uint16 t1;
uint16 t2;
uint32 time;
void ULTRASONIC_Init(enULTRASONICE_NUMBER ultrasonic_number)
{
	Timer1_Init(TIMER1_NORMAL_MODE,FROM_PRESACLLING_8,OCRA_DISCONNECTED,OCRB_DISCONNECTED);
	Timer1_OVF_SetCallBack(FUNC_OVF);
	Timer1_ICU_SetCallBack(FUNC_ICU);
	switch(ultrasonic_number)
	{
	case ULTRASONIC1 :
		GPIO_InitPin(ULTRASONIC1_TRIGGER_PORT,ULTRASONIC1_TRIGGER_PIN,GPIO_OUTPUT);
		break;
	case ULTRASONIC2 :
		GPIO_InitPin(ULTRASONIC2_TRIGGER_PORT,ULTRASONIC2_TRIGGER_PIN,GPIO_OUTPUT);
		break;
	case ULTRASONIC3 :
		GPIO_InitPin(ULTRASONIC3_TRIGGER_PORT,ULTRASONIC3_TRIGGER_PIN,GPIO_OUTPUT);
		break;
	case ULTRASONIC4 :
		GPIO_InitPin(ULTRASONIC4_TRIGGER_PORT,ULTRASONIC4_TRIGGER_PIN,GPIO_OUTPUT);
		break;
	}

	GPIO_InitPin(ICU_PORT,ICU_PIN,GPIO_INPUT);

	//CONNECTED ON ICU
}

uint8 ULTRASONIC_GetDistance(enULTRASONICE_NUMBER ultrasonic_number,uint8* dis)
{
	uint8 distance;
	//TCNT1=0;  //INCASE OF ONLY ULTRASONICE USUES TIMER
	counter1=c;
	flag=0;
	ULTRASONIC_START(ultrasonic_number);
	Timer1_InputCaptureEdge(ICU_RISING_EDGE);
	Timer1_ICU_Interrupt_Enable();
	Timer1_OVInterrupt_Enable();
	if(flag==2)
	{
	counter2 = c;
	counter = counter2-counter1;
	time=(t2-t1)+((uint32)counter*65535);
	distance=time/58;
	*dis=distance;
	return 1;
	}
return 0;
}
void static ULTRASONIC_START(enULTRASONICE_NUMBER ultrasonic_number)
{

		switch(ultrasonic_number)
		{
		case ULTRASONIC1 :
			GPIO_WritePin(ULTRASONIC1_TRIGGER_PORT,ULTRASONIC1_TRIGGER_PIN,GPIO_HIGH);
			_delay_us(10);
			GPIO_WritePin(ULTRASONIC1_TRIGGER_PORT,ULTRASONIC1_TRIGGER_PIN,GPIO_LOW);
			break;
		case ULTRASONIC2 :
			GPIO_WritePin(ULTRASONIC2_TRIGGER_PORT,ULTRASONIC2_TRIGGER_PIN,GPIO_HIGH);
			_delay_us(10);
			GPIO_WritePin(ULTRASONIC2_TRIGGER_PORT,ULTRASONIC2_TRIGGER_PIN,GPIO_LOW);
			break;
		case ULTRASONIC3 :
			GPIO_WritePin(ULTRASONIC3_TRIGGER_PORT,ULTRASONIC3_TRIGGER_PIN,GPIO_HIGH);
			_delay_us(10);
			GPIO_WritePin(ULTRASONIC3_TRIGGER_PORT,ULTRASONIC3_TRIGGER_PIN,GPIO_LOW);
			break;
		case ULTRASONIC4 :
			GPIO_WritePin(ULTRASONIC4_TRIGGER_PORT,ULTRASONIC4_TRIGGER_PIN,GPIO_HIGH);
			_delay_us(10);
			GPIO_WritePin(ULTRASONIC4_TRIGGER_PORT,ULTRASONIC4_TRIGGER_PIN,GPIO_LOW);
			break;
		}

}
static void FUNC_ICU()
{
	if(flag==0)
	{

		t1=ICR1;
		flag=1;
		Timer1_InputCaptureEdge(ICU_FALLING_EDGE);


	}
	else if(flag==1)
	{
		t2=ICR1;
		flag=2;
		Timer1_InputCaptureEdge(ICU_RISING_EDGE);
		Timer1_ICU_Interrupt_Disable();
		Timer1_OVInterrupt_Disable();

	}
}
static void FUNC_OVF()
{
	c++;
}
