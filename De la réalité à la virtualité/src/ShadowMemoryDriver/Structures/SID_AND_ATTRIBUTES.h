/* 
Copyright (c) FRET.  All rights reserved.

File Name : SID_AND_ATTRIBUTES.h

Abstract:
Security Identifier And Attributes structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 3-Sep-2006 
*/

#ifndef _SID_AND_ATTRIBUTES_H_INCLUDED
#define _SID_AND_ATTRIBUTES_H_INCLUDED

#ifndef SID_AND_ATTRIBUTES_INCLUDED
#define SID_AND_ATTRIBUTES_INCLUDED

typedef struct _SID_AND_ATTRIBUTES
{
	PVOID	Sid;			//+0x000
	ULONG	Attributes;		//+0x004
} SID_AND_ATTRIBUTES, *PSID_AND_ATTRIBUTES, **PPSID_AND_ATTRIBUTES;

#endif //_INCLUDED
#endif//_H_INCLUDED
