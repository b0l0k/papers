/* 
Copyright (c) FRET.  All rights reserved.

File Name : EPROCESS_QUOTA_ENTRY.h

Abstract:
 Executive Process Quota Entry structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 26-Aug-2006 
*/

#ifndef _EPROCESS_QUOTA_ENTRY_H_INCLUDED
#define _EPROCESS_QUOTA_ENTRY_H_INCLUDED

#ifndef EPROCESS_QUOTA_ENTRY_INCLUDED
#define EPROCESS_QUOTA_ENTRY_INCLUDED

typedef struct _EPROCESS_QUOTA_ENTRY
{
	SIZE_T	Usage;		//+0x000
	SIZE_T	Limit;		//+0x004
	SIZE_T	Peak;		//+0x008
	SIZE_T	Return;		//+0x00c
} EPROCESS_QUOTA_ENTRY, *PEPROCESS_QUOTA_ENTRY, **PPEPROCESS_QUOTA_ENTRY;

#endif //_INCLUDED
#endif //_H_INCLUDED
