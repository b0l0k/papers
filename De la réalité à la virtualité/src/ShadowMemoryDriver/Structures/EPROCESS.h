/* 
Copyright (c) FRET.  All rights reserved.

File Name : EPROCESS.h

Abstract:
Executive Process structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 05
Last Update : 1-Sep-2006 
*/

#ifndef _EPROCESS_H_INCLUDED
#define _EPROCESS_H_INCLUDED

#include "KPROCESS.h"
#include "EX_PUSH_LOCK.h"
#include "LARGE_INTEGER.h"
#include "EX_RUNDOWN_REF.h"
#include "LIST_ENTRY.h"
#include "HANDLE_TABLE.h"
#include "EX_FAST_REF.h"
#include "FAST_MUTEX.h"
#include "ETHREAD.h"
#include "EJOB.h"
#include "EPROCESS_QUOTA_BLOCK.h"
#include "PAGEFAULT_HISTORY.h"
#include "DEVICE_MAP.h"
#include "HARDWARE_PTE_X86.h"
#include "PEB.h"
#include "SE_AUDIT_PROCESS_CREATION_INFO.h"
#include "SECTION_OBJECT.h"
#include "MMSUPPORT.h"

#ifndef EPROCESS_INCLUDED
#define EPROCESS_INCLUDED

/*
#if (_WIN32_WINNT == 0x500) && (WINVER == 0x500)
	#error WIN2K EPROCESS structure not implemented

#elif (_WIN32_WINNT == 0x501) && (WINVER == 0x501)
*/
typedef struct _EPROCESS
{
	KPROCESS			Pcb;					//+0x000
	EX_PUSH_LOCK		ProcessLock;			//+0x06c
	LARGE_INTEGER		CreateTime;				//+0x070
	LARGE_INTEGER		ExitTime;				//+0x078
	EX_RUNDOWN_REF		RundownProtect;			//+0x080
	HANDLE				UniqueProcessId;		//+0x084
	LIST_ENTRY			ActiveProcessLinks;		//+0x088
	ULONG				QuotaUsage [3];			//+0x090
	ULONG				QuotaPeak [3];			//+0x09c
	ULONG				CommitCharge;			//+0x0a8
	ULONG				PeakVirtualSize;		//+0x0ac
	ULONG				VirtualSize;			//+0x0b0
	LIST_ENTRY			SessionProcessLinks;	//+0x0b4
	PVOID				DebugPort;				//+0x0bc
	PVOID				ExceptionPort;			//+0x0c0
	PHANDLE_TABLE		ObjectTable;			//+0x0c4
	EX_FAST_REF			Token;					//+0x0c8
	FAST_MUTEX			WorkingSetLock;			//+0x0cc
	ULONG				WorkingSetPage;			//+0x0ec
	FAST_MUTEX			AddressCreationLock;	//+0x0f0
	KSPIN_LOCK			HyperSpaceLock;			//+0x110
	PETHREAD			ForkInProgress;			//+0x114
	ULONG				HardwareTrigger;		//+0x118
	PVOID				VadRoot;				//+0x11c /*PMM_AVL_TABLE ??? A vérifier ! */
	PVOID				VadHint;				//+0x120
	PVOID				CloneRoot;				//+0x124
	ULONG				NumberOfPrivatePages;	//+0x128
	ULONG				NumberOfLockedPages;	//+0x12c
	PVOID				Win32Process;			//+0x130
	PEJOB				Job;					//+0x134
	PSECTION_OBJECT		SectionObject;			//+0x138 /*PVOID or not??? TO CHECK !!!*/
	PVOID				SectionBaseAddress;		//+0x13c
	PEPROCESS_QUOTA_BLOCK	QuotaBlock;			//+0x140
	PPAGEFAULT_HISTORY	WorkingSetWatch;		//+0x144
	PVOID				Win32WindowStation;		//+0x148
	PVOID				InheritedFromUniqueProcessId;//+0x14c
	PVOID				LdtInformation;			//+0x150
	PVOID				VadFreeHint;			//+0x154
	PVOID				VdmObjects;				//+0x158
	PDEVICE_MAP			DeviceMap;				//+0x15c /*PVOID or not ??? TO CHECK !!! */
	LIST_ENTRY			PhysicalVadList;		//+0x160
	union {
		HARDWARE_PTE_X86	PageDirectoryPte;	//+0x168
		ULONGLONG			Filler;				//+0x168
	};
	PVOID				Session;				//+0x170
	UCHAR				ImageFileName [16];		//+0x174
	LIST_ENTRY			JobLinks;				//+0x184
	PVOID				LockedPagesList;		//+0x18c
	LIST_ENTRY			ThreadListHead;			//+0x190
	PVOID				SecurityPort;			//+0x198
	PVOID				PaeTop;					//+0x19c
	ULONG				ActiveThreads;			//+0x1a0
	ACCESS_MASK			GrantedAccess;			//+0x1a4
	ULONG				DefaultHardErrorProcessing;	//+0x1a8
	NTSTATUS			LastThreadExitStatus;	//+0x1ac
	PPEB				Peb;					//+0x1b0
	EX_FAST_REF			PrefetchTrace;			//+0x1b4
	LARGE_INTEGER		ReadOperationCount;		//+0x1b8
	LARGE_INTEGER		WriteOperationCount;	//+0x1c0
	LARGE_INTEGER		OtherOperationCount;	//+0x1c8
	LARGE_INTEGER		ReadTransferCount;		//+0x1d0
	LARGE_INTEGER		WriteTransferCount;		//+0x1d8
	LARGE_INTEGER		OtherTransferCount;		//+0x1e0
	ULONG				CommitChargeLimit;		//+0x1e8
	ULONG				CommitChargePeak;		//+0x1ec
	PVOID				AweInfo;				//+0x1f0
	SE_AUDIT_PROCESS_CREATION_INFO	SeAuditProcessCreationInfo;//+0x1f4
	MMSUPPORT			Vm;						//+0x1f8
	ULONG				LastFaultCount;			//+0x238
	ULONG				ModifiedPageCount;		//+0x23c
	ULONG				NumberOfVads;			//+0x240
	ULONG				JobStatus;				//+0x244
	union {
		ULONG			Flags;					//+0x248
		struct {
			ULONG 	CreateReported : 1;			//0, +0x248
			ULONG 	NoDebugInherit : 1;			//1, +0x248
			ULONG 	ProcessExiting : 1;			//2, +0x248
			ULONG 	ProcessDelete : 1;			//3, +0x248
			ULONG 	Wow64SplitPages : 1;		//4, +0x248
			ULONG 	VmDeleted : 1;				//5, +0x248
			ULONG 	OutswapEnabled : 1;			//6, +0x248
			ULONG 	Outswapped : 1;				//7, +0x248
			ULONG 	ForkFailed : 1;				//8, +0x248
			ULONG 	HasPhysicalVad : 1;			//9, +0x248
			ULONG 	AddressSpaceInitialized : 2;//10, +0x248
			ULONG 	SetTimerResolution : 1;		//12, +0x248
			ULONG 	BreakOnTermination : 1;		//13, +0x248
			ULONG 	SessionCreationUnderway : 1;//14, +0x248
			ULONG 	WriteWatch : 1;				//15, +0x248
			ULONG 	ProcessInSession : 1;		//16, +0x248
			ULONG 	OverrideAddressSpace : 1;	//17, +0x248
			ULONG 	HasAddressSpace : 1;		//18, +0x248
			ULONG 	LaunchPrefetched : 1;		//19, +0x248
			ULONG 	InjectInpageErrors : 1;		//20, +0x248
			ULONG 	VmTopDown : 1;				//21, +0x248
			ULONG 	Unused3 : 1;				//22, +0x248
			ULONG 	Unused4 : 1;				//23, +0x248
			ULONG 	VdmAllowed : 1;				//24, +0x248
			ULONG 	Unused : 5;					//25, +0x248
			ULONG 	Unused1 : 1;				//30, +0x248
			ULONG 	Unused2 : 1;				//31, +0x248
		};		
	};
	NTSTATUS			ExitStatus;				//+0x24c
	USHORT				NextPageColor;			//+0x250
	union {
		struct {
			UCHAR	SubSystemMinorVersion;		//+0x252
			UCHAR	SubSystemMajorVersion;		//+0x253
		};
		USHORT		SubSystemVersion;			//+0x252
	};
	UCHAR				PriorityClass;			//+0x254
	UCHAR				WorkingSetAcquiredUnsafe;//+0x255
	ULONG				Cookie;					//+0x258
} EPROCESS, *PEPROCESS, **PPEPROCESS;

