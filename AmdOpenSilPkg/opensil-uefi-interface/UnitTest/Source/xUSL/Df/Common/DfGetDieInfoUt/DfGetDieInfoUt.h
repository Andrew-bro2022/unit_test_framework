/* SPDX-License-Identifier: MIT */
/* Copyright (C) 2024 Advanced Micro Devices, Inc. All rights reserved. */
/**
* @file DfGetDieInfoUt.h
* @brief
*
*/

#include <xPRF-api.h>
#include <UtBaseLib.h>
#include <UtSilInitLib.h>
#include <UtLogLib.h>
#include <Library/UtSilServicesMockLib.h>
#include <DF/Common/DfCmn2Rev.h>
#include <DF/Common/BaseFabricTopologyCmn.h>
#include <DF/Common/SilBaseFabricTopologyLib.h>


UINT32
GetNumberOfProcessorsPresentUt (
  void
  );

UINT32 
GetNumberOfRootBridgesOnDieUt (
  UINT32 Socket
  );

UINT32 
GetDieSystemOffsetUt (
  UINT32 Socket
  );

CONST
AMD_FABRIC_TOPOLOGY_DIE_DEVICE_MAP* //need confirm
  GetDeviceMapOnDieUt (
  void
  );