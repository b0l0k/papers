/* 
Copyright (c) FRET.  All rights reserved.

File Name : EX_PUSH_LOCK.h

Abstract:
Ex Push Lock structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _EX_PUSH_LOCK_H_INCLUDED
#define _EX_PUSH_LOCK_H_INCLUDED

#ifndef EX_PUSH_LOCK_INCLUDED
#define EX_PUSH_LOCK_INCLUDED

typedef struct _EX_PUSH_LOCK
{
	union
	{
		struct
		{
			ULONG_PTR Waiting:1;	//0, +0x000
			ULONG_PTR Exclusive:1;	//1, +0x000
			ULONG_PTR Shared:30;		//2, +0x000
		};
		ULONG Value;				//+0x000
		PVOID Ptr;					//+0x000
	};
} EX_PUSH_LOCK, *PEX_PUSH_LOCK, **PPEX_PUSH_LOCK;

#endif //_INCLUDED
#endif //_H_INCLUDED
