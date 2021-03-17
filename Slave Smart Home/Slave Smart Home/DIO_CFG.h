/*
 * DIO_CFG.h
 *
 * Created: 3/12/2021 3:13:48 PM
 *  Author: Kero
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "DIO.h"

typedef struct
{
	Dio_Dir ChannelDir;
	STD_LevelTypes ChannelLevel;
}DIO_PinCFG;

#define PinCount 32

void DIO_Init (void);


#endif /* DIO_CFG_H_ */