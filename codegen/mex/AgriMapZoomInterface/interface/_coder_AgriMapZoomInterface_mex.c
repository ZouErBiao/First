/*
 * _coder_AgriMapZoomInterface_mex.c
 *
 * Code generation for function '_coder_AgriMapZoomInterface_mex'
 *
 */

/* Include files */
#include "AgriMapZoomInterface.h"
#include "_coder_AgriMapZoomInterface_mex.h"
#include "AgriMapZoomInterface_terminate.h"
#include "_coder_AgriMapZoomInterface_api.h"
#include "AgriMapZoomInterface_initialize.h"
#include "AgriMapZoomInterface_data.h"

/* Function Declarations */
static void c_AgriMapZoomInterface_mexFunct(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[3]);

/* Function Definitions */
static void c_AgriMapZoomInterface_mexFunct(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[3])
{
  int32_T n;
  const mxArray *inputs[3];
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        20, "AgriMapZoomInterface");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 20,
                        "AgriMapZoomInterface");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  AgriMapZoomInterface_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  AgriMapZoomInterface_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(AgriMapZoomInterface_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  AgriMapZoomInterface_initialize();

  /* Dispatch the entry-point. */
  c_AgriMapZoomInterface_mexFunct(nlhs, plhs, nrhs, prhs);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_AgriMapZoomInterface_mex.c) */
