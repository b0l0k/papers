/* 
Copyright (c) FRET.  All rights reserved.

File Name : PAGEFAULT_HISTORY.h

Abstract:
Page Fault History structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _PAGEFAULT_HISTORY_H_INCLUDED
#define _PAGEFAULT_HISTORY_H_INCLUDED

#include "PROCESS_WS_WATCH_INFORMATION.h"

#ifndef PAGEFAULT_HISTORY_INCLUDED
#define PAGEFAULT_HISTORY_INCLUDED

typedef struct _PAGEFAULT_HISTORY
{
	ULONG	CurrentIndex;	//+0x000
	ULONG	MaxIndex;		//+0x004
	ULONG	SpinLock;		//+0x008
	PVOID	Reserved;		//+0x00c
	PROCESS_WS_WATCH_INFORMATION	WatchInfo [1];//+0x010
} PAGEFAULT_HISTORY, *PPAGEFAULT_HISTORY, **PPPAGEFAULT_HISTORY;

#endif //_INCLUDED
#endif//_H_INCLUDED
