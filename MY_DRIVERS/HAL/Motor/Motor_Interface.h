/*
 * Motor_Interface.h
 *
 *  Created on: Jul 31, 2024
 *      Author: mohaned
 */

#ifndef HAL_MOTOR_MOTOR_INTERFACE_H_
#define HAL_MOTOR_MOTOR_INTERFACE_H_
#include "../../Library/STD_Types.h"

#define Motor_CW   0
#define Motor_CCW  1

void Motor_voidInit();
void Motor_SetDirection(u8 L_u8Direction);
void Motor_Stop();


#endif /* HAL_MOTOR_MOTOR_INTERFACE_H_ */
