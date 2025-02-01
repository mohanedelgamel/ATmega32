/*
 * Timer0_Interface.h
 *
 *  Created on: Aug 1, 2024
 *      Author: mohaned
 */

#ifndef MCAL_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_TIMER0_INTERFACE_H_



void TIM0_voidInit();
void TIM0_SetValueUS(u32 us);
void TIM0_voidDisable();
void TIM0_SetCallBack(void(*ptr)(void));

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
