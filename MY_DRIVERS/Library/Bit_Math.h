/*
 * Bit_Math.h
 *
 *  Created on: Jul 26, 2024
 *      Author: mohaned
 */

#ifndef LIBRARY_BIT_MATH_H_
#define LIBRARY_BIT_MATH_H_

#define SET_BIT(Byte,BitNumber) (Byte|=(1<<BitNumber))
#define CLEAR_BIT(Byte,BitNumber) (Byte &= ~(1<<BitNumber))
#define TOGGLE_BIT(Byte,BitNumber) (Byte ^=(1<<BitNumber))
#define GET_BIT(BYTE,Bit_NO) ((BYTE>>Bit_NO)&(0x01))


#endif /* LIBRARY_BIT_MATH_H_ */
