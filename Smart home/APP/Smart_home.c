#include "Smart_home.h"

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATHS.h"

#define F_CPU 8000000UL
#include <util/delay.h>

#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/TWI/TWI_interface.h"
#include "../MCAL/TIMERS/TIMER1_Interface.h"
#include "../MCAL/UART/UART_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"

#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/SERVO/SERVO_Configuration.h"
#include "../HAL/SERVO/SERVO_Inerface.h"
#include "../HAL/LED/LED_Configuration.h"
#include "../HAL/LED/LED_Interface.h"
#include "../HAL/EEPROM/EEPROM_Interface.h"

extern SERVO_C SERVO_AstrConfiguration[SERVO_NOs];
extern LED_C LED_AstrConfiguration[LED_NOs];

#define EEPROM_INIT_FLAG_ADDRESS 0x00
#define EEPROM_INIT_FLAG_VALUE   0xA5

u8 KPD_VALUE;
u8 ENTERED_PASSCODES[3] = {0};
u16 CONCATENATED_PASSCODES = 0;
u8 EEPROM_GETVALUE = 0;

void System_Init(void) {
    DIO_voidInit();
    UART_voidInit(9600);
    _delay_ms(100);
    GIE_voidEnable();
    EXTI_u8Enable(INT0, FALLING_EDGE);
    LCD_voidInit();
    SERVO_voidPinInit(SERVO_AstrConfiguration);
    SERVO_voidInit();
    LED_u8Init(LED_AstrConfiguration);
    EEPROM_voidInit();
    u8 eepromFlag = 0;
    EEPROM_u8ReadByte(&eepromFlag, EEPROM_INIT_FLAG_ADDRESS);

    if (eepromFlag != EEPROM_INIT_FLAG_VALUE) {
    	// EEPROM is not initialized, so initialize user passcodes
        Save_Users();

        // Set the initialization flag
        EEPROM_u8SendByte(EEPROM_INIT_FLAG_VALUE, EEPROM_INIT_FLAG_ADDRESS);
    }
}

void Get_PassValues(void) {
    for (u8 PassNum = 0; PassNum < 3; PassNum++) {
        while (1) {
            UART_u8ReceiveByte(&KPD_VALUE);
            if (KPD_VALUE > 0 && KPD_VALUE < 255) {
                ENTERED_PASSCODES[PassNum] = KPD_VALUE - '0';
                LCD_voidSendNumber(ENTERED_PASSCODES[PassNum]);
                _delay_ms(200);
                break;
            }
        }
    }
    CONCATENATED_PASSCODES = (ENTERED_PASSCODES[0] * 100) + (ENTERED_PASSCODES[1] * 10) + (ENTERED_PASSCODES[2]);
}

void Save_Users(void) {
    LCD_voidSendString((u8 *)"Welcome");
    _delay_ms(500);
    LCD_voidClear();
    _delay_ms(100);
    LCD_voidSendString((u8 *)"Enter Passcodes");
    _delay_ms(500);

    for (u8 UserNumber = 1; UserNumber < 11; UserNumber++) {
        LCD_voidClear();
        _delay_ms(100);
        LCD_voidSendString((u8 *)"Enter Pass <256");
        LCD_voidGoToXY(LCD_u8_LINE2, 0);
        LCD_voidSendNumber(UserNumber);
        LCD_voidSendChar(':');
        Get_PassValues();
        _delay_ms(500);

        if (CONCATENATED_PASSCODES < 256) {
            EEPROM_u8SendByte(CONCATENATED_PASSCODES, UserNumber);
        } else {
            LCD_voidClear();
            _delay_ms(100);
            LCD_voidSendString((u8 *)"Can't Enter Value");
            UserNumber--;
            _delay_ms(500);
        }
    }
}

u8 ValidatePasscode(void) {
    for (u8 EEPROM_Address = 1; EEPROM_Address < 11; EEPROM_Address++) {
        EEPROM_u8ReadByte(&EEPROM_GETVALUE, EEPROM_Address);
        if (EEPROM_GETVALUE == CONCATENATED_PASSCODES) {
            return 1; // Passcode matches
        }
    }
    return 0; // Passcode doesn't match
}

void UnlockDoor(void) {
    LCD_voidClear();
    _delay_ms(100);
    LCD_voidSendString((u8 *)"Access Granted");
    SERVO_u8SetAngle(180, &SERVO_AstrConfiguration[0]); // Unlock position
    LED_u8SetLedHigh(&LED_AstrConfiguration[0]); // Green LED on
    LED_u8SetLedLow(&LED_AstrConfiguration[1]);  // Red LED off
}

void LockDoor(void) {
    LED_u8SetLedHigh(&LED_AstrConfiguration[1]); // Red LED on
    LED_u8SetLedLow(&LED_AstrConfiguration[0]);  // Green LED off
    SERVO_u8SetAngle(0, &SERVO_AstrConfiguration[0]); // Lock position
    LCD_voidClear();
    _delay_ms(100);
    LCD_voidSendString((u8 *)"Door Locked");
}

void GetPasscodeFromUser(void) {
    for (u8 TrialNumber = 1; TrialNumber < 4; TrialNumber++) {
        LCD_voidClear();
        _delay_ms(100);
        LCD_voidSendString((u8 *)"Enter Pass <256");
        LCD_voidGoToXY(LCD_u8_LINE2, 0);
        LCD_voidSendNumber(TrialNumber);
        LCD_voidSendChar(':');

        EnteredPass();
        u8 PassStates = ValidatePasscode();

        if (PassStates == 1) {
            UnlockDoor();
            _delay_ms(5000);
            Options();
            break;
        } else {
            LCD_voidClear();
            _delay_ms(100);
            LCD_voidSendString((u8 *)"ACCESS DENIED");
            _delay_ms(500);
            LockDoor();

            if (TrialNumber == 3) {
                LCD_voidClear();
                _delay_ms(100);
                LCD_voidSendString((u8 *)"TRY LATER");
                _delay_ms(500);
            }
        }
    }
}

