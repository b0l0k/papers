/* 
 Copyright (c) FRET.  All rights reserved.

File Name : CLIENT_ID.h

Abstract:
Client ID structure

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 05
Last Update : 29-Aug-2006 
*/

#ifndef _CLIENT_ID_H_INCLUDED
#define _CLIENT_ID_H_INCLUDED

#ifndef CLIENT_ID_INCLUDED
#define CLIENT_ID_INCLUDED
#ifndef _NTDDK_

typedef struct _CLIENT_ID
{
	PVOID	UniqueProcess;		//+0x000
	PVOID	UniqueThread;		//+0x004
} CLIENT_ID, *PCLIENT_ID, **PPCLIENT_ID;

#endif // _NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
