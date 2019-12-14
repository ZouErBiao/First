/*
 * AgriMapZoomInterface_terminate.c
 *
 * Code generation for function 'AgriMapZoomInterface_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "AgriMapZoomInterface_terminate.h"
#include "_coder_AgriMapZoomInterface_mex.h"
#include "AgriMapZoomInterface_data.h"

/* Function Definitions */
void AgriMapZoomInterface_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void AgriMapZoomInterface_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (AgriMapZoomInterface_terminate.c) */
