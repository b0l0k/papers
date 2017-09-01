/* 
Copyright (c) FRET.  All rights reserved.

File Name : HANDLE_TRACE_DB_ENTRY.h

Abstract:
Handle Trace Debug Entry structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 26-Aug-2006 
*/

#ifndef _HANDLE_TRACE_DB_ENTRY_H_INCLUDED
#define _HANDLE_TRACE_DB_ENTRY_H_INCLUDED

#include "CLIENT_ID.h"

#ifndef HANDLE_TRACE_DB_ENTRY_INCLUDED
#define HANDLE_TRACE_DB_ENTRY_INCLUDED

// <size 0x50>
typedef struct _HANDLE_TRACE_DB_ENTRY
{
	CLIENT_ID	ClientId;		//+0x000
	PVOID		Handle;			//+0x008
	ULONG		Type;			//+0x00c
	PVOID		StackTrace [16];//+0x010
} HANDLE_TRACE_DB_ENTRY, *PHANDLE_TRACE_DB_ENTRY, **PPHANDLE_TRACE_DB_ENTRY;

#endif //_INCLUDED
#endif //_H_INCLUDED
