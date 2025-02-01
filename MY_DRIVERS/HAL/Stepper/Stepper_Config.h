/*
 * Stepper_Config.h
 *
 *  Created on: Jul 31, 2024
 *      Author: mohaned
 */

#ifndef HAL_STEPPER_STEPPER_CONFIG_H_
#define HAL_STEPPER_STEPPER_CONFIG_H_

#include "../../Library/STD_Types.h"
#include "../../MCAL/DIO/DIO_Interface.h"

const struct coil {
		u8 PORT;
		u8 PIN;
};

struct coil coils[]=
{
		{DIO_PORTC,DIO_PIN0},
		{DIO_PORTC,DIO_PIN1},
		{DIO_PORTC,DIO_PIN2},
		{DIO_PORTC,DIO_PIN3},

};

#define CoilsNum  (sizeof(coils)/sizeof(coils[0]))

#endif /* HAL_STEPPER_STEPPER_CONFIG_H_ */
