#include "APP/Smart_home.h"

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATHS.h"

#define F_CPU 8000000UL
#include <util/delay.h>

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/TWI/TWI_interface.h"
#include "MCAL/TIMERS/TIMER1_Interface.h"
#include "MCAL/UART/UART_Interface.h"

#include "HAL/LCD/LCD_interface.h"
#include "HAL/SERVO/SERVO_Configuration.h"
#include "HAL/SERVO/SERVO_Inerface.h"
#include "HAL/LED/LED_Configuration.h"
#include "HAL/LED/LED_Interface.h"
#include "HAL/EEPROM/EEPROM_Interface.h"

u8 ReadFlag;

int main(void) {
    u8 userChoice = 0;

    // System Initialization
    System_Init();
    /*EEPROM_u8ReadByte(&ReadFlag, 1);
    if(ReadFlag >= 0) {
    	//do nothing
    } else {
    	Save_Users();
    }*/

    while (1) {
        // Initial display to prompt user for action
        userChoice = InitialDisplay();

        if (userChoice == 1) {
            // User chose to enter the door
            GetPasscodeFromUser();
        } else if (userChoice == 2) {
            // User chose to change the password
            ChangePasscodes();
        } else {
            // Invalid input, loop back to initial display
            LCD_voidClear();
            _delay_ms(200);
            LCD_voidSendString((u8 *)"Invalid Choice!");
            _delay_ms(1000);
        }
    }

    return 0;
}
