/*
 * Button_Interface.h
 *
 *  Created on: Jul 28, 2024
 *      Author: mohaned
 */

#ifndef HAL_BUTTON_BUTTON_INTERFACE_H_
#define HAL_BUTTON_BUTTON_INTERFACE_H_

#define Button1 1
#define Button2 2

void Button__voidInit();
u8 Button_GetStatus(u8 L_u8ButtonNumber,u8 *L_u8Buttonstate);
void Button_voidWaitForButton(u8 L_u8ButtonNumber);


#endif /* HAL_BUTTON_BUTTON_INTERFACE_H_ */
