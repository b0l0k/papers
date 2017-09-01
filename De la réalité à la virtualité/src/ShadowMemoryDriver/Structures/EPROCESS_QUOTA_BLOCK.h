/* 
Copyright (c) FRET.  All rights reserved.

File Name : EPROCESS_QUOTA_BLOCK.h

Abstract:
 Executive Process Quota Block structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 26-Aug-2006 
*/

#ifndef _EPROCESS_QUOTA_BLOCK_H_INCLUDED
#define _EPROCESS_QUOTA_BLOCK_H_INCLUDED

#include "EPROCESS_QUOTA_ENTRY.h"
#include "LIST_ENTRY.h"

#ifndef EPROCESS_QUOTA_BLOCK_INCLUDED
#define EPROCESS_QUOTA_BLOCK_INCLUDED

typedef struct _EPROCESS_QUOTA_BLOCK
{
	EPROCESS_QUOTA_ENTRY	QuotaEntry [3];		//+0x000
	LIST_ENTRY				QuotaList;			//+0x030
	ULONG					ReferenceCount;		//+0x038
	ULONG					ProcessCount;		//+0x03c
} EPROCESS_QUOTA_BLOCK, *PEPROCESS_QUOTA_BLOCK, **PPEPROCESS_QUOTA_BLOCK;

#endif //_INCLUDED
#endif //_H_INCLUDED
