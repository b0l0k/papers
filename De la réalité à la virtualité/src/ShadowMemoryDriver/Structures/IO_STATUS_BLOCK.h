/* 
Copyright (c) FRET.  All rights reserved.

File Name : IO_STATUS_BLOCK.h

Abstract:
Input/Output Status Block structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _IO_STATUS_BLOCK_H_INCLUDED
#define _IO_STATUS_BLOCK_H_INCLUDED

#ifndef IO_STATUS_BLOCK_INCLUDED
#define IO_STATUS_BLOCK_INCLUDED
#ifndef _NTDDK_

//<size 0x8>
typedef struct _IO_STATUS_BLOCK
{
	union
	{
		NTSTATUS	Status;			//+0x000
		PVOID		Pointer;		//+0x000
	};
	ULONG		Information;	//+0x004
} IO_STATUS_BLOCK, *PIO_STATUS_BLOCK, **PPIO_STATUS_BLOCK;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
