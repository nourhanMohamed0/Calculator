/*
 * H_LCD.c
 *
 *  Created on: Sep 5, 2024
 *      Author: Nourhan Mohamed Hassan
 */
#include <stdio.h>
#include "../H_LCD_Driver/H_LCD.h"
#include "../H_LCD_Driver/H_LCD_CFG.h"

void H_LCD_Init(){
#ifdef EIGHT_PINS_MODE
	M_DIO_SetPortDirection(LCD_DATA_PORT,ALL_PORT_OUTPUT);
	M_DIO_SetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
	M_DIO_SetPinDirection(LCD_EN_PORT,LCD_EN_PIN,OUTPUT);
	//wait 40 ms
	_delay_ms(100);
	//1. set Function_Set command
	H_LCD_sendCommand(FUNCTION_SET);
	_delay_ms(2);

	//2.send on/off instruction
	//H_LCD_sendCommand(0B00001111);
	H_LCD_sendCommand(DISPLAY_ON_CURSOR_OFF);
	_delay_ms(2);
	//3.clear display
	H_LCD_sendCommand(CLEAR_DISPLAY);
	_delay_ms(2);
	//4.send entry mood
	H_LCD_sendCommand(ENTRY_MODE);
#elif defined FOUR_PINS_MODE
	M_DIO_SetPinDirection(LCD_DATA_PORT, LCD_PIN4, OUTPUT);
	M_DIO_SetPinDirection(LCD_DATA_PORT, LCD_PIN5, OUTPUT);
	M_DIO_SetPinDirection(LCD_DATA_PORT, LCD_PIN6, OUTPUT);
	M_DIO_SetPinDirection(LCD_DATA_PORT, LCD_PIN7, OUTPUT);
	M_DIO_SetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
	M_DIO_SetPinDirection(LCD_EN_PORT,LCD_EN_PIN,OUTPUT);
	H_LCD_sendCommand(RETURN_HOME);
	_delay_ms(10);
	H_LCD_sendCommand(FUNCTION_SET);
	_delay_ms(1);
	H_LCD_sendCommand(DISPLAY_ON_CURSOR_OFF);
    _delay_ms(2);
    H_LCD_sendCommand(CLEAR_DISPLAY);
    	_delay_ms(2);
    	//4.send entry mood
    	H_LCD_sendCommand(ENTRY_MODE);
    	_delay_ms(2);
#endif

}
void H_LCD_sendData(u8 data){
#ifdef EIGHT_PINS_MODE
	//1. send data on data port
	M_DIO_SetPortValue(LCD_DATA_PORT,data);

	//2.set RS to high
	M_DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,HIGH);

	//3.send enable pulse
	M_DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(10);
	M_DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
#elif defined FOUR_PINS_MODE
		M_DIO_WriteHighNibble(LCD_DATA_PORT,data>>4);
		M_DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,HIGH);

		M_DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
		_delay_ms(10);
		M_DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);

		M_DIO_WriteHighNibble(LCD_DATA_PORT,data);
		M_DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,HIGH);
		M_DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
		_delay_ms(10);
		M_DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
		_delay_ms(1);
#endif



}
void H_LCD_sendCommand(u8 command){
#ifdef EIGHT_PINS_MODE
	//1. send data on data port
		M_DIO_SetPortValue(LCD_DATA_PORT,command);

		M_DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,LOW);

		//4.send enable pulse
		M_DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
		_delay_ms(10);
		M_DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
#elif defined FOUR_PINS_MODE
		M_DIO_WriteHighNibble(LCD_DATA_PORT,command>>4);
		M_DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,LOW);
		M_DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
		_delay_ms(10);
		M_DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
		M_DIO_WriteHighNibble(LCD_DATA_PORT,command);
		M_DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,LOW);
		M_DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
		_delay_ms(10);
		M_DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
		_delay_ms(1);
#endif

}
void H_LCD_sendString(const u8 *str){
	while(*str !='\0')
		H_LCD_sendData(*str++);
}
void H_changeCursorPlace(u8 row,u8 column){
	u8 place=0;
	if((row>2)||(row<1)||(column>16)||(column<1))
		place=ROW_ONE;
	else if (row==1)
		place=ROW_ONE+column-1;
	else if (row==2)
		place=ROW_TWO+column-1;
	H_LCD_sendCommand(place);
	_delay_ms(1);

}
void H_sendNumber(const u16 number){
	char buffer[6];
	sprintf(buffer,"%u",number);
	for (u8 i = 0; buffer[i] != '\0'; i++)
		H_LCD_sendData(buffer[i]); // Send each character to the LCD
}
