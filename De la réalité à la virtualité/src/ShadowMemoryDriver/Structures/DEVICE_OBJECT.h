/* 
Copyright (c) FRET.  All rights reserved.

File Name : DEVICE_OBJECT.h

Abstract:
 DEVICE OBJECT structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _DEVICE_OBJECT_H_INCLUDED
#define _DEVICE_OBJECT_H_INCLUDED

#include "DRIVER_OBJECT.h"
#include "IRP.h"
#include "IO_TIMER.h"
#include "VPB.h"
#include "KDEVICE_QUEUE.h"
#include "KDPC.h"
#include "KEVENT.h"
#include "DEVOBJ_EXTENSION.h"

#ifndef DEVICE_OBJECT_INCLUDED
#define DEVICE_OBJECT_INCLUDED
#ifndef _NTDDK_

typedef struct _DEVICE_OBJECT
{
	SHORT			Type;					//+0x000
	USHORT			Size;					//+0x002
	LONG			ReferenceCount;			//+0x004
	PDRIVER_OBJECT	DriverObject;			//+0x008
	struct _DEVICE_OBJECT *	NextDevice;		//+0x00c
	struct _DEVICE_OBJECT *	AttachedDevice;	//+0x010
	PIRP			CurrentIrp;				//+0x014
	PIO_TIMER		Timer;					//+0x018
	ULONG			Flags;					//+0x01c
	ULONG			Characteristics;		//+0x020
	PVPB			Vpb;					//+0x024
	PVOID			DeviceExtension;		//+0x028
	ULONG			DeviceType;				//+0x02c
	CHAR			StackSize;				//+0x030
	union {
		LIST_ENTRY  ListEntry;
		WAIT_CONTEXT_BLOCK  Wcb;
	} Queue;								//+0x034
	ULONG			AlignmentRequirement;	//+0x05c
	KDEVICE_QUEUE	DeviceQueue;			//+0x060
	KDPC			Dpc;					//+0x074
	ULONG			ActiveThreadCount;		//+0x094
	PVOID			SecurityDescriptor;		//+0x098
	KEVENT			DeviceLock;				//+0x09c
	USHORT			SectorSize;				//+0x0ac
	USHORT			Spare1;					//+0x0ae
	PDEVOBJ_EXTENSION	DeviceObjectExtension;		//+0x0b0
	PVOID			Reserved;				//+0x0b4
} DEVICE_OBJECT, *PDEVICE_OBJECT, **PPDEVICE_OBJECT;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
