/*******************************************************************************
*  ______                            ______                 _
* (_____ \                          |  ___ \               | |
*  _____) )___   _ _ _   ____   ___ | | _ | |  ___   ____  | |  _  ____  _   _
* |  ____// _ \ | | | | / _  ) / __)| || || | / _ \ |  _ \ | | / )/ _  )| | | |
* | |    | |_| || | | |( (/ / | |   | || || || |_| || | | || |< (( (/ / | |_| |
* |_|     \___/  \____| \____)|_|   |_||_||_| \___/ |_| |_||_| \_)\____) \__  |
*                                                                       (____/
* Copyright (C) 2021 Ivan Dimkovic. All rights reserved.
*
* All trademarks, logos and brand names are the property of their respective
* owners. All company, product and service names used are for identification
* purposes only. Use of these names, trademarks and brands does not imply
* endorsement.
*
* SPDX-License-Identifier: Apache-2.0
* Full text of the license is available in project root directory (LICENSE)
*
* WARNING: This code is a proof of concept for educative purposes. It can
* modify internal computer configuration parameters and cause malfunctions or
* even permanent damage. It has been tested on a limited range of target CPUs
* and has minimal built-in failsafe mechanisms, thus making it unsuitable for
* recommended use by users not skilled in the art. Use it at your own risk.
*
*******************************************************************************/

#pragma once

/*******************************************************************************
 * 
 ******************************************************************************/

typedef struct _CPUTYPE {
  UINT32 family;
  UINT32 model;
  UINT32 stepping;
} CPUTYPE;

typedef struct _CPUCONFIGTABLE {

  CPUTYPE cpuType;
  CHAR8 uArch[32];

  BOOLEAN hasUnlimitedIccMaxFlag;           // Extra bit controlling unlimited IccMax
  UINT8 IccMaxBits;                         // ADL=11bits, RKL and lower=10bits
  UINT8 VfPointsExposed;                    // OC Mailbox exposes V/F points (param2)
  UINT8 HasEcores;                          // Has E Cores
  

} CPUCONFIGTABLE;

/*******************************************************************************
 * DetectCpu
 ******************************************************************************/

BOOLEAN DetectCpu();

/*******************************************************************************
 * Detected CPU Data
 ******************************************************************************/

extern CPUCONFIGTABLE* gActiveCpuData;