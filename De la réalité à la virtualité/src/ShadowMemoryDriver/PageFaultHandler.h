#ifndef PAGEFAULTHANDLER_H
#define PAGEFAULTHANDLER_H

#include <ntddk.h>

ULONG Cr3Process;			//Cr3 du processus contenant la page � filtrer

PVOID pProtectedPage;		//Adresse dans la page filtr�

ULONG* pPteProtectedPage;		//Pointeur sur le PTE de notre page filtr�

ULONG PtePageReadWrite;		//PTE � mettre en cas de tentative de lecture/ecrite dans la page filtr�
ULONG PtePageExecute;		//PTE � mettre en cas de tentative d'execution dans la page filtr�

PVOID pRetInProtectedPage;	//Adresse d'un ret dans la page � filtrer

ULONG OldPageFaultHandler;

void NewInt0E( void );

#endif


