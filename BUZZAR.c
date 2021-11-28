/*
 * BUZZAR.c
 *
 *  Created on: Oct 1, 2021
 *      Author: lenovo
 */
#include "BUZZAR.h"
#include "GPIO.h"
#include <util/delay.h>
void BUZZAR_INIT(void)
{
	GPIO_InitPin(GPIO_C,GPIO_PIN6,GPIO_OUTPUT);

}
void BUZZAR_TurnOn(void)
{
	GPIO_WritePin(GPIO_C,GPIO_PIN6,GPIO_HIGH);
}
void BUZZAR_TurnOff(void)
{
	GPIO_WritePin(GPIO_C,GPIO_PIN6,GPIO_LOW);
}
void BUZZAR_Tone(float32 voice_time_period)
{

	for(int i=0; i<1;i++)
			{
				GPIO_WritePin(GPIO_C,GPIO_PIN6,GPIO_HIGH);
				_delay_ms(voice_time_period);
				GPIO_WritePin(GPIO_C,GPIO_PIN6,GPIO_LOW);
				_delay_ms(voice_time_period);

			}
}
