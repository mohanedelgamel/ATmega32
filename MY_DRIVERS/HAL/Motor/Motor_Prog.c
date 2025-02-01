/*
 * Motor_Prog.c
 *
 *  Created on: Jul 31, 2024
 *      Author: mohaned
 */

#include "Motor_Config.h"
#include "Motor_Interface.h"
#include "Motor_Private.h"

#include "../../Library/Bit_Math.h"
#include "../../Library/STD_Types.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>


void Motor_voidInit()
{
	MDIO_u8SetPinDirection(Motor_CCW_PORT,Motor_CCW_PIN,DIO_OUTPUT);
	MDIO_u8SetPinDirection(Motor_CW_PORT,Motor_CW_PIN,DIO_OUTPUT);
	Motor_Stop();

}
void Motor_SetDirection(u8 L_u8Direction)
{
	switch(L_u8Direction)
	{
	case Motor_CW:
		{ MDIO_u8SetPinValue(Motor_CCW_PORT,Motor_CCW_PIN,DIO_LOW);_delay_ms(1);
		 MDIO_u8SetPinValue(Motor_CW_PORT,Motor_CW_PIN,DIO_HIGH);
		 break;


		}
	case Motor_CCW:
			{ MDIO_u8SetPinValue(Motor_CW_PORT,Motor_CW_PIN,DIO_LOW);_delay_ms(1);
			 MDIO_u8SetPinValue(Motor_CCW_PORT,Motor_CCW_PIN,DIO_HIGH);
			 break;

			}

	}
	}
void Motor_Stop(){
	              MDIO_u8SetPinValue(Motor_CW_PORT,Motor_CW_PIN,DIO_LOW);
				 MDIO_u8SetPinValue(Motor_CCW_PORT,Motor_CCW_PIN,DIO_LOW);

}
