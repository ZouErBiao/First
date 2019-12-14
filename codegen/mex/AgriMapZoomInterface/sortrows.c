/*
 * sortrows.c
 *
 * Code generation for function 'sortrows'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "sortrows.h"
#include "eml_int_forloop_overflow_check.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "sortLE.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRSInfo pc_emlrtRSI = { 52, "sortrows",
  "F:\\MatlabInstall\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m" };

static emlrtRSInfo qc_emlrtRSI = { 53, "sortrows",
  "F:\\MatlabInstall\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m" };

static emlrtRSInfo rc_emlrtRSI = { 54, "sortrows",
  "F:\\MatlabInstall\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m" };

static emlrtRSInfo sc_emlrtRSI = { 78, "sortIdx",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo tc_emlrtRSI = { 101, "sortIdx",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo uc_emlrtRSI = { 239, "sortIdx",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo vc_emlrtRSI = { 292, "sortIdx",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRSInfo wc_emlrtRSI = { 69, "sortrows",
  "F:\\MatlabInstall\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m" };

static emlrtRSInfo xc_emlrtRSI = { 72, "sortrows",
  "F:\\MatlabInstall\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m" };

static emlrtRTEInfo ab_emlrtRTEI = { 1, 20, "sortrows",
  "F:\\MatlabInstall\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m" };

static emlrtRTEInfo jb_emlrtRTEI = { 234, 9, "sortIdx",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRTEInfo kb_emlrtRTEI = { 32, 5, "sortrows",
  "F:\\MatlabInstall\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m" };

static emlrtRTEInfo lb_emlrtRTEI = { 234, 1, "sortIdx",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" };

static emlrtRTEInfo mb_emlrtRTEI = { 67, 1, "sortrows",
  "F:\\MatlabInstall\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m" };

/* Function Definitions */
void sortrows(const emlrtStack *sp, emxArray_real_T *y)
{
  emxArray_int32_T *idx;
  int32_T m;
  int32_T i2;
  int32_T k;
  boolean_T overflow;
  emxArray_int32_T *iwork;
  int32_T n;
  int32_T i;
  int32_T j;
  int32_T pEnd;
  int32_T p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  emxArray_real_T *ycol;
  boolean_T b2;
  boolean_T b3;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_int32_T(sp, &idx, 1, &kb_emlrtRTEI, true);
  m = y->size[0];
  st.site = &pc_emlrtRSI;
  i2 = idx->size[0];
  idx->size[0] = y->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)idx, i2, (int32_T)sizeof(int32_T),
                    &ab_emlrtRTEI);
  k = y->size[0];
  for (i2 = 0; i2 < k; i2++) {
    idx->data[i2] = 0;
  }

  if (y->size[0] == 0) {
    b_st.site = &sc_emlrtRSI;
    if (1 > y->size[0]) {
      overflow = false;
    } else {
      overflow = (y->size[0] > 2147483646);
    }

    if (overflow) {
      c_st.site = &t_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (k = 1; k <= y->size[0]; k++) {
      idx->data[k - 1] = k;
    }
  } else {
    emxInit_int32_T(&st, &iwork, 1, &lb_emlrtRTEI, true);
    b_st.site = &tc_emlrtRSI;
    n = y->size[0] + 1;
    k = y->size[0];
    i2 = iwork->size[0];
    iwork->size[0] = k;
    emxEnsureCapacity(&b_st, (emxArray__common *)iwork, i2, (int32_T)sizeof
                      (int32_T), &jb_emlrtRTEI);
    c_st.site = &uc_emlrtRSI;
    if (1 > y->size[0] - 1) {
      overflow = false;
    } else {
      overflow = (y->size[0] - 1 > 2147483645);
    }

    if (overflow) {
      d_st.site = &t_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 1; k <= n - 2; k += 2) {
      if (sortLE(y, k, k + 1)) {
        idx->data[k - 1] = k;
        idx->data[k] = k + 1;
      } else {
        idx->data[k - 1] = k + 1;
        idx->data[k] = k;
      }
    }

    if ((y->size[0] & 1) != 0) {
      idx->data[y->size[0] - 1] = y->size[0];
    }

    i = 2;
    while (i < n - 1) {
      i2 = i << 1;
      j = 1;
      for (pEnd = 1 + i; pEnd < n; pEnd = qEnd + i) {
        p = j;
        q = pEnd;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }

        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          if (sortLE(y, idx->data[p - 1], idx->data[q - 1])) {
            iwork->data[k] = idx->data[p - 1];
            p++;
            if (p == pEnd) {
              while (q < qEnd) {
                k++;
                iwork->data[k] = idx->data[q - 1];
                q++;
              }
            }
          } else {
            iwork->data[k] = idx->data[q - 1];
            q++;
            if (q == qEnd) {
              while (p < pEnd) {
                k++;
                iwork->data[k] = idx->data[p - 1];
                p++;
              }
            }
          }

          k++;
        }

        c_st.site = &vc_emlrtRSI;
        for (k = 0; k + 1 <= kEnd; k++) {
          idx->data[(j + k) - 1] = iwork->data[k];
        }

        j = qEnd;
      }

      i = i2;
    }

    emxFree_int32_T(&iwork);
  }

  emxInit_real_T1(&st, &ycol, 1, &mb_emlrtRTEI, true);
  st.site = &qc_emlrtRSI;
  pEnd = y->size[0];
  k = y->size[0];
  i2 = ycol->size[0];
  ycol->size[0] = k;
  emxEnsureCapacity(&st, (emxArray__common *)ycol, i2, (int32_T)sizeof(real_T),
                    &ab_emlrtRTEI);
  for (j = 0; j < 2; j++) {
    b_st.site = &wc_emlrtRSI;
    if (1 > pEnd) {
      b2 = false;
    } else {
      b2 = (pEnd > 2147483646);
    }

    if (b2) {
      c_st.site = &t_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (i = 0; i + 1 <= pEnd; i++) {
      ycol->data[i] = y->data[(idx->data[i] + y->size[0] * j) - 1];
    }

    b_st.site = &xc_emlrtRSI;
    for (i = 0; i + 1 <= pEnd; i++) {
      y->data[i + y->size[0] * j] = ycol->data[i];
    }
  }

  emxFree_real_T(&ycol);
  emxFree_int32_T(&idx);
  st.site = &rc_emlrtRSI;
  if (1 > m) {
    b3 = false;
  } else {
    b3 = (m > 2147483646);
  }

  if (b3) {
    b_st.site = &t_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (sortrows.c) */
