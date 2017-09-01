#ifndef PROCESS_H
#define PROCESS_H

#include <ntddk.h>

#include "Error.h"
#include "PageFaultHandler.h"
#include "./Structures/EPROCESS.h"

#define PROCESS_PAGE_DIR_BASE                  0xC0300000
#define PROCESS_PAGE_TABLE_BASE                0xC0000000

PEPROCESS MyProcess;

PMDL pMDLProtectedPage;
PMDL pMDLPageReadWrite;
PMDL pMDLPageExecute;

VOID KeAttachProcess(PEPROCESS);
VOID KeDetachProcess();

PEPROCESS FindEprocessByName(PUCHAR MyName);

ULONG* GetPteAddress( PVOID VirtualAddress );
VOID MarkPagePresent( ULONG* pPte );
VOID MarkPageNotPresent( ULONG* pPte );

PVOID FindRetInPage( PVOID VirtualAddress );

ULONG SetProtectedPage( PUCHAR NameProcess, PVOID ProtectedPage, PVOID PageReadWrite, PVOID PageExecute);
VOID UnSetProtectedPage();

#endif


