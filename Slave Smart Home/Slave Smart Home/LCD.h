/*
 * LCD.h
 *
 * Created: 3/12/2021 3:17:43 PM
 *  Author: Kero
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO_CFG.h"

#define LCD_RS Dio_channelD1
#define LCD_RW Dio_channelD2
#define LCD_E Dio_channelD3

#define LCD_DataPort Dio_portD
#define LCD_ControlPort Dio_portD

#define LCD_DataReg PORTD_Reg
#define LCD_ControlReg PORTD_Reg

void LCD_Init();
void LCD_CMD(Uint8 Cmd);
void LCD_Char(Uint8 Data);
void LCD_String(char * string);
void LCD_StartPOS(Uint8 line,Uint8 pos);





#endif /* LCD_H_ */