/* 
 Copyright (c) FRET.  All rights reserved.

File Name : UNICODE_STRING.h

Abstract:
Unicode String structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _UNICODE_STRING_H_INCLUDED
#define _UNICODE_STRING_H_INCLUDED

#ifndef UNICODE_STRING_INCLUDED
#define UNICODE_STRING_INCLUDED
#ifndef _NTDDK_

typedef struct _UNICODE_STRING
{
	USHORT	Length;			//+0x000
	USHORT	MaximumLength;	//+0x002
	PWSTR	Buffer;			//+0x004
} UNICODE_STRING, *PUNICODE_STRING, **PPUNICODE_STRING;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
