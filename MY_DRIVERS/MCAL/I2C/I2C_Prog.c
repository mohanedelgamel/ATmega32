/*
 * I2C_Prog.c
 *
 *  Created on: Aug 11, 2024
 *      Author: mohaned
 */

#include "../../Library/Bit_Math.h"
#include "../../Library/STD_Types.h"


#include "I2C_Config.h"
#include "I2C_Interface.h"
#include "I2C_Private.h"


void I2C_InitMater(u32 bit_rate)
{
	/* Enable I2C*/
	SET_BIT(TWCR_REG,TWEN);
	/*   select prescalar*/

	CLEAR_BIT(TWSR_REG,TWPS0);
	CLEAR_BIT(TWSR_REG,TWPS1);
	/*set Bit-rate*/
	TWBR_REG = ( ((u32)(8000000) )/(8*bit_rate))-2 ;

}
void I2C_InitSlave()
{
	/* Enable I2C*/
		SET_BIT(TWCR_REG,TWEN);

		/* set slave adrres*/
		TWAR_REG=I2C_SLAVE_ADDREES<<1;


}
u8  I2C_SendStart(){

	/*send start condition and clear twint to start transmission*/
	TWCR_REG = (1<< TWSTA) | (1<< TWINT) | (1 << TWEN);
	/*wait until finish operation */
	while (GET_BIT(TWCR_REG,TWINT)==0);
	/*return status */
		return TWSR_REG &0xF8;



}
u8  I2C_SendAdrress(u8 Adress,u8 Op){

	/*write Address and operation*/

	TWDR_REG= (Adress << TWA0) | Op;

	/*clear flag to start transmission*/
	TWCR_REG = (1<< TWINT) | (1 << TWEN) | (1 << TWEN);
	/*wait until finish operation */
	while (GET_BIT(TWCR_REG,TWINT)==0);

	/*return status */
	return TWSR_REG &0xF8;
}
u8  I2C_SendData(u8 Data){

	/*write Address and operation*/
	TWDR_REG= Data;
	/*clear flag to start transmission*/
	TWCR_REG = (1<< TWINT) | (1 << TWEN);
	/*wait until finish operation */
	while (GET_BIT(TWCR_REG,TWINT)==0);
	/*return status */
		return TWSR_REG &0xF8;

}
void  I2C_SendStop(){

		/*send start condition and clear twint to start transmission*/
	TWCR_REG = (1<< TWSTO) | (1<< TWINT) | (1 << TWEN);


		CLEAR_BIT(TWCR_REG,TWSTA);
}
u8  I2C_ReceiveWithACKCalling()
{
	/*enable ACK and clear FLAG to start transmission*/
	TWCR_REG = (1<< TWEA) | (1<< TWINT) | (1 << TWEN);
			/*wait until finish operation */
			while (GET_BIT(TWCR_REG,TWINT)==0);
			/*return status */
			TWDR_REG=0;
			return TWSR_REG &0xF8;
}
u8  I2C_ReceiveWithACK(){
	/*enable ACK and clear FLAG to start transmission*/
	TWCR_REG = (1<< TWEA) | (1<< TWINT) | (1 << TWEN);
		/*wait until finish operation */
		while (GET_BIT(TWCR_REG,TWINT)==0);
		return TWDR_REG;

}
u8  I2C_ReceiveWithoutACK(){
	/*enable ACK and clear FLAG to start transmission*/
	TWCR_REG = (1<< TWINT) | (1 << TWEN);
			/*wait until finish operation */
			while (GET_BIT(TWCR_REG,TWINT)==0);
			return TWDR_REG;
}

u8 I2C_SendFrame(u8 Address,u8 *Buf,u8 Len)
{
	/*send start cond */
	u8 state ;
	state=I2C_SendStart();

	/*Check if there is an error */
	if (state !=I2C_MASTER_STATE_STA) return state;

	// send address and op over the bus
	state = I2C_SendAdrress(Address,I2C_WRITE_OP);

	// if there is no response or lost arbitration
	if (state != I2C_MASTER_STATE_SLA_W_ACK) return state;


	//send data
	for (u8 i =0 ;i<Len;i++)
	{

		//send data
		state =I2C_SendData(Buf[i]);
		//check if there is data left
		if (state != I2C_MASTER_STATE_DATA_TR_ACK) break ;

	}

	//send stop

	CLEAR_BIT(TWCR_REG,TWSTA);
     I2C_SendStop();
	return state;
}
u8 I2C_SendRepeatedStart() {
    // Send repeated start condition
    SET_BIT(TWCR_REG, TWSTA);
    SET_BIT(TWCR_REG, TWINT);
    while (!(TWCR_REG & (1 << TWINT)));  // Wait for TWINT Flag set
    return TWSR_REG & 0xF8;  // Return status
}
