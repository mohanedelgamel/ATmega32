/*
 * Timer1_Private.h
 *
 *  Created on: Aug 5, 2024
 *      Author: mohaned
 */

#ifndef MCAL_TIMER1_TIMER1_PRIVATE_H_
#define MCAL_TIMER1_TIMER1_PRIVATE_H_


#define  TCCR1A_REG *((volatile u8 *) (0x4F))
#define  TCCR1B_REG *((volatile u8 *) (0x4E))
#define  TCNT1L_REG *((volatile u16 *)(0x4C))
#define  OCR1AL_REG *((volatile u16 *)(0x4A))
#define  OCR1BL_REG *((volatile u16 *)(0x48))
#define  ICR1L_REG  *((volatile u16 *)(0x46))
#define  TIMSK_REG  *((volatile u8 *) (0x59))
#define  TIFR_REG   *((volatile u8 *) (0x58))



//TCCR1A_REG
#define WGM10   0
#define WGM11   1
#define FOC1B   2
#define FOC1A   3
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7

//TCCR1B_REG
#define CS10   0
#define CS11   1
#define CS12   2
#define WGM12  3
#define WGM13  4

#define ICES1  6
#define ICNC1  7


//TIMSK_REG

#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5


//TIFR_REG

#define TOV1   2
#define OCF1B  3
#define OCF1A  4
#define ICF1   5

#endif /* MCAL_TIMER1_TIMER1_PRIVATE_H_ */
