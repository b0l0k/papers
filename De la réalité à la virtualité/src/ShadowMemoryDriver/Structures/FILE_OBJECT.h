/* 
Copyright (c) FRET.  All rights reserved.

File Name : FILE_OBJECT.h

Abstract:
File Object structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _FILE_OBJECT_H_INCLUDED
#define _FILE_OBJECT_H_INCLUDED

#include "DEVICE_OBJECT.h"
#include "VPB.h"
#include "SECTION_OBJECT_POINTERS.h"
#include "UNICODE_STRING.h"
#include "LARGE_INTEGER.h"
#include "KEVENT.h"
#include "IO_COMPLETION_CONTEXT.h"

#ifndef FILE_OBJECT_INCLUDED
#define FILE_OBJECT_INCLUDED
#ifndef _NTDDK_

//
// Define File Object (FO) flags
//
#define FO_FILE_OPEN                    0x00000001
#define FO_SYNCHRONOUS_IO               0x00000002
#define FO_ALERTABLE_IO                 0x00000004
#define FO_NO_INTERMEDIATE_BUFFERING    0x00000008
#define FO_WRITE_THROUGH                0x00000010
#define FO_SEQUENTIAL_ONLY              0x00000020
#define FO_CACHE_SUPPORTED              0x00000040
#define FO_NAMED_PIPE                   0x00000080
#define FO_STREAM_FILE                  0x00000100
#define FO_MAILSLOT                     0x00000200
#define FO_GENERATE_AUDIT_ON_CLOSE      0x00000400
#define FO_DIRECT_DEVICE_OPEN           0x00000800
#define FO_FILE_MODIFIED                0x00001000
#define FO_FILE_SIZE_CHANGED            0x00002000
#define FO_CLEANUP_COMPLETE             0x00004000
#define FO_TEMPORARY_FILE               0x00008000
#define FO_DELETE_ON_CLOSE              0x00010000
#define FO_OPENED_CASE_SENSITIVE        0x00020000
#define FO_HANDLE_CREATED               0x00040000
#define FO_FILE_FAST_IO_READ            0x00080000
#define FO_RANDOM_ACCESS                0x00100000
#define FO_FILE_OPEN_CANCELLED          0x00200000
#define FO_VOLUME_OPEN                  0x00400000
#define FO_FILE_OBJECT_HAS_EXTENSION    0x00800000
#define FO_REMOTE_ORIGIN                0x01000000

typedef struct _FILE_OBJECT
{
	CSHORT					Type;				//+0x000
	CSHORT					Size;				//+0x002
	PDEVICE_OBJECT			DeviceObject;		//+0x004
	PVPB					Vpb;				//+0x008
	PVOID					FsContext;			//+0x00c
	PVOID					FsContext2;			//+0x010
	PSECTION_OBJECT_POINTERS	SectionObjectPointer;//+0x014
	PVOID					PrivateCacheMap;	//+0x018
	NTSTATUS				FinalStatus;		//+0x01c
	PFILE_OBJECT			RelatedFileObject;	//+0x020
	BOOLEAN					LockOperation;		//+0x024
	BOOLEAN					DeletePending;		//+0x025
	BOOLEAN					ReadAccess;			//+0x026
	BOOLEAN					WriteAccess;		//+0x027
	BOOLEAN					DeleteAccess;		//+0x028
	BOOLEAN					SharedRead;			//+0x029
	BOOLEAN					SharedWrite;		//+0x02a
	BOOLEAN					SharedDelete;		//+0x02b
	ULONG					Flags;				//+0x02c
	UNICODE_STRING			FileName;			//+0x030
	LARGE_INTEGER			CurrentByteOffset;	//+0x038
	ULONG					Waiters;			//+0x040
	ULONG					Busy;				//+0x044
	PVOID					LastLock;			//+0x048
	KEVENT					Lock;				//+0x04c
	KEVENT					Event;				//+0x05c
	PIO_COMPLETION_CONTEXT	CompletionContext;	//+0x06c
} FILE_OBJECT, *PFILE_OBJECT, **PPFILE_OBJECT;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
