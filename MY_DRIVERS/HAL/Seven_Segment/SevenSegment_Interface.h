/*
 * SevenSegment_Interface.h
 *
 *  Created on: Jul 27, 2024
 *      Author: mohaned
 */

#ifndef HAL_SEVEN_SEGMENT_SEVENSEGMENT_INTERFACE_H_
#define HAL_SEVEN_SEGMENT_SEVENSEGMENT_INTERFACE_H_

#include "../../Library/STD_Types.h"

typedef enum SEVSEGERR_t
{
	SEV_OK,
	SEV_NOTOK
	}SEVERR;

u8 SevenSegment_u8Init();
void SevenSegment_voidClear();
u8 SevenSegment_u8PrintValue(u8 L_u8Value );




#endif /* HAL_SEVEN_SEGMENT_SEVENSEGMENT_INTERFACE_H_ */
