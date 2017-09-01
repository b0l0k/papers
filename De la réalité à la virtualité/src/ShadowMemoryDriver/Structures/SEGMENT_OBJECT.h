/* 
Copyright (c) FRET.  All rights reserved.

File Name : SEGMENT_OBJECT.h

Abstract:
Segment Object structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 26-Aug-2006 
*/

#ifndef _SEGMENT_OBJECT_H_INCLUDED
#define _SEGMENT_OBJECT_H_INCLUDED

#include "LARGE_INTEGER.h"
#include "CONTROL_AREA.h"
#include "SUBSECTION.h"
#include "LARGE_CONTROL_AREA.h"
#include "MMSECTION_FLAGS.h"
#include "MMSUBSECTION_FLAGS.h"

#ifndef SEGMENT_OBJECT_INCLUDED
#define SEGMENT_OBJECT_INCLUDED

typedef struct _SEGMENT_OBJECT
{
	PVOID				BaseAddress;			//+0x000
	ULONG				TotalNumberOfPtes;		//+0x004
	LARGE_INTEGER		SizeOfSegment;			//+0x008
	ULONG				NonExtendedPtes;		//+0x010
	ULONG				ImageCommitment;		//+0x014
	PCONTROL_AREA		ControlArea;			//+0x018
	PSUBSECTION			Subsection;				//+0x01c
	PLARGE_CONTROL_AREA LargeControlArea;		//+0x020
	PMMSECTION_FLAGS	MmSectionFlags;			//+0x024
	PMMSUBSECTION_FLAGS MmSubSectionFlags;		//+0x028
} SEGMENT_OBJECT, *PSEGMENT_OBJECT, **PPSEGMENT_OBJECT;

#endif //_INCLUDED
#endif //_H_INCLUDED