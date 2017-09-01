/* 
Copyright (c) FRET.  All rights reserved.

File Name : HARDWARE_PTE_X86.h

Abstract:
Hardware Page Table Entry x86 structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _HARDWARE_PTE_X86_H_INCLUDED
#define _HARDWARE_PTE_X86_H_INCLUDED

#ifndef HARDWARE_PTE_X86_INCLUDED
#define HARDWARE_PTE_X86_INCLUDED

typedef struct _HARDWARE_PTE_X86
{
	ULONG 	Valid : 1;			//0, +0x000
	ULONG 	Write : 1;			//1, +0x000
	ULONG 	Owner : 1;			//2, +0x000
	ULONG 	WriteThrough : 1;	//3, +0x000
	ULONG 	CacheDisable : 1;	//4, +0x000
	ULONG 	Accessed : 1;		//5, +0x000
	ULONG 	Dirty : 1;			//6, +0x000
	ULONG 	LargePage : 1;		//7, +0x000
	ULONG 	Global : 1;			//8, +0x000
	ULONG 	CopyOnWrite : 1;	//9, +0x000
	ULONG 	Prototype : 1;		//10, +0x000
	ULONG 	reserved : 1;		//11, +0x000
	ULONG 	PageFrameNumber : 20;//12, +0x000
} HARDWARE_PTE_X86, *PHARDWARE_PTE_X86, **PPHARDWARE_PTE_X86;

#endif //_INCLUDED
#endif //_H_INCLUDED
