/* 
Copyright (c) FRET.  All rights reserved.

File Name : KDEVICE_QUEUE_ENTRY.h

Abstract:
Kernel Device Queue Entry structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _KDEVICE_QUEUE_ENTRY_H_INCLUDED
#define _KDEVICE_QUEUE_ENTRY_H_INCLUDED

#include "LIST_ENTRY.h"

#ifndef KDEVICE_QUEUE_ENTRY_INCLUDED
#define KDEVICE_QUEUE_ENTRY_INCLUDED
#ifndef _NTDDK_

typedef struct _KDEVICE_QUEUE_ENTRY
{
	LIST_ENTRY		DeviceListEntry;	//+0x000
	ULONG			SortKey;			//+0x008
	BOOLEAN			Inserted;			//+0x00c
} KDEVICE_QUEUE_ENTRY, *PKDEVICE_QUEUE_ENTRY, **PPKDEVICE_QUEUE_ENTRY;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED