/*
 * XY2BL.c
 *
 * Code generation for function 'XY2BL'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "XY2BL.h"
#include "mpower.h"
#include "error.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRSInfo pe_emlrtRSI = { 30, "XY2BL", "D:\\2.AgriMapZoom\\XY2BL.m" };

static emlrtRSInfo qe_emlrtRSI = { 39, "XY2BL", "D:\\2.AgriMapZoom\\XY2BL.m" };

static emlrtRSInfo re_emlrtRSI = { 40, "XY2BL", "D:\\2.AgriMapZoom\\XY2BL.m" };

static emlrtRSInfo se_emlrtRSI = { 43, "XY2BL", "D:\\2.AgriMapZoom\\XY2BL.m" };

static emlrtRSInfo te_emlrtRSI = { 44, "XY2BL", "D:\\2.AgriMapZoom\\XY2BL.m" };

/* Function Definitions */
void XY2BL(const emlrtStack *sp, real_T x, real_T y, real_T L0, real_T *B,
           real_T *L)
{
  real_T deltaB;
  int32_T exitg1;
  real_T Bi;
  real_T Bf;
  real_T tf;
  real_T b_x;
  real_T c_x;
  real_T Nf;
  real_T etaf;
  real_T LP;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /* L经度，B纬度 */
  /*  此函数用于进行高斯反算 */
  /*  CGCS2000椭球参数 */
  /*  a=6378137; */
  /*  e=0.081819191042811; */
  /*  ee=0.0820944381518626; */
  /*  1975国际椭球参数 */
  /*  a=6378140; */
  /*  e=0.0818192214555235; */
  /* 使用WGS-84椭球s */
  /*  e1=(sqrt(a^2-b^2))/b;  */
  /*  计算底点的经度 */
  *B = x / 6.3674491458004639E+6;
  deltaB = 1000.0;
  do {
    exitg1 = 0;
    st.site = &pe_emlrtRSI;
    if (deltaB > 1.0000000000000001E-20) {
      Bi = 0.99497289764476393 * (((((x / 6.3354393272027643E+6 +
        0.0025315543040037871 * muDoubleScalarSin(2.0 * *B)) -
        2.656897550951634E-6 * muDoubleScalarSin(4.0 * *B)) +
        3.4700630661423838E-9 * muDoubleScalarSin(6.0 * *B)) -
        4.9154641589109507E-12 * muDoubleScalarSin(8.0 * *B)) +
        6.5545478516430659E-15 * muDoubleScalarSin(10.0 * *B));
      deltaB = muDoubleScalarAbs(Bi - *B);
      *B = Bi;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  Bf = *B;

  /*  计算大地经纬度BL */
  tf = muDoubleScalarTan(*B);
  st.site = &qe_emlrtRSI;
  mpower(0.082094438036854261);
  st.site = &qe_emlrtRSI;
  b_x = 1.0 + 0.0067394967565869036 * muDoubleScalarCos(*B) * muDoubleScalarCos(*
    B);
  if (b_x < 0.0) {
    b_st.site = &o_emlrtRSI;
    error(&b_st);
  }

  st.site = &re_emlrtRSI;
  c_x = 1.0 - mpower(0.081819190928906327) * muDoubleScalarSin(*B) *
    muDoubleScalarSin(*B);
  if (c_x < 0.0) {
    b_st.site = &o_emlrtRSI;
    error(&b_st);
  }

  Nf = 6.378137E+6 / muDoubleScalarSqrt(c_x);
  etaf = 0.082094438036854261 * muDoubleScalarCos(*B);
  st.site = &se_emlrtRSI;
  *B -= 0.5 * mpower(muDoubleScalarSqrt(b_x)) * tf * ((y / Nf * (y / Nf) -
    0.083333333333333329 * (((5.0 + 3.0 * mpower(tf)) + mpower(etaf)) - 9.0 *
    mpower(etaf) * mpower(tf)) * b_mpower(y / Nf)) + 0.0027777777777777779 *
    ((61.0 + 90.0 * mpower(tf)) + 45.0 * b_mpower(tf)) * c_mpower(y / Nf));
  st.site = &te_emlrtRSI;
  LP = 1.0 / muDoubleScalarCos(Bf) * ((y / Nf - 0.16666666666666666 * ((1.0 +
    2.0 * mpower(tf)) + mpower(etaf)) * d_mpower(y / Nf)) +
    0.0083333333333333332 * ((((5.0 + 28.0 * mpower(tf)) + 24.0 * b_mpower(tf))
    + 6.0 * mpower(etaf)) + 8.0 * mpower(etaf) * mpower(tf)) * e_mpower(y / Nf));
  *B = *B / 3.1415926535897931 * 180.0;
  *L = L0 + LP / 3.1415926535897931 * 180.0;
}

/* End of code generation (XY2BL.c) */
