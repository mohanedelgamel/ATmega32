/*
 * ADC_Private.h
 *
 *  Created on: Aug 4, 2024
 *      Author: mohaned
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_


#define ADMUX_REG  *((volatile u8 *)(0x27))
#define ADCSRA_REG *((volatile u8 *)(0x26))
#define SFIOR_REG  *((volatile u8 *)(0x50))
#define ADCDATA_REG   *((volatile u16 *)(0x24)) // ADCL + ADCH two registers 24 and 25 to get 10 bits


//ADMUX REG
#define MUX0   0
#define MUX1   1
#define MUX2   2
#define MUX3   3
#define MUX4   4
#define ADLAR  5
#define REFS0  6
#define REFS1  7


//ADCSRA_REG
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

//SFIOR_REG

#define ADTS0    5
#define ADTS1    6
#define ADTS2    7

void __vector_16() __attribute__((signal));

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
