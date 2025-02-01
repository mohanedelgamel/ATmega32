/********************************************************************/
/************************ Author: Omar Tarek ************************/
/************************ Date : 5/8/2024    ************************/
/************************ SWC : SERVO        ************************/
/************************ Government : ITI   ************************/
/************************ Diploma : One Month  **********************/
/********************************************************************/
#ifndef SERVO_INTERFACE_H
#define SERVO_INTERFACE_H

void SERVO_voidPinInit(SERVO_C *Copy_strServos);
void SERVO_voidInit(void);
u8 SERVO_u8SetAngle(u8 Copy_u8Angle, SERVO_C *Copy_strServoID);

#endif