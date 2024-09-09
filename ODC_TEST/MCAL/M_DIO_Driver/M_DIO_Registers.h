/*
 * M_DIO_Registers.h
 *
 *  Created on: Sep 5, 2024
 *      Author: Nourhan Mohamed Hassan
 */

#ifndef MCAL_M_DIO_DRIVER_M_DIO_REGISTERS_H_
#define MCAL_M_DIO_DRIVER_M_DIO_REGISTERS_H_
#include "../../STD_Types.h"
#include "../../Common_Macros.h"

/***********************PORTA************************/

#define MDIO_PORTA (*((volatile u8*)(0x3B)))
#define MDIO_PINA  (*((volatile u8*)(0x39)))
#define MDIO_DDRA  (*((volatile u8*)(0x3A)))

/***********************PORTB************************/

#define MDIO_PORTB (*((volatile u8*)(0x38)))
#define MDIO_PINB  (*((volatile u8*)(0x36)))
#define MDIO_DDRB  (*((volatile u8*)(0x37)))

/***********************PORTC************************/

#define MDIO_PORTC (*((volatile u8*)(0x35)))
#define MDIO_PINC  (*((volatile u8*)(0x33)))
#define MDIO_DDRC  (*((volatile u8*)(0x34)))

/***********************PORTD************************/

#define MDIO_PORTD (*((volatile u8*)(0x32)))
#define MDIO_PIND  (*((volatile u8*)(0x30)))
#define MDIO_DDRD  (*((volatile u8*)(0x31)))




#endif /* MCAL_M_DIO_DRIVER_M_DIO_REGISTERS_H_ */
