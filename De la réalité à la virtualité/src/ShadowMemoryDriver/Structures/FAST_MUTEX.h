/* 
Copyright (c) FRET.  All rights reserved.

File Name : FAST_MUTEX.h

Abstract:
Fast Mutex structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _FAST_MUTEX_H_INCLUDED
#define _FAST_MUTEX_H_INCLUDED

#include "KTHREAD.h"
#include "KEVENT.h"

#ifndef FAST_MUTEX_INCLUDED
#define FAST_MUTEX_INCLUDED
#ifndef _NTDDK_

typedef struct _FAST_MUTEX
{
	LONG		Count;			//+0x000
	PKTHREAD	Owner;			//+0x004
	ULONG		Contention;		//+0x008
	KEVENT		Event;			//+0x00c
	ULONG		OldIrql;		//+0x01c
} FAST_MUTEX, *PFAST_MUTEX, **PPFAST_MUTEX;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
