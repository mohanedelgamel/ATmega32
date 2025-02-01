/*
 * SPI_Prog.c
 *
 *  Created on: Aug 8, 2024
 *      Author: mohaned
 */

#include "../../Library/Bit_Math.h"
#include "../../Library/STD_Types.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"


void (*vFunPtr)(void)=NULL;


void SPI_voidInit(){

	/* choose slave or master */
#if SPI_MODE==SPI_MODE_MASTER
	SET_BIT(SPCR_REG,MSTR);
#elif SPI_MODE==SPI_MODE_SLAVE
	CLEAR_BIT(SPCR_REG,MSTR);
#endif

	/* choose clock(prescallar)  */
	SPCR_REG &=~(0b11);
	SPCR_REG |=((SPI_PRESCALLER)&(0b11));

	SPSR_REG &= (~(0b1));
	SPSR_REG |= ((SPI_PRESCALLER>>2)&(0b1));


	/* choose clock Polarity */

#if SPI_CKPOL==SPI_MODE_CKPOL_H
	SET_BIT(SPCR_REG,CPOL);
#elif SPI_CKPOL==SPI_MODE_CKPOL_L
	CLEAR_BIT(SPCR_REG,CPOL);
#endif

	/* choose clock phase */

#if SPI_CKPH==SPI_MODE_CKPH_SAMPLE
	CLEAR_BIT(SPCR_REG,CPHA);
#elif SPI_CKPH==SPI_MODE_CKPH_SETUP
	SET_BIT(SPCR_REG,CPHA);
#endif
	/* choose enable interrupt  */


	/* choose  data direction  MSB or LSB */
#if SPI_DATA_DIR==SPI_DATA_DIR_MSB
	CLEAR_BIT(SPCR_REG,DORD);
#elif SPI_DATA_DIR==SPI_DATA_DIR_LSB
	SET_BIT(SPCR_REG,DORD);
#endif

	/* enable SPI */
	SET_BIT(SPCR_REG,SPE);
}
void SPI_voidSend(u8 Data){

	SPDR_REG=Data;
	while (!(GET_BIT(SPSR_REG,SPIF)));

}
u8   SPI_u8Receive(){
	while (!(GET_BIT(SPSR_REG,SPIF)));
	return SPDR_REG;
}

void SPI_voidSendReceive(u8 Data,u8 *RetValue)
{
	if(RetValue!=NULL)
	{
		//send data
		SPDR_REG=Data;

		//wait value to be delivered
		while (!(GET_BIT(SPSR_REG,SPIF)));

		//receive data from buffer
		*RetValue=SPDR_REG;

	}else
	{

	}
}

void SPI_voidEnable_Interrupt()
{
	SET_BIT(SPCR_REG,SPIE);
}

void SPI_voidDisable_Interrupt()
{
	CLEAR_BIT(SPCR_REG,SPIE);
}

void SPI_SetCallback(void(*fptr)(void))
{
	vFunPtr=fptr;

}

void __vector_12(void)
{
	if (vFunPtr!=NULL)
	{
	vFunPtr();
	}else
	{

	}
}
