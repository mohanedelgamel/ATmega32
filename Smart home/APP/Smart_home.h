/*
 * Smart_home.h
 *
 *  Created on: Aug 17, 2024
 *      Author: omart
 */

#ifndef APP_SMART_HOME_H_
#define APP_SMART_HOME_H_

#include "../LIB/STD_TYPES.h"

void System_Init(void);
u8 InitialDisplay(void);
void Save_Users(void);
void Get_PassValues(void);
u8 ValidatePasscode(void);
void UnlockDoor(void);
void LockDoor(void);
void GetPasscodeFromUser(void);
void EnteredPass(void);
void ChangePasscodes(void);
void TurnLight(void);
void Options(void);

#endif /* APP_SMART_HOME_H_ */
