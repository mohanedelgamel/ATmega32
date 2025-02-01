/*
 * ICU_Interface.h
 *
 *  Created on: Aug 6, 2024
 *      Author: mohaned
 */

#ifndef HAL_ICU_ICU_INTERFACE_H_
#define HAL_ICU_ICU_INTERFACE_H_

#include "../../Library/STD_Types.h"

void ICU_Init();
u16  ICU_GetOnTime();
u16  ICU_GetOffTime();
u32  ICU_GetPeriod();


#endif /* HAL_ICU_ICU_INTERFACE_H_ */
