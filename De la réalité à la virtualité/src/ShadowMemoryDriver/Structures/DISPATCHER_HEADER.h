/* 
Copyright (c) FRET.  All rights reserved.

File Name : DISPATCH_HEADER.h

Abstract:
 Dispatcher Header structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 26-Aug-2006 
*/

#ifndef _DISPATCHER_HEADER_H_INCLUDED
#define _DISPATCHER_HEADER_H_INCLUDED

#include "LIST_ENTRY.h"

#ifndef DISPATCHER_HEADER_INCLUDED
#define DISPATCHER_HEADER_INCLUDED
#ifndef _NTDDK_

typedef struct _DISPATCHER_HEADER
{
	UCHAR	Type;			//+0x000
	UCHAR	Absolute;		//+0x001
	UCHAR	Size;			//+0x002
	UCHAR	Inserted;		//+0x003
	LONG	SignalState;	//+0x004
	LIST_ENTRY	WaitListHead;	//+0x008
} DISPATCHER_HEADER, *PDISPATCHER_HEADER, **PPDISPATCHER_HEADER;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
