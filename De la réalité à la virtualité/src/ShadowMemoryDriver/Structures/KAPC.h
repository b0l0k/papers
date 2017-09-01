/* 
Copyright (c) FRET.  All rights reserved.

File Name : KAPC.h

Abstract:
Kernel Asynchronous Procedure Call (APC) object structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 05
Last Update : 2-Sep-2006 
*/

#ifndef _KAPC_H_INCLUDED
#define _KAPC_H_INCLUDED

#include "KTHREAD.h"
#include "LIST_ENTRY.h"

#ifndef KAPC_INCLUDED
#define KAPC_INCLUDED
#ifndef _NTDDK_

struct _KAPC;

typedef
VOID
(*PKNORMAL_ROUTINE) (
    IN PVOID NormalContext,
    IN PVOID SystemArgument1,
    IN PVOID SystemArgument2
    );

typedef
VOID
(*PKKERNEL_ROUTINE) (
    IN struct _KAPC *Apc,
    IN OUT PKNORMAL_ROUTINE *NormalRoutine,
    IN OUT PVOID *NormalContext,
    IN OUT PVOID *SystemArgument1,
    IN OUT PVOID *SystemArgument2
    );

typedef
VOID
(*PKRUNDOWN_ROUTINE) (
    IN struct _KAPC *Apc
    );

typedef CCHAR KPROCESSOR_MODE;

// <size 0x30>
typedef struct _KAPC
{
	CSHORT				Type;				//+0x000
	CSHORT				Size;				//+0x002
	ULONG				Spare0;				//+0x004
	PKTHREAD			Thread;				//+0x008
	LIST_ENTRY			ApcListEntry;		//+0x00c
	PKKERNEL_ROUTINE	KernelRoutine;		//+0x014
	PKRUNDOWN_ROUTINE	RundownRoutine;		//+0x018
	PKNORMAL_ROUTINE	NormalRoutine;		//+0x01c
	PVOID				NormalContext;		//+0x020
	PVOID				SystemArgument1;	//+0x024
	PVOID				SystemArgument2;	//+0x028
	CCHAR				ApcStateIndex;		//+0x02c
	KPROCESSOR_MODE		ApcMode;			//+0x02d
	UCHAR				Inserted;			//+0x02e
} KAPC, *PKAPC, **PPKAPC;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
