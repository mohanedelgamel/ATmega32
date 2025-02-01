/*
 * Button_Prog.c
 *
 *  Created on: Jul 28, 2024
 *      Author: mohaned
 */

#include "../../Library/STD_Types.h"
#include "../../MCAL/DIO/DIO_Interface.h"

#include "Button_Config.h"
#include "Button_Private.h"
#include "Button_Interface.h"


void Button__voidInit(){
	MDIO_u8SetPinDirection(Button1_PORT,Button1_PIN,DIO_INPUT);
	MDIO_u8SetPinDirection(Button2_PORT,Button2_PIN,DIO_INPUT);

	//Enable Pull_up
	MDIO_u8SetPinValue(Button1_PORT,Button1_PIN,DIO_HIGH);
	MDIO_u8SetPinValue(Button2_PORT,Button2_PIN,DIO_HIGH);


}
u8 Button_GetStatus(u8 L_u8ButtonNumber,u8 *L_u8Buttonstate){

	if (MDIO_u8SGetPinValue(Button1_PORT,Button1_PIN,L_u8Buttonstate)==OK)
	{
	return OK;
	}
	return NOT_OK;
}

void Button_voidWaitForButton(u8 L_u8ButtonNumber)
{

}
