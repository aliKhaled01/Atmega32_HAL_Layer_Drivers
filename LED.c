/*
 * LED.c
 *
 *  Created on: Sep 26, 2021
 *      Author: lenovo
 */
#include "LED.h"
#include "GPIO.h"
#include <util/delay.h>
#include <stdarg.h>
uint8 LED_ON(enLED_COLOR color)
{
	uint8 ret;
	if(color>LED_RED)
	{
		ret=ERORR_FAIL;
	}
	else
	{
		ret = ERORR_SUCCESS;
		switch(color)
		{
		case LED_YELLWO:
			GPIO_InitPin(GPIO_A,GPIO_PIN6,GPIO_OUTPUT);
			GPIO_WritePin(GPIO_A,GPIO_PIN6,GPIO_HIGH);
			break;

		case LED_RED:
			GPIO_InitPin(GPIO_B,GPIO_PIN7,GPIO_OUTPUT);
			GPIO_WritePin(GPIO_B,GPIO_PIN7,GPIO_HIGH);
			break;

		case LED_GREEN:
			GPIO_InitPin(GPIO_A,GPIO_PIN4,GPIO_OUTPUT);
			GPIO_WritePin(GPIO_A,GPIO_PIN4,GPIO_HIGH);
			break;

		case LED_BLUE:
			GPIO_InitPin(GPIO_A,GPIO_PIN5,GPIO_OUTPUT);
			GPIO_WritePin(GPIO_A,GPIO_PIN5,GPIO_HIGH);
			break;
		}
	}
	return 	ret;
}
void LEDS_ON (uint8 no_of_leds,...)
{
	va_list ap;
	va_start(ap,no_of_leds);
	for(uint8 i=0;i<no_of_leds;i++)
	{
		enLED_COLOR color = va_arg(ap,enLED_COLOR);
		switch (color)
		{
		case LED_RED:

			GPIO_WritePin(GPIO_B,GPIO_PIN7,GPIO_HIGH);
			break;
		case LED_GREEN:

			GPIO_WritePin(GPIO_A,GPIO_PIN4,GPIO_HIGH);
			break;
		case LED_BLUE:

			GPIO_WritePin(GPIO_A,GPIO_PIN5,GPIO_HIGH);
			break;
		case LED_YELLWO:

			GPIO_WritePin(GPIO_A,GPIO_PIN6,GPIO_HIGH);
			break;
		}
	}

	va_end(ap);
}
uint8 LED_OFF(enLED_COLOR color)
{
	uint8 ret = ERORR_SUCCESS;
	switch(color)
	{
	case LED_YELLWO:
		GPIO_InitPin(GPIO_A,GPIO_PIN6,GPIO_OUTPUT);
		GPIO_WritePin(GPIO_A,GPIO_PIN6,GPIO_LOW);
		break;

	case LED_RED:
		GPIO_InitPin(GPIO_B,GPIO_PIN7,GPIO_OUTPUT);
		GPIO_WritePin(GPIO_B,GPIO_PIN7,GPIO_LOW);
		break;

	case LED_GREEN:
		GPIO_InitPin(GPIO_A,GPIO_PIN4,GPIO_OUTPUT);
		GPIO_WritePin(GPIO_A,GPIO_PIN4,GPIO_LOW);
		break;

	case LED_BLUE:
		GPIO_InitPin(GPIO_A,GPIO_PIN5,GPIO_OUTPUT);
		GPIO_WritePin(GPIO_A,GPIO_PIN5,GPIO_LOW);
		break;

	default:
		ret = ERORR_FAIL;
		break;
	}

	return 	ret;
}

