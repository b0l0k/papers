/* 
Copyright (c) FRET.  All rights reserved.

File Name : SERVICE_DESCRIPTOR_TABLE.h

Abstract:
Service Descriptor Table (SDT) structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 02
Last Update : 3-Sep-2006 
*/

#ifndef _SERVICE_DESCRIPTOR_TABLE_H_INCLUDED
#define _SERVICE_DESCRIPTOR_TABLE_H_INCLUDED

#include "SYSTEM_SERVICE_TABLE.h"

#ifndef SERVICE_DESCRIPTOR_TABLE_INCLUDED
#define SERVICE_DESCRIPTOR_TABLE_INCLUDED

//Comments grabbed from MS Windows Internals, 4th ed - Mark E. Russinovich, David A. Solomon.
//See this book for further details for the differences beetween KeServiceDescriptorTable and KeServiceDescriptorTableShadow.

typedef struct _SERVICE_DESCRIPTOR_TABLE
{
	SYSTEM_SERVICE_TABLE	Ntoskrnl;	// main native API table [ntoskrnl.exe]
	SYSTEM_SERVICE_TABLE	Win32k;		// win subsystem [win32k.sys], only in shadow table (KeServiceDescriptorTableShadow). A call to a GUI function must has been made.
	SYSTEM_SERVICE_TABLE	Spud;		// IIS Spud Driver [namely "spud.sys"], only in shadow table, IIS must be installed.
	SYSTEM_SERVICE_TABLE	Unused;		// Unused
} SERVICE_DESCRIPTOR_TABLE, *PSERVICE_DESCRIPTOR_TABLE, **PPSERVICE_DESCRIPTOR_TABLE;

//define KeServiceDescriptorTable (exported by Ntoskrnl) as a pointer to SDT.
extern PSERVICE_DESCRIPTOR_TABLE KeServiceDescriptorTable;

//Define a simple way to call a function directly by its Service ID from SST.
#define SSTCALL(function) KeServiceDescriptorTable->Ntoskrnl.ServiceTable[function]

#endif //_INCLUDED
#endif //H_INCLUDED