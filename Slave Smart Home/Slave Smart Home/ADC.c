/*
 * ADC.c
 *
 * Created: 3/12/2021 3:08:10 PM
 *  Author: Kero
 */ 
#include "ADC.h"

void ADC_Init (void)
{
	//Reference Selection Bits
	ADMUX|=(1<<REFS0)|(1<<REFS1);
	//enable ADC and 128 preScale
	ADCSRA|=(1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);	
}
unsigned short ADC_Read (unsigned char Channel)
{
	unsigned short Data =0;
	ADMUX = (ADMUX & 0xE0) | (Channel & 0x1F);
	ADCSRA|= (1<<ADSC); //Start Conversion
	//wait 25 or 13 ADC cycle
	while (!(ADCSRA & (1<<ADIF))); //read ADIF flag if 0 or 1
	//while(((ADCSRA>>ADIF)& 1)==0);
	ADCSRA |= (1<<ADIF); // clear ADIF flag
	Data = ADCL;
	Data |=(ADCH<<8);
	return Data;
}