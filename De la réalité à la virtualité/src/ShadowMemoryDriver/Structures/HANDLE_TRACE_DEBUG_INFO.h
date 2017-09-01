/* 
Copyright (c) FRET.  All rights reserved.

File Name : HANDLE_TRACE_DEBUG_INFO.h

Abstract:
Handle Trace Debug Info structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 26-Aug-2006 
*/

#ifndef _HANDLE_TRACE_DEBUG_INFO_H_INCLUDED
#define _HANDLE_TRACE_DEBUG_INFO_H_INCLUDED

#include "HANDLE_TRACE_DB_ENTRY.h"

#ifndef HANDLE_TRACE_DEBUG_INFO_INCLUDED
#define HANDLE_TRACE_DEBUG_INFO_INCLUDED

// <size 0x50004>
typedef struct _HANDLE_TRACE_DEBUG_INFO
{
	ULONG	CurrentStackIndex;		//+0x000
	HANDLE_TRACE_DB_ENTRY	TraceDb [4096];		//+0x004
} HANDLE_TRACE_DEBUG_INFO, *PHANDLE_TRACE_DEBUG_INFO, **PPHANDLE_TRACE_DEBUG_INFO;

#endif //_INCLUDED
#endif //_H_INCLUDED
