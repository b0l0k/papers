/* 
Copyright (c) FRET.  All rights reserved.

File Name : DEVICE_POWER_STATE.h

Abstract:
 DEVICE_POWER_STATE enumeration.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 26-Aug-2006 
*/

#ifndef _DEVICE_POWER_STATE_H_INCLUDED
#define _DEVICE_POWER_STATE_H_INCLUDED

#ifndef DEVICE_POWER_STATE_INCLUDED
#define DEVICE_POWER_STATE_INCLUDED
#ifndef _NTDDK_

typedef enum _DEVICE_POWER_STATE
{
  PowerDeviceUnspecified = 0,
    PowerDeviceD0,
    PowerDeviceD1,
    PowerDeviceD2,
    PowerDeviceD3,
    PowerDeviceMaximum
} DEVICE_POWER_STATE, *PDEVICE_POWER_STATE, **PPDEVICE_POWER_STATE;

#endif // _NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
