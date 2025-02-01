/********************************************************************/
/************************ Author: Omar Tarek ************************/
/************************ Date : 25/7/2024   ************************/
/************************ SWC : DIO          ************************/
/************************ Government : ITI   ************************/
/************************ Diploma : One Month  **********************/
/********************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"

#include "GIE_Interface.h"

#define GIE_u8_SREG *((volatile u8 *)0x5F) //Enable Interrupt Registers
#define GIE_u8_SREG_BIT 7

void GIE_voidEnable(void)
{
    /* Enable SREG (GIE) */
    SET_BIT(GIE_u8_SREG, GIE_u8_SREG_BIT);
}

void GIE_voidDisable(void)
{
    /* Disable SREG (GIE) */
    CLR_BIT(GIE_u8_SREG, GIE_u8_SREG_BIT);
}
