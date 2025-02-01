/*
 * GIE_Prog.c
 *
 *  Created on: Jul 30, 2024
 *      Author: mohaned
 */

#include "GIE_Interface.h"
#include "GIE_Private.h"

#include "../../Library/Bit_Math.h"
#include "../../Library/STD_Types.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG_REG,I_BIT);

}
void GIE_voidDisable(void)
{
	CLEAR_BIT(SREG_REG,I_BIT);

}
