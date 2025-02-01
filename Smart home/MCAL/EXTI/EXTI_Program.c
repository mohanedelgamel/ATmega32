/**************************************************************************/
/************************ Author: Omar Tarek       ************************/
/************************ Date : 30/7/2024         ************************/
/************************ SWC : External Interrupt ************************/
/************************ Government : ITI         ************************/
/************************ Diploma : One Month      ************************/
/**************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"

#include "EXTI_Private.h"
#include "EXTI_Interface.h"
#include "EXTI_Configuration.h"

static void (*EXTI_ApfEXTI[3])(void) = {NULL, NULL, NULL};

void EXTI_voidInit(void)
{
    /********************************
    *Set Logical Trigger for INTs**** 
    ********************************/
    /******************************* INT0 *******************************/
    #if INT0_TRIGGER == LOW_LEVEL_TRIGGER
    /* Low Level */
    CLR_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC01_BIT);
    CLR_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC00_BIT);

    #elif INT0_TRIGGER == ANY_EDGE_TRIGGER
    /* Any Logical Change */
    CLR_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC01_BIT);
    SET_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC00_BIT);

    #elif INT0_TRIGGER == FALLING_EDGE_TRIGGER
    /* Falling Edge */
    SET_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC01_BIT);
    CLR_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC00_BIT);

    #elif INT0_TRIGGER == RISING_EDGE_TRIGGER
    /* Rising Edge */
    SET_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC01_BIT);
    SET_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC00_BIT);

    #else
    #error Invalid Triggering Edge
    #endif

    /******************************* INT1 *******************************/
    #if INT1_TRIGGER == LOW_LEVEL_TRIGGER
    /* Low Level */
    CLR_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC11_BIT);
    CLR_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC10_BIT);

    #elif INT1_TRIGGER == ANY_EDGE_TRIGGER
    /* Any Logical Change */
    CLR_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC11_BIT);
    SET_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC10_BIT);

    #elif INT1_TRIGGER == FALLING_EDGE_TRIGGER
    /* Falling Edge */
    SET_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC11_BIT);
    CLR_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC10_BIT);

    #elif INT1_TRIGGER == RISING_EDGE_TRIGGER
    /* Rising Edge */
    SET_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC11_BIT);
    SET_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC10_BIT);
    
    #else
    #error Invalid Triggering Edge
    #endif

    /******************************* INT2 *******************************/
    #if INT2_TRIGGER == FALLING_EDGE_TRIGGER
    /* Falling Edge */
    CLR_BIT(EXTI_u8_MCUCSR_REGISTER, EXTI_u8_MCUCSR_ISC2_BIT);

    #elif INT2_TRIGGER == RISING_EDGE_TRIGGER
    /* Rising Edge */
    SET_BIT(EXTI_u8_MCUCSR_REGISTER, EXTI_u8_MCUCSR_ISC2_BIT);
    
    #else
    #error Invalid Triggering Edge
    #endif

    /********************************
    **********Activate INTs********** 
    ********************************/
   /******************************* INT0 *******************************/
   #if INT0_STATE == ENABLE
   SET_BIT(EXTI_u8_GICR_REGISTER, EXTI_u8_GICR_INT0_BIT);

   #elif INT0_STATE == DISABLE
   CLR_BIT(EXTI_u8_GICR_REGISTER, EXTI_u8_GICR_INT0_BIT);
   
   #else
   #error Invalid INT State
   #endif
   
   /******************************* INT1 *******************************/
   #if INT1_STATE == ENABLE
   SET_BIT(EXTI_u8_GICR_REGISTER, EXTI_u8_GICR_INT1_BIT);

   #elif INT1_STATE == DISABLE
   CLR_BIT(EXTI_u8_GICR_REGISTER, EXTI_u8_GICR_INT1_BIT);
   
   #else
   #error Invalid INT State
   #endif

   /******************************* INT2 *******************************/
   #if INT2_STATE == ENABLE
   SET_BIT(EXTI_u8_GICR_REGISTER, EXTI_u8_GICR_INT2_BIT);

   #elif INT2_STATE == DISABLE
   CLR_BIT(EXTI_u8_GICR_REGISTER, EXTI_u8_GICR_INT2_BIT);
   
   #else
   #error Invalid INT State
   #endif

}

