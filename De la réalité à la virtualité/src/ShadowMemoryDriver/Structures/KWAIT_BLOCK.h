/* 
Copyright (c) FRET.  All rights reserved.

File Name : KWAIT_BLOCK.h

Abstract:
Kernel Wait Block structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 05
Last Update : 2-Sep-2006 
*/

#ifndef _KWAIT_BLOCK_H_INCLUDED
#define _KWAIT_BLOCK_H_INCLUDED

#include "LIST_ENTRY.h"
#include "KTHREAD.h"

#ifndef KWAIT_BLOCK_INCLUDED
#define KWAIT_BLOCK_INCLUDED
#ifndef _NTDDK_

// <size 0x18>
typedef struct _KWAIT_BLOCK
{
	LIST_ENTRY						WaitListEntry;			//+0x000
	KTHREAD *RESTRICTED_POINTER 	Thread;					//+0x008
	PVOID							Object;					//+0x00c
	struct _KWAIT_BLOCK *RESTRICTED_POINTER	NextWaitBlock;	//+0x010
	USHORT							WaitKey;				//+0x014
	USHORT							WaitType;				//+0x016
} KWAIT_BLOCK, *PKWAIT_BLOCK, *RESTRICTED_POINTER PRKWAIT_BLOCK;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
