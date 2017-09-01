/* 
Copyright (c) FRET.  All rights reserved.

File Name : OWNER_ENTRY.h

Abstract:
Owner Entry structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _OWNER_ENTRY_H_INCLUDED
#define _OWNER_ENTRY_H_INCLUDED

#ifndef OWNER_ENTRY_INCLUDED
#define OWNER_ENTRY_INCLUDED
#ifndef _NTDDK_

typedef struct _OWNER_ENTRY
{
	ULONG	OwnerThread;	//+0x000
	LONG	OwnerCount;		//+0x004
	ULONG	TableSize;		//+0x004
} OWNER_ENTRY, *POWNER_ENTRY, **PPOWNER_ENTRY;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
