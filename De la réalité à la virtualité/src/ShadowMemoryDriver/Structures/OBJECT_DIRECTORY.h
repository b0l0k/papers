/* 
Copyright (c) FRET.  All rights reserved.

File Name : OBJECT_DIRECTORY.h

Abstract:
Object Directory structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _OBJECT_DIRECTORY_H_INCLUDED
#define _OBJECT_DIRECTORY_H_INCLUDED

#include "OBJECT_DIRECTORY_ENTRY.h"
#include "EX_PUSH_LOCK.h"
#include "DEVICE_MAP.h"

#ifndef OBJECT_DIRECTORY_INCLUDED
#define OBJECT_DIRECTORY_INCLUDED

typedef struct _OBJECT_DIRECTORY
{
	POBJECT_DIRECTORY_ENTRY HashBuckets [37];		//+0x000
	EX_PUSH_LOCK			Lock;					//+0x094
	struct _DEVICE_MAP *	DeviceMap;				//+0x098
	ULONG					SessionId;				//+0x09c
	USHORT					Reserved;				//+0x0a0
	USHORT					SymbolicLinkUsageCount;	//+0x0a2
} OBJECT_DIRECTORY, *POBJECT_DIRECTORY, **PPOBJECT_DIRECTORY;

#endif //_INCLUDED
#endif//_H_INCLUDED
