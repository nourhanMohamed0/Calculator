/*
 * M_Dio.h
 *
 *  Created on: Sep 5, 2024
 *      Author: Nourhan Mohamed Hassan
 */

#ifndef MCAL_M_DIO_DRIVER_M_DIO_INIT_H_
#define MCAL_M_DIO_DRIVER_M_DIO_INIT_H_

#include "M_DIO_Registers.h"

typedef enum {
	 NOK,OK
} ERROR_STATE_T;

/*****************************************************************************/
/* Service Name: M_DIO_SetPinDirection                                       */
/* Parameters (in): - portName                                               */
/*                  - pinNumber                                              */
/*                  - dir                                                    */
/* Parameters (out): None                                                    */
/* Return Value: ERROR_STATE_T                                               */
/* Description: Service to set a Direction of a channel                      */
/*****************************************************************************/
ERROR_STATE_T M_DIO_SetPinDirection(u8 portName, u8 pinNumber, u8 dir);

/*****************************************************************************/
/* Service Name: M_DIO_SetPinValue                                           */
/* Parameters (in): - portName                                               */
/*                  - pinNumber                                              */
/*                  - val                                                    */
/* Parameters (out): None                                                    */
/* Return Value: ERROR_STATE_T                                               */
/* Description: Service to set a value of a channel                          */
/*****************************************************************************/
ERROR_STATE_T M_DIO_SetPinValue(u8 portName, u8 pinNumber, u8 val);

/*****************************************************************************/
/* Service Name: M_DIO_GetPinValue                                           */
/* Parameters (in): - portName                                               */
/*                  - pinNumber                                              */
/*                  - *val                                                   */
/* Parameters (out): val                                                     */
/* Return Value: ERROR_STATE_T                                               */
/* Description: Service to get a value of a channel                          */
/*****************************************************************************/

ERROR_STATE_T M_DIO_GetPinValue(u8 portName, u8 pinNumber, u8 *val);

/*****************************************************************************/
/* Service Name: M_DIO_SetPortValue                                          */
/* Parameters (in): - portName                                               */
/*                  - val                                                    */
/* Parameters (out): None                                                    */
/* Return Value: ERROR_STATE_T                                               */
/* Description: Service to set a Direction of a port                         */
/*****************************************************************************/
ERROR_STATE_T M_DIO_SetPortValue(u8 portName, u8 val);

/*****************************************************************************/
/* Service Name: M_DIO_GetPortValue                                          */
/* Parameters (in): - portName                                               */
/*                  - *val                                                   */
/* Parameters (out): val                                                     */
/* Return Value: ERROR_STATE_T                                               */
/* Description: Service to get a Direction of a port                         */
/*****************************************************************************/

ERROR_STATE_T M_DIO_GetPortValue(u8 portName, u8 *val);

/*****************************************************************************/
/* Service Name: M_DIO_SetPortDirection                                      */
/* Parameters (in): - portName                                               */
/*                  - dir                                                    */
/* Parameters (out): None                                                    */
/* Return Value: ERROR_STATE_T                                               */
/* Description: Service to set a Direction of a port                         */
/*****************************************************************************/
ERROR_STATE_T M_DIO_SetPortDirection(u8 portName, u8 dir);
/*****************************************************************************/
/* Service Name: M_DIO_SetPortDirection                                      */
/* Parameters (in): - portName                                               */
/*                  - pinNumber                                              */
/* Parameters (out): None                                                    */
/* Return Value: ERROR_STATE_T                                               */
/* Description: Service to Enable an internal pull up                        */
/*****************************************************************************/
ERROR_STATE_T M_DIO_EnablPullup(u8 portName, u8 pinNumber);
/*****************************************************************************/
/* Service Name: M_DIO_WriteHighNibble                                       */
/* Parameters (in): - portName                                               */
/*                  - data                                                   */
/* Parameters (out): None                                                    */
/* Return Value: ERROR_STATE_T                                               */
/* Description: Service to write on high nibble                              */
/*****************************************************************************/
ERROR_STATE_T M_DIO_WriteHighNibble(u8 portName,u8 data);
/*****************************************************************************/
/* Service Name: M_DIO_WriteLowNibble                                        */
/* Parameters (in): - portName                                               */
/*                  - data                                                   */
/* Parameters (out): None                                                    */
/* Return Value: ERROR_STATE_T                                               */
/* Description: Service to write on Low nibble                               */
/*****************************************************************************/
ERROR_STATE_T M_DIO_WriteLowNibble(u8 portName,u8 data);

typedef enum {
	INPUT = 0, OUTPUT = 1
} PIN_DIRECTION_T;

typedef enum {
	LOW = 0, HIGH = 1
} PIN_VALUE_T;

typedef enum {
	PIN0 = 0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7
} PIN_NUMBER_T;

typedef enum {
	PORT_A = 0, PORT_B, PORT_C, PORT_D

} PORT_NUMBER_T;

#define ALL_PORT_OUTPUT 0XFF
#define ALL_PORT_HIGH   0xFF
#endif /* MCAL_M_DIO_DRIVER_M_DIO_INIT_H_ */
