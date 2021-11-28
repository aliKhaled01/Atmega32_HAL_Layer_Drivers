/*****************************************************
 *Author :Moatasem
 *Date:   12/10/2018
 *Version: v02
 *Brief: IR Module
 *******************************************************/
#ifndef HAL_IR_H_
#define HAL_IR_H_

#include "STD_Types.h"
#include "GPIO.h"

/**************************************/
#define IR_NUM1 12
#define IR_NUM2 24
#define IR_NUM3 94
#define IR_NUM4 8
#define IR_NUM5 28
#define IR_NUM6 90
#define IR_NUM7 66
#define IR_NUM8 82
#define IR_NUM9 74

#define  IR_PORT GPIO_D
#define IR_PIN   PIN_2
/**************************************/
void IR_init();
void IR_Enable();
uint8 IR_GetValue();
uint8 IR_GetAddress();
void IR_SetValue(int num);
#endif /* HAL_05_IR_IR_H_ */









