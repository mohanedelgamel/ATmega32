/*
 * Timer2_Interface.h
 *
 *  Created on: Aug 1, 2024
 *      Author: mohaned
 */

#ifndef MCAL_TIMER2_TIMER2_INTERFACE_H_
#define MCAL_TIMER2_TIMER2_INTERFACE_H_



void TIM2_voidInit();
void TIM2_SetValueUS(u32 us);
void TIM2_voidDisable();
void TIM2_SetCallBack(void(*ptr)(void));

#endif /* MCAL_TIMER2_TIMER2_INTERFACE_H_ */
