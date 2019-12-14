/*
 * CalculateCosa.c
 *
 * Code generation for function 'CalculateCosa'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "CalculateCosa.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRTEInfo ib_emlrtRTEI = { 1, 17, "CalculateCosa",
  "D:\\2.AgriMapZoom\\CalculateCosa.m" };

static emlrtRTEInfo jc_emlrtRTEI = { 3, 1, "CalculateCosa",
  "D:\\2.AgriMapZoom\\CalculateCosa.m" };

static emlrtBCInfo oo_emlrtBCI = { -1, -1, 6, 27, "NEdgevectorList",
  "CalculateCosa", "D:\\2.AgriMapZoom\\CalculateCosa.m", 0 };

static emlrtBCInfo po_emlrtBCI = { -1, -1, 6, 71, "NEdgevectorList",
  "CalculateCosa", "D:\\2.AgriMapZoom\\CalculateCosa.m", 0 };

static emlrtBCInfo qo_emlrtBCI = { -1, -1, 6, 1, "Cosa", "CalculateCosa",
  "D:\\2.AgriMapZoom\\CalculateCosa.m", 0 };

static emlrtBCInfo ro_emlrtBCI = { -1, -1, 6, 48, "NEdgevectorList",
  "CalculateCosa", "D:\\2.AgriMapZoom\\CalculateCosa.m", 0 };

static emlrtBCInfo so_emlrtBCI = { -1, -1, 6, 92, "NEdgevectorList",
  "CalculateCosa", "D:\\2.AgriMapZoom\\CalculateCosa.m", 0 };

static emlrtBCInfo to_emlrtBCI = { -1, -1, 4, 31, "NEdgevectorList",
  "CalculateCosa", "D:\\2.AgriMapZoom\\CalculateCosa.m", 0 };

static emlrtBCInfo uo_emlrtBCI = { -1, -1, 4, 52, "NEdgevectorList",
  "CalculateCosa", "D:\\2.AgriMapZoom\\CalculateCosa.m", 0 };

static emlrtBCInfo vo_emlrtBCI = { -1, -1, 4, 77, "NEdgevectorList",
  "CalculateCosa", "D:\\2.AgriMapZoom\\CalculateCosa.m", 0 };

static emlrtBCInfo wo_emlrtBCI = { -1, -1, 4, 98, "NEdgevectorList",
  "CalculateCosa", "D:\\2.AgriMapZoom\\CalculateCosa.m", 0 };

static emlrtBCInfo xo_emlrtBCI = { -1, -1, 4, 5, "Cosa", "CalculateCosa",
  "D:\\2.AgriMapZoom\\CalculateCosa.m", 0 };

/* Function Definitions */
void CalculateCosa(const emlrtStack *sp, const real_T NEdgevectorList_data[],
                   const int32_T NEdgevectorList_size[2], real_T n,
                   emxArray_real_T *Cosa)
{
  int32_T i28;
  int32_T loop_ub;
  int32_T i;
  int32_T i29;
  int32_T i30;
  int32_T i31;
  int32_T i32;
  i28 = Cosa->size[0] * Cosa->size[1];
  Cosa->size[0] = 1;
  Cosa->size[1] = (int32_T)n;
  emxEnsureCapacity(sp, (emxArray__common *)Cosa, i28, (int32_T)sizeof(real_T),
                    &ib_emlrtRTEI);
  loop_ub = (int32_T)n;
  for (i28 = 0; i28 < loop_ub; i28++) {
    Cosa->data[i28] = 0.0;
  }

  emlrtForLoopVectorCheckR2012b(2.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)(n + -1.0),
    &jc_emlrtRTEI, sp);
  i = 0;
  while (i <= (int32_T)(n + -1.0) - 1) {
    i28 = (int32_T)(2.0 + (real_T)i);
    if (!((i28 >= 1) && (i28 <= NEdgevectorList_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(i28, 1, NEdgevectorList_size[0],
        &to_emlrtBCI, sp);
    }

    loop_ub = (int32_T)((2.0 + (real_T)i) - 1.0);
    if (!((loop_ub >= 1) && (loop_ub <= NEdgevectorList_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, NEdgevectorList_size[0],
        &uo_emlrtBCI, sp);
    }

    i29 = (int32_T)(2.0 + (real_T)i);
    if (!((i29 >= 1) && (i29 <= NEdgevectorList_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(i29, 1, NEdgevectorList_size[0],
        &vo_emlrtBCI, sp);
    }

    i30 = (int32_T)((2.0 + (real_T)i) - 1.0);
    if (!((i30 >= 1) && (i30 <= NEdgevectorList_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(i30, 1, NEdgevectorList_size[0],
        &wo_emlrtBCI, sp);
    }

    i31 = Cosa->size[1];
    i32 = (int32_T)(2.0 + (real_T)i);
    if (!((i32 >= 1) && (i32 <= i31))) {
      emlrtDynamicBoundsCheckR2012b(i32, 1, i31, &xo_emlrtBCI, sp);
    }

    Cosa->data[i32 - 1] = NEdgevectorList_data[i28 - 1] *
      NEdgevectorList_data[loop_ub - 1] + NEdgevectorList_data[(i29 +
      NEdgevectorList_size[0]) - 1] * NEdgevectorList_data[(i30 +
      NEdgevectorList_size[0]) - 1];
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  i28 = Cosa->size[1];
  if (!(1 <= i28)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i28, &qo_emlrtBCI, sp);
  }

  if (!(1 <= NEdgevectorList_size[0])) {
    emlrtDynamicBoundsCheckR2012b(1, 1, NEdgevectorList_size[0], &oo_emlrtBCI,
      sp);
  }

  if (!(1 <= NEdgevectorList_size[0])) {
    emlrtDynamicBoundsCheckR2012b(1, 1, NEdgevectorList_size[0], &po_emlrtBCI,
      sp);
  }

  i28 = (int32_T)n;
  if (!((i28 >= 1) && (i28 <= NEdgevectorList_size[0]))) {
    emlrtDynamicBoundsCheckR2012b(i28, 1, NEdgevectorList_size[0], &ro_emlrtBCI,
      sp);
  }

  loop_ub = (int32_T)n;
  if (!((loop_ub >= 1) && (loop_ub <= NEdgevectorList_size[0]))) {
    emlrtDynamicBoundsCheckR2012b(loop_ub, 1, NEdgevectorList_size[0],
      &so_emlrtBCI, sp);
  }

  Cosa->data[0] = NEdgevectorList_data[0] * NEdgevectorList_data[i28 - 1] +
    NEdgevectorList_data[NEdgevectorList_size[0]] * NEdgevectorList_data
    [(loop_ub + NEdgevectorList_size[0]) - 1];
}

/* End of code generation (CalculateCosa.c) */
