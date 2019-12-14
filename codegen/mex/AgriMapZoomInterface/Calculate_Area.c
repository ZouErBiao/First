/*
 * Calculate_Area.c
 *
 * Code generation for function 'Calculate_Area'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "Calculate_Area.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRTEInfo fc_emlrtRTEI = { 4, 1, "Calculate_Area",
  "D:\\2.AgriMapZoom\\Calculate_Area.m" };

static emlrtBCInfo xl_emlrtBCI = { -1, -1, 3, 16, "Pxy", "Calculate_Area",
  "D:\\2.AgriMapZoom\\Calculate_Area.m", 0 };

static emlrtBCInfo yl_emlrtBCI = { -1, -1, 5, 21, "Pxy", "Calculate_Area",
  "D:\\2.AgriMapZoom\\Calculate_Area.m", 0 };

static emlrtBCInfo am_emlrtBCI = { -1, -1, 5, 32, "Pxy", "Calculate_Area",
  "D:\\2.AgriMapZoom\\Calculate_Area.m", 0 };

static emlrtBCInfo bm_emlrtBCI = { -1, -1, 5, 45, "Pxy", "Calculate_Area",
  "D:\\2.AgriMapZoom\\Calculate_Area.m", 0 };

static emlrtBCInfo cm_emlrtBCI = { -1, -1, 5, 56, "Pxy", "Calculate_Area",
  "D:\\2.AgriMapZoom\\Calculate_Area.m", 0 };

/* Function Definitions */
real_T Calculate_Area(const emlrtStack *sp, real_T Pxy_data[], int32_T Pxy_size
                      [2], real_T n)
{
  real_T b_sum;
  real_T b_Pxy_data[202];
  int32_T Pxy_size_idx_0;
  int32_T i21;
  int32_T loop_ub;
  int32_T i22;
  int32_T i;
  b_sum = 0.0;
  if (!(1 <= Pxy_size[0])) {
    emlrtDynamicBoundsCheckR2012b(1, 1, Pxy_size[0], &xl_emlrtBCI, sp);
  }

  Pxy_size_idx_0 = Pxy_size[0] + 1;
  for (i21 = 0; i21 < 2; i21++) {
    loop_ub = Pxy_size[0];
    for (i22 = 0; i22 < loop_ub; i22++) {
      b_Pxy_data[i22 + Pxy_size_idx_0 * i21] = Pxy_data[i22 + Pxy_size[0] * i21];
    }
  }

  for (i21 = 0; i21 < 2; i21++) {
    b_Pxy_data[Pxy_size[0] + Pxy_size_idx_0 * i21] = Pxy_data[Pxy_size[0] * i21];
  }

  Pxy_size[0]++;
  for (i21 = 0; i21 < 2; i21++) {
    for (i22 = 0; i22 < Pxy_size_idx_0; i22++) {
      Pxy_data[i22 + Pxy_size[0] * i21] = b_Pxy_data[i22 + Pxy_size_idx_0 * i21];
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)n,
    &fc_emlrtRTEI, sp);
  i = 0;
  while (i <= (int32_T)n - 1) {
    if (!((i + 1 >= 1) && (i + 1 <= Pxy_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, Pxy_size[0], &yl_emlrtBCI, sp);
    }

    i21 = (int32_T)((1.0 + (real_T)i) + 1.0);
    if (!((i21 >= 1) && (i21 <= Pxy_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(i21, 1, Pxy_size[0], &am_emlrtBCI, sp);
    }

    if (!((i + 1 >= 1) && (i + 1 <= Pxy_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, Pxy_size[0], &bm_emlrtBCI, sp);
    }

    i22 = (int32_T)((1.0 + (real_T)i) + 1.0);
    if (!((i22 >= 1) && (i22 <= Pxy_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(i22, 1, Pxy_size[0], &cm_emlrtBCI, sp);
    }

    b_sum = (b_sum + Pxy_data[i] * Pxy_data[(i21 + Pxy_size[0]) - 1]) -
      Pxy_data[i + Pxy_size[0]] * Pxy_data[i22 - 1];
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  return muDoubleScalarAbs(b_sum / 2.0);
}

/* End of code generation (Calculate_Area.c) */
