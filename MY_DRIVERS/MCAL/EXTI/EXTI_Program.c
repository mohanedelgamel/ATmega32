/*
 * EXTI_Program.c
 *
 *  Created on: Jul 30, 2024
 *      Author: mohaned
 */

/*
 * EXTI_Prog.c
 *
 *  Created on: Jul 30, 2024
 *      Author: mohaned
 */
#include "../../Library/Bit_Math.h"
#include "../../Library/STD_Types.h"

#include "EXTI_Config.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"



void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));

void EXTI_CallBack(void (*Ptr)(),u8 EXTI_Num);

void (*Ptr1)(void);
void (*Ptr2)(void);
void (*Ptr3)(void);

void EXTI_Init(void){
#if EXTI0_MODE == EXTI_LOW_LEVEL
	CLEAR_BIT(MCUCR_REG,ISC00);
	CLEAR_BIT(MCUCR_REG,ISC01);
#elif EXTI0_MODE == EXTI_ON_CHANGE
	SET_BIT(MCUCR_REG, ISC00);
	CLEAR_BIT(MCUCR_REG, ISC01);
#elif EXTI0_MODE == EXTI_FALLING
	CLEAR_BIT(MCUCR_REG,ISC00);
	SET_BIT(MCUCR_REG,ISC01);
#elif EXTI0_MODE == EXTI_RAISING
	SET_BIT(MCUCR_REG,ISC00);
	SET_BIT(MCUCR_REG,ISC01);
#endif

#if EXTI1_MODE == EXTI_LOW_LEVEL
	CLEAR_BIT(MCUCR_REG,ISC10);
	CLEAR_BIT(MCUCR_REG,ISC11);
#elif EXTI1_MODE == EXTI_ON_CHANGE
	SET_BIT(MCUCR_REG, ISC10);
	CLEAR_BIT(MCUCR_REG, ISC11);
#elif EXTI1_MODE == EXTI_FALLING
	CLEAR_BIT(MCUCR_REG,ISC10);
	SET_BIT(MCUCR_REG,ISC11);
#elif EXTI1_MODE == EXTI_RAISING
	SET_BIT(MCUCR_REG,ISC10);
	SET_BIT(MCUCR_REG,ISC11);
#endif


#if EXTI2_MODE == EXTI_FALLING
	CLEAR_BIT(MCUSCR_REG,ISC2);
#elif EXTI2_MODE == EXTI_RAISING
	SET_BIT(MCUCSR_REG,ISC2);
#endif
}

void EXTI_Enable(u8 L_u8EXTI_Num) {

	switch(L_u8EXTI_Num) {
	case EXTI0:
		SET_BIT(GICR_REG, INT0);
		break;
	case EXTI1:
		SET_BIT(GICR_REG, INT1);
		break;
	case EXTI2:
		SET_BIT(GICR_REG, INT2);
		break;

	}
}
void EXTI_Disable(u8 L_u8EXTI_Num) {
	switch (L_u8EXTI_Num) {
	case EXTI0:
		CLEAR_BIT(GICR_REG, INT0);
		break;
	case EXTI1:
		CLEAR_BIT(GICR_REG, INT1);
		break;
	case EXTI2:
		CLEAR_BIT(GICR_REG, INT2);
		break;
	}
}


void EXTI_CallBack(void (*Ptr)(),u8 EXTI_Num)
{
	switch(EXTI_Num)
	{
	case EXTI0 : Ptr1=__vector_1; break;
	case EXTI1 : Ptr2=__vector_2; break;
	case EXTI2 : Ptr3=__vector_3;break;

	}

}

void __vector_1(void) {
	Ptr1();

}
void __vector_2(void) {
	Ptr2();
}
void __vector_3(void) {
Ptr3();
}

