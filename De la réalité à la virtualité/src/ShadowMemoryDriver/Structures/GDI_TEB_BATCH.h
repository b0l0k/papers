/* 
 Copyright (c) FRET.  All rights reserved.

File Name : GDI_TEB_BATCH.h

Abstract:
GDI TEB BATCH structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 23-Aug-2006 
*/

#ifndef _GDI_TEB_BATCH_H_INCLUDED
#define _GDI_TEB_BATCH_H_INCLUDED

#ifndef GDI_TEB_BATCH_INCLUDED
#define GDI_TEB_BATCH_INCLUDED

// <size 0x4e0>
typedef struct _GDI_TEB_BATCH
{
	ULONG	Offset;		//+0x000
	ULONG	HDC;		//+0x004
	ULONG	Buffer [310];		//+0x008
} GDI_TEB_BATCH, *PGDI_TEB_BATCH, **PPGDI_TEB_BATCH;

#endif //_INCLUDED
#endif //_H_INCLUDED
