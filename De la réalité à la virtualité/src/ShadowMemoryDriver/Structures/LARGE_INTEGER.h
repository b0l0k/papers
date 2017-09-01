/* 
 Copyright (c) FRET.  All rights reserved.

File Name : LARGE_INTEGER.h

Abstract:
Large Integer structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 28-Aug-2006 
*/

#ifndef _LARGE_INTEGER_H_INCLUDED
#define _LARGE_INTEGER_H_INCLUDED

#ifndef LARGE_INTEGER_INCLUDED
#define LARGE_INTEGER_INCLUDED
#if !defined ( _NTDDK_ ) && !defined( _WINNT_ )

typedef union _LARGE_INTEGER
{  
	struct 
	{    
		DWORD LowPart;
		LONG HighPart;
	};
	struct 
	{    
		DWORD LowPart;
		LONG HighPart;
	} u;  
	LONGLONG QuadPart;
} LARGE_INTEGER, *PLARGE_INTEGER, **PPLARGE_INTEGER;

#endif //_WINNT_
#endif //_INCLUDED
#endif //_H_INCLUDED
