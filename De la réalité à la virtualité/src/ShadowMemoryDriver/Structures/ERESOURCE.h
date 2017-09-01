/* 
Copyright (c) FRET.  All rights reserved.

File Name : ERESOURCE.h

Abstract:
Executive Resource structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _ERESOURCE_H_INCLUDED
#define _ERESOURCE_H_INCLUDED

#include "LIST_ENTRY.h"
#include "OWNER_ENTRY.h"
#include "KSEMAPHORE.h"
#include "KEVENT.h"

#ifndef ERESOURCE_INCLUDED
#define ERESOURCE_INCLUDED
#ifndef _NTDDK_

//ERESOURCE Flags 
#define ResourceNeverExclusive            0x0010
#define ResourceReleaseByOtherThread      0x0020
#define ResourceOwnedExclusive            0x0080

#define RESOURCE_HASH_TABLE_SIZE          64

typedef struct _ERESOURCE
{
	LIST_ENTRY		SystemResourcesList;		//+0x000
	POWNER_ENTRY	OwnerTable;					//+0x008
	SHORT			ActiveCount;				//+0x00c
	USHORT			Flag;						//+0x00e
	PKSEMAPHORE		SharedWaiters;				//+0x010
	PKEVENT			ExclusiveWaiters;			//+0x014
	OWNER_ENTRY		OwnerThreads [2];			//+0x018
	ULONG			ContentionCount;			//+0x028
	USHORT			NumberOfSharedWaiters;		//+0x02c
	USHORT			NumberOfExclusiveWaiters;	//+0x02e
	union {
		PVOID		Address;					//+0x030
		ULONG_PTR	CreatorBackTraceIndex;		//+0x030
	};
	KSPIN_LOCK		SpinLock;					//+0x034
} ERESOURCE, *PERESOURCE, **PPERESOURCE;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
