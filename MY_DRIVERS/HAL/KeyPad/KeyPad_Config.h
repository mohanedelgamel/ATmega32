/*
 * KeyPad_Config.h
 *
 *  Created on: Jul 30, 2024
 *      Author: mohaned
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

const struct Col {
	u8 C_PORT;
	u8 C_PIN;
};

struct Col Cols[4]= {
	{DIO_PORTD,DIO_PIN0},

	{DIO_PORTD,DIO_PIN1},

	{DIO_PORTD,DIO_PIN2},

	{DIO_PORTD,DIO_PIN3}

};

const struct Row {
	u8 R_PORT;
	u8 R_PIN;
};

struct Row Rows[4]= {
	{DIO_PORTC,DIO_PIN4},

	{DIO_PORTC,DIO_PIN5},

	{DIO_PORTC,DIO_PIN6},

	{DIO_PORTC,DIO_PIN7}

};


const u8 Keys[4][4]={
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{' ','0','=','+'},

};


/*
#define KeyPad_C1_PORT DIO_PORTA
#define KeyPad_C1_PIN  DIO_PIN0

#define KeyPad_C2_PORT DIO_PORTA
#define KeyPad_C2_PIN  DIO_PIN1

#define KeyPad_C3_PORT DIO_PORTA
#define KeyPad_C3_PIN  DIO_PIN2

#define KeyPad_C4_PORT DIO_PORTA
#define KeyPad_C4_PIN  DIO_PIN3

#define KeyPad_R1_PORT DIO_PORTA
#define KeyPad_R1_PIN  DIO_PIN4

#define KeyPad_R2_PORT DIO_PORTA
#define KeyPad_R2_PIN  DIO_PIN5

#define KeyPad_R3_PORT DIO_PORTA
#define KeyPad_R3_PIN  DIO_PIN6

#define KeyPad_R4_PORT DIO_PORTA
#define KeyPad_R4_PIN  DIO_PIN7
*/
#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
