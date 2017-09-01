/* 
Copyright (c) FRET.  All rights reserved.

File Name : FS_FILTER_SECTION_SYNC_TYPE.h

Abstract:
File System Filter Section Synchronization Type Enumeration.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 01
Last Update : 2-Sep-2006 
*/

#ifndef _FS_FILTER_SECTION_SYNC_TYPE_H_INCLUDED
#define _FS_FILTER_SECTION_SYNC_TYPE_H_INCLUDED

#include "LARGE_INTEGER.h"
#include "ERESOURCE.h"
#include "FS_FILTER_SECTION_SYNC_TYPE.h"

#ifndef FS_FILTER_SECTION_SYNC_TYPE_INCLUDED
#define FS_FILTER_SECTION_SYNC_TYPE_INCLUDED

typedef enum _FS_FILTER_SECTION_SYNC_TYPE
{
	SyncTypeOther = 0,
	SyncTypeCreateSection
} FS_FILTER_SECTION_SYNC_TYPE, *PFS_FILTER_SECTION_SYNC_TYPE;

#endif //_INCLUDED
#endif //_H_INCLUDED