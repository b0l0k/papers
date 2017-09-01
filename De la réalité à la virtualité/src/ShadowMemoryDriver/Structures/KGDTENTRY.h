/* 
Copyright (c) FRET.  All rights reserved.

File Name : KGDTENTRY.h

Abstract:
Kernel Global Descriptor Table Entry structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 26-Aug-2006 
*/

#ifndef _KGDTENTRY_H_INCLUDED
#define _KGDTENTRY_H_INCLUDED

#ifndef KGDTENTRY_INCLUDED
#define KGDTENTRY_INCLUDED

typedef struct _KGDTENTRY
{
	USHORT	LimitLow;		//+0x000
	USHORT	BaseLow;		//+0x002
	union
	{
		struct
		{
			UCHAR BaseMid;
			UCHAR Flags1;
			UCHAR Flags2;
			UCHAR BaseHi;
		} Bytes;
		struct
		{
			ULONG BaseMid:8;
			ULONG Type:5;
			ULONG Dpl:2;
			ULONG Pres:1;
			ULONG LimitHi:4;
			ULONG Sys:1;
			ULONG Reserved_0:1;
			ULONG Default_Big:1;
			ULONG Granularity:1;
			ULONG BaseHi:8;
		} Bits;
	} HighWord;		//+0x004
} KGDTENTRY, *PKGDTENTRY, **PPKGDTENTRY;

#endif //_INCLUDED
#endif //_H_INCLUDED
