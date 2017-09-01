/* 
Copyright (c) FRET.  All rights reserved.

File Name : EX_RUNDOWN_REF.h

Abstract:
Ex Rundown Reference structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _EX_RUNDOWN_REF_H_INCLUDED
#define _EX_RUNDOWN_REF_H_INCLUDED

#ifndef EX_RUNDOWN_REF_INCLUDED
#define EX_RUNDOWN_REF_INCLUDED

typedef struct _EX_RUNDOWN_REF
{
	union
	{
	ULONG	Count;	//+0x000
	PVOID	Ptr;	//+0x000
	};
} EX_RUNDOWN_REF, *PEX_RUNDOWN_REF, **PPEX_RUNDOWN_REF;

#endif //_INCLUDED
#endif //_H_INCLUDED
