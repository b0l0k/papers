/* 
Copyright (c) FRET.  All rights reserved.

File Name : _KEXECUTE_OPTIONS.h

Abstract:
Kernel Execute Options structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _KEXECUTE_OPTIONS_H_INCLUDED
#define _KEXECUTE_OPTIONS_H_INCLUDED

#ifndef KEXECUTE_OPTIONS_INCLUDED
#define KEXECUTE_OPTIONS_INCLUDED

// <size 0x1>
typedef struct _KEXECUTE_OPTIONS
{
	UCHAR 	ExecuteDisable : 1;			//0, +0x000
	UCHAR 	ExecuteEnable : 1;			//1, +0x000
	UCHAR 	DisableThunkEmulation : 1;	//2, +0x000
	UCHAR 	Permanent : 1;				//3, +0x000
	UCHAR 	ExecuteDispatchEnable : 1;	//4, +0x000
	UCHAR 	ImageDispatchEnable : 1;	//5, +0x000
	UCHAR 	Spare : 2;					//6, +0x000
} KEXECUTE_OPTIONS, *PKEXECUTE_OPTIONS, **PPKEXECUTE_OPTIONS;

#endif //_INCLUDED
#endif //_H_INCLUDED
