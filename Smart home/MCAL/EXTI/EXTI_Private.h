/**************************************************************************/
/************************ Author: Omar Tarek       ************************/
/************************ Date : 30/7/2024         ************************/
/************************ SWC : External Interrupt ************************/
/************************ Government : ITI         ************************/
/************************ Diploma : One Month      ************************/
/**************************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H
/*************************** Registers ***************************/
#define EXTI_u8_MCUCR_REGISTER  *((volatile u8*)0x55)
#define EXTI_u8_MCUCSR_REGISTER *((volatile u8*)0x54)
#define EXTI_u8_GICR_REGISTER   *((volatile u8*)0x5B)
#define EXTI_u8_GIFR_REGISTER   *((volatile u8*)0x5A)

/*************************** BITS ***************************/
#define EXTI_u8_MCUCR_ISC11_BIT 3 //INT1 Sense Control
#define EXTI_u8_MCUCR_ISC10_BIT 2 //INT1 Sense Control
#define EXTI_u8_MCUCR_ISC01_BIT 1 //INT0 Sense Control
#define EXTI_u8_MCUCR_ISC00_BIT 0 //INT0 Sense Control

#define EXTI_u8_MCUCSR_ISC2_BIT 6 //INT2 Sense Control

#define EXTI_u8_GICR_INT1_BIT 7
#define EXTI_u8_GICR_INT0_BIT 6
#define EXTI_u8_GICR_INT2_BIT 5

#define EXTI_u8_GIFR_INTF1_BIT 7
#define EXTI_u8_GIFR_INTF0_BIT 6
#define EXTI_u8_GIFR_INTF2_BIT 5


/* CONFIGURATIONS */
#define FALLING_EDGE_TRIGGER 0
#define RISING_EDGE_TRIGGER  1
#define ANY_EDGE_TRIGGER     2
#define LOW_LEVEL_TRIGGER    3

#define ENABLE 1
#define DISABLE 0
#endif