/********************************************************************/
/************************ Author: Omar Tarek ************************/
/************************ Date : 25/7/2024   ************************/
/************************ SWC : DIO          ************************/
/************************ Government : ITI   ************************/
/************************ Diploma : One Month  **********************/
/********************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"

#include "DIO_Private.h"
#include "DIO_Configuration.h"
#include "DIO_Interface.h"

void DIO_voidInit(void)
{
    DIO_u8_DDRA_REGISTER = DIO_INIT(DIO_u8_PA7_DIRECTION,DIO_u8_PA6_DIRECTION,DIO_u8_PA5_DIRECTION,DIO_u8_PA4_DIRECTION,
						   DIO_u8_PA3_DIRECTION,DIO_u8_PA2_DIRECTION,DIO_u8_PA1_DIRECTION,DIO_u8_PA0_DIRECTION);
    
    DIO_u8_DDRB_REGISTER = DIO_INIT(DIO_u8_PB7_DIRECTION,DIO_u8_PB6_DIRECTION,DIO_u8_PB5_DIRECTION,DIO_u8_PB4_DIRECTION,
						   DIO_u8_PB3_DIRECTION,DIO_u8_PB2_DIRECTION,DIO_u8_PB1_DIRECTION,DIO_u8_PB0_DIRECTION);
    
    DIO_u8_DDRC_REGISTER = DIO_INIT(DIO_u8_PC7_DIRECTION,DIO_u8_PC6_DIRECTION,DIO_u8_PC5_DIRECTION,DIO_u8_PC4_DIRECTION,
						   DIO_u8_PC3_DIRECTION,DIO_u8_PC2_DIRECTION,DIO_u8_PC1_DIRECTION,DIO_u8_PC0_DIRECTION);
    
    DIO_u8_DDRD_REGISTER = DIO_INIT(DIO_u8_PD7_DIRECTION,DIO_u8_PD6_DIRECTION,DIO_u8_PD5_DIRECTION,DIO_u8_PD4_DIRECTION,
						   DIO_u8_PD3_DIRECTION,DIO_u8_PD2_DIRECTION,DIO_u8_PD1_DIRECTION,DIO_u8_PD0_DIRECTION);

    DIO_u8_PORTA_REGISTER = DIO_INIT(DIO_u8_PA7_VALUE,DIO_u8_PA6_VALUE,DIO_u8_PA5_VALUE,DIO_u8_PA4_VALUE,
						   DIO_u8_PA3_VALUE,DIO_u8_PA2_VALUE,DIO_u8_PA1_VALUE,DIO_u8_PA0_VALUE);
											                    
	DIO_u8_PORTB_REGISTER = DIO_INIT(DIO_u8_PB7_VALUE,DIO_u8_PB6_VALUE,DIO_u8_PB5_VALUE,DIO_u8_PB4_VALUE,
						   DIO_u8_PB3_VALUE,DIO_u8_PB2_VALUE,DIO_u8_PB1_VALUE,DIO_u8_PB0_VALUE);
											 
	DIO_u8_PORTC_REGISTER = DIO_INIT(DIO_u8_PC7_VALUE,DIO_u8_PC6_VALUE,DIO_u8_PC5_VALUE,DIO_u8_PC4_VALUE,
						   DIO_u8_PC3_VALUE,DIO_u8_PC2_VALUE,DIO_u8_PC1_VALUE,DIO_u8_PC0_VALUE);
											 
	DIO_u8_PORTD_REGISTER = DIO_INIT(DIO_u8_PD7_VALUE,DIO_u8_PD6_VALUE,DIO_u8_PD5_VALUE,DIO_u8_PD4_VALUE,
						   DIO_u8_PD3_VALUE,DIO_u8_PD2_VALUE,DIO_u8_PD1_VALUE,DIO_u8_PD0_VALUE);
}

u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;

    if ((Copy_u8Port <= DIO_u8_PORTD) && (Copy_u8Pin <= DIO_u8_PIN7) && ((Copy_u8Direction == DIO_u8_OUTPUT) || (Copy_u8Direction == DIO_u8_INPUT)))
    {
        switch (Copy_u8Port)
        {
        case DIO_u8_PORTA:
            switch (Copy_u8Direction)
            {
            case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRA_REGISTER, Copy_u8Pin); break;
            case DIO_u8_INPUT: CLR_BIT(DIO_u8_DDRA_REGISTER, Copy_u8Pin); break;
            }
            break;
        case DIO_u8_PORTB:
            switch (Copy_u8Direction)
            {
            case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRB_REGISTER, Copy_u8Pin); break;
            case DIO_u8_INPUT: CLR_BIT(DIO_u8_DDRB_REGISTER, Copy_u8Pin); break;
            }
            break;
        case DIO_u8_PORTC:
            switch (Copy_u8Direction)
            {
            case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRC_REGISTER, Copy_u8Pin); break;
            case DIO_u8_INPUT: CLR_BIT(DIO_u8_DDRC_REGISTER, Copy_u8Pin); break;
            }
            break;
        case DIO_u8_PORTD:
            switch (Copy_u8Direction)
            {
            case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRD_REGISTER, Copy_u8Pin); break;
            case DIO_u8_INPUT: CLR_BIT(DIO_u8_DDRD_REGISTER, Copy_u8Pin); break;
            }
            break;
        
        default:
            Local_u8ErrorState = STD_TYPE_NOK;
            break;
        }
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    
    return Local_u8ErrorState;
}

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;

    if ((Copy_u8Port <= DIO_u8_PORTD) && (Copy_u8Pin <= DIO_u8_PIN7) && ((Copy_u8Value == DIO_u8_HIGH) || (Copy_u8Value == DIO_u8_LOW)))
    {
        switch (Copy_u8Port)
        {
        case DIO_u8_PORTA:
            switch (Copy_u8Value)
            {
            case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTA_REGISTER, Copy_u8Pin); break;
            case DIO_u8_LOW: CLR_BIT(DIO_u8_PORTA_REGISTER, Copy_u8Pin); break;
            }
            break;
        case DIO_u8_PORTB:
            switch (Copy_u8Value)
            {
            case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTB_REGISTER, Copy_u8Pin); break;
            case DIO_u8_LOW: CLR_BIT(DIO_u8_PORTB_REGISTER, Copy_u8Pin); break;
            }
            break;
        case DIO_u8_PORTC:
            switch (Copy_u8Value)
            {
            case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTC_REGISTER, Copy_u8Pin); break;
            case DIO_u8_LOW: CLR_BIT(DIO_u8_PORTC_REGISTER, Copy_u8Pin); break;
            }
            break;
        case DIO_u8_PORTD:
            switch (Copy_u8Value)
            {
            case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTD_REGISTER, Copy_u8Pin); break;
            case DIO_u8_LOW: CLR_BIT(DIO_u8_PORTD_REGISTER, Copy_u8Pin); break;
            }
            break;
        
        default:
            Local_u8ErrorState = STD_TYPE_NOK;
            break;
        }
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    
    return Local_u8ErrorState;
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_Pu8Value)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    u8 Local_u8PinValue;
    if ((Copy_u8Port <= DIO_u8_PORTD) && (Copy_u8Pin <= DIO_u8_PIN7) && (Copy_Pu8Value != NULL))
    {
        switch (Copy_u8Port)
        {
        case DIO_u8_PORTA:
            Local_u8PinValue = GET_BIT(DIO_u8_PINA_REGISTER, Copy_u8Pin);
            if (Local_u8PinValue == 0) {
               *Copy_Pu8Value = DIO_u8_LOW;
            } else {
               *Copy_Pu8Value = DIO_u8_HIGH;
            }
            break;
        case DIO_u8_PORTB:
            Local_u8PinValue = GET_BIT(DIO_u8_PINB_REGISTER, Copy_u8Pin);
            if (Local_u8PinValue == 0) {
               *Copy_Pu8Value = DIO_u8_LOW;
            } else {
               *Copy_Pu8Value = DIO_u8_HIGH;
            }
            break;
        case DIO_u8_PORTC:
            Local_u8PinValue = GET_BIT(DIO_u8_PINC_REGISTER, Copy_u8Pin);
            if (Local_u8PinValue == 0) {
               *Copy_Pu8Value = DIO_u8_LOW;
            } else {
               *Copy_Pu8Value = DIO_u8_HIGH;
            }
            break;
        case DIO_u8_PORTD:
            Local_u8PinValue = GET_BIT(DIO_u8_PIND_REGISTER, Copy_u8Pin);
            if (Local_u8PinValue == 0) {
               *Copy_Pu8Value = DIO_u8_LOW;
            } else {
               *Copy_Pu8Value = DIO_u8_HIGH;
            }
            break;
        
        default:
            break;
        }
    } else {
        Local_u8ErrorState = STD_TYPE_NOK;
    }

    return Local_u8ErrorState;
}


u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;

    if (Copy_u8Direction == DIO_u8_OUTPUT || Copy_u8Direction == DIO_u8_INPUT)
    {
        switch (Copy_u8Port)
        {
        case DIO_u8_PORTA:
            switch (Copy_u8Direction)
            {
            case DIO_u8_OUTPUT : DIO_u8_DDRA_REGISTER = 0xFF;break;
            case DIO_u8_INPUT : DIO_u8_DDRA_REGISTER = 0x00;break;
            }
            break;
        
        case DIO_u8_PORTB:
            switch (Copy_u8Direction)
            {
            case DIO_u8_OUTPUT : DIO_u8_DDRB_REGISTER = 0xFF;break;
            case DIO_u8_INPUT : DIO_u8_DDRB_REGISTER = 0x00;break;
            }
            break;

        case DIO_u8_PORTC:
            switch (Copy_u8Direction)
            {
            case DIO_u8_OUTPUT : DIO_u8_DDRC_REGISTER = 0xFF;break;
            case DIO_u8_INPUT : DIO_u8_DDRC_REGISTER = 0x00;break;
            }
            break;

        case DIO_u8_PORTD:
            switch (Copy_u8Direction)
            {
            case DIO_u8_OUTPUT : DIO_u8_DDRD_REGISTER = 0xFF;break;
            case DIO_u8_INPUT : DIO_u8_DDRD_REGISTER = 0x00;break;
            }
            break;        

        default: Local_u8ErrorState = STD_TYPE_NOK;
            break;
        }
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    
    return Local_u8ErrorState;
}


u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
    u8 Local_u8ErrorStatue = STD_TYPE_OK;

    switch (Copy_u8Port)
    {
    case DIO_u8_PORTA:
        DIO_u8_PORTA_REGISTER = Copy_u8Value;
        break;
    case DIO_u8_PORTB:
        DIO_u8_PORTB_REGISTER = Copy_u8Value;
        break;
    case DIO_u8_PORTC:
        DIO_u8_PORTC_REGISTER = Copy_u8Value;
        break;
    case DIO_u8_PORTD:
        DIO_u8_PORTD_REGISTER = Copy_u8Value;
        break;
    
    default:
        Local_u8ErrorStatue = STD_TYPE_NOK;
        break;
    }

    return Local_u8ErrorStatue;
    
}

u8 DIO_u8GetPortValue(u8 Copy_u8Port, u8 *Copy_Pu8Value)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;

    if (Copy_Pu8Value != NULL)
    {
        switch (Copy_u8Port)
        {
        case DIO_u8_PORTA: *Copy_Pu8Value = DIO_u8_PINA_REGISTER;break;
        case DIO_u8_PORTB: *Copy_Pu8Value = DIO_u8_PINB_REGISTER;break;
        case DIO_u8_PORTC: *Copy_Pu8Value = DIO_u8_PINC_REGISTER;break;
        case DIO_u8_PORTD: *Copy_Pu8Value = DIO_u8_PIND_REGISTER;break;

        default: Local_u8ErrorState = STD_TYPE_NOK;
            break;
        }
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    
    return Local_u8ErrorState;
}
