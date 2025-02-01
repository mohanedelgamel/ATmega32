/********************************************************************/
/************************ Author: Omar Tarek ************************/
/************************ Date : 1/8/2024    ************************/
/************************ SWC : TIMER1       ************************/
/************************ Government : ITI   ************************/
/************************ Diploma : One Month  **********************/
/********************************************************************/
#ifndef TIMER1_CONFIGURATION_H
#define TIMER1_CONFIGURATION_H

#define FR_CPU 8000000UL

/* Options : 1- NORMAL_MODE
             2- CTC_MODE
             3- PWM_MODE
             4- PHASE_CORRECT_MODE */
#define TIMER1_MODE PWM_MODE



/* Options : 1- NO_PRESCALER
             2- PRESCALER_8
             3- PRESCALER_64
             4- PRESCALER_256
             5- PRESCALER_1024
             6- EXT_FALLING_EDGE
             7- EXT_RISING_EDGE */
#define PRESCALER PRESCALER_8

#endif
