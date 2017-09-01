/* 
 Copyright (c) FRET.  All rights reserved.

File Name : RTL_CRITICAL_SECTION.h

Abstract:
Runtime Library Section structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 23-Aug-2006 
*/

#ifndef _RTL_CRITICAL_SECTION_H_INCLUDED
#define _RTL_CRITICAL_SECTION_H_INCLUDED

#include "RTL_CRITICAL_SECTION_DEBUG.h"

#ifndef RTL_CRITICAL_SECTION_INCLUDED
#define RTL_CRITICAL_SECTION_INCLUDED
#ifndef _WINNT_

// <size 0x18>
typedef struct _RTL_CRITICAL_SECTION
{
	PRTL_CRITICAL_SECTION_DEBUG	DebugInfo;	//+0x000
	LONG		LockCount;			//+0x004
	LONG		RecursionCount;		//+0x008
	HANDLE		OwningThread;		//+0x00c
	HANDLE		LockSemaphore;		//+0x010
	ULONG_PTR	SpinCount;			//+0x014
} RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION, **PPRTL_CRITICAL_SECTION;

#endif //_WINNT_
#endif //_INCLUDED
#endif //_H_INCLUDED
