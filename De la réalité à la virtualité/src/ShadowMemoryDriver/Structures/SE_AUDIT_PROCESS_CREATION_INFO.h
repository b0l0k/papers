/* 
Copyright (c) FRET.  All rights reserved.

File Name : SE_AUDIT_PROCESS_CREATION_INFO.h

Abstract:
Security Manager Audit Process Creation Info structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _SE_AUDIT_PROCESS_CREATION_INFO_H_INCLUDED
#define _SE_AUDIT_PROCESS_CREATION_INFO_H_INCLUDED

#include "OBJECT_NAME_INFORMATION.h"

#ifndef SE_AUDIT_PROCESS_CREATION_INFO_INCLUDED
#define SE_AUDIT_PROCESS_CREATION_INFO_INCLUDED

typedef struct _SE_AUDIT_PROCESS_CREATION_INFO
{
	POBJECT_NAME_INFORMATION	ImageFileName;		//+0x000
} SE_AUDIT_PROCESS_CREATION_INFO, *PSE_AUDIT_PROCESS_CREATION_INFO, **PPSE_AUDIT_PROCESS_CREATION_INFO;

#endif //_INCLUDED
#endif //_H_INCLUDED
