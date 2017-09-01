/* 
Copyright (c) FRET.  All rights reserved.

File Name : KTRAP_FRAME.h

Abstract:
Kernel Trap Frame structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _KTRAP_FRAME_H_INCLUDED
#define _KTRAP_FRAME_H_INCLUDED

#include "EXCEPTION_REGISTRATION_RECORD.h"

#ifndef KTRAP_FRAME_INCLUDED
#define KTRAP_FRAME_INCLUDED

// <size 0x8c>
typedef struct _KTRAP_FRAME
{
	ULONG	DbgEbp;			//+0x000
	ULONG	DbgEip;			//+0x004
	ULONG	DbgArgMark;		//+0x008
	ULONG	DbgArgPointer;	//+0x00c
	ULONG	TempSegCs;		//+0x010
	ULONG	TempEsp;		//+0x014
	ULONG	Dr0;			//+0x018
	ULONG	Dr1;			//+0x01c
	ULONG	Dr2;			//+0x020
	ULONG	Dr3;			//+0x024
	ULONG	Dr6;			//+0x028
	ULONG	Dr7;			//+0x02c
	ULONG	SegGs;			//+0x030
	ULONG	SegEs;			//+0x034
	ULONG	SegDs;			//+0x038
	ULONG	Edx;			//+0x03c
	ULONG	Ecx;			//+0x040
	ULONG	Eax;			//+0x044
	ULONG	PreviousPreviousMode;//+0x048
	PEXCEPTION_REGISTRATION_RECORD	ExceptionList;//+0x04c
	ULONG	SegFs;			//+0x050
	ULONG	Edi;			//+0x054
	ULONG	Esi;			//+0x058
	ULONG	Ebx;			//+0x05c
	ULONG	Ebp;			//+0x060
	ULONG	ErrCode;		//+0x064
	ULONG	Eip;			//+0x068
	ULONG	SegCs;			//+0x06c
	ULONG	EFlags;			//+0x070
	ULONG	HardwareEsp;	//+0x074
	ULONG	HardwareSegSs;	//+0x078
	ULONG	V86Es;			//+0x07c
	ULONG	V86Ds;			//+0x080
	ULONG	V86Fs;			//+0x084
	ULONG	V86Gs;			//+0x088
} KTRAP_FRAME, *PKTRAP_FRAME, **PPKTRAP_FRAME;

#endif //_INCLUDED
#endif//_H_INCLUDED
