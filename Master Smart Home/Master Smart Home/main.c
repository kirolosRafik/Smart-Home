/*
 * Master Smart Home.c
 *
 * Created: 3/12/2021 2:38:06 PM
 * Author : Kero
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "UART.h"
#include "LCD.h"
#include "SPI.h"


int main(void)
{
	/* Replace with your application code */
	DIO_Init();
	LCD_Init();
	SPI_Init('M');
	Slave_EN();
	Uart_Init();
	
	LCD_StartPOS(1,1);
	LCD_String("kirolos Rafik ");
	LCD_StartPOS(2,1);
	LCD_String("My Smart Home ");
	
	
	while (1)
	{
		
		switch (UartReceive())
		{
			case '1':
			SPI_Write('1');
			LCD_CMD(0x01);//clear LCD
			LCD_StartPOS(1,1);
			LCD_String("LED is ON");
			break;
			case '2':
			SPI_Write('2');
			LCD_CMD(0x01);//clear LCD
			LCD_StartPOS(1,1);
			LCD_String("LED is OFF");
			break;
			case '3':
			SPI_Write('3');
			LCD_CMD(0x01);//clear LCD
			LCD_StartPOS(1,1);
			LCD_String("Receiving Temp:");
			break;
			case 's':
			SPI_Write('s');
			LCD_CMD(0x01);//clear LCD
			LCD_StartPOS(1,1);
			LCD_String("Motor is ON");
			break;
			case 'e':
			SPI_Write('s');
			LCD_CMD(0x01);//clear LCD
			LCD_StartPOS(1,1);
			LCD_String("Motor is OFF");
			break;
			case '+':
			SPI_Write('+');
			break;
			case '-':
			SPI_Write('-');
			break;
		}
	}
}

