/*
 * ICU_Prog.c
 *
 *  Created on: Aug 6, 2024
 *      Author: mohaned
 */

#include "../../Library/STD_Types.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/EXTI/EXTI_Interface.h"
#include "../../MCAL/Timer1/Timer1_Interface.h"

#include"ICU_Config.h"
#include"ICU_Interface.h"
#include"ICU_Private.h"



void ICU_Init(){
#if ICU_CHANNEL == EXTI0
	MDIO_u8SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
#elif 	ICU_CHANNEL == EXT1
	MDIO_u8SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_INPUT);
#elif	ICU_CHANNEL == EXTI2
	MDIO_u8SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_INPUT);

#endif
	EXTI_SetMode(ICU_CHANNEL,EXTI_RAISING);
	EXTI_CallBack(ICU_Process,ICU_CHANNEL);
	EXTI_Enable(ICU_CHANNEL);

	TIM1_voidInit();
	TIM1_ClearValue();


}

void ICU_Process()
{
	static  u8 state =ICU_WaITING_FOR_FIRST_RISING;
	static volatile u16  temp_TON =0;
	static volatile u16 temp_TOFF=0;


	switch(state)
	{
	case ICU_WaITING_FOR_FIRST_RISING:
		TIM1_ClearValue();
		EXTI_SetMode(ICU_CHANNEL,EXTI_FALLING);
		state=ICU_WaITING_FOR_FALLING;
		break;
	case ICU_WaITING_FOR_FALLING:
		temp_TON=TIM1_ReadValue();
		TIM1_ClearValue();
		state=ICU_WaITING_FOR_SECOND_RISING;
		EXTI_SetMode(ICU_CHANNEL,EXTI_RAISING);
		break;
	case ICU_WaITING_FOR_SECOND_RISING:
		temp_TOFF=TIM1_ReadValue();
		TIM1_ClearValue();
		state=ICU_WaITING_FOR_FIRST_RISING;
		EXTI_SetMode(ICU_CHANNEL,EXTI_RAISING);
	}
	T_ON=temp_TON;
	T_OFF=temp_TOFF;
}
u16  ICU_GetOnTime(){
	return T_ON;

}
u16  ICU_GetOffTime(){
	return T_OFF;

}
u32  ICU_GetPeriod(){
return  (((u32)T_ON)+T_OFF);
}
