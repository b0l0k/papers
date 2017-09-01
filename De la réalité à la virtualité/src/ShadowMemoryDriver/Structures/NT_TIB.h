/* 
 Copyright (c) FRET.  All rights reserved.

File Name : NT_TIB.h

Abstract:
Windows NT Thread Information Block structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 05
Last Update : 2-Sep-2006 
*/

#ifndef _NT_TIB_H_INCLUDED
#define _NT_TIB_H_INCLUDED

#include "EXCEPTION_REGISTRATION_RECORD.h"

#ifndef NT_TIB_INCLUDED
#define NT_TIB_INCLUDED
#if !defined( _WINNT_ ) && !defined( _NTDDK_ )

typedef struct _NT_TIB
{
	PEXCEPTION_REGISTRATION_RECORD	ExceptionList;		//+0x000
	PVOID	StackBase;				//+0x004
	PVOID	StackLimit;				//+0x008
	PVOID	SubSystemTib;			//+0x00c
	PVOID	FiberData;				//+0x010
	ULONG	Version;				//+0x010
	PVOID	ArbitraryUserPointer;	//+0x014
	struct _NT_TIB *	Self;		//+0x018
} NT_TIB, *PNT_TIB, **PPNT_TIB;

#endif //_WINNT_ && _NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
