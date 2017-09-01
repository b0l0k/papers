/* 
Copyright (c) FRET.  All rights reserved.

File Name : MMSUBSECTION_FLAGS.h

Abstract:
Memory Manager Subsection Flags structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _MMSUBSECTION_FLAGS_H_INCLUDED
#define _MMSUBSECTION_FLAGS_H_INCLUDED

#ifndef MMSUBSECTION_FLAGS_INCLUDED
#define MMSUBSECTION_FLAGS_INCLUDED

typedef struct _MMSUBSECTION_FLAGS
{
	ULONG 	ReadOnly : 1;			//0, +0x000
	ULONG 	ReadWrite : 1;			//1, +0x000
	ULONG 	SubsectionStatic : 1;	//2, +0x000
	ULONG 	GlobalMemory : 1;		//3, +0x000
	ULONG 	Protection : 5;			//4, +0x000
	ULONG 	LargePages : 1;			//9, +0x000
	ULONG 	StartingSector4132 : 10;//10, +0x000
	ULONG 	SectorEndOffset : 12;	//20, +0x000
} MMSUBSECTION_FLAGS, *PMMSUBSECTION_FLAGS, **PPMMSUBSECTION_FLAGS;

#endif //_INCLUDED
#endif//_H_INCLUDED
