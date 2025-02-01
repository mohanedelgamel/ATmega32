/********************************************************************/
/************************ Author: Omar Tarek ************************/
/************************ Date : 25/7/2024   ************************/
/************************ SWC : DIO          ************************/
/************************ Government : ITI   ************************/
/************************ Diploma : One Month  **********************/
/********************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/* PINS */
#define DIO_u8_PIN0 0
#define DIO_u8_PIN1 1
#define DIO_u8_PIN2 2
#define DIO_u8_PIN3 3
#define DIO_u8_PIN4 4
#define DIO_u8_PIN5 5
#define DIO_u8_PIN6 6
#define DIO_u8_PIN7 7

/* PORTS */
#define DIO_u8_PORTA 0
#define DIO_u8_PORTB 1
#define DIO_u8_PORTC 2
#define DIO_u8_PORTD 3

/* VALUES */
#define DIO_u8_HIGH 1
#define DIO_u8_LOW 0

/* DIRECTIONS */
#define DIO_u8_OUTPUT 1
#define DIO_u8_INPUT 0

void DIO_voidInit(void);
u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);
u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_Pu8Value);

u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);
u8 DIO_u8GetPortValue(u8 Copy_u8Port, u8 *Copy_Pu8Value);

#endif