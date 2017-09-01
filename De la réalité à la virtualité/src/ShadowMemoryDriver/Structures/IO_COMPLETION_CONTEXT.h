/* 
Copyright (c) FRET.  All rights reserved.

File Name : IO_COMPLETION_CONTEXT.h

Abstract:
Input/Ouput Completion Context structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _IO_COMPLETION_CONTEXT_H_INCLUDED
#define _IO_COMPLETION_CONTEXT_H_INCLUDED

#ifndef IO_COMPLETION_CONTEXT_INCLUDED
#define IO_COMPLETION_CONTEXT_INCLUDED
#ifndef _NTDDK_

// <size 0x8>
typedef struct _IO_COMPLETION_CONTEXT
{
	PVOID	Port;		//+0x000
	PVOID	Key;		//+0x004
} IO_COMPLETION_CONTEXT, *PIO_COMPLETION_CONTEXT, **PPIO_COMPLETION_CONTEXT;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
