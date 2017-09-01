/* 
 Copyright (c) FRET.  All rights reserved.

File Name : CURDIR.h

Abstract:
Current Directory structure

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 23-Aug-2006 
*/

#ifndef _CURDIR_H_INCLUDED
#define _CURDIR_H_INCLUDED

#include "UNICODE_STRING.h"

#ifndef CURDIR_INCLUDED
#define CURDIR_INCLUDED

typedef struct _CURDIR
{
	UNICODE_STRING	DosPath;	//+0x000
	PVOID			Handle;		//+0x008
} CURDIR, *PCURDIR, **PPCURDIR;

#endif //_INCLUDED
#endif //_H_INCLUDED
