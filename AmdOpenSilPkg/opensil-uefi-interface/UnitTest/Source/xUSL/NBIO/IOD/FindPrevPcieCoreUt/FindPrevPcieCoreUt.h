/* Copyright (C) 2021 - 2024 Advanced Micro Devices, Inc. All rights reserved. */
// SPDX-License-Identifier: MIT
/**
 * @file  FindPrevPcieCoreUt.h
 * @brief
 *
 */

#pragma once

#include <UtBaseLib.h>
#include <UtSilInitLib.h>
#include <UtLogLib.h>
#include <NBIO/GnbDxio.h>
#include <NBIO/NbioPcieTopologyHelper.h>
#include <NBIO/Nbio.h>
#include <NBIO/NbioCommon.h>

#include <xSIM.h>
#include <CommonLib/SmnAccess.h>
#include <NbioSmnTable.h>
#include "GnbRegisters.h"
#include "NbioData.h"
#include "NbioPcie.h"
#include "NbioHidePcieCore.c"

#include <Uefi.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdint.h>
#include <stdbool.h>
#include <Io.h>

