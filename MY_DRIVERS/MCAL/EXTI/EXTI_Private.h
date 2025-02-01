/*
 * EXTI_Private.h
 *
 *  Created on: Jul 30, 2024
 *      Author: mohaned
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#define GICR_REG   *( volatile u8 *)(0x5B)
#define GIFR_REG   *( volatile u8 *)(0x5A)
#define MCUCR_REG  *( volatile u8 *)(0x55)
#define MCUCSR_REG *( volatile u8 *)(0x54)

/* MCUCR register bits */
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define SM0   4
#define SM1   5
#define SM2   6
#define SE    7

/* MCUCSR register bits */
#define PORF  0
#define EXTRF 1
#define BORF  2
#define WDRF  3
#define JTRF  4
#define ISC2  6
#define JTD   7

/* GICR register bits */
#define IVCE  0
#define IVSEL 1
#define INT2  5
#define INT0  6
#define INT1  7

/* GIFR register bits */
#define INTF2 5
#define INTF0 6
#define INTF1 7








#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
