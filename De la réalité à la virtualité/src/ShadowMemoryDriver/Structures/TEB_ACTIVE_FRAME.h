/* 
 Copyright (c) FRET.  All rights reserved.

File Name : TEB_ACTIVE_FRAME.h

Abstract:
Thread Environment Block Active Frame structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 23-Aug-2006 
*/

#ifndef _TEB_ACTIVE_FRAME_H_INCLUDED
#define _TEB_ACTIVE_FRAME_H_INCLUDED

#include "TEB_ACTIVE_FRAME_CONTEXT.h"

#ifndef TEB_ACTIVE_FRAME_INCLUDED
#define TEB_ACTIVE_FRAME_INCLUDED

typedef struct _TEB_ACTIVE_FRAME
{
	ULONG	Flags;							//+0x000
	struct _TEB_ACTIVE_FRAME *	Previous;	//+0x004
	PTEB_ACTIVE_FRAME_CONTEXT	Context;	//+0x008
} TEB_ACTIVE_FRAME, *PTEB_ACTIVE_FRAME, **PPTEB_ACTIVE_FRAME;

#endif //_INCLUDED
#endif //_H_INCLUDED
