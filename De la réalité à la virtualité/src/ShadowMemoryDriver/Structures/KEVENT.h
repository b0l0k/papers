/* 
Copyright (c) FRET.  All rights reserved.

File Name : KEVENT.h

Abstract:
Kernel Event Object structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _KEVENT_H_INCLUDED
#define _KEVENT_H_INCLUDED

#include "DISPATCHER_HEADER.h"


#ifndef KEVENT_INCLUDED
#define KEVENT_INCLUDED
#ifndef _NTDDK_

typedef struct _KEVENT
{
	DISPATCHER_HEADER	Header;		//+0x000
} KEVENT, *PKEVENT, **PPKEVENT;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