/*
#elif (_WIN32_WINNT == 0x502) && (WINVER == 0x502)

typedef struct _EPROCESS {
    KPROCESS                        Pcb;					// +0x000
    EX_PUSH_LOCK                    ProcessLock;			// +0x06c
    LARGE_INTEGER                   CreateTime;				// +0x070
    LARGE_INTEGER                   ExitTime;				// +0x078
    EX_RUNDOWN_REF                  RundownProtect;			// +0x080
    ULONG                           UniqueProcessId;		// +0x084
    LIST_ENTRY                      ActiveProcessLinks;		// +0x088
    ULONG                           QuotaUsage[3];			// +0x090
    ULONG                           QuotaPeak[3];			// +0x09c
    ULONG                           CommitCharge;			// +0x0a8
    ULONG                           PeakVirtualSize;		// +0x0ac
    ULONG                           VirtualSize;			// +0x0b0
    LIST_ENTRY                      SessionProcessLinks;	// +0x0b4
    PVOID                           DebugPort;				// +0x0bc
    PVOID                           ExceptionPort;			// +0x0c0
    PHANDLE_TABLE                   ObjectTable;			// +0x0c4
    EX_FAST_REF                     Token;					// +0x0c8
    ULONG                           WorkingSetPage;			// +0x0cc
    KGUARDED_MUTEX                  AddressCreationLock;	// +0x0d0
    ULONG                           HyperSpaceLock;			// +0x0f0
    PETHREAD                        ForkInProgress;			// +0x0f4
    ULONG                           HardwareTrigger;		// +0x0f8
    PMM_AVL_TABLE                   PhysicalVadRoot;		// +0x0fc
    PVOID                           CloneRoot;				// +0x100
    ULONG                           NumberOfPrivatePages;	// +0x104
    ULONG                           NumberOfLockedPages;	// +0x108
    PVOID                           Win32Process;			// +0x10c
    PEJOB                           Job;					// +0x110
    PVOID                           SectionObject;			// +0x114
    PVOID                           SectionBaseAddress;		// +0x118
    PEPROCESS_QUOTA_BLOCK           QuotaBlock;				// +0x11c
    PPAGEFAULT_HISTORY              WorkingSetWatch;		// +0x120
    PVOID                           Win32WindowStation;		// +0x124
    ULONG                           InheritedFromUniqueProcessId;// +0x128
    PVOID                           LdtInformation;			// +0x12c
    PVOID                           VadFreeHint;			// +0x130
    PVOID                           VdmObjects;				// +0x134
    PVOID                           DeviceMap;				// +0x138
    PVOID                           Spare0[3];				// +0x13c
    union {
        HARDWARE_PTE                PageDirectoryPte;		// +0x148
        UINT64                      Filler;					// +0x148
    };
    PVOID                           Session;				// +0x150
    UCHAR                           ImageFileName[16];		// +0x154
    LIST_ENTRY                      JobLinks;				// +0x164
    PVOID                           LockedPagesList;		// +0x16c
    LIST_ENTRY                      ThreadListHead;			// +0x170
    PVOID                           SecurityPort;			// +0x178
    PVOID                           PaeTop;					// +0x17c
    ULONG                           ActiveThreads;			// +0x180
    ULONG                           GrantedAccess;			// +0x184
    ULONG                           DefaultHardErrorProcessing;// +0x188
    SHORT                           LastThreadExitStatus;	// +0x18c
    PPEB                            Peb;					// +0x190
    EX_FAST_REF                     PrefetchTrace;			// +0x194
    LARGE_INTEGER                   ReadOperationCount;		// +0x198
    LARGE_INTEGER                   WriteOperationCount;	// +0x1a0
    LARGE_INTEGER                   OtherOperationCount;	// +0x1a8
    LARGE_INTEGER                   ReadTransferCount;		// +0x1b0
    LARGE_INTEGER                   WriteTransferCount;		// +0x1b8
    LARGE_INTEGER                   OtherTransferCount;		// +0x1c0
    ULONG                           CommitChargeLimit;		// +0x1c8
    ULONG                           CommitChargePeak;		// +0x1cc
    PVOID                           AweInfo;				// +0x1d0
    SE_AUDIT_PROCESS_CREATION_INFO  SeAuditProcessCreationInfo;// +0x1d4
    MMSUPPORT                       Vm;						// +0x1d8
    LIST_ENTRY                      MmProcessLinks;			// +0x238
    ULONG                           ModifiedPageCount;		// +0x240
    ULONG                           JobStatus;				// +0x244
    union {
        ULONG                       Flags;					// 0x248
        struct {
            ULONG                   CreateReported              : 1;
            ULONG                   NoDebugInherit              : 1;
            ULONG                   ProcessExiting              : 1;
            ULONG                   ProcessDelete               : 1;
            ULONG                   Wow64SplitPages             : 1;
            ULONG                   VmDeleted                   : 1;
            ULONG                   OutswapEnabled              : 1;
            ULONG                   Outswapped                  : 1;
            ULONG                   ForkFailed                  : 1;
            ULONG                   Wow64VaSpace4Gb             : 1;
            ULONG                   AddressSpaceInitialized     : 2;
            ULONG                   SetTimerResolution          : 1;
            ULONG                   BreakOnTermination          : 1;
            ULONG                   SessionCreationUnderway     : 1;
            ULONG                   WriteWatch                  : 1;
            ULONG                   ProcessInSession            : 1;
            ULONG                   OverrideAddressSpace        : 1;
            ULONG                   HasAddressSpace             : 1;
            ULONG                   LaunchPrefetched            : 1;
            ULONG                   InjectInpageErrors          : 1;
            ULONG                   VmTopDown                   : 1;
            ULONG                   ImageNotifyDone             : 1;
            ULONG                   PdeUpdateNeeded             : 1;
            ULONG                   VdmAllowed                  : 1;
            ULONG                   Unused                      : 7;
        };
    };
    NTSTATUS                        ExitStatus;				// +0x24c
    USHORT                          NextPageColor;			// +0x250
    union {
        struct {
            UCHAR                   SubSystemMinorVersion;	// +0x252
            UCHAR                   SubSystemMajorVersion;	// +0x253
        };
        USHORT                      SubSystemVersion;		// +0x252
    };
    UCHAR                           PriorityClass;			// +0x254
    MM_AVL_TABLE                    VadRoot;				// +0x258
} EPROCESS, *PEPROCESS; // 0x278 in total

#else
#error Wrong Define !

#endif
*/
#endif //_INCLUDED
#endif//_H_INCLUDED
