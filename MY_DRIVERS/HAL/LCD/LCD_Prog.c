/*
 * LCD_Prog.c
 *
 *  Created on: Jul 28, 2024
 *      Author: mohaned
 */

#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"

#include "../../Library/Bit_Math.h"
#include "../../Library/STD_Types.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>




void LCD_voidInit()
{
	MDIO_u8SetPinDirection(LCD_RS,DIO_OUTPUT);
	MDIO_u8SetPinDirection(LCD_RW,DIO_OUTPUT);
	MDIO_u8SetPinDirection(LCD_E, DIO_OUTPUT);
	MDIO_u8SetPinDirection(LCD_D0,DIO_OUTPUT);
	MDIO_u8SetPinDirection(LCD_D1,DIO_OUTPUT);
	MDIO_u8SetPinDirection(LCD_D2,DIO_OUTPUT);
	MDIO_u8SetPinDirection(LCD_D3,DIO_OUTPUT);
	MDIO_u8SetPinDirection(LCD_D4,DIO_OUTPUT);
	MDIO_u8SetPinDirection(LCD_D5,DIO_OUTPUT);
	MDIO_u8SetPinDirection(LCD_D6,DIO_OUTPUT);
	MDIO_u8SetPinDirection(LCD_D7,DIO_OUTPUT);

	_delay_ms(30);
	LCD_voidSendCommand(LCD_Function_Set1);
	_delay_ms(1);
	LCD_voidSendCommand(LCD_Display_Mode3);
	_delay_ms(1);
	LCD_voidSendCommand(LCD_Clear_Screen);
	_delay_ms(2);
	LCD_voidSendCommand(LCD_Entery_Mode1);


}

void LCD_voidSendCommand(u8 A_u8Command){
	MDIO_u8SetPinValue(LCD_RS,DIO_LOW); //set rs 0 command
	MDIO_u8SetPinValue(LCD_RW,DIO_LOW); //set rw 0 write

	// send the command
	MDIO_u8SetPinValue(LCD_D0,GET_BIT(A_u8Command,0));
	MDIO_u8SetPinValue(LCD_D1,GET_BIT(A_u8Command,1));
	MDIO_u8SetPinValue(LCD_D2,GET_BIT(A_u8Command,2));
	MDIO_u8SetPinValue(LCD_D3,GET_BIT(A_u8Command,3));
	MDIO_u8SetPinValue(LCD_D4,GET_BIT(A_u8Command,4));
	MDIO_u8SetPinValue(LCD_D5,GET_BIT(A_u8Command,5));
	MDIO_u8SetPinValue(LCD_D6,GET_BIT(A_u8Command,6));
	MDIO_u8SetPinValue(LCD_D7,GET_BIT(A_u8Command,7));


 LCD_voidSendPulse();

}

void static LCD_voidSendPulse()
{
	MDIO_u8SetPinValue(LCD_E,DIO_HIGH);
		_delay_ms(1);

		MDIO_u8SetPinValue(LCD_E,DIO_LOW);
		_delay_ms(1);
	}

void LCD_voidSetDDRAM_Adress(u8 A_u8Adress)
{
	// bit 7 must be 1 from datasheet
	SET_BIT(A_u8Adress,7);
	LCD_voidSendCommand(A_u8Adress);

}


void LCD_voidSendData(u8 A_u8Data){

	    MDIO_u8SetPinValue(LCD_RS,DIO_HIGH); //set rs 1 data
	    MDIO_u8SetPinValue(LCD_RW,DIO_LOW);  //write

	    MDIO_u8SetPinValue(LCD_D0,GET_BIT(A_u8Data,0));
		MDIO_u8SetPinValue(LCD_D1,GET_BIT(A_u8Data,1));
		MDIO_u8SetPinValue(LCD_D2,GET_BIT(A_u8Data,2));
		MDIO_u8SetPinValue(LCD_D3,GET_BIT(A_u8Data,3));
		MDIO_u8SetPinValue(LCD_D4,GET_BIT(A_u8Data,4));
		MDIO_u8SetPinValue(LCD_D5,GET_BIT(A_u8Data,5));
		MDIO_u8SetPinValue(LCD_D6,GET_BIT(A_u8Data,6));
		MDIO_u8SetPinValue(LCD_D7,GET_BIT(A_u8Data,7));

		LCD_voidSendPulse();

}

void LCD_voidSendString(const u8* str) {
    if (str == NULL) {
        return; // Handle null pointer case
    }

    while (*str) {
        LCD_voidSendData(*str++);
    }
}
void LCD_voidCreate_SpecialCharacter(u8  *A_u8SpecialChar   ,u8 CGRAM_Index)
{
	//set Adress counter into CGRAM Address
	u8 Adress;
	if (CGRAM_Index <8)
	{
		Adress=CGRAM_Index*8;
		Adress=SET_BIT(Adress,6);
		LCD_voidSendCommand(Adress);



	for (u8  i=0; i<8;i++)
	{
	LCD_voidSendData(A_u8SpecialChar[i]);
	}

	}
	LCD_voidSendCommand(LCD_Return_Home);

}

//AdressINCGROM start from 0 to 7
void LCD_voidDisplay_SpecialCharacter(u8 AdressInCGROM   ,u8 PlaceToDisplay)
{
	LCD_voidSetDDRAM_Adress(PlaceToDisplay);
	LCD_voidSendData(AdressInCGROM);
}



void LCD_voidLeftShift(u8 L_u8ShiftNum)
{
	for(u8 i=0; i<L_u8ShiftNum ;i++)//11 character after 16 bit
				{
					_delay_ms(30);
				LCD_voidSendCommand(LCD_ShiftEntireLeft);
				_delay_ms(100);
				}
}
void LCD_voidRightShift(u8 L_u8ShiftNum)
{
	for(u8 i=0; i<L_u8ShiftNum ;i++)//11 character after 16 bit

	{
	_delay_ms(30);

	LCD_voidSendCommand(LCD_ShiftEntireRight);

	}

}

static void IntToStr(u16 num, u8 *str) {
    u8 i = 0;
    u8 sign = num;

    if (sign < 0) {
        num = -num;
    }

    do {
        str[i++] = num % 10 + '0'; // Get the last digit
        num /= 10; // Remove the last digit
    } while (num > 0);

    if (sign < 0) {
        str[i++] = '-';
    }

    str[i] = '\0'; // Null-terminate the string

    // Reverse the string
    for (u8 j = 0; j < i / 2; j++) {
        u8 temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}

void LCD_Number(u16 num) {
    u8 buffer[10];
    IntToStr(num, buffer);
    LCD_voidSendString(buffer);
}
