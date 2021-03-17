/*
 * Uart.c
 *
 * Created: 3/12/2021 2:53:46 PM
 *  Author: Kero
 */ 
#include "UART.h"

void Uart_Init()
{
	UCSRB|=(1<<RXEN)|(1<<TXEN);
	UCSRC|=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	UBRRL = MYUBRR; //Low 8 bit
	UBRRH = (MYUBRR>>8);
}
void UartSend(unsigned char Data)
{
	while (!(UCSRA & (1<<UDRE)));
	UDR = Data;
}
unsigned char UartReceive()
{
	while (!(UCSRA & (1<<RXC)));
	return UDR;
}
void UartSendString (char*string)
{
	unsigned char i =0;
	while(string[i] !='\0')
	{
		UartSend(string[i]);
		i++;
	}
}