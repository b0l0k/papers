/* 
Copyright (c) FRET.  All rights reserved.

File Name : KAPC_STATE.h

Abstract:
Kernel Asynchronous Procedure Call structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _KAPC_STATE_H_INCLUDED
#define _KAPC_STATE_H_INCLUDED

#include "LIST_ENTRY.h"
#include "KPROCESS.h"

#ifndef KAPC_STATE_INCLUDED
#define KAPC_STATE_INCLUDED

// <size 0x18>
typedef struct _KAPC_STATE
{
	LIST_ENTRY	ApcListHead [2];		//+0x000
	PKPROCESS	Process;				//+0x010
	UCHAR		KernelApcInProgress;	//+0x014
	UCHAR		KernelApcPending;		//+0x015
	UCHAR		UserApcPending;			//+0x016
} KAPC_STATE, *PKAPC_STATE, **PPKAPC_STATE;

#endif //_INCLUDED
#endif //_H_INCLUDED
