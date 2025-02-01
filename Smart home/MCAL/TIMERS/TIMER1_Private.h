/********************************************************************/
/************************ Author: Omar Tarek ************************/
/************************ Date : 1/8/2024    ************************/
/************************ SWC : TIMER1       ************************/
/************************ Government : ITI   ************************/
/************************ Diploma : One Month  **********************/
/********************************************************************/
#ifndef TIMER1_PRIVATE_H
#define TIMER1_PRIVATE_H

#define TIMER1_u8_TCCR1A_REGISTER *((volatile u8*)0x4F)
#define TIMER1_u8_TCCR1B_REGISTER *((volatile u8*)0x4E)

#define TIMER1_u8_TCNT1H_REGISTER *((volatile u8*)0x4D)
#define TIMER1_u8_TCNT1L_REGISTER *((volatile u8*)0x4C)
#define TIMER1_u16_TCNT1_REGISTER *((volatile u16*)0x4C)

#define TIMER1_u8_OCR1AH_REGISTER  *((volatile u8*)0x4B)
#define TIMER1_u8_OCR1AL_REGISTER  *((volatile u8*)0x4A)
#define TIMER1_u16_OCR1A_REGISTER  *((volatile u16*)0x4A)

#define TIMER1_u8_OCR1BH_REGISTER  *((volatile u8*)0x49)
#define TIMER1_u8_OCR1BL_REGISTER  *((volatile u8*)0x48)
#define TIMER1_u16_OCR1B_REGISTER  *((volatile u16*)0x48)

#define TIMER1_u8_ICR1H_REGISTER  *((volatile u8*)0x47)
#define TIMER1_u8_ICR1L_REGISTER  *((volatile u8*)0x46)
#define TIMER1_u16_ICR1_REGISTER  *((volatile u16*)0x46)

#define TIMER1_u8_TIMSK_REGISTER *((volatile u8*)0x59)
#define TIMER1_u8_TIFR_REGISTER  *((volatile u8*)0x58)

/* Bits of TIMSK */
#define TIMER1_TIMSK_TICIE1_BIT 5
#define TIMER1_TIMSK_OCIE1A_BIT 4
#define TIMER1_TIMSK_OCIE1B_BIT 3
#define TIMER1_TIMSK_TOIE1_BIT  2

/* Bits of TIFR */
#define TIMER1_TIFR_ICF1_BIT  5
#define TIMER1_TIFR_OCF1A_BIT 4
#define TIMER1_TIFR_OCF1B_BIT 3
#define TIMER1_TIFR_TOV1_BIT  2

/* Bits of TCCR1A */
#define TIMER1_TCCR1A_COM1A1_BIT  7
#define TIMER1_TCCR1A_COM1A0_BIT  6
#define TIMER1_TCCR1A_COM1B1_BIT  5
#define TIMER1_TCCR1A_COM1B0_BIT  4
#define TIMER1_TCCR1A_FOC1A_BIT   3
#define TIMER1_TCCR1A_FOC1B_BIT   2
#define TIMER1_TCCR1A_WGM11_BIT   1
#define TIMER1_TCCR1A_WGM10_BIT   0

/* Bits of TCCR1B */
#define TIMER1_TCCR1B_ICNC1_BIT  7
#define TIMER1_TCCR1B_ICES1_BIT  6
#define TIMER1_TCCR1B_WGM13_BIT  4
#define TIMER1_TCCR1B_WGM12_BIT  3
#define TIMER1_TCCR1B_CS12_BIT   2
#define TIMER1_TCCR1B_CS11_BIT   1
#define TIMER1_TCCR1B_CS10_BIT   0

/***********************************/
#define NORMAL_MODE         0
#define CTC_MODE            1
#define PWM_MODE            2
#define PHASE_CORRECT_MODE  3

/***********************************/

#define NO_PRESCALER        0
#define EXT_FALLING_EDGE    1
#define EXT_RISING_EDGE     2
#define PRESCALER_8         8
#define PRESCALER_64        64
#define PRESCALER_256       256
#define PRESCALER_1024      1024

/***********************************/
 
#endif