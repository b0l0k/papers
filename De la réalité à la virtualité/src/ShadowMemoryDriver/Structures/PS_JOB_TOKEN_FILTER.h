/* 
Copyright (c) FRET.  All rights reserved.

File Name : PS_JOB_TOKEN_FILTER.h

Abstract:
Process Job Token Filter structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _PS_JOB_TOKEN_FILTER_H_INCLUDED
#define _PS_JOB_TOKEN_FILTER_H_INCLUDED

#include "SID_AND_ATTRIBUTES.h"
#include "LUID_AND_ATTRIBUTES.h"

#ifndef PS_JOB_TOKEN_FILTER_INCLUDED
#define PS_JOB_TOKEN_FILTER_INCLUDED

typedef struct _PS_JOB_TOKEN_FILTER
{
	ULONG				CapturedSidCount;			//+0x000
	PSID_AND_ATTRIBUTES	CapturedSids;				//+0x004
	ULONG				CapturedSidsLength;			//+0x008
	ULONG				CapturedGroupCount;			//+0x00c
	PSID_AND_ATTRIBUTES	CapturedGroups;				//+0x010
	ULONG				CapturedGroupsLength;		//+0x014
	ULONG				CapturedPrivilegeCount;		//+0x018
	PLUID_AND_ATTRIBUTES	CapturedPrivileges;		//+0x01c
	ULONG				CapturedPrivilegesLength;	//+0x020
} PS_JOB_TOKEN_FILTER, *PPS_JOB_TOKEN_FILTER, **PPPS_JOB_TOKEN_FILTER;

#endif //_INCLUDED
#endif//_H_INCLUDED
