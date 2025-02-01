/*
 * Timer2_Private.h
 *
 *  Created on: Aug 1, 2024
 *      Author: mohaned
 */

#ifndef MCAL_TIMER2_TIMER2_PRIVATE_H_
#define MCAL_TIMER2_TIMER2_PRIVATE_H_

#define TCCR2_REG   *(( volatile u8* )(0x45))
#define TCNT2_REG   *(( volatile u8* )(0x44))
#define OCR2_REG    *(( volatile u8* )(0x43))
#define TIMSK_REG   *(( volatile u8* )(0x59))
#define ASSR_REG    *(( volatile u8* )(0x42))
#define TIFR_REG    *(( volatile u8* )(0x58))
#define SFIOR_REG   *(( volatile u8* )(0x50))

//TCCR0 REG
#define CS20   0
#define CS21   1
#define CS22   2
#define WGM21  3
#define COM20  4
#define COM21  5
#define WGM20  6
#define FOC2   7


//TIMSK_REG
#define TOIE0   0
#define OCIE0   1
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5
#define TOIE2   6
#define OCIE2   7

//ASSR_REG
#define TCR2UB   0
#define OCR2UB   1
#define TCN2UB   2
#define AS2      3


//TIFR
#define TOV0   0
#define OCF0   1
#define TOV1   2
#define OCF1B  3
#define OCF1A  4
#define ICF1   5
#define TOV2   6
#define OCF2   7

//SFIOR
#define PSR10   0
#define PSR2   1
#define PUD   2
#define ACME  3

#define ADTS0   5
#define ADTS1   6
#define ADTS2   7

void __vector_5() __attribute__((signal));
void __vector_4() __attribute__((signal));

#endif /* MCAL_TIMER2_TIMER2_PRIVATE_H_ */
