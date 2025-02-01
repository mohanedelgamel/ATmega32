/********************************************************************/
/************************ Author: Omar Tarek ************************/
/************************ Date : 5/8/2024    ************************/
/************************ SWC : SERVO        ************************/
/************************ Government : ITI   ************************/
/************************ Diploma : One Month  **********************/
/********************************************************************/
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "SERVO_Configuration.h"
#include "SERVO_Private.h"

SERVO_C SERVO_AstrConfiguration[SERVO_NOs] = 
{
    {DIO_u8_PORTD, DIO_u8_PIN5}
};
