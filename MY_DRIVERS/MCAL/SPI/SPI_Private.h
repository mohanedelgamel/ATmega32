/*
 * SPI_Private.h
 *
 *  Created on: Aug 8, 2024
 *      Author: mohaned
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

#define SPCR_REG   *((volatile u8*)(0x2D))
#define SPSR_REG   *((volatile u8*)(0x2E))
#define SPDR_REG   *((volatile u8*)(0x2F))


/* SPCR */
#define SPIE    7
#define SPE     6
#define DORD    5
#define MSTR    4
#define CPOL    3
#define CPHA    2
#define SPR1    1
#define SPR0    0


/* SPSR */
#define SPIF    7
#define WCOL    6
/* bits 5-1 reserved */
#define SPI2X   0



void __vector_12(void) __attribute__((signal));
#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
