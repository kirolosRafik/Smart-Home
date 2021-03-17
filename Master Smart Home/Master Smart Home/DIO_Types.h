/*
 * DIO_Types.h
 *
 * Created: 3/12/2021 2:48:59 PM
 *  Author: Kero
 */ 


#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

typedef enum
{
	//portA
	Dio_channelA0=0,
	Dio_channelA1,
	Dio_channelA2,
	Dio_channelA3,
	Dio_channelA4,
	Dio_channelA5,
	Dio_channelA6,
	Dio_channelA7,
	//portB
	Dio_channelB0,
	Dio_channelB1,
	Dio_channelB2,
	Dio_channelB3,
	Dio_channelB4,
	Dio_channelB5,
	Dio_channelB6,
	Dio_channelB7,
	//portC
	Dio_channelC0,
	Dio_channelC1,
	Dio_channelC2,
	Dio_channelC3,
	Dio_channelC4,
	Dio_channelC5,
	Dio_channelC6,
	Dio_channelC7,
	//portD
	Dio_channelD0,
	Dio_channelD1,
	Dio_channelD2,
	Dio_channelD3,
	Dio_channelD4,
	Dio_channelD5,
	Dio_channelD6,
	Dio_channelD7
}Dio_channelTybes;

typedef enum
{
	Dio_PORTA=0,
	Dio_portB,
	Dio_portC,
	Dio_portD
}Dio_portTybes;

typedef enum
{
	Input=0,
	Output
}Dio_Dir;

#endif /* DIO_TYPES_H_ */