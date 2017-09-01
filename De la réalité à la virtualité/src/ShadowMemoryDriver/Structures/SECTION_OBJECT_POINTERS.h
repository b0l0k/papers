/* 
Copyright (c) FRET.  All rights reserved.

File Name : SECTION_OBJECT_POINTERS.h

Abstract:
Section Object Pointers structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _SECTION_OBJECT_POINTERS_H_INCLUDED
#define _SECTION_OBJECT_POINTERS_H_INCLUDED

#ifndef SECTION_OBJECT_POINTERS_INCLUDED
#define SECTION_OBJECT_POINTERS_INCLUDED
#ifndef _NTDDK_

typedef struct _SECTION_OBJECT_POINTERS
{
	PVOID	DataSectionObject;		//+0x000
	PVOID	SharedCacheMap;			//+0x004
	PVOID	ImageSectionObject;		//+0x008
} SECTION_OBJECT_POINTERS, *PSECTION_OBJECT_POINTERS, **PPSECTION_OBJECT_POINTERS;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
