#ifndef PAGEFAULTHANDLER_H
#define PAGEFAULTHANDLER_H

#include <ntddk.h>

ULONG Cr3Process;			//Cr3 du processus contenant la page à filtrer

PVOID pProtectedPage;		//Adresse dans la page filtré

ULONG* pPteProtectedPage;		//Pointeur sur le PTE de notre page filtré

ULONG PtePageReadWrite;		//PTE à mettre en cas de tentative de lecture/ecrite dans la page filtré
ULONG PtePageExecute;		//PTE à mettre en cas de tentative d'execution dans la page filtré

PVOID pRetInProtectedPage;	//Adresse d'un ret dans la page à filtrer

ULONG OldPageFaultHandler;

void NewInt0E( void );

#endif


