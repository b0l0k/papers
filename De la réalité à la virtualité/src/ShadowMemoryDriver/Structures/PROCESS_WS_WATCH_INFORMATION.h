/* 
Copyright (c) FRET.  All rights reserved.

File Name : PROCESS_WS_WATCH_INFORMATION.h

Abstract:
Process Working Set Watch Information structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _PROCESS_WS_WATCH_INFORMATION_H_INCLUDED
#define _PROCESS_WS_WATCH_INFORMATION_H_INCLUDED

#ifndef PROCESS_WS_WATCH_INFORMATION_INCLUDED
#define PROCESS_WS_WATCH_INFORMATION_INCLUDED
#ifndef _NTDDK_

typedef struct _PROCESS_WS_WATCH_INFORMATION
{
	PVOID	FaultingPc;		//+0x000
	PVOID	FaultingVa;		//+0x004
} PROCESS_WS_WATCH_INFORMATION, *PPROCESS_WS_WATCH_INFORMATION, **PPPROCESS_WS_WATCH_INFORMATION;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
