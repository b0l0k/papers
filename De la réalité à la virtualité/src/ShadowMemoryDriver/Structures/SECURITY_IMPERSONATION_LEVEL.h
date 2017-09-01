/* 
Copyright (c) FRET.  All rights reserved.

File Name : SECURITY_IMPERSONATION_LEVEL.h

Abstract:
Security Impersonation Level enumeration.

Author: FRET ( www.binary-reverser.org)
Documented by : Neitsa

Version : 04
Last Update : 29-Aug-2006 
*/

#ifndef _SECURITY_IMPERSONATION_LEVEL_H_INCLUDED
#define _SECURITY_IMPERSONATION_LEVEL_H_INCLUDED

#ifndef SECURITY_IMPERSONATION_LEVEL_INCLUDED
#define SECURITY_IMPERSONATION_LEVEL_INCLUDED
#ifndef _NTDDK_

typedef enum _SECURITY_IMPERSONATION_LEVEL
{
  SecurityAnonymous = 0,
    SecurityIdentification,
    SecurityImpersonation,
    SecurityDelegation
} SECURITY_IMPERSONATION_LEVEL, *PSECURITY_IMPERSONATION_LEVEL, **PPSECURITY_IMPERSONATION_LEVEL;

#endif //_NTDDK_
#endif //_INCLUDED
#endif //_H_INCLUDED
