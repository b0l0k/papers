/* 
 Copyright (c) FRET.  All rights reserved.

File Name : PEB.h

Abstract:
Process Environment Block structure

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 05
Last Update : 3-Sep-2006 
*/

#ifndef _PEB_H_INCLUDED
#define _PEB_H_INCLUDED

#include "PEB_LDR_DATA.h"
#include "RTL_USER_PROCESS_PARAMETERS.h"
#include "RTL_CRITICAL_SECTION.h"
#include "PEB_FREE_BLOCK.h"
#include "LARGE_INTEGER.h"
#include "ULARGE_INTEGER.h"
#include "UNICODE_STRING.h"

#ifndef PEB_INCLUDED
#define PEB_INCLUDED

typedef VOID(NTAPI * PPEBLOCKROUTINE)(PVOID PebLock);

typedef struct _PEB
{
	UCHAR		InheritedAddressSpace;				//+0x000
	UCHAR		ReadImageFileExecOptions;			//+0x001
	UCHAR		BeingDebugged;						//+0x002
	UCHAR		SpareBool;							//+0x003
	PVOID		Mutant;								//+0x004
	PVOID		ImageBaseAddress;					//+0x008
	PPEB_LDR_DATA	Ldr;							//+0x00c
	PRTL_USER_PROCESS_PARAMETERS	ProcessParameters;//+0x010
	PVOID		SubSystemData;						//+0x014
	PVOID		ProcessHeap;						//+0x018
	PRTL_CRITICAL_SECTION	FastPebLock;			//+0x01c
	PPEBLOCKROUTINE		FastPebLockRoutine;			//+0x020
	PPEBLOCKROUTINE		FastPebUnlockRoutine;		//+0x024
	ULONG		EnvironmentUpdateCount;				//+0x028
	PVOID		KernelCallbackTable;				//+0x02c
	ULONG		SystemReserved [1];					//+0x030
	ULONG		AtlThunkSListPtr32;					//+0x034
	PPEB_FREE_BLOCK	FreeList;						//+0x038
	ULONG		TlsExpansionCounter;				//+0x03c
	PVOID		TlsBitmap;							//+0x040
	ULONG		TlsBitmapBits [2];					//+0x044
	PVOID		ReadOnlySharedMemoryBase;			//+0x04c
	PVOID		ReadOnlySharedMemoryHeap;			//+0x050
	PVOID*		ReadOnlyStaticServerData;			//+0x054
	PVOID		AnsiCodePageData;					//+0x058
	PVOID		OemCodePageData;					//+0x05c
	PVOID		UnicodeCaseTableData;				//+0x060
	ULONG		NumberOfProcessors;					//+0x064
	ULONG		NtGlobalFlag;						//+0x068
	LARGE_INTEGER	CriticalSectionTimeout;			//+0x070
	ULONG		HeapSegmentReserve;					//+0x078
	ULONG		HeapSegmentCommit;					//+0x07c
	ULONG		HeapDeCommitTotalFreeThreshold;		//+0x080
	ULONG		HeapDeCommitFreeBlockThreshold;		//+0x084
	ULONG		NumberOfHeaps;						//+0x088
	ULONG		MaximumNumberOfHeaps;				//+0x08c
	PVOID*		ProcessHeaps;						//+0x090
	PVOID		GdiSharedHandleTable;				//+0x094
	PVOID		ProcessStarterHelper;				//+0x098
	ULONG		GdiDCAttributeList;					//+0x09c
	PVOID		LoaderLock;							//+0x0a0
	ULONG		OSMajorVersion;						//+0x0a4
	ULONG		OSMinorVersion;						//+0x0a8
	USHORT		OSBuildNumber;						//+0x0ac
	USHORT		OSCSDVersion;						//+0x0ae
	ULONG		OSPlatformId;						//+0x0b0
	ULONG		ImageSubsystem;						//+0x0b4
	ULONG		ImageSubsystemMajorVersion;			//+0x0b8
	ULONG		ImageSubsystemMinorVersion;			//+0x0bc
	ULONG		ImageProcessAffinityMask;			//+0x0c0
	ULONG		GdiHandleBuffer [34];				//+0x0c4
	PVOID		PostProcessInitRoutine;				//+0x14c // PPOST_PROCESS_INIT_ROUTINE ??
	PVOID		TlsExpansionBitmap;					//+0x150 // PRTL_BITMAP ??
	ULONG		TlsExpansionBitmapBits [32];		//+0x154
	ULONG		SessionId;							//+0x1d4
	ULARGE_INTEGER	AppCompatFlags;					//+0x1d8
	ULARGE_INTEGER	AppCompatFlagsUser;				//+0x1e0
	PVOID		pShimData;							//+0x1e8
	PVOID		AppCompatInfo;						//+0x1ec
	UNICODE_STRING	CSDVersion;						//+0x1f0
	PVOID		ActivationContextData;				//+0x1f8
	PVOID		ProcessAssemblyStorageMap;			//+0x1fc
	PVOID		SystemDefaultActivationContextData;	//+0x200
	PVOID		SystemAssemblyStorageMap;			//+0x204
	ULONG		MinimumStackCommit;					//+0x208
} PEB, *PPEB, **PPPEB;

#endif //_INCLUDED
#endif//_H_INCLUDED
