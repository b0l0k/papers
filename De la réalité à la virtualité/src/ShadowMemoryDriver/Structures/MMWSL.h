/* 
Copyright (c) FRET.  All rights reserved.

File Name : MMWSL.h

Abstract:
Memory Manager Working Set List structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _MMWSL_H_INCLUDED
#define _MMWSL_H_INCLUDED

#include "MMWSLE.h"
#include "MMWSLE_HASH.h"

#ifndef MMWSL_INCLUDED
#define MMWSL_INCLUDED

typedef struct _MMWSL
{
	ULONG			Quota;						//+0x000
	ULONG			FirstFree;					//+0x004
	ULONG			FirstDynamic;				//+0x008
	ULONG			LastEntry;					//+0x00c
	ULONG			NextSlot;					//+0x010
	PMMWSLE			Wsle;						//+0x014
	ULONG			LastInitializedWsle;		//+0x018
	ULONG			NonDirectCount;				//+0x01c
	PMMWSLE_HASH	HashTable;					//+0x020
	ULONG			HashTableSize;				//+0x024
	ULONG			NumberOfCommittedPageTables;//+0x028
	PVOID			HashTableStart;				//+0x02c
	PVOID			HighestPermittedHashAddress;//+0x030
	ULONG			NumberOfImageWaiters;		//+0x034
	ULONG			VadBitMapHint;				//+0x038
	USHORT			UsedPageTableEntries [768];	//+0x03c
	ULONG			CommittedPageTables [24];	//+0x63c
} MMWSL, *PMMWSL, **PPMMWSL;

#endif //_INCLUDED
#endif//_H_INCLUDED
