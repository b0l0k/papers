/* 
Copyright (c) FRET.  All rights reserved.

File Name : KSEMAPHORE.h

Abstract:
Kernel Semaphore Object structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _KSEMAPHORE_H_INCLUDED
#define _KSEMAPHORE_H_INCLUDED

#include "DISPATCHER_HEADER.h"

#ifndef KSEMAPHORE_INCLUDED
#define KSEMAPHORE_INCLUDED
#ifndef _NTDDK_

typedef struct _KSEMAPHORE
{
	DISPATCHER_HEADER	Header;		//+0x000
	LONG				Limit;		//+0x010
} KSEMAPHORE, *PKSEMAPHORE, **PPKSEMAPHORE;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
