/*
 * DIO_CFG.c
 *
 * Created: 3/12/2021 3:13:24 PM
 *  Author: Kero
 */ 
#include "DIO_CFG.h"

DIO_PinCFG ChannelCFG []= {
	//portA
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	//portB
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	//portC
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	//portD
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High}
};
void DIO_Init ()
{
	Dio_portTybes portx;
	Dio_channelTybes BitNumber;
	Uint8 count;
	for (count=Dio_channelA0;count<PinCount;count++)
	{
		portx = count / 8;
		BitNumber = count % 8;
		switch (portx)
		{
			case Dio_PORTA:
			if (ChannelCFG [count].ChannelDir == Output)
			{
				Set_Bit(DDRA_Reg,BitNumber);
			}
			else
			{
				Clear_Bit(DDRA_Reg,BitNumber);
			}
			break;
			case Dio_portB:
			if (ChannelCFG [count].ChannelDir == Output)
			{
				Set_Bit(DDRB_Reg,BitNumber);
			}
			else
			{
				Clear_Bit(DDRB_Reg,BitNumber);
			}
			break;
			case Dio_portC:
			if (ChannelCFG [count].ChannelDir == Output)
			{
				Set_Bit(DDRC_Reg,BitNumber);
			}
			else
			{
				Clear_Bit(DDRC_Reg,BitNumber);
			}
			break;
			case Dio_portD:
			if (ChannelCFG [count].ChannelDir == Output)
			{
				Set_Bit(DDRD_Reg,BitNumber);
			}
			else
			{
				Clear_Bit(DDRD_Reg,BitNumber);
			}
			break;
		}
	}
}