u8 EXTI_u8Enable(u8 Copy_u8EXTIPin, u8 Copy_u8Trigger)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    
    /* Enable External Interrupt (PIE) and Select Edge Source */  
    switch (Copy_u8EXTIPin)
    {
    case INT0:
        switch (Copy_u8Trigger)
        {
        case FALLING_EDGE:
            SET_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC01_BIT);
            CLR_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC00_BIT);
            break;
        case LOW_LEVEL:
            CLR_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC01_BIT);
            CLR_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC00_BIT);
            break;
        case RISING_EDGE:
            SET_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC01_BIT);
            SET_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC00_BIT);
            break;
        case ANY_EDGE:
            CLR_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC01_BIT);
            SET_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC00_BIT);
            break;
    
        default:
            Local_u8ErrorState = STD_TYPE_NOK;
            break;
        }
        if (Local_u8ErrorState == STD_TYPE_OK)
           SET_BIT(EXTI_u8_GICR_REGISTER, EXTI_u8_GICR_INT0_BIT);
        break;
    
    case INT1:
        switch (Copy_u8Trigger)
        {
        case FALLING_EDGE:
            SET_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC11_BIT);
            CLR_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC10_BIT);
            break;
        case LOW_LEVEL:
            CLR_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC11_BIT);
            CLR_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC10_BIT);
            break;
        case RISING_EDGE:
            SET_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC11_BIT);
            SET_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC10_BIT);
            break;
        case ANY_EDGE:
            CLR_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC11_BIT);
            SET_BIT(EXTI_u8_MCUCR_REGISTER, EXTI_u8_MCUCR_ISC10_BIT);
            break;
    
        default:
            Local_u8ErrorState = STD_TYPE_NOK;
            break;
        }
        if (Local_u8ErrorState == STD_TYPE_OK)
            SET_BIT(EXTI_u8_GICR_REGISTER, EXTI_u8_GICR_INT1_BIT);
        break;
    
    case INT2:
        switch (Copy_u8Trigger)
        {
        case FALLING_EDGE:
            CLR_BIT(EXTI_u8_GICR_REGISTER, EXTI_u8_GICR_INT2_BIT);
            SET_BIT(EXTI_u8_GIFR_REGISTER, EXTI_u8_GIFR_INTF2_BIT);
            CLR_BIT(EXTI_u8_MCUCSR_REGISTER, EXTI_u8_MCUCSR_ISC2_BIT);
            break;
        case RISING_EDGE:
            CLR_BIT(EXTI_u8_GICR_REGISTER, EXTI_u8_GICR_INT2_BIT);
            SET_BIT(EXTI_u8_GIFR_REGISTER, EXTI_u8_GIFR_INTF2_BIT);
            SET_BIT(EXTI_u8_MCUCSR_REGISTER, EXTI_u8_MCUCSR_ISC2_BIT);
            break;
    
        default:
            Local_u8ErrorState = STD_TYPE_NOK;
            break;
        }
        if (Local_u8ErrorState == STD_TYPE_OK)
            SET_BIT(EXTI_u8_GICR_REGISTER, EXTI_u8_GICR_INT2_BIT);
        break;
    
    default:
        Local_u8ErrorState = STD_TYPE_NOK;
        break;
    }
    
    return Local_u8ErrorState;
    
}

u8 EXTI_u8Disable(u8 Copy_u8EXTIPin)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    
    switch (Copy_u8EXTIPin)
    {
    case INT0:
        CLR_BIT(EXTI_u8_GICR_REGISTER, EXTI_u8_GICR_INT0_BIT);
        break;
    case INT1:
        CLR_BIT(EXTI_u8_GICR_REGISTER, EXTI_u8_GICR_INT1_BIT);
        break;
    case INT2:
        CLR_BIT(EXTI_u8_GICR_REGISTER, EXTI_u8_GICR_INT2_BIT);
        break;
    
    default:
        Local_u8ErrorState = STD_TYPE_NOK;
        break;
    }
    return Local_u8ErrorState;
}

u8 EXTI_u8SetCallBack(u8 Copy_u8EXTIPin, void(*Copy_pfApp)(void))
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    if ((Copy_pfApp != NULL) && (Copy_u8EXTIPin < INT2))
    {
        EXTI_ApfEXTI[Copy_u8EXTIPin] = Copy_pfApp;
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    return Local_u8ErrorState;
    
}



/* Prototype for ISR of EXTI 0*/
void __vector_1(void)     __attribute__((signal));
void __vector_1(void)
{
    if (EXTI_ApfEXTI[INT0] != NULL)
    {
        EXTI_ApfEXTI[INT0]();
        SET_BIT(EXTI_u8_GIFR_REGISTER, EXTI_u8_GIFR_INTF0_BIT);

    }
    
}

/* Prototype for ISR of EXTI 1*/
void __vector_2(void)     __attribute__((signal));
void __vector_2(void)
{
    if (EXTI_ApfEXTI[INT1] != NULL)
    {
        EXTI_ApfEXTI[INT1]();
        SET_BIT(EXTI_u8_GIFR_REGISTER, EXTI_u8_GIFR_INTF1_BIT);
    }
}

/* Prototype for ISR of EXTI 2*/
void __vector_3(void)     __attribute__((signal));
void __vector_3(void)
{
    if (EXTI_ApfEXTI[INT2] != NULL)
    {
        EXTI_ApfEXTI[INT2]();
        SET_BIT(EXTI_u8_GIFR_REGISTER, EXTI_u8_GIFR_INTF2_BIT);
    }
}
