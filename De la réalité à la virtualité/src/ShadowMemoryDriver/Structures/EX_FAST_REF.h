/* 
Copyright (c) FRET.  All rights reserved.

File Name : EX_FAST_REF.h

Abstract:
Ex Fast Reference structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _EX_FAST_REF_H_INCLUDED
#define _EX_FAST_REF_H_INCLUDED

#ifndef EX_FAST_REF_INCLUDED
#define EX_FAST_REF_INCLUDED

typedef struct _EX_FAST_REF
{
	union
	{
	PVOID	Object;		//+0x000
	ULONG 	RefCnt : 3;	//0, +0x000
	ULONG	Value;		//+0x000  
	};
} EX_FAST_REF, *PEX_FAST_REF, **PPEX_FAST_REF;

#endif //_INCLUDED
#endif //_H_INCLUDED
