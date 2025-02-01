/********************************************************************/
/************************ Author: Omar Tarek ************************/
/************************ Date : 13/8/2024   ************************/
/************************ SWC : TWI          ************************/
/************************ Government : ITI   ************************/
/************************ Diploma : One Month  **********************/
/********************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"

#include "TWI_Private.h"
#include "TWI_Interface.h"
#include "TWI_Configuration.h"

void TWI_voidMasterInit(u32 Copy_u32BitRate) {

    // Enable I2C
    SET_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWEN_BIT);

    // Set prescaler value (prescaler = 1)
    CLR_BIT(TWI_u8_TWSR_REGISTER, TWI_u8_TWSR_TWPS1_BIT);
    CLR_BIT(TWI_u8_TWSR_REGISTER, TWI_u8_TWSR_TWPS0_BIT);

    // Set TWBR for the desired bit rate
    TWI_u8_TWBR_REGISTER = (((u32)(8000000)) / (8*Copy_u32BitRate)) - 2 ;

    // Enable ACK
    TWI_u8_TWCR_REGISTER = (1<<TWI_u8_TWCR_TWEA_BIT) | (1<<TWI_u8_TWCR_TWINT_BIT) | (1<<TWI_u8_TWCR_TWEN_BIT);
}

TWI_ErrorState TWI_u8SlaveInit(u8 Copy_u8SlaveAddress) {
    TWI_ErrorState Local_enuErrorState = TWI_OK;

    // Enable I2C
    TWI_u8_TWCR_REGISTER = (1<<TWI_u8_TWCR_TWEN_BIT);

    // Set slave address (shifted left by 1) and clear the TWGCE bit
    TWI_U8_TWAR_REGISTER = (Copy_u8SlaveAddress << 1) & 0xFE;

    // Enable ACK
    TWI_u8_TWCR_REGISTER = (1<<TWI_u8_TWCR_TWEA_BIT) | (1<<TWI_u8_TWCR_TWINT_BIT) | (1<<TWI_u8_TWCR_TWEN_BIT);

    return Local_enuErrorState;
}

TWI_ErrorState TWI_u8SendStartCondition(void) {
    TWI_ErrorState Local_enuErrorState = TWI_OK;

    // Send start condition
    TWI_u8_TWCR_REGISTER = (1<<TWI_u8_TWCR_TWINT_BIT) | (1<<TWI_u8_TWCR_TWSTA_BIT) | (1 << TWI_u8_TWCR_TWEN_BIT);

    // Wait for TWINT flag to set
    while (GET_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWINT_BIT) == 0);

    // Check the status register for a successful start condition
    if ((TWI_u8_TWSR_REGISTER & 0xF8) != MASTER_START_CONDITION) {
        Local_enuErrorState = TWI_SC_Error;
    }


    return Local_enuErrorState;
}

TWI_ErrorState TWI_u8SendRepeatedStartCondition(void)
{
    TWI_ErrorState Local_enuErrorState = TWI_OK;

    //clear flag + start condition
    TWI_u8_TWCR_REGISTER = (1<<TWI_u8_TWCR_TWINT_BIT) | (1<<TWI_u8_TWCR_TWSTA_BIT) | (1 << TWI_u8_TWCR_TWEN_BIT);

    //check the flag while(!= 1)
    while(!(GET_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWINT_BIT)));

    //check status code for repeated start condition ACK
    if (((TWI_u8_TWSR_REGISTER & 0xF8) != MASTER_REPEATED_START_CONDITION) )
    {
        Local_enuErrorState = TWI_RSC_Error;
    }

    return Local_enuErrorState;
}

TWI_ErrorState TWI_u8SendStopCondition(void) {
    TWI_ErrorState Local_enuErrorState = TWI_OK;

    // Send stop condition
    TWI_u8_TWCR_REGISTER = (1<<TWI_u8_TWCR_TWINT_BIT) | (1<<TWI_u8_TWCR_TWEN_BIT) | (1 << TWI_u8_TWCR_TWSTO_BIT);

    // Stop condition will clear TWSTO automatically, no need to check TWINT
    return Local_enuErrorState;
}

TWI_ErrorState TWI_u8SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress) {
    TWI_ErrorState Local_enuErrorState = TWI_OK;

    // Load slave address with write bit (0)
    TWI_u8_TWDR_REGISTER = (Copy_u8SlaveAddress << 1) & 0xFE;

    // Clear the TWINT bit to start transmission
    TWI_u8_TWCR_REGISTER = (1<<TWI_u8_TWCR_TWINT_BIT) | (1 << TWI_u8_TWCR_TWEN_BIT);

    // Wait for TWINT flag to set
    while (GET_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWINT_BIT) == 0);

    // Check status register for ACK
    if ((TWI_u8_TWSR_REGISTER & 0xF8) != MASTER_SLA_W_ACK) {
        Local_enuErrorState = TWI_SLA_W_Error;
    }

    return Local_enuErrorState;
}

TWI_ErrorState TWI_u8SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress) {
    TWI_ErrorState Local_enuErrorState = TWI_OK;

    // Load slave address with read bit (1)
    TWI_u8_TWDR_REGISTER = (Copy_u8SlaveAddress << 1) | 0x01;

    // Clear the TWINT bit to start transmission
    TWI_u8_TWCR_REGISTER = (1<<TWI_u8_TWCR_TWINT_BIT) | (1 << TWI_u8_TWCR_TWEN_BIT);

    // Wait for TWINT flag to set
    while (GET_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWINT_BIT) == 0);

    // Check status register for ACK
    if ((TWI_u8_TWSR_REGISTER & 0xF8) != MASTER_SLA_R_ACK) {
        Local_enuErrorState = TWI_SLA_R_Error;
    }

    return Local_enuErrorState;
}

TWI_ErrorState TWI_u8SendDataByte(u8 Copy_u8DataByte) {
    TWI_ErrorState Local_enuErrorState = TWI_OK;

    // Load data into TWDR register
    TWI_u8_TWDR_REGISTER = Copy_u8DataByte;

    // Clear the TWINT bit to start transmission
    TWI_u8_TWCR_REGISTER = (1<<TWI_u8_TWCR_TWINT_BIT) | (1<<TWI_u8_TWCR_TWEN_BIT);

    // Wait for TWINT flag to set
    while (GET_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWINT_BIT) == 0);

    // Check status register for ACK
    if ((TWI_u8_TWSR_REGISTER & 0xF8) != MASTER_DATA_TRANSMITTED_ACK) {
        Local_enuErrorState = TWI_MT_DATA_Error;
    }

    return Local_enuErrorState;
}


TWI_ErrorState TWI_u8ReceiveDataByteWithAck(u8 *Copy_pu8DataByte) {
    TWI_ErrorState Local_enuErrorState = TWI_OK;

    // Check if the pointer is not null
    if (Copy_pu8DataByte == NULL) {
        return TWI_NULL_POINTER;
    }

    // Clear the TWINT bit to start receiving
    TWI_u8_TWCR_REGISTER = (1<<TWI_u8_TWCR_TWINT_BIT) | (1<<TWI_u8_TWCR_TWEA_BIT) | (1 << TWI_u8_TWCR_TWEN_BIT);

    // Wait for TWINT flag to set
    while (GET_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWINT_BIT) == 0);

    // Check status register for ACK
    if ((TWI_u8_TWSR_REGISTER & 0xF8) != MASTER_DATA_RECEIVED_ACK) {
        Local_enuErrorState = TWI_MR_DATA_Error;
    } else {
        // Read data from TWDR register
        *Copy_pu8DataByte = TWI_u8_TWDR_REGISTER;
    }

    return Local_enuErrorState;
}

TWI_ErrorState TWI_u8ReceiveDataByteWithoutACK(u8 *Copy_pu8DataByte) {
    TWI_ErrorState Local_enuErrorState = TWI_OK;

    // Check if the pointer is not null
    if (Copy_pu8DataByte == NULL) {
        return TWI_NULL_POINTER;
    }

    // Clear the TWINT bit to start receiving
    TWI_u8_TWCR_REGISTER = (1<<TWI_u8_TWCR_TWINT_BIT) | (1 << TWI_u8_TWCR_TWEN_BIT);

    // Wait for TWINT flag to set
    while (GET_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWINT_BIT) == 0);

    *Copy_pu8DataByte = TWI_u8_TWDR_REGISTER;

    // Check status register for ACK
    if ((TWI_u8_TWSR_REGISTER & 0xF8) != MASTER_DATA_RECEIVED_ACK) {
        Local_enuErrorState = TWI_MR_DATA_Error;
    }

    return Local_enuErrorState;
}
TWI_ErrorState TWI_enuSendFrame(u8 Copy_u8Address, u8 *Copy_Pu8Buffer, u8 Copy_u8Length) {
    TWI_ErrorState Local_enuState = TWI_OK;

    // Send start condition
    Local_enuState = TWI_u8SendStartCondition();
    if (Local_enuState != TWI_OK) {
        TWI_u8SendStopCondition();
        return Local_enuState;
    }

    // Send slave address with write
    Local_enuState = TWI_u8SendSlaveAddressWithWrite(Copy_u8Address);
    if (Local_enuState != TWI_OK) {
        TWI_u8SendStopCondition();
        return Local_enuState;
    }

    // Send data bytes
    for (u8 Local_u8Counter = 0; Local_u8Counter < Copy_u8Length; Local_u8Counter++) {
            Local_enuState = TWI_u8SendDataByte(Copy_Pu8Buffer[Local_u8Counter]);
            if (Local_enuState != TWI_OK) {
                TWI_u8SendStopCondition();
                return Local_enuState;
            }
        }


    // Send stop condition
    Local_enuState = TWI_u8SendStopCondition();

    return Local_enuState;
}
