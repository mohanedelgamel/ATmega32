/*
 * SevenSegment_Prog.c
 *
 *  Created on: Jul 27, 2024
 *      Author: mohaned
 */

#include "SevenSegment_Config.h"
#include "SevenSegment_Interface.h"
#include "SevenSegment_Private.h"
#include "../../MCAL/DIO/DIO_Interface.h"


u8 SevenSegment_u8Init()
{
	MDIO_u8SetPinDirection(A_PORT,A_PIN, DIO_HIGH);
	MDIO_u8SetPinDirection(B_PORT,B_PIN, DIO_HIGH);
	MDIO_u8SetPinDirection(C_PORT,C_PIN, DIO_HIGH);
	MDIO_u8SetPinDirection(D_PORT,D_PIN, DIO_HIGH);
	MDIO_u8SetPinDirection(E_PORT,E_PIN, DIO_HIGH);
	MDIO_u8SetPinDirection(F_PORT,F_PIN, DIO_HIGH);
	MDIO_u8SetPinDirection(G_PORT,G_PIN, DIO_HIGH);
	MDIO_u8SetPinDirection(H_PORT,A_PIN, DIO_HIGH);

	SevenSegment_voidClear();

	return SEV_OK;
}

void SevenSegment_voidClear(){
	                MDIO_u8SetPinValue(A_PORT,A_PIN, DIO_LOW);
					MDIO_u8SetPinValue(B_PORT,B_PIN, DIO_LOW);
					MDIO_u8SetPinValue(C_PORT,C_PIN, DIO_LOW);
					MDIO_u8SetPinValue(D_PORT,D_PIN, DIO_LOW);
					MDIO_u8SetPinValue(E_PORT,E_PIN, DIO_LOW);
					MDIO_u8SetPinValue(F_PORT,F_PIN, DIO_LOW);
					MDIO_u8SetPinValue(G_PORT,G_PIN, DIO_LOW);
					MDIO_u8SetPinValue(H_PORT,H_PIN, DIO_LOW);
}

