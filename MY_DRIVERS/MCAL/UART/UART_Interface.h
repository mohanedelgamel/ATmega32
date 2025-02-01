/*
 * UART_Interface.h
 *
 *  Created on: Aug 7, 2024
 *      Author: mohaned
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_
#include "../../Library/STD_Types.h"

void UART_Init();
void UART_SendData(u8 Data);
u8 UART_ReceiveData();


#endif /* MCAL_UART_UART_INTERFACE_H_ */
