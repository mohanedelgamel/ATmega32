/*
 * Timer0_Private.h
 *
 *  Created on: Aug 1, 2024
 *      Author: mohaned
 */

#ifndef MCAL_TIMER0_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_TIMER0_PRIVATE_H_

#define TCCR0_REG   *(( volatile u8* )(0x53))
#define TCNT0_REG   *(( volatile u8* )(0x52))
#define OCR0_REG    *(( volatile u8* )(0x5C))
#define TIMSK_REG   *(( volatile u8* )(0x59))

//TCCR0 REG
#define CS00   0
#define CS01   1
#define CS02   2
#define WGM01  3
#define COM00  4
#define COM01  5
#define WGM00  6
#define FOC0   7


//TIMSK_REG
#define TOIE0   0
#define OCIE0   1
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5
#define TOIE2   6
#define OCIE2   7




void __vector_10() __attribute__((signal));
void __vector_11() __attribute__((signal));

#endif /* MCAL_TIMER0_TIMER0_PRIVATE_H_ */
