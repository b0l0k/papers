/* 
Copyright (c) FRET.  All rights reserved.

File Name : SINGLE_LIST_ENTRY.h

Abstract:
Signle List Entry structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 1-Sep-2006 
*/

#ifndef _SINGLE_LIST_ENTRY_H_INCLUDED
#define _SINGLE_LIST_ENTRY_H_INCLUDED

#ifndef SINGLE_LIST_ENTRY_INCLUDED
#define SINGLE_LIST_ENTRY_INCLUDED
#ifndef _NTDDK_

typedef struct _SINGLE_LIST_ENTRY
{
	PSINGLE_LIST_ENTRY	Next;		//+0x000
} SINGLE_LIST_ENTRY, *PSINGLE_LIST_ENTRY, **PPSINGLE_LIST_ENTRY;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
