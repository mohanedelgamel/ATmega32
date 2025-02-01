/********************************************************************/
/************************ Author: Omar Tarek ************************/
/************************ Date : 1/8/2024    ************************/
/************************ SWC : TIMER1       ************************/
/************************ Government : ITI   ************************/
/************************ Diploma : One Month  **********************/
/********************************************************************/
#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H

#define PWM_OCR1A 0
#define PWM_OCR1B 1
#define NON_INVERTING 0
#define INVERTING 1

void TIMER1_voidInit(void);
void TIMER1_voidOVF(void);
void TIMER1_voidSetOVFValue(u16 Copy_u16Value);
u16 TIMER1_u16GetOVFValue(void);
void TIMER1_voidSetOCR(u16 Copy_u16OCRValue);
void TIMER1_voidPWM(u16 Copy_u16OCRValue, u16 Copy_u16ICRValue);
void TIMER1_voidDisable(void);

#endif