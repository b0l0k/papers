/* 
Copyright (c) FRET.  All rights reserved.

File Name : FS_FILTER_PARAMETERS.h

Abstract:
File System Filter Parameters structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 01
Last Update : 2-Sep-2006 
*/

#ifndef _FS_FILTER_PARAMETERS_H_INCLUDED
#define _FS_FILTER_PARAMETERS_H_INCLUDED

#include "LARGE_INTEGER.h"
#include "ERESOURCE.h"
#include "FS_FILTER_SECTION_SYNC_TYPE.h"

#ifndef FS_FILTER_PARAMETERS_INCLUDED
#define FS_FILTER_PARAMETERS_INCLUDED

// <size 0x14> <All fields' offset at 0x0>
typedef union _FS_FILTER_PARAMETERS
{
	struct
	{
		PLARGE_INTEGER  EndingOffset;
	} AcquireForModifiedPageWriter;
	struct
	{
		PERESOURCE  ResourceToRelease;
	} ReleaseForModifiedPageWriter;
	struct {
		FS_FILTER_SECTION_SYNC_TYPE  SyncType;
		ULONG  PageProtection;
	} AcquireForSectionSynchronization;
	struct
	{
		PVOID  Argument1;
		PVOID  Argument2;
		PVOID  Argument3;
		PVOID  Argument4;
		PVOID  Argument5;
	} Others;
} FS_FILTER_PARAMETERS, *PFS_FILTER_PARAMETERS, **PPFS_FILTER_PARAMETERS;

#endif //_INCLUDED
#endif //_H_INCLUDED