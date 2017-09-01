/* 
Copyright (c) FRET.  All rights reserved.

File Name : FS_FILTER_CALLBACK_DATA.h

Abstract:
FS Filter Callback structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 01
Last Update : 2-Sep-2006 
*/

#ifndef _FS_FILTER_CALLBACK_DATA_H_INCLUDED
#define _FS_FILTER_CALLBACK_DATA_H_INCLUDED

#include "DEVICE_OBJECT.h"
#include "FILE_OBJECT.h"
#include "FS_FILTER_PARAMETERS.h"

#ifndef FS_FILTER_CALLBACK_DATA_INCLUDED
#define FS_FILTER_CALLBACK_DATA_INCLUDED

//<size 0x24>
typedef struct _FS_FILTER_CALLBACK_DATA
{
	ULONG					SizeOfFsFilterCallbackData;	//+0x000
	UCHAR					Operation;					//+0x004
	UCHAR					Reserved;					//+0x005
	PDEVICE_OBJECT			DeviceObject;				//+0x008
	PFILE_OBJECT			FileObject;					//+0x00c
	FS_FILTER_PARAMETERS	Parameters;					//+0x010
} FS_FILTER_CALLBACK_DATA, *PFS_FILTER_CALLBACK_DATA, **PPFS_FILTER_CALLBACK_DATA;

#endif //_INCLUDED
#endif //_H_INCLUDED
