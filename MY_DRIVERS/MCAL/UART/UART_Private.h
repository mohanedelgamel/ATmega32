/*
 * UART_Private.h
 *
 *  Created on: Aug 7, 2024
 *      Author: mohaned
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_


#define UCSRC_REG   *((volatile u8 *)(0x40))
#define UCSRB_REG   *((volatile u8 *)(0x2A))
#define UBRRH_REG   *((volatile u8 *)(0x40))
#define UBRRL_REG   *((volatile u8 *)(0x29))
#define UCSRA_REG   *((volatile u8 *)(0x2B))
#define UDR_REG     *((volatile u8 *)(0x2C))

/* UCSRA */
#define RXC     7
#define TXC     6
#define UDRE    5
#define FE      4
#define DOR     3
#define PE      2
#define U2X     1
#define MPCM    0

/* UCSRB */
#define RXCIE   7
#define TXCIE   6
#define UDRIE   5
#define RXEN    4
#define TXEN    3
#define UCSZ2   2
#define RXB8    1
#define TXB8    0

/* UCSRC */
#define URSEL   7
#define UMSEL   6
#define UPM1    5
#define UPM0    4
#define USBS    3
#define UCSZ1   2
#define UCSZ0   1
#define UCPOL   0


#endif /* MCAL_UART_UART_PRIVATE_H_ */
