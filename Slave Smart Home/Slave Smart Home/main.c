/*
* Slave Smart Home.c
*
* Created: 3/12/2021 3:06:32 PM
* Author : Kero
*/

#include <avr/io.h>
#include <stdlib.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "SPI.h"
#include "LCD.h"
#include "ADC.h"

int main(void)
{
	/* Replace with your application code */

	SPI_Init('S');
	DIO_Init();
	LCD_Init();
	ADC_Init();
	DDRC|=(1<<7)|(1<<3)|(1<<4);
	DDRB |=(1<<3);
	OCR0 = 0;
	TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS01)|(1<<CS00);
	unsigned short Temp = 0;
	char Buffer[16];
	unsigned char count = 0, RecieveRequst ,motorflag=0;
	while (1)
	{
		RecieveRequst=SPI_Recieve();
		switch (SPI_Recieve())
		{
			case '1':
			PORTC |=(1<<7);
			break;
			case '2':
			PORTC &=~(1<<7);
			break;
			case '3':
			Temp = ADC_Read(1);
			Temp/=4;
			itoa(Temp,Buffer,10);
			LCD_StartPOS(1,0);
			LCD_String("THE TEMP. = ");
			LCD_String (Buffer);
			//_delay_ms(5000);
		   //LCD_CMD(0x01);
			break;
			case 's':
			OCR0 = 0;
			PORTC &=~(1<<3);
			PORTC|=(1<<4);
			LCD_CMD(0X01);
			LCD_StartPOS(1,1);
			LCD_String("Speed = 0");
			motorflag = 1;
			count =0;
			break;
			case 'e':
			OCR0 = 0;
			PORTC &=~(1<<3);
			PORTC &=~(1<<4);
			motorflag = 0;
			count = 0;
			break;
			case '+':
			if (motorflag == 0)
			{
				LCD_CMD(0x01);
				LCD_StartPOS(1,1);
				LCD_String("please Turn on Motor");
			}
			else
			{
				count++;
				switch(count)
				{
					case 1:
					OCR0 = 63;
					LCD_CMD(0x01);
					LCD_StartPOS(1,1);
					LCD_String("Speed 25%");
					break;
					case 2:
					OCR0 = 127;
					LCD_CMD(0x01);
					LCD_StartPOS(1,1);
					LCD_String("speed 50%");
					break;
					case 3:
					OCR0 = 191;
					LCD_CMD(0x01);
					LCD_StartPOS(1,1);
					LCD_String("Speed 75%");
					break;
					case 4:
					OCR0 = 255;
					LCD_CMD(0x01);
					LCD_StartPOS(1,1);
					LCD_String("Speed 100%");
					break;
				}
					if (count>4)
					{
						count=4;
					}
					break;
			}
			case '-':
			{
				if (motorflag==0)
				{
					LCD_CMD(0x01);
					LCD_StartPOS(1,1);
					LCD_String("please Turn on Motor");
				}
				else
				{
					count--;
					switch(count)
					{
						case 0:
						OCR0 = 0;
						LCD_CMD(0x01);
						LCD_StartPOS(1,1);
						LCD_String("Speed = 0");
						break;
						case 1:
						OCR0 = 63;
						LCD_CMD(0x01);
						LCD_StartPOS(1,1);
						LCD_String("Speed 25%");
						break;
						case 2:
						OCR0 = 127;
						LCD_CMD(0x01);
						LCD_StartPOS(1,1);
						LCD_String("speed 50%");
						break;
						case 3:
						OCR0 = 191;
						LCD_CMD(0x01);
						LCD_StartPOS(1,1);
						LCD_String("Speed 75%");
						break;
						case 4:
						OCR0 = 255;
						LCD_CMD(0x01);
						LCD_StartPOS(1,1);
						LCD_String("Speed 100%");
						break;
					}
					if(count<0)
					{
						count=0;
					}
					break;
				}
			}
		}
	}
}


