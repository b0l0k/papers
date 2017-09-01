/* 
Copyright (c) FRET.  All rights reserved.

File Name : SYSTEM_SERVICE_TABLE.h

Abstract:
System Service Table (SST) structure.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 02
Last Update : 3-Sep-2006 
*/

#ifndef _SYSTEM_SERVICE_TABLE_H_INCLUDED
#define _SYSTEM_SERVICE_TABLE_H_INCLUDED

#ifndef SYSTEM_SERVICE_TABLE_INCLUDED
#define SYSTEM_SERVICE_TABLE_INCLUDED

typedef struct _SYSTEM_SERVICE_TABLE
{
	 /*
	 * Pointer to an array of entry points to functions.
	 * This table contains pointers to service handler functions, 
	 * each function is indexed by its service ID.
	 */
	PULONG	ServiceTable;
	/*
	* Pointer to an array of usage counters.
	* This Table contains an array where each entry is the number of
	* time a service (function, indexed by its service ID) has been called.
	* /!\ Only for Checked Build /!\
	*/
	PULONG	CounterTable;
	/*
	* Number of services in the ServiceTable array.
	*/
	ULONG	ServiceLimit;
	/*
	* Pointer to an array of Number of Arguments needed by a Service.
	* This table contains an array where each entry is the number of arguments
	* needed by a Service function (each number of function arguments' is indexed 
	* by its Service ID).
	*/
	PCHAR	ArgumentTable;	
} SYSTEM_SERVICE_TABLE, *PSYSTEM_SERVICE_TABLE, **PPSYSTEM_SERVICE_TABLE;

#endif //_INCLUDED
#endif //_H_INCLUDED
