/*
 * AgriMapZoomInterface_mexutil.c
 *
 * Code generation for function 'AgriMapZoomInterface_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "AgriMapZoomInterface_mexutil.h"

/* Function Definitions */
int32_T asr_s32(int32_T u, uint32_T n)
{
  int32_T y;
  if (u >= 0) {
    y = (int32_T)((uint32_T)u >> n);
  } else {
    y = -(int32_T)((uint32_T)-(u + 1) >> n) - 1;
  }

  return y;
}

/* End of code generation (AgriMapZoomInterface_mexutil.c) */
