/* 
 Copyright (c) FRET.  All rights reserved.

File Name : PEB_FREE_BLOCK.h

Abstract:
PEB Free Block structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 23-Aug-2006 
*/

#ifndef _PEB_FREE_BLOCK_H_INCLUDED
#define _PEB_FREE_BLOCK_H_INCLUDED

#ifndef PEB_FREE_BLOCK_INCLUDED
#define PEB_FREE_BLOCK_INCLUDED

typedef struct _PEB_FREE_BLOCK
{
	struct _PEB_FREE_BLOCK *	Next;		//+0x000
	ULONG						Size;		//+0x004
} PEB_FREE_BLOCK, *PPEB_FREE_BLOCK, **PPPEB_FREE_BLOCK;

#endif //_INCLUDED
#endif //_H_INCLUDED
