/* 
Copyright (c) FRET.  All rights reserved.

File Name : MMWSLE.h

Abstract:
Memory Manager Working Set List Entry structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _MMWSLE_H_INCLUDED
#define _MMWSLE_H_INCLUDED

#include "MMWSLENTRY.h"

#ifndef MMWSLE_INCLUDED
#define MMWSLE_INCLUDED

typedef struct _MMWSLE
{
	union
	{
		PVOID VirtualAddress;
		ULONG Long;
		MMWSLENTRY e1;
	}u1;		//+0x000
} MMWSLE, *PMMWSLE, **PPMMWSLE;

#endif //_INCLUDED
#endif//_H_INCLUDED
