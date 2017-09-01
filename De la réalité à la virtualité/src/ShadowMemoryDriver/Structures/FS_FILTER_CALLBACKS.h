/* 
Copyright (c) FRET.  All rights reserved.

File Name : FS_FILTER_CALLBACKS.h

Abstract:
FS Filter Callbacks structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 05
Last Update : 2-Sep-2006 
*/

//<documentation : see FsRtlRegisterFileSystemFilterCallbacks in DDK (IFS kit)>
#ifndef _FS_FILTER_CALLBACKS_H_INCLUDED
#define _FS_FILTER_CALLBACKS_H_INCLUDED

#include "FS_FILTER_CALLBACK_DATA.h"

#ifndef FS_FILTER_CALLBACKS_INCLUDED
#define FS_FILTER_CALLBACKS_INCLUDED

typedef NTSTATUS
(NTAPI *PFS_FILTER_CALLBACK) (
	IN PFS_FILTER_CALLBACK_DATA	Data,
	OUT PVOID					*CompletionContext //void**
);
 
typedef VOID
(NTAPI *PFS_FILTER_COMPLETION_CALLBACK) (
	IN PFS_FILTER_CALLBACK_DATA	Data,
	IN NTSTATUS					OperationStatus,
	IN PVOID					CompletionContext
);
typedef struct _FS_FILTER_CALLBACKS
{
	ULONG							SizeOfFsFilterCallbacks;				//+0x000
	ULONG							Reserved;								//+0x004
	PFS_FILTER_CALLBACK				PreAcquireForSectionSynchronization;	//+0x008
	PFS_FILTER_COMPLETION_CALLBACK	PostAcquireForSectionSynchronization;	//+0x00c
	PFS_FILTER_CALLBACK				PreReleaseForSectionSynchronization;	//+0x010
	PFS_FILTER_COMPLETION_CALLBACK	PostReleaseForSectionSynchronization;	//+0x014
	PFS_FILTER_CALLBACK				PreAcquireForCcFlush;					//+0x018
	PFS_FILTER_COMPLETION_CALLBACK	PostAcquireForCcFlush;					//+0x01c
	PFS_FILTER_CALLBACK				PreReleaseForCcFlush;					//+0x020
	PFS_FILTER_COMPLETION_CALLBACK	PostReleaseForCcFlush;					//+0x024
	PFS_FILTER_CALLBACK				PreAcquireForModifiedPageWriter;		//+0x028
	PFS_FILTER_COMPLETION_CALLBACK	PostAcquireForModifiedPageWriter;		//+0x02c
	PFS_FILTER_CALLBACK				PreReleaseForModifiedPageWriter;		//+0x030
	PFS_FILTER_COMPLETION_CALLBACK	PostReleaseForModifiedPageWriter;		//+0x034
} FS_FILTER_CALLBACKS, *PFS_FILTER_CALLBACKS, **PPFS_FILTER_CALLBACKS;

#endif //_INCLUDED
#endif//_H_INCLUDED
