/*
 * ADC_Config.h
 *
 *  Created on: Aug 4, 2024
 *      Author: mohaned
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

/* select adjustment for 2 data register */
#define ADC_ADJUSTRIGHT  0
#define ADC_ADJUSTLEFT   1

#define ADC_ADJUST ADC_ADJUSTRIGHT

/*  select presaclar for ADC     */
#define ADC_PSC_2   0b000
#define ADC_PSC_4   0b010
#define ADC_PSC_8   0b011
#define ADC_PSC_16  0b100
#define ADC_PSC_32  0b101
#define ADC_PSC_64  0b110
#define ADC_PSC_128 0b111

#define ADC_PSC ADC_PSC_2

/*  Select Voltage referance  */
#define ADC_EXTERNAL_AREF      0b00  // sensor max voltage
#define ADC_INTERNAL_AVCC      0b01  // 5v for the ADC
#define ADC_INTERNAL256_VREF   0b11  // 2.56 internal

#define ADC_VREF  ADC_INTERNAL_AVCC

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
