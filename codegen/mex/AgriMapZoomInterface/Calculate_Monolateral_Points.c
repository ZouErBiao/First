/*
 * Calculate_Monolateral_Points.c
 *
 * Code generation for function 'Calculate_Monolateral_Points'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "Calculate_Monolateral_Points.h"
#include "flipud.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "Calculate_Effective_Point.h"
#include "CalculateSina.h"
#include "NormalizeDPList.h"
#include "DPList.h"

/* Variable Definitions */
static emlrtRSInfo pb_emlrtRSI = { 60, "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m" };

static emlrtRSInfo qb_emlrtRSI = { 22, "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m" };

static emlrtRSInfo rb_emlrtRSI = { 20, "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m" };

static emlrtRSInfo sb_emlrtRSI = { 19, "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m" };

static emlrtRTEInfo j_emlrtRTEI = { 1, 48, "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m" };

static emlrtRTEInfo k_emlrtRTEI = { 18, 1, "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m" };

static emlrtRTEInfo l_emlrtRTEI = { 21, 1, "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m" };

static emlrtBCInfo of_emlrtBCI = { -1, -1, 19, 42, "Points",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo pf_emlrtBCI = { -1, -1, 19, 17, "NEdgevectorList",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtECInfo q_emlrtECI = { -1, 19, 1, "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m" };

static emlrtBCInfo qf_emlrtBCI = { -1, -1, 20, 60, "NEdgevectorList",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo rf_emlrtBCI = { -1, -1, 20, 17, "NEdgevectorList",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtECInfo r_emlrtECI = { -1, 20, 1, "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m" };

static emlrtBCInfo sf_emlrtBCI = { -1, -1, 22, 45, "NEdgevectorList",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtDCInfo k_emlrtDCI = { 31, 12, "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 1 };

static emlrtBCInfo tf_emlrtBCI = { -1, -1, 45, 63, "NEdgevectorList",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo uf_emlrtBCI = { -1, -1, 22, 8, "Sina",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtECInfo s_emlrtECI = { -1, 22, 1, "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m" };

static emlrtBCInfo vf_emlrtBCI = { -1, -1, 48, 50, "Points",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo wf_emlrtBCI = { -1, -1, 48, 85, "NEdgevectorList",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo xf_emlrtBCI = { -1, -1, 48, 125, "Sina",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo yf_emlrtBCI = { -1, -1, 48, 24, "Points",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo ag_emlrtBCI = { -1, -1, 49, 52, "Points",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo bg_emlrtBCI = { -1, -1, 49, 89, "NEdgevectorList",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo cg_emlrtBCI = { -1, -1, 49, 129, "Sina",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo dg_emlrtBCI = { -1, -1, 49, 24, "Points",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo eg_emlrtBCI = { -1, -1, 51, 50, "Points",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo fg_emlrtBCI = { -1, -1, 51, 85, "NEdgevectorList",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo gg_emlrtBCI = { -1, -1, 51, 125, "Sina",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo hg_emlrtBCI = { -1, -1, 51, 24, "Points",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo ig_emlrtBCI = { -1, -1, 34, 61, "NEdgevectorList",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo jg_emlrtBCI = { -1, -1, 37, 50, "Points",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo kg_emlrtBCI = { -1, -1, 37, 83, "NEdgevectorList",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo lg_emlrtBCI = { -1, -1, 37, 123, "Sina",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo mg_emlrtBCI = { -1, -1, 37, 24, "Points",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo ng_emlrtBCI = { -1, -1, 38, 52, "Points",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo og_emlrtBCI = { -1, -1, 38, 87, "NEdgevectorList",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo pg_emlrtBCI = { -1, -1, 38, 127, "Sina",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo qg_emlrtBCI = { -1, -1, 38, 24, "Points",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo rg_emlrtBCI = { -1, -1, 40, 50, "Points",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo sg_emlrtBCI = { -1, -1, 40, 83, "NEdgevectorList",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo tg_emlrtBCI = { -1, -1, 40, 123, "Sina",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo ug_emlrtBCI = { -1, -1, 40, 24, "Points",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo vg_emlrtBCI = { -1, -1, 60, 75, "Points",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtDCInfo l_emlrtDCI = { 63, 59, "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 1 };

static emlrtBCInfo wg_emlrtBCI = { 1, 100, 63, 59, "PointLast",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtDCInfo m_emlrtDCI = { 66, 66, "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 1 };

static emlrtBCInfo xg_emlrtBCI = { 1, 100, 66, 66, "PointLast",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtBCInfo yg_emlrtBCI = { 1, 100, 29, 24, "Points_Monolateral",
  "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 0 };

static emlrtECInfo t_emlrtECI = { -1, 29, 5, "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m" };

static emlrtDCInfo n_emlrtDCI = { 63, 28, "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 1 };

static emlrtECInfo u_emlrtECI = { -1, 63, 9, "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m" };

static emlrtDCInfo o_emlrtDCI = { 66, 28, "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m", 1 };

static emlrtECInfo v_emlrtECI = { -1, 66, 9, "Calculate_Monolateral_Points",
  "D:\\2.AgriMapZoom\\Calculate_Monolateral_Points.m" };

/* Function Definitions */
void Calculate_Monolateral_Points(const emlrtStack *sp, real_T Points_data[],
  int32_T Points_size[2], real_T n, real_T Monolateral, real_T Monolateral_L,
  real_T Monolateral_flag, real_T Clock_Flag, real_T Points_Monolateral[200],
  real_T *PM_Cnt, real_T *f_error)
{
  emxArray_real_T *NEdgevectorList;
  int32_T i12;
  int32_T loop_ub;
  emxArray_int32_T *r3;
  int32_T b_Monolateral;
  real_T b_Points_data[510];
  int32_T b_Points_size[2];
  emxArray_real_T *r4;
  emxArray_real_T c_Points_data;
  int32_T iv14[2];
  emxArray_real_T *b_NEdgevectorList;
  int32_T iv15[2];
  emxArray_real_T *Sina;
  emxArray_real_T *c_NEdgevectorList;
  emxArray_real_T *r5;
  int32_T iv16[2];
  int32_T tmp_data[100];
  int32_T iv17[2];
  int32_T tmp_size[2];
  real_T b_Sina;
  real_T Points[2];
  real_T d_Points_data[510];
  int32_T c_Points_size[2];
  real_T PointLast[200];
  int32_T b_loop_ub;
  int32_T b_tmp_size[2];
  real_T b_tmp_data[510];
  real_T c_tmp_data[200];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* 计算单边内缩的点 */
  /* { */
  /* 输入： */
  /* n:多边形点的个数(数据类型：double 1x1) */
  /* Points：需要移动某边的多变形的边界点集，格式为多行两列的矩阵(数据类型：double nx2) */
  /* Monolateral：要移动的边的边号(数据类型：double 1x1) */
  /* Monolateral_L：某边要移动的距离,不能把某个边给缩没了(数据类型：double 1x1) */
  /* Monolateral_flag：某边要移动的方向(数据类型：double 1x1) */
  /* 输出： */
  /* PM_Cnt：输出的有效点的个数(数据类型：double 1x1) */
  /* Points_Monolateral：经过移动某边后的多边形的边界点(数据类型：double 100x2) */
  /* f_error：错误标志，为零则无错误，为1为有错误(数据类型：double 1x1) */
  /* } */
  memset(&Points_Monolateral[0], 0, 200U * sizeof(real_T));
  emxInit_real_T(sp, &NEdgevectorList, 2, &k_emlrtRTEI, true);
  *PM_Cnt = 0.0;
  i12 = NEdgevectorList->size[0] * NEdgevectorList->size[1];
  NEdgevectorList->size[0] = (int32_T)n;
  NEdgevectorList->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)NEdgevectorList, i12, (int32_T)
                    sizeof(real_T), &j_emlrtRTEI);
  loop_ub = (int32_T)n << 1;
  for (i12 = 0; i12 < loop_ub; i12++) {
    NEdgevectorList->data[i12] = 0.0;
  }

  emxInit_int32_T(sp, &r3, 1, &j_emlrtRTEI, true);
  i12 = (int32_T)n;
  if (!((i12 >= 1) && (i12 <= Points_size[0]))) {
    emlrtDynamicBoundsCheckR2012b(i12, 1, Points_size[0], &of_emlrtBCI, sp);
  }

  i12 = (int32_T)n;
  b_Monolateral = (int32_T)n;
  if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
    emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &pf_emlrtBCI, sp);
  }

  i12 = r3->size[0];
  r3->size[0] = (int32_T)n;
  emxEnsureCapacity(sp, (emxArray__common *)r3, i12, (int32_T)sizeof(int32_T),
                    &j_emlrtRTEI);
  loop_ub = (int32_T)n;
  for (i12 = 0; i12 < loop_ub; i12++) {
    r3->data[i12] = i12;
  }

  b_Points_size[0] = (int32_T)n;
  b_Points_size[1] = 2;
  for (i12 = 0; i12 < 2; i12++) {
    loop_ub = (int32_T)n;
    for (b_Monolateral = 0; b_Monolateral < loop_ub; b_Monolateral++) {
      b_Points_data[b_Monolateral + b_Points_size[0] * i12] =
        Points_data[b_Monolateral + Points_size[0] * i12];
    }
  }

  emxInit_real_T(sp, &r4, 2, &j_emlrtRTEI, true);
  c_Points_data.data = (real_T *)&b_Points_data;
  c_Points_data.size = (int32_T *)&b_Points_size;
  c_Points_data.allocatedSize = 510;
  c_Points_data.numDimensions = 2;
  c_Points_data.canFreeData = false;
  st.site = &sb_emlrtRSI;
  DPList(&st, &c_Points_data, n, r4);
  iv14[0] = r3->size[0];
  iv14[1] = 2;
  emlrtSubAssignSizeCheckR2012b(iv14, 2, *(int32_T (*)[2])r4->size, 2,
    &q_emlrtECI, sp);
  for (i12 = 0; i12 < 2; i12++) {
    loop_ub = r4->size[0];
    for (b_Monolateral = 0; b_Monolateral < loop_ub; b_Monolateral++) {
      NEdgevectorList->data[r3->data[b_Monolateral] + NEdgevectorList->size[0] *
        i12] = r4->data[b_Monolateral + r4->size[0] * i12];
    }
  }

  i12 = NEdgevectorList->size[0];
  b_Monolateral = (int32_T)n;
  if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
    emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &qf_emlrtBCI, sp);
  }

  i12 = NEdgevectorList->size[0];
  b_Monolateral = (int32_T)n;
  if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
    emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &rf_emlrtBCI, sp);
  }

  i12 = r3->size[0];
  r3->size[0] = (int32_T)n;
  emxEnsureCapacity(sp, (emxArray__common *)r3, i12, (int32_T)sizeof(int32_T),
                    &j_emlrtRTEI);
  loop_ub = (int32_T)n;
  for (i12 = 0; i12 < loop_ub; i12++) {
    r3->data[i12] = i12;
  }

  emxInit_real_T(sp, &b_NEdgevectorList, 2, &j_emlrtRTEI, true);
  i12 = b_NEdgevectorList->size[0] * b_NEdgevectorList->size[1];
  b_NEdgevectorList->size[0] = (int32_T)n;
  b_NEdgevectorList->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)b_NEdgevectorList, i12, (int32_T)
                    sizeof(real_T), &j_emlrtRTEI);
  for (i12 = 0; i12 < 2; i12++) {
    loop_ub = (int32_T)n;
    for (b_Monolateral = 0; b_Monolateral < loop_ub; b_Monolateral++) {
      b_NEdgevectorList->data[b_Monolateral + b_NEdgevectorList->size[0] * i12] =
        NEdgevectorList->data[b_Monolateral + NEdgevectorList->size[0] * i12];
    }
  }

  st.site = &rb_emlrtRSI;
  NormalizeDPList(&st, b_NEdgevectorList, n, r4);
  iv15[0] = r3->size[0];
  iv15[1] = 2;
  emlrtSubAssignSizeCheckR2012b(iv15, 2, *(int32_T (*)[2])r4->size, 2,
    &r_emlrtECI, sp);
  emxFree_real_T(&b_NEdgevectorList);
  for (i12 = 0; i12 < 2; i12++) {
    loop_ub = r4->size[0];
    for (b_Monolateral = 0; b_Monolateral < loop_ub; b_Monolateral++) {
      NEdgevectorList->data[r3->data[b_Monolateral] + NEdgevectorList->size[0] *
        i12] = r4->data[b_Monolateral + r4->size[0] * i12];
    }
  }

  emxFree_real_T(&r4);
  emxInit_real_T(sp, &Sina, 2, &l_emlrtRTEI, true);

  /* 单位向量 */
  i12 = Sina->size[0] * Sina->size[1];
  Sina->size[0] = 1;
  Sina->size[1] = (int32_T)n;
  emxEnsureCapacity(sp, (emxArray__common *)Sina, i12, (int32_T)sizeof(real_T),
                    &j_emlrtRTEI);
  loop_ub = (int32_T)n;
  for (i12 = 0; i12 < loop_ub; i12++) {
    Sina->data[i12] = 0.0;
  }

  i12 = NEdgevectorList->size[0];
  b_Monolateral = (int32_T)n;
  if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
    emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &sf_emlrtBCI, sp);
  }

  i12 = (int32_T)n;
  b_Monolateral = (int32_T)n;
  if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
    emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &uf_emlrtBCI, sp);
  }

  i12 = r3->size[0];
  r3->size[0] = (int32_T)n;
  emxEnsureCapacity(sp, (emxArray__common *)r3, i12, (int32_T)sizeof(int32_T),
                    &j_emlrtRTEI);
  loop_ub = (int32_T)n;
  for (i12 = 0; i12 < loop_ub; i12++) {
    r3->data[i12] = i12;
  }

  emxInit_real_T(sp, &c_NEdgevectorList, 2, &j_emlrtRTEI, true);
  i12 = c_NEdgevectorList->size[0] * c_NEdgevectorList->size[1];
  c_NEdgevectorList->size[0] = (int32_T)n;
  c_NEdgevectorList->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)c_NEdgevectorList, i12, (int32_T)
                    sizeof(real_T), &j_emlrtRTEI);
  for (i12 = 0; i12 < 2; i12++) {
    loop_ub = (int32_T)n;
    for (b_Monolateral = 0; b_Monolateral < loop_ub; b_Monolateral++) {
      c_NEdgevectorList->data[b_Monolateral + c_NEdgevectorList->size[0] * i12] =
        NEdgevectorList->data[b_Monolateral + NEdgevectorList->size[0] * i12];
    }
  }

  emxInit_real_T(sp, &r5, 2, &j_emlrtRTEI, true);
  st.site = &qb_emlrtRSI;
  CalculateSina(&st, c_NEdgevectorList, n, r5);
  iv16[0] = 1;
  iv16[1] = r3->size[0];
  emlrtSubAssignSizeCheckR2012b(iv16, 2, *(int32_T (*)[2])r5->size, 2,
    &s_emlrtECI, sp);
  loop_ub = r5->size[1];
  emxFree_real_T(&c_NEdgevectorList);
  for (i12 = 0; i12 < loop_ub; i12++) {
    Sina->data[Sina->size[0] * r3->data[i12]] = r5->data[r5->size[0] * i12];
  }

  emxFree_real_T(&r5);
  emxFree_int32_T(&r3);
  *f_error = 0.0;
  if ((Monolateral > n) || (Monolateral < 1.0)) {
    *f_error = 1.0;
  }

  if (*f_error == 1.0) {
    i12 = (int32_T)n;
    if (!((i12 >= 1) && (i12 <= 100))) {
      emlrtDynamicBoundsCheckR2012b(i12, 1, 100, &yg_emlrtBCI, sp);
    }

    loop_ub = (int32_T)n;
    for (i12 = 0; i12 < loop_ub; i12++) {
      tmp_data[i12] = i12;
    }

    iv17[0] = (int32_T)n;
    iv17[1] = 2;
    tmp_size[0] = (int32_T)n;
    tmp_size[1] = 2;
    emlrtSubAssignSizeCheckR2012b(iv17, 2, tmp_size, 2, &t_emlrtECI, sp);
    for (i12 = 0; i12 < 2; i12++) {
      loop_ub = (int32_T)n;
      for (b_Monolateral = 0; b_Monolateral < loop_ub; b_Monolateral++) {
        Points_Monolateral[tmp_data[b_Monolateral] + 100 * i12] = 0.0;
      }
    }
  } else {
    if (Monolateral_flag != (int32_T)muDoubleScalarFloor(Monolateral_flag)) {
      emlrtIntegerCheckR2012b(Monolateral_flag, &k_emlrtDCI, sp);
    }

    switch ((int32_T)Monolateral_flag) {
     case 0:
      /* 内移 */
      if (Monolateral == 1.0) {
        i12 = NEdgevectorList->size[0];
        b_Monolateral = (int32_T)n;
        if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
          emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &ig_emlrtBCI, sp);
        }

        b_Sina = Sina->data[0];
        for (i12 = 0; i12 < 2; i12++) {
          Points_data[Points_size[0] * i12] -= NEdgevectorList->data[((int32_T)n
            + NEdgevectorList->size[0] * i12) - 1] * Monolateral_L / b_Sina;
        }

        b_Sina = Sina->data[Sina->size[0]];
        for (i12 = 0; i12 < 2; i12++) {
          Points_data[1 + Points_size[0] * i12] += NEdgevectorList->data[1 +
            NEdgevectorList->size[0] * i12] * Monolateral_L / b_Sina;
        }
      } else if (Monolateral < n) {
        i12 = NEdgevectorList->size[0];
        b_Monolateral = (int32_T)(Monolateral - 1.0);
        if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
          emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &kg_emlrtBCI, sp);
        }

        i12 = Sina->size[1];
        b_Monolateral = (int32_T)Monolateral;
        if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
          emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &lg_emlrtBCI, sp);
        }

        i12 = (int32_T)Monolateral;
        if (!((i12 >= 1) && (i12 <= Points_size[0]))) {
          emlrtDynamicBoundsCheckR2012b(i12, 1, Points_size[0], &jg_emlrtBCI, sp);
        }

        b_Sina = Sina->data[Sina->size[0] * ((int32_T)Monolateral - 1)];
        i12 = (int32_T)Monolateral;
        if (!((i12 >= 1) && (i12 <= Points_size[0]))) {
          emlrtDynamicBoundsCheckR2012b(i12, 1, Points_size[0], &mg_emlrtBCI, sp);
        }

        for (i12 = 0; i12 < 2; i12++) {
          Points[i12] = Points_data[((int32_T)Monolateral + Points_size[0] * i12)
            - 1] - NEdgevectorList->data[((int32_T)Monolateral +
            NEdgevectorList->size[0] * i12) - 2] * Monolateral_L / b_Sina;
        }

        for (i12 = 0; i12 < 2; i12++) {
          Points_data[((int32_T)Monolateral + Points_size[0] * i12) - 1] =
            Points[i12];
        }

        i12 = NEdgevectorList->size[0];
        b_Monolateral = (int32_T)(Monolateral + 1.0);
        if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
          emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &og_emlrtBCI, sp);
        }

        i12 = Sina->size[1];
        b_Monolateral = (int32_T)(Monolateral + 1.0);
        if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
          emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &pg_emlrtBCI, sp);
        }

        loop_ub = (int32_T)Monolateral + 1;
        if (!((loop_ub >= 1) && (loop_ub <= Points_size[0]))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, Points_size[0], &ng_emlrtBCI,
            sp);
        }

        b_Sina = Sina->data[Sina->size[0] * (int32_T)Monolateral];
        b_Monolateral = (int32_T)Monolateral + 1;
        if (!((b_Monolateral >= 1) && (b_Monolateral <= Points_size[0]))) {
          emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, Points_size[0],
            &qg_emlrtBCI, sp);
        }

        for (i12 = 0; i12 < 2; i12++) {
          Points[i12] = Points_data[(loop_ub + Points_size[0] * i12) - 1] +
            NEdgevectorList->data[(int32_T)Monolateral + NEdgevectorList->size[0]
            * i12] * Monolateral_L / b_Sina;
        }

        for (i12 = 0; i12 < 2; i12++) {
          Points_data[(b_Monolateral + Points_size[0] * i12) - 1] = Points[i12];
        }
      } else {
        i12 = NEdgevectorList->size[0];
        b_Monolateral = (int32_T)(Monolateral - 1.0);
        if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
          emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &sg_emlrtBCI, sp);
        }

        i12 = Sina->size[1];
        b_Monolateral = (int32_T)Monolateral;
        if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
          emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &tg_emlrtBCI, sp);
        }

        i12 = (int32_T)Monolateral;
        if (!((i12 >= 1) && (i12 <= Points_size[0]))) {
          emlrtDynamicBoundsCheckR2012b(i12, 1, Points_size[0], &rg_emlrtBCI, sp);
        }

        b_Sina = Sina->data[Sina->size[0] * ((int32_T)Monolateral - 1)];
        i12 = (int32_T)Monolateral;
        if (!((i12 >= 1) && (i12 <= Points_size[0]))) {
          emlrtDynamicBoundsCheckR2012b(i12, 1, Points_size[0], &ug_emlrtBCI, sp);
        }

        for (i12 = 0; i12 < 2; i12++) {
          Points[i12] = Points_data[((int32_T)Monolateral + Points_size[0] * i12)
            - 1] - NEdgevectorList->data[((int32_T)Monolateral +
            NEdgevectorList->size[0] * i12) - 2] * Monolateral_L / b_Sina;
        }

        for (i12 = 0; i12 < 2; i12++) {
          Points_data[((int32_T)Monolateral + Points_size[0] * i12) - 1] =
            Points[i12];
        }

        b_Sina = Sina->data[0];
        for (i12 = 0; i12 < 2; i12++) {
          Points_data[Points_size[0] * i12] += NEdgevectorList->
            data[NEdgevectorList->size[0] * i12] * Monolateral_L / b_Sina;
        }
      }
      break;

     case 1:
      /* 外移 */
      if (Monolateral == 1.0) {
        i12 = NEdgevectorList->size[0];
        b_Monolateral = (int32_T)n;
        if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
          emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &tf_emlrtBCI, sp);
        }

        b_Sina = Sina->data[0];
        for (i12 = 0; i12 < 2; i12++) {
          Points_data[Points_size[0] * i12] += NEdgevectorList->data[((int32_T)n
            + NEdgevectorList->size[0] * i12) - 1] * Monolateral_L / b_Sina;
        }

        b_Sina = Sina->data[Sina->size[0]];
        for (i12 = 0; i12 < 2; i12++) {
          Points_data[1 + Points_size[0] * i12] -= NEdgevectorList->data[1 +
            NEdgevectorList->size[0] * i12] * Monolateral_L / b_Sina;
        }
      } else if (Monolateral < n) {
        i12 = NEdgevectorList->size[0];
        b_Monolateral = (int32_T)(Monolateral - 1.0);
        if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
          emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &wf_emlrtBCI, sp);
        }

        i12 = Sina->size[1];
        b_Monolateral = (int32_T)Monolateral;
        if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
          emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &xf_emlrtBCI, sp);
        }

        i12 = (int32_T)Monolateral;
        if (!((i12 >= 1) && (i12 <= Points_size[0]))) {
          emlrtDynamicBoundsCheckR2012b(i12, 1, Points_size[0], &vf_emlrtBCI, sp);
        }

        b_Sina = Sina->data[Sina->size[0] * ((int32_T)Monolateral - 1)];
        i12 = (int32_T)Monolateral;
        if (!((i12 >= 1) && (i12 <= Points_size[0]))) {
          emlrtDynamicBoundsCheckR2012b(i12, 1, Points_size[0], &yf_emlrtBCI, sp);
        }

        for (i12 = 0; i12 < 2; i12++) {
          Points[i12] = Points_data[((int32_T)Monolateral + Points_size[0] * i12)
            - 1] + NEdgevectorList->data[((int32_T)Monolateral +
            NEdgevectorList->size[0] * i12) - 2] * Monolateral_L / b_Sina;
        }

        for (i12 = 0; i12 < 2; i12++) {
          Points_data[((int32_T)Monolateral + Points_size[0] * i12) - 1] =
            Points[i12];
        }

        i12 = NEdgevectorList->size[0];
        b_Monolateral = (int32_T)(Monolateral + 1.0);
        if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
          emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &bg_emlrtBCI, sp);
        }

        i12 = Sina->size[1];
        b_Monolateral = (int32_T)(Monolateral + 1.0);
        if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
          emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &cg_emlrtBCI, sp);
        }

        loop_ub = (int32_T)Monolateral + 1;
        if (!((loop_ub >= 1) && (loop_ub <= Points_size[0]))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, Points_size[0], &ag_emlrtBCI,
            sp);
        }

        b_Sina = Sina->data[Sina->size[0] * (int32_T)Monolateral];
        b_Monolateral = (int32_T)Monolateral + 1;
        if (!((b_Monolateral >= 1) && (b_Monolateral <= Points_size[0]))) {
          emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, Points_size[0],
            &dg_emlrtBCI, sp);
        }

        for (i12 = 0; i12 < 2; i12++) {
          Points[i12] = Points_data[(loop_ub + Points_size[0] * i12) - 1] -
            NEdgevectorList->data[(int32_T)Monolateral + NEdgevectorList->size[0]
            * i12] * Monolateral_L / b_Sina;
        }

        for (i12 = 0; i12 < 2; i12++) {
          Points_data[(b_Monolateral + Points_size[0] * i12) - 1] = Points[i12];
        }
      } else {
        i12 = NEdgevectorList->size[0];
        b_Monolateral = (int32_T)(Monolateral - 1.0);
        if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
          emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &fg_emlrtBCI, sp);
        }

        i12 = Sina->size[1];
        b_Monolateral = (int32_T)Monolateral;
        if (!((b_Monolateral >= 1) && (b_Monolateral <= i12))) {
          emlrtDynamicBoundsCheckR2012b(b_Monolateral, 1, i12, &gg_emlrtBCI, sp);
        }

        i12 = (int32_T)Monolateral;
        if (!((i12 >= 1) && (i12 <= Points_size[0]))) {
          emlrtDynamicBoundsCheckR2012b(i12, 1, Points_size[0], &eg_emlrtBCI, sp);
        }

        b_Sina = Sina->data[Sina->size[0] * ((int32_T)Monolateral - 1)];
        i12 = (int32_T)Monolateral;
        if (!((i12 >= 1) && (i12 <= Points_size[0]))) {
          emlrtDynamicBoundsCheckR2012b(i12, 1, Points_size[0], &hg_emlrtBCI, sp);
        }

        for (i12 = 0; i12 < 2; i12++) {
          Points[i12] = Points_data[((int32_T)Monolateral + Points_size[0] * i12)
            - 1] + NEdgevectorList->data[((int32_T)Monolateral +
            NEdgevectorList->size[0] * i12) - 2] * Monolateral_L / b_Sina;
        }

        for (i12 = 0; i12 < 2; i12++) {
          Points_data[((int32_T)Monolateral + Points_size[0] * i12) - 1] =
            Points[i12];
        }

        b_Sina = Sina->data[0];
        for (i12 = 0; i12 < 2; i12++) {
          Points_data[Points_size[0] * i12] -= NEdgevectorList->
            data[NEdgevectorList->size[0] * i12] * Monolateral_L / b_Sina;
        }
      }
      break;

     default:
      *f_error = 1.0;

      /* warning('输入的平面坐标标志并非简单地0或1'); */
      break;
    }

    i12 = (int32_T)n;
    if (!((i12 >= 1) && (i12 <= Points_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(i12, 1, Points_size[0], &vg_emlrtBCI, sp);
    }

    c_Points_size[0] = (int32_T)n;
    c_Points_size[1] = 2;
    for (i12 = 0; i12 < 2; i12++) {
      loop_ub = (int32_T)n;
      for (b_Monolateral = 0; b_Monolateral < loop_ub; b_Monolateral++) {
        d_Points_data[b_Monolateral + (int32_T)n * i12] =
          Points_data[b_Monolateral + Points_size[0] * i12];
      }
    }

    st.site = &pb_emlrtRSI;
    Calculate_Effective_Point(&st, d_Points_data, c_Points_size, n, PointLast,
      &b_Sina);

    /* 去除无效环 */
    if (Clock_Flag == 0.0) {
      *PM_Cnt = b_Sina;
      if (1.0 > b_Sina) {
        loop_ub = -1;
      } else {
        if (b_Sina != (int32_T)muDoubleScalarFloor(b_Sina)) {
          emlrtIntegerCheckR2012b(b_Sina, &l_emlrtDCI, sp);
        }

        i12 = (int32_T)b_Sina;
        if (!((i12 >= 1) && (i12 <= 100))) {
          emlrtDynamicBoundsCheckR2012b(i12, 1, 100, &wg_emlrtBCI, sp);
        }

        loop_ub = i12 - 1;
      }

      if (1.0 > b_Sina) {
        b_loop_ub = 0;
      } else {
        if (b_Sina != (int32_T)muDoubleScalarFloor(b_Sina)) {
          emlrtIntegerCheckR2012b(b_Sina, &n_emlrtDCI, sp);
        }

        b_loop_ub = (int32_T)b_Sina;
      }

      for (i12 = 0; i12 < b_loop_ub; i12++) {
        tmp_data[i12] = i12;
      }

      iv17[0] = b_loop_ub;
      iv17[1] = 2;
      b_tmp_size[0] = loop_ub + 1;
      b_tmp_size[1] = 2;
      for (i12 = 0; i12 < 2; i12++) {
        tmp_size[i12] = b_tmp_size[i12];
      }

      emlrtSubAssignSizeCheckR2012b(iv17, 2, tmp_size, 2, &u_emlrtECI, sp);
      for (i12 = 0; i12 < 2; i12++) {
        for (b_Monolateral = 0; b_Monolateral <= loop_ub; b_Monolateral++) {
          Points_Monolateral[tmp_data[b_Monolateral] + 100 * i12] =
            PointLast[b_Monolateral + 100 * i12];
        }
      }

      /* 把结果变成顺时针的 */
    } else {
      *PM_Cnt = b_Sina;
      if (1.0 > b_Sina) {
        loop_ub = 0;
      } else {
        if (b_Sina != (int32_T)muDoubleScalarFloor(b_Sina)) {
          emlrtIntegerCheckR2012b(b_Sina, &m_emlrtDCI, sp);
        }

        loop_ub = (int32_T)b_Sina;
        if (!((loop_ub >= 1) && (loop_ub <= 100))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 100, &xg_emlrtBCI, sp);
        }
      }

      if (1.0 > b_Sina) {
        b_loop_ub = 0;
      } else {
        if (b_Sina != (int32_T)muDoubleScalarFloor(b_Sina)) {
          emlrtIntegerCheckR2012b(b_Sina, &o_emlrtDCI, sp);
        }

        b_loop_ub = (int32_T)b_Sina;
      }

      for (i12 = 0; i12 < b_loop_ub; i12++) {
        tmp_data[i12] = i12;
      }

      tmp_size[0] = loop_ub;
      tmp_size[1] = 2;
      for (i12 = 0; i12 < 2; i12++) {
        for (b_Monolateral = 0; b_Monolateral < loop_ub; b_Monolateral++) {
          b_tmp_data[b_Monolateral + loop_ub * i12] = PointLast[b_Monolateral +
            100 * i12];
        }
      }

      flipud(b_tmp_data, tmp_size);
      b_tmp_size[0] = tmp_size[0];
      b_tmp_size[1] = 2;
      loop_ub = tmp_size[0] * tmp_size[1];
      for (i12 = 0; i12 < loop_ub; i12++) {
        c_tmp_data[i12] = b_tmp_data[i12];
      }

      iv17[0] = b_loop_ub;
      iv17[1] = 2;
      emlrtSubAssignSizeCheckR2012b(iv17, 2, b_tmp_size, 2, &v_emlrtECI, sp);
      for (i12 = 0; i12 < 2; i12++) {
        loop_ub = b_tmp_size[0];
        for (b_Monolateral = 0; b_Monolateral < loop_ub; b_Monolateral++) {
          Points_Monolateral[tmp_data[b_Monolateral] + 100 * i12] =
            c_tmp_data[b_Monolateral + b_tmp_size[0] * i12];
        }
      }

      /* 把结果变成顺时针的 */
    }
  }

  emxFree_real_T(&Sina);
  emxFree_real_T(&NEdgevectorList);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Calculate_Monolateral_Points.c) */
