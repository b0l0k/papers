/* 
Copyright (c) FRET.  All rights reserved.

File Name : MMPTE_PROTOTYPE.h

Abstract:
Memory Manager Page Table Entry Prototype structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _MMPTE_PROTOTYPE_H_INCLUDED
#define _MMPTE_PROTOTYPE_H_INCLUDED

#ifndef MMPTE_PROTOTYPE_INCLUDED
#define MMPTE_PROTOTYPE_INCLUDED

typedef struct _MMPTE_PROTOTYPE
{
	ULONG 	Valid : 1;				//0, +0x000
	ULONG 	ProtoAddressLow : 7;	//1, +0x000
	ULONG 	ReadOnly : 1;			//8, +0x000
	ULONG 	WhichPool : 1;			//9, +0x000
	ULONG 	Prototype : 1;			//10, +0x000
	ULONG 	ProtoAddressHigh : 21;	//11, +0x000
} MMPTE_PROTOTYPE, *PMMPTE_PROTOTYPE;

#endif //_INCLUDED
#endif //_H_INCLUDED