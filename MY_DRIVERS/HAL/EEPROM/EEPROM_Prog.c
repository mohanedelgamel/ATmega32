/*
 * EEPROM_Prog.c
 *
 *  Created on: Aug 12, 2024
 *      Author: mohaned
 */

#include "../../Library/Bit_Math.h"
#include "../../Library/STD_Types.h"
#include "../../MCAL/I2C/I2C_Interface.h"
#include "../../MCAL/I2C/I2C_Private.h"
#include "../../MCAL/DIO/DIO_Interface.h"

#include <util/delay.h>
#include "EEPROM_Config.h"
#include "EEPROM_Interface.h"
#include "EEPROM_Private.h"

void EEPROM_Init(){

	//set pins as input
	MDIO_u8SetPinDirection(DIO_PORTC,DIO_PIN0,DIO_INPUT);
	MDIO_u8SetPinDirection(DIO_PORTC,DIO_PIN1,DIO_INPUT);
	//close pull up to use open drain method
	MDIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_LOW);
	MDIO_u8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_LOW);

	I2C_InitMater(10000);
}
u8 EEPROM_SendByte(u8 Byte,u16 Address){

	u8 state=1;
/*1 0 1 0 A2 D9 D8 RW   */  //for model 24C08

/*1 0 1 0 A2 A1 A0 RW   */  //for model 24C02


	//24C08

	//--------------------4Bits ------1bit------------------2bit
	u8 Device_Address=  ( (0b1010<<4) |  ((EEPROM_A2_VAL&1)<<3)  | ( ( ( (Address>>8) &3 )<<1)  &  (~1) )  );


	u8 Data_Address=(u8)Address;//get first 8 bit

	//send start
	I2C_SendStart();

	//send device address
	//for easier calculation drop the operation value and let i2c fun write op
	Device_Address=Device_Address>>1;
	state =I2C_SendAdrress(Device_Address,I2C_WRITE_OP);
	if (state != I2C_MASTER_STATE_SLA_W_ACK){
		I2C_SendStop();
		return state;
	}
	//send rest 8 bit of adrres
	state =I2C_SendData(Data_Address);
	if (state != I2C_MASTER_STATE_DATA_TR_ACK ){
			I2C_SendStop();
			return state;
		}

	//send data to be written inside EEprom
	state =I2C_SendData(Byte);
		if (state != I2C_MASTER_STATE_DATA_TR_ACK ){
				I2C_SendStop();
				return state;
			}

	I2C_SendStop();
	return state;

}






u8   EEPROM_ReadByte(u8  *Buffer,u16 Address)
{
	u8 state=1;
/*1 0 1 0 A2 D9 D8 RW   */  //for model 24C08

/*1 0 1 0 A2 A1 A0 RW   */  //for model 24C02


	//24C08

	//--------------------4Bits ------1bit------------------2bit
	//u8 Device_Address=  ( (0b1010<<4) |  ((EEPROM_A2_VAL&1)<<3)  | (  ( (Address>>8) &3 )  &  (~1) )  );
	//u8 Data_Address=(u8)Address;//get first 8 bit

	//send start
	I2C_SendStart();

	//send device address
	//for easier calculation drop the operation value and let i2c fun write op
	//Device_Address=Device_Address>>1;
	state =I2C_SendAdrress( ((0x50) | (EEPROM_A2_VAL<<2) | ((Address >> 8) & 3) ),I2C_WRITE_OP);

	if (state != I2C_MASTER_STATE_SLA_W_ACK){
		I2C_SendStop();
		return state;
	}
	//send rest 8 bit of adrres
	state =I2C_SendData((u8)Address);
	if (state != I2C_MASTER_STATE_DATA_TR_ACK){
			I2C_SendStop();
			return state;
		}


//	CLEAR_BIT(TWCR_REG,TWSTA);
	//restart after setting address pointer to specific address to be read


	I2C_SendRepeatedStart();



	//send device address
		//for easier calculation drop the operation value and let i2c fun write op

	//Device_Address=Device_Address>>1;
		state =I2C_SendAdrress((  (0x50) | (EEPROM_A2_VAL<<2) | ((Address >> 8) & 3) ),I2C_READ_OP);
		if (state != I2C_MASTER_STATE_SLA_R_ACK){
			I2C_SendStop();
			return state;
		}



		*Buffer=I2C_ReceiveWithoutACK();
		I2C_SendStop();

		return state;

}




