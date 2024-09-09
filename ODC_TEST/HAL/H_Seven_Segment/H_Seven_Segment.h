/*
 * H_Seven_Segment.h
 *
 *  Created on: Sep 5, 2024
 *      Author: Afrotto
 */

#ifndef HAL_H_SEVEN_SEGMENT_H_SEVEN_SEGMENT_H_
#define HAL_H_SEVEN_SEGMENT_H_SEVEN_SEGMENT_H_

#include "../../MCAL/M_DIO_Driver/M_DIO_Init.h"

/*****************************************************************************/
/* Service Name: H_SevenSegment_Init                                         */
/* Parameters (in): - portName                                               */
/* Parameters (out): None                                                    */
/* Return Value: ERROR_STATE_T                                               */
/* Description: Service Init seven segment port                              */
/*****************************************************************************/
ERROR_STATE_T H_SevenSegment_Init(u8 portName);
/*****************************************************************************/
/* Service Name: H_SevenSegment_Write_Cathode                                */
/* Parameters (in): - data                                                   */
/* Parameters (in): - portName                                               */
/* Parameters (out): None                                                    */
/* Return Value: void                                                        */
/* Description: Service to write on seven segment                            */
/*****************************************************************************/
ERROR_STATE_T H_SevenSegment_Write_Cathode(u8 data,u8 portName);
/*****************************************************************************/
/* Service Name: H_SevenSegment_Write_Anode                                  */
/* Parameters (in): - data                                                   */
/* Parameters (in): - portName                                               */
/* Parameters (out): None                                                    */
/* Return Value: void                                                        */
/* Description: Service to write on seven segment                            */
/*****************************************************************************/
ERROR_STATE_T H_SevenSegment_Write_Anode(u8 data,u8 portName);
/*****************************************************************************/
/* Service Name: H_SevenSegment_BCD_Init_HighNibble                          */
/* Parameters (in): - portName                                               */
/* Parameters (out): None                                                    */
/* Return Value: void                                                        */
/* Description: Service to Init BCD seven segment                            */
/*****************************************************************************/
ERROR_STATE_T H_SevenSegment_BCD_Init_HighNibble(u8 portName);
/*****************************************************************************/
/* Service Name: H_SevenSegment_BCD_Init_LowNibble                          */
/* Parameters (in): - portName                                               */
/* Parameters (out): None                                                    */
/* Return Value: void                                                        */
/* Description: Service to Init BCD seven segment                            */
/*****************************************************************************/
ERROR_STATE_T H_SevenSegment_BCD_Init_LowNibble(u8 portName);
/*****************************************************************************/
/* Service Name: H_SevenSegment_BCD_Write                                    */
/* Parameters (in): - data                                                   */
/* Parameters (in): - portName                                               */
/* Parameters (out): None                                                    */
/* Return Value: ERROR_STATE_T                                               */
/* Description: Service to Write on BCD seven segment                        */
/*****************************************************************************/
ERROR_STATE_T H_SevenSegment_BCD_HighNibble_Write(u8 portName,u8 data);

#endif /* HAL_H_SEVEN_SEGMENT_H_SEVEN_SEGMENT_H_ */
