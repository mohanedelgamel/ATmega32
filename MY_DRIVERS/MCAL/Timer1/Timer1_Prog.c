/*
 * Timer1_Prog.c
 *
 *  Created on: Aug 5, 2024
 *      Author: mohaned
 */


#include "Timer1_Config.h"
#include "Timer1_Private.h"
#include "Timer1_Interface.h"

#include "../../Library/Bit_Math.h"
#include "../../Library/STD_Types.h"

void TIM1_InitPWM(){
	//set fast PWM mode
	CLEAR_BIT(TCCR1A_REG,WGM10);
	SET_BIT(TCCR1A_REG,WGM11);
	SET_BIT(TCCR1B_REG,WGM12);
	SET_BIT(TCCR1B_REG,WGM13);



	//set mode channel A
	CLEAR_BIT(TCCR1A_REG,COM1A0);
	SET_BIT(TCCR1A_REG,COM1A1);

	//set mode channel B
	CLEAR_BIT(TCCR1A_REG,COM1B0);
	SET_BIT(TCCR1A_REG,COM1B1);


}
void TIM1_StartPWM(){
	//set prescaller to 8
		CLEAR_BIT(TCCR1B_REG,CS10);
		SET_BIT(TCCR1B_REG,CS11);
		CLEAR_BIT(TCCR1B_REG,CS12);

}
void TIM1_SetDutyCycle(u8 Channel,u8 Duty){

	u32 T_On=(u32)Duty*ICR1L_REG/100;
	TIM1_SetT_ON(Channel,T_On);
}

void TIM1_SetT_ON(u8 Channel,u16 us)
{

		switch(Channel){
		case PWM_OCR1A : OCR1AL_REG=(u16) us;break;
		case PWM_OCR1B : OCR1BL_REG=(u16) us;break;
		}
}
void TIM1_SetPeriod(u16 us)
{

	ICR1L_REG=us;
}
void TIM1_PWMSetMode(u8 mode ,u8 Channel)
{
	switch(Channel){
		case PWM_OCR1A :
		TCCR1A_REG &=~(0b11<<COM1A0) ;
		TCCR1A_REG  |= mode <<COM1A0;
		break;
		case PWM_OCR1B :TCCR1A_REG &=~(0b11<<COM1B0) ;
		TCCR1A_REG  |= mode <<COM1B0;
		}

}
