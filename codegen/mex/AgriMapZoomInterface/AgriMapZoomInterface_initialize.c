/*
 * AgriMapZoomInterface_initialize.c
 *
 * Code generation for function 'AgriMapZoomInterface_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "AgriMapZoomInterface_initialize.h"
#include "_coder_AgriMapZoomInterface_mex.h"
#include "AgriMapZoomInterface_data.h"

/* Function Definitions */
void AgriMapZoomInterface_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (AgriMapZoomInterface_initialize.c) */
