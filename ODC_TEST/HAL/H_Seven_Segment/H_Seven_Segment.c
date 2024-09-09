/*
 * H_Seven_Segment.c
 *
 *  Created on: Sep 5, 2024
 *      Author: Nourhan Mohamed Hassan
 */
#include "H_Seven_Segment.h"
#include "H_Seven_Segment_CFG.h"
ERROR_STATE_T H_SevenSegment_Init(u8 portName){
	ERROR_STATE_T retVal=NOK;
	switch(portName){
	case PORT_A:M_DIO_SetPortDirection(portName,ALL_PORT_OUTPUT); break;
	case PORT_B:M_DIO_SetPortDirection(portName,ALL_PORT_OUTPUT); break;
	case PORT_C:M_DIO_SetPortDirection(portName,ALL_PORT_OUTPUT); break;
	case PORT_D:M_DIO_SetPortDirection(portName,ALL_PORT_OUTPUT); break;
	retVal=OK;
	}
	return retVal;
}
ERROR_STATE_T H_SevenSegment_Write_Cathode(u8 data,u8 portName){
	u8 arrCathode[10]={
			0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X47,0X7F,0X6F
	};
	ERROR_STATE_T retVal=NOK;
	switch(portName){
	case PORT_A:M_DIO_SetPortValue(portName,*(arrCathode+data)); break;
	case PORT_B:M_DIO_SetPortValue(portName,*(arrCathode+data)); break;
	case PORT_C:M_DIO_SetPortValue(portName,*(arrCathode+data)); break;
	case PORT_D:M_DIO_SetPortValue(portName,*(arrCathode+data)); break;
	retVal=OK;
	}
	return retVal;
}
ERROR_STATE_T H_SevenSegment_Write_Anode(u8 data,u8 portName){
	u8 arrAnode[]={
	0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xB8,0x80,0x90
	};
	ERROR_STATE_T retVal=NOK;
	switch(portName){
	case PORT_A:M_DIO_SetPortValue(portName,*(arrAnode+data)); break;
	case PORT_B:M_DIO_SetPortValue(portName,*(arrAnode+data)); break;
	case PORT_C:M_DIO_SetPortValue(portName,*(arrAnode+data)); break;
	case PORT_D:M_DIO_SetPortValue(portName,*(arrAnode+data)); break;
	retVal=OK;
	}
	return retVal;
}

ERROR_STATE_T H_SevenSegment_BCD_Init_HighNibble(u8 portName){
	ERROR_STATE_T retVal=NOK;
		switch(portName){
		case PORT_A:
		M_DIO_SetPinDirection(PORT_A,PIN4,OUTPUT);
		M_DIO_SetPinDirection(PORT_A,PIN5,OUTPUT);
		M_DIO_SetPinDirection(PORT_A,PIN6,OUTPUT);
		M_DIO_SetPinDirection(PORT_A,PIN7,OUTPUT); break;
		case PORT_B:
		M_DIO_SetPinDirection(PORT_B,PIN4,OUTPUT);
		M_DIO_SetPinDirection(PORT_B,PIN5,OUTPUT);
		M_DIO_SetPinDirection(PORT_B,PIN6,OUTPUT);
		M_DIO_SetPinDirection(PORT_B,PIN7,OUTPUT); break;

		case PORT_C:
		M_DIO_SetPinDirection(PORT_C,PIN4,OUTPUT);
		M_DIO_SetPinDirection(PORT_C,PIN5,OUTPUT);
		M_DIO_SetPinDirection(PORT_C,PIN6,OUTPUT);
		M_DIO_SetPinDirection(PORT_C,PIN7,OUTPUT); break;

		case PORT_D:
		M_DIO_SetPinDirection(PORT_D,PIN4,OUTPUT);
		M_DIO_SetPinDirection(PORT_D,PIN5,OUTPUT);
		M_DIO_SetPinDirection(PORT_D,PIN6,OUTPUT);
		M_DIO_SetPinDirection(PORT_D,PIN7,OUTPUT); break;
		retVal=OK;
		}
		return retVal;
}
ERROR_STATE_T H_SevenSegment_BCD_Init_LowNibble(u8 portName){
	ERROR_STATE_T retVal=NOK;
		switch(portName){
		case PORT_A:
		M_DIO_SetPinDirection(PORT_A,PIN0,OUTPUT);
		M_DIO_SetPinDirection(PORT_A,PIN1,OUTPUT);
		M_DIO_SetPinDirection(PORT_A,PIN2,OUTPUT);
		M_DIO_SetPinDirection(PORT_A,PIN3,OUTPUT); break;
		case PORT_B:
		M_DIO_SetPinDirection(PORT_B,PIN0,OUTPUT);
		M_DIO_SetPinDirection(PORT_B,PIN1,OUTPUT);
		M_DIO_SetPinDirection(PORT_B,PIN2,OUTPUT);
		M_DIO_SetPinDirection(PORT_B,PIN3,OUTPUT); break;

		case PORT_C:
		M_DIO_SetPinDirection(PORT_C,PIN0,OUTPUT);
		M_DIO_SetPinDirection(PORT_C,PIN1,OUTPUT);
		M_DIO_SetPinDirection(PORT_C,PIN2,OUTPUT);
		M_DIO_SetPinDirection(PORT_C,PIN3,OUTPUT); break;

		case PORT_D:
		M_DIO_SetPinDirection(PORT_D,PIN0,OUTPUT);
		M_DIO_SetPinDirection(PORT_D,PIN1,OUTPUT);
		M_DIO_SetPinDirection(PORT_D,PIN2,OUTPUT);
		M_DIO_SetPinDirection(PORT_D,PIN3,OUTPUT); break;
		retVal=OK;
		}
		return retVal;
}

ERROR_STATE_T H_SevenSegment_BCD_HighNibble_Write(u8 portName,u8 data){
	ERROR_STATE_T retVal=NOK;
	switch(portName){
	case PORT_A:M_DIO_WriteHighNibble(portName,data); break;
	case PORT_B:M_DIO_WriteHighNibble(portName,data); break;
	case PORT_C:M_DIO_WriteHighNibble(portName,data); break;
	case PORT_D:M_DIO_WriteHighNibble(portName,data); break;
	retVal=OK;
	}
	return retVal;
}
ERROR_STATE_T H_SevenSegment_BCD_LowNibble_Write(u8 portName,u8 data){
	ERROR_STATE_T retVal=NOK;
	switch(portName){
	case PORT_A:M_DIO_WriteLowNibble(portName,data); break;
	case PORT_B:M_DIO_WriteLowNibble(portName,data); break;
	case PORT_C:M_DIO_WriteLowNibble(portName,data); break;
	case PORT_D:M_DIO_WriteLowNibble(portName,data); break;
	retVal=OK;
	}
	return retVal;
}

