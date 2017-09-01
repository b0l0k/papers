/* 
 Copyright (c) FRET.  All rights reserved.

File Name : KDPC.h

Abstract:
Kernel Deferred Procedure Call object structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 05
Last Update : 2-Sep-2006 
*/

#ifndef _KDPC_H_INCLUDED
#define _KDPC_H_INCLUDED

#include "LIST_ENTRY.h"


#ifndef KDPC_INCLUDED
#define KDPC_INCLUDED
#ifndef _NTDDK_

struct _KDPC;

typedef
VOID
(*PKDEFERRED_ROUTINE) (
    IN struct _KDPC *Dpc,
    IN PVOID DeferredContext,
    IN PVOID SystemArgument1,
    IN PVOID SystemArgument2
    );

typedef struct _KDPC
{
	CSHORT				Type;				//+0x000
	UCHAR				Number;				//+0x002
	UCHAR				Importance;			//+0x003
	LIST_ENTRY			DpcListEntry;		//+0x004
	PKDEFERRED_ROUTINE	DeferredRoutine;	//+0x00c
	PVOID				DeferredContext;	//+0x010
	PVOID				SystemArgument1;	//+0x014
	PVOID				SystemArgument2;	//+0x018
	PULONG_PTR			Lock;				//+0x01c
} KDPC, *PKDPC, **PPKDPC;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
