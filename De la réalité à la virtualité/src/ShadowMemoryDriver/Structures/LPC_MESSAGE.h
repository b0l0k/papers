/* 
Copyright (c) FRET.  All rights reserved.

File Name : LPC_MESSAGE.h

Abstract:
Local Procedure Call Message structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _LPC_MESSAGE_H_INCLUDED
#define _LPC_MESSAGE_H_INCLUDED

#include "CLIENT_ID.h"

#ifndef _LPC_MESSAGE_INCLUDED
#define _LPC_MESSAGE_INCLUDED

/* Types of LPC messages */
#define UNUSED_MSG_TYPE                 0
#define LPC_REQUEST                     1
#define LPC_REPLY                       2
#define LPC_DATAGRAM                    3
#define LPC_LOST_REPLY                  4
#define LPC_PORT_CLOSED                 5
#define LPC_CLIENT_DIED                 6
#define LPC_EXCEPTION                   7
#define LPC_DEBUG_EVENT                 8
#define LPC_ERROR_EVENT                 9
#define LPC_CONNECTION_REQUEST         10

// [from <ntdef.h>]
#ifndef ANYSIZE_ARRAY
#define ANYSIZE_ARRAY 1       // winnt
#endif

typedef struct _LPC_MESSAGE
{
	USHORT		DataSize;				//+0x000
	USHORT		MessageSize;			//+0x002
	USHORT		MessageType;			//+0x004
	USHORT		VirtualRangesOffset;	//+0x006
	CLIENT_ID	ClientId;				//+0x008
	ULONG		MessageId;				//+0x010
	ULONG		SectionSize;			//+0x014
	UCHAR		Data[ANYSIZE_ARRAY];	//+0x018
} LPC_MESSAGE, *PLPC_MESSAGE;

#endif //_H_INCLUDED
#endif //_INCLUDED