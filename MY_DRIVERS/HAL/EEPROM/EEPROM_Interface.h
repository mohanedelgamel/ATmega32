/*
 * EEPROM_Interface.h
 *
 *  Created on: Aug 12, 2024
 *      Author: mohaned
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

#include "../../Library/STD_Types.h"

/* for model 24C08  A2 is connected to high or low */
#define EEPROM_A2_VAL_HIGH  1
#define EEPROM_A2_VAL_LOW   0



void EEPROM_Init();
u8 EEPROM_SendByte(u8 Byte,u16 Address);
u8 EEPROM_ReadByte(u8 *Buffer,u16 Address);




#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
