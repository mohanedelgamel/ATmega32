/*
 * Timer1_Interface.h
 *
 *  Created on: Aug 5, 2024
 *      Author: mohaned
 */

#ifndef MCAL_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_TIMER1_INTERFACE_H_

#include "../../Library/STD_Types.h"
#define PWM_OCR1A  0
#define PWM_OCR1B  1


#define PWM_INVERTING      0b11
#define PWM_NON_INVERTING  0b10

void TIM1_InitICU();
void TIM1_ClearValue();
u16  TIM1_ReadValue();

void TIM1_InitPWM();
void TIM1_StartPWM();
void TIM1_SetDutyCycle(u8 Channel,u8 Duty);
void TIM1_SetT_ON(u8 Channel,u16 us);
void TIM1_SetPeriod(u16 us);
void TIM1_PWMSetMode(u8 mode ,u8 Channel);

#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
