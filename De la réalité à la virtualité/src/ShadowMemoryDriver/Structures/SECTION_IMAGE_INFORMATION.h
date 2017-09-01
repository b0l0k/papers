/* 
Copyright (c) FRET.  All rights reserved.

File Name : SECTION_IMAGE_INFORMATION.h

Abstract:
Section Image Information structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _SECTION_IMAGE_INFORMATION_H_INCLUDED
#define _SECTION_IMAGE_INFORMATION_H_INCLUDED

#ifndef SECTION_IMAGE_INFORMATION_INCLUDED
#define SECTION_IMAGE_INFORMATION_INCLUDED

typedef struct _SECTION_IMAGE_INFORMATION
{
	PVOID	TransferAddress;		//+0x000
	ULONG	ZeroBits;				//+0x004
	ULONG	MaximumStackSize;		//+0x008
	ULONG	CommittedStackSize;		//+0x00c
	ULONG	SubSystemType;			//+0x010
	USHORT	SubSystemMinorVersion;	//+0x014
	USHORT	SubSystemMajorVersion;	//+0x016
	ULONG	SubSystemVersion;		//+0x014
	ULONG	GpValue;				//+0x018
	USHORT	ImageCharacteristics;	//+0x01c
	USHORT	DllCharacteristics;		//+0x01e
	USHORT	Machine;				//+0x020
	UCHAR	ImageContainsCode;		//+0x022
	UCHAR	Spare1;					//+0x023
	ULONG	LoaderFlags;			//+0x024
	ULONG	ImageFileSize;			//+0x028
	ULONG	Reserved [1];			//+0x02c
} SECTION_IMAGE_INFORMATION, *PSECTION_IMAGE_INFORMATION, **PPSECTION_IMAGE_INFORMATION;

#endif //_INCLUDED
#endif//_H_INCLUDED
