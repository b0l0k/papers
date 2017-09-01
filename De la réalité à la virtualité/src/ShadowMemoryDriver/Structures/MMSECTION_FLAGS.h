/* 
Copyright (c) FRET.  All rights reserved.

File Name : MMSECTION_FLAGS.h

Abstract:
Memory Manager Section Flags structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 26-Aug-2006 
*/

#ifndef _MMSECTION_FLAGS_H_INCLUDED
#define _MMSECTION_FLAGS_H_INCLUDED

#ifndef MMSECTION_FLAGS_INCLUDED
#define MMSECTION_FLAGS_INCLUDED

typedef struct _MMSECTION_FLAGS
{
	ULONG 	BeingDeleted : 1;				//0, +0x000
	ULONG 	BeingCreated : 1;				//1, +0x000
	ULONG 	BeingPurged : 1;				//2, +0x000
	ULONG 	NoModifiedWriting : 1;			//3, +0x000
	ULONG 	FailAllIo : 1;					//4, +0x000
	ULONG 	Image : 1;						//5, +0x000
	ULONG 	Based : 1;						//6, +0x000
	ULONG 	File : 1;						//7, +0x000
	ULONG 	Networked : 1;					//8, +0x000
	ULONG 	NoCache : 1;					//9, +0x000
	ULONG 	PhysicalMemory : 1;				//10, +0x000
	ULONG 	CopyOnWrite : 1;				//11, +0x000
	ULONG 	Reserve : 1;					//12, +0x000
	ULONG 	Commit : 1;						//13, +0x000
	ULONG 	FloppyMedia : 1;				//14, +0x000
	ULONG 	WasPurged : 1;					//15, +0x000
	ULONG 	UserReference : 1;				//16, +0x000
	ULONG 	GlobalMemory : 1;				//17, +0x000
	ULONG 	DeleteOnClose : 1;				//18, +0x000
	ULONG 	FilePointerNull : 1;			//19, +0x000
	ULONG 	DebugSymbolsLoaded : 1;			//20, +0x000
	ULONG 	SetMappedFileIoComplete : 1;	//21, +0x000
	ULONG 	CollidedFlush : 1;				//22, +0x000
	ULONG 	NoChange : 1;					//23, +0x000
	ULONG 	HadUserReference : 1;			//24, +0x000
	ULONG 	ImageMappedInSystemSpace : 1;	//25, +0x000
	ULONG 	UserWritable : 1;				//26, +0x000
	ULONG 	Accessed : 1;					//27, +0x000
	ULONG 	GlobalOnlyPerSession : 1;		//28, +0x000
	ULONG 	Rom : 1;						//29, +0x000
	ULONG 	filler : 2;						//30, +0x000
} MMSECTION_FLAGS, *PMMSECTION_FLAGS, **PPMMSECTION_FLAGS;

#endif //_INCLUDED
#endif//_H_INCLUDED
