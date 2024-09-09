/*
 * H_KeyPad.h
 *
 *  Created on: Sep 5, 2024
 *      Author: Nourhan Mohamed Hassan
 */

#ifndef HAL_H_KEYPAD_DRIVER_H_KEYPAD_H_
#define HAL_H_KEYPAD_DRIVER_H_KEYPAD_H_
#include "../../MCAL/M_DIO_Driver/M_DIO_Init.h"
#include "H_KeyPad_CFG.h"

/*****************************************************************************/
/* Service Name: H_keyPad_Init                                               */
/* Parameters (in): - None                                                   */
/* Parameters (out): None                                                    */
/* Return Value: void                                                        */
/* Description: Service to Initialize the KeyPad                             */
/*****************************************************************************/

void H_keyPad_Init();
/*****************************************************************************/
/* Service Name: H_GetKeyPadPressed                                          */
/* Parameters (in): - value                                                  */
/* Parameters (out):- value                                                  */
/* Return Value: void                                                        */
/* Description: Service to write on KeyPad                                   */
/*****************************************************************************/
void H_GetKeyPadPressed(u8 *value);

#endif /* HAL_H_KEYPAD_DRIVER_H_KEYPAD_H_ */
