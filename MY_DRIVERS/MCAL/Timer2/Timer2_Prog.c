/*
 * Timer2_Prog.c
 *
 *  Created on: Aug 1, 2024
 *      Author: mohaned
 */


#include "../../Library/Bit_Math.h"
#include "../../Library/STD_Types.h"

#include "Timer2_Config.h"
#include "Timer2_Interface.h"
#include "Timer2_Private.h"


u32 NOCounts;
u32 Preload;

void (* OVR2_Ptr)(void);
void (* CTC2_Ptr)(void);
void TIM2_voidInit(){

#if TIMER2_MODE==TIMER2_NORMAL_MODE
	//Normal mode
	CLEAR_BIT(TCCR2_REG,WGM20);
	CLEAR_BIT(TCCR2_REG,WGM21);

	//Enable=Overflow Interrupt
	SET_BIT(TIMSK_REG,TOIE2);
#elif TIMER2_MODE==TIMER2_CTC_MODE
	    //CTC mode
		CLEAR_BIT(TCCR2_REG,WGM20);
		SET_BIT(TCCR2_REG,WGM21);
		//Enable CTC Interrupt
		SET_BIT(TIMSK_REG,OCIE2);

#endif
}
void TIM2_SetValueUS(u32 us){

	#if TIMER2_MODE==TIMER2_NORMAL_MODE
	// prescalar =8
	// Timer freq =1MHz
	// Tick time =1 us
	// OVF time = 2^(8 bits) * 1us= 256us


	NOCounts = us/256;
	u32 mod= us%256;
	Preload = 256 - (mod);
	TCNT2_REG= Preload;

	 //Prescalar ==8 (clock source)
				CLEAR_BIT(TCCR2_REG,CS20);
				SET_BIT(TCCR2_REG,CS21);
				CLEAR_BIT(TCCR2_REG,CS22);


#elif TIMER2_MODE==TIMER2_CTC_MODE


		//get max suitable compare value
		for (u8 i=255 ;i>0;i--)
		{
			if (us%i==0)
			{
				OCR2_REG=i;
				NOCounts=(us/i);
				break;
			}

		}
		//Prescalar ==8 (clock source)
							CLEAR_BIT(TCCR2_REG,CS20);
							SET_BIT(TCCR2_REG,CS21);
							CLEAR_BIT(TCCR2_REG,CS22);


#endif

}
void TIM2_voidDisable(){
	//Disable timer
	    CLEAR_BIT(TCCR2_REG,CS20);
		CLEAR_BIT(TCCR2_REG,CS21);
		CLEAR_BIT(TCCR2_REG,CS22);
}

void TIM2_SetCallBack(void(*ptr)(void))
{
	if  (ptr!=NULL)
	{
#if TIMER2_MODE==TIMER2_NORMAL_MODE
	OVR2_Ptr=ptr;
#elif  TIMER2_MODE==TIMER2_CTC_MODE
	CTC2_Ptr=ptr;
#endif

	}
}

void __vector_5(void)
{
	static u32 counter=0;
	if (counter==NOCounts)
	{
	OVR2_Ptr();
	counter=0;
	TCNT2_REG=Preload;
	}
	counter ++;
}

void __vector_4(void)
{
	static u32 counter=0;
		if (counter==NOCounts)
		{
		CTC2_Ptr();
		counter=0;
		}
		counter ++;

}
