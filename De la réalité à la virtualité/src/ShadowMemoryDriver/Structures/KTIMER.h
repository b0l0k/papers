/* 
Copyright (c) FRET.  All rights reserved.

File Name : KTIMER.h

Abstract:
Kernel Timer structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _KTIMER_H_INCLUDED
#define _KTIMER_H_INCLUDED

#include "DISPATCHER_HEADER.h"
#include "ULARGE_INTEGER.h"
#include "LIST_ENTRY.h"
#include "KDPC.h"

#ifndef KTIMER_INCLUDED
#define KTIMER_INCLUDED
#ifndef _NTDDK_

typedef struct _KTIMER
{
	DISPATCHER_HEADER	Header;			//+0x000
	ULARGE_INTEGER		DueTime;		//+0x010
	LIST_ENTRY			TimerListEntry;	//+0x018
	PKDPC				Dpc;			//+0x020
	LONG				Period;			//+0x024
} KTIMER, *PKTIMER, **PPKTIMER;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
