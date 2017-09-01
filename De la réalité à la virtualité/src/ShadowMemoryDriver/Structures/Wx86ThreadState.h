/* 
 Copyright (c) FRET.  All rights reserved.

File Name : Wx86ThreadState.h

Abstract:
Wx86ThreadState structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 23-Aug-2006 
*/

#ifndef _Wx86ThreadState_H_INCLUDED
#define _Wx86ThreadState_H_INCLUDED

#ifndef Wx86ThreadState_INCLUDED
#define Wx86ThreadState_INCLUDED

typedef struct _Wx86ThreadState
{
	ULONG *	CallBx86Eip;		//+0x000
	PVOID	DeallocationCpu;	//+0x004
	UCHAR	UseKnownWx86Dll;	//+0x008
	CHAR	OleStubInvoked;		//+0x009
} Wx86ThreadState, *PWx86ThreadState, **PPWx86ThreadState;

#endif //_INCLUDED
#endif //_H_INCLUDED
