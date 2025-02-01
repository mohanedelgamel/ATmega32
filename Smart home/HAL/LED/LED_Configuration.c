/********************************************************************/
/************************ Author: Omar Tarek ************************/
/************************ Date : 28/7/2024   ************************/
/************************ SWC : LED          ************************/
/************************ Government : ITI   ************************/
/************************ Diploma : One Month  **********************/
/********************************************************************/
#include "../../LIB/STD_TYPES.h"


#include "../../MCAL/DIO/DIO_Interface.h"

#include "LED_Configuration.h"
#include "LED_Private.h"


/* Options : 1- DIO_u8_PORTA
             2- DIO_u8_PORTB
             3- DIO_u8_PORTC
             4- DIO_u8_PORTD */

/* Options : 1- DIO_u8_PIN0
             2- DIO_u8_PIN1
             3- DIO_u8_PIN2
             4- DIO_u8_PIN3 
             4- DIO_u8_PIN4
             4- DIO_u8_PIN5
             4- DIO_u8_PIN6
             4- DIO_u8_PIN7 */

/* Options : 1- LED_OFF
             2- LED_ON */


LED_C LED_AstrConfiguration[LED_NOs] =
{
    {DIO_u8_PORTC, DIO_u8_PIN5, LED_OFF},
    {DIO_u8_PORTC, DIO_u8_PIN6, LED_OFF},
	{DIO_u8_PORTA, DIO_u8_PIN0, LED_OFF}
};
