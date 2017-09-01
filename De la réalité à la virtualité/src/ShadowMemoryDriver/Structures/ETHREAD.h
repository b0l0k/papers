/* 
Copyright (c) FRET.  All rights reserved.

File Name : ETHREAD.h

Abstract:
Executive Thread structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 1-Sep-2006 
*/

#ifndef _ETHREAD_H_INCLUDED
#define _ETHREAD_H_INCLUDED

#include "KTHREAD.h"
#include "LARGE_INTEGER.h"
#include "LIST_ENTRY.h"
#include "TERMINATION_PORT.h"
#include "CLIENT_ID.h"
#include "KSEMAPHORE.h"
#include "LPC_MESSAGE.h"
#include "PS_IMPERSONATION_INFORMATION.h"
#include "DEVICE_OBJECT.h"
#include "EPROCESS.h"
#include "EX_RUNDOWN_REF.h"
#include "EX_PUSH_LOCK.h"

#ifndef ETHREAD_INCLUDED
#define ETHREAD_INCLUDED

//Define PKSTART_ROUTINE
#ifndef _NTDDK_
	typedef VOID(DDKAPI * PKSTART_ROUTINE)(IN PVOID StartContext)
#endif

#include <pshpack4.h> // 4 byte packing
typedef struct _ETHREAD
{
	KTHREAD				Tcb;						//+0x000
	union {
		LARGE_INTEGER	CreateTime;					//+0x1c0
		struct {
			ULONG 		NestedFaultCount : 2;		//0, +0x1c0
			ULONG 		ApcNeeded : 1;				//2, +0x1c0
		};
	};
	union {
		LARGE_INTEGER	ExitTime;					//+0x1c8
		LIST_ENTRY		LpcReplyChain;				//+0x1c8
		LIST_ENTRY		KeyedWaitChain;				//+0x1c8
	};
	union {
		NTSTATUS		ExitStatus;					//+0x1d0
		PVOID			OfsChain;					//+0x1d0
	};
	LIST_ENTRY			PostBlockList;				//+0x1d4
	union {
		PTERMINATION_PORT	TerminationPort;		//+0x1dc
		PETHREAD		ReaperLink;					//+0x1dc
		PVOID			KeyedWaitValue;				//+0x1dc
	};
	KSPIN_LOCK			ActiveTimerListLock;		//+0x1e0
	LIST_ENTRY			ActiveTimerListHead;		//+0x1e4
	CLIENT_ID			Cid;						//+0x1ec
	union {
		KSEMAPHORE		LpcReplySemaphore;			//+0x1f4
		KSEMAPHORE		KeyedWaitSemaphore;			//+0x1f4
	};
	union {
		PLPC_MESSAGE	LpcReplyMessage;			//+0x208
		PVOID			LpcWaitingOnPort;			//+0x208
	};
	PPS_IMPERSONATION_INFORMATION	ImpersonationInfo;	//+0x20c
	LIST_ENTRY			IrpList;					//+0x210
	ULONG				TopLevelIrp;				//+0x218
	PDEVICE_OBJECT		DeviceToVerify;				//+0x21c
	PEPROCESS			ThreadsProcess;				//+0x220
	PKSTART_ROUTINE		StartAddress;				//+0x224
	union {
		PVOID			Win32StartAddress;			//+0x228
		ULONG			LpcReceivedMessageId;		//+0x228
	};
	LIST_ENTRY			ThreadListEntry;			//+0x22c
	EX_RUNDOWN_REF		RundownProtect;				//+0x234
	EX_PUSH_LOCK		ThreadLock;					//+0x238
	ULONG				LpcReplyMessageId;			//+0x23c
	ULONG				ReadClusterSize;			//+0x240
	ACCESS_MASK			GrantedAccess;				//+0x244
	union {
		ULONG			CrossThreadFlags;			//+0x248
		struct {
			ULONG		Terminated : 1;				//0, +0x248
			ULONG		DeadThread : 1;				//1, +0x248
			ULONG		HideFromDebugger : 1;		//2, +0x248
			ULONG		ActiveImpersonationInfo : 1;//3, +0x248
			ULONG		SystemThread : 1;			//4, +0x248
			ULONG	 	HardErrorsAreDisabled : 1;	//5, +0x248
			ULONG		BreakOnTermination : 1;		//6, +0x248
			ULONG		SkipCreationMsg : 1;		//7, +0x248
			ULONG		SkipTerminationMsg : 1;		//8, +0x248
		};
	};
	union {
		ULONG			SameThreadPassiveFlags;		//+0x24c
		struct {
			ULONG		ActiveExWorker : 1;			//0, +0x24c
			ULONG		ExWorkerCanWaitUser : 1;	//1, +0x24c
			ULONG		MemoryMaker : 1;			//2, +0x24c
		};
	};
	union {
		ULONG			SameThreadApcFlags;			//+0x250
		struct {
			BOOLEAN 	LpcReceivedMsgIdValid : 1;	//0, +0x250
			BOOLEAN 	LpcExitThreadCalled : 1;	//1, +0x250
			BOOLEAN 	AddressSpaceOwner : 1;		//2, +0x250
		};
	};
	BOOLEAN				ForwardClusterOnly;			//+0x254
	BOOLEAN				DisablePageFaultClustering;	//+0x255
} ETHREAD, *PETHREAD, **PPETHREAD;
#include <poppack.h> // Normal packing

#endif //_INCLUDED
#endif //_H_INCLUDED
