/*
 * LCD.h
 *
 * Created: 3/12/2021 2:50:07 PM
 *  Author: Kero
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO_CFG.h"

#define LCD_RS Dio_channelC1
#define LCD_RW Dio_channelC2
#define LCD_E Dio_channelC3

#define LCD_DataPort Dio_portC
#define LCD_ControlPort Dio_portC

#define LCD_DataReg PORTC_Reg
#define LCD_ControlReg PORTC_Reg

void LCD_Init();
void LCD_CMD(Uint8 Cmd);
void LCD_Char(Uint8 Data);
void LCD_String(char * string);
void LCD_StartPOS(Uint8 line,Uint8 pos);


#endif /* LCD_H_ */