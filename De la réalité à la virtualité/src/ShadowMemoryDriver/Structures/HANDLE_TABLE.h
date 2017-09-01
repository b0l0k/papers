/* 
Copyright (c) FRET.  All rights reserved.

File Name : HANDLE_TABLE.h

Abstract:
Handle Table structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _HANDLE_TABLE_H_INCLUDED
#define _HANDLE_TABLE_H_INCLUDED

#include "EPROCESS.h"
#include "EX_PUSH_LOCK.h"
#include "LIST_ENTRY.h"
#include "HANDLE_TRACE_DEBUG_INFO.h"


#ifndef HANDLE_TABLE_INCLUDED
#define HANDLE_TABLE_INCLUDED

// <size 0x44>
typedef struct _HANDLE_TABLE
{
	ULONG			TableCode;				//+0x000
	PEPROCESS		QuotaProcess;			//+0x004
	PVOID			UniqueProcessId;		//+0x008
	EX_PUSH_LOCK	HandleTableLock [4];	//+0x00c
	LIST_ENTRY		HandleTableList;		//+0x01c
	EX_PUSH_LOCK	HandleContentionEvent;	//+0x024
	PHANDLE_TRACE_DEBUG_INFO	DebugInfo;	//+0x028
	LONG			ExtraInfoPages;			//+0x02c
	ULONG			FirstFree;				//+0x030
	ULONG			LastFree;				//+0x034
	ULONG			NextHandleNeedingPool;	//+0x038
	LONG			HandleCount;			//+0x03c
	union
	{
		ULONG			Flags;				//+0x040
		ULONG 			StrictFIFO : 1;		//0, +0x040
	};
} HANDLE_TABLE, *PHANDLE_TABLE, **PPHANDLE_TABLE;

#endif //_INCLUDED
#endif //_H_INCLUDED
