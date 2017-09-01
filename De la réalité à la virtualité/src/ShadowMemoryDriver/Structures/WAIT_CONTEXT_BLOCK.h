#ifndef _WAIT_CONTEXT_BLOCK_H_INCLUDED
#define _WAIT_CONTEXT_BLOCK_H_INCLUDED

#include "DEVICE_OBJECT.h"
#include "IRP.h"
#include "KDEVICE_QUEUE_ENTRY.h"
#include "KDPC.h"

#ifndef WAIT_CONTEXT_BLOCK_INCLUDED
#define WAIT_CONTEXT_BLOCK_INCLUDED
#ifndef _NTDDK_

// [from DDK]
// Define the actions that a driver execution routine may request of the
// adapter/controller allocation routines upon return.
//
typedef enum _IO_ALLOCATION_ACTION {
    KeepObject = 1,
    DeallocateObject,
    DeallocateObjectKeepRegisters
} IO_ALLOCATION_ACTION, *PIO_ALLOCATION_ACTION;

// [from DDK]
// Define device driver adapter/controller execution routine.
//
typedef
IO_ALLOCATION_ACTION
(*PDRIVER_CONTROL) (
    struct _DEVICE_OBJECT *DeviceObject,
    struct _IRP *Irp,
    PVOID MapRegisterBase,
    PVOID Context
    );

typedef struct _WAIT_CONTEXT_BLOCK
{
	KDEVICE_QUEUE_ENTRY  WaitQueueEntry;
	PDRIVER_CONTROL  DeviceRoutine;
	PVOID  DeviceContext;
	ULONG  NumberOfMapRegisters;
	PVOID  DeviceObject;
	PVOID  CurrentIrp;
	PKDPC  BufferChainingDpc;
} WAIT_CONTEXT_BLOCK, *PWAIT_CONTEXT_BLOCK, **PPWAIT_CONTEXT_BLOCK;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED