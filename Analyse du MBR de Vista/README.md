
Titre:       Eh ! Hook moi ça !  
Auteur:      Vincent Bouzon - b0l0k  
Web:         http://www.c0ding.fr  
Date:        18 juillet 2007

Encore penché sur Singularity, je tombe par hasard sur un article parlant de Bitlocker et plus particulièrement la protection apporté au niveau du boot.

Je saute sur mon désassembleur préféré pour voir ça de mes propres yeux et je désassemble le MBR qui est le premier code de la séquence de boot qui est analysable facilement.

Bitlocker pour sécuriser la séquence de boot s’appuie sur un composant cryptographique matériel nommé TPM (Trusted Platform Module).

Avec un composant TPM, nous pouvons résumer la séquence de boot de Vista comme ceci :  
**TPM Init -> BIOS -> MBR -> Secteur de Boot -> BootMgr -> Winload.exe -> …**  

Commençons à analyser le MBR :
```assembly
0000:0600   xor    ax, ax
0000:0602   mov    ss, ax
0000:0604   mov    sp, 7C00h      ; Mise en place de la pile
0000:0607   mov    es, ax
0000:0609   mov    ds, ax         ; ss = es = ds = 0
0000:060B   mov    si, 7C00h
0000:060E   mov    di, 600h
0000:0611   mov    cx, 200h
0000:0614   cld
0000:0615   rep movsb             ; Recopie du MBR en 600h
0000:0617   push   ax
0000:0618   push   61Ch
0000:061B   retf                  ; Redirection de l'exécution en 61Ch
```
Comme tout le monde le sait le BIOS charge le MBR en 0000:7C00h.  
Le MBR met d’abord en place la pile puis se copie 0000:0600h pour laisser la place au secteur de boot qui sera copier plus tard.
Ensuite l’exécution est redirigée en 61Ch.  

Pour mieux comprendre la suite, il faut rappeler le format d’un MBR :

![MBR](imgs/MBR.JPG)

Et du format de la table des partitions :
```assembly
struct PARTITION_DESCRIPTOR {
    unsigned char ACTIVE;
    unsigned char START_HEAD;
    unsigned char START_SEC;
    unsigned char START_CYL;
    unsigned char TYPE;
    unsigned char END_HEAD;
    unsigned char END_SEC;
    unsigned char END_CYL;
    unsigned int  START;
    unsigned int  SIZE;
};
 
struct PARTITION_TABLE {
    struct PARTITION_DESCRIPTOR ENTRIES[4];
};
```

