/* 
 Copyright (c) FRET.  All rights reserved.

File Name : ULARGE_INTEGER.h

Abstract:
Unsigned Large Integer structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _ULARGE_INTEGER_H_INCLUDED
#define _ULARGE_INTEGER_H_INCLUDED

#ifndef ULARGE_INTEGER_INCLUDED
#define ULARGE_INTEGER_INCLUDED
#if !defined ( _WINNT_ ) && !defined ( _NTDDK_ )

typedef union _ULARGE_INTEGER
{  
	struct
	{    
		DWORD LowPart;
		DWORD HighPart;
	};
	struct
	{
		DWORD LowPart;
		DWORD HighPart;
	} u;
	ULONGLONG QuadPart;
} ULARGE_INTEGER, *PULARGE_INTEGER, **PPULARGE_INTEGER;

#endif //_WINNT_ _NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
