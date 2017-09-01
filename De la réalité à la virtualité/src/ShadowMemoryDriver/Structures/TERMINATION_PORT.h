/* 
Copyright (c) FRET.  All rights reserved.

File Name : TERMINATION_PORT.h

Abstract:
Termination Port structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _TERMINATION_PORT_H_INCLUDED
#define _TERMINATION_PORT_H_INCLUDED

#ifndef TERMINATION_PORT_INCLUDED
#define TERMINATION_PORT_INCLUDED

typedef struct _TERMINATION_PORT
{
	struct _TERMINATION_PORT *	Next;		//+0x000
	PVOID	Port;							//+0x004
} TERMINATION_PORT, *PTERMINATION_PORT, **PPTERMINATION_PORT;


#endif //_INCLUDED
#endif //_H_INCLUDED
