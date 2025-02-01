/*
 * FAST_ICU_Prog.c
 *
 *  Created on: Aug 7, 2024
 *      Author: mohaned
 */

#include "FAST_ICU_Config.h"
#include "FAST_ICU_Interface.h"
#include "FAST_ICU_Private.h"

#include "../../MCAL/Timer1/Timer1_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"


u16 period;
u16 TON;
void FAST_ICU_Init(){
	TIM1_voidInit();
	TIM1_SetEdge(ICU_EDGE_RISING);
	TIM1_setCallback(FAST_ICU_Process);
	MDIO_u8SetPinDirection(DIO_PORTD,DIO_PIN6,DIO_INPUT);
}

void FAST_ICU_Process(){
	static u8 state=FAST_ICU_FIRST_RISING;
	static u16 Point_1 =0;
	static u16 Point_2 =0;
	static u16 Point_3 =0;

	switch (state)
	{
	case FAST_ICU_FIRST_RISING:
		Point_1=TIM1_GetICRValue();
		TIM1_SetEdge(ICU_EDGE_FALLING);
		state=FAST_ICU_FALLING;
		break;
	case FAST_ICU_FALLING:
			Point_2=TIM1_GetICRValue();
			TIM1_SetEdge(ICU_EDGE_RISING);
			state=FAST_ICU_SECOND_RISING;
			break;

	case FAST_ICU_SECOND_RISING:
			Point_3=TIM1_GetICRValue();
			TIM1_SetEdge(ICU_EDGE_RISING);
			state=FAST_ICU_FIRST_RISING;
			period =Point_3-Point_2;
			TON =Point_2-Point_1;
			break;




	}

}
u16  FAST_ICU_GetOnTime(){
	return TON;
}
u16  FAST_ICU_GetOffTime(){
	return (period-TON);
}
u32  FAST_ICU_GetPeriod(){
	return period;
}
