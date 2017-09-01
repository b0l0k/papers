/* 
Copyright (c) FRET.  All rights reserved.

File Name : OBJECT_DIRECTORY_ENTRY.h

Abstract:
Object Directory Entry structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _OBJECT_DIRECTORY_ENTRY_H_INCLUDED
#define _OBJECT_DIRECTORY_ENTRY_H_INCLUDED

#ifndef OBJECT_DIRECTORY_ENTRY_INCLUDED
#define OBJECT_DIRECTORY_ENTRY_INCLUDED

typedef struct _OBJECT_DIRECTORY_ENTRY
{
	struct _OBJECT_DIRECTORY_ENTRY *	ChainLink;		//+0x000
	PVOID	Object;										//+0x004
} OBJECT_DIRECTORY_ENTRY, *POBJECT_DIRECTORY_ENTRY, **PPOBJECT_DIRECTORY_ENTRY;

#endif //_INCLUDED
#endif //_H_INCLUDED
