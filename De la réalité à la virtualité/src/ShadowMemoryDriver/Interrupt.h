#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <ntddk.h>

#pragma pack(1)

typedef struct idtr { 
	unsigned short Limit;
	unsigned long Base;
} Idtr, *PIdtr; 

typedef struct idtentry {
	unsigned short OffsetLow;
	unsigned short Selector;
	unsigned char Reserved;
	unsigned char Always1:3;
	unsigned char Type:1;
	unsigned char Always0:1;
	unsigned char Dpl:2;
	unsigned char Present:1;
	unsigned short OffsetHigh;
} IdtEntry, *PIdtEntry; 

Idtr MyIdtr;

void HookInt( unsigned char interrupt , unsigned long NewHandler , unsigned long* OldHandler );
void DeHookInt( unsigned char interrupt , unsigned long OldHandler);

#endif
