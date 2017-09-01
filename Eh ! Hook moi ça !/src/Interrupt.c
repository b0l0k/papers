#include "Interrupt.h"

void HookInt( unsigned char interrupt , unsigned long NewHandler , unsigned long *OldHandler )
{
	Idtr MyIdtr;
	PIdtEntry MyIdtEntry;
	unsigned long pInt;

	_asm
	{
		cli
		sidt MyIdtr
	}

	if( interrupt * sizeof(IdtEntry) < MyIdtr.Limit)
	{

		MyIdtEntry = (PIdtEntry)MyIdtr.Base;

		*OldHandler = (MyIdtEntry[interrupt].OffsetHigh << 16) | MyIdtEntry[interrupt].OffsetLow;

		pInt = (unsigned long)&MyIdtEntry[interrupt];

		MyIdtEntry[interrupt].OffsetLow = (unsigned short)NewHandler;
		MyIdtEntry[interrupt].OffsetHigh =(unsigned short)((unsigned long)NewHandler >> 16);

		_asm invlpg pInt

	}

	_asm sti
}

void DeHookInt( unsigned char interrupt , unsigned long OldHandler)
{
	Idtr MyIdtr;
	PIdtEntry MyIdtEntry;
	unsigned long pInt;

	_asm
	{
		cli
		sidt MyIdtr
	}

	if( interrupt * sizeof(IdtEntry) < MyIdtr.Limit)
	{
		MyIdtEntry = (PIdtEntry)MyIdtr.Base;

		pInt = (unsigned long)&MyIdtEntry[interrupt];

		MyIdtEntry[interrupt].OffsetLow = (unsigned short)OldHandler;
		MyIdtEntry[interrupt].OffsetHigh =(unsigned short)((unsigned long)OldHandler >> 16);

		_asm invlpg pInt
	}

	_asm sti
}