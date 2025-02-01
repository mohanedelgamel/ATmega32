/*
 * DIO_Interface.h
 *
 *  Created on: Jul 26, 2024
 *      Author: mohaned
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include "../../Library/STD_Types.h"
#define DIO_PORTA 1
#define DIO_PORTB 2
#define DIO_PORTC 3
#define DIO_PORTD 4

#define DIO_DDRA 1
#define DIO_DDRB 2
#define DIO_DDRC 3
#define DIO_DDRD 4

#define DIO_PINA 1
#define DIO_PINB 2
#define DIO_PINC 3
#define DIO_PIND 4

#define DIO_PIN7 7
#define DIO_PIN6 6
#define DIO_PIN5 5
#define DIO_PIN4 4
#define DIO_PIN3 3
#define DIO_PIN2 2
#define DIO_PIN1 1
#define DIO_PIN0 0

#define DIO_LOW  0
#define DIO_HIGH 1


#define DIO_OUTPUT 1
#define DIO_INPUT  0



typedef enum ERROR_t {
	OK,
	NOT_OK
}ERROR;


u8 MDIO_u8SetPinValue(u8 L_u8Port,u8 L_u8Pin,u8 L_u8Value);
u8 MDIO_u8SetPinDirection(u8 L_u8Port,u8 L_u8Pin,u8 L_u8Direction);
u8 MDIO_u8SetPortValue(u8 L_u8Port,u8 L_u8Direction);
u8 MDIO_u8SetPortirection(u8 L_u8Port,u8 L_u8Direction);
u8 MDIO_u8SGetPinValue(u8 L_u8Port,u8 L_u8Pin,u8 *LP_Value);



#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
