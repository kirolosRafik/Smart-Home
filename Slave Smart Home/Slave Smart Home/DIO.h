/*
 * DIO.h
 *
 * Created: 3/12/2021 3:12:29 PM
 *  Author: Kero
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "BIT_MATH.h"
#include "STD_Types.h"
#include "DIO_Types.h"
#include "DIO_HW.h"

void DIO_write (Dio_channelTybes ChannelId,STD_LevelTypes Level1);
void DIO_writePort (Dio_portTybes portId,Uint8 data);

#endif /* DIO_H_ */