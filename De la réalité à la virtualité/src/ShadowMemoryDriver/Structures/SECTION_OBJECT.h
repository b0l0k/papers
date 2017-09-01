/* 
Copyright (c) FRET.  All rights reserved.

File Name : SECTION_OBJECT.h

Abstract:
Section Object structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 26-Aug-2006 
*/

#ifndef _SECTION_OBJECT_H_INCLUDED
#define _SECTION_OBJECT_H_INCLUDED

#include "SEGMENT_OBJECT.h"

#ifndef SECTION_OBJECT_INCLUDED
#define SECTION_OBJECT_INCLUDED

typedef struct _SECTION_OBJECT
{
	PVOID			StartingVa;		//+0x000
	PVOID			EndingVa;		//+0x004
	PVOID			LeftChild;		//+0x008
	PVOID			RightChild;		//+0x00c
	PSEGMENT_OBJECT Segment;		//+0x010
} SECTION_OBJECT, *PSECTION_OBJECT, **PPSECTION_OBJECT;

#endif //_INCLUDED
#endif //_H_INCLUDED