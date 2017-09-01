/* 
Copyright (c) FRET.  All rights reserved.

File Name : KQUEUE.h

Abstract:
Kernel Queue structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _KQUEUE_H_INCLUDED
#define _KQUEUE_H_INCLUDED

#include "DISPATCHER_HEADER.h"
#include "LIST_ENTRY.h"

#ifndef KQUEUE_INCLUDED
#define KQUEUE_INCLUDED

// <size 0x28>
typedef struct _KQUEUE
{
	DISPATCHER_HEADER	Header;				//+0x000
	LIST_ENTRY			EntryListHead;		//+0x010
	ULONG				CurrentCount;		//+0x018
	ULONG				MaximumCount;		//+0x01c
	LIST_ENTRY			ThreadListHead;		//+0x020
} KQUEUE, *PKQUEUE, **PPKQUEUE;

#endif //_INCLUDED
#endif//_H_INCLUDED
