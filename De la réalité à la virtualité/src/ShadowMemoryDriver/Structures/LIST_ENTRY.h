/* 
 Copyright (c) FRET.  All rights reserved.

File Name : LIST_ENTRY.h

Abstract:
List Entry structure. Define a double linked list.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 28-Aug-2006 
*/

#ifndef _LIST_ENTRY_H_INCLUDED
#define _LIST_ENTRY_H_INCLUDED

#ifndef LIST_ENTRY_INCLUDED
#define LIST_ENTRY_INCLUDED
#if !defined( _NTDDK_ ) && !defined( _WINNT_ )

typedef struct _LIST_ENTRY
{
	PLIST_ENTRY	Flink;		//+0x000
	PLIST_ENTRY	Blink;		//+0x004
} LIST_ENTRY, *PLIST_ENTRY, **PPLIST_ENTRY;

#endif //_WINNT_ && _NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
