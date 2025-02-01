/********************************************************************/
/************************ Author: Omar Tarek ************************/
/************************ Date : 28/7/2024   ************************/
/************************ SWC : LED          ************************/
/************************ Government : ITI   ************************/
/************************ Diploma : One Month  **********************/
/********************************************************************/
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "LED_Private.h"
#include "LED_Configuration.h"



u8 LED_u8Init(LED_C * Copy_pstrLEDs)
{
    u8 Local_u8Counter = 0, Local_u8ErrorState = STD_TYPE_OK;
    for (Local_u8Counter = 0; Local_u8Counter < LED_NOs; Local_u8Counter++)
    {
        DIO_u8SetPinDirection(Copy_pstrLEDs[Local_u8Counter].LED_u8PortID, Copy_pstrLEDs[Local_u8Counter].LED_u8PinID, DIO_u8_OUTPUT);
        if (Copy_pstrLEDs[Local_u8Counter].LED_u8InitState == LED_ON)
        {
            DIO_u8SetPinValue(Copy_pstrLEDs[Local_u8Counter].LED_u8PortID, Copy_pstrLEDs[Local_u8Counter].LED_u8PinID, DIO_u8_HIGH);
        }
        else if (Copy_pstrLEDs[Local_u8Counter].LED_u8InitState == LED_OFF)
        {
            DIO_u8SetPinValue(Copy_pstrLEDs[Local_u8Counter].LED_u8PortID, Copy_pstrLEDs[Local_u8Counter].LED_u8PinID, DIO_u8_LOW);
        }
        else
        {
            Local_u8ErrorState = STD_TYPE_NOK;
        }
    }
    return Local_u8ErrorState;
}

u8 LED_u8SetLedHigh(LED_C * Copy_pstrLEDs)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    if (Copy_pstrLEDs != NULL)
    {
        DIO_u8SetPinValue(Copy_pstrLEDs->LED_u8PortID, Copy_pstrLEDs->LED_u8PinID, DIO_u8_HIGH);
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    return Local_u8ErrorState;
}

u8 LED_u8SetLedLow(LED_C * Copy_pstrLEDs)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    if (Copy_pstrLEDs != NULL)
    {
        DIO_u8SetPinValue(Copy_pstrLEDs->LED_u8PortID, Copy_pstrLEDs->LED_u8PinID, DIO_u8_LOW);
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    return Local_u8ErrorState;
}
