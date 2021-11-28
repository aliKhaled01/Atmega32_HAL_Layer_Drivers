/*
 * LED.h
 *
 *  Created on: Sep 26, 2021
 *      Author: lenovo
 */
#ifndef LED_H_
#define LED_H_
#include "STD_TYPES.h"
typedef enum
{
	 LED_YELLWO,LED_BLUE,LED_GREEN,LED_RED
}enLED_COLOR;
uint8 LED_ON(enLED_COLOR color);
/*
 * Name: void LED_ON(LED_COLOR color)
 * input:
 	 	 color LED_YELLWO,LED_BLUE,LED_GREEN,LED_RED
 * Output:
 	 	 ErorrState:
 	 	         ERORR_SUCSSES 1
 	 	         ERORR_FAIL    0
 * Description:
  	 	     TurnOnLed
 * log:
 	     	 v0 Released
 */

uint8 LED_OFF(enLED_COLOR color);
/*
 * Name: void LED_OFF(LED_COLOR color)
 * input:
 	 	 color LED_YELLWO,LED_BLUE,LED_GREEN,LED_RED
 * Output:
 	 	 ErorrState:
 	 	         ERORR_SUCSSES 1
 	 	         ERORR_FAIL    0
 * Description:
  	 	  TurnOffLed
 * log:
 	     	 v0 Released
 */
uint8 LED_OnAll(void);
/*
 * Name: LED_OnAll(void)
 * input:
 	 	 void
 * Output:
 	 	 ErorrState:
 	 	         ERORR_SUCSSES 1
 	 	         ERORR_FAIL    0
 * Description:
  	 	     TurnOnAllLeds
 * log:
 	     	 v0 Released
 */
void LED_OffAll(void);
/*
 * Name: LED_OffAll(void)
 * input:
 	 	 void
 * Output:
 	 	 ErorrState:
 	 	         ERORR_SUCSSES 1
 	 	         ERORR_FAIL    0
 * Description:
  	 	     TurnOffAllLeds
 * log:
 	     	 v0 Released
 */
uint8 LED_TOGGLE_HTL(enLED_COLOR color,uint16 delaytime);
void LEDS_ON(uint8 no_of_leds,...);
void LED_TOGGLE(enLED_COLOR color);
void LED_Init(enLED_COLOR color);

//void LED_INIT(LED_COLOR);
/*Description :
 	 	 	 LED_INIT GPIO_LEDPIN GPIO_OUTPUT
 *
 */
#endif /* LED_H_ */
