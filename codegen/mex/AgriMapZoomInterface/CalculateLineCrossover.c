/*
 * CalculateLineCrossover.c
 *
 * Code generation for function 'CalculateLineCrossover'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "CalculateLineCrossover.h"
#include "sort1.h"

/* Variable Definitions */
static emlrtRSInfo x_emlrtRSI = { 6, "CalculateLineCrossover",
  "D:\\2.AgriMapZoom\\CalculateLineCrossover.m" };

static emlrtRSInfo y_emlrtRSI = { 20, "CalculateLineCrossover",
  "D:\\2.AgriMapZoom\\CalculateLineCrossover.m" };

static emlrtRSInfo ab_emlrtRSI = { 38, "CalculateLineCrossover",
  "D:\\2.AgriMapZoom\\CalculateLineCrossover.m" };

static emlrtRSInfo bb_emlrtRSI = { 31, "sort",
  "F:\\MatlabInstall\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" };

/* Function Definitions */
void CalculateLineCrossover(const emlrtStack *sp, real_T x1, real_T b_y1, real_T
  x2, real_T y2, real_T x3, real_T y3, real_T x4, real_T y4, real_T
  LineCrossover[2])
{
  real_T Middle[4];
  real_T a;
  real_T b;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /* 计算两条相交线段之间的交点 */
  if ((x1 != x2) && (b_y1 == y2) && (y2 == y3) && (x3 != x4) && (y3 == y4)) {
    /* 两条线段都与x轴平行 */
    st.site = &x_emlrtRSI;
    Middle[0] = x1;
    Middle[1] = x2;
    Middle[2] = x3;
    Middle[3] = x4;
    b_st.site = &bb_emlrtRSI;
    sort(&b_st, Middle);
    LineCrossover[0] = Middle[2];
    LineCrossover[1] = b_y1;
  } else if ((x1 != x2) && (b_y1 == y2) && (x3 == x4) && (y3 != y4)) {
    /* 第一条鱼x轴平行，第二条与y轴平行 */
    LineCrossover[0] = x3;
    LineCrossover[1] = b_y1;
  } else if ((x1 != x2) && (b_y1 == y2) && (x3 != x4) && (y3 != y4)) {
    /* 第一条鱼x轴平行，第二条不与坐标轴平行 */
    LineCrossover[0] = (b_y1 - y3) * (x4 - x3) / (y4 - y3) + x3;
    LineCrossover[1] = b_y1;
  } else if ((x1 == x2) && (b_y1 != y2) && (x3 != x4) && (y3 == y4)) {
    /* 第一条平行于y轴，第二条平行于x轴 */
    LineCrossover[0] = x1;
    LineCrossover[1] = y3;
  } else if ((x1 == x2) && (b_y1 != y2) && (x1 == x3) && (x3 == x4) && (y3 != y4))
  {
    /* 第一条平行于y轴，第二条平行于y轴 */
    LineCrossover[0] = x1;
    st.site = &y_emlrtRSI;
    Middle[0] = b_y1;
    Middle[1] = y2;
    Middle[2] = y3;
    Middle[3] = y4;
    b_st.site = &bb_emlrtRSI;
    sort(&b_st, Middle);
    LineCrossover[1] = Middle[2];
  } else if ((x1 == x2) && (b_y1 != y2) && (x1 != x3) && (y3 != y4)) {
    /* 第一条平行于y轴，第二条不与任何轴平行 */
    LineCrossover[0] = x1;
    LineCrossover[1] = (y4 - y3) * (x1 - x3) / (x4 - x3) + y3;
  } else if ((x1 != x2) && (b_y1 != y2) && (x3 != x4) && (y3 == y4)) {
    /* 第一条不与任何轴平行，第二条与x轴平行 */
    LineCrossover[0] = (y3 - b_y1) * (x2 - x1) / (y2 - b_y1) + x1;
    LineCrossover[1] = y3;
  } else if ((x1 != x2) && (b_y1 != y2) && (x3 == x4) && (y3 != y4)) {
    LineCrossover[0] = x3;
    LineCrossover[1] = (y2 - b_y1) * (x3 - x1) / (x2 - x1) + b_y1;
  } else {
    a = (y4 - y3) / (x4 - x3);
    b = (y2 - b_y1) / (x2 - x1);
    if (a != b) {
      /* 两线段线斜率不相同 */
      LineCrossover[0] = (((b_y1 - y3) + a * x3) - b * x1) / (a - b);
      LineCrossover[1] = (((a * b * x1 - a * b * x3) + b * y3) - a * b_y1) / (b
        - a);
    } else {
      /* 两线段斜率相同 */
      st.site = &ab_emlrtRSI;
      Middle[0] = x1;
      Middle[1] = x2;
      Middle[2] = x3;
      Middle[3] = x4;
      b_st.site = &bb_emlrtRSI;
      sort(&b_st, Middle);
      LineCrossover[0] = Middle[2];
      LineCrossover[1] = b * (Middle[2] - x1) + b_y1;
    }
  }
}

/* End of code generation (CalculateLineCrossover.c) */
