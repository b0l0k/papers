/* 
Copyright (c) FRET.  All rights reserved.

File Name : MMWSLE_HASH.h

Abstract:
Memory Manager Working Set List Entry Hash structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _MMWSLE_HASH_H_INCLUDED
#define _MMWSLE_HASH_H_INCLUDED

#ifndef MMWSLE_HASH_INCLUDED
#define MMWSLE_HASH_INCLUDED

typedef struct _MMWSLE_HASH
{
	PVOID	Key;		//+0x000
	ULONG	Index;		//+0x004
} MMWSLE_HASH, *PMMWSLE_HASH, **PPMMWSLE_HASH;

#endif //_INCLUDED
#endif//_H_INCLUDED
