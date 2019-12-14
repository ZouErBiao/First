/*
 * judgeClockWise.c
 *
 * Code generation for function 'judgeClockWise'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "judgeClockWise.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRTEInfo rb_emlrtRTEI = { 25, 1, "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m" };

static emlrtDCInfo i_emlrtDCI = { 39, 10, "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m", 1 };

static emlrtBCInfo kd_emlrtBCI = { -1, -1, 39, 10, "lat_in", "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m", 0 };

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 39, 22, "lat_in", "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m", 0 };

static emlrtDCInfo j_emlrtDCI = { 39, 36, "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m", 1 };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 39, 36, "lon_in", "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m", 0 };

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 39, 48, "lon_in", "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m", 0 };

static emlrtBCInfo od_emlrtBCI = { -1, -1, 40, 14, "lon_in", "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m", 0 };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 40, 26, "lon_in", "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m", 0 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 40, 40, "lat_in", "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m", 0 };

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 40, 52, "lat_in", "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m", 0 };

static emlrtRTEInfo sb_emlrtRTEI = { 55, 1, "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m" };

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 59, 16, "lon_in", "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m", 0 };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 59, 44, "lat_in", "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m", 0 };

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 59, 28, "lon_in", "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m", 0 };

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 59, 56, "lat_in", "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m", 0 };

static emlrtBCInfo wd_emlrtBCI = { -1, -1, 57, 20, "lon_in", "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m", 0 };

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 57, 36, "lon_in", "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m", 0 };

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 57, 50, "lat_in", "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m", 0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 57, 66, "lat_in", "judgeClockWise",
  "D:\\2.AgriMapZoom\\judgeClockWise.m", 0 };

/* Function Definitions */
real_T judgeClockWise(const emlrtStack *sp, const emxArray_real_T *lat_in, const
                      emxArray_real_T *lon_in, real_T len)
{
  real_T CWAFlag;
  int32_T i;
  real_T j;
  real_T k;
  int32_T i4;
  int32_T i5;
  real_T d;
  int32_T i6;

  /* % 判断地块是顺时针还是逆时针 */
  /* 输出:顺时针为1，逆时针为0 */
  /* 算法说明： */
  /*  对某一个点计算cross product = ((xi - xi-1),(yi - yi-1)) x ((xi+1 - xi),(yi+1 - yi)) = (xi - xi-1) * (yi+1 - yi) - (yi - yi-1) * (xi+1 - xi) */
  /*  如果上式的值为正，逆时针；为负则是顺时针 */
  /*  而对于一般的简单多边形，则需对于多边形的每一个点计算上述值，如果正值比较多，是逆时针；负值较多则为顺时针。 */
  /*  lat_in:x,lon_in:y */
  /* % */
  /* % 判断 */
  CWAFlag = 0.0;
  if (len < 3.0) {
  } else {
    /* % 叉乘遍历计算 */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, len, mxDOUBLE_CLASS, (int32_T)len,
      &rb_emlrtRTEI, sp);
    i = 0;
    while (i <= (int32_T)len - 1) {
      /*  找到相邻两点 */
      if (len + 1.0 == muDoubleScalarFloor(len + 1.0)) {
        j = ((1.0 + (real_T)i) + 1.0) - muDoubleScalarFloor(((1.0 + (real_T)i) +
          1.0) / (len + 1.0)) * (len + 1.0);
      } else {
        j = ((1.0 + (real_T)i) + 1.0) / (len + 1.0);
        if (muDoubleScalarAbs(j - muDoubleScalarRound(j)) <=
            2.2204460492503131E-16 * muDoubleScalarAbs(j)) {
          j = 0.0;
        } else {
          j = (j - muDoubleScalarFloor(j)) * (len + 1.0);
        }
      }

      if (j == 0.0) {
        j = 1.0;

        /* len; */
      }

      if (len + 1.0 == muDoubleScalarFloor(len + 1.0)) {
        k = ((1.0 + (real_T)i) + 2.0) - muDoubleScalarFloor(((1.0 + (real_T)i) +
          2.0) / (len + 1.0)) * (len + 1.0);
      } else {
        k = ((1.0 + (real_T)i) + 2.0) / (len + 1.0);
        if (muDoubleScalarAbs(k - muDoubleScalarRound(k)) <=
            2.2204460492503131E-16 * muDoubleScalarAbs(k)) {
          k = 0.0;
        } else {
          k = (k - muDoubleScalarFloor(k)) * (len + 1.0);
        }
      }

      if ((1.0 + (real_T)i) + 2.0 > len + 1.0) {
        k = 2.0;
      } else {
        if (k == 0.0) {
          k = 1.0;

          /* len; */
        }
      }

      /*  计算叉乘 */
      if (j != (int32_T)muDoubleScalarFloor(j)) {
        emlrtIntegerCheckR2012b(j, &i_emlrtDCI, sp);
      }

      i4 = lat_in->size[0];
      i5 = (int32_T)j;
      if (!((i5 >= 1) && (i5 <= i4))) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &kd_emlrtBCI, sp);
      }

      i4 = lat_in->size[0];
      i5 = i + 1;
      if (!((i5 >= 1) && (i5 <= i4))) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ld_emlrtBCI, sp);
      }

      if (k != (int32_T)muDoubleScalarFloor(k)) {
        emlrtIntegerCheckR2012b(k, &j_emlrtDCI, sp);
      }

      i4 = lon_in->size[0];
      i5 = (int32_T)k;
      if (!((i5 >= 1) && (i5 <= i4))) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &md_emlrtBCI, sp);
      }

      i4 = lon_in->size[0];
      i5 = (int32_T)j;
      if (!((i5 >= 1) && (i5 <= i4))) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &nd_emlrtBCI, sp);
      }

      i4 = lon_in->size[0];
      i5 = (int32_T)j;
      if (!((i5 >= 1) && (i5 <= i4))) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &od_emlrtBCI, sp);
      }

      i4 = lon_in->size[0];
      i5 = i + 1;
      if (!((i5 >= 1) && (i5 <= i4))) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &pd_emlrtBCI, sp);
      }

      i4 = lat_in->size[0];
      i5 = (int32_T)k;
      if (!((i5 >= 1) && (i5 <= i4))) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &qd_emlrtBCI, sp);
      }

      i4 = lat_in->size[0];
      i5 = (int32_T)j;
      if (!((i5 >= 1) && (i5 <= i4))) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &rd_emlrtBCI, sp);
      }

      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  */
    /* % Green 算法 */
    d = 0.0;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, len - 1.0, mxDOUBLE_CLASS, (int32_T)
      (len - 1.0), &sb_emlrtRTEI, sp);
    i = 0;
    while (i <= (int32_T)(len - 1.0) - 1) {
      /* d += - 0.5 * ( y[i + 1] + y[i]) * (x[i + 1] - x[i]); */
      i4 = lon_in->size[0];
      i5 = (int32_T)((1.0 + (real_T)i) + 1.0);
      if (!((i5 >= 1) && (i5 <= i4))) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &wd_emlrtBCI, sp);
      }

      i4 = lon_in->size[0];
      if (!((i + 1 >= 1) && (i + 1 <= i4))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, i4, &xd_emlrtBCI, sp);
      }

      i4 = lat_in->size[0];
      i6 = (int32_T)((1.0 + (real_T)i) + 1.0);
      if (!((i6 >= 1) && (i6 <= i4))) {
        emlrtDynamicBoundsCheckR2012b(i6, 1, i4, &yd_emlrtBCI, sp);
      }

      i4 = lat_in->size[0];
      if (!((i + 1 >= 1) && (i + 1 <= i4))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, i4, &ae_emlrtBCI, sp);
      }

      d -= 0.5 * (lon_in->data[i5 - 1] + lon_in->data[i]) * (lat_in->data[i6 - 1]
        - lat_in->data[i]);
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    i4 = lon_in->size[0];
    if (!(1 <= i4)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i4, &sd_emlrtBCI, sp);
    }

    i4 = lat_in->size[0];
    if (!(1 <= i4)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i4, &td_emlrtBCI, sp);
    }

    i4 = lon_in->size[0];
    i5 = (int32_T)len;
    if (!((i5 >= 1) && (i5 <= i4))) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ud_emlrtBCI, sp);
    }

    i4 = lat_in->size[0];
    i6 = (int32_T)len;
    if (!((i6 >= 1) && (i6 <= i4))) {
      emlrtDynamicBoundsCheckR2012b(i6, 1, i4, &vd_emlrtBCI, sp);
    }

    d -= 0.5 * (lon_in->data[0] + lon_in->data[i5 - 1]) * (lat_in->data[0] -
      lat_in->data[i6 - 1]);

    /*  */
    if (d >= 0.0) {
      /* 逆时针 */
    } else {
      CWAFlag = 1.0;

      /* 顺时针 */
    }
  }

  return CWAFlag;
}

/* End of code generation (judgeClockWise.c) */
