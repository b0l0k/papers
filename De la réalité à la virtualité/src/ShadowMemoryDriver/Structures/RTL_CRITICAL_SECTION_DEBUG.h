/* 
 Copyright (c) FRET.  All rights reserved.

File Name : RTL_CRITICAL_SECTION_DEBUG.h

Abstract:
Runtime Library Critical Section Debug structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 23-Aug-2006 
*/

#ifndef _RTL_CRITICAL_SECTION_DEBUG_H_INCLUDED
#define _RTL_CRITICAL_SECTION_DEBUG_H_INCLUDED

#include "RTL_CRITICAL_SECTION.h"
#include "LIST_ENTRY.h"

#ifndef RTL_CRITICAL_SECTION_DEBUG_INCLUDED
#define RTL_CRITICAL_SECTION_DEBUG_INCLUDED
#ifndef _WINNT_

typedef struct _RTL_CRITICAL_SECTION_DEBUG
{
	USHORT			Type;					//+0x000
	USHORT			CreatorBackTraceIndex;	//+0x002
	struct _RTL_CRITICAL_SECTION *	CriticalSection;//+0x004
	LIST_ENTRY		ProcessLocksList;		//+0x008
	ULONG			EntryCount;				//+0x010
	ULONG			ContentionCount;		//+0x014
	ULONG			Spare [2];				//+0x018
} RTL_CRITICAL_SECTION_DEBUG, *PRTL_CRITICAL_SECTION_DEBUG, **PPRTL_CRITICAL_SECTION_DEBUG;

#endif //_WINNT_
#endif //_INCLUDED
#endif//_H_INCLUDED
