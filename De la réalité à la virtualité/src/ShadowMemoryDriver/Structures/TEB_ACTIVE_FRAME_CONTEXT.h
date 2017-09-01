/* 
 Copyright (c) FRET.  All rights reserved.

File Name : TEB_ACTIVE_FRAME_CONTEXT.h

Abstract:
Thread Environment Block Active Frame Context structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 23-Aug-2006 
*/

#ifndef _TEB_ACTIVE_FRAME_CONTEXT_H_INCLUDED
#define _TEB_ACTIVE_FRAME_CONTEXT_H_INCLUDED

#ifndef TEB_ACTIVE_FRAME_CONTEXT_INCLUDED
#define TEB_ACTIVE_FRAME_CONTEXT_INCLUDED

typedef struct _TEB_ACTIVE_FRAME_CONTEXT
{
	ULONG	Flags;		//+0x000
	PCHAR	FrameName;	//+0x004
} TEB_ACTIVE_FRAME_CONTEXT, *PTEB_ACTIVE_FRAME_CONTEXT, **PPTEB_ACTIVE_FRAME_CONTEXT;

#endif //_INCLUDED
#endif//_H_INCLUDED
