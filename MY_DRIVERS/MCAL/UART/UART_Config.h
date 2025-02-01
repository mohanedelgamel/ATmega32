/*
 * UART_Config.h
 *
 *  Created on: Aug 7, 2024
 *      Author: mohaned
 */

#ifndef MCAL_UART_UART_CONFIG_H_
#define MCAL_UART_UART_CONFIG_H_

/* mode of transmission   */
#define UART_ASYNCHRONOUS  0b0
#define UART_SYNCHRONOUS   0b1

/* parity mode   */
#define UART_PARITY_DISABLED 0b00
#define UART_PARITY_EVEN     0b10
#define UART_PARITY_ODD      0b11

/* number of stop bits   */
#define UART_STOP_BIT1  0b0
#define UART_STOP_BIT2  0b1

/* Data number of bits  */
#define UART_CHARACTER_SIZE_5 0b000
#define UART_CHARACTER_SIZE_6 0b001
#define UART_CHARACTER_SIZE_7 0b010
#define UART_CHARACTER_SIZE_8 0b011
//#define UART_CHARACTER_SIZE_9 0b111

/*  foc=8MH  U2X=0    */
#define UART_BAUDRATE2K4   207
#define UART_BAUDRATE4K8   103
#define UART_BAUDRATE9K6    51
#define UART_BAUDRATE19K2   25
#define UART_BAUDRATE38k4   12




/* Configurations  */

#define UART_MODE              UART_ASYNCHRONOUS
#define UART_STOP_BIT          UART_STOP_BIT2
#define UART_PARITY_MODE       UART_PARITY_DISABLED
#define UART_CHARACTER_SIZE    UART_CHARACTER_SIZE_8
#define UART_BAUDRATE          UART_BAUDRATE9K6

#endif /* MCAL_UART_UART_CONFIG_H_ */
