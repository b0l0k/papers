/* 
Copyright (c) FRET.  All rights reserved.

File Name : MMPTE.h

Abstract:
Memory Manager Page Table Entry structure.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

//doc : http://www.eas.asu.edu/~cse532/old%20stuff/Page_Fault_Handling_mod.ppt

#ifndef _MMPTE_H_INCLUDED
#define _MMPTE_H_INCLUDED

#include "HARDWARE_PTE.h"
#include "MMPTE_HARDWARE.h"
#include "MMPTE_PROTOTYPE.h"
#include "MMPTE_SOFTWARE.h"
#include "MMPTE_TRANSITION.h"
#include "MMPTE_SUBSECTION.h"
#include "MMPTE_LIST.h"

#ifndef MMPTE_INCLUDED
#define MMPTE_INCLUDED

// <size 0x4>
typedef struct _MMPTE
{
	union	{
		ULONG				Long;
		HARDWARE_PTE		Flush;
		MMPTE_HARDWARE		Hard;
		MMPTE_PROTOTYPE		Proto;
		MMPTE_SOFTWARE		Soft;
		MMPTE_TRANSITION	Trans;
		MMPTE_SUBSECTION	Subsect;
		MMPTE_LIST			List;
	};//+0x000
} MMPTE, *PMMPTE, **PPMMPTE;

#endif //_INCLUDED
#endif//_H_INCLUDED
