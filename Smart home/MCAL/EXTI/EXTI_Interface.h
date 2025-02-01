/**************************************************************************/
/************************ Author: Omar Tarek       ************************/
/************************ Date : 30/7/2024         ************************/
/************************ SWC : External Interrupt ************************/
/************************ Government : ITI         ************************/
/************************ Diploma : One Month      ************************/
/**************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define INT0 0 //PD2
#define INT1 1 //PD3
#define INT2 2 //PB2

#define FALLING_EDGE 0
#define RISING_EDGE  1
#define ANY_EDGE     2
#define LOW_LEVEL    3

void EXTI_voidInit(void);
u8 EXTI_u8Enable(u8 Copy_u8EXTIPin, u8 Copy_u8Trigger);
u8 EXTI_u8Disable(u8 Copy_u8EXTIPin);
u8 EXTI_u8SetCallBack(u8 Copy_u8EXTIPin, void(*Copy_pfApp)(void));

#endif