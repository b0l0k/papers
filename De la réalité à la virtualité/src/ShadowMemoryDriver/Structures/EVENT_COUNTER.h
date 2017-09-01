/* 
Copyright (c) FRET.  All rights reserved.

File Name : EVENT_COUNTER.h

Abstract:
Event Counter structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 1-Sep-2006 
*/

#ifndef _EVENT_COUNTER_H_INCLUDED
#define _EVENT_COUNTER_H_INCLUDED

#include "SINGLE_LIST_ENTRY.h"
#include "KEVENT.h"

#ifndef EVENT_COUNTER_INCLUDED
#define EVENT_COUNTER_INCLUDED

typedef struct _EVENT_COUNTER
{
	SINGLE_LIST_ENTRY	ListEntry;		//+0x000
	ULONG				RefCount;		//+0x004
	KEVENT				Event;			//+0x008
} EVENT_COUNTER, *PEVENT_COUNTER, **PPEVENT_COUNTER;

#endif //_INCLUDED
#endif //_H_INCLUDED
