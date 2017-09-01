/* 
 Copyright (c) FRET.  All rights reserved.

File Name : OBJECT_NAME_INFORMATION.h

Abstract:
Object Name information structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 23-Aug-2006 
*/

#ifndef _OBJECT_NAME_INFORMATION_H_INCLUDED
#define _OBJECT_NAME_INFORMATION_H_INCLUDED

#include "UNICODE_STRING.h"

#ifndef OBJECT_NAME_INFORMATION_INCLUDED
#define OBJECT_NAME_INFORMATION_INCLUDED
#ifndef _NTDDK_

typedef struct _OBJECT_NAME_INFORMATION
{
	UNICODE_STRING	Name;		//+0x000
} OBJECT_NAME_INFORMATION, *POBJECT_NAME_INFORMATION, **PPOBJECT_NAME_INFORMATION;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
