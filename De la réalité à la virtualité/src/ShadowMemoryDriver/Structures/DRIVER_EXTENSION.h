/* 
Copyright (c) FRET.  All rights reserved.

File Name : DRIVER_EXTENSION.h

Abstract:
 Driver Extension structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 26-Aug-2006 
*/

#ifndef _DRIVER_EXTENSION_H_INCLUDED
#define _DRIVER_EXTENSION_H_INCLUDED

#include "DRIVER_OBJECT.h"
#include "UNICODE_STRING.h"
#include "IO_CLIENT_EXTENSION.h"
#include "FS_FILTER_CALLBACKS.h"

#ifndef DRIVER_EXTENSION_INCLUDED
#define DRIVER_EXTENSION_INCLUDED
#ifndef _NTDDK_

typedef struct _DRIVER_EXTENSION
{
	PDRIVER_OBJECT	DriverObject;			//+0x000
	PVOID			AddDevice;				//+0x004
	ULONG			Count;					//+0x008
	UNICODE_STRING	ServiceKeyName;			//+0x00c
	PIO_CLIENT_EXTENSION	ClientDriverExtension;	//+0x014
	PFS_FILTER_CALLBACKS	FsFilterCallbacks;		//+0x018
} DRIVER_EXTENSION, *PDRIVER_EXTENSION, **PPDRIVER_EXTENSION;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
