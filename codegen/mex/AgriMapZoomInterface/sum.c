/*
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRSInfo bd_emlrtRSI = { 13, "sum",
  "F:\\MatlabInstall\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" };

static emlrtRSInfo cd_emlrtRSI = { 46, "sumprod",
  "F:\\MatlabInstall\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

static emlrtRSInfo dd_emlrtRSI = { 36, "combine_vector_elements",
  "F:\\MatlabInstall\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

static emlrtRTEInfo gc_emlrtRTEI = { 19, 15, "sumprod",
  "F:\\MatlabInstall\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

static emlrtRTEInfo hc_emlrtRTEI = { 39, 9, "sumprod",
  "F:\\MatlabInstall\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m" };

/* Function Definitions */
real_T sum(const emlrtStack *sp, const emxArray_real_T *x)
{
  real_T y;
  boolean_T overflow;
  boolean_T p;
  int32_T k;
  int32_T exitg1;
  int32_T i23;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if ((x->size[0] == 1) || (x->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &gc_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  overflow = false;
  p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      if (k + 1 <= 1) {
        i23 = x->size[0];
      } else {
        i23 = 1;
      }

      if (i23 != 0) {
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!p) {
  } else {
    overflow = true;
  }

  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &hc_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  b_st.site = &cd_emlrtRSI;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    c_st.site = &dd_emlrtRSI;
    if (2 > x->size[0]) {
      overflow = false;
    } else {
      overflow = (x->size[0] > 2147483646);
    }

    if (overflow) {
      d_st.site = &t_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 2; k <= x->size[0]; k++) {
      y += x->data[k - 1];
    }
  }

  return y;
}

/* End of code generation (sum.c) */
