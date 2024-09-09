/*
 * M_Timer_Driver_Registers.h
 *
 *  Created on: Sep 7, 2024
 *      Author: Afrotto
 */

#ifndef MCAL_M_TIMER_DRIVER_M_TIMER_DRIVER_REGISTERS_H_
#define MCAL_M_TIMER_DRIVER_M_TIMER_DRIVER_REGISTERS_H_

#define M_TIMER_TCCR0 *((volatile u8*)(0x53))
#define M_TIMER_TCNT0 *((volatile u8*)(0x52))
#define M_TIMER_TIFR  *((volatile u8*)(0x58))
#define M_TIMER_OCR0  *((volatile u8*)(0x5C))
#define M_TIMER_TIMSK  *((volatile u8*)(0x5C))

#define CS00 0
#define CS01 1
#define CS02 2

#define PRESCALER_256    0
#define PRESCALER_8      1
#define PRESCALER_64     2
#define PRESCALER_1024   3
#define REGISTER_8BIT_VALUE 256

#endif /* MCAL_M_TIMER_DRIVER_M_TIMER_DRIVER_REGISTERS_H_ */
