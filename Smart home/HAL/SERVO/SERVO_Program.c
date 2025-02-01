/********************************************************************/
/************************ Author: Omar Tarek ************************/
/************************ Date : 5/8/2024    ************************/
/************************ SWC : SERVO        ************************/
/************************ Government : ITI   ************************/
/************************ Diploma : One Month  **********************/
/********************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMERS/TIMER1_Interface.h"

#include "SERVO_Configuration.h"
#include "SERVO_Private.h"


void SERVO_voidPinInit(SERVO_C *Copy_strServos)
{
    u8 Local_u8Counter;
    for (Local_u8Counter = 0; Local_u8Counter < SERVO_NOs; Local_u8Counter++)
    {
        DIO_u8SetPinDirection(Copy_strServos[Local_u8Counter].SERVO_u8Port, Copy_strServos[Local_u8Counter].SERVO_u8Pin, DIO_u8_OUTPUT);
        DIO_u8SetPinValue(Copy_strServos[Local_u8Counter].SERVO_u8Port, Copy_strServos[Local_u8Counter].SERVO_u8Pin, DIO_u8_LOW);
    }
    
}

void SERVO_voidInit(void)
{
    TIMER1_voidInit();
    TIMER1_voidPWM(999, 19999);
}

u8 SERVO_u8SetAngle(u8 Copy_u8Angle, SERVO_C *Copy_strServoID)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    u32 Local_u32AngleOCR;
    while(Copy_u8Angle > 180) {
        Copy_u8Angle -= 180;
    }
    if (Copy_strServoID != NULL)
    {
        Local_u32AngleOCR = (u32)((5.556f * Copy_u8Angle) + MIN_OCR);
        TIMER1_voidSetOCR(Local_u32AngleOCR);
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    return Local_u8ErrorState;
}
