/*
 * CalculateIntersection.c
 *
 * Code generation for function 'CalculateIntersection'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "CalculateIntersection.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "sortrows.h"
#include "indexShapeCheck.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRSInfo hc_emlrtRSI = { 63, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtRSInfo ic_emlrtRSI = { 41, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtRSInfo jc_emlrtRSI = { 23, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtRSInfo kc_emlrtRSI = { 22, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtRTEInfo w_emlrtRTEI = { 1, 24, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtRTEInfo x_emlrtRTEI = { 57, 13, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtRTEInfo y_emlrtRTEI = { 58, 13, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtBCInfo ik_emlrtBCI = { -1, -1, 16, 37, "PolygonList",
  "CalculateIntersection", "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtRTEInfo cc_emlrtRTEI = { 20, 5, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtBCInfo jk_emlrtBCI = { -1, -1, 29, 47, "PolygonList",
  "CalculateIntersection", "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo kk_emlrtBCI = { -1, -1, 33, 38, "m1", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo lk_emlrtBCI = { -1, -1, 38, 38, "m0", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtECInfo eb_emlrtECI = { -1, 33, 17, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtBCInfo mk_emlrtBCI = { -1, -1, 38, 20, "mm", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtECInfo fb_emlrtECI = { -1, 38, 17, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtBCInfo nk_emlrtBCI = { -1, -1, 41, 33, "mm", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo ok_emlrtBCI = { -1, -1, 44, 46, "mm", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo pk_emlrtBCI = { -1, -1, 46, 56, "mm", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo qk_emlrtBCI = { -1, -1, 44, 28, "mM", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtECInfo gb_emlrtECI = { -1, 44, 25, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtBCInfo rk_emlrtBCI = { -1, -1, 46, 28, "mM", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtECInfo hb_emlrtECI = { -1, 46, 25, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtBCInfo sk_emlrtBCI = { -1, -1, 48, 47, "mM", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo tk_emlrtBCI = { -1, -1, 48, 28, "mm", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtECInfo ib_emlrtECI = { -1, 48, 25, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtBCInfo uk_emlrtBCI = { -1, -1, 51, 48, "mm", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo vk_emlrtBCI = { -1, -1, 51, 28, "mM", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtECInfo jb_emlrtECI = { -1, 51, 25, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtBCInfo wk_emlrtBCI = { -1, -1, 53, 47, "mM", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo xk_emlrtBCI = { -1, -1, 53, 28, "mm", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtECInfo kb_emlrtECI = { -1, 53, 25, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtRTEInfo dc_emlrtRTEI = { 59, 13, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtBCInfo yk_emlrtBCI = { -1, -1, 60, 20, "cc", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo al_emlrtBCI = { -1, -1, 64, 47, "PolygonList",
  "CalculateIntersection", "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo bl_emlrtBCI = { -1, -1, 63, 16, "dd", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtECInfo lb_emlrtECI = { -1, 63, 13, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtECInfo mb_emlrtECI = { -1, 16, 5, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtBCInfo cl_emlrtBCI = { 1, 100, 29, 17, "ppp",
  "CalculateIntersection", "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo dl_emlrtBCI = { 1, 100, 64, 17, "ppp",
  "CalculateIntersection", "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtECInfo nb_emlrtECI = { -1, 66, 13, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m" };

static emlrtBCInfo el_emlrtBCI = { -1, -1, 41, 51, "m1", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo fl_emlrtBCI = { -1, -1, 50, 38, "m1", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo gl_emlrtBCI = { -1, -1, 45, 46, "m1", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo hl_emlrtBCI = { -1, -1, 45, 28, "mM", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo il_emlrtBCI = { 1, 100, 66, 17, "ppp",
  "CalculateIntersection", "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo jl_emlrtBCI = { -1, -1, 66, 80, "IntersectionPointList",
  "CalculateIntersection", "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtDCInfo u_emlrtDCI = { 66, 80, "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 1 };

static emlrtBCInfo kl_emlrtBCI = { -1, -1, 60, 50, "IntersectionPointList",
  "CalculateIntersection", "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo ll_emlrtBCI = { -1, -1, 60, 53, "mm", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo ml_emlrtBCI = { -1, -1, 60, 74, "PolygonList",
  "CalculateIntersection", "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo nl_emlrtBCI = { -1, -1, 60, 103, "IntersectionPointList",
  "CalculateIntersection", "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo ol_emlrtBCI = { -1, -1, 60, 106, "mm",
  "CalculateIntersection", "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo pl_emlrtBCI = { -1, -1, 60, 127, "PolygonList",
  "CalculateIntersection", "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo ql_emlrtBCI = { -1, -1, 61, 44, "IntersectionPointList",
  "CalculateIntersection", "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo rl_emlrtBCI = { -1, -1, 61, 47, "mm", "CalculateIntersection",
  "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo sl_emlrtBCI = { -1, -1, 61, 68, "PolygonList",
  "CalculateIntersection", "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo tl_emlrtBCI = { -1, -1, 61, 97, "IntersectionPointList",
  "CalculateIntersection", "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo ul_emlrtBCI = { -1, -1, 61, 100, "mm",
  "CalculateIntersection", "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo vl_emlrtBCI = { -1, -1, 61, 121, "PolygonList",
  "CalculateIntersection", "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

static emlrtBCInfo wl_emlrtBCI = { -1, -1, 61, 130, "mm",
  "CalculateIntersection", "D:\\2.AgriMapZoom\\CalculateIntersection.m", 0 };

/* Function Definitions */
void CalculateIntersection(const emlrtStack *sp, const real_T PolygonList_data[],
  const int32_T PolygonList_size[2], real_T PL_Cnt, const real_T
  IntersectionPointList_data[], const int32_T IntersectionPointList_size[2],
  real_T IP_Cnt, real_T ppp[700], real_T *p_Cnt)
{
  int32_T loop_ub;
  int32_T i19;
  int32_T ii;
  int32_T tmp_data[100];
  int32_T iv24[2];
  int32_T b_PolygonList_size[2];
  int32_T PolygonList[2];
  int32_T i20;
  real_T Count;
  int32_T i;
  emxArray_real_T *cc;
  emxArray_real_T *dd;
  emxArray_real_T *r7;
  emxArray_real_T *b_i;
  emxArray_boolean_T *x;
  emxArray_int32_T *b_ii;
  emxArray_real_T *c_i;
  emxArray_real_T *IntersectionPointList;
  int32_T nx;
  int32_T idx;
  boolean_T exitg3;
  boolean_T guard3 = false;
  int32_T m0_size_idx_0;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int32_T mm_size_idx_0;
  real_T mm_data[100];
  int32_T b_tmp_data[50];
  int32_T iv25[1];
  int32_T m1[1];
  real_T i_data[50];
  real_T mc_idx_4;
  int32_T mM_size_idx_0;
  real_T mM_data[100];
  int32_T iv26[1];
  int32_T m0[1];
  int32_T j;
  real_T d_i;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T mc_idx_3;
  int32_T iv27[1];
  int32_T mm[1];
  int32_T iv28[1];
  int32_T b_mm[1];
  int32_T iv29[1];
  int32_T mM[1];
  int32_T c_tmp_data[99];
  int32_T iv30[1];
  int32_T c_mm[1];
  int32_T iv31[1];
  int32_T b_mM[1];
  int32_T tt;
  int32_T c_ii[2];
  int32_T d_ii[2];
  int32_T b_IntersectionPointList[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* 插入矩阵 */
  /* { */
  /* 输入： */
  /* PolygonList：被插入点集，格式为：PL_Cnt乘以7 */
  /* PL_Cnt：PolygonList的点个数 */
  /* IntersectionPointList：插入点的点集，格式为IP_Cnt乘以7 */
  /* IP_Cnt：IntersectionPointList的点的个数 */
  /* 输出： */
  /* ppp：合并后的点集 */
  /* } */
  memset(&ppp[0], 0, 700U * sizeof(real_T));
  *p_Cnt = 0.0;
  if (IP_Cnt == 0.0) {
    if (1.0 > PL_Cnt) {
      loop_ub = -1;
    } else {
      if (!(1 <= PolygonList_size[0])) {
        emlrtDynamicBoundsCheckR2012b(1, 1, PolygonList_size[0], &ik_emlrtBCI,
          sp);
      }

      i19 = (int32_T)PL_Cnt;
      if (!((i19 >= 1) && (i19 <= PolygonList_size[0]))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, PolygonList_size[0], &ik_emlrtBCI,
          sp);
      }

      loop_ub = i19 - 1;
    }

    if (1.0 > PL_Cnt) {
      ii = 0;
    } else {
      ii = (int32_T)PL_Cnt;
    }

    for (i19 = 0; i19 < ii; i19++) {
      tmp_data[i19] = i19;
    }

    iv24[0] = ii;
    iv24[1] = 7;
    b_PolygonList_size[0] = loop_ub + 1;
    b_PolygonList_size[1] = 7;
    for (i19 = 0; i19 < 2; i19++) {
      PolygonList[i19] = b_PolygonList_size[i19];
    }

    emlrtSubAssignSizeCheckR2012b(iv24, 2, PolygonList, 2, &mb_emlrtECI, sp);
    for (i19 = 0; i19 < 7; i19++) {
      for (i20 = 0; i20 <= loop_ub; i20++) {
        ppp[tmp_data[i20] + 100 * i19] = PolygonList_data[i20 +
          PolygonList_size[0] * i19];
      }
    }

    *p_Cnt = PL_Cnt;
  } else {
    Count = 0.0;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, PL_Cnt, mxDOUBLE_CLASS, (int32_T)
      PL_Cnt, &cc_emlrtRTEI, sp);
    i = 1;
    emxInit_real_T(sp, &cc, 2, &x_emlrtRTEI, true);
    emxInit_real_T(sp, &dd, 2, &y_emlrtRTEI, true);
    emxInit_real_T(sp, &r7, 2, &w_emlrtRTEI, true);
    emxInit_real_T1(sp, &b_i, 1, &w_emlrtRTEI, true);
    emxInit_boolean_T(sp, &x, 1, &w_emlrtRTEI, true);
    emxInit_int32_T(sp, &b_ii, 1, &v_emlrtRTEI, true);
    emxInit_real_T1(sp, &c_i, 1, &w_emlrtRTEI, true);
    emxInit_real_T(sp, &IntersectionPointList, 2, &w_emlrtRTEI, true);
    while (i - 1 <= (int32_T)PL_Cnt - 1) {
      st.site = &kc_emlrtRSI;
      loop_ub = IntersectionPointList_size[0];
      i19 = x->size[0];
      x->size[0] = IntersectionPointList_size[0];
      emxEnsureCapacity(&st, (emxArray__common *)x, i19, (int32_T)sizeof
                        (boolean_T), &w_emlrtRTEI);
      for (i19 = 0; i19 < loop_ub; i19++) {
        x->data[i19] = (IntersectionPointList_data[i19 +
                        IntersectionPointList_size[0] * 5] == 1.0 + (real_T)(i -
          1));
      }

      b_st.site = &lc_emlrtRSI;
      nx = x->size[0];
      idx = 0;
      i19 = b_ii->size[0];
      b_ii->size[0] = x->size[0];
      emxEnsureCapacity(&b_st, (emxArray__common *)b_ii, i19, (int32_T)sizeof
                        (int32_T), &w_emlrtRTEI);
      ii = 1;
      exitg3 = false;
      while ((!exitg3) && (ii <= nx)) {
        guard3 = false;
        if (x->data[ii - 1]) {
          idx++;
          b_ii->data[idx - 1] = ii;
          if (idx >= nx) {
            exitg3 = true;
          } else {
            guard3 = true;
          }
        } else {
          guard3 = true;
        }

        if (guard3) {
          ii++;
        }
      }

      if (idx <= x->size[0]) {
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &yb_emlrtRTEI,
          "Coder:builtins:AssertionFailed", 0);
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          i19 = b_ii->size[0];
          b_ii->size[0] = 0;
          emxEnsureCapacity(&b_st, (emxArray__common *)b_ii, i19, (int32_T)
                            sizeof(int32_T), &w_emlrtRTEI);
        }
      } else {
        if (1 > idx) {
          i19 = 0;
        } else {
          i19 = idx;
        }

        iv24[0] = 1;
        iv24[1] = i19;
        c_st.site = &nc_emlrtRSI;
        indexShapeCheck(&c_st, b_ii->size[0], iv24);
        i20 = b_ii->size[0];
        b_ii->size[0] = i19;
        emxEnsureCapacity(&b_st, (emxArray__common *)b_ii, i20, (int32_T)sizeof
                          (int32_T), &o_emlrtRTEI);
      }

      i19 = b_i->size[0];
      b_i->size[0] = b_ii->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)b_i, i19, (int32_T)sizeof
                        (real_T), &w_emlrtRTEI);
      loop_ub = b_ii->size[0];
      for (i19 = 0; i19 < loop_ub; i19++) {
        b_i->data[i19] = b_ii->data[i19];
      }

      m0_size_idx_0 = b_ii->size[0];
      st.site = &jc_emlrtRSI;
      loop_ub = IntersectionPointList_size[0];
      i19 = x->size[0];
      x->size[0] = IntersectionPointList_size[0];
      emxEnsureCapacity(&st, (emxArray__common *)x, i19, (int32_T)sizeof
                        (boolean_T), &w_emlrtRTEI);
      for (i19 = 0; i19 < loop_ub; i19++) {
        x->data[i19] = (IntersectionPointList_data[i19 +
                        IntersectionPointList_size[0] * 6] == 1.0 + (real_T)(i -
          1));
      }

      b_st.site = &lc_emlrtRSI;
      nx = x->size[0];
      idx = 0;
      i19 = b_ii->size[0];
      b_ii->size[0] = x->size[0];
      emxEnsureCapacity(&b_st, (emxArray__common *)b_ii, i19, (int32_T)sizeof
                        (int32_T), &w_emlrtRTEI);
      ii = 1;
      exitg2 = false;
      while ((!exitg2) && (ii <= nx)) {
        guard2 = false;
        if (x->data[ii - 1]) {
          idx++;
          b_ii->data[idx - 1] = ii;
          if (idx >= nx) {
            exitg2 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          ii++;
        }
      }

      if (idx <= x->size[0]) {
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &yb_emlrtRTEI,
          "Coder:builtins:AssertionFailed", 0);
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          i19 = b_ii->size[0];
          b_ii->size[0] = 0;
          emxEnsureCapacity(&b_st, (emxArray__common *)b_ii, i19, (int32_T)
                            sizeof(int32_T), &w_emlrtRTEI);
        }
      } else {
        if (1 > idx) {
          i19 = 0;
        } else {
          i19 = idx;
        }

        b_PolygonList_size[0] = 1;
        b_PolygonList_size[1] = i19;
        c_st.site = &nc_emlrtRSI;
        indexShapeCheck(&c_st, b_ii->size[0], b_PolygonList_size);
        i20 = b_ii->size[0];
        b_ii->size[0] = i19;
        emxEnsureCapacity(&b_st, (emxArray__common *)b_ii, i20, (int32_T)sizeof
                          (int32_T), &o_emlrtRTEI);
      }

      i19 = c_i->size[0];
      c_i->size[0] = b_ii->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)c_i, i19, (int32_T)sizeof
                        (real_T), &w_emlrtRTEI);
      loop_ub = b_ii->size[0];
      for (i19 = 0; i19 < loop_ub; i19++) {
        c_i->data[i19] = b_ii->data[i19];
      }

      ii = b_ii->size[0];

      /* 找到各交点所在边的起始顶点，并排续 */
      if ((c_i->size[0] == 0) && (b_i->size[0] == 0)) {
        Count++;
        if (!((i >= 1) && (i <= PolygonList_size[0]))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, PolygonList_size[0], &jk_emlrtBCI,
            sp);
        }

        i19 = (int32_T)Count;
        if (!((i19 >= 1) && (i19 <= 100))) {
          emlrtDynamicBoundsCheckR2012b(i19, 1, 100, &cl_emlrtBCI, sp);
        }

        for (i19 = 0; i19 < 7; i19++) {
          ppp[((int32_T)Count + 100 * i19) - 1] = PolygonList_data[(i +
            PolygonList_size[0] * i19) - 1];
        }
      } else {
        if (b_i->size[0] == 0) {
          mm_size_idx_0 = c_i->size[0];
          loop_ub = c_i->size[0];
          for (i19 = 0; i19 < loop_ub; i19++) {
            mm_data[i19] = 0.0;
          }

          if (1 > ii) {
            loop_ub = -1;
          } else {
            i19 = c_i->size[0];
            if (!(1 <= i19)) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i19, &kk_emlrtBCI, sp);
            }

            i19 = c_i->size[0];
            if (!(ii <= i19)) {
              emlrtDynamicBoundsCheckR2012b(ii, 1, i19, &kk_emlrtBCI, sp);
            }

            loop_ub = ii - 1;
          }

          if (1 > ii) {
            ii = 0;
          }

          for (i19 = 0; i19 < ii; i19++) {
            b_tmp_data[i19] = i19;
          }

          iv25[0] = ii;
          m1[0] = loop_ub + 1;
          emlrtSubAssignSizeCheckR2012b(iv25, 1, m1, 1, &eb_emlrtECI, sp);
          ii = c_i->size[0];
          for (i19 = 0; i19 < ii; i19++) {
            i_data[i19] = c_i->data[i19];
          }

          for (i19 = 0; i19 <= loop_ub; i19++) {
            mm_data[b_tmp_data[i19]] = i_data[i19];
          }

          mc_idx_4 = c_i->size[0];
        } else {
          mm_size_idx_0 = c_i->size[0] + b_i->size[0];
          loop_ub = c_i->size[0] + b_i->size[0];
          for (i19 = 0; i19 < loop_ub; i19++) {
            mm_data[i19] = 0.0;
          }

          mM_size_idx_0 = c_i->size[0] + b_i->size[0];
          loop_ub = c_i->size[0] + b_i->size[0];
          for (i19 = 0; i19 < loop_ub; i19++) {
            mM_data[i19] = 0.0;
          }

          i19 = b_i->size[0];
          if (!(1 <= i19)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i19, &lk_emlrtBCI, sp);
          }

          i19 = b_i->size[0];
          if (!((m0_size_idx_0 >= 1) && (m0_size_idx_0 <= i19))) {
            emlrtDynamicBoundsCheckR2012b(m0_size_idx_0, 1, i19, &lk_emlrtBCI,
              sp);
          }

          i19 = ii + m0_size_idx_0;
          if (!((m0_size_idx_0 >= 1) && (m0_size_idx_0 <= i19))) {
            emlrtDynamicBoundsCheckR2012b(m0_size_idx_0, 1, i19, &mk_emlrtBCI,
              sp);
          }

          loop_ub = b_i->size[0];
          for (i19 = 0; i19 < loop_ub; i19++) {
            b_tmp_data[i19] = i19;
          }

          iv26[0] = loop_ub;
          m0[0] = m0_size_idx_0;
          emlrtSubAssignSizeCheckR2012b(iv26, 1, m0, 1, &fb_emlrtECI, sp);
          loop_ub = b_i->size[0];
          for (i19 = 0; i19 < loop_ub; i19++) {
            i_data[i19] = b_i->data[i19];
          }

          loop_ub = b_i->size[0] - 1;
          for (i19 = 0; i19 <= loop_ub; i19++) {
            mm_data[b_tmp_data[i19]] = i_data[i19];
          }

          mc_idx_4 = b_i->size[0];
          j = 1;
          while (j - 1 <= c_i->size[0] - 1) {
            i19 = (int32_T)mc_idx_4;
            if (!((i19 >= 1) && (i19 <= mm_size_idx_0))) {
              emlrtDynamicBoundsCheckR2012b(i19, 1, mm_size_idx_0, &nk_emlrtBCI,
                sp);
            }

            st.site = &ic_emlrtRSI;
            loop_ub = (int32_T)mc_idx_4;
            ii = c_i->size[0];
            for (i19 = 0; i19 < ii; i19++) {
              i_data[i19] = c_i->data[i19];
            }

            i19 = c_i->size[0];
            if (!((j >= 1) && (j <= i19))) {
              emlrtDynamicBoundsCheckR2012b(j, 1, i19, &el_emlrtBCI, &st);
            }

            d_i = i_data[j - 1];
            i19 = x->size[0];
            x->size[0] = (int32_T)mc_idx_4;
            emxEnsureCapacity(&st, (emxArray__common *)x, i19, (int32_T)sizeof
                              (boolean_T), &w_emlrtRTEI);
            for (i19 = 0; i19 < loop_ub; i19++) {
              x->data[i19] = (mm_data[i19] < d_i);
            }

            b_st.site = &lc_emlrtRSI;
            nx = x->size[0];
            idx = 0;
            i19 = b_ii->size[0];
            b_ii->size[0] = x->size[0];
            emxEnsureCapacity(&b_st, (emxArray__common *)b_ii, i19, (int32_T)
                              sizeof(int32_T), &w_emlrtRTEI);
            ii = 1;
            exitg1 = false;
            while ((!exitg1) && (ii <= nx)) {
              guard1 = false;
              if (x->data[ii - 1]) {
                idx++;
                b_ii->data[idx - 1] = ii;
                if (idx >= nx) {
                  exitg1 = true;
                } else {
                  guard1 = true;
                }
              } else {
                guard1 = true;
              }

              if (guard1) {
                ii++;
              }
            }

            if (idx <= x->size[0]) {
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &yb_emlrtRTEI,
                "Coder:builtins:AssertionFailed", 0);
            }

            if (x->size[0] == 1) {
              if (idx == 0) {
                i19 = b_ii->size[0];
                b_ii->size[0] = 0;
                emxEnsureCapacity(&b_st, (emxArray__common *)b_ii, i19, (int32_T)
                                  sizeof(int32_T), &w_emlrtRTEI);
              }
            } else {
              if (1 > idx) {
                i19 = 0;
              } else {
                i19 = idx;
              }

              PolygonList[0] = 1;
              PolygonList[1] = i19;
              c_st.site = &nc_emlrtRSI;
              indexShapeCheck(&c_st, b_ii->size[0], PolygonList);
              i20 = b_ii->size[0];
              b_ii->size[0] = i19;
              emxEnsureCapacity(&b_st, (emxArray__common *)b_ii, i20, (int32_T)
                                sizeof(int32_T), &o_emlrtRTEI);
            }

            i19 = b_i->size[0];
            b_i->size[0] = b_ii->size[0];
            emxEnsureCapacity(&st, (emxArray__common *)b_i, i19, (int32_T)sizeof
                              (real_T), &w_emlrtRTEI);
            loop_ub = b_ii->size[0];
            for (i19 = 0; i19 < loop_ub; i19++) {
              b_i->data[i19] = b_ii->data[i19];
            }

            ii = b_ii->size[0];
            mc_idx_3 = b_ii->size[0];
            if (b_i->size[0] > 0) {
              if (!((ii >= 1) && (ii <= mm_size_idx_0))) {
                emlrtDynamicBoundsCheckR2012b(ii, 1, mm_size_idx_0, &ok_emlrtBCI,
                  sp);
              }

              if (!((ii >= 1) && (ii <= mM_size_idx_0))) {
                emlrtDynamicBoundsCheckR2012b(ii, 1, mM_size_idx_0, &qk_emlrtBCI,
                  sp);
              }

              loop_ub = b_ii->size[0];
              for (i19 = 0; i19 < loop_ub; i19++) {
                tmp_data[i19] = i19;
              }

              iv27[0] = loop_ub;
              mm[0] = mc_idx_3;
              emlrtSubAssignSizeCheckR2012b(iv27, 1, mm, 1, &gb_emlrtECI, sp);
              loop_ub = b_i->size[0] - 1;
              for (i19 = 0; i19 <= loop_ub; i19++) {
                mM_data[tmp_data[i19]] = mm_data[i19];
              }

              loop_ub = c_i->size[0];
              for (i19 = 0; i19 < loop_ub; i19++) {
                i_data[i19] = c_i->data[i19];
              }

              i19 = c_i->size[0];
              if (!((j >= 1) && (j <= i19))) {
                emlrtDynamicBoundsCheckR2012b(j, 1, i19, &gl_emlrtBCI, sp);
              }

              i19 = b_i->size[0] + 1;
              if (!((i19 >= 1) && (i19 <= mM_size_idx_0))) {
                emlrtDynamicBoundsCheckR2012b(i19, 1, mM_size_idx_0,
                  &hl_emlrtBCI, sp);
              }

              mM_data[i19 - 1] = i_data[j - 1];
              if ((real_T)mc_idx_3 + 1.0 > mc_idx_4) {
                i19 = 0;
                i20 = 0;
              } else {
                if (!((ii + 1 >= 1) && (ii + 1 <= mm_size_idx_0))) {
                  emlrtDynamicBoundsCheckR2012b(ii + 1, 1, mm_size_idx_0,
                    &pk_emlrtBCI, sp);
                }

                i19 = ii;
                i20 = (int32_T)mc_idx_4;
                if (!((i20 >= 1) && (i20 <= mm_size_idx_0))) {
                  emlrtDynamicBoundsCheckR2012b(i20, 1, mm_size_idx_0,
                    &pk_emlrtBCI, sp);
                }
              }

              if ((real_T)mc_idx_3 + 2.0 > mc_idx_4 + 1.0) {
                nx = 0;
                idx = 0;
              } else {
                if (!((ii + 2 >= 1) && (ii + 2 <= mM_size_idx_0))) {
                  emlrtDynamicBoundsCheckR2012b(ii + 2, 1, mM_size_idx_0,
                    &rk_emlrtBCI, sp);
                }

                nx = ii + 1;
                idx = (int32_T)(mc_idx_4 + 1.0);
                if (!((idx >= 1) && (idx <= mM_size_idx_0))) {
                  emlrtDynamicBoundsCheckR2012b(idx, 1, mM_size_idx_0,
                    &rk_emlrtBCI, sp);
                }
              }

              loop_ub = idx - nx;
              for (ii = 0; ii < loop_ub; ii++) {
                tmp_data[ii] = nx + ii;
              }

              iv28[0] = idx - nx;
              b_mm[0] = i20 - i19;
              emlrtSubAssignSizeCheckR2012b(iv28, 1, b_mm, 1, &hb_emlrtECI, sp);
              loop_ub = i20 - i19;
              for (i20 = 0; i20 < loop_ub; i20++) {
                mM_data[tmp_data[i20]] = mm_data[i19 + i20];
              }

              mc_idx_4++;
              i19 = (int32_T)mc_idx_4;
              if (!((i19 >= 1) && (i19 <= mM_size_idx_0))) {
                emlrtDynamicBoundsCheckR2012b(i19, 1, mM_size_idx_0,
                  &sk_emlrtBCI, sp);
              }

              i19 = (int32_T)mc_idx_4;
              if (!((i19 >= 1) && (i19 <= mm_size_idx_0))) {
                emlrtDynamicBoundsCheckR2012b(i19, 1, mm_size_idx_0,
                  &tk_emlrtBCI, sp);
              }

              loop_ub = (int32_T)mc_idx_4;
              for (i19 = 0; i19 < loop_ub; i19++) {
                tmp_data[i19] = i19;
              }

              iv29[0] = (int32_T)mc_idx_4;
              mM[0] = (int32_T)mc_idx_4;
              emlrtSubAssignSizeCheckR2012b(iv29, 1, mM, 1, &ib_emlrtECI, sp);
              loop_ub = (int32_T)mc_idx_4 - 1;
              for (i19 = 0; i19 <= loop_ub; i19++) {
                mm_data[tmp_data[i19]] = mM_data[i19];
              }
            } else {
              loop_ub = c_i->size[0];
              for (i19 = 0; i19 < loop_ub; i19++) {
                i_data[i19] = c_i->data[i19];
              }

              i19 = c_i->size[0];
              if (!((j >= 1) && (j <= i19))) {
                emlrtDynamicBoundsCheckR2012b(j, 1, i19, &fl_emlrtBCI, sp);
              }

              mM_data[0] = i_data[j - 1];
              i19 = (int32_T)mc_idx_4;
              if (!((i19 >= 1) && (i19 <= mm_size_idx_0))) {
                emlrtDynamicBoundsCheckR2012b(i19, 1, mm_size_idx_0,
                  &uk_emlrtBCI, sp);
              }

              if (!(2 <= mM_size_idx_0)) {
                emlrtDynamicBoundsCheckR2012b(2, 1, mM_size_idx_0, &vk_emlrtBCI,
                  sp);
              }

              i19 = (int32_T)(mc_idx_4 + 1.0);
              if (!((i19 >= 1) && (i19 <= mM_size_idx_0))) {
                emlrtDynamicBoundsCheckR2012b(i19, 1, mM_size_idx_0,
                  &vk_emlrtBCI, sp);
              }

              loop_ub = (int32_T)(mc_idx_4 + 1.0) - 2;
              for (i19 = 0; i19 <= loop_ub; i19++) {
                c_tmp_data[i19] = 1 + i19;
              }

              iv30[0] = (int32_T)(mc_idx_4 + 1.0) - 1;
              c_mm[0] = (int32_T)mc_idx_4;
              emlrtSubAssignSizeCheckR2012b(iv30, 1, c_mm, 1, &jb_emlrtECI, sp);
              loop_ub = (int32_T)mc_idx_4 - 1;
              for (i19 = 0; i19 <= loop_ub; i19++) {
                mM_data[c_tmp_data[i19]] = mm_data[i19];
              }

              mc_idx_4++;
              i19 = (int32_T)mc_idx_4;
              if (!((i19 >= 1) && (i19 <= mM_size_idx_0))) {
                emlrtDynamicBoundsCheckR2012b(i19, 1, mM_size_idx_0,
                  &wk_emlrtBCI, sp);
              }

              i19 = (int32_T)mc_idx_4;
              if (!((i19 >= 1) && (i19 <= mm_size_idx_0))) {
                emlrtDynamicBoundsCheckR2012b(i19, 1, mm_size_idx_0,
                  &xk_emlrtBCI, sp);
              }

              loop_ub = (int32_T)mc_idx_4;
              for (i19 = 0; i19 < loop_ub; i19++) {
                tmp_data[i19] = i19;
              }

              iv31[0] = (int32_T)mc_idx_4;
              b_mM[0] = (int32_T)mc_idx_4;
              emlrtSubAssignSizeCheckR2012b(iv31, 1, b_mM, 1, &kb_emlrtECI, sp);
              loop_ub = (int32_T)mc_idx_4 - 1;
              for (i19 = 0; i19 <= loop_ub; i19++) {
                mm_data[tmp_data[i19]] = mM_data[i19];
              }

              /* 在开头处插入一个值 */
            }

            j++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(sp);
            }
          }

          /* m0为以i为起始点的边上有几个交点 */
        }

        i19 = cc->size[0] * cc->size[1];
        cc->size[0] = (int32_T)mc_idx_4;
        cc->size[1] = 2;
        emxEnsureCapacity(sp, (emxArray__common *)cc, i19, (int32_T)sizeof
                          (real_T), &w_emlrtRTEI);
        loop_ub = (int32_T)mc_idx_4 << 1;
        for (i19 = 0; i19 < loop_ub; i19++) {
          cc->data[i19] = 1.0;
        }

        i19 = dd->size[0] * dd->size[1];
        dd->size[0] = (int32_T)mc_idx_4;
        dd->size[1] = 2;
        emxEnsureCapacity(sp, (emxArray__common *)dd, i19, (int32_T)sizeof
                          (real_T), &w_emlrtRTEI);
        loop_ub = (int32_T)mc_idx_4 << 1;
        for (i19 = 0; i19 < loop_ub; i19++) {
          dd->data[i19] = 0.0;
        }

        emlrtForLoopVectorCheckR2012b(1.0, 1.0, mc_idx_4, mxDOUBLE_CLASS,
          (int32_T)mc_idx_4, &dc_emlrtRTEI, sp);
        tt = 1;
        while (tt - 1 <= (int32_T)mc_idx_4 - 1) {
          ii = cc->size[0];
          if (!((tt >= 1) && (tt <= ii))) {
            emlrtDynamicBoundsCheckR2012b(tt, 1, ii, &yk_emlrtBCI, sp);
          }

          if (!((tt >= 1) && (tt <= mm_size_idx_0))) {
            emlrtDynamicBoundsCheckR2012b(tt, 1, mm_size_idx_0, &ll_emlrtBCI, sp);
          }

          i19 = (int32_T)mm_data[tt - 1];
          if (!((i19 >= 1) && (i19 <= IntersectionPointList_size[0]))) {
            emlrtDynamicBoundsCheckR2012b(i19, 1, IntersectionPointList_size[0],
              &kl_emlrtBCI, sp);
          }

          if (!((i >= 1) && (i <= PolygonList_size[0]))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, PolygonList_size[0],
              &ml_emlrtBCI, sp);
          }

          if (!((tt >= 1) && (tt <= mm_size_idx_0))) {
            emlrtDynamicBoundsCheckR2012b(tt, 1, mm_size_idx_0, &ol_emlrtBCI, sp);
          }

          i20 = (int32_T)mm_data[tt - 1];
          if (!((i20 >= 1) && (i20 <= IntersectionPointList_size[0]))) {
            emlrtDynamicBoundsCheckR2012b(i20, 1, IntersectionPointList_size[0],
              &nl_emlrtBCI, sp);
          }

          if (!((i >= 1) && (i <= PolygonList_size[0]))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, PolygonList_size[0],
              &pl_emlrtBCI, sp);
          }

          if (!((tt >= 1) && (tt <= mm_size_idx_0))) {
            emlrtDynamicBoundsCheckR2012b(tt, 1, mm_size_idx_0, &rl_emlrtBCI, sp);
          }

          nx = (int32_T)mm_data[tt - 1];
          if (!((nx >= 1) && (nx <= IntersectionPointList_size[0]))) {
            emlrtDynamicBoundsCheckR2012b(nx, 1, IntersectionPointList_size[0],
              &ql_emlrtBCI, sp);
          }

          if (!((i >= 1) && (i <= PolygonList_size[0]))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, PolygonList_size[0],
              &sl_emlrtBCI, sp);
          }

          if (!((tt >= 1) && (tt <= mm_size_idx_0))) {
            emlrtDynamicBoundsCheckR2012b(tt, 1, mm_size_idx_0, &ul_emlrtBCI, sp);
          }

          idx = (int32_T)mm_data[tt - 1];
          if (!((idx >= 1) && (idx <= IntersectionPointList_size[0]))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, IntersectionPointList_size[0],
              &tl_emlrtBCI, sp);
          }

          if (!((i >= 1) && (i <= PolygonList_size[0]))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, PolygonList_size[0],
              &vl_emlrtBCI, sp);
          }

          cc->data[tt - 1] = (IntersectionPointList_data[(i19 +
            IntersectionPointList_size[0] * 3) - 1] - PolygonList_data[(i +
            PolygonList_size[0] * 3) - 1]) * (IntersectionPointList_data[(i20 +
            IntersectionPointList_size[0] * 3) - 1] - PolygonList_data[(i +
            PolygonList_size[0] * 3) - 1]) + (IntersectionPointList_data[(nx +
            (IntersectionPointList_size[0] << 2)) - 1] - PolygonList_data[(i +
            (PolygonList_size[0] << 2)) - 1]) * (IntersectionPointList_data[(idx
            + (IntersectionPointList_size[0] << 2)) - 1] - PolygonList_data[(i +
            (PolygonList_size[0] << 2)) - 1]);
          if (!((tt >= 1) && (tt <= mm_size_idx_0))) {
            emlrtDynamicBoundsCheckR2012b(tt, 1, mm_size_idx_0, &wl_emlrtBCI, sp);
          }

          cc->data[(tt + cc->size[0]) - 1] = mm_data[tt - 1];
          tt++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        if (1.0 > mc_idx_4) {
          loop_ub = 0;
        } else {
          i19 = (int32_T)mc_idx_4;
          if (!(1 <= i19)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i19, &bl_emlrtBCI, sp);
          }

          i19 = (int32_T)mc_idx_4;
          loop_ub = (int32_T)mc_idx_4;
          if (!((loop_ub >= 1) && (loop_ub <= i19))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i19, &bl_emlrtBCI, sp);
          }
        }

        i19 = b_ii->size[0];
        b_ii->size[0] = loop_ub;
        emxEnsureCapacity(sp, (emxArray__common *)b_ii, i19, (int32_T)sizeof
                          (int32_T), &w_emlrtRTEI);
        for (i19 = 0; i19 < loop_ub; i19++) {
          b_ii->data[i19] = i19;
        }

        st.site = &hc_emlrtRSI;
        sortrows(&st, cc);
        c_ii[0] = b_ii->size[0];
        c_ii[1] = 2;
        emlrtSubAssignSizeCheckR2012b(c_ii, 2, *(int32_T (*)[2])cc->size, 2,
          &lb_emlrtECI, sp);
        for (i19 = 0; i19 < 2; i19++) {
          loop_ub = cc->size[0];
          for (i20 = 0; i20 < loop_ub; i20++) {
            dd->data[b_ii->data[i20] + dd->size[0] * i19] = cc->data[i20 +
              cc->size[0] * i19];
          }
        }

        /* 对矩阵cc进行按第一列升序排列 */
        if (!((i >= 1) && (i <= PolygonList_size[0]))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, PolygonList_size[0], &al_emlrtBCI,
            sp);
        }

        i19 = (int32_T)(Count + 1.0);
        if (!((i19 >= 1) && (i19 <= 100))) {
          emlrtDynamicBoundsCheckR2012b(i19, 1, 100, &dl_emlrtBCI, sp);
        }

        for (i19 = 0; i19 < 7; i19++) {
          ppp[((int32_T)(Count + 1.0) + 100 * i19) - 1] = PolygonList_data[(i +
            PolygonList_size[0] * i19) - 1];
        }

        Count++;
        i19 = b_ii->size[0];
        b_ii->size[0] = (int32_T)(mc_idx_4 - 1.0) + 1;
        emxEnsureCapacity(sp, (emxArray__common *)b_ii, i19, (int32_T)sizeof
                          (int32_T), &w_emlrtRTEI);
        loop_ub = (int32_T)(mc_idx_4 - 1.0);
        for (i19 = 0; i19 <= loop_ub; i19++) {
          i20 = (int32_T)(Count + (1.0 + (real_T)i19));
          if (!((i20 >= 1) && (i20 <= 100))) {
            emlrtDynamicBoundsCheckR2012b(i20, 1, 100, &il_emlrtBCI, sp);
          }

          b_ii->data[i19] = i20 - 1;
        }

        loop_ub = dd->size[0];
        i19 = r7->size[0] * r7->size[1];
        r7->size[0] = loop_ub;
        r7->size[1] = 7;
        emxEnsureCapacity(sp, (emxArray__common *)r7, i19, (int32_T)sizeof
                          (real_T), &w_emlrtRTEI);
        for (i19 = 0; i19 < 7; i19++) {
          for (i20 = 0; i20 < loop_ub; i20++) {
            d_i = dd->data[i20 + dd->size[0]];
            if (d_i != (int32_T)muDoubleScalarFloor(d_i)) {
              emlrtIntegerCheckR2012b(d_i, &u_emlrtDCI, sp);
            }

            nx = (int32_T)d_i;
            if (!((nx >= 1) && (nx <= IntersectionPointList_size[0]))) {
              emlrtDynamicBoundsCheckR2012b(nx, 1, IntersectionPointList_size[0],
                &jl_emlrtBCI, sp);
            }

            r7->data[i20 + r7->size[0] * i19] = IntersectionPointList_data[(nx +
              IntersectionPointList_size[0] * i19) - 1];
          }
        }

        d_ii[0] = b_ii->size[0];
        d_ii[1] = 7;
        loop_ub = dd->size[0];
        i19 = IntersectionPointList->size[0] * IntersectionPointList->size[1];
        IntersectionPointList->size[0] = loop_ub;
        IntersectionPointList->size[1] = 7;
        emxEnsureCapacity(sp, (emxArray__common *)IntersectionPointList, i19,
                          (int32_T)sizeof(real_T), &w_emlrtRTEI);
        for (i19 = 0; i19 < 7; i19++) {
          for (i20 = 0; i20 < loop_ub; i20++) {
            IntersectionPointList->data[i20 + IntersectionPointList->size[0] *
              i19] = IntersectionPointList_data[((int32_T)dd->data[i20 +
              dd->size[0]] + IntersectionPointList_size[0] * i19) - 1];
          }
        }

        for (i19 = 0; i19 < 2; i19++) {
          b_IntersectionPointList[i19] = IntersectionPointList->size[i19];
        }

        emlrtSubAssignSizeCheckR2012b(d_ii, 2, b_IntersectionPointList, 2,
          &nb_emlrtECI, sp);
        for (i19 = 0; i19 < 7; i19++) {
          loop_ub = r7->size[0];
          for (i20 = 0; i20 < loop_ub; i20++) {
            ppp[b_ii->data[i20] + 100 * i19] = r7->data[i20 + r7->size[0] * i19];
          }
        }

        Count += mc_idx_4;
      }

      *p_Cnt = Count;
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    emxFree_real_T(&IntersectionPointList);
    emxFree_real_T(&c_i);
    emxFree_int32_T(&b_ii);
    emxFree_boolean_T(&x);
    emxFree_real_T(&b_i);
    emxFree_real_T(&r7);
    emxFree_real_T(&dd);
    emxFree_real_T(&cc);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (CalculateIntersection.c) */
