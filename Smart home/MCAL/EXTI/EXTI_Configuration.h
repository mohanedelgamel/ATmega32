/**************************************************************************/
/************************ Author: Omar Tarek       ************************/
/************************ Date : 30/7/2024         ************************/
/************************ SWC : External Interrupt ************************/
/************************ Government : ITI         ************************/
/************************ Diploma : One Month      ************************/
/**************************************************************************/
#ifndef EXTI_CONFIGURATION_H
#define EXTI_CONFIGURATION_H

/* Options 1- FALLING_EDGE_TRIGGER
           2- RISING_EDGE_TRIGGER 
           3- ANY_EDGE_TRIGGER    
           4- LOW_LEVEL_TRIGGER   */
#define INT0_TRIGGER FALLING_EDGE_TRIGGER
#define INT1_TRIGGER FALLING_EDGE_TRIGGER

/* Options 1- FALLING_EDGE_TRIGGER
           2- RISING_EDGE_TRIGGER */
#define INT2_TRIGGER FALLING_EDGE_TRIGGER

/* Options 1- ENABLE
           2- DISABLE*/
#define INT0_STATE ENABLE
#define INT1_STATE DISABLE
#define INT2_STATE DISABLE

#endif