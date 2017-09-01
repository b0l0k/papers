/* 
 Copyright (c) FRET.  All rights reserved.

File Name : STRING.h

Abstract:
String structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 23-Aug-2006 
*/

#ifndef _STRING_H_INCLUDED
#define _STRING_H_INCLUDED

#ifndef STRING_INCLUDED
#define STRING_INCLUDED
#ifndef _NTDDK_

typedef struct _STRING
{
	USHORT	Length;			//+0x000
	USHORT	MaximumLength;	//+0x002
	PCHAR	Buffer;			//+0x004
} STRING, *PSTRING, **PPSTRING;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
