/* 
Copyright (c) FRET.  All rights reserved.

File Name : SEGMENT.h

Abstract:
Segment structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _SEGMENT_H_INCLUDED
#define _SEGMENT_H_INCLUDED

#include "CONTROL_AREA.h"
#include "MMPTE.h"
#include "MMEXTEND_INFO.h"
#include "SECTION_IMAGE_INFORMATION.h"

#ifndef SEGMENT_INCLUDED
#define SEGMENT_INCLUDED

// <size 0x40>
typedef struct _SEGMENT
{
	struct _CONTROL_AREA *	ControlArea;	//+0x000
	ULONG			TotalNumberOfPtes;		//+0x004
	ULONG			NonExtendedPtes;		//+0x008
	ULONG			WritableUserReferences;	//+0x00c
	ULONGLONG		SizeOfSegment;			//+0x010
	MMPTE			SegmentPteTemplate;		//+0x018
	ULONG			NumberOfCommittedPages;	//+0x01c
	PMMEXTEND_INFO	ExtendInfo;				//+0x020
	PVOID			SystemImageBase;		//+0x024
	PVOID			BasedAddress;			//+0x028
	union
	{
		ULONG		ImageCommitment;
		PEPROCESS	CreatingProcess;
	} u1;		//+0x02c
	union
	{
		PSECTION_IMAGE_INFORMATION ImageInformation;
		PVOID		FirstMappedVa;
	} u2;		//+0x030
	PMMPTE			PrototypePte;			//+0x034
	MMPTE			ThePtes [1];			//+0x038
} SEGMENT, *PSEGMENT, **PPSEGMENT;


#endif //_INCLUDED
#endif//_H_INCLUDED
