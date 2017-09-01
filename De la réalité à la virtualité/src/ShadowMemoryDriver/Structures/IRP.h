/* 
Copyright (c) FRET.  All rights reserved.

File Name : IRP.h

Abstract:
Input Request Packet structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _IRP_H_INCLUDED
#define _IRP_H_INCLUDED

#include "MDL.h"
#include "LIST_ENTRY.h"
#include "IO_STATUS_BLOCK.h"
#include "KEVENT.h"

#ifndef IRP_INCLUDED
#define IRP_INCLUDED
#ifndef _NTDDK_

// <size 0x70>
typedef struct _IRP
{
	CSHORT	Type;		//+0x000
	USHORT	Size;		//+0x002
	PMDL	MdlAddress;		//+0x004
	ULONG	Flags;		//+0x008
	union {
		struct _IRP *MasterIrp;
		LONG IrpCount;
		PVOID SystemBuffer;
	} AssociatedIrp;		//+0x00c
	LIST_ENTRY	ThreadListEntry;		//+0x010
	IO_STATUS_BLOCK	IoStatus;		//+0x018
	CHAR	RequestorMode;		//+0x020
	UCHAR	PendingReturned;		//+0x021
	CHAR	StackCount;		//+0x022
	CHAR	CurrentLocation;		//+0x023
	UCHAR	Cancel;		//+0x024
	UCHAR	CancelIrql;		//+0x025
	CHAR	ApcEnvironment;		//+0x026
	UCHAR	AllocationFlags;		//+0x027
	PIO_STATUS_BLOCK	UserIosb;		//+0x028
    PKEVENT UserEvent;		//+0x02c
    union {
        struct {
            PIO_APC_ROUTINE UserApcRoutine;
            PVOID UserApcContext;
        } AsynchronousParameters;
        LARGE_INTEGER AllocationSize;
    } Overlay;		//+0x030
    PDRIVER_CANCEL CancelRoutine;		//+0x038
    PVOID UserBuffer;		//+0x03c
    union {
        struct {
            union {
				KDEVICE_QUEUE_ENTRY DeviceQueueEntry;
                struct {
                    PVOID DriverContext[4];
                } ;
            } ;
            PETHREAD Thread;
			PCHAR AuxiliaryBuffer;
            struct {
                LIST_ENTRY ListEntry;
                union {
                    struct _IO_STACK_LOCATION *CurrentStackLocation;
					ULONG PacketType;
				};
            };
			PFILE_OBJECT OriginalFileObject;
        } Overlay;
        KAPC Apc;
        PVOID CompletionKey;
    } Tail;		//+0x040
} IRP, *PIRP, **PPIRP;

#endif //_NTDKK_
#endif //_INCLUDED
#endif //_H_INCLUDED
