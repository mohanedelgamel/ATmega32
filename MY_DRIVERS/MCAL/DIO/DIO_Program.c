/*
 * DIO_Program.c
 *
 *  Created on: Jul 26, 2024
 *      Author: mohaned
 */

/*
 * DIO_Prog.c
 *
 *  Created on: Jul 26, 2024
 *      Author: mohaned
 */

#include "../../LIBRARY/STD_Types.h"
#include "../../LIBRARY/Bit_Math.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"

u8 MDIO_u8SetPinValue(u8 L_u8Port, u8 L_u8Pin, u8 L_u8Value) {


	if (L_u8Value == DIO_HIGH) {
		switch (L_u8Port) {

		case DIO_PORTA:
		SET_BIT(PORTA_REG, L_u8Pin);
		break;
		case  DIO_PORTB:
		SET_BIT(PORTB_REG, L_u8Pin);

		break;
		case  DIO_PORTC:
		SET_BIT(PORTC_REG, L_u8Pin);
		break;
		case  DIO_PORTD:
		SET_BIT(PORTD_REG, L_u8Pin);
		break;
		default:
		return NOT_OK;
		break;
	}
	}
	else if (L_u8Value ==  DIO_LOW) {
		switch (L_u8Port) {
		case  DIO_PORTA:
			CLEAR_BIT(PORTA_REG, L_u8Pin);
			break;
		case  DIO_PORTB:
			CLEAR_BIT(PORTB_REG, L_u8Pin);
			break;
		case  DIO_PORTC:
			CLEAR_BIT(PORTC_REG, L_u8Pin);
			break;
		case  DIO_PORTD:
			CLEAR_BIT(PORTD_REG, L_u8Pin);
			break;
		default:
			return NOT_OK;
			break;
		}
	} else {
		return NOT_OK;

	}


	return OK;
}

u8 MDIO_u8SetPinDirection(u8 L_u8Port, u8 L_u8Pin, u8 L_u8Direction) {

	if (L_u8Direction ==  DIO_OUTPUT) {
		switch (L_u8Port) {

		case  DIO_DDRA:
			SET_BIT(DDRA_REG, L_u8Pin);
			break;
		case  DIO_DDRB:
			SET_BIT(DDRB_REG, L_u8Pin);
			break;
		case  DIO_DDRC:
			SET_BIT(DDRC_REG, L_u8Pin);
			break;
		case  DIO_DDRD:
			SET_BIT(DDRD_REG, L_u8Pin);
			break;
		default:
			return NOT_OK;
			break;
		}
	} else if (L_u8Direction ==  DIO_INPUT) {
		switch (L_u8Port) {
		case  DIO_DDRA:
			CLEAR_BIT(DDRA_REG, L_u8Pin);
			break;
		case  DIO_DDRB:
			CLEAR_BIT(DDRB_REG, L_u8Pin);
			break;
		case  DIO_DDRC:
			CLEAR_BIT(DDRC_REG, L_u8Pin);
			break;
		case  DIO_DDRD:
			CLEAR_BIT(DDRD_REG, L_u8Pin);
			break;
		default:
			return NOT_OK;
			break;
		}
	} else {
		return NOT_OK;
	}
	return OK;
}

u8 MDIO_u8SetPortValue(u8 L_u8Port, u8 L_u8Value) {
	switch (L_u8Port) {

	case  DIO_PORTA:
		PORTA_REG = L_u8Value;
		break;
	case  DIO_PORTB:
		PORTB_REG = L_u8Value;
		break;
	case  DIO_PORTC:
		PORTC_REG = L_u8Value;
		break;
	case  DIO_PORTD:
		PORTD_REG = L_u8Value;
		break;
	default:
		return NOT_OK;
		break;
	}
	return OK;
}
u8 MDIO_u8SetPortirection(u8 L_u8Port, u8 L_u8Direction) {
	switch (L_u8Port) {
	case  DIO_DDRA:
		DDRA_REG = L_u8Direction;
		break;
	case  DIO_DDRB:
		DDRB_REG = L_u8Direction;
		break;
	case  DIO_DDRC:
		DDRC_REG = L_u8Direction;
		break;
	case  DIO_DDRD:
		DDRD_REG = L_u8Direction;
		break;
	default:
		return NOT_OK;
		break;
	}
	return OK;
}

u8 MDIO_u8SGetPinValue(u8 L_u8Port, u8 L_u8Pin, u8 *LP_Value) {
    if (LP_Value == 0) {
        return NOT_OK;
    }

    switch (L_u8Port) {
        case  DIO_PORTA:
            *LP_Value = GET_BIT(PINA_REG, L_u8Pin);
            SET_BIT(PORTA_REG,L_u8Pin);//enable pull up
            break;
        case  DIO_PORTB:
            *LP_Value = GET_BIT(PINB_REG, L_u8Pin);
            SET_BIT(PORTB_REG,L_u8Pin);
            break;
        case  DIO_PORTC:
            *LP_Value = GET_BIT(PINC_REG, L_u8Pin);
            SET_BIT(PORTC_REG,L_u8Pin);
            break;
            *LP_Value = GET_BIT(PIND_REG, L_u8Pin);
            SET_BIT(PORTD_REG,L_u8Pin);
            break;
        default:
            return NOT_OK;
    }

    return OK;
}
