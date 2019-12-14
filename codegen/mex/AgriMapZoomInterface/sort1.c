/*
 * sort1.c
 *
 * Code generation for function 'sort1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "sort1.h"
#include "flipud.h"
#include "eml_int_forloop_overflow_check.h"
#include "sortIdx.h"
#include "AgriMapZoomInterface_mexutil.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRSInfo cb_emlrtRSI = { 66, "sort",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" };

static emlrtRSInfo db_emlrtRSI = { 70, "sortIdx",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo eb_emlrtRSI = { 331, "sortIdx",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo fb_emlrtRSI = { 356, "sortIdx",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo gb_emlrtRSI = { 441, "sortIdx",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo hb_emlrtRSI = { 448, "sortIdx",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo ib_emlrtRSI = { 520, "sortIdx",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo jb_emlrtRSI = { 527, "sortIdx",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo kb_emlrtRSI = { 528, "sortIdx",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo lb_emlrtRSI = { 535, "sortIdx",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

/* Function Definitions */
void sort(const emlrtStack *sp, real_T x[4])
{
  int32_T idx[4];
  real_T x4[4];
  int32_T idx4[4];
  real_T xwork[4];
  int32_T m;
  int32_T nNaNs;
  int32_T ib;
  int32_T k;
  int32_T bLen;
  int32_T nPairs;
  int32_T i4;
  int8_T perm[4];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &db_emlrtRSI;
  c_st.site = &eb_emlrtRSI;
  for (m = 0; m < 4; m++) {
    idx[m] = 0;
    x4[m] = 0.0;
    idx4[m] = 0;
    xwork[m] = 0.0;
  }

  nNaNs = 0;
  ib = 0;
  for (k = 0; k < 4; k++) {
    if (muDoubleScalarIsNaN(x[k])) {
      idx[3 - nNaNs] = k + 1;
      xwork[3 - nNaNs] = x[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = k + 1;
      x4[ib - 1] = x[k];
      if (ib == 4) {
        ib = k - nNaNs;
        if (x4[0] <= x4[1]) {
          m = 1;
          bLen = 2;
        } else {
          m = 2;
          bLen = 1;
        }

        if (x4[2] <= x4[3]) {
          nPairs = 3;
          i4 = 4;
        } else {
          nPairs = 4;
          i4 = 3;
        }

        if (x4[m - 1] <= x4[nPairs - 1]) {
          if (x4[bLen - 1] <= x4[nPairs - 1]) {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)bLen;
            perm[2] = (int8_T)nPairs;
            perm[3] = (int8_T)i4;
          } else if (x4[bLen - 1] <= x4[i4 - 1]) {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)nPairs;
            perm[2] = (int8_T)bLen;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)nPairs;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)bLen;
          }
        } else if (x4[m - 1] <= x4[i4 - 1]) {
          if (x4[bLen - 1] <= x4[i4 - 1]) {
            perm[0] = (int8_T)nPairs;
            perm[1] = (int8_T)m;
            perm[2] = (int8_T)bLen;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)nPairs;
            perm[1] = (int8_T)m;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)bLen;
          }
        } else {
          perm[0] = (int8_T)nPairs;
          perm[1] = (int8_T)i4;
          perm[2] = (int8_T)m;
          perm[3] = (int8_T)bLen;
        }

        idx[ib - 3] = idx4[perm[0] - 1];
        idx[ib - 2] = idx4[perm[1] - 1];
        idx[ib - 1] = idx4[perm[2] - 1];
        idx[ib] = idx4[perm[3] - 1];
        x[ib - 3] = x4[perm[0] - 1];
        x[ib - 2] = x4[perm[1] - 1];
        x[ib - 1] = x4[perm[2] - 1];
        x[ib] = x4[perm[3] - 1];
        ib = 0;
      }
    }
  }

  if (ib > 0) {
    for (m = 0; m < 4; m++) {
      perm[m] = 0;
    }

    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] <= x4[1]) {
      if (x4[1] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    d_st.site = &gb_emlrtRSI;
    if (ib > 2147483646) {
      e_st.site = &t_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 4; k - 3 <= ib; k++) {
      idx[(k - nNaNs) - ib] = idx4[perm[k - 4] - 1];
      x[(k - nNaNs) - ib] = x4[perm[k - 4] - 1];
    }
  }

  m = asr_s32(nNaNs, 1U);
  d_st.site = &hb_emlrtRSI;
  for (k = 1; k <= m; k++) {
    ib = idx[(k - nNaNs) + 3];
    idx[(k - nNaNs) + 3] = idx[4 - k];
    idx[4 - k] = ib;
    x[(k - nNaNs) + 3] = xwork[4 - k];
    x[4 - k] = xwork[(k - nNaNs) + 3];
  }

  if ((nNaNs & 1) != 0) {
    x[(m - nNaNs) + 4] = xwork[(m - nNaNs) + 4];
  }

  if (4 - nNaNs > 1) {
    c_st.site = &fb_emlrtRSI;
    for (m = 0; m < 4; m++) {
      idx4[m] = 0;
    }

    nPairs = asr_s32(4 - nNaNs, 2U);
    bLen = 4;
    while (nPairs > 1) {
      if ((nPairs & 1) != 0) {
        nPairs--;
        ib = bLen * nPairs;
        m = 4 - (nNaNs + ib);
        if (m > bLen) {
          d_st.site = &ib_emlrtRSI;
          merge(&d_st, idx, x, ib, bLen, m - bLen, idx4, xwork);
        }
      }

      ib = bLen << 1;
      nPairs = asr_s32(nPairs, 1U);
      d_st.site = &jb_emlrtRSI;
      for (k = 1; k <= nPairs; k++) {
        d_st.site = &kb_emlrtRSI;
        merge(&d_st, idx, x, (k - 1) * ib, bLen, bLen, idx4, xwork);
      }

      bLen = ib;
    }

    if (4 - nNaNs > bLen) {
      d_st.site = &lb_emlrtRSI;
      merge(&d_st, idx, x, 0, bLen, 4 - (nNaNs + bLen), idx4, xwork);
    }
  }
}

/* End of code generation (sort1.c) */
