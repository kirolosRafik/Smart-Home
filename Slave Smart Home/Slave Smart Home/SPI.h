/*
 * SPI.h
 *
 * Created: 3/12/2021 3:19:20 PM
 *  Author: Kero
 */ 


#ifndef SPI_H_
#define SPI_H_
#include <avr/io.h>
#define SPIPort PORTB
#define SPIDDR DDRB

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

#define Slave_EN() (SPIPort&=~(1<<SS))
#define Slave_DIS() (SPIPort|=(1<<SS))

void SPI_Init (unsigned char status);
unsigned char SPI_TxRx(unsigned char data);
char SPI_Recieve ();


#endif /* SPI_H_ */