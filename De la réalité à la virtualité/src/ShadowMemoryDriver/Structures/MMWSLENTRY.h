/* 
Copyright (c) FRET.  All rights reserved.

File Name : MMWSLENTRY.h

Abstract:
Memory Manager Working Set ListEntry structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _MMWSLENTRY_H_INCLUDED
#define _MMWSLENTRY_H_INCLUDED

#ifndef MMWSLENTRY_INCLUDED
#define MMWSLENTRY_INCLUDED

typedef struct _MMWSLENTRY
{
	ULONG 	Valid : 1;				//0, +0x000
	ULONG 	LockedInWs : 1;			//1, +0x000
	ULONG 	LockedInMemory : 1;		//2, +0x000
	ULONG 	Protection : 5;			//3, +0x000
	ULONG 	Hashed : 1;				//8, +0x000
	ULONG 	Direct : 1;				//9, +0x000
	ULONG 	Age : 2;				//10, +0x000
	ULONG 	VirtualPageNumber : 20;	//12, +0x000
} MMWSLENTRY, *PMMWSLENTRY, **PPMMWSLENTRY;

#endif //_INCLUDED
#endif//_H_INCLUDED
