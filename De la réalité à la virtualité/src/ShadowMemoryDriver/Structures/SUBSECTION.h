/* 
Copyright (c) FRET.  All rights reserved.

File Name : SUBSECTION.h

Abstract:
Subsection structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _SUBSECTION_H_INCLUDED
#define _SUBSECTION_H_INCLUDED

#include "CONTROL_AREA.h"
#include "MMSUBSECTION_FLAGS.h"
#include "MMPTE.h"

#ifndef SUBSECTION_INCLUDED
#define SUBSECTION_INCLUDED

typedef struct _SUBSECTION
{
	PCONTROL_AREA	ControlArea;			//+0x000
	union
	{
		ULONG		LongFlags;
		MMSUBSECTION_FLAGS SubsectionFlags;
	} u;		//+0x004
	ULONG			StartingSector;			//+0x008
	ULONG			NumberOfFullSectors;	//+0x00c
	PMMPTE			SubsectionBase;			//+0x010
	ULONG			UnusedPtes;				//+0x014
	ULONG			PtesInSubsection;		//+0x018
	struct _SUBSECTION *	NextSubsection;	//+0x01c
} SUBSECTION, *PSUBSECTION, **PPSUBSECTION;

#endif //_INCLUDED
#endif //_H_INCLUDED
