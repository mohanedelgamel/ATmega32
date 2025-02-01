/*
 * KeyPad_prog.c
 *
 *  Created on: Jul 30, 2024
 *      Author: mohaned
 */

#include "../../MCAL/DIO/DIO_Interface.h"
#include "KeyPad_Config.h"
#include "KeyPad_Interface.h"
#include "KeyPad_Private.h"
#include <util/delay.h>

#include "../../Library/Bit_Math.h"
#include "../../Library/STD_Types.h"

void KeyPad_voidInit() {
	for (int i = 0; i < 4; i++) {
		MDIO_u8SetPinDirection(Cols[i].C_PORT, Cols[i].C_PIN, DIO_OUTPUT);
	}

	for (int i = 0; i < 4; i++) {
		MDIO_u8SetPinDirection(Rows[i].R_PORT, Rows[i].R_PIN, DIO_INPUT);
	}

	for (int i = 0; i < 4; i++) {
		MDIO_u8SetPinValue(Cols[i].C_PORT, Cols[i].C_PIN, DIO_HIGH);
	}

}

u8 KeyPad_u8GetValue() {
	u8 L_u8Getvalue;
	u8 L_u8RetKey = 0;
	for (int i = 0; i < 4; i++) {

		MDIO_u8SetPinValue(Cols[i].C_PORT, Cols[i].C_PIN, DIO_LOW);
		for (int j = 0; j < 4; j++)
		{
			MDIO_u8SGetPinValue(Rows[j].R_PORT, Rows[j].R_PIN, &L_u8Getvalue);
			if (L_u8Getvalue == DIO_LOW)
			{
				L_u8RetKey = Keys[i][j];
				_delay_ms(50);
				while (L_u8Getvalue == DIO_LOW)
				{
					MDIO_u8SGetPinValue(Rows[j].R_PORT, Rows[j].R_PIN,&L_u8Getvalue);
				}
			}

		}
		MDIO_u8SetPinValue(Cols[i].C_PORT, Cols[i].C_PIN, DIO_HIGH);
	}

	return L_u8RetKey;
}

