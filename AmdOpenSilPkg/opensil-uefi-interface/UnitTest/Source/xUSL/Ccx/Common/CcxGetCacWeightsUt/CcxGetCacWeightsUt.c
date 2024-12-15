/* Copyright (C) 2021 - 2024 Advanced Micro Devices, Inc. All rights reserved. */
// SPDX-License-Identifier: MIT
/**
 * @file CcxGetCacWeightsUt.c
 * @brief
 *
 */

#include <UtBaseLib.h>
#include <UtSilInitLib.h>
#include <UtLogLib.h>

#include <stdlib.h>     // if not included, build ok
#include <time.h>       // if not included, build ok
#include <stdbool.h>    // if not included, build ok
#include <xSIM.h>       // if not included, will cause error 2059, c2061
#include <CCX/Common/Ccx.h> //must put here, solve the error of undefine of CcxEnableSmee
#include <Include/MsrReg.h>// if not included, build ok

// HOST_DEBUG_SERVICE mHostDebugService = NULL;
void
xUslMsrAndThenOr (
  uint32_t Index,
  uint64_t AndData,
  uint64_t OrData
  )
{
  return;
}

uint64_t 
xUslRdMsr (
  uint32_t MsrAddress
  )
{
  return 0;
}

void 
xUslWrMsr (
  uint32_t MsrAddress, 
  uint64_t MsrValue
  )
{
  return;
}

void 
xUslMsrOr (
  uint32_t Index, 
  uint64_t OrData)
{
  return;
}

void 
xUslMsrAnd (
  uint32_t Index, 
  uint64_t AndData
  )
{
  return;
}

bool 
xUslIsComputeUnitPrimary (
  void
  ) 
{
  return TRUE;
}

AMD_UNIT_TEST_STATUS
EFIAPI
TestPrerequisite (
  IN AMD_UNIT_TEST_CONTEXT Context
  )
{
  return AMD_UNIT_TEST_PASSED; 
}

void
EFIAPI
TestBody (
  IN AMD_UNIT_TEST_CONTEXT Context
  )
{
  AMD_UNIT_TEST_FRAMEWORK *Ut = (AMD_UNIT_TEST_FRAMEWORK*) UtGetActiveFrameworkHandle ();
  const char* TestName        = UtGetTestName (Ut);
  const char* IterationName   = UtGetTestIteration (Ut);

  SIL_STATUS           SilStatus;
  SIL_DATA_BLOCK_ID ipId = SilId_SocCommon;
  
  Ut->Log(AMD_UNIT_TEST_LOG_INFO, __FUNCTION__, __LINE__,
    "%s (Iteration: %s) Test started.", TestName, IterationName);

  if (strcmp (IterationName, "SilPass") == 0) {
    // Arrange for SilGetIp2IpApi (SilId_SmuClass, (void **)&SmuApi) in CcxGetCacWeights (uint64_t *CacWeights);
    // mock func -> SilGetIp2IpApi (SIL_DATA_BLOCK_ID IpId, void **Api);
    void *validApi = NULL;
    uint64_t CacWeightsGet[5] ={0, 236, 93671, 32447, 46512};

    SilGetIp2IpApi (ipId, &validApi);

    // Act  
    SilStatus = CcxGetCacWeights(CacWeightsGet);

    // Assert
    if (SilStatus != SilPass) {
      Ut->Log(AMD_UNIT_TEST_LOG_ERROR, __FUNCTION__, __LINE__,
            "Did not receive SilPass", IterationName);
      UtSetTestStatus (Ut, AMD_UNIT_TEST_ABORTED);
    } else {
      UtSetTestStatus (Ut, AMD_UNIT_TEST_PASSED);
    }
  } else if (strcmp (IterationName, "SilAborted") == 0) {
    // Arrange 
    void **invalidApi = NULL; //pass as invalidApi
    uint64_t CacWeightsGet[5] ={0, 236, 93671, 32447, 46512};

    SilGetIp2IpApi (ipId, invalidApi);

    // Act  
    SilStatus = CcxGetCacWeights(CacWeightsGet);

    // Assert 
    if (SilStatus != SilPass) {
      Ut->Log(AMD_UNIT_TEST_LOG_ERROR, __FUNCTION__, __LINE__,
            "Did not receive SilPass", IterationName);
      UtSetTestStatus (Ut, AMD_UNIT_TEST_ABORTED);
    } else {
      UtSetTestStatus (Ut, AMD_UNIT_TEST_PASSED);
    }
  } else {
    Ut->Log(AMD_UNIT_TEST_LOG_ERROR, __FUNCTION__, __LINE__,
      "Iteration '%s' is not implemented.", IterationName);
    UtSetTestStatus (Ut, AMD_UNIT_TEST_ABORTED);
  }

  UtSetTestStatus (Ut, AMD_UNIT_TEST_PASSED);
  Ut->Log(AMD_UNIT_TEST_LOG_INFO, __FUNCTION__, __LINE__,
    "%s (Iteration: %s) Test ended.", TestName, IterationName);
}

