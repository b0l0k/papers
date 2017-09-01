/* 
Copyright (c) FRET.  All rights reserved.

File Name : DRIVER_OBJECT.h

Abstract:
 Driver Object structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 26-Aug-2006 
*/

#ifndef _DRIVER_OBJECT_H_INCLUDED
#define _DRIVER_OBJECT_H_INCLUDED

#include "DEVICE_OBJECT.h"
#include "DRIVER_EXTENSION.h"
#include "UNICODE_STRING.h"
#include "FAST_IO_DISPATCH.h"
#include "IRP.h" //for PDRIVER_DISPATCH

#ifndef DRIVER_OBJECT_INCLUDED
#define DRIVER_OBJECT_INCLUDED
#ifndef _NTDDK_

// [All defines from DDK]
// Define the major function codes for IRPs.
//
#define IRP_MJ_CREATE                   0x00
#define IRP_MJ_CREATE_NAMED_PIPE        0x01
#define IRP_MJ_CLOSE                    0x02
#define IRP_MJ_READ                     0x03
#define IRP_MJ_WRITE                    0x04
#define IRP_MJ_QUERY_INFORMATION        0x05
#define IRP_MJ_SET_INFORMATION          0x06
#define IRP_MJ_QUERY_EA                 0x07
#define IRP_MJ_SET_EA                   0x08
#define IRP_MJ_FLUSH_BUFFERS            0x09
#define IRP_MJ_QUERY_VOLUME_INFORMATION 0x0a
#define IRP_MJ_SET_VOLUME_INFORMATION   0x0b
#define IRP_MJ_DIRECTORY_CONTROL        0x0c
#define IRP_MJ_FILE_SYSTEM_CONTROL      0x0d
#define IRP_MJ_DEVICE_CONTROL           0x0e
#define IRP_MJ_INTERNAL_DEVICE_CONTROL  0x0f
#define IRP_MJ_SHUTDOWN                 0x10
#define IRP_MJ_LOCK_CONTROL             0x11
#define IRP_MJ_CLEANUP                  0x12
#define IRP_MJ_CREATE_MAILSLOT          0x13
#define IRP_MJ_QUERY_SECURITY           0x14
#define IRP_MJ_SET_SECURITY             0x15
#define IRP_MJ_POWER                    0x16
#define IRP_MJ_SYSTEM_CONTROL           0x17
#define IRP_MJ_DEVICE_CHANGE            0x18
#define IRP_MJ_QUERY_QUOTA              0x19
#define IRP_MJ_SET_QUOTA                0x1a
#define IRP_MJ_PNP                      0x1b
#define IRP_MJ_PNP_POWER                IRP_MJ_PNP      // Obsolete....
#define IRP_MJ_MAXIMUM_FUNCTION         0x1b

//[from DDK]
// Define driver dispatch routine type.
//
typedef
NTSTATUS
(*PDRIVER_DISPATCH) (
    struct _DEVICE_OBJECT *DeviceObject,
    struct _IRP *Irp
    );
	
typedef struct  _DRIVER_OBJECT
{
	SHORT				Type;				//+0x000
	SHORT				Size;				//+0x002
	PDEVICE_OBJECT		DeviceObject;		//+0x004
	ULONG				Flags;				//+0x008
	PVOID				DriverStart;		//+0x00c
	ULONG				DriverSize;			//+0x010
	PVOID				DriverSection;		//+0x014
	PDRIVER_EXTENSION	DriverExtension;	//+0x018
	UNICODE_STRING		DriverName;			//+0x01c
	PUNICODE_STRING		HardwareDatabase;	//+0x024
	PFAST_IO_DISPATCH	FastIoDispatch;		//+0x028
	PVOID				DriverInit;			//+0x02c
	PVOID				DriverStartIo;		//+0x030
	PVOID				DriverUnload;		//+0x034
	PDRIVER_DISPATCH	MajorFunction[IRP_MJ_MAXIMUM_FUNCTION + 1];		//+0x038
} DRIVER_OBJECT, *PDRIVER_OBJECT, **PPDRIVER_OBJECT;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
