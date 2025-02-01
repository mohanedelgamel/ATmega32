/*
 * LED_Interface.h
 *
 *  Created on: Jul 26, 2024
 *      Author: mohaned
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#include "../../Library/STD_Types.h"


#define LED1 0
#define LED2 1



void LED_voidInit();
void LED_voidSetLEDHigh(u8 L_u8Led);
void LED_voidSetLEDLow(u8 L_u8Led);


#endif /* HAL_LED_LED_INTERFACE_H_ */
