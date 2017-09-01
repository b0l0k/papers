/* 
Copyright (c) FRET.  All rights reserved.

File Name : MMPTE_TRANSITION.h

Abstract:
Memory Manager Page Table Entry Trnasition structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _MMPTE_TRANSITION_H_INCLUDED
#define _MMPTE_TRANSITION_H_INCLUDED

#ifndef MMPTE_TRANSITION_INCLUDED
#define MMPTE_TRANSITION_INCLUDED

typedef struct _MMPTE_TRANSITION
{
	ULONG 	Valid : 1;				//0, +0x000
	ULONG 	Write : 1;				//1, +0x000
	ULONG 	Owner : 1;				//2, +0x000
	ULONG 	WriteThrough : 1;		//3, +0x000
	ULONG 	CacheDisable : 1;		//4, +0x000
	ULONG 	Protection : 5;			//5, +0x000
	ULONG 	Prototype : 1;			//10, +0x000
	ULONG 	Transition : 1;			//11, +0x000
	ULONG 	PageFrameNumber : 20;	//12, +0x000
} MMPTE_TRANSITION, *PMMPTE_TRANSITION;

#endif //_INCLUDED
#endif //_H_INCLUDED