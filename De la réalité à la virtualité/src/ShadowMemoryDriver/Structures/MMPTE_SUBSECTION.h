/* 
Copyright (c) FRET.  All rights reserved.

File Name : MMPTE_SUBSECTION.h

Abstract:
Memroy Manager Page Table Entry Subsection structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _MMPTE_SUBSECTION_H_INCLUDED
#define _MMPTE_SUBSECTION_H_INCLUDED

#ifndef MMPTE_SUBSECTION_INCLUDED
#define MMPTE_SUBSECTION_INCLUDED

typedef struct _MMPTE_SUBSECTION
{
	ULONG 	Valid : 1;					//0, +0x000
	ULONG 	SubsectionAddressLow : 4;	//1, +0x000
	ULONG 	Protection : 5;				//5, +0x000
	ULONG 	Prototype : 1;				//10, +0x000
	ULONG 	SubsectionAddressHigh : 20;	//11, +0x000
	ULONG 	WhichPool : 1;				//31, +0x000
} MMPTE_SUBSECTION, *PMMPTE_SUBSECTION;

#endif //_INCLUDED
#endif //_H_INCLUDED