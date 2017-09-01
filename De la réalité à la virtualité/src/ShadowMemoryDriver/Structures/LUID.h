/* 
Copyright (c) FRET.  All rights reserved.

File Name : LUID.h

Abstract:
Locally Unique Identifier structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/


#ifndef _LUID_H_INCLUDED
#define _LUID_H_INCLUDED

#ifndef LUID_INCLUDED
#define LUID_INCLUDED
#ifndef _NTDDK_ //defined in <ntdef.h>

// <size 0x8>
typedef struct _LUID
{
	ULONG	LowPart;		//+0x000
	LONG	HighPart;		//+0x004
} LUID, *PLUID, **PPLUID;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
