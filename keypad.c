///*
// * keypad.c
// *
// *  Created on: Oct 8, 2021
// *      Author: lenovo
// */
//#include "keypad.h"
//
//#include "GPIO.h"
//#include "STD_TYPES.h"
//static uint8 keypadchars[4][4] =
//{
//		{'1','2','3','-'},
//		{'4','5','6','*'},
//		{'7','8','9','/'},
//		{'X','0','#','+'}
//};
//void keypad_Init()
//{
//	//ROWS INPUT
//	GPIO_InitPin(KEYPAD_ROW1_PORT,KEYPAD_ROW1_PIN,GPIO_INPUT);
//	GPIO_InitPin(KEYPAD_ROW2_PORT,KEYPAD_ROW2_PIN,GPIO_INPUT);
//	GPIO_InitPin(KEYPAD_ROW3_PORT,KEYPAD_ROW3_PIN,GPIO_INPUT);
//	GPIO_InitPin(KEYPAD_ROW4_PORT,KEYPAD_ROW4_PIN,GPIO_INPUT);
//	//ROW ACTIVE PULL UP
//	GPIO_WritePin(KEYPAD_ROW1_PORT,KEYPAD_ROW1_PIN,GPIO_HIGH);
//	GPIO_WritePin(KEYPAD_ROW2_PORT,KEYPAD_ROW2_PIN,GPIO_HIGH);
//	GPIO_WritePin(KEYPAD_ROW3_PORT,KEYPAD_ROW3_PIN,GPIO_HIGH);
//	GPIO_WritePin(KEYPAD_ROW4_PORT,KEYPAD_ROW4_PIN,GPIO_HIGH);
//	// COL OUTPUTS
//	GPIO_InitPin(KEYPAD_COL1_PORT,KEYPAD_COL1_PIN,GPIO_OUTPUT);
//	GPIO_InitPin(KEYPAD_COL2_PORT,KEYPAD_COL2_PIN,GPIO_OUTPUT);
//	GPIO_InitPin(KEYPAD_COL3_PORT,KEYPAD_COL3_PIN,GPIO_OUTPUT);
//	GPIO_InitPin(KEYPAD_COL4_PORT,KEYPAD_COL4_PIN,GPIO_OUTPUT);
//
//
//}
//uint8 keypad_GetChar()
//{
//	uint8 col=0;
//	uint8 key =0;
//	uint8 row_total_value = 0x0f; //1111
//	for(col=0;col<KEYPAD_COLS;col++)
//	{
//		//set cols high
//		Set_Col_High();
//		clear_one_col_for_each_loop(col);
//		 row_total_value = Get_Row_Value();
//		if(row_total_value!=NO_MATRIX_BUTTON_PRESSED)  //any button pressed
//		{
//			while(Get_Row_Value()!=NO_MATRIX_BUTTON_PRESSED); //wait
//				break;
//		}
//	}
//	if(col==KEYPAD_COLS)
//	{
//		key=0;
//	}
//	else
//	{
//		switch(row_total_value)
//		{
//		case 0b1110 :row_total_value =0; break;
//		case 0b1101 :row_total_value =1; break;
//		case 0b1011 :row_total_value =2; break;
//		case 0b0111 :row_total_value =3; break;
//		}
//		key =keypadchars[row_total_value][col];
//	}
//	// switch cols rows
//
//	return key;
//
//}
//static uint8 Get_Row_Value()
//{
//	uint8 row_total_value=0;
//	uint8 row1_value=1;
//	uint8 row2_value=1;
//	uint8 row3_value=1;
//	uint8 row4_value=1;
//	GPIO_GetPin(KEYPAD_ROW1_PORT,KEYPAD_ROW1_PIN,&row1_value); //0
//	GPIO_GetPin(KEYPAD_ROW2_PORT,KEYPAD_ROW2_PIN,&row2_value); //1
//	GPIO_GetPin(KEYPAD_ROW3_PORT,KEYPAD_ROW3_PIN,&row3_value);//1
//	GPIO_GetPin(KEYPAD_ROW4_PORT,KEYPAD_ROW4_PIN,&row4_value);//1
//	row_total_value = row1_value|row2_value<<1|row3_value<<2|row4_value<<3;
//	return row_total_value ;
//
//}
//static void clear_one_col_for_each_loop(uint8 col_no)
//{
//	switch(col_no)
//	{
//	case 0:
//		GPIO_WritePin(KEYPAD_COL1_PORT,KEYPAD_COL1_PIN,GPIO_LOW);
//		break;
//	case 1:
//		GPIO_WritePin(KEYPAD_COL2_PORT,KEYPAD_COL2_PIN,GPIO_LOW);
//		break;
//	case 2:
//		GPIO_WritePin(KEYPAD_COL3_PORT,KEYPAD_COL3_PIN,GPIO_LOW);
//		break;
//	case 3:
//		GPIO_WritePin(KEYPAD_COL4_PORT,KEYPAD_COL4_PIN,GPIO_LOW);
//		break;
//	}
//
//}
//static void Set_Col_High()
//{
//#if KEYPAD_TYPE == KEYPAD4X4
//	GPIO_WritePin(KEYPAD_COL1_PORT,KEYPAD_COL1_PIN,GPIO_HIGH);
//	GPIO_WritePin(KEYPAD_COL2_PORT,KEYPAD_COL2_PIN,GPIO_HIGH);
//	GPIO_WritePin(KEYPAD_COL3_PORT,KEYPAD_COL3_PIN,GPIO_HIGH);
//	GPIO_WritePin(KEYPAD_COL4_PORT,KEYPAD_COL4_PIN,GPIO_HIGH);
//#endif
//}
//
//
//
//
////switch(i)
////	{
////	case 1:
////		switch(row_total_value)
////		{
////		case 0b1110: //col1 row1
////			key='1';
////			break;
////		case 0b1101:
////			key='4';
////			break;
////
////		case 0b1011:
////			key='7';
////			break;
////		case 0b0111:
////			key='X';
////			break;
////		}
////		break;
////		case 2:
////			switch(row_total_value)
////			{
////			case 0b1110: //col1 row1
////				key='2';
////				break;
////			case 0b1101:
////				key='5';
////				break;
////
////			case 0b1011:
////				key='8';
////				break;
////			case 0b0111:
////				key='0';
////				break;
////			}
////			break;
////			case 3:
////				switch(row_total_value)
////				{
////				case 0b1110: //col1 row1
////					key='3';
////					break;
////				case 0b1101:
////					key='6';
////					break;
////
////				case 0b1011:
////					key='9';
////					break;
////				case 0b0111:
////					key='#';
////					break;
////				}
////				break;
////				case 4:
////					switch(row_total_value)
////					{
////					case 0b1110: //col1 row1
////						key='+';
////						break;
////					case 0b1101:
////						key='-';
////						break;
////
////					case 0b1011:
////						key='*';
////						break;
////					case 0b0111:
////						key='/';
////						break;
////					}
////					break;
////	}
