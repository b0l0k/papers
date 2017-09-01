/* 
Copyright (c) FRET.  All rights reserved.

File Name : FAST_IO_DISPATCH.h

Abstract:
Fast Input/Ouput Dispatch structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _FAST_IO_DISPATCH_H_INCLUDED
#define _FAST_IO_DISPATCH_H_INCLUDED

#ifndef FAST_IO_DISPATCH_INCLUDED
#define FAST_IO_DISPATCH_INCLUDED
#ifndef _NTDDK_

//needed types
#error NTDDK.h must be included, some types are not yet implemented.

typedef struct _FAST_IO_DISPATCH
{
	ULONG	SizeOfFastIoDispatch;		//+0x000
	PVOID	FastIoCheckIfPossible;		//+0x004
	PVOID	FastIoRead;					//+0x008
	PVOID	FastIoWrite;				//+0x00c
	PVOID	FastIoQueryBasicInfo;		//+0x010
	PVOID	FastIoQueryStandardInfo;	//+0x014
	PVOID	FastIoLock;					//+0x018
	PVOID	FastIoUnlockSingle;			//+0x01c
	PVOID	FastIoUnlockAll;			//+0x020
	PVOID	FastIoUnlockAllByKey;		//+0x024
	PVOID	FastIoDeviceControl;		//+0x028
	PVOID	AcquireFileForNtCreateSection;	//+0x02c
	PVOID	ReleaseFileForNtCreateSection;	//+0x030
	PVOID	FastIoDetachDevice;			//+0x034
	PVOID	FastIoQueryNetworkOpenInfo;	//+0x038
	PVOID	AcquireForModWrite;			//+0x03c
	PVOID	MdlRead;					//+0x040
	PVOID	MdlReadComplete;			//+0x044
	PVOID	PrepareMdlWrite;			//+0x048
	PVOID	MdlWriteComplete;			//+0x04c
	PVOID	FastIoReadCompressed;		//+0x050
	PVOID	FastIoWriteCompressed;		//+0x054
	PVOID	MdlReadCompleteCompressed;	//+0x058
	PVOID	MdlWriteCompleteCompressed;	//+0x05c
	PVOID	FastIoQueryOpen;			//+0x060
	PVOID	ReleaseForModWrite;			//+0x064
	PVOID	AcquireForCcFlush;			//+0x068
	PVOID	ReleaseForCcFlush;			//+0x06c
} FAST_IO_DISPATCH, *PFAST_IO_DISPATCH, **PPFAST_IO_DISPATCH;

#endif // _NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
