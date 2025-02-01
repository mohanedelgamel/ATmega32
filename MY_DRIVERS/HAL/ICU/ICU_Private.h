/*
 * ICU_Private.h
 *
 *  Created on: Aug 6, 2024
 *      Author: mohaned
 */

#ifndef HAL_ICU_ICU_PRIVATE_H_
#define HAL_ICU_ICU_PRIVATE_H_

#define ICU_WaITING_FOR_FIRST_RISING   0
#define ICU_WaITING_FOR_FALLING        1
#define ICU_WaITING_FOR_SECOND_RISING  2

void ICU_Process();

static volatile u16 T_ON=0;
static volatile u16 T_OFF=0;
#endif /* HAL_ICU_ICU_PRIVATE_H_ */
