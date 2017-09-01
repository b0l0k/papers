/* 
Copyright (c) FRET.  All rights reserved.

File Name : KPROCESS.h

Abstract:
Kernel Process structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 05
Last Update : 2-Sep-2006 
*/

#ifndef _KPROCESS_H_INCLUDED
#define _KPROCESS_H_INCLUDED

#include "DISPATCHER_HEADER.h"
#include "LIST_ENTRY.h"
#include "KGDTENTRY.h"
#include "KIDTENTRY.h"
#include "SINGLE_LIST_ENTRY.h"
#include "KEXECUTE_OPTIONS.h"

#ifndef KPROCESS_INCLUDED
#define KPROCESS_INCLUDED

typedef struct _KPROCESS
{
	DISPATCHER_HEADER	Header;					//+0x000
	LIST_ENTRY			ProfileListHead;		//+0x010
	ULONG				DirectoryTableBase [2];	//+0x018
	KGDTENTRY			LdtDescriptor;			//+0x020
	KIDTENTRY			Int21Descriptor;		//+0x028
	USHORT				IopmOffset;				//+0x030
	UCHAR				Iopl;					//+0x032
	UCHAR				Unused;					//+0x033
	ULONG				ActiveProcessors;		//+0x034
	ULONG				KernelTime;				//+0x038
	ULONG				UserTime;				//+0x03c
	LIST_ENTRY			ReadyListHead;			//+0x040
	SINGLE_LIST_ENTRY	SwapListEntry;			//+0x048
	PVOID				VdmTrapcHandler;		//+0x04c
	LIST_ENTRY			ThreadListHead;			//+0x050
	ULONG				ProcessLock;			//+0x058
	ULONG				Affinity;				//+0x05c
	USHORT				StackCount;				//+0x060
	CHAR				BasePriority;			//+0x062
	CHAR				ThreadQuantum;			//+0x063
	UCHAR				AutoAlignment;			//+0x064
	UCHAR				State;					//+0x065
	UCHAR				ThreadSeed;				//+0x066
	UCHAR				DisableBoost;			//+0x067
	UCHAR				PowerState;				//+0x068
	UCHAR				DisableQuantum;			//+0x069
	UCHAR				IdealNode;				//+0x06a
	union
	{
		KEXECUTE_OPTIONS	Flags;				//+0x06b
		UCHAR				ExecuteOptions;		//+0x06b
	};
} KPROCESS, *PKPROCESS, **PPKPROCESS;

#endif //_INCLUDED
#endif //_H_INCLUDED
