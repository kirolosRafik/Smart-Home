/*
 * ADC.h
 *
 * Created: 3/12/2021 3:08:44 PM
 *  Author: Kero
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>


void ADC_Init (void);
unsigned short ADC_Read (unsigned char channel);



#endif /* ADC_H_ */