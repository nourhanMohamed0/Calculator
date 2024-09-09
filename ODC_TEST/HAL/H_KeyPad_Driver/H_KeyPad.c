/*
 * H_KeyPad.c
 *
 *  Created on: Sep 5, 2024
 *      Author: Nourhan Mohamed Hassan
 */
#include "H_KeyPad.h"
void H_keyPad_Init(){
	M_DIO_SetPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW_PIN0,OUTPUT);
	M_DIO_SetPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW_PIN1,OUTPUT);
	M_DIO_SetPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW_PIN2,OUTPUT);
	M_DIO_SetPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW_PIN3,OUTPUT);
	M_DIO_SetPinDirection(KEYPAD_COL_PORT,KEYPAD_COL_PIN4,INPUT);
	M_DIO_SetPinDirection(KEYPAD_COL_PORT,KEYPAD_COL_PIN5,INPUT);
	M_DIO_SetPinDirection(KEYPAD_COL_PORT,KEYPAD_COL_PIN6,INPUT);
	M_DIO_SetPinDirection(KEYPAD_COL_PORT,KEYPAD_COL_PIN7,INPUT);
	M_DIO_EnablPullup(KEYPAD_COL_PORT, KEYPAD_COL_PIN4);
	M_DIO_EnablPullup(KEYPAD_COL_PORT, KEYPAD_COL_PIN5);
	M_DIO_EnablPullup(KEYPAD_COL_PORT, KEYPAD_COL_PIN6);
	M_DIO_EnablPullup(KEYPAD_COL_PORT, KEYPAD_COL_PIN7);
}
void H_GetKeyPadPressed(u8 *value){
	u8 arr[4][4]={
			{'7','8','9','/'},
			{'4','5','6','*'},
			{'1','2','3','-'},
			{'A','0','=','+'}
	};

	u8 row=0,col=0;
	*value=NOT_PRESSED;
	u8 readVal;
	for(row=0;row<ROWS_NUMBER;row++){
		M_DIO_SetPinValue(KEYPAD_ROW_PORT,KEYPAD_ROW_PIN0,HIGH);
		M_DIO_SetPinValue(KEYPAD_ROW_PORT,KEYPAD_ROW_PIN1,HIGH);
		M_DIO_SetPinValue(KEYPAD_ROW_PORT,KEYPAD_ROW_PIN2,HIGH);
		M_DIO_SetPinValue(KEYPAD_ROW_PORT,KEYPAD_ROW_PIN3,HIGH);
		M_DIO_SetPinValue(KEYPAD_ROW_PORT,row,LOW);
		for(col=0;col<COL_NUMBER;col++){
			M_DIO_GetPinValue(KEYPAD_COL_PORT,col+COL_NUMBER,&readVal);
			if (readVal==0){
				*value=arr[row][col];
				break;
			}
	}
		if (readVal==0)
			break;

}

}
