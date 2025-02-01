/*
 * Stepper_Prog.c
 *
 *  Created on: Jul 31, 2024
 *      Author: mohaned
 */

#include "Stepper_Config.h"
#include "Stepper_Private.h"
#include "Stepper_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../Library/Bit_Math.h"
#include "../../Library/STD_Types.h"


static u8 current=0;
void Stepper_voidInit()
{
	for(u8 i=0;i<CoilsNum;i++)
	{
		MDIO_u8SetPinDirection(coils[i].PORT,coils[i].PIN,DIO_OUTPUT);
	}


}
void Stepper_voidStepCW()
{

	for(u8 i=0;i<CoilsNum;i++)
		{
			MDIO_u8SetPinValue(coils[i].PORT,coils[i].PIN,GET_BIT(seq[current],i));
		}

	current ++;
	if (current>7)
		{
			current=0;
		}
}
void Stepper_voidStepCCW()
{
	current --;
	if (current>7) //due to over flow when -- below zero it will turn into 255
				{
					current=7;
				}
		for(u8 i=0;i<CoilsNum;i++)
			{
				MDIO_u8SetPinValue(coils[i].PORT,coils[i].PIN,GET_BIT(seq[current],i));
			}

}
