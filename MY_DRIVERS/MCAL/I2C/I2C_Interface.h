/*
 * I2C_Interface.h
 *
 *  Created on: Aug 11, 2024
 *      Author: mohaned
 */

#ifndef MCAL_I2C_I2C_INTERFACE_H_
#define MCAL_I2C_I2C_INTERFACE_H_
#include "../../Library/STD_Types.h"

#define I2C_READ_OP  0b1
#define I2C_WRITE_OP 0b0

//master transmit mode
#define I2C_MASTER_STATE_STA                 0x08
#define I2C_MASTER_STATE_REPEATED_STA        0x10
#define I2C_MASTER_STATE_SLA_W_ACK           0x18
#define I2C_MASTER_STATE_SLA_W_NACK          0x20
#define I2C_MASTER_STATE_DATA_TR_ACK         0x28
#define I2C_MASTER_STATE_DATA_TR_NACK        0x30
#define I2C_MASTER_STATE_ARBITRATION_LOST    0x38


#define I2C_MASTER_STATE_SLA_R_ACK           0x40
#define I2C_MASTER_STATE_SLA_R_NACK          0x48
#define I2C_MASTER_STATE_DATA_RC_ACK         0x50
#define I2C_MASTER_STATE_DATA_RC_NACK        0x58

void I2C_InitMater(u32 bit_rate);
void I2C_InitSlave();
u8  I2C_SendStart();
u8  I2C_SendAdrress(u8 Adress,u8 Op);
u8  I2C_SendData(u8 Data);
void  I2C_SendStop();
u8  I2C_ReceiveWithACK();
u8  I2C_ReceiveWithACKCalling();
u8  I2C_ReceiveWithoutACK();
u8 I2C_SendRepeatedStart();

u8 I2C_SendFrame(u8 Address,u8 *Buf,u8 Len);


#endif /* MCAL_I2C_I2C_INTERFACE_H_ */
