/*
 * LM35_Interface.h
 *
 *  Created on: Aug 4, 2024
 *      Author: mohaned
 */

#ifndef HAL_LM35_LM35_INTERFACE_H_
#define HAL_LM35_LM35_INTERFACE_H_
#include "../../Library/STD_Types.h"

u8 LM35_voidInit();
u8 LM35_voidGetTemp();
u8 * LM35_IntToStr(u16 num, u8 str[6]);

#endif /* HAL_LM35_LM35_INTERFACE_H_ */
