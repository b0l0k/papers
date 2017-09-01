/* 
 Copyright (c) FRET.  All rights reserved.

File Name : PEB_LDR_DATA.h

Abstract:
Process Environment Block Loader Data structure.
Process Environment Block Loader Data Table Entry structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 05
Last Update : 2-Sep-2006 
*/

#ifndef _PEB_LDR_DATA_H_INCLUDED
#define _PEB_LDR_DATA_H_INCLUDED

#include "LIST_ENTRY.h"
#include "UNICODE_STRING.h"

#ifndef PEB_LDR_DATA_INCLUDED
#define PEB_LDR_DATA_INCLUDED

typedef struct _PEB_LDR_DATA
{
	ULONG			Length;							//+0x000
	BOOLEAN			Initialized;					//+0x004
	PVOID			SsHandle;						//+0x008
	LIST_ENTRY		InLoadOrderModuleList;			//+0x00c
	LIST_ENTRY		InMemoryOrderModuleList;		//+0x014
	LIST_ENTRY		InInitializationOrderModuleList;//+0x01c
	PVOID			EntryInProgress;				//+0x024
} PEB_LDR_DATA, *PPEB_LDR_DATA, **PPPEB_LDR_DATA;

#endif //PEB_LDR_DATA_INCLUDED

//Loader Data Table Entry Flags 
#define LDRP_STATIC_LINK                        0x00000002
#define LDRP_IMAGE_DLL                          0x00000004
#define LDRP_LOAD_IN_PROGRESS                   0x00001000
#define LDRP_UNLOAD_IN_PROGRESS                 0x00002000
#define LDRP_ENTRY_PROCESSED                    0x00004000
#define LDRP_ENTRY_INSERTED                     0x00008000
#define LDRP_CURRENT_LOAD                       0x00010000
#define LDRP_FAILED_BUILTIN_LOAD                0x00020000
#define LDRP_DONT_CALL_FOR_THREADS              0x00040000
#define LDRP_PROCESS_ATTACH_CALLED              0x00080000
#define LDRP_DEBUG_SYMBOLS_LOADED               0x00100000
#define LDRP_IMAGE_NOT_AT_BASE                  0x00200000
#define LDRP_COR_IMAGE                          0x00400000
#define LDR_COR_OWNS_UNMAP                      0x00800000
#define LDRP_REDIRECTED                         0x10000000

#ifndef LDR_DATA_TABLE_ENTRY_INCLUDED
#define LDR_DATA_TABLE_ENTRY_INCLUDED

typedef struct _LDR_DATA_TABLE_ENTRY
{
	LIST_ENTRY		InLoadOrderLinks;					//+0x000
	LIST_ENTRY		InMemoryOrderModuleList;			//+0x008
	LIST_ENTRY		InInitializationOrderModuleList;	//+0x010
	PVOID			DllBase;							//+0x018
	PVOID			EntryPoint;							//+0x01c
	ULONG			SizeOfImage;						//+0x020
	UNICODE_STRING	 FullDllName;						//+0x024
	UNICODE_STRING	BaseDllName;						//+0x02c
	ULONG			Flags;								//+0x034
	USHORT			LoadCount;							//+0x038
	USHORT			TlsIndex;							//+0x03a
	union
	{
		LIST_ENTRY	HashLinks;						
		PVOID		SectionPointer;
	};		//+0x03c
	ULONG			Checksum;							//+0x040
	union 
	{
		ULONG		TimeDateStamp;
		PVOID		LoadedImports;
	};		//+0x044
	PVOID			EntryPointActivationContext;		//+0x048
	PVOID			PatchInformation;					//+0x04c
} LDR_DATA_TABLE_ENTRY, *PLDR_DATA_TABLE_ENTRY;

#endif //LDR_DATA_TABLE_ENTRY_INCLUDED
#endif //_H_INCLUDED

