/* 
Copyright (c) FRET.  All rights reserved.

File Name : VPB.h

Abstract:
Volume Parameter Block structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 05
Last Update : 3-Sep-2006 
*/

#ifndef _VPB_H_INCLUDED
#define _VPB_H_INCLUDED

#include "DEVICE_OBJECT.h"


#ifndef VPB_INCLUDED
#define VPB_INCLUDED
#ifndef _NTDDK_

//
// Define Volume Parameter Block (VPB) flags.
//

#define VPB_MOUNTED                     0x00000001
#define VPB_LOCKED                      0x00000002
#define VPB_PERSISTENT                  0x00000004
#define VPB_REMOVE_PENDING              0x00000008
#define VPB_RAW_MOUNT                   0x00000010

typedef struct _VPB
{
	SHORT		Type;				//+0x000
	SHORT		Size;				//+0x002
	USHORT		Flags;				//+0x004
	USHORT		VolumeLabelLength;	//+0x006
	PDEVICE_OBJECT	DeviceObject;	//+0x008
	PDEVICE_OBJECT	RealDevice;		//+0x00c
	ULONG		SerialNumber;		//+0x010
	ULONG		ReferenceCount;		//+0x014
	USHORT		VolumeLabel [32];	//+0x018
} VPB, *PVPB, **PPVPB;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
