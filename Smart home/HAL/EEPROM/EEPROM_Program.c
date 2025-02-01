/********************************************************************/
/************************ Author: Omar Tarek ************************/
/************************ Date : 15/8/2024   ************************/
/************************ SWC : EEPROM       ************************/
/************************ Government : ITI   ************************/
/************************ Diploma : One Month  **********************/
/********************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"

#define F_CPU 8000000UL
#include <util\delay.h>

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TWI/TWI_Interface.h"

#include "EEPROM_Private.h"
#include "EEPROM_Configuration.h"
#include "EEPROM_Interface.h"

void EEPROM_voidInit(void)
{
    DIO_u8SetPinDirection(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_INPUT);
    DIO_u8SetPinDirection(DIO_u8_PORTC, DIO_u8_PIN1, DIO_u8_INPUT);
    
    DIO_u8SetPinValue(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_LOW);
    DIO_u8SetPinValue(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_LOW);

    TWI_voidMasterInit(10000);
}


u8 EEPROM_u8SendByte(u8 Copy_u8DataByte, u16 Copy_u16Address)
{
	TWI_ErrorState Local_enuTWIErrorState = TWI_OK;
	u8 Local_u8ErrorState = STD_TYPE_OK;
    u8 Local_u8AddressPacket;

	Local_u8AddressPacket = (EEPROM_FIXED_ADDRESS) | (EEPROM_u8_A2_ADDRESS<<2) | (Copy_u16Address>>8);

	/*Send start condition*/
	Local_enuTWIErrorState = TWI_u8SendStartCondition();
	Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);
	

	/*Send the address packet*/
	Local_enuTWIErrorState = TWI_u8SendSlaveAddressWithWrite(Local_u8AddressPacket);
	Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);

	/*Send the rest 8bits of the location address*/
	Local_enuTWIErrorState = TWI_u8SendDataByte((u8)Copy_u16Address);
	Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);

	/*Send the data byte to the memory location*/
	Local_enuTWIErrorState = TWI_u8SendDataByte(Copy_u8DataByte);
	Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);

	/*Send stop condition*/
	TWI_u8SendStopCondition();

	/*Delay until the write cycle is finished*/
	_delay_ms(10);

	return Local_u8ErrorState;
}

u8 EEPROM_u8ReadByte(u8 * Copy_Pu8DataByte, u16 Copy_u16Address)
{
    TWI_ErrorState Local_enuTWIErrorState = TWI_OK;
	u8 Local_u8ErrorState = STD_TYPE_OK;
    u8 Local_u8AddressPacket;

	Local_u8AddressPacket = (EEPROM_FIXED_ADDRESS) | (EEPROM_u8_A2_ADDRESS<<2) | (Copy_u16Address>>8);

	if (Copy_Pu8DataByte != NULL)
	{
		/*Send start condition*/
		Local_enuTWIErrorState = TWI_u8SendStartCondition();
		Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);

		/*Send the address packet with write request*/
		Local_enuTWIErrorState = TWI_u8SendSlaveAddressWithWrite(Local_u8AddressPacket);
		Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);

		/*Send the rest 8bits of the location address*/
		Local_enuTWIErrorState = TWI_u8SendDataByte((u8)Copy_u16Address);
		Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);

		/*Send repeated start to change write request into read request*/
		Local_enuTWIErrorState = TWI_u8SendRepeatedStartCondition();
		Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);

		/*Send the address packet with read request*/
		Local_enuTWIErrorState = TWI_u8SendSlaveAddressWithRead(Local_u8AddressPacket);
		Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);

		/*Get the data from memory*/
		Local_enuTWIErrorState = TWI_u8ReceiveDataByteWithoutACK(Copy_Pu8DataByte);
		Local_u8ErrorState = Private_u8CheckErrorState(Local_enuTWIErrorState);

		/*send the stop condition*/
		TWI_u8SendStopCondition();

		/*Delay until the write cycle is finished*/
		_delay_ms(10);

	}
	else
	{
		Local_u8ErrorState = STD_TYPE_NOK;
	}

	return Local_u8ErrorState;
}


static u8 Private_u8CheckErrorState(TWI_ErrorState Copy_enuErrorState)
{
	u8 Local_u8ErrorState = STD_TYPE_OK;
	if (Copy_enuErrorState != TWI_OK)
	{
		Local_u8ErrorState = STD_TYPE_NOK;
	}
	return Local_u8ErrorState;
}
