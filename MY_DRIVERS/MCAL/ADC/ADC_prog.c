/*
 * ADC_prog.c
 *
 *  Created on: Aug 4, 2024
 *      Author: mohaned
 */

#include "../../Library/Bit_Math.h"
#include "../../Library/STD_Types.h"

#include "ADC_Config.h"
#include "ADC_Private.h"
#include "ADC_Interface.h"


void (*ADC_Ptr)(void);


void ADC_voidInit(){
	ADCSRA_REG=0;
	ADMUX_REG=0;

	//Enable adc peripheral
	SET_BIT(ADCSRA_REG,ADEN);

	//Select prescalar
	ADCSRA_REG |=(ADC_PSC<<ADPS0);

	//select adjustment
	ADMUX_REG |= (ADC_ADJUST<<ADLAR);

	//select VREF
	ADMUX_REG |= (ADC_VREF<<REFS0);

}
void ADC_voidSelectChannel(u8 L_u8Channel){

	ADMUX_REG &= 0b11100000; // clear bits of channels
	ADMUX_REG |= L_u8Channel <<MUX0; // set the bits according config
}
u16 ADC_u16StartConversion(void){
	//start conversion bit
	SET_BIT(ADCSRA_REG,ADSC);

	//wait until conversion complete

	while (GET_BIT(ADCSRA_REG,ADSC))
	{
		//do nothing
	}

	SET_BIT(ADCSRA_REG,ADIF);
	return ADCDATA_REG;

}


u8 * ADC_IntToStr(u16 num, u8 str[6]) {
    u8 i = 0;
    u8 j;
    u8 temp;

    // Convert the number to string
    do {
        str[i++] = (num % 10) + '0'; // Convert digit to character
        num /= 10;
    } while (num > 0);

    // Null-terminate the string
    str[i] = '\0';

    // Reverse the string
    for (j = 0; j < i / 2; j++) {
        temp = str[j];
        str[j] = str[i - 1 - j];
        str[i - 1 - j] = temp;
    }

    return str;
}

void ADC_voidInterruptEnable()
{
	SET_BIT(ADCSRA_REG,ADIE);
}



void ADC_SetCallBack(void(*ptr)(void))
{
	if (GET_BIT(ADCSRA_REG,ADIF))
	{
	ADC_Ptr=ptr;
	}

}

void __vector_16()
{
	ADC_Ptr();
}