AMD_UNIT_TEST_STATUS
EFIAPI
TestCleanUp (
  IN AMD_UNIT_TEST_CONTEXT Context
  )
{
  // AMD_UNIT_TEST_FRAMEWORK *Ut = (AMD_UNIT_TEST_FRAMEWORK*) UtGetActiveFrameworkHandle ();
  // const char* TestName        = UtGetTestName (Ut);
  // const char* IterationName   = UtGetTestIteration (Ut);
  // Ut->Log(AMD_UNIT_TEST_LOG_INFO, __FUNCTION__, __LINE__,
  //   "%s (Iteration: %s) CleanUp started.", TestName, IterationName);
  // // Free openSIL allocated memory
  // UtSilDeinit ();
  // Ut->Log(AMD_UNIT_TEST_LOG_INFO, __FUNCTION__, __LINE__,
  //   "%s (Iteration: %s) CleanUp ended.", TestName, IterationName);
  return AMD_UNIT_TEST_PASSED;
}

/**
 * main
 * @brief      Stating point for Execution
 *
 * @details    This routine:
 *              - Handles the command line arguments.
 *              - Declares the unit test framework.
 *              - Run the tests.
 *              - Deallocate the Unit test framework.
 *
 * @param      argc                     Argument count
 * @param      *argv[]                  Argument vector
 *
 * @retval     AMD_UNIT_TEST_PASSED     Function succeeded
 * @retval     NON-ZERO                 Error occurs
 */
int
main (
  int   argc,
  char  *argv[]
  )
{
  AMD_UNIT_TEST_STATUS Status;
  AMD_UNIT_TEST_FRAMEWORK Ut;

  // Initializing the UnitTest framework
  Status = UtInitFromArgs (
    &Ut,
    argc,
    argv
  );
  if (Status != AMD_UNIT_TEST_PASSED) {
    return Status;
  }

  // char *SimpleCharContext = "A simple TestBody context";

  // Logging the start of the test.
  // Note: Test status at this time is set to "NOT_SET".
  Ut.Log(AMD_UNIT_TEST_LOG_INFO, __FUNCTION__, __LINE__,
    "Test %s started. TestStatus is %s.", UtGetTestName (&Ut), UtGetTestStatusString (&Ut));

  // You can pass into the TestPrerequisite, TestBody, and TestCleanUp context of
  // your desire
  // UtSetTestContext (&Ut, (AMD_UNIT_TEST_CONTEXT)SimpleCharContext);

  // Running the test
  Ut.Log(AMD_UNIT_TEST_LOG_INFO, __FUNCTION__, __LINE__, "Running test.");
  UtRunTest (&Ut);

  // Freeing up all framework related allocated memories
  Ut.Log(AMD_UNIT_TEST_LOG_INFO, __FUNCTION__, __LINE__, "Test %s ended.", UtGetTestName (&Ut));
  UtDeinit (&Ut);

  return AMD_UNIT_TEST_PASSED;
}
