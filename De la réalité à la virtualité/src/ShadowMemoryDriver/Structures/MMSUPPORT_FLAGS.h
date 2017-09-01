/* 
Copyright (c) FRET.  All rights reserved.

File Name : MMSUPPORT_FLAGS.h

Abstract:
Memory Manager Support Flags structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _MMSUPPORT_FLAGS_H_INCLUDED
#define _MMSUPPORT_FLAGS_H_INCLUDED

#ifndef MMSUPPORT_FLAGS_INCLUDED
#define MMSUPPORT_FLAGS_INCLUDED

typedef struct _MMSUPPORT_FLAGS
{
	ULONG 	SessionSpace : 1;				//0, +0x000
	ULONG 	BeingTrimmed : 1;				//1, +0x000
	ULONG 	SessionLeader : 1;				//2, +0x000
	ULONG 	TrimHard : 1;					//3, +0x000
	ULONG 	WorkingSetHard : 1;				//4, +0x000
	ULONG 	AddressSpaceBeingDeleted : 1;	//5, +0x000
	ULONG 	Available : 10;					//6, +0x000
	ULONG 	AllowWorkingSetAdjustment : 8;	//16, +0x000
	ULONG 	MemoryPriority : 8;				//24, +0x000
} MMSUPPORT_FLAGS, *PMMSUPPORT_FLAGS, **PPMMSUPPORT_FLAGS;

#endif //_INCLUDED
#endif//_H_INCLUDED