void EnteredPass(void) {
    for (u8 PassNum = 0; PassNum < 3; PassNum++) {
        while (1) {
        	UART_u8ReceiveByte(&KPD_VALUE);
            if (KPD_VALUE > 0 && KPD_VALUE < 255) {
                ENTERED_PASSCODES[PassNum] = KPD_VALUE - '0';  // Changed to '0' for clarity
                LCD_voidSendChar('*');
                break;
            }
        }
    }

    CONCATENATED_PASSCODES = ENTERED_PASSCODES[0] * 100 + ENTERED_PASSCODES[1] * 10 + ENTERED_PASSCODES[2];
}

u8 InitialDisplay(void) {
    u8 UserChoice = 0;
    SERVO_u8SetAngle(0, &SERVO_AstrConfiguration[0]); // Lock position
    LED_u8SetLedHigh(&LED_AstrConfiguration[1]);      // Red LED on
    LED_u8SetLedLow(&LED_AstrConfiguration[0]);       // Green LED off

    LCD_voidClear();
    _delay_ms(100);
    LCD_voidSendString((u8 *)"Welcome to Door lock system");
    LCD_voidShiftDisplay(LCD_u8_SHIFT_LEFT, 50, 200);

    _delay_ms(1000);
    LCD_voidClear();
    _delay_ms(100);
    LCD_voidSendString((u8 *)"Enter The Mode");
    _delay_ms(1000);
    LCD_voidClear();
    _delay_ms(100);
    LCD_voidSendString((u8 *)"1-ENTER DOOR ");
    LCD_voidGoToXY(LCD_u8_LINE2, 0);
    LCD_voidSendString((u8 *)"2-CHANGE PASS");

    while (1) {
        UART_u8ReceiveByte(&KPD_VALUE);
        if (KPD_VALUE >= '0' && KPD_VALUE <= '9') {
            UserChoice = KPD_VALUE - '0';
            LCD_voidSendNumber(UserChoice);
            break;
        }
    }

    return UserChoice;
}

void ChangePasscodes(void) {
    u8 ChangePass_UserNum = 10;
    LCD_voidClear();
    _delay_ms(100);
    LCD_voidSendString((u8 *)"Enter User Num");
    LCD_voidGoToXY(LCD_u8_LINE2, 0);
    LCD_voidSendString((u8 *)"From 1 to 10:");

    while (1) {
        UART_u8ReceiveByte(&KPD_VALUE);
        if ((KPD_VALUE > '0') && (KPD_VALUE < '11')) {
            ChangePass_UserNum = KPD_VALUE - '0';
            LCD_voidSendNumber(ChangePass_UserNum);
            _delay_ms(1000);
            break;
        }
    }

    LCD_voidClear();
    _delay_ms(100);
    LCD_voidSendString((u8 *)"Enter New pass");
    LCD_voidGoToXY(LCD_u8_LINE2, 0);
    LCD_voidSendString((u8 *)"<256:");

    Get_PassValues();
    _delay_ms(500);

    if (CONCATENATED_PASSCODES < 256) {
        EEPROM_u8SendByte(CONCATENATED_PASSCODES, ChangePass_UserNum);
    } else {
        LCD_voidClear();
        _delay_ms(100);
        LCD_voidSendString((u8 *)"CAN'T ENTER VALUE");
        _delay_ms(500);
        return;
    }
    LCD_voidClear();
    _delay_ms(100);
    LCD_voidSendString((u8 *)"PASSWORD CHANGED");
    _delay_ms(2000);
}

void TurnLight(void) {
    u8 UserChoice;

    LCD_voidClear();
    _delay_ms(100);
    LCD_voidSendString((u8 *)"1- Turn on");
    LCD_voidGoToXY(LCD_u8_LINE2, 0);
    LCD_voidSendString((u8 *)"2- Turn off");

    while (1) {
        UART_u8ReceiveByte(&KPD_VALUE);
        if (KPD_VALUE >= '1' && KPD_VALUE <= '2') {
            UserChoice = KPD_VALUE - '0';
            break;
        }
    }

    if (UserChoice == 1) {
        LED_u8SetLedHigh(&LED_AstrConfiguration[2]); // Turn on the LED
        LCD_voidClear();
        _delay_ms(100);
        LCD_voidSendString((u8 *)"LED ON");
        _delay_ms(500);
    } else if (UserChoice == 2) {
        LED_u8SetLedLow(&LED_AstrConfiguration[2]); // Turn off the LED
        LCD_voidClear();
        _delay_ms(100);
        LCD_voidSendString((u8 *)"LED OFF");
        _delay_ms(500);
    }
}

void Options(void) {
    u8 OptionChoice;
    while (1) {
        LCD_voidClear();
        _delay_ms(100);
        LCD_voidSendString((u8 *)"1- LIGHT");
        LCD_voidGoToXY(LCD_u8_LINE2, 0);
        LCD_voidSendString((u8 *)"2- LOCK");

        while (1) {
            UART_u8ReceiveByte(&KPD_VALUE);
            if (KPD_VALUE >= '1' && KPD_VALUE <= '2') {
                OptionChoice = KPD_VALUE - '0';
                break;
            }
        }

        if (OptionChoice == 1) {
            TurnLight(); // Call the function to control the LED
        } else if (OptionChoice == 2) {
            LockDoor(); // Lock the door
            break;
        }
    }
}

