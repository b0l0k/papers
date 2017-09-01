/* 
Copyright (c) FRET.  All rights reserved.

File Name : DEVICE_MAP.h

Abstract:
 Device Map structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 26-Aug-2006 
*/

#ifndef _DEVICE_MAP_H_INCLUDED
#define _DEVICE_MAP_H_INCLUDED

#include "OBJECT_DIRECTORY.h"

#ifndef DEVICE_MAP_INCLUDED
#define DEVICE_MAP_INCLUDED

typedef struct _DEVICE_MAP
{
	struct _OBJECT_DIRECTORY *	DosDevicesDirectory;		//+0x000
	struct _OBJECT_DIRECTORY *	GlobalDosDevicesDirectory;	//+0x004
	ULONG	ReferenceCount;		//+0x008
	ULONG	DriveMap;			//+0x00c
	UCHAR	DriveType [32];		//+0x010
} DEVICE_MAP, *PDEVICE_MAP, **PPDEVICE_MAP;


#endif //_INCLUDED
#endif //_H_INCLUDED
