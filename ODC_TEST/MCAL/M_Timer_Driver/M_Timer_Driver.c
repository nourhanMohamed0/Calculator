/*
 * M_Timer_Driver.c
 *
 *  Created on: Sep 7, 2024
 *      Author: Afrotto
 */


#include "M_Timer_Driver.h"
#include <avr/interrupt.h>
#define F_CPU 1000000UL
void M_Timer_Init_Interrupt_Normal(u32 delay_ms,u32 prescaler){
	u32 overFlowCounter=0,numOfOverFlow=0;
	u8 initial_value=0;
	float T_tick=1/(F_CPU/prescaler);// 256Msec
	float maxDelay=T_tick*REGISTER_8BIT_VALUE;
	sei(); //1.Enable Interrupt
	SET_BIT(M_TIMER_TIMSK,0);
	if (delay_ms>(maxDelay*1000)){

		numOfOverFlow=(delay_ms/maxDelay);
		M_TIMER_TCNT0=initial_value;      //2.set initial value for timer
		//3.start timing by select prescaling from TCCR0 reg
				SET_BIT(M_TIMER_TCCR0,CS02);
			while(overFlowCounter<=numOfOverFlow)
					{
						while(READ_BIT(M_TIMER_TIFR,0)==0);
						//clear overflow flag
						M_TIMER_TIFR|=(1<<0);
						overFlowCounter++;
					}
			overFlowCounter=0;
					//stop timer
			M_TIMER_TCCR0=0x00;



	}


}
