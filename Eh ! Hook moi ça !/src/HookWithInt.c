#include <ntddk.h>

#include "Interrupt.h"

ULONG OldZwCreateFile;
ULONG OldDebugExceptionHandler;
UCHAR bExit;

void PrintHook()
{
	DbgPrint(" Now Get In ZwCreateFile Hook: Pid: %d...\n", (ULONG)PsGetCurrentProcessId());
}

void __declspec( naked ) NewZwCreateFile()
{
	__asm
	{    
		call PrintHook;
		mov eax,0x25;            
		jmp OldZwCreateFile;
	}
}


void __declspec( naked ) NewInt01()
{
	__asm
	{
		push eax;
		mov eax, dr6;

		test eax, 0x2000;
		jz Is_Breakpoint;

		xor eax,eax;
		mov dr6, eax;

		cmp bExit, 0;
		jnz End;  

		mov eax, [esp + 4];
		add eax, 3;
		mov [esp + 4], eax;

		jmp Enable_GD;

Is_Breakpoint:
		test eax, 0x1;
		jz Is_Other; 

		xor eax,eax;
		mov dr6, eax;

		mov eax, NewZwCreateFile;
		mov [esp + 4],eax;

Enable_GD:
		mov eax, dr7;
		or  eax, 0x2000;
		mov dr7, eax;

End:
		pop eax;
		iretd;

Is_Other:

		pop eax;
		jmp OldDebugExceptionHandler;
	}
}


VOID OnUnload( PDRIVER_OBJECT DriverObject )
{	

	bExit = 1;

	__asm
	{
		xor eax, eax;
		mov dr0, eax;			

		mov eax, dr7;
		and eax, 0xfffffffc;
		mov dr7, eax;
	}

	DeHookInt(0x01 , OldDebugExceptionHandler);
	DbgPrint("Hook de l'interruption 0x01 supprime !\n");

	DbgPrint("Bye\n");
}


NTSTATUS DriverEntry( PDRIVER_OBJECT  DriverObject, PUNICODE_STRING  RegistryPath )
{
	DbgPrint("Hello !\n");

	bExit = 0;

	DriverObject->DriverUnload = OnUnload;

	HookInt(0x01, (unsigned long)NewInt01, &OldDebugExceptionHandler);

	DbgPrint("Hook de l'interruption 0x01 mis en place !\n");

	OldZwCreateFile = (ULONG)ZwCreateFile + 5;
	
	__asm
	{
		mov eax, ZwCreateFile;
		mov dr0, eax;			

		mov eax, dr7;
		or  eax, 0x2202;
		and eax, 0xfff0ffff;
		mov dr7, eax;
	}

	return STATUS_SUCCESS;
}
