/*
 * Servo_Prog.c
 *
 *  Created on: Aug 5, 2024
 *      Author: mohaned
 */
#include "Servo_Config.h"
#include "Servo_Private.h"
#include "Servo_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/Timer1/Timer1_Interface.h"

void Servo_Init(){
	MDIO_u8SetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);
	TIM1_InitPWM();
	TIM1_PWMSetMode(SERVO_CHANNEL,PWM_NON_INVERTING);
	TIM1_SetPeriod(SERVO_PERIOD);
	TIM1_StartPWM();
}
void Servo_SetAngle(u8 Angle)
{
	Angle +=90;
	u32 T_On= 1000 + (((u32)Angle)*1000)/180;
	TIM1_SetT_ON(SERVO_CHANNEL,T_On);

	}
