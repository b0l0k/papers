/* 
 Copyright (c) FRET.  All rights reserved.

File Name : ACTIVATION_CONTEXT_STACK.h

Abstract:
Activation Context Stack structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 1-Sep-2006 
*/

#ifndef _ACTIVATION_CONTEXT_STACK_H_INCLUDED
#define _ACTIVATION_CONTEXT_STACK_H_INCLUDED

#include "LIST_ENTRY.h"

#ifndef ACTIVATION_CONTEXT_STACK_INCLUDED
#define ACTIVATION_CONTEXT_STACK_INCLUDED

typedef struct _ACTIVATION_CONTEXT_STACK
{
	ULONG		Flags;							//+0x000
	ULONG		NextCookieSequenceNumber;		//+0x004
	PVOID		ActiveFrame;					//+0x008
	LIST_ENTRY	FrameListCache;					//+0x00c
} ACTIVATION_CONTEXT_STACK, *PACTIVATION_CONTEXT_STACK, **PPACTIVATION_CONTEXT_STACK;

#endif //_INCLUDED
#endif //_H_INCLUDED
