/*
 * LCD_Config.h
 *
 *  Created on: Jul 28, 2024
 *      Author: mohaned
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

#include "../../Library/STD_Types.h"
//special characters

//const u8  NOKIA_Signal[8]= {0x00, 0x02, 0x02, 0x06, 0x06, 0x0E, 0x0E, 0x1E};


 //control pins
#define LCD_RS  DIO_PORTB,DIO_PIN0
#define LCD_RW  DIO_PORTB,DIO_PIN1
#define LCD_E   DIO_PORTB,DIO_PIN2


//Data pins
#define LCD_D0 DIO_PORTA,DIO_PIN0
#define LCD_D1 DIO_PORTA,DIO_PIN1
#define LCD_D2 DIO_PORTA,DIO_PIN2
#define LCD_D3 DIO_PORTA,DIO_PIN3
#define LCD_D4 DIO_PORTA,DIO_PIN4
#define LCD_D5 DIO_PORTA,DIO_PIN5
#define LCD_D6 DIO_PORTA,DIO_PIN6
#define LCD_D7 DIO_PORTA,DIO_PIN7




#endif /* HAL_LCD_LCD_CONFIG_H_ */
