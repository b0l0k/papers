/* 
Copyright (c) FRET.  All rights reserved.

File Name : .h

Abstract:
Memory Manager Extended Info structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _MMEXTEND_INFO_H_INCLUDED
#define _MMEXTEND_INFO_H_INCLUDED


#ifndef MMEXTEND_INFO_INCLUDED
#define MMEXTEND_INFO_INCLUDED

typedef struct _MMEXTEND_INFO
{
	ULONGLONG	CommittedSize;		//+0x000
	ULONG		ReferenceCount;		//+0x008
} MMEXTEND_INFO, *PMMEXTEND_INFO, **PPMMEXTEND_INFO;

#endif //_INCLUDED
#endif//_H_INCLUDED
