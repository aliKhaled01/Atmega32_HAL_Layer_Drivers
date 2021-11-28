/*****************************************************
 *Author :Moatasem
 *Date:   12/10/2018
 *Version: v02
 *Brief: IR Module
 *******************************************************/
#include <string.h>
#include "IR.h"

#include "EXT_INT.h"
#include "Timers.h"

static volatile uint8 start_bit=0;
static volatile uint8 Frame_cnt=0;
volatile uint32 Frame[80]={0};
static volatile uint8 value=0;
static volatile uint8 address=0;
void Format_Response();
void Bit_Request();
static uint16 tick=0;
void IR_init()
{
	GPIO_init_pin(IR_PORT, IR_PIN, GPIO_INPUT);
}

void IR_Enable()
{
	stEXT_interrupt IR_signal;
	IR_signal.InterruptFunctionPtr=Bit_Request;//set function to callback function
	IR_signal.InterruptPinSelect=EXT_INTERRPUT_INT0_PD2;
	IR_signal.InterruptSenseControl=EXT_RISING_EDGE;//select type of edge detector
	EXT_InitInterrupt(&IR_signal);//call init function to prepared interrupt to use
	sei();
}
//32 bit
void Bit_Request()
{
	//	UART_SendByte('#');
	//UART_SendByte('@');
	if(start_bit==0)
	{
		//LCD_GoTo(2, 0);
		//LCD_WriteSentence("REC..START..BIT");
		Timer1_SetInterruptTime_us(7000,Format_Response);//1s
		start_bit=1;
	}
	else
	{
		//LCD_GoTo(3, 0);
		//LCD_WriteSentence("REC..Frame..BITs");
//		Frame[Frame_cnt]=(Get_Current_Timer1()*0.5)+(tick*1000);//13.5ms //2.25ms //1.25ms
		Frame[Frame_cnt]=Get_Current_Timer1()*64; //13.5ms //2.25ms //1.25ms

		Timer1_SetInterruptTime_us(7000,Format_Response);
		Frame_cnt++;

	}

}

void Format_Response(){


	//tick++;

	//UART_SendByte(tick+48);
	//if(tick==1000)//1 second
	{

		for(uint8 i=0;i<8;i++)
		{
			if(Frame[17+i]>= (uint32)2000&& Frame[17+i] <= (uint32)2500)
			{
				SET_BIT(value,i);
			}
			else
			{
				CLEAR_BIT(value,i);
			}

			if(Frame[1+i]>= (uint32)2000&& Frame[1+i] <= (uint32)2500)
			{
				SET_BIT(address,i);
			}
			else
			{
				CLEAR_BIT(address,i);
			}
		}
		if(Frame[0]!= 0)
		{
//			LCD_WriteNumber(Frame[0]);
//			LCD_GoTo(1, 0);
//			LCD_WriteNumber(Frame[17]);
//			LCD_WriteSentence(",");
//			LCD_WriteNumber(Frame[18]);
//			LCD_GoTo(2, 0);
//			LCD_WriteNumber(Frame[18]);
//			LCD_WriteSentence(",");
//			LCD_WriteNumber(Frame[20]);
//			LCD_GoTo(3, 0);
//			LCD_WriteNumber(Frame[21]);
//			LCD_WriteSentence(",");
//			LCD_WriteNumber(Frame[22]);
			start_bit=0;
			//memset((uint8*)Frame,0,sizeof(Frame));
		}
		tick=0;
		Frame_cnt=0;
	}
}


uint8 IR_GetValue(){
	return value;
}
uint8 IR_GetAddress(){
	return address;
}
void IR_SetValue(int num)
{
	memset((uint8*)Frame,0,sizeof(Frame));
	value=num;
	address=num;
}

/***********************************************/
// 1 -> 7866879
// 2- > 1573119
// 3 -> 6160639
// 4 -> 5245439
// 5 -> 1835263
// 6 -> 5898495
// 7 -> 4325631
// 8 -> 5374207
// 9 -> 4849919
/**********************************************/


