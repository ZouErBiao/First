/*
 * NormalizeDPList.c
 *
 * Code generation for function 'NormalizeDPList'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "NormalizeDPList.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "error.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRSInfo r_emlrtRSI = { 6, "NormalizeDPList",
  "D:\\2.AgriMapZoom\\NormalizeDPList.m" };

static emlrtRTEInfo g_emlrtRTEI = { 1, 28, "NormalizeDPList",
  "D:\\2.AgriMapZoom\\NormalizeDPList.m" };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 6, 21, "NEdgevectorList",
  "NormalizeDPList", "D:\\2.AgriMapZoom\\NormalizeDPList.m", 0 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 6, 43, "EdgevectorList",
  "NormalizeDPList", "D:\\2.AgriMapZoom\\NormalizeDPList.m", 0 };

static emlrtRTEInfo qb_emlrtRTEI = { 5, 1, "NormalizeDPList",
  "D:\\2.AgriMapZoom\\NormalizeDPList.m" };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 6, 68, "EdgevectorList",
  "NormalizeDPList", "D:\\2.AgriMapZoom\\NormalizeDPList.m", 0 };

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 6, 88, "EdgevectorList",
  "NormalizeDPList", "D:\\2.AgriMapZoom\\NormalizeDPList.m", 0 };

static emlrtBCInfo id_emlrtBCI = { -1, -1, 6, 110, "EdgevectorList",
  "NormalizeDPList", "D:\\2.AgriMapZoom\\NormalizeDPList.m", 0 };

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 6, 130, "EdgevectorList",
  "NormalizeDPList", "D:\\2.AgriMapZoom\\NormalizeDPList.m", 0 };

/* Function Definitions */
void NormalizeDPList(const emlrtStack *sp, const emxArray_real_T *EdgevectorList,
                     real_T n, emxArray_real_T *NEdgevectorList)
{
  int32_T i3;
  int32_T loop_ub;
  int32_T i;
  real_T x;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /* 单位化各边向量 */
  /* n为行数 */
  i3 = NEdgevectorList->size[0] * NEdgevectorList->size[1];
  NEdgevectorList->size[0] = (int32_T)n;
  NEdgevectorList->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)NEdgevectorList, i3, (int32_T)sizeof
                    (real_T), &g_emlrtRTEI);
  loop_ub = (int32_T)n << 1;
  for (i3 = 0; i3 < loop_ub; i3++) {
    NEdgevectorList->data[i3] = 0.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)n,
    &qb_emlrtRTEI, sp);
  i = 1;
  while (i - 1 <= (int32_T)n - 1) {
    st.site = &r_emlrtRSI;
    i3 = EdgevectorList->size[0];
    if (!((i >= 1) && (i <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i3, &gd_emlrtBCI, &st);
    }

    i3 = EdgevectorList->size[0];
    if (!((i >= 1) && (i <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i3, &hd_emlrtBCI, &st);
    }

    i3 = EdgevectorList->size[0];
    if (!((i >= 1) && (i <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i3, &id_emlrtBCI, &st);
    }

    i3 = EdgevectorList->size[0];
    if (!((i >= 1) && (i <= i3))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i3, &jd_emlrtBCI, &st);
    }

    x = EdgevectorList->data[i - 1] * EdgevectorList->data[i - 1] +
      EdgevectorList->data[(i + EdgevectorList->size[0]) - 1] *
      EdgevectorList->data[(i + EdgevectorList->size[0]) - 1];
    if (x < 0.0) {
      b_st.site = &o_emlrtRSI;
      error(&b_st);
    }

    x = muDoubleScalarSqrt(x);
    i3 = EdgevectorList->size[0];
    loop_ub = (i - 1) + 1;
    if (!((loop_ub >= 1) && (loop_ub <= i3))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i3, &fd_emlrtBCI, sp);
    }

    loop_ub = NEdgevectorList->size[0];
    if (!((i >= 1) && (i <= loop_ub))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, loop_ub, &ed_emlrtBCI, sp);
    }

    for (i3 = 0; i3 < 2; i3++) {
      NEdgevectorList->data[(i + NEdgevectorList->size[0] * i3) - 1] =
        EdgevectorList->data[(i + EdgevectorList->size[0] * i3) - 1] / x;
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

/* End of code generation (NormalizeDPList.c) */
