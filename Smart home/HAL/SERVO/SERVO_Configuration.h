/********************************************************************/
/************************ Author: Omar Tarek ************************/
/************************ Date : 5/8/2024    ************************/
/************************ SWC : SERVO        ************************/
/************************ Government : ITI   ************************/
/************************ Diploma : One Month  **********************/
/********************************************************************/
#ifndef SERVO_CONFIGURATION_H
#define SERVO_CONFIGURATION_H

#define SERVO_NOs 1

typedef struct SERVO_Configuration
{
    u8 SERVO_u8Port;
    u8 SERVO_u8Pin;
}SERVO_C;

#define MAX_ANGLE 180
#define MIN_ANGLE 0

#define MAX_OCR 1999 // 180
#define MIN_OCR 999 // 0

#endif