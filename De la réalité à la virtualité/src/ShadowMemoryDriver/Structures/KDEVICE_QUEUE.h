/* 
Copyright (c) FRET.  All rights reserved.

File Name : KDEVICE_QUEUE.h

Abstract:
Kernel Device Queue Object structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _KDEVICE_QUEUE_H_INCLUDED
#define _KDEVICE_QUEUE_H_INCLUDED

#include "LIST_ENTRY.h"

#ifndef KDEVICE_QUEUE_INCLUDED
#define KDEVICE_QUEUE_INCLUDED
#ifndef _NTDDK_

//<size 0x14>
typedef struct _KDEVICE_QUEUE
{
	CSHORT		Type;			//+0x000
	CSHORT		Size;			//+0x002
	LIST_ENTRY	DeviceListHead;	//+0x004
	KSPIN_LOCK	Lock;			//+0x00c
	BOOLEAN		Busy;			//+0x010
} KDEVICE_QUEUE, *PKDEVICE_QUEUE, **PPKDEVICE_QUEUE;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
