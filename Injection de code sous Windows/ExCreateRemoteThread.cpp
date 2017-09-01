#include <windows.h>
#include <cstdio>
#include <TlHelp32.h>

unsigned char sc[] = { 
	'o' , 'O' , 0x00,
	0x33, 0xC0,						//xor eax,eax
	0xBB, 0x00, 0x00, 0x00, 0x00,	//mov ebx,dword
	0x50,							//push eax
	0x53,							//push ebx
	0x53,							//push ebx
	0x50,							//push eax
	0xB8, 0x00, 0x00, 0x00, 0x00,	//mov eax,dword
	0xFF, 0xD0,						//call eax
	0xC3							//ret
};

int main(int c, char **v)
{
	if( c < 2 ) ExitProcess(0);

	DWORD AddrMsgBox = (DWORD)GetProcAddress(LoadLibrary("user32.dll"),"MessageBoxA");

	printf("Adresse de MessageBoxA: 0x%x\n",AddrMsgBox);

	(DWORD)*(DWORD *)&sc[15] = AddrMsgBox;

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

	printf("ID de %s : %d\n",processentry.szExeFile,processentry.th32ProcessID);

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, processentry.th32ProcessID);

	if(!hProcess) ExitProcess(0);

	DWORD Addr = (DWORD)VirtualAllocEx(hProcess, NULL, 1000, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);

	//MEM_RESERVE : Réserve la mémoire.
	//MEM_COMMIT  : Initialise la mémoire à zéro.

	if(!Addr) 
	{
		CloseHandle(hProcess);
		ExitProcess(0);
	}

	(DWORD)*(DWORD *)&sc[6] = Addr;

	if(!WriteProcessMemory(hProcess, (LPVOID)Addr, sc, sizeof(sc), NULL)) ExitProcess(0);

	HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)(Addr + 3), NULL, 0, NULL);

	if(!hThread)
	{
		CloseHandle(hProcess);
		ExitProcess(0);
	}

	WaitForSingleObject(hThread,10000);

	VirtualFreeEx(hProcess, (LPVOID)Addr, 1000, MEM_RELEASE);

	CloseHandle(hThread);
	CloseHandle(hProcess);

	ExitProcess(1);
}