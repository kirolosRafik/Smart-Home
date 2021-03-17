/*
 * SPI.c
 *
 * Created: 3/12/2021 3:19:02 PM
 *  Author: Kero
 */ 
#include "SPI.h"

void SPI_Init (unsigned char status)
{
	switch(status)
	{
		case 'M':
		SPIDDR |= (1<<SS)|(1<<MOSI)|(1<<SCK);
		SPIDDR &=~ (1<<MISO);
		SPCR |=(1<<MSTR)|(1<<SPE);
		Slave_DIS();
		break;
		case 'S':
		SPIDDR &=~ (1<<SS)|(1<<MOSI)|(1<<SCK);
		SPIDDR |= (1<<MISO);
		SPCR |= (1<<SPE);
		break;
	}
	
}

unsigned char SPI_TxRx(unsigned char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));   //waiting for reading data
	return SPDR;
}
char SPI_Recieve ()
{
	while(!(SPSR & (1<<SPIF)));
	return SPDR;//(SPDR)
}
