/********************************************************************/
/************************ Author: Omar Tarek ************************/
/************************ Date : 1/8/2024    ************************/
/************************ SWC : TIMER1       ************************/
/************************ Government : ITI   ************************/
/************************ Diploma : One Month  **********************/
/********************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"

#include "TIMER1_Private.h"
#include "TIMER1_Configuration.h"
#include "TIMER1_Interface.h"

//static void(*TIMER1_pfunction)(void) = NULL;

u32 TIMER1_u16Counts, TIMER1_u16PreLoad;

void TIMER1_voidInit(void)
{
    #if TIMER1_MODE == NORMAL_MODE
    /* Normal Mode */
    CLR_BIT(TIMER1_u8_TCCR1B_REGISTER, TIMER1_TCCR1B_WGM13_BIT);
    CLR_BIT(TIMER1_u8_TCCR1B_REGISTER, TIMER1_TCCR1B_WGM12_BIT);
    CLR_BIT(TIMER1_u8_TCCR1A_REGISTER, TIMER1_TCCR1A_WGM11_BIT);
    CLR_BIT(TIMER1_u8_TCCR1A_REGISTER, TIMER1_TCCR1A_WGM10_BIT);

    /* Enable PIE for Normal Mode */
    SET_BIT(TIMER1_u8_TIMSK_REGISTER, TIMER1_TIMSK_TOIE1_BIT);

    #elif TIMER1_MODE == CTC_MODE
    /* CTC Mode */
    //SET_BIT(TIMER1_u8_TCCR0_REGISTER, TIMER1_TCCR0_WGM01_BIT);
    //CLR_BIT(TIMER1_u8_TCCR0_REGISTER, TIMER1_TCCR0_WGM00_BIT);

    /* Enable PIE for CTC Mode */
    //SET_BIT(TIMER1_u8_TIMSK_REGISTER, TIMER1_TIMSK_OCIE0_BIT);

    #elif TIMER1_MODE == PWM_MODE
    /* PWM Mode with ICR at TOP */
    SET_BIT(TIMER1_u8_TCCR1B_REGISTER, TIMER1_TCCR1B_WGM13_BIT);
    SET_BIT(TIMER1_u8_TCCR1B_REGISTER, TIMER1_TCCR1B_WGM12_BIT);
    SET_BIT(TIMER1_u8_TCCR1A_REGISTER, TIMER1_TCCR1A_WGM11_BIT);
    CLR_BIT(TIMER1_u8_TCCR1A_REGISTER, TIMER1_TCCR1A_WGM10_BIT);

    /* Non-Inverting Mode */
    SET_BIT(TIMER1_u8_TCCR1A_REGISTER, TIMER1_TCCR1A_COM1A1_BIT);
    CLR_BIT(TIMER1_u8_TCCR1A_REGISTER, TIMER1_TCCR1A_COM1A0_BIT);
    #endif

    
}

void TIMER1_voidPWM(u16 Copy_u16OCRValue, u16 Copy_u16ICRValue)
{
    TIMER1_u16_ICR1_REGISTER = Copy_u16ICRValue;

    TIMER1_u16_OCR1A_REGISTER = Copy_u16OCRValue;

    /* Prescaler = 8 */
    CLR_BIT(TIMER1_u8_TCCR1B_REGISTER, TIMER1_TCCR1B_CS12_BIT);
    SET_BIT(TIMER1_u8_TCCR1B_REGISTER, TIMER1_TCCR1B_CS11_BIT);
    CLR_BIT(TIMER1_u8_TCCR1B_REGISTER, TIMER1_TCCR1B_CS10_BIT);
}

void TIMER1_voidSetOCR(u16 Copy_u16OCRValue)
{
    TIMER1_u16_OCR1A_REGISTER = Copy_u16OCRValue;
}

void TIMER1_voidDisable(void)
{
    CLR_BIT(TIMER1_u8_TCCR1B_REGISTER, TIMER1_TCCR1B_CS12_BIT);
    CLR_BIT(TIMER1_u8_TCCR1B_REGISTER, TIMER1_TCCR1B_CS11_BIT);
    CLR_BIT(TIMER1_u8_TCCR1B_REGISTER, TIMER1_TCCR1B_CS10_BIT);
}

void TIMER1_voidOVF(void)
{
    /* Prescaler = 8 */
    CLR_BIT(TIMER1_u8_TCCR1B_REGISTER, TIMER1_TCCR1B_CS12_BIT);
    SET_BIT(TIMER1_u8_TCCR1B_REGISTER, TIMER1_TCCR1B_CS11_BIT);
    CLR_BIT(TIMER1_u8_TCCR1B_REGISTER, TIMER1_TCCR1B_CS10_BIT);
}

void TIMER1_voidSetOVFValue(u16 Copy_u16Value)
{
    TIMER1_u16_TCNT1_REGISTER = Copy_u16Value;
}

u16 TIMER1_u16GetOVFValue(void)
{
    return TIMER1_u16_TCNT1_REGISTER;
}
