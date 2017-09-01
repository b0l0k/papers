/* 
Copyright (c) FRET.  All rights reserved.

File Name : IO_TIMER.h

Abstract:
Input/Output Timer structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _IO_TIMER_H_INCLUDED
#define _IO_TIMER_H_INCLUDED

#include "LIST_ENTRY.h"
#include "DEVICE_OBJECT.h"

#ifndef IO_TIMER_INCLUDED
#define IO_TIMER_INCLUDED

#ifndef DDKAPI
#define DDKAPI __stdcall
#endif

#ifndef _NTDDK_
typedef VOID(DDKAPI * PIO_TIMER_ROUTINE)(IN struct _DEVICE_OBJECT *DeviceObject, IN PVOID Context)
#endif

// <size 0x18>
typedef struct _IO_TIMER
{
	SHORT				Type;			//+0x000
	SHORT				TimerFlag;		//+0x002
	LIST_ENTRY			TimerList;		//+0x004
	PIO_TIMER_ROUTINE	TimerRoutine;	//+0x00c
	PVOID				Context;		//+0x010
	PDEVICE_OBJECT		DeviceObject;	//+0x014
} IO_TIMER, *PIO_TIMER, **PPIO_TIMER;

#endif //_INCLUDED
#endif//_H_INCLUDED
