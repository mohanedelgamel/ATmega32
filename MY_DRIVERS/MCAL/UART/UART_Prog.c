/*
 * UART_Prog.c
 *
 *  Created on: Aug 7, 2024
 *      Author: mohaned
 */


#include "UART_Config.h"
#include "UART_Interface.h"
#include "UART_Private.h"


#include "../../Library/Bit_Math.h"
#include "../../Library/STD_Types.h"

void UART_Init(){

	u8 UCSRC_temp=0b10000000;
	/* mode of UART  */
	UCSRC_temp |= (UART_MODE <<UMSEL);

	/* Parity mode  */
	UCSRC_temp |= (UART_PARITY_MODE <<UPM0);

	/* STOP BIT mode  */
	UCSRC_temp |= UART_STOP_BIT <<USBS;

	/* Character size mode  */
		UCSRC_temp |= ((UART_CHARACTER_SIZE &0b11)  <<UCSZ0);
		UCSRB_REG  |= (GET_BIT(UART_CHARACTER_SIZE,2) <<UCSZ2);

		/* BAUDRATE mode  */
		UBRRL_REG = (u8)UART_BAUDRATE;
		UBRRH_REG = (u8)(UART_BAUDRATE>>8) & 0x7f;


		/*Receiver enable  */
		SET_BIT(UCSRB_REG,RXEN);

		/*Transmitter enable  */
		SET_BIT(UCSRB_REG,TXEN);

		UCSRC_REG=UCSRC_temp;
}
void UART_SendData(u8 Data){
	while (GET_BIT(UCSRA_REG,UDRE)==0);
	UDR_REG=Data;


}
u8 UART_ReceiveData()
{
	while (GET_BIT(UCSRA_REG,RXC)==0);
	return UDR_REG;
}
