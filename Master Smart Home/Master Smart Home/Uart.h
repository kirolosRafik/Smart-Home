/*
 * Uart.h
 *
 * Created: 3/12/2021 2:54:07 PM
 *  Author: Kero
 */ 


#ifndef UART_H_
#define UART_H_
#include <avr/io.h>
#define F_CPU 16000000UL
#define BAUDRATE 9600
//#ifndef DoubleSpeed
#define MYUBRR ((F_CPU / (16UL * BAUDRATE)) -1)
//#else
//#define MYUBRR ((F_CPU / (8UL * BAUDRATE)) -1)
//#endif

void Uart_Init();
void UartSend(unsigned char Data);
unsigned char UartReceive();
void UartSendString (char*string);

#endif /* UART_H_ */