Voila, on est paré pour la suite :
```assembly
0000:061D   mov    cx, 4
0000:0620   mov    bp, offset PartitionTable
0000:0623
0000:0623 FindPartitionBootable:
0000:0623   cmp    [bp+PARTITION_DESCRIPTOR.ACTIVE], 0
0000:0627   jl     short PartitionBootableFound
0000:0629   jnz    PrintInvalidPartitionTable
0000:062D   add    bp, size PARTITION_DESCRIPTOR
0000:0630   loop   FindPartitionBootable       ; Recherche d'une partition bootable
0000:0632   int    18h                         ; Sinon on repasse l'exécution au Bios
```
La boucle suivante parcourt la table des partitions et teste le champs ACTIVE si le bit de poids fort est a 1 alors la partition est bootable. Dans le cas où aucune partition bootable est trouvé, on repasse la main au bois avec l’interruption 18h.
```assembly
0000:0634 PartitionBootableFound:
0000:0634   mov    [bp+PARTITION_DESCRIPTOR.ACTIVE], dl
0000:0637   push   bp
0000:0638   mov    byte ptr [bp+size PARTITION_DESCRIPTOR+PARTITION_DESCRIPTOR.START_HEAD], 5
0000:063C   mov    byte ptr [bp+size PARTITION_DESCRIPTOR+PARTITION_DESCRIPTOR.ACTIVE], 0
0000:0640   mov    ah, 41h
0000:0642   mov    bx, 55AAh
0000:0645   int    13h                         ; Vérification de la présence de l'extension de l'interruption 13h
0000:0647   pop    bp
0000:0648   jb     short ReadBootSector
0000:064A   cmp    bx, 0AA55h
0000:064E   jnz    short ReadBootSector
0000:0650   test   cx, 1
0000:0654   jz     short ReadBootSector
0000:0656   inc    byte ptr [bp+size PARTITION_DESCRIPTOR+PARTITION_DESCRIPTOR.ACTIVE]
```
Tout d’abord, le périphérique du MBR est stocké dans le champ ACTIVE de la partition bootable, on recycle l’octet vu qu’il nous sert plus !
Encore du recyclage après, on stocke deux octet dans le PARTITION_DESCRIPTOR suivant qui ne nous servira plus lui aussi.
On verra par la suite, l’utilisation de ces deux octets.  
Ensuite il vérifie la présence de l’int 13h étendu. Si elle n’est pas présente on incrémente un des fameux octets.
```assembly
0000:0659 ReadBootSector:
0000:0659   pushad
0000:065B   cmp    byte ptr [bp+size PARTITION_DESCRIPTOR+PARTITION_DESCRIPTOR.ACTIVE], 0
0000:065F   jz     short ReadWithoutExtension
0000:0661   push   large 0
0000:0667   push   large dword ptr [bp+8]
0000:066B   push   0
0000:066E   push   7C00h
0000:0671   push   1
0000:0674   push   10h
0000:0677   mov    ah, 42h
0000:0679   mov    dl, [bp+PARTITION_DESCRIPTOR.ACTIVE]
0000:067C   mov    si, sp
0000:067E   int    13h      ; Lecture du secteur de boot avec l'extension de l'interruption 13h
0000:0680   lahf
0000:0681   add    sp, 10h
0000:0684   sahf
0000:0685   jmp    short EndRead
 
0000:0687 ReadWithoutExtension:
0000:0687   mov    ax, 201h
0000:068A   mov    bx, 7C00h
0000:068D   mov    dl, [bp+PARTITION_DESCRIPTOR.ACTIVE]
0000:0690   mov    dh, [bp+PARTITION_DESCRIPTOR.START_HEAD]
0000:0693   mov    cl, [bp+PARTITION_DESCRIPTOR.START_SEC]
0000:0696   mov    ch, [bp+PARTITION_DESCRIPTOR.START_CYL]
0000:0699   int    13h     ; DISK - READ SECTORS INTO MEMORY
0000:0699                  ; AL = number of sectors to read, CH = track, CL = sector
0000:0699                  ; DH = head, DL = drive, ES:BX -&gt; buffer to fill
0000:0699                  ; Return: CF set on error, AH = status, AL = number of sectors read
```
Tout d’abord, on compare l’octet pour voir si l’extension est présente et l’exécution est redirigé sur l’utilisation de l’int 13h avec ou sans extension pour lire le secteur de boot et le placé en 0000:7C00h.
```assembly
0000:069B   popad
0000:069D   jnb    short CheckBootSector
0000:069F   dec    byte ptr [bp+size PARTITION_DESCRIPTOR+PARTITION_DESCRIPTOR.START_HEAD]
0000:06A2   jnz    ResetDisk
0000:06A6   cmp    [bp+PARTITION_DESCRIPTOR.ACTIVE], 80h
0000:06AA   jz     PrintErrorLoadingOS
0000:06AE   mov    dl, 80h
0000:06B0   jmp    short PartitionBootableFound
0000:06B2
0000:06B2 ResetDisk:
0000:06B2   push   bp
0000:06B3   xor    ah, ah
0000:06B5   mov    dl, [bp+PARTITION_DESCRIPTOR.ACTIVE]
0000:06B8   int    13h            ; DISK - RESET DISK SYSTEM
0000:06B8                         ; DL = drive (if bit 7 is set both hard disks and floppy disks reset)
0000:06BA   pop    bp
0000:06BB   jmp    short ReadBootSector
```
Ensuite on vérifie la bonne lecture du secteur sinon on décrémente le 2eme fameux octet dont je vous parlais, il sert tout simplement de compteur. C’est-à-dire qu’il y’a 5 tentatives d’essaie de lecteur du secteur de boot. Pour chaque erreur, on décrémente, on fait un reset du périphérique et on réessaie de lire.
```assembly
0000:06BD CheckBootSector:
0000:06BD   cmp    word ptr ds:7DFEh, 0AA55h
0000:06C3   jnz    short PrintMissingOS
0000:06C5   push   word ptr [bp+PARTITION_DESCRIPTOR.ACTIVE]
0000:06C8
0000:06C8 ActivateA20:
0000:06C8   call   WaitKeyboadIsEmplty
0000:06CB   jnz    CheckTPM
0000:06CF   mov    al, 0D1h      ; D1: Write Output Port: next byte written to port 60h is placed
0000:06CF                        ;  in the 8042 output port (which is inaccessible to the data bus)
0000:06CF                        ;
0000:06CF                        ;         |7|6|5|4|3|2|1|0|  8042 Output Port
0000:06CF                        ;          | | | | | | | `---- system reset line
0000:06CF                        ;          | | | | | | `----- gate A20
0000:06CF                        ;          | | | | `-------- undefined
0000:06CF                        ;          | | | `--------- output buffer full
0000:06CF                        ;          | | `---------- input buffer empty
0000:06CF                        ;          | `----------- keyboard clock (output)
0000:06CF                        ;          `------------ keyboard data (output)
0000:06CF
0000:06D1   out    64h, al                     ; AT Keyboard controller 8042
0000:06D3   call   WaitKeyboadIsEmplty
0000:06D6   mov    al, 0DFh                    ; DFh = 11011111b
0000:06D8   out    60h, al                     ; AT Keyboard controller 8042
0000:06DA   call   WaitKeyboadIsEmplty
0000:06DD   mov    al, 0FFh                    ; F0h-FFh : Pulse Output Port
0000:06DF   out    64h, al                     ; AT Keyboard controller 8042
0000:06DF                                      ; Reset the keyboard and start internal diagnostics
0000:06E1   call   WaitKeyboadIsEmplty
```
On commence par vérifier si le secteur de boot contient bien la signature AA55h. Ensuite une routine que l’on retrouve dans la plupart des MBR, elle permet d’activer la ligne [A20](https://en.wikipedia.org/wiki/A20_line).
Jusque ici cette analyse, rien de bien nouveau pour un MBR ! C’est maintenant qu’on va avoir du nouveau !
```assembly
0000:06FD HashBootSector:
0000:06FD   push   large 0BB07h
0000:0703   push   large 200h
0000:0709   push   large 8
0000:070F   push   ebx
0000:0711   push   ebx
0000:0713   push   ebp
0000:0715   push   large 0
0000:071B   push   large 7C00h
0000:0721   popad
0000:0723   push   0
0000:0726   pop    es
0000:0727   int    1Ah        ; TCG_CompactHashLogExtendEvent
0000:0727                     ;
0000:0727                     ; AX = BB07h
0000:0727                     ; ES:DI = segment:offset of buffer to be hashed. Physical location of buffer starts at 16*ES+DI
0000:0727                     ; ECX = length of buffer to be hashed. Lengths of 0 through 32K must be supported
0000:0727                     ; EDX = PCR number that that hash must be extended into
0000:0727                     ; ESI = an informative value that must be stored in the event log
0000:0727                     ; EBX = 41504354h
0000:0727                     ; ECX = 0h
0000:0727                     ; EDX = 0h
```
Le code commence par vérifié la présence d’un TPM avec l’int 1Ah et AX = BB00h. Si c’est le cas, un hash du secteur de boot est effectué avec le TPM et le résultat est stocké dans le PCR[8].
Enfin l’exécution est passé au MBR :
```assembly
0000:0729 ExecuteBootSector:
0000:0729   pop    dx
0000:072A   xor    dh, dh
0000:072C   jmp    far ptr 0:7C00h
```

Donc le MBR est bien différent depuis l’introduction de la technologie Bitlocker. Voila, ayant trouvé aucune analyse complète du MBR de Vista, j’ai décidé de poster cette petite aventure !

Vous pouvez retrouver le dump et le listing du MBR de Vista [ici](/src)  

__*Autres documents :*__
http://netah25.developpez.com/windows/BitLocker/  
http://download.microsoft.com/download/5/D/6/5D6EAF2B-7DDF-476B-93DC-7CF0072878E6/secure-start_tech.doc  
http://download.microsoft.com/documents/uk/security/downloads/BitLocker%20Forensics%20UK%20LE2.ppt  
http://actes.sstic.org/SSTIC06/BitLocker/SSTIC06-article-Ourghanlian-BitLocker.pdf  
http://www.blackhat.com/presentations/bh-europe-07/Kumar/Presentation/bh-eu-07-kumar-apr19.pdf