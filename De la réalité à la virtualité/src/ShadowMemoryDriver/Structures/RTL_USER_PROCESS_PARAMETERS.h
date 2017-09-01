/* 
 Copyright (c) FRET.  All rights reserved.

File Name : RTL_USER_PROCESS_PARAMETERS.h

Abstract:
Runtime Library User Process Parameters structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 23-Aug-2006 
*/

#ifndef _RTL_USER_PROCESS_PARAMETERS_H_INCLUDED
#define _RTL_USER_PROCESS_PARAMETERS_H_INCLUDED

#include "CURDIR.h"
#include "UNICODE_STRING.h"
#include "RTL_DRIVE_LETTER_CURDIR.h"

#ifndef RTL_USER_PROCESS_PARAMETERS_INCLUDED
#define RTL_USER_PROCESS_PARAMETERS_INCLUDED

// <size 0x290>
typedef struct _RTL_USER_PROCESS_PARAMETERS
{
	ULONG	MaximumLength;			//+0x000
	ULONG	Length;					//+0x004
	ULONG	Flags;					//+0x008
	ULONG	DebugFlags;				//+0x00c
	PVOID	ConsoleHandle;			//+0x010
	ULONG	ConsoleFlags;			//+0x014
	PVOID	StandardInput;			//+0x018
	PVOID	StandardOutput;			//+0x01c
	PVOID	StandardError;			//+0x020
	CURDIR	CurrentDirectory;		//+0x024
	UNICODE_STRING	DllPath;		//+0x030
	UNICODE_STRING	ImagePathName;	//+0x038
	UNICODE_STRING	CommandLine;	//+0x040
	PVOID	Environment;			//+0x048
	ULONG	StartingX;				//+0x04c
	ULONG	StartingY;				//+0x050
	ULONG	CountX;					//+0x054
	ULONG	CountY;					//+0x058
	ULONG	CountCHARsX;			//+0x05c
	ULONG	CountCHARsY;			//+0x060
	ULONG	FillAttribute;			//+0x064
	ULONG	WindowFlags;			//+0x068
	ULONG	ShowWindowFlags;		//+0x06c
	UNICODE_STRING	WindowTitle;	//+0x070
	UNICODE_STRING	DesktopInfo;	//+0x078
	UNICODE_STRING	ShellInfo;		//+0x080
	UNICODE_STRING	RuntimeData;	//+0x088
	RTL_DRIVE_LETTER_CURDIR	CurrentDirectores [32];	//+0x090
} RTL_USER_PROCESS_PARAMETERS, *PRTL_USER_PROCESS_PARAMETERS, **PPRTL_USER_PROCESS_PARAMETERS;

#endif //_INCLUDED
#endif //_H_INCLUDED
