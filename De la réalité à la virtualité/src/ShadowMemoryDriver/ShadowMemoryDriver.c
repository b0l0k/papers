#include <ntddk.h>

#include "PageFaultHandler.h"
#include "Interrupt.h"
#include "Process.h"


PMDL PageDriver;


VOID OnUnload( PDRIVER_OBJECT DriverObject )
{	
	MmUnlockPages(PageDriver);
	DbgPrint("Page RootKit unlock !\n");

	DeHookInt(0x0E , OldPageFaultHandler);
	DbgPrint("Hook de l'interruption 0x0E supprime !\n");

	UnSetProtectedPage();

	DbgPrint("Bye\n");
}



NTSTATUS DriverEntry( PDRIVER_OBJECT  DriverObject, PUNICODE_STRING  RegistryPath )
{
	DbgPrint("Hello !\n");

	DriverObject->DriverUnload = OnUnload;
		
	PageDriver = IoAllocateMdl(NewInt0E, 2048, FALSE, FALSE, NULL);

	__try
	{
		MmProbeAndLockPages(PageDriver, KernelMode, IoReadAccess | IoWriteAccess |IoModifyAccess); 
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		DbgPrint("Rootkit: MmProbe.. Failed on Memory Page(s): 0x%x\n", GetExceptionCode());
	}

	DbgPrint("Page Fault Handler locked !\n");

	HookInt(0x0E, (unsigned long)NewInt0E, &OldPageFaultHandler);
	DbgPrint("Hook de l'interruption 0x0E mis en place !\n");

	SetProtectedPage("test.exe", (PVOID)0x00402000, (PVOID)0x00403000, (PVOID)0x00402000 );

	return STATUS_SUCCESS;
}