uint8 LED_TOGGLE_HTL(enLED_COLOR color,uint16 delaytime)
{
	uint8 ret = ERORR_SUCCESS;
	switch(color)
	{
	case LED_YELLWO:
		GPIO_InitPin(GPIO_A,GPIO_PIN6,GPIO_OUTPUT);
		GPIO_WritePin(GPIO_A,GPIO_PIN6,GPIO_HIGH);
		_delay_ms(delaytime);
		GPIO_WritePin(GPIO_A,GPIO_PIN6,GPIO_LOW);
		break;

	case LED_RED:
		GPIO_InitPin(GPIO_B,GPIO_PIN7,GPIO_OUTPUT);
		GPIO_WritePin(GPIO_B,GPIO_PIN7,GPIO_HIGH);
		_delay_ms(delaytime);
		GPIO_WritePin(GPIO_B,GPIO_PIN7,GPIO_LOW);
		break;

	case LED_GREEN:
		GPIO_InitPin(GPIO_A,GPIO_PIN4,GPIO_OUTPUT);
		GPIO_WritePin(GPIO_A,GPIO_PIN4,GPIO_HIGH);
		_delay_ms(delaytime);
		GPIO_WritePin(GPIO_A,GPIO_PIN4,GPIO_LOW);
		break;

	case LED_BLUE:
		GPIO_InitPin(GPIO_A,GPIO_PIN5,GPIO_OUTPUT);
		GPIO_WritePin(GPIO_A,GPIO_PIN5,GPIO_HIGH);
		_delay_ms(delaytime);
		GPIO_WritePin(GPIO_A,GPIO_PIN5,GPIO_LOW);
		break;

	default:
		ret = ERORR_FAIL;
		break;
	}

	return 	ret;


}
uint8 LED_STATUS(enLED_COLOR color)
{
	uint8 ret;

	switch(color)
	{
	case LED_RED:
		GPIO_GetPin(GPIO_B,GPIO_PIN7,&ret);

		break;
	case LED_YELLWO:
		GPIO_GetPin(GPIO_A,GPIO_PIN6,&ret);
		break;
	case LED_BLUE:
		GPIO_GetPin(GPIO_A,GPIO_PIN5,&ret);
		break;
	case LED_GREEN:
		GPIO_GetPin(GPIO_A,GPIO_PIN4,&ret);
		break;


	}
	return ret;
}

void LED_OffAll(void)
{

	GPIO_InitPin(GPIO_A,GPIO_PIN6,GPIO_OUTPUT);
	GPIO_WritePin(GPIO_A,GPIO_PIN6,GPIO_LOW);
	GPIO_InitPin(GPIO_B,GPIO_PIN7,GPIO_OUTPUT);
	GPIO_WritePin(GPIO_B,GPIO_PIN7,GPIO_LOW);
	GPIO_InitPin(GPIO_A,GPIO_PIN4,GPIO_OUTPUT);
	GPIO_WritePin(GPIO_A,GPIO_PIN4,GPIO_LOW);
	GPIO_InitPin(GPIO_A,GPIO_PIN5,GPIO_OUTPUT);
	GPIO_WritePin(GPIO_A,GPIO_PIN5,GPIO_LOW);

}
void LED_TOGGLE(enLED_COLOR color)
{
	switch(color)
	{
	case LED_RED:
		GPIO_TogglePin(GPIO_B,GPIO_PIN7);

		break;
	case LED_YELLWO:
		GPIO_TogglePin(GPIO_A,GPIO_PIN6);
		break;
	case LED_BLUE:
		GPIO_TogglePin(GPIO_A,GPIO_PIN5);
		break;
	case LED_GREEN:
		GPIO_TogglePin(GPIO_A,GPIO_PIN4);
		break;


	}
}
void LED_Init(enLED_COLOR color)
{
	switch(color)
	{
	case LED_RED:
		GPIO_InitPin(GPIO_B,GPIO_PIN7,GPIO_OUTPUT);

		break;
	case LED_YELLWO:
		GPIO_InitPin(GPIO_A,GPIO_PIN6,GPIO_OUTPUT);
		break;
	case LED_BLUE:
		GPIO_InitPin(GPIO_A,GPIO_PIN5,GPIO_OUTPUT);
		break;
	case LED_GREEN:
		GPIO_InitPin(GPIO_A,GPIO_PIN4,GPIO_OUTPUT);
		break;


	}
}

