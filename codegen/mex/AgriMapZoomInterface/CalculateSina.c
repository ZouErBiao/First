/*
 * CalculateSina.c
 *
 * Code generation for function 'CalculateSina'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "CalculateSina.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRTEInfo m_emlrtRTEI = { 1, 17, "CalculateSina",
  "D:\\2.AgriMapZoom\\CalculateSina.m" };

static emlrtRTEInfo vb_emlrtRTEI = { 4, 1, "CalculateSina",
  "D:\\2.AgriMapZoom\\CalculateSina.m" };

static emlrtBCInfo ah_emlrtBCI = { -1, -1, 7, 29, "NEdgevectorList",
  "CalculateSina", "D:\\2.AgriMapZoom\\CalculateSina.m", 0 };

static emlrtBCInfo bh_emlrtBCI = { -1, -1, 7, 75, "NEdgevectorList",
  "CalculateSina", "D:\\2.AgriMapZoom\\CalculateSina.m", 0 };

static emlrtBCInfo ch_emlrtBCI = { -1, -1, 7, 8, "Sina", "CalculateSina",
  "D:\\2.AgriMapZoom\\CalculateSina.m", 0 };

static emlrtBCInfo dh_emlrtBCI = { -1, -1, 7, 52, "NEdgevectorList",
  "CalculateSina", "D:\\2.AgriMapZoom\\CalculateSina.m", 0 };

static emlrtBCInfo eh_emlrtBCI = { -1, -1, 7, 98, "NEdgevectorList",
  "CalculateSina", "D:\\2.AgriMapZoom\\CalculateSina.m", 0 };

static emlrtBCInfo fh_emlrtBCI = { -1, -1, 5, 33, "NEdgevectorList",
  "CalculateSina", "D:\\2.AgriMapZoom\\CalculateSina.m", 0 };

static emlrtBCInfo gh_emlrtBCI = { -1, -1, 5, 56, "NEdgevectorList",
  "CalculateSina", "D:\\2.AgriMapZoom\\CalculateSina.m", 0 };

static emlrtBCInfo hh_emlrtBCI = { -1, -1, 5, 81, "NEdgevectorList",
  "CalculateSina", "D:\\2.AgriMapZoom\\CalculateSina.m", 0 };

static emlrtBCInfo ih_emlrtBCI = { -1, -1, 5, 104, "NEdgevectorList",
  "CalculateSina", "D:\\2.AgriMapZoom\\CalculateSina.m", 0 };

static emlrtBCInfo jh_emlrtBCI = { -1, -1, 5, 12, "Sina", "CalculateSina",
  "D:\\2.AgriMapZoom\\CalculateSina.m", 0 };

/* Function Definitions */
void CalculateSina(const emlrtStack *sp, const emxArray_real_T *NEdgevectorList,
                   real_T n, emxArray_real_T *Sina)
{
  int32_T i13;
  int32_T loop_ub;
  int32_T i;
  int32_T i14;
  int32_T i15;
  int32_T i16;
  int32_T i17;

  /* 计算各个夹角的sin值，利用的是单位向量的叉乘、n为NEdgevectorList的列数 */
  i13 = Sina->size[0] * Sina->size[1];
  Sina->size[0] = 1;
  Sina->size[1] = (int32_T)n;
  emxEnsureCapacity(sp, (emxArray__common *)Sina, i13, (int32_T)sizeof(real_T),
                    &m_emlrtRTEI);
  loop_ub = (int32_T)n;
  for (i13 = 0; i13 < loop_ub; i13++) {
    Sina->data[i13] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(2.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)(n + -1.0),
    &vb_emlrtRTEI, sp);
  i = 0;
  while (i <= (int32_T)(n + -1.0) - 1) {
    i13 = NEdgevectorList->size[0];
    loop_ub = (int32_T)(2.0 + (real_T)i);
    if (!((loop_ub >= 1) && (loop_ub <= i13))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i13, &fh_emlrtBCI, sp);
    }

    i13 = NEdgevectorList->size[0];
    i14 = (int32_T)((2.0 + (real_T)i) - 1.0);
    if (!((i14 >= 1) && (i14 <= i13))) {
      emlrtDynamicBoundsCheckR2012b(i14, 1, i13, &gh_emlrtBCI, sp);
    }

    i13 = NEdgevectorList->size[0];
    i15 = (int32_T)(2.0 + (real_T)i);
    if (!((i15 >= 1) && (i15 <= i13))) {
      emlrtDynamicBoundsCheckR2012b(i15, 1, i13, &hh_emlrtBCI, sp);
    }

    i13 = NEdgevectorList->size[0];
    i16 = (int32_T)((2.0 + (real_T)i) - 1.0);
    if (!((i16 >= 1) && (i16 <= i13))) {
      emlrtDynamicBoundsCheckR2012b(i16, 1, i13, &ih_emlrtBCI, sp);
    }

    i13 = Sina->size[1];
    i17 = (int32_T)(2.0 + (real_T)i);
    if (!((i17 >= 1) && (i17 <= i13))) {
      emlrtDynamicBoundsCheckR2012b(i17, 1, i13, &jh_emlrtBCI, sp);
    }

    Sina->data[Sina->size[0] * (i17 - 1)] = NEdgevectorList->data[loop_ub - 1] *
      NEdgevectorList->data[(i14 + NEdgevectorList->size[0]) - 1] -
      NEdgevectorList->data[(i15 + NEdgevectorList->size[0]) - 1] *
      NEdgevectorList->data[i16 - 1];
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  i13 = Sina->size[1];
  if (!(1 <= i13)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i13, &ch_emlrtBCI, sp);
  }

  i13 = NEdgevectorList->size[0];
  if (!(1 <= i13)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i13, &ah_emlrtBCI, sp);
  }

  i13 = NEdgevectorList->size[0];
  if (!(1 <= i13)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i13, &bh_emlrtBCI, sp);
  }

  i13 = NEdgevectorList->size[0];
  loop_ub = (int32_T)n;
  if (!((loop_ub >= 1) && (loop_ub <= i13))) {
    emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i13, &dh_emlrtBCI, sp);
  }

  i13 = NEdgevectorList->size[0];
  i14 = (int32_T)n;
  if (!((i14 >= 1) && (i14 <= i13))) {
    emlrtDynamicBoundsCheckR2012b(i14, 1, i13, &eh_emlrtBCI, sp);
  }

  Sina->data[0] = NEdgevectorList->data[0] * NEdgevectorList->data[(loop_ub +
    NEdgevectorList->size[0]) - 1] - NEdgevectorList->data[NEdgevectorList->
    size[0]] * NEdgevectorList->data[i14 - 1];
}

/* End of code generation (CalculateSina.c) */
