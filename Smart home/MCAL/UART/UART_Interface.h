/********************************************************************/
/************************ Author: Omar Tarek ************************/
/************************ Date : 11/8/2024   ************************/
/************************ SWC : USART        ************************/
/************************ Government : ITI   ************************/
/************************ Diploma : One Month  **********************/
/********************************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_voidInit(u16 Copy_u16BaudRate);

void UART_voidSendByte(u8 Copy_u8SendData);
u8 UART_u8ReceiveByte(u8 * Copy_Pu8ReceiveDate);

u8 UART_voidSendString(u8 *Copy_Pu8SendString);
u8 UART_u8ReceiveString(u8 * Copy_Pu8ReceiveString, u8 Copy_u8DataLength);
u8 UART_u8CallBackFunction(void(* Copy_PAppFunc)(void));

#endif
