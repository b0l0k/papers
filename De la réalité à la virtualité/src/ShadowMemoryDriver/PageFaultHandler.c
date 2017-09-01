#include "PageFaultHandler.h"

void __declspec( naked ) NewInt0E()
{
	__asm
	{
		pushad

		mov eax, cr3
		cmp Cr3Process, eax 
		jne GoOldPageFault 

		mov esi, cr2					// esi : Adresse de l'instruction qui � caus� le page fault

		mov eax, esi
		and eax, 0xFFFFF000 
		mov ebx, pProtectedPage
		and ebx, 0xFFFFF000 
		cmp ebx, eax

		jne GoOldPageFault


		mov ebx, pPteProtectedPage		// ebx : Pointeur sur le PTE de notre page filtr�

		
		cmp [esp + 0x24], esi			// On compare l'adresse de retour et esi 
		jne IsDataRequest

		/******************************************/
		/*	  Execution demand� dans notre page   */
		/******************************************/
				
		cli

		mov ecx, [ebx]					// ecx : Sauvegarde du PTE Original
		
		mov eax, PtePageExecute			// eax : fake PTE execute

		mov [ebx], eax					// PTE remplac�*/
		
		or dword ptr [ebx], 0x01		

		mov eax, pRetInProtectedPage
		call eax						// Chargement PTE de notre page filtr� ( PtePageExecute ) dans le TLB

		mov [ebx], ecx					// Remise en place du PTE Original

		and dword ptr [ebx], 0xFFFFFFFE	// Inutile mais au cas o�

		sti

		jmp Sortie

IsDataRequest:

		/******************************************/
		/*	  Lect/Ecri demand� dans notre page   */
		/******************************************/

		cli

		mov ecx, [ebx]					// ecx : Sauvegarde du PTE Original

		mov eax, PtePageReadWrite		// eax : fake PTE execute

		mov [ebx], eax					// PTE remplac�

		or dword ptr [ebx], 0x01		

		mov eax, cr2
		mov eax, [eax]					// Chargement du PTE de notre page filtr� ( PtePageReadWrite ) dans le TLB

		mov [ebx], ecx					// Remise en place du PTE Original

		and dword ptr [ebx], 0xFFFFFFFE	// Inutile mais au cas o�

		sti

Sortie:
		popad
		add esp,4						// CodeError avant l'EIP
		iretd

GoOldPageFault:

		popad
		jmp OldPageFaultHandler
	}
}