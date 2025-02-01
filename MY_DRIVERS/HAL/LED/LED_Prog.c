/*
 * LED_Prog.c
 *
 *  Created on: Jul 26, 2024
 *      Author: mohaned
 */

#include "LED_Interface.h"
#include "LED_Config.h"
#include "LED_Private.h"
#include "../../LIBRARY/STD_Types.h"
#include "../../MCAL/DIO/DIO_Interface.h"

void LED_voidInit()
{
	{
	MDIO_u8SetPinDirection(LED1_PORT, LED1_PIN, DIO_OUTPUT);
	MDIO_u8SetPinDirection(LED2_PORT, LED2_PIN, DIO_OUTPUT);

	}
}


void LED_voidSetLEDHigh(u8 L_u8Led) {
	switch (L_u8Led) {
	case LED1:
		MDIO_u8SetPinValue(LED1_PORT, LED1_PIN, DIO_HIGH);
		break;
	case LED2:
		MDIO_u8SetPinValue(LED2_PORT, LED2_PIN,DIO_HIGH);
		break;

	}

}
void LED_voidSetLEDLow(u8 L_u8Led) {
	switch (L_u8Led) {
	case LED1:
		MDIO_u8SetPinValue(LED1_PORT, LED1_PIN, DIO_LOW);
		break;
	case LED2:
		MDIO_u8SetPinValue(LED2_PORT, LED2_PIN, DIO_LOW);
		break;

	}
}




