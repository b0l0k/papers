/* 
 Copyright (c) FRET.  All rights reserved.

File Name : RTL_DRIVE_LETTER_CURDIR.h

Abstract:
Runtime Library Drive Letter Current Directory structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 23-Aug-2006 
*/

#ifndef _RTL_DRIVE_LETTER_CURDIR_H_INCLUDED
#define _RTL_DRIVE_LETTER_CURDIR_H_INCLUDED

#include "STRING.h"

#ifndef RTL_DRIVE_LETTER_CURDIR_INCLUDED
#define RTL_DRIVE_LETTER_CURDIR_INCLUDED

typedef struct _RTL_DRIVE_LETTER_CURDIR
{
	USHORT	Flags;			//+0x000
	USHORT	Length;			//+0x002
	ULONG	TimeStamp;		//+0x004
	STRING	DosPath;		//+0x008
} RTL_DRIVE_LETTER_CURDIR, *PRTL_DRIVE_LETTER_CURDIR, **PPRTL_DRIVE_LETTER_CURDIR;

#endif //_INCLUDED
#endif //_H_INCLUDED
