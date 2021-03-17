/*
 * LCD.c
 *
 * Created: 3/12/2021 3:16:56 PM
 *  Author: Kero
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include "LCD.h"
void LCD_Init()
{
	DIO_Init();
	_delay_ms(20);
	LCD_CMD(0x33);
	_delay_us(200);
	LCD_CMD(0x32);
	LCD_CMD(0x28);//set function
	LCD_CMD(0x06);//Entery mode
	LCD_CMD(0x0c);//display on
	LCD_CMD(0x01);//clear
}

void LCD_CMD(Uint8 Cmd)
{
	Uint8 SendCmd;
	//send high nipple 3
	SendCmd = (LCD_DataReg & 0x0F)|(Cmd & 0xF0);
	DIO_writePort (LCD_DataPort,SendCmd);
	DIO_write(LCD_RS,STD_Low);
	DIO_write(LCD_E,STD_High);
	_delay_us(50);
	DIO_write(LCD_E,STD_Low);
	//delay
	_delay_ms(5);
	//send low nipple  3
	SendCmd = (LCD_DataReg & 0x0F)|(Cmd << 4);
	DIO_writePort (LCD_DataPort,SendCmd);
	DIO_write(LCD_RS,STD_Low);
	DIO_write(LCD_E,STD_High);
	_delay_us(50);
	DIO_write(LCD_E,STD_Low);
	_delay_ms(2);
}

void LCD_Char(Uint8 Data)
{
	Uint8 SendData;
	//send high nipple 3
	SendData= (LCD_DataReg & 0x0F)|(Data & 0xF0);
	DIO_writePort (LCD_DataPort,SendData);
	DIO_write(LCD_RS,STD_High);
	DIO_write(LCD_E,STD_High);
	_delay_us(50);
	DIO_write(LCD_E,STD_Low);
	//delay
	_delay_ms(5);
	//send low nipple  3
	SendData = (LCD_DataReg & 0x0F)|(Data << 4);
	DIO_writePort (LCD_DataPort,SendData);
	DIO_write(LCD_RS,STD_High);
	DIO_write(LCD_E,STD_High);
	_delay_us(50);
	DIO_write(LCD_E,STD_Low);
	_delay_ms(2);
}
void LCD_String(char * string)
{
	Uint8 count=0;
	while(string[count]!='\0')
	{
		LCD_Char(string[count]);
		count++;
	}
}
void LCD_StartPOS(Uint8 line,Uint8 pos)
{
	switch (line)
	{
		Uint8 SendCmd;
		case 1:
		SendCmd = 0x80 | (pos & 0x0F);
		LCD_CMD(SendCmd);
		break;
		case 2:
		SendCmd = 0xC0 | (pos & 0x0F);
		LCD_CMD(SendCmd);
		break;
	}
}