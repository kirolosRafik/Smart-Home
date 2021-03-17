/*
 * DIO.c
 *
 * Created: 3/12/2021 3:11:55 PM
 *  Author: Kero
 */ 
#include "DIO.h"

void DIO_write (Dio_channelTybes ChannelId,STD_LevelTypes Level1)
{
	Dio_portTybes portx = ChannelId / 8;
	Dio_channelTybes BitNumber = ChannelId % 8;
	switch (portx)
	{
		case Dio_PORTA:
		if (Level1 == STD_High)
		{
			Set_Bit(PORTA_Reg,BitNumber);
		}
		else
		{
			Clear_Bit(PORTA_Reg,BitNumber);
		}
		break;
		case Dio_portB:
		if (Level1 == STD_High)
		{
			Set_Bit(PORTB_Reg,BitNumber);
		}
		else
		{
			Clear_Bit(PORTB_Reg,BitNumber);
		}
		break;
		case Dio_portC:
		if (Level1 == STD_High)
		{
			Set_Bit(PORTC_Reg,BitNumber);
		}
		else
		{
			Clear_Bit(PORTC_Reg,BitNumber);
		}
		break;
		case Dio_portD:
		if (Level1 == STD_High)
		{
			Set_Bit(PORTD_Reg,BitNumber);
		}
		else
		{
			Clear_Bit(PORTD_Reg,BitNumber);
		}
		break;
	}
}
//write in LCD
void DIO_writePort (Dio_portTybes portId,Uint8 data)
{
	switch(portId)
	{
		case Dio_PORTA:
		PORTA_Reg = data;
		break;
		case Dio_portB:
		PORTB_Reg = data;
		break;
		case Dio_portC:
		PORTC_Reg = data;
		break;
		case Dio_portD:
		PORTD_Reg = data;
		break;
	}
}