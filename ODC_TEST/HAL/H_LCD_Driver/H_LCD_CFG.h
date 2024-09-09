/*
 * H_LCD_CFG.h
 *
 *  Created on: Sep 5, 2024
 *      Author: Nourhan Mohamed Hassan
 */

#ifndef HAL_H_LCD_DRIVER_H_LCD_CFG_H_
#define HAL_H_LCD_DRIVER_H_LCD_CFG_H_
#include "../../MCAL/M_DIO_Driver/M_DIO_Init.h"
#include "H_LCD_CFG.h"

#include <util/delay.h>

//#define EIGHT_PINS_MODE
#define FOUR_PINS_MODE

#define LCD_DATA_PORT PORT_A

#define LCD_RS_PORT   PORT_B
#define LCD_RS_PIN    PIN1

//#define LCD_RW_PORT   MDIO_PORTB
//#define LCD_RW_PIN    PIN2

#define LCD_EN_PORT   PORT_B
#define LCD_EN_PIN    PIN0


#define CLEAR_DISPLAY 0X01
#define RETURN_HOME   0X02
#define ENTRY_MODE    0X06
#define DISPLAY_ON_CURSOR_OFF 0X0C

#if defined FOUR_PINS_MODE
#define LCD_PIN4 PIN4
#define LCD_PIN5 PIN5
#define LCD_PIN6 PIN6
#define LCD_PIN7 PIN7
#define FUNCTION_SET  0X28 //FOR 4 BITS
#elif defined EIGHT_PINS_MODE
#define FUNCTION_SET  0X38 //FOR 8BITS
#endif
#define ROW_ONE 0X80
#define ROW_TWO 0XC0

#endif /* HAL_H_LCD_DRIVER_H_LCD_CFG_H_ */
