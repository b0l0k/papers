/* 
Copyright (c) FRET.  All rights reserved.

File Name : DEVOBJ_EXTENSION.h

Abstract:
 Device Object Extension structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 26-Aug-2006 
*/

//!< \warning This structure is already defined in NTDDK.h but is better defined here !

#ifndef _DEVOBJ_EXTENSION_H_INCLUDED
#define _DEVOBJ_EXTENSION_H_INCLUDED

#include "DEVICE_OBJECT.h"
#include "DEVICE_OBJECT_POWER_EXTENSION.h"
#include "VPB.h"

#ifndef DEVOBJ_EXTENSION_INCLUDED
#define DEVOBJ_EXTENSION_INCLUDED
#ifndef _NTDDK_

typedef struct _DEVOBJ_EXTENSION
{
	CSHORT			Type;			//+0x000
	USHORT			Size;			//+0x002
	PDEVICE_OBJECT	DeviceObject;	//+0x004 *** End of DKK definition ***
	ULONG			PowerFlags;		//+0x008
	PDEVICE_OBJECT_POWER_EXTENSION	Dope;		//+0x00c
	ULONG			ExtensionFlags;	//+0x010
	PVOID			DeviceNode;		//+0x014
	PDEVICE_OBJECT	AttachedTo;		//+0x018
	LONG			StartIoCount;	//+0x01c
	LONG			StartIoKey;		//+0x020
	ULONG			StartIoFlags;	//+0x024
	PVPB			Vpb;			//+0x028
} DEVOBJ_EXTENSION, *PDEVOBJ_EXTENSION, **PPDEVOBJ_EXTENSION;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
