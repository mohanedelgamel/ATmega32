/********************************************************************/
/************************ Author: Omar Tarek ************************/
/************************ Date : 15/8/2024   ************************/
/************************ SWC : EEPROM       ************************/
/************************ Government : ITI   ************************/
/************************ Diploma : One Month  **********************/
/********************************************************************/

#ifndef EEPROM_PRIVATE_H
#define EEPROM_PRIVATE_H

void EEPROM_voidInit(void);
u8 EEPROM_u8SendByte(u8 Copy_u8DataByte, u16 Copy_u16Address);
u8 EEPROM_u8ReadByte(u8 * Copy_Pu8DataByte, u16 Copy_u16Address);

#endif