/*
 * LCD_Interface.h
 *
 *  Created on: Jul 28, 2024
 *      Author: mohaned
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#include "../../Library/STD_Types.h"

#define LCD_Clear_Screen            0b00000001
#define LCD_Return_Home             0b00000011 // start from first square
#define LCD_Entery_Mode1            0b00000110 // display shift off (normal mode)
#define LCD_Entery_Mode2            0b00000111 // display shift ON (will shift cursor and delete some characters)
#define LCD_Display_Mode1           0b00001111 // display onn cursor onn cursor blink
#define LCD_Display_Mode2           0b00001101 // display onn cursor off cursor blink
#define LCD_Display_Mode3           0b00001100 // display onn cursor off cursor blink
#define LCD_Function_Set1           0b00111011 // 8 bit mode ,2,lines,5*7 font
#define LCD_Function_Set2           0b00111111 // 8 bit mode ,2,lines,10*7 font

#define LCD_ShiftLeft               0b00010000 //shift cursor left
#define LCD_ShiftRight              0b00010100 //shift cursor right
#define LCD_ShiftEntireLeft         0b00011000 //display shift to left
#define LCD_ShiftEntireRight        0b00011100 //display shift to right



//special characters
//const u8  NOKIA_Signal[8]= {0x00, 0x02, 0x02, 0x06, 0x06, 0x0E, 0x0E, 0x1E};


void LCD_voidInit();
void LCD_voidSendCommand(u8 A_u8Command);
void LCD_voidSetDDRAM_Adress(u8 A_u8Adress);
void LCD_voidSendData(u8 A_u8Data);
void LCD_voidSendString(const u8* str);
void LCD_voidCreate_SpecialCharacter(u8  *A_u8SpecialChar   ,u8 CGRAM_Index);
void LCD_voidDisplay_SpecialCharacter(u8 AdressInCGROM   ,u8 PlaceToDisplay);
void LCD_voidLeftShift(u8 L_u8ShiftNum);
void LCD_voidRightShift(u8 L_u8ShiftNum);
void LCD_Number(u16 num) ;



#endif /* HAL_LCD_LCD_INTERFACE_H_ */
