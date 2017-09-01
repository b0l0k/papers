/* 
Copyright (c) FRET.  All rights reserved.

File Name : MDL.h

Abstract:
Memory Descriptor List structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 05
Last Update : 2-Sep-2006 
*/

#ifndef _MDL_H_INCLUDED
#define _MDL_H_INCLUDED

#include "EPROCESS.h"

#ifndef MDL_INCLUDED
#define MDL_INCLUDED
#ifndef _NTDDK_

typedef struct _MDL
{
	struct _MDL *	Next;			//+0x000
	CSHORT			Size;			//+0x004
	CSHORT			MdlFlags;		//+0x006
	PEPROCESS		Process;		//+0x008
	PVOID			MappedSystemVa;	//+0x00c
	PVOID			StartVa;		//+0x010
	ULONG			ByteCount;		//+0x014
	ULONG			ByteOffset;		//+0x018
} MDL, *PMDL, **PPMDL;

#define MDL_MAPPED_TO_SYSTEM_VA     0x0001
#define MDL_PAGES_LOCKED            0x0002
#define MDL_SOURCE_IS_NONPAGED_POOL 0x0004
#define MDL_ALLOCATED_FIXED_SIZE    0x0008
#define MDL_PARTIAL                 0x0010
#define MDL_PARTIAL_HAS_BEEN_MAPPED 0x0020
#define MDL_IO_PAGE_READ            0x0040
#define MDL_WRITE_OPERATION         0x0080
#define MDL_PARENT_MAPPED_SYSTEM_VA 0x0100
#define MDL_FREE_EXTRA_PTES         0x0200
#define MDL_IO_SPACE                0x0800
#define MDL_NETWORK_HEADER          0x1000
#define MDL_MAPPING_CAN_FAIL        0x2000
#define MDL_ALLOCATED_MUST_SUCCEED  0x4000


#define MDL_MAPPING_FLAGS (MDL_MAPPED_TO_SYSTEM_VA     | \
                           MDL_PAGES_LOCKED            | \
                           MDL_SOURCE_IS_NONPAGED_POOL | \
                           MDL_PARTIAL_HAS_BEEN_MAPPED | \
                           MDL_PARENT_MAPPED_SYSTEM_VA | \
                           MDL_SYSTEM_VA               | \
                           MDL_IO_SPACE )

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
