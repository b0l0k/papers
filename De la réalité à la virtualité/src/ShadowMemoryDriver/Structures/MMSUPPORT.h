/* 
Copyright (c) FRET.  All rights reserved.

File Name : MMSUPPORT.h

Abstract:
Memory Manager Support structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _MMSUPPORT_H_INCLUDED
#define _MMSUPPORT_H_INCLUDED

#include "LARGE_INTEGER.h"
#include "MMSUPPORT_FLAGS.h"
#include "MMWSL.h"
#include "LIST_ENTRY.h"

#ifndef MMSUPPORT_INCLUDED
#define MMSUPPORT_INCLUDED

typedef struct _MMSUPPORT
{
	LARGE_INTEGER	LastTrimTime;				//+0x000
	MMSUPPORT_FLAGS	Flags;						//+0x008
	ULONG			PageFaultCount;				//+0x00c
	ULONG			PeakWorkingSetSize;			//+0x010
	ULONG			WorkingSetSize;				//+0x014
	ULONG			MinimumWorkingSetSize;		//+0x018
	ULONG			MaximumWorkingSetSize;		//+0x01c
	PMMWSL			VmWorkingSetList;			//+0x020
	LIST_ENTRY		WorkingSetExpansionLinks;	//+0x024
	ULONG			Claim;						//+0x02c
	ULONG			NextEstimationSlot;			//+0x030
	ULONG			NextAgingSlot;				//+0x034
	ULONG			EstimatedAvailable;			//+0x038
	ULONG			GrowthSinceLastEstimate;	//+0x03c
} MMSUPPORT, *PMMSUPPORT, **PPMMSUPPORT;

#endif //_INCLUDED
#endif//_H_INCLUDED
