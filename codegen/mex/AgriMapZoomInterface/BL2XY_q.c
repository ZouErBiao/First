/*
 * BL2XY_q.c
 *
 * Code generation for function 'BL2XY_q'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "BL2XY_q.h"
#include "mpower.h"
#include "error.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRSInfo i_emlrtRSI = { 31, "BL2XY_q", "D:\\2.AgriMapZoom\\BL2XY_q.m"
};

static emlrtRSInfo j_emlrtRSI = { 34, "BL2XY_q", "D:\\2.AgriMapZoom\\BL2XY_q.m"
};

static emlrtRSInfo k_emlrtRSI = { 38, "BL2XY_q", "D:\\2.AgriMapZoom\\BL2XY_q.m"
};

static emlrtRSInfo l_emlrtRSI = { 39, "BL2XY_q", "D:\\2.AgriMapZoom\\BL2XY_q.m"
};

/* Function Definitions */
void BL2XY_q(const emlrtStack *sp, real_T B, real_T L, real_T L0, real_T *x,
             real_T *y)
{
  real_T N;
  real_T eta;
  real_T t;
  real_T m;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /* L经度，B纬度 */
  /* 采用任意带，任意带的中心经线L0，由用户输入 */
  /*  此函数用于进行高斯正算 */
  /* 使用WGS-84椭球 */
  /*  e1=(sqrt(a^2-b^2))/b;  */
  /* k=3;%使用3度带 */
  /*  计算中央子午线经度 */
  /*  if k==6 */
  /*      L0=6*(fix(L/6)+1)-3; */
  /*  elseif k==3 */
  /*      L0=3*(fix((L-1.5)/3)+1); */
  /*  end */
  /* 采用任意带，任意带的中心经线L0，由用户输入 */
  B = B / 180.0 * 3.1415926535897931;

  /*  计算子午圈弧长 */
  st.site = &i_emlrtRSI;
  mpower(0.081819190928906327);

  /*  计算高斯平面坐标 */
  st.site = &j_emlrtRSI;
  mpower(0.081819190928906327);
  st.site = &j_emlrtRSI;
  *x = 1.0 - 0.0066943800042608276 * muDoubleScalarSin(B) * muDoubleScalarSin(B);
  if (*x < 0.0) {
    b_st.site = &o_emlrtRSI;
    error(&b_st);
  }

  N = 6.378137E+6 / muDoubleScalarSqrt(*x);
  eta = 0.082094438036854261 * muDoubleScalarCos(B);
  t = muDoubleScalarTan(B);
  m = muDoubleScalarCos(B) * ((L - L0) / 180.0 * 3.1415926535897931);
  st.site = &k_emlrtRSI;
  *x = 6.3354393272027643E+6 * (((((1.0050525017989294 * B -
    0.0025315543040037871 * muDoubleScalarSin(2.0 * B)) + 2.656897550951634E-6 *
    muDoubleScalarSin(4.0 * B)) - 3.4700630661423838E-9 * muDoubleScalarSin(6.0 *
    B)) + 4.9154641589109507E-12 * muDoubleScalarSin(8.0 * B)) -
    6.5545478516430659E-15 * muDoubleScalarSin(10.0 * B)) + N * t * ((0.5 *
    mpower(m) + 0.041666666666666664 * (((5.0 - mpower(t)) + 9.0 * mpower(eta))
    + 4.0 * b_mpower(eta)) * b_mpower(m)) + 0.0013888888888888889 * ((61.0 -
    58.0 * mpower(t)) + b_mpower(t)) * c_mpower(m));
  st.site = &l_emlrtRSI;
  *y = N * ((m + 0.16666666666666666 * ((1.0 - mpower(t)) + mpower(eta)) *
             d_mpower(m)) + 0.0083333333333333332 * ((((5.0 - 18.0 * mpower(t))
    + b_mpower(t)) + 14.0 * mpower(eta)) - 58.0 * mpower(eta) * mpower(t)) *
            e_mpower(m));
}

/* End of code generation (BL2XY_q.c) */
