/* 
Copyright (c) FRET.  All rights reserved.

File Name : KTHREAD.h

Abstract:
Kernel Thread structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 05
Last Update : 2-Sep-2006 
*/

#ifndef _KTHREAD_H_INCLUDED
#define _KTHREAD_H_INCLUDED

#include "DISPATCHER_HEADER.h"
#include "LIST_ENTRY.h"
#include "TEB.h"
#include "KAPC_STATE.h"
#include "KWAIT_BLOCK.h"
#include "SINGLE_LIST_ENTRY.h"
#include "SERVICE_DESCRIPTOR_TABLE.h"
#include "KQUEUE.h"
#include "KTIMER.h"
#include "KTRAP_FRAME.h"
#include "KAPC.h"
#include "KSEMAPHORE.h"

#ifndef KTHREAD_INCLUDED
#define KTHREAD_INCLUDED

#include <pshpack1.h> // 1 byte pack
typedef struct _KTHREAD
{
	DISPATCHER_HEADER	Header;				//+0x000
	LIST_ENTRY			MutantListHead;		//+0x010
	PVOID				InitialStack;		//+0x018
	PVOID				StackLimit;			//+0x01c
	PTEB				Teb;				//+0x020
	PVOID				TlsArray;			//+0x024
	PVOID				KernelStack;		//+0x028
	BOOLEAN				DebugActive;		//+0x02c
	UCHAR				State;				//+0x02d
	UCHAR				Alerted [2];		//+0x02e
	UCHAR				Iopl;				//+0x030
	UCHAR				NpxState;			//+0x031
	CHAR				Saturation;			//+0x032
	CHAR				Priority;			//+0x033
	KAPC_STATE			ApcState;			//+0x034
	ULONG				ContextSwitches;	//+0x04c
	UCHAR				IdleSwapBlock;		//+0x050
	UCHAR				Spare0 [3];			//+0x051
	NTSTATUS			WaitStatus;			//+0x054
	UCHAR				WaitIrql;			//+0x058
	CHAR				WaitMode;			//+0x059
	UCHAR				WaitNext;			//+0x05a
	UCHAR				WaitReason;			//+0x05b
	PKWAIT_BLOCK		WaitBlockList;		//+0x05c
	union 
	{
		LIST_ENTRY		WaitListEntry;		//+0x060
		SINGLE_LIST_ENTRY	SwapListEntry;	//+0x060
	};
	ULONG				WaitTime;			//+0x068
	CHAR				BasePriority;		//+0x06c
	UCHAR				DecrementCount;		//+0x06d
	CHAR				PriorityDecrement;	//+0x06e
	CHAR				Quantum;			//+0x06f
	KWAIT_BLOCK			WaitBlock [4];		//+0x070
	PVOID				LegoData;			//+0x0d0
	ULONG				KernelApcDisable;	//+0x0d4
	ULONG				UserAffinity;		//+0x0d8
	UCHAR				SystemAffinityActive;//+0x0dc
	UCHAR				PowerState;			//+0x0dd
	UCHAR				NpxIrql;			//+0x0de
	UCHAR				InitialNode;		//+0x0df
	PSERVICE_DESCRIPTOR_TABLE	ServiceTable;//+0x0e0
	PKQUEUE				Queue;				//+0x0e4
	KSPIN_LOCK			ApcQueueLock;		//+0x0e8
	KTIMER				Timer;				//+0x0f0
	LIST_ENTRY			QueueListEntry;		//+0x118
	ULONG				SoftAffinity;		//+0x120
	ULONG				Affinity;			//+0x124
	BOOLEAN				Preempted;			//+0x128
	BOOLEAN				ProcessReadyQueue;	//+0x129
	BOOLEAN				KernelStackResident;//+0x12a
	UCHAR				NextProcessor;		//+0x12b
	PVOID				CallbackStack;		//+0x12c
	PVOID				Win32Thread;		//+0x130
	PKTRAP_FRAME		TrapFrame;			//+0x134
	PKAPC_STATE			ApcStatePointer [2];//+0x138
	CHAR				PreviousMode;		//+0x140
	BOOLEAN				EnableStackSwap;	//+0x141
	BOOLEAN				LargeStack;			//+0x142
	UCHAR				ResourceIndex;		//+0x143
	ULONG				KernelTime;			//+0x144
	ULONG				UserTime;			//+0x148
	KAPC_STATE			SavedApcState;		//+0x14c
	BOOLEAN				Alertable;			//+0x164
	UCHAR				ApcStateIndex;		//+0x165
	BOOLEAN				ApcQueueable;		//+0x166
	BOOLEAN				AutoAlignment;		//+0x167
	PVOID				StackBase;			//+0x168
	KAPC				SuspendApc;			//+0x16c
	KSEMAPHORE			SuspendSemaphore;	//+0x19c
	LIST_ENTRY			ThreadListEntry;	//+0x1b0
	CHAR				FreezeCount;		//+0x1b8
	CHAR				SuspendCount;		//+0x1b9
	UCHAR				IdealProcessor;		//+0x1ba
	BOOLEAN				DisableBoost;		//+0x1bb
} KTHREAD, *PKTHREAD, **PPKTHREAD;
 #include <poppack.h>

#endif //_INCLUDED
#endif //_H_INCLUDED
