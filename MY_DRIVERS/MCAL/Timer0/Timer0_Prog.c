/*
 * Timer0_Prog.c
 *
 *  Created on: Aug 1, 2024
 *      Author: mohaned
 */


#include "../../Library/Bit_Math.h"
#include "../../Library/STD_Types.h"

#include "Timer0_Config.h"
#include "Timer0_Interface.h"
#include "Timer0_Private.h"


u32 NOCounts;
u32 Preload;

void (* OVR_Ptr)(void);
void (* CTC_Ptr)(void);
void TIM0_voidInit(){

#if TIMER_MODE==TIMER0_NORMAL_MODE
	//Normal mode
	CLEAR_BIT(TCCR0_REG,WGM00);
	CLEAR_BIT(TCCR0_REG,WGM01);

	//Enable=Overflow Interrupt
	SET_BIT(TIMSK_REG,TOIE0);
#elif TIMER_MODE==TIMER0_CTC_MODE
	    //CTC mode
		CLEAR_BIT(TCCR0_REG,WGM00);
		SET_BIT(TCCR0_REG,WGM01);
		//Enable CTC Interrupt
		SET_BIT(TIMSK_REG,OCIE0);

#endif
}
void TIM0_SetValueUS(u32 us){

	#if TIMER_MODE==TIMER0_NORMAL_MODE
	// prescalar =8
	// Timer freq =1MHz
	// Tick time =1 us
	// OVF time = 2^(8 bits) * 1us= 256us


	NOCounts = us/256;
	u32 mod= us%256;
	Preload = 256 - (mod);
	TCNT0_REG= Preload;
	 //Prescalar ==8 (clock source)
				CLEAR_BIT(TCCR0_REG,CS00);
				SET_BIT(TCCR0_REG,CS01);
				CLEAR_BIT(TCCR0_REG,CS02);



#elif TIMER_MODE==TIMER0_CTC_MODE


		for (u8 i=255 ;i>0;i--)
		{
			if (us%i==0)
			{
				OCR0_REG=i;
				NOCounts=(us/i);
				break;
			}

		}

		//Prescalar ==8 (clock source)
							CLEAR_BIT(TCCR0_REG,CS00);
							SET_BIT(TCCR0_REG,CS01);
							CLEAR_BIT(TCCR0_REG,CS02);


#endif

}
void TIM0_voidDisable(){
	//Disable timer
	    CLEAR_BIT(TCCR0_REG,CS00);
		CLEAR_BIT(TCCR0_REG,CS01);
		CLEAR_BIT(TCCR0_REG,CS02);
}

void TIM0_SetCallBack(void(*ptr)(void))
{
	if  (ptr!=NULL)
	{
#if TIMER_MODE==TIMER0_NORMAL_MODE
	OVR_Ptr=ptr;
#elif  TIMER_MODE==TIMER0_CTC_MODE
	CTC_Ptr=ptr;
#endif

	}
}

void __vector_11(void)
{
	static u32 counter=0;
	if (counter==NOCounts)
	{
	OVR_Ptr();
	counter=0;
	TCNT0_REG=Preload;
	}
	counter ++;
}

void __vector_10(void)
{
	static u32 counter=0;
		if (counter==NOCounts)
		{
		CTC_Ptr();
		counter=0;
		TCNT0_REG=0;
		}
		counter ++;

}
