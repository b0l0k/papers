/* 
 Copyright (c) FRET.  All rights reserved.

File Name : TEB.h

Abstract:
Thread Environment Block structure

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 23-Aug-2006 
*/

#ifndef _TEB_H_INCLUDED
#define _TEB_H_INCLUDED

#include "NT_TIB.h"
#include "CLIENT_ID.h"
#include "PEB.h"
#include "ACTIVATION_CONTEXT_STACK.h"
#include "GDI_TEB_BATCH.h"
#include "UNICODE_STRING.h"
#include "LIST_ENTRY.h"
#include "Wx86ThreadState.h"
#include "TEB_ACTIVE_FRAME.h"

#ifndef TEB_INCLUDED
#define TEB_INCLUDED

typedef struct _TEB
{
	NT_TIB			NtTib;						//+0x000
	PVOID			EnvironmentPointer;			//+0x01c
	CLIENT_ID		ClientId;					//+0x020
	PVOID			ActiveRpcHandle;			//+0x028
	PVOID			ThreadLocalStoragePointer;	//+0x02c
	PPEB			ProcessEnvironmentBlock;	//+0x030
	ULONG			LastErrorValue;				//+0x034
	ULONG			CountOfOwnedCriticalSections;//+0x038
	PVOID			CsrClientThread;			//+0x03c
	PVOID			Win32ThreadInfo;			//+0x040 // _W32THREAD * ???
	ULONG			User32Reserved [26];		//+0x044
	ULONG			UserReserved [5];			//+0x0ac
	PVOID			WOW32Reserved;				//+0x0c0
	LCID			CurrentLocale;				//+0x0c4
	ULONG			FpSoftwareStatusRegister;	//+0x0c8
	PVOID			SystemReserved1 [54];		//+0x0cc
	LONG			ExceptionCode;				//+0x1a4
	ACTIVATION_CONTEXT_STACK	ActivationContextStack;//+0x1a8
	UCHAR			SpareBytes1 [24];			//+0x1bc
	GDI_TEB_BATCH	GdiTebBatch;				//+0x1d4
	CLIENT_ID		RealClientId;				//+0x6b4
	PVOID			GdiCachedProcessHandle;		//+0x6bc
	ULONG			GdiClientPID;				//+0x6c0
	ULONG			GdiClientTID;				//+0x6c4
	PVOID			GdiThreadLocalInfo;			//+0x6c8
	ULONG			Win32ClientInfo [62];		//+0x6cc
	PVOID			glDispatchTable [233];		//+0x7c4
	ULONG			glReserved1 [29];			//+0xb68
	PVOID			glReserved2;				//+0xbdc
	PVOID			glSectionInfo;				//+0xbe0
	PVOID			glSection;					//+0xbe4
	PVOID			glTable;					//+0xbe8
	PVOID			glCurrentRC;				//+0xbec
	PVOID			glContext;					//+0xbf0
	NTSTATUS		LastStatusValue;			//+0xbf4
	UNICODE_STRING	StaticUnicodeString;		//+0xbf8
	WCHAR			StaticUnicodeBuffer [261];	//+0xc00
	PVOID			DeallocationStack;			//+0xe0c
	PVOID			TlsSlots [64];				//+0xe10
	LIST_ENTRY		TlsLinks;					//+0xf10
	PVOID			Vdm;						//+0xf18
	PVOID			ReservedForNtRpc;			//+0xf1c
	PVOID			DbgSsReserved [2];			//+0xf20
	ULONG			HardErrorsAreDisabled;		//+0xf28
	PVOID			Instrumentation [16];		//+0xf2c
	PVOID			WinSockData;				//+0xf6c
	ULONG			GdiBatchCount;				//+0xf70
	BOOLEAN			InDbgPrint;					//+0xf74
	BOOLEAN			FreeStackOnTermination;		//+0xf75
	BOOLEAN			HasFiberData;				//+0xf76
	UCHAR			IdealProcessor;				//+0xf77
	ULONG			Spare3;						//+0xf78
	PVOID			ReservedForPerf;			//+0xf7c
	PVOID			ReservedForOle;				//+0xf80
	ULONG			WaitingOnLoaderLock;		//+0xf84
	Wx86ThreadState	Wx86Thread;					//+0xf88
	PVOID*			TlsExpansionSlots;			//+0xf94
	ULONG			ImpersonationLocale;		//+0xf98
	ULONG			IsImpersonating;			//+0xf9c
	PVOID			NlsCache;					//+0xfa0
	PVOID			pShimData;					//+0xfa4
	ULONG			HeapVirtualAffinity;		//+0xfa8
	PVOID			CurrentTransactionHandle;	//+0xfac
	PTEB_ACTIVE_FRAME	ActiveFrame;			//+0xfb0
	UCHAR			SafeThunkCall;				//+0xfb4
	UCHAR			BooleanSpare [3];			//+0xfb5
} TEB, *PTEB, **PPTEB;

#endif //_INCLUDED
#endif//_H_INCLUDED
