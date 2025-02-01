/*
 * EXTI_Interface.h
 *
 *  Created on: Jul 30, 2024
 *      Author: mohaned
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#include "../../Library/STD_Types.h"
#define EXTI0 0
#define EXTI1 1
#define EXTI2 2

void EXTI_Init(void);
void EXTI_Enable(u8 L_u8EXTI_Num);
void EXTI_Disable(u8 L_u8EXTI_Num);


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
