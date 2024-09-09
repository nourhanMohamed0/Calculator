/*
 * H_LCD.h
 *
 *  Created on: Sep 5, 2024
 *      Author: Nourhan Mohamed Hassan
 */

#ifndef HAL_H_LCD_DRIVER_H_LCD_H_
#define HAL_H_LCD_DRIVER_H_LCD_H_
#include "../H_LCD_Driver/H_LCD_CFG.h"
/*****************************************************************************/
/* Service Name: H_LCD_sendData                                              */
/* Parameters (in): - data                                                   */
/* Parameters (out): None                                                    */
/* Return Value: void                                                        */
/* Description: Service to send data to be displayed on LCD                  */
/*****************************************************************************/
void H_LCD_sendData(u8 data);
/*****************************************************************************/
/* Service Name: H_LCD_sendCommand                                           */
/* Parameters (in): - command                                                */
/* Parameters (out): None                                                    */
/* Return Value: void                                                        */
/* Description: Service to send command to be displayed on LCD               */
/*****************************************************************************/
void H_LCD_sendCommand(u8 command);
/*****************************************************************************/
/* Service Name: H_LCD_Init                                                  */
/* Parameters (in): - None                                                   */
/* Parameters (out): None                                                    */
/* Return Value: void                                                        */
/* Description: Service to Initialize LCD                                    */
/*****************************************************************************/
void H_LCD_Init();
/*****************************************************************************/
/* Service Name: H_LCD_sendString                                            */
/* Parameters (in): - *str                                                   */
/* Parameters (out): None                                                    */
/* Return Value: void                                                        */
/* Description: Service to Send String to LCD                                */
/*****************************************************************************/
void H_LCD_sendString(const u8 *str);
/*****************************************************************************/
/* Service Name: H_sendNumber                                                */
/* Parameters (in): - number                                                 */
/* Parameters (out): None                                                    */
/* Return Value: void                                                        */
/* Description: Service to Send number to LCD                                */
/*****************************************************************************/
void H_sendNumber(const u16 number);
/*****************************************************************************/
/* Service Name: H_changeCursorPlace                                         */
/* Parameters (in): - column                                                 */
/* Parameters (in): - row                                                    */
/* Parameters (out): None                                                    */
/* Return Value: void                                                        */
/* Description: Service to set cursor on LCD                                 */
/*****************************************************************************/
void H_changeCursorPlace(u8 row,u8 column);

#endif /* HAL_H_LCD_DRIVER_H_LCD_H_ */
