/*
 * keypad.h
 *
 *  Created on: Oct 8, 2021
 *      Author: lenovo
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "STD_TYPES.h"

#define KEYPAD_COLS 4
#define KEYPAD4X4   0
#define KEYPAD_TYPE KEYPAD4X4
//Configuration menu

#define KEYPAD_ROW1_PORT GPIO_C
#define KEYPAD_ROW1_PIN GPIO_PIN5
#define KEYPAD_ROW2_PORT GPIO_C
#define KEYPAD_ROW2_PIN GPIO_PIN4
#define KEYPAD_ROW3_PORT GPIO_C
#define KEYPAD_ROW3_PIN GPIO_PIN3
#define KEYPAD_ROW4_PORT GPIO_C
#define KEYPAD_ROW4_PIN GPIO_PIN2

#define KEYPAD_COL1_PORT GPIO_D
#define KEYPAD_COL1_PIN GPIO_PIN7
#define KEYPAD_COL2_PORT GPIO_D
#define KEYPAD_COL2_PIN GPIO_PIN6
#define KEYPAD_COL3_PORT GPIO_D
#define KEYPAD_COL3_PIN GPIO_PIN5
#define KEYPAD_COL4_PORT GPIO_D
#define KEYPAD_COL4_PIN GPIO_PIN3
#define NO_MATRIX_BUTTON_PRESSED  0x0f
/////////////

void keypad_Init();
uint8 keypad_GetChar();
static void Set_Col_High();
static void clear_one_col_for_each_loop(uint8 col_no);//public
static uint8 Get_Row_Value();
#endif /* KEYPAD_H_ */