u8 SevenSegment_u8PrintValue(u8 L_u8Value) {
	switch (L_u8Value) {

	case Zero:
		//( 0b00111111);
	{
		MDIO_u8SetPinValue(A_PORT,A_PIN, DIO_HIGH);
		MDIO_u8SetPinValue(B_PORT,B_PIN, DIO_HIGH);
		MDIO_u8SetPinValue(C_PORT,C_PIN, DIO_HIGH);
		MDIO_u8SetPinValue(D_PORT,D_PIN, DIO_HIGH);
		MDIO_u8SetPinValue(E_PORT,E_PIN, DIO_HIGH);
		MDIO_u8SetPinValue(F_PORT,F_PIN, DIO_HIGH);
		MDIO_u8SetPinValue(G_PORT,G_PIN, DIO_LOW);
		MDIO_u8SetPinValue(H_PORT,H_PIN, DIO_LOW);
	}
		break;
	case One:
		//( 0b00000110)
	{
		        MDIO_u8SetPinValue(A_PORT,A_PIN, DIO_LOW);
				MDIO_u8SetPinValue(B_PORT,B_PIN, DIO_HIGH);
				MDIO_u8SetPinValue(C_PORT,C_PIN, DIO_HIGH);
				MDIO_u8SetPinValue(D_PORT,D_PIN, DIO_LOW);
				MDIO_u8SetPinValue(E_PORT,E_PIN, DIO_LOW);
				MDIO_u8SetPinValue(F_PORT,F_PIN, DIO_LOW);
				MDIO_u8SetPinValue(G_PORT,G_PIN, DIO_LOW);
				MDIO_u8SetPinValue(H_PORT,H_PIN, DIO_LOW);
	}

		break;
	case Two:
		//( 0b01011011);
	{
		        MDIO_u8SetPinValue(A_PORT,A_PIN, DIO_HIGH);
				MDIO_u8SetPinValue(B_PORT,B_PIN, DIO_HIGH);
				MDIO_u8SetPinValue(C_PORT,C_PIN, DIO_LOW);
				MDIO_u8SetPinValue(D_PORT,D_PIN, DIO_HIGH);
				MDIO_u8SetPinValue(E_PORT,E_PIN, DIO_HIGH);
				MDIO_u8SetPinValue(F_PORT,F_PIN, DIO_LOW);
				MDIO_u8SetPinValue(G_PORT,G_PIN, DIO_HIGH);
				MDIO_u8SetPinValue(H_PORT,H_PIN, DIO_LOW);
	}
		break;
	case Three:
	//( 0b01001111);
	{
		        MDIO_u8SetPinValue(A_PORT,A_PIN, DIO_HIGH);
				MDIO_u8SetPinValue(B_PORT,B_PIN, DIO_HIGH);
				MDIO_u8SetPinValue(C_PORT,C_PIN, DIO_HIGH);
				MDIO_u8SetPinValue(D_PORT,D_PIN, DIO_HIGH);
				MDIO_u8SetPinValue(E_PORT,E_PIN, DIO_LOW);
				MDIO_u8SetPinValue(F_PORT,F_PIN, DIO_LOW);
				MDIO_u8SetPinValue(G_PORT,G_PIN, DIO_HIGH);
				MDIO_u8SetPinValue(H_PORT,H_PIN, DIO_LOW);
	}
		break;
	case Four:
		//( 0b01100110);
	{
		        MDIO_u8SetPinValue(A_PORT,A_PIN,DIO_LOW);
				MDIO_u8SetPinValue(B_PORT,B_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(C_PORT,C_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(D_PORT,D_PIN,DIO_LOW);
				MDIO_u8SetPinValue(E_PORT,E_PIN,DIO_LOW);
				MDIO_u8SetPinValue(F_PORT,F_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(G_PORT,G_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(H_PORT,H_PIN,DIO_LOW);
	}
		break;
	case Five:
		//( 0b01101101);
	{
		        MDIO_u8SetPinValue(A_PORT,A_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(B_PORT,B_PIN,DIO_LOW);
				MDIO_u8SetPinValue(C_PORT,C_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(D_PORT,D_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(E_PORT,E_PIN,DIO_LOW);
				MDIO_u8SetPinValue(F_PORT,F_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(G_PORT,G_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(H_PORT,H_PIN,DIO_LOW);
	}
		break;
	case Six:
		//( 0b01111101);
	{
	         	MDIO_u8SetPinValue(A_PORT,A_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(B_PORT,B_PIN,DIO_LOW);
				MDIO_u8SetPinValue(C_PORT,C_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(D_PORT,D_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(E_PORT,E_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(F_PORT,F_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(G_PORT,G_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(H_PORT,H_PIN,DIO_LOW);
	}
		break;
	case Seven:
		//( 0b00000111);
	{
		        MDIO_u8SetPinValue(A_PORT,A_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(B_PORT,B_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(C_PORT,C_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(D_PORT,D_PIN,DIO_LOW);
				MDIO_u8SetPinValue(E_PORT,E_PIN,DIO_LOW);
				MDIO_u8SetPinValue(F_PORT,F_PIN,DIO_LOW);
				MDIO_u8SetPinValue(G_PORT,G_PIN,DIO_LOW);
				MDIO_u8SetPinValue(H_PORT,H_PIN,DIO_LOW);
	}
		break;
	case Eight:
		//( 0b01111111);

	{

		        MDIO_u8SetPinValue(A_PORT,A_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(B_PORT,B_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(C_PORT,C_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(D_PORT,D_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(E_PORT,E_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(F_PORT,F_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(G_PORT,G_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(H_PORT,H_PIN,DIO_LOW);
	}
		break;
	case Nine:
		//( 0b0110 1111);
	{
		        MDIO_u8SetPinValue(A_PORT,A_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(B_PORT,B_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(C_PORT,C_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(D_PORT,D_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(E_PORT,E_PIN,DIO_LOW);
				MDIO_u8SetPinValue(F_PORT,F_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(G_PORT,G_PIN,DIO_HIGH);
				MDIO_u8SetPinValue(H_PORT,H_PIN,DIO_LOW);
	}
		break;
	default:
		return SEV_NOTOK;
		break;
	}
	return SEV_OK;

}
