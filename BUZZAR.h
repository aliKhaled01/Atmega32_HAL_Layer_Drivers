/*
 * BUZZAR.h
 *
 *  Created on: Oct 1, 2021
 *      Author: lenovo
 */

#ifndef BUZZAR_H_
#define BUZZAR_H_
#include "STD_TYPES.h"
void BUZZAR_INIT(void);
/*
 * DESCRIPTION : INTIALIZE THE BUZZAR PC6
 */
void BUZZAR_TurnOn(void);

void BUZZAR_TurnOff(void);

void BUZZAR_Tone(float32 voice_time_period);
/*
 * input:uint8 voice_time_period (ms)
 * Description : Generates Tone with specific time period
 */

#endif /* BUZZAR_H_ */
