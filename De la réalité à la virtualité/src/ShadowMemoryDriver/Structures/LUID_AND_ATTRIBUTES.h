/* 
Copyright (c) FRET.  All rights reserved.

File Name : LUID_AND_ATTRIBUTES.h

Abstract:
Locally Unique Identifier And Attributes structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 05
Last Update : 2-Sep-2006 
*/

#ifndef _LUID_AND_ATTRIBUTES_H_INCLUDED
#define _LUID_AND_ATTRIBUTES_H_INCLUDED

#include "LUID.h"

#ifndef LUID_AND_ATTRIBUTES_INCLUDED
#define LUID_AND_ATTRIBUTES_INCLUDED
#ifndef _NTDDK_

#include <pshpack4.h> // 4 byte packing
typedef struct _LUID_AND_ATTRIBUTES
{
	LUID	Luid;			//+0x000
	ULONG	Attributes;		//+0x008
} LUID_AND_ATTRIBUTES, *PLUID_AND_ATTRIBUTES, **PPLUID_AND_ATTRIBUTES;

#ifndef ANYSIZE_ARRAY
#define ANYSIZE_ARRAY 1       // winnt
#endif

typedef LUID_AND_ATTRIBUTES LUID_AND_ATTRIBUTES_ARRAY[ANYSIZE_ARRAY];
typedef LUID_AND_ATTRIBUTES_ARRAY *PLUID_AND_ATTRIBUTES_ARRAY;

#include <poppack.h>

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
