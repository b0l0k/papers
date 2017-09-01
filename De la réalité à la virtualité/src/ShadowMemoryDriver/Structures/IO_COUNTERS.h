/* 
Copyright (c) FRET.  All rights reserved.

File Name : IO_COUNTERS.h

Abstract:
Input/Ouput Counters structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _IO_COUNTERS_H_INCLUDED
#define _IO_COUNTERS_H_INCLUDED

#ifndef IO_COUNTERS_INCLUDED
#define IO_COUNTERS_INCLUDED
#ifndef _NTDDK_

// <size 0x30>
typedef struct _IO_COUNTERS
{
	ULONGLONG	ReadOperationCount;		//+0x000
	ULONGLONG	WriteOperationCount;	//+0x008
	ULONGLONG	OtherOperationCount;	//+0x010
	ULONGLONG	ReadTransferCount;		//+0x018
	ULONGLONG	WriteTransferCount;		//+0x020
	ULONGLONG	OtherTransferCount;		//+0x028
} IO_COUNTERS, *PIO_COUNTERS, **PPIO_COUNTERS;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
