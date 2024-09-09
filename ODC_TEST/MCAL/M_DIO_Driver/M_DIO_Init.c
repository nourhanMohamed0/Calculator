/*
 * M_DIO_Init.c
 *
 *  Created on: Sep 5, 2024
 *      Author: Afrotto
 */
#include "M_DIO_Init.h"

ERROR_STATE_T M_DIO_SetPinDirection(u8 portName,u8 pinNumber,u8 dir){
	ERROR_STATE_T retVal=NOK;
	if ((pinNumber>=PIN0) && (pinNumber<=PIN7))
	{
		if (dir==OUTPUT)
		{
			switch(portName){
			case PORT_A:SET_BIT(MDIO_DDRA,pinNumber);break;
			case PORT_B:SET_BIT(MDIO_DDRB,pinNumber);break;
			case PORT_C:SET_BIT(MDIO_DDRC,pinNumber);break;
			case PORT_D:SET_BIT(MDIO_DDRD,pinNumber);break;
			retVal=OK;
			}
		}
		else if(dir==INPUT) {
			switch(portName){
			case PORT_A:CLR_BIT(MDIO_DDRA,pinNumber);break;
			case PORT_B:CLR_BIT(MDIO_DDRB,pinNumber);break;
			case PORT_C:CLR_BIT(MDIO_DDRC,pinNumber);break;
			case PORT_D:CLR_BIT(MDIO_DDRD,pinNumber);break;
			retVal=OK;
			}
		}
	}
	return retVal;
}

ERROR_STATE_T M_DIO_SetPinValue(u8 portName,u8 pinNumber,u8 val){
	ERROR_STATE_T retVal=NOK;
		if ((pinNumber>=PIN0) && (pinNumber<=PIN7))
		{
			if (val==HIGH)
			{
				switch(portName){
				case PORT_A:SET_BIT(MDIO_PORTA,pinNumber);break;
				case PORT_B:SET_BIT(MDIO_PORTB,pinNumber);break;
				case PORT_C:SET_BIT(MDIO_PORTC,pinNumber);break;
				case PORT_D:SET_BIT(MDIO_PORTD,pinNumber);break;
				retVal=OK;
				}
			}
			else if(val==LOW) {
				switch(portName){
				case PORT_A:CLR_BIT(MDIO_PORTA,pinNumber);break;
				case PORT_B:CLR_BIT(MDIO_PORTB,pinNumber);break;
				case PORT_C:CLR_BIT(MDIO_PORTC,pinNumber);break;
				case PORT_D:CLR_BIT(MDIO_PORTD,pinNumber);break;
				retVal=OK;
				}
			}
		}
		return retVal;

}

ERROR_STATE_T M_DIO_GetPinValue(u8 portName,u8 pinNumber,u8 *val){
	ERROR_STATE_T retVal=NOK;
	if(*val != NULL){
			if ((pinNumber>=PIN0) && (pinNumber<=PIN7))
			{
					switch(portName){
					case PORT_A:*val=READ_BIT(MDIO_PINA,pinNumber);break;
					case PORT_B:*val=READ_BIT(MDIO_PINB,pinNumber);break;
					case PORT_C:*val=READ_BIT(MDIO_PINC,pinNumber);break;
					case PORT_D:*val=READ_BIT(MDIO_PIND,pinNumber);break;
					retVal=OK;
					}
			}
	}
			return retVal;
}


ERROR_STATE_T M_DIO_SetPortValue(u8 portName,u8 val){
	ERROR_STATE_T retVal=NOK;
	switch(portName){
	case PORT_A:MDIO_PORTA=val;break;
	case PORT_B:MDIO_PORTB=val;break;
	case PORT_C:MDIO_PORTC=val;break;
	case PORT_D:MDIO_PORTD=val;break;
	retVal=OK;
	}
	return retVal;
}

ERROR_STATE_T M_DIO_GetPortValue(u8 portName,u8 *val){
	ERROR_STATE_T retVal=NOK;
	if(*val != NULL){
	switch(portName){
		case PORT_A:*val=MDIO_PORTA;break;
		case PORT_B:*val=MDIO_PORTB;break;
		case PORT_C:*val=MDIO_PORTC;break;
		case PORT_D:*val=MDIO_PORTC;break;
		retVal=OK;
		}
	}
		return retVal;
}
ERROR_STATE_T M_DIO_SetPortDirection(u8 portName,u8 dir){
	ERROR_STATE_T retVal=NOK;
	switch(portName){
	case PORT_A:MDIO_DDRA=dir;break;
	case PORT_B:MDIO_DDRB=dir;break;
	case PORT_C:MDIO_DDRC=dir;break;
	case PORT_D:MDIO_DDRD=dir;break;
	retVal=OK;
	}
	return retVal;
}
ERROR_STATE_T M_DIO_EnablPullup(u8 portName, u8 pinNumber){
	ERROR_STATE_T retVal=NOK;
	switch(portName){
		case PORT_A:M_DIO_SetPinDirection(PORT_A,pinNumber,INPUT);SET_BIT(MDIO_PORTA,pinNumber);break;
		case PORT_B:M_DIO_SetPinDirection(PORT_B,pinNumber,INPUT);SET_BIT(MDIO_PORTB,pinNumber);break;
		case PORT_C:M_DIO_SetPinDirection(PORT_C,pinNumber,INPUT);SET_BIT(MDIO_PORTC,pinNumber);break;
		case PORT_D:M_DIO_SetPinDirection(PORT_D,pinNumber,INPUT);SET_BIT(MDIO_PORTD,pinNumber);break;
		retVal=OK;
		}
	return retVal;
}
ERROR_STATE_T M_DIO_WriteHighNibble(u8 portName,u8 data){
	data<<=4;
	ERROR_STATE_T retVal=NOK;
		switch(portName){
			case PORT_A:MDIO_PORTA&=0x0f; MDIO_PORTA|=data;break;
			case PORT_B:MDIO_PORTB&=0x0f; MDIO_PORTB|=data;break;
			case PORT_C:MDIO_PORTC&=0x0f; MDIO_PORTC|=data;break;
			case PORT_D:MDIO_PORTD&=0x0f; MDIO_PORTA|=data;break;
			retVal=OK;
			}
		return retVal;

}
ERROR_STATE_T M_DIO_WriteLowNibble(u8 portName,u8 data){
	data&=0x0f;
	ERROR_STATE_T retVal=NOK;
		switch(portName){
			case PORT_A:MDIO_PORTA&=0xf0; MDIO_PORTA|=data;break;
			case PORT_B:MDIO_PORTB&=0xf0; MDIO_PORTB|=data;break;
			case PORT_C:MDIO_PORTC&=0xf0; MDIO_PORTC|=data;break;
			case PORT_D:MDIO_PORTD&=0xf0; MDIO_PORTA|=data;break;
			retVal=OK;
			}
		return retVal;

}
