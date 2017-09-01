/* 
Copyright (c) FRET.  All rights reserved.

File Name : MMPTE_SOFTWARE.h

Abstract:
Memory Manager Page Table Entry Software structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _MMPTE_SOFTWARE_H_INCLUDED
#define _MMPTE_SOFTWARE_H_INCLUDED

#ifndef MMPTE_SOFTWARE_INCLUDED
#define MMPTE_SOFTWARE_INCLUDED

typedef struct _MMPTE_SOFTWARE
{
	ULONG 	Valid : 1;			//0, +0x000
	ULONG 	PageFileLow : 4;	//1, +0x000
	ULONG 	Protection : 5;		//5, +0x000
	ULONG 	Prototype : 1;		//10, +0x000
	ULONG 	Transition : 1;		//11, +0x000
	ULONG 	PageFileHigh : 20;	//12, +0x000
} MMPTE_SOFTWARE, *PMMPTE_SOFTWARE;

#endif //_INCLUDED
#endif //_H_INCLUDED