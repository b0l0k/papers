/* 
Copyright (c) FRET.  All rights reserved.

File Name : KWAIT_REASON.h

Abstract:
Kernel Wait Reason enumeration.

Author: FRET (www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 2-Sep-2006 
*/

#ifndef _KWAIT_REASON_H_INCLUDED
#define _KWAIT_REASON_H_INCLUDED

#ifndef _KWAIT_REASON_INCLUDED
#define _KWAIT_REASON_INCLUDED
#ifndef _NTDDK_

typedef enum _KWAIT_REASON
{
  Executive = 0x0,
  FreePage = 0x1,
  PageIn = 0x2,
  PoolAllocation = 0x3,
  DelayExecution = 0x4,
  Suspended = 0x5,
  UserRequest = 0x6,
  WrExecutive = 0x7,
  WrFreePage = 0x8,
  WrPageIn = 0x9,
  WrPoolAllocation = 0xa,
  WrDelayExecution = 0xb,
  WrSuspended = 0xc,
  WrUserRequest = 0xd,
  WrEventPair = 0xe,
  WrQueue = 0xf,
  WrLpcReceive = 0x10,
  WrLpcReply = 0x11,
  WrVirtualMemory = 0x12,
  WrPageOut = 0x13,
  WrRendezvous = 0x14,
  Spare2 = 0x15,
  Spare3 = 0x16,
  Spare4 = 0x17,
  Spare5 = 0x18,
  Spare6 = 0x19,
  WrKernel = 0x1a,
  MaximumWaitReason = 0x1b
} KWAIT_REASON;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED