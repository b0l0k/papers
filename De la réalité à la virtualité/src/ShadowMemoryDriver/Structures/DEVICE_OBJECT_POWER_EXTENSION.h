/* 
Copyright (c) FRET.  All rights reserved.

File Name : DEVICE_OBJECT_POWER_EXTENSION.h

Abstract:
Device Object Power Extension  structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 1-Sep-2006 
*/

#ifndef _DEVICE_OBJECT_POWER_EXTENSION_H_INCLUDED
#define _DEVICE_OBJECT_POWER_EXTENSION_H_INCLUDED

#include "DEVICE_OBJECT.h"
#include "LIST_ENTRY.h"
#include "DEVICE_POWER_STATE.h"
#include "POWER_CHANNEL_SUMMARY.h"

#ifndef DEVICE_OBJECT_POWER_EXTENSION_INCLUDED
#define DEVICE_OBJECT_POWER_EXTENSION_INCLUDED

typedef struct _DEVICE_OBJECT_POWER_EXTENSION
{
	ULONG					IdleCount;				//+0x000
	ULONG					ConservationIdleTime;	//+0x004
	ULONG					PerformanceIdleTime;	//+0x008
	PDEVICE_OBJECT			DeviceObject;			//+0x00c
	LIST_ENTRY				IdleList;				//+0x010
	UCHAR					DeviceType;				//+0x018
	DEVICE_POWER_STATE		State;					//+0x01c
	LIST_ENTRY				NotifySourceList;		//+0x020
	LIST_ENTRY				NotifyTargetList;		//+0x028
	POWER_CHANNEL_SUMMARY	PowerChannelSummary;	//+0x030
	LIST_ENTRY				Volume;					//+0x044
} DEVICE_OBJECT_POWER_EXTENSION, *PDEVICE_OBJECT_POWER_EXTENSION, **PPDEVICE_OBJECT_POWER_EXTENSION;

#endif //_INCLUDED
#endif//_H_INCLUDED
