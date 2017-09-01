/* 
Copyright (c) FRET.  All rights reserved.

File Name : PS_IMPERSONATION_INFORMATION.h

Abstract:
Process Impersonation Information structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _PS_IMPERSONATION_INFORMATION_H_INCLUDED
#define _PS_IMPERSONATION_INFORMATION_H_INCLUDED

#include "SECURITY_IMPERSONATION_LEVEL.h"


#ifndef PS_IMPERSONATION_INFORMATION_INCLUDED
#define PS_IMPERSONATION_INFORMATION_INCLUDED

typedef struct _PS_IMPERSONATION_INFORMATION
{
	PVOID							Token;				//+0x000
	UCHAR							CopyOnOpen;			//+0x004
	UCHAR							EffectiveOnly;		//+0x005
	SECURITY_IMPERSONATION_LEVEL	ImpersonationLevel;	//+0x008
} PS_IMPERSONATION_INFORMATION, *PPS_IMPERSONATION_INFORMATION, **PPPS_IMPERSONATION_INFORMATION;

#endif //_INCLUDED
#endif //_H_INCLUDED
