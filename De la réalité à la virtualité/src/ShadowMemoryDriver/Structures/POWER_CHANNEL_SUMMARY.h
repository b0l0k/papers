/* 
Copyright (c) FRET.  All rights reserved.

File Name : POWER_CHANNEL_SUMMARY.h

Abstract:
Power Channel Summary structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _POWER_CHANNEL_SUMMARY_H_INCLUDED
#define _POWER_CHANNEL_SUMMARY_H_INCLUDED

#include "LIST_ENTRY.h"

#ifndef POWER_CHANNEL_SUMMARY_INCLUDED
#define POWER_CHANNEL_SUMMARY_INCLUDED

typedef struct _POWER_CHANNEL_SUMMARY
{
	ULONG		Signature;		//+0x000
	ULONG		TotalCount;		//+0x004
	ULONG		D0Count;		//+0x008
	LIST_ENTRY	NotifyList;		//+0x00c
} POWER_CHANNEL_SUMMARY, *PPOWER_CHANNEL_SUMMARY, **PPPOWER_CHANNEL_SUMMARY;

#endif //_INCLUDED
#endif//_H_INCLUDED
