/*
 * DPList.c
 *
 * Code generation for function 'DPList'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "DPList.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRTEInfo f_emlrtRTEI = { 1, 27, "DPList",
  "D:\\2.AgriMapZoom\\DPList.m" };

static emlrtRTEInfo pb_emlrtRTEI = { 4, 1, "DPList",
  "D:\\2.AgriMapZoom\\DPList.m" };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 7, 30, "Point", "DPList",
  "D:\\2.AgriMapZoom\\DPList.m", 0 };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 7, 52, "Point", "DPList",
  "D:\\2.AgriMapZoom\\DPList.m", 0 };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 5, 20, "EdgevectorList", "DPList",
  "D:\\2.AgriMapZoom\\DPList.m", 0 };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 7, 16, "EdgevectorList", "DPList",
  "D:\\2.AgriMapZoom\\DPList.m", 0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 7, 41, "Point", "DPList",
  "D:\\2.AgriMapZoom\\DPList.m", 0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 7, 63, "Point", "DPList",
  "D:\\2.AgriMapZoom\\DPList.m", 0 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 5, 36, "Point", "DPList",
  "D:\\2.AgriMapZoom\\DPList.m", 0 };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 5, 49, "Point", "DPList",
  "D:\\2.AgriMapZoom\\DPList.m", 0 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 5, 60, "Point", "DPList",
  "D:\\2.AgriMapZoom\\DPList.m", 0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 5, 73, "Point", "DPList",
  "D:\\2.AgriMapZoom\\DPList.m", 0 };

/* Function Definitions */
void DPList(const emlrtStack *sp, const emxArray_real_T *Point, real_T n,
            emxArray_real_T *EdgevectorList)
{
  int32_T i2;
  int32_T loop_ub;
  int32_T i;

  /* 计算指定数组中两点之间的向量、n为行数 */
  i2 = EdgevectorList->size[0] * EdgevectorList->size[1];
  EdgevectorList->size[0] = (int32_T)n;
  EdgevectorList->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)EdgevectorList, i2, (int32_T)sizeof
                    (real_T), &f_emlrtRTEI);
  loop_ub = (int32_T)n << 1;
  for (i2 = 0; i2 < loop_ub; i2++) {
    EdgevectorList->data[i2] = 0.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, n - 1.0, mxDOUBLE_CLASS, (int32_T)(n -
    1.0), &pb_emlrtRTEI, sp);
  i = 0;
  while (i <= (int32_T)(n - 1.0) - 1) {
    loop_ub = EdgevectorList->size[0];
    if (!((i + 1 >= 1) && (i + 1 <= loop_ub))) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, loop_ub, &vc_emlrtBCI, sp);
    }

    i2 = Point->size[0];
    loop_ub = (int32_T)((1.0 + (real_T)i) + 1.0);
    if (!((loop_ub >= 1) && (loop_ub <= i2))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, &ad_emlrtBCI, sp);
    }

    i2 = Point->size[0];
    if (!((i + 1 >= 1) && (i + 1 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, i2, &bd_emlrtBCI, sp);
    }

    EdgevectorList->data[i] = Point->data[loop_ub - 1] - Point->data[i];
    i2 = Point->size[0];
    loop_ub = (int32_T)((1.0 + (real_T)i) + 1.0);
    if (!((loop_ub >= 1) && (loop_ub <= i2))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, &cd_emlrtBCI, sp);
    }

    i2 = Point->size[0];
    if (!((i + 1 >= 1) && (i + 1 <= i2))) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, i2, &dd_emlrtBCI, sp);
    }

    EdgevectorList->data[i + EdgevectorList->size[0]] = Point->data[(loop_ub +
      Point->size[0]) - 1] - Point->data[i + Point->size[0]];
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  i2 = Point->size[0];
  if (!(1 <= i2)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i2, &tc_emlrtBCI, sp);
  }

  i2 = Point->size[0];
  if (!(1 <= i2)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i2, &uc_emlrtBCI, sp);
  }

  loop_ub = EdgevectorList->size[0];
  i2 = (int32_T)n;
  if (!((i2 >= 1) && (i2 <= loop_ub))) {
    emlrtDynamicBoundsCheckR2012b(i2, 1, loop_ub, &wc_emlrtBCI, sp);
  }

  i2 = Point->size[0];
  loop_ub = (int32_T)n;
  if (!((loop_ub >= 1) && (loop_ub <= i2))) {
    emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, &xc_emlrtBCI, sp);
  }

  EdgevectorList->data[(int32_T)n - 1] = Point->data[0] - Point->data[loop_ub -
    1];
  i2 = Point->size[0];
  loop_ub = (int32_T)n;
  if (!((loop_ub >= 1) && (loop_ub <= i2))) {
    emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, &yc_emlrtBCI, sp);
  }

  EdgevectorList->data[((int32_T)n + EdgevectorList->size[0]) - 1] = Point->
    data[Point->size[0]] - Point->data[(loop_ub + Point->size[0]) - 1];
}

/* End of code generation (DPList.c) */
