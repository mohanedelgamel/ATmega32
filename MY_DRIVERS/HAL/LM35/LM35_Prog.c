/*
 * LM35_Prog.c
 *
 *  Created on: Aug 4, 2024
 *      Author: mohaned
 */

#include "LM35_Config.h"
#include "LM35_Private.h"
#include "LM35_Interface.h"

#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../Library/STD_Types.h"
u8 LM35_voidInit(){
	ADC_voidInit();
	ADC_voidSelectChannel(LM35_CH);

}
u8 LM35_voidGetTemp(){

	u16 adc=ADC_u16StartConversion();

	return(adc*5*100)/1024;
}

u8 * LM35_IntToStr(u16 num, u8 str[6])
{ u8 i = 0;
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
