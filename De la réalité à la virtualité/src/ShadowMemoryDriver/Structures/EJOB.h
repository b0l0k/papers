/* 
Copyright (c) FRET.  All rights reserved.

File Name : EJOB.h

Abstract:
Executive Job  structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 26-Aug-2006 
*/

#ifndef _EJOB_H_INCLUDED
#define _EJOB_H_INCLUDED

#include "KEVENT.h"
#include "LIST_ENTRY.h"
#include "ERESOURCE.h"
#include "LARGE_INTEGER.h"
#include "PS_JOB_TOKEN_FILTER.h"
#include "IO_COUNTERS.h"
#include "FAST_MUTEX.h"

#ifndef EJOB_INCLUDED
#define EJOB_INCLUDED

#include <pshpack1.h> // 1 byte pack
typedef struct _EJOB
{
	KEVENT			Event;						//+0x000
	LIST_ENTRY		JobLinks;					//+0x010
	LIST_ENTRY		ProcessListHead;			//+0x018
	ERESOURCE		JobLock;					//+0x020
	LARGE_INTEGER	TotalUserTime;				//+0x058
	LARGE_INTEGER	TotalKernelTime;			//+0x060
	LARGE_INTEGER	ThisPeriodTotalUserTime;	//+0x068
	LARGE_INTEGER	ThisPeriodTotalKernelTime;	//+0x070
	ULONG			TotalPageFaultCount;		//+0x078
	ULONG			TotalProcesses;				//+0x07c
	ULONG			ActiveProcesses;			//+0x080
	ULONG			TotalTerminatedProcesses;	//+0x084
	LARGE_INTEGER	PerProcessUserTimeLimit;	//+0x088
	LARGE_INTEGER	PerJobUserTimeLimit;		//+0x090
	ULONG			LimitFlags;					//+0x098
	ULONG			MinimumWorkingSetSize;		//+0x09c
	ULONG			MaximumWorkingSetSize;		//+0x0a0
	ULONG			ActiveProcessLimit;			//+0x0a4
	ULONG			Affinity;					//+0x0a8
	UCHAR			PriorityClass;				//+0x0ac
	ULONG			UIRestrictionsClass;		//+0x0b0
	ULONG			SecurityLimitFlags;			//+0x0b4
	PVOID			Token;						//+0x0b8
	PPS_JOB_TOKEN_FILTER	Filter;				//+0x0bc
	ULONG			EndOfJobTimeAction;			//+0x0c0
	PVOID			CompletionPort;				//+0x0c4
	PVOID			CompletionKey;				//+0x0c8
	ULONG			SessionId;					//+0x0cc
	ULONG			SchedulingClass;			//+0x0d0
	ULONGLONG		ReadOperationCount;			//+0x0d8
	ULONGLONG		WriteOperationCount;		//+0x0e0
	ULONGLONG		OtherOperationCount;		//+0x0e8
	ULONGLONG		ReadTransferCount;			//+0x0f0
	ULONGLONG		WriteTransferCount;			//+0x0f8
	ULONGLONG		OtherTransferCount;			//+0x100
	IO_COUNTERS		IoInfo;						//+0x108
	ULONG			ProcessMemoryLimit;			//+0x138
	ULONG			JobMemoryLimit;				//+0x13c
	ULONG			PeakProcessMemoryUsed;		//+0x140
	ULONG			PeakJobMemoryUsed;			//+0x144
	ULONG			CurrentJobMemoryUsed;		//+0x148
	FAST_MUTEX		MemoryLimitsLock;			//+0x14c
	LIST_ENTRY		JobSetLinks;				//+0x16c
	ULONG			MemberLevel;				//+0x174
	ULONG			JobFlags;					//+0x178
} EJOB, *PEJOB, **PPEJOB;
#include <poppack.h>

#endif //_INCLUDED
#endif //_H_INCLUDED
