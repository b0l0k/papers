/* 
Copyright (c) FRET.  All rights reserved.

File Name : IO_CLIENT_EXTENSION.h

Abstract:
Input/Ouput Client Extension structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _IO_CLIENT_EXTENSION_H_INCLUDED
#define _IO_CLIENT_EXTENSION_H_INCLUDED

#ifndef IO_CLIENT_EXTENSION_INCLUDED
#define IO_CLIENT_EXTENSION_INCLUDED

// <size 0x8>
typedef struct _IO_CLIENT_EXTENSION
{
	struct _IO_CLIENT_EXTENSION *	NextExtension;		//+0x000
	PVOID	ClientIdentificationAddress;		//+0x004
} IO_CLIENT_EXTENSION, *PIO_CLIENT_EXTENSION, **PPIO_CLIENT_EXTENSION;

#endif //_INCLUDED
#endif //_H_INCLUDED
