/* 
Copyright (c) FRET.  All rights reserved.

File Name : LARGE_CONTROL_AREA.h

Abstract:
Large Control Area structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _LARGE_CONTROL_AREA_H_INCLUDED
#define _LARGE_CONTROL_AREA_H_INCLUDED

#include "SEGMENT.h"
#include "LIST_ENTRY.h"
#include "MMSECTION_FLAGS.h"
#include "FILE_OBJECT.h"
#include "EVENT_COUNTER.h"

#ifndef LARGE_CONTROL_AREA_INCLUDED
#define LARGE_CONTROL_AREA_INCLUDED

// <size 0x40>
typedef struct _LARGE_CONTROL_AREA
{
	PSEGMENT		Segment;					//+0x000
	LIST_ENTRY		DereferenceList;			//+0x004
	ULONG			NumberOfSectionReferences;	//+0x00c
	ULONG			NumberOfPfnReferences;		//+0x010
	ULONG			NumberOfMappedViews;		//+0x014
	USHORT			NumberOfSubsections;		//+0x018
	USHORT			FlushInProgressCount;		//+0x01a
	ULONG			NumberOfUserReferences;		//+0x01c
	union
	{
		ULONG		LongFlags;
		MMSECTION_FLAGS Flags;
	} u;		//+0x020
	PFILE_OBJECT	FilePointer;				//+0x024
	PEVENT_COUNTER	WaitingForDeletion;			//+0x028
	USHORT			ModifiedWriteCount;			//+0x02c
	USHORT			NumberOfSystemCacheViews;	//+0x02e
	ULONG			StartingFrame;				//+0x030
	LIST_ENTRY		UserGlobalList;				//+0x034
	ULONG			SessionId;					//+0x03c
} LARGE_CONTROL_AREA, *PLARGE_CONTROL_AREA, **PPLARGE_CONTROL_AREA;

#endif //_INCLUDED
#endif //_H_INCLUDED
