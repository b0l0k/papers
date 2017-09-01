/* 
Copyright (c) FRET.  All rights reserved.

File Name : MMPTE_LIST.h

Abstract:
Memory Manager Page Table Entry List structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 05
Last Update : 2-Sep-2006 
*/

#ifndef _MMPTE_LIST_H_INCLUDED
#define _MMPTE_LIST_H_INCLUDED

#ifndef MMPTE_LIST_INCLUDED
#define MMPTE_LIST_INCLUDED

//<size 0x04>
typedef struct _MMPTE_LIST
{
	ULONG 	Valid : 1;		//0, +0x000
	ULONG 	OneEntry : 1;		//1, +0x000
	ULONG 	filler0 : 8;		//2, +0x000
	ULONG 	Prototype : 1;		//10, +0x000
	ULONG 	filler1 : 1;		//11, +0x000
	ULONG 	NextEntry : 20;		//12, +0x000
} MMPTE_LIST, *PMMPTE_LIST;

#endif //_INCLUDED
#endif //_H_INCLUDED