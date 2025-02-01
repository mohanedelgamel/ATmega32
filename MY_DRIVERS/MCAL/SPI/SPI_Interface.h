/*
 * SPI_Interface.h
 *
 *  Created on: Aug 8, 2024
 *      Author: mohaned
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_
#include "../../Library/STD_Types.h"

#define SPI_MODE_MASTER 1
#define SPI_MODE_SLAVE 0

#define SPI_MODE_CKPOL_H 1
#define SPI_MODE_CKPOL_L 0


#define SPI_MODE_CKPH_SAMPLE 0
#define SPI_MODE_CKPH_SETUP  1


#define SPI_DATA_DIR_MSB 0
#define SPI_DATA_DIR_LSB 1

 #define SPI_CLOCK_PRESCALER4   0b000
 #define SPI_CLOCK_PRESCALER16  0b001
 #define SPI_CLOCK_PRESCALER64  0b010
 #define SPI_CLOCK_PRESCALER128 0b011
 #define SPI_CLOCK_PRESCALER2   0b100
 #define SPI_CLOCK_PRESCALER8   0b101
 #define SPI_CLOCK_PRESCALER32  0b110


void SPI_voidInit();
void SPI_voidSend(u8 Data);
u8   SPI_u8Receive();
void SPI_voidSendReceive(u8 Data,u8 *RetValue);
void SPI_voidEnable_Interrupt();
void SPI_voidDisable_Interrupt();


#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
