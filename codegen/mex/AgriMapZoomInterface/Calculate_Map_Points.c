/*
 * Calculate_Map_Points.c
 *
 * Code generation for function 'Calculate_Map_Points'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "Calculate_Map_Points.h"
#include "flipud.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "CalculateNewPoint.h"
#include "Calculate_Area.h"
#include "Calculate_Effective_Point.h"
#include "Preprocess.h"
#include "CalculateSina.h"
#include "NormalizeDPList.h"
#include "DPList.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRSInfo jd_emlrtRSI = { 23, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m" };

static emlrtRSInfo kd_emlrtRSI = { 24, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m" };

static emlrtRSInfo ld_emlrtRSI = { 25, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m" };

static emlrtRSInfo md_emlrtRSI = { 64, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m" };

static emlrtRSInfo od_emlrtRSI = { 46, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m" };

static emlrtRSInfo pd_emlrtRSI = { 50, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m" };

static emlrtRSInfo qd_emlrtRSI = { 51, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m" };

static emlrtRTEInfo bb_emlrtRTEI = { 1, 39, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m" };

static emlrtRTEInfo cb_emlrtRTEI = { 20, 1, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m" };

static emlrtRTEInfo db_emlrtRTEI = { 21, 1, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m" };

static emlrtRTEInfo eb_emlrtRTEI = { 22, 1, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m" };

static emlrtECInfo ob_emlrtECI = { -1, 61, 13, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m" };

static emlrtDCInfo v_emlrtDCI = { 61, 23, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 1 };

static emlrtBCInfo dm_emlrtBCI = { 1, 100, 61, 61, "PointLast",
  "Calculate_Map_Points", "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtDCInfo w_emlrtDCI = { 61, 61, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 1 };

static emlrtBCInfo em_emlrtBCI = { 1, 100, 51, 49, "PointLast",
  "Calculate_Map_Points", "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtDCInfo x_emlrtDCI = { 51, 49, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 1 };

static emlrtBCInfo fm_emlrtBCI = { 1, 100, 50, 77, "P", "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtBCInfo gm_emlrtBCI = { 1, 100, 46, 32, "P", "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtBCInfo hm_emlrtBCI = { 1, 100, 42, 18, "P", "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtBCInfo im_emlrtBCI = { -1, -1, 44, 106, "Sina",
  "Calculate_Map_Points", "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtBCInfo jm_emlrtBCI = { -1, -1, 44, 80, "NEdgevectorList",
  "Calculate_Map_Points", "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtBCInfo km_emlrtBCI = { -1, -1, 44, 55, "NEdgevectorList",
  "Calculate_Map_Points", "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtBCInfo lm_emlrtBCI = { -1, -1, 44, 29, "Point",
  "Calculate_Map_Points", "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtBCInfo mm_emlrtBCI = { -1, -1, 42, 107, "Sina",
  "Calculate_Map_Points", "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtECInfo pb_emlrtECI = { -1, 25, 1, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m" };

static emlrtBCInfo nm_emlrtBCI = { -1, -1, 25, 8, "Sina", "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtBCInfo om_emlrtBCI = { -1, -1, 42, 84, "NEdgevectorList",
  "Calculate_Map_Points", "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtBCInfo pm_emlrtBCI = { -1, -1, 42, 59, "NEdgevectorList",
  "Calculate_Map_Points", "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtBCInfo qm_emlrtBCI = { -1, -1, 42, 33, "Point",
  "Calculate_Map_Points", "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtECInfo qb_emlrtECI = { -1, 66, 12, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m" };

static emlrtBCInfo rm_emlrtBCI = { 1, 100, 66, 60, "PointLast",
  "Calculate_Map_Points", "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtBCInfo sm_emlrtBCI = { -1, -1, 64, 71, "Point",
  "Calculate_Map_Points", "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtDCInfo y_emlrtDCI = { 37, 8, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 1 };

static emlrtBCInfo tm_emlrtBCI = { -1, -1, 25, 50, "NEdgevectorList",
  "Calculate_Map_Points", "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtECInfo rb_emlrtECI = { -1, 24, 1, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m" };

static emlrtBCInfo um_emlrtBCI = { -1, -1, 24, 17, "NEdgevectorList",
  "Calculate_Map_Points", "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtBCInfo vm_emlrtBCI = { -1, -1, 24, 55, "EList",
  "Calculate_Map_Points", "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtECInfo sb_emlrtECI = { -1, 23, 1, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m" };

static emlrtBCInfo wm_emlrtBCI = { -1, -1, 23, 7, "EList",
  "Calculate_Map_Points", "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtBCInfo xm_emlrtBCI = { -1, -1, 23, 36, "Point",
  "Calculate_Map_Points", "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 0 };

static emlrtDCInfo ab_emlrtDCI = { 20, 16, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 1 };

static emlrtDCInfo bb_emlrtDCI = { 20, 16, "Calculate_Map_Points",
  "D:\\2.AgriMapZoom\\Calculate_Map_Points.m", 4 };

/* Function Definitions */
void Calculate_Map_Points(const emlrtStack *sp, const real_T Point_data[], const
  int32_T Point_size[2], real_T P_Cnt, real_T L, real_T flag, real_T Theita,
  real_T Clock_Flag, real_T PointLast[200], real_T *PL_Cnt, real_T *f_error)
{
  emxArray_real_T *Sina;
  int32_T i24;
  real_T b_Sina;
  int32_T loop_ub;
  emxArray_real_T *EList;
  emxArray_real_T *NEdgevectorList;
  int32_T b_loop_ub;
  emxArray_int32_T *r8;
  real_T b_Point_data[510];
  int32_T b_Point_size[2];
  int32_T i25;
  emxArray_real_T *r9;
  emxArray_real_T c_Point_data;
  int32_T iv32[2];
  emxArray_real_T *b_EList;
  int32_T iv33[2];
  emxArray_real_T *b_NEdgevectorList;
  emxArray_real_T *r10;
  int32_T iv34[2];
  real_T P[200];
  int32_T t;
  int32_T i;
  real_T P_data[200];
  int32_T P_size[2];
  real_T Prep_Cnt;
  real_T Prep_Preprocessing[200];
  int32_T Prep_Preprocessing_size[2];
  int32_T PointLast_size[2];
  real_T Area;
  int32_T tmp_data[100];
  int32_T tmp_size[2];
  real_T b_tmp_data[510];
  int32_T b_tmp_size[2];
  real_T c_tmp_data[200];
  int32_T iv35[2];
  real_T d_Point_data[510];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &Sina, 2, &cb_emlrtRTEI, true);

  /* { */
  /* 作用：对多边形进行整体内缩或外扩 */
  /* 输入： */
  /* P_Cnt:为点集点的个数(数据类型：double 1x1) */
  /* Point:为初始点坐标集(数据类型：double P_Cntx1) */
  /* L:为缩放的宽度(数据类型：double 1x1) */
  /* flag: = 0缩小，flag = 1,扩大(数据类型：double 1x1) */
  /* Theita:为小角度的上限(数据类型：double 1x1) */
  /* Clock_Flag:原输入点集的时针方向（未经转换成顺时针前） */
  /* 0-逆时针 */
  /* 1-顺时针 */
  /* 输出： */
  /* PL_Cnt:输出点集点的个数(数据类型：double 1x1) */
  /* PointLast：处理后的点集(数据类型：double PL_Cntx1) */
  /* f_error：0：正常；1：出现错误(数据类型：double 1x1) */
  /* } */
  i24 = Sina->size[0] * Sina->size[1];
  Sina->size[0] = 1;
  if (!(P_Cnt > 0.0)) {
    emlrtNonNegativeCheckR2012b(P_Cnt, &bb_emlrtDCI, sp);
  }

  b_Sina = P_Cnt;
  if (b_Sina != (int32_T)muDoubleScalarFloor(b_Sina)) {
    emlrtIntegerCheckR2012b(b_Sina, &ab_emlrtDCI, sp);
  }

  Sina->size[1] = (int32_T)b_Sina;
  emxEnsureCapacity(sp, (emxArray__common *)Sina, i24, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  if (!(P_Cnt > 0.0)) {
    emlrtNonNegativeCheckR2012b(P_Cnt, &bb_emlrtDCI, sp);
  }

  if (b_Sina != (int32_T)muDoubleScalarFloor(b_Sina)) {
    emlrtIntegerCheckR2012b(b_Sina, &ab_emlrtDCI, sp);
  }

  loop_ub = (int32_T)b_Sina;
  for (i24 = 0; i24 < loop_ub; i24++) {
    Sina->data[i24] = 0.0;
  }

  emxInit_real_T(sp, &EList, 2, &db_emlrtRTEI, true);
  i24 = EList->size[0] * EList->size[1];
  EList->size[0] = (int32_T)P_Cnt;
  EList->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)EList, i24, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  loop_ub = (int32_T)P_Cnt << 1;
  for (i24 = 0; i24 < loop_ub; i24++) {
    EList->data[i24] = 0.0;
  }

  emxInit_real_T(sp, &NEdgevectorList, 2, &eb_emlrtRTEI, true);
  i24 = NEdgevectorList->size[0] * NEdgevectorList->size[1];
  NEdgevectorList->size[0] = (int32_T)P_Cnt;
  NEdgevectorList->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)NEdgevectorList, i24, (int32_T)
                    sizeof(real_T), &bb_emlrtRTEI);
  loop_ub = (int32_T)P_Cnt << 1;
  for (i24 = 0; i24 < loop_ub; i24++) {
    NEdgevectorList->data[i24] = 0.0;
  }

  if (1.0 > P_Cnt) {
    loop_ub = 0;
  } else {
    if (!(1 <= Point_size[0])) {
      emlrtDynamicBoundsCheckR2012b(1, 1, Point_size[0], &xm_emlrtBCI, sp);
    }

    loop_ub = (int32_T)P_Cnt;
    if (!((loop_ub >= 1) && (loop_ub <= Point_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, Point_size[0], &xm_emlrtBCI, sp);
    }
  }

  if (1.0 > P_Cnt) {
    b_loop_ub = 0;
  } else {
    i24 = (int32_T)P_Cnt;
    b_loop_ub = (int32_T)P_Cnt;
    if (!((b_loop_ub >= 1) && (b_loop_ub <= i24))) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i24, &wm_emlrtBCI, sp);
    }
  }

  emxInit_int32_T(sp, &r8, 1, &bb_emlrtRTEI, true);
  i24 = r8->size[0];
  r8->size[0] = b_loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)r8, i24, (int32_T)sizeof(int32_T),
                    &bb_emlrtRTEI);
  for (i24 = 0; i24 < b_loop_ub; i24++) {
    r8->data[i24] = i24;
  }

  b_Point_size[0] = loop_ub;
  b_Point_size[1] = 2;
  for (i24 = 0; i24 < 2; i24++) {
    for (i25 = 0; i25 < loop_ub; i25++) {
      b_Point_data[i25 + b_Point_size[0] * i24] = Point_data[i25 + Point_size[0]
        * i24];
    }
  }

  emxInit_real_T(sp, &r9, 2, &bb_emlrtRTEI, true);
  c_Point_data.data = (real_T *)&b_Point_data;
  c_Point_data.size = (int32_T *)&b_Point_size;
  c_Point_data.allocatedSize = 510;
  c_Point_data.numDimensions = 2;
  c_Point_data.canFreeData = false;
  st.site = &jd_emlrtRSI;
  DPList(&st, &c_Point_data, P_Cnt, r9);
  iv32[0] = r8->size[0];
  iv32[1] = 2;
  emlrtSubAssignSizeCheckR2012b(iv32, 2, *(int32_T (*)[2])r9->size, 2,
    &sb_emlrtECI, sp);
  for (i24 = 0; i24 < 2; i24++) {
    loop_ub = r9->size[0];
    for (i25 = 0; i25 < loop_ub; i25++) {
      EList->data[r8->data[i25] + EList->size[0] * i24] = r9->data[i25 +
        r9->size[0] * i24];
    }
  }

  if (1.0 > P_Cnt) {
    loop_ub = 0;
  } else {
    i24 = EList->size[0];
    if (!(1 <= i24)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i24, &vm_emlrtBCI, sp);
    }

    i24 = EList->size[0];
    loop_ub = (int32_T)P_Cnt;
    if (!((loop_ub >= 1) && (loop_ub <= i24))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i24, &vm_emlrtBCI, sp);
    }
  }

  if (1.0 > P_Cnt) {
    b_loop_ub = 0;
  } else {
    i24 = (int32_T)P_Cnt;
    b_loop_ub = (int32_T)P_Cnt;
    if (!((b_loop_ub >= 1) && (b_loop_ub <= i24))) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i24, &um_emlrtBCI, sp);
    }
  }

  i24 = r8->size[0];
  r8->size[0] = b_loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)r8, i24, (int32_T)sizeof(int32_T),
                    &bb_emlrtRTEI);
  for (i24 = 0; i24 < b_loop_ub; i24++) {
    r8->data[i24] = i24;
  }

  emxInit_real_T(sp, &b_EList, 2, &bb_emlrtRTEI, true);
  i24 = b_EList->size[0] * b_EList->size[1];
  b_EList->size[0] = loop_ub;
  b_EList->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)b_EList, i24, (int32_T)sizeof(real_T),
                    &bb_emlrtRTEI);
  for (i24 = 0; i24 < 2; i24++) {
    for (i25 = 0; i25 < loop_ub; i25++) {
      b_EList->data[i25 + b_EList->size[0] * i24] = EList->data[i25 +
        EList->size[0] * i24];
    }
  }

  emxFree_real_T(&EList);
  st.site = &kd_emlrtRSI;
  NormalizeDPList(&st, b_EList, P_Cnt, r9);
  iv33[0] = r8->size[0];
  iv33[1] = 2;
  emlrtSubAssignSizeCheckR2012b(iv33, 2, *(int32_T (*)[2])r9->size, 2,
    &rb_emlrtECI, sp);
  emxFree_real_T(&b_EList);
  for (i24 = 0; i24 < 2; i24++) {
    loop_ub = r9->size[0];
    for (i25 = 0; i25 < loop_ub; i25++) {
      NEdgevectorList->data[r8->data[i25] + NEdgevectorList->size[0] * i24] =
        r9->data[i25 + r9->size[0] * i24];
    }
  }

  emxFree_real_T(&r9);

  /* 单位向量 */
  if (1.0 > P_Cnt) {
    loop_ub = 0;
  } else {
    i24 = NEdgevectorList->size[0];
    if (!(1 <= i24)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i24, &tm_emlrtBCI, sp);
    }

    i24 = NEdgevectorList->size[0];
    loop_ub = (int32_T)P_Cnt;
    if (!((loop_ub >= 1) && (loop_ub <= i24))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i24, &tm_emlrtBCI, sp);
    }
  }

  if (1.0 > P_Cnt) {
    b_loop_ub = 0;
  } else {
    i24 = (int32_T)P_Cnt;
    b_loop_ub = (int32_T)P_Cnt;
    if (!((b_loop_ub >= 1) && (b_loop_ub <= i24))) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i24, &nm_emlrtBCI, sp);
    }
  }

  i24 = r8->size[0];
  r8->size[0] = b_loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)r8, i24, (int32_T)sizeof(int32_T),
                    &bb_emlrtRTEI);
  for (i24 = 0; i24 < b_loop_ub; i24++) {
    r8->data[i24] = i24;
  }

  emxInit_real_T(sp, &b_NEdgevectorList, 2, &bb_emlrtRTEI, true);
  i24 = b_NEdgevectorList->size[0] * b_NEdgevectorList->size[1];
  b_NEdgevectorList->size[0] = loop_ub;
  b_NEdgevectorList->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)b_NEdgevectorList, i24, (int32_T)
                    sizeof(real_T), &bb_emlrtRTEI);
  for (i24 = 0; i24 < 2; i24++) {
    for (i25 = 0; i25 < loop_ub; i25++) {
      b_NEdgevectorList->data[i25 + b_NEdgevectorList->size[0] * i24] =
        NEdgevectorList->data[i25 + NEdgevectorList->size[0] * i24];
    }
  }

  emxInit_real_T(sp, &r10, 2, &bb_emlrtRTEI, true);
  st.site = &ld_emlrtRSI;
  CalculateSina(&st, b_NEdgevectorList, P_Cnt, r10);
  iv34[0] = 1;
  iv34[1] = r8->size[0];
  emlrtSubAssignSizeCheckR2012b(iv34, 2, *(int32_T (*)[2])r10->size, 2,
    &pb_emlrtECI, sp);
  loop_ub = r10->size[1];
  emxFree_real_T(&b_NEdgevectorList);
  for (i24 = 0; i24 < loop_ub; i24++) {
    Sina->data[Sina->size[0] * r8->data[i24]] = r10->data[r10->size[0] * i24];
  }

  emxFree_real_T(&r10);
  emxFree_int32_T(&r8);
  for (i24 = 0; i24 < 200; i24++) {
    P[i24] = 0.0;
    PointLast[i24] = 0.0;
  }

  *PL_Cnt = 0.0;

  /* 内缩后的多变行面积最小值为某一常数，如果L对应的内缩面积是Area_Limit，则保留L-0.5米对应的内缩后的点 */
  *f_error = 0.0;

  /* % */
  if (flag != (int32_T)muDoubleScalarFloor(flag)) {
    emlrtIntegerCheckR2012b(flag, &y_emlrtDCI, sp);
  }

  switch ((int32_T)flag) {
   case 0:
    /* flag: = 0缩小，flag = 1,扩大 */
    t = 1;
    while (t != 0) {
      i = 0;
      while (i <= (int32_T)P_Cnt - 2) {
        i24 = NEdgevectorList->size[0];
        i25 = (int32_T)(2.0 + (real_T)i);
        if (!((i25 >= 1) && (i25 <= i24))) {
          emlrtDynamicBoundsCheckR2012b(i25, 1, i24, &pm_emlrtBCI, sp);
        }

        i24 = NEdgevectorList->size[0];
        i25 = (int32_T)((2.0 + (real_T)i) - 1.0);
        if (!((i25 >= 1) && (i25 <= i24))) {
          emlrtDynamicBoundsCheckR2012b(i25, 1, i24, &om_emlrtBCI, sp);
        }

        i24 = Sina->size[1];
        i25 = (int32_T)(2.0 + (real_T)i);
        if (!((i25 >= 1) && (i25 <= i24))) {
          emlrtDynamicBoundsCheckR2012b(i25, 1, i24, &mm_emlrtBCI, sp);
        }

        i24 = 2 + i;
        if (!((i24 >= 1) && (i24 <= Point_size[0]))) {
          emlrtDynamicBoundsCheckR2012b(i24, 1, Point_size[0], &qm_emlrtBCI, sp);
        }

        b_Sina = Sina->data[Sina->size[0] * (i + 1)];
        i24 = 2 + i;
        if (!((i24 >= 1) && (i24 <= 100))) {
          emlrtDynamicBoundsCheckR2012b(i24, 1, 100, &hm_emlrtBCI, sp);
        }

        for (i24 = 0; i24 < 2; i24++) {
          P[(i + 100 * i24) + 1] = Point_data[(i + Point_size[0] * i24) + 1] +
            (NEdgevectorList->data[(i + NEdgevectorList->size[0] * i24) + 1] -
             NEdgevectorList->data[i + NEdgevectorList->size[0] * i24]) * L /
            b_Sina;
        }

        i++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      if (!(1 <= Point_size[0])) {
        emlrtDynamicBoundsCheckR2012b(1, 1, Point_size[0], &lm_emlrtBCI, sp);
      }

      i24 = NEdgevectorList->size[0];
      if (!(1 <= i24)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i24, &km_emlrtBCI, sp);
      }

      i24 = Sina->size[1];
      if (!(1 <= i24)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i24, &im_emlrtBCI, sp);
      }

      i24 = NEdgevectorList->size[0];
      i25 = (int32_T)P_Cnt;
      if (!((i25 >= 1) && (i25 <= i24))) {
        emlrtDynamicBoundsCheckR2012b(i25, 1, i24, &jm_emlrtBCI, sp);
      }

      b_Sina = Sina->data[0];
      for (i24 = 0; i24 < 2; i24++) {
        P[100 * i24] = Point_data[Point_size[0] * i24] + (NEdgevectorList->
          data[NEdgevectorList->size[0] * i24] - NEdgevectorList->data[((int32_T)
          P_Cnt + NEdgevectorList->size[0] * i24) - 1]) * L / b_Sina;
      }

      if (1.0 > P_Cnt) {
        loop_ub = 0;
      } else {
        loop_ub = (int32_T)P_Cnt;
        if (!((loop_ub >= 1) && (loop_ub <= 100))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 100, &gm_emlrtBCI, sp);
        }
      }

      P_size[0] = loop_ub;
      P_size[1] = 2;
      for (i24 = 0; i24 < 2; i24++) {
        for (i25 = 0; i25 < loop_ub; i25++) {
          P_data[i25 + loop_ub * i24] = P[i25 + 100 * i24];
        }
      }

      st.site = &od_emlrtRSI;
      Preprocess(&st, P_data, P_size, P_Cnt, Prep_Preprocessing, &Prep_Cnt);
      memcpy(&P[0], &Prep_Preprocessing[0], 200U * sizeof(real_T));
      if (1.0 > Prep_Cnt) {
        loop_ub = 0;
      } else {
        loop_ub = (int32_T)Prep_Cnt;
        if (!((loop_ub >= 1) && (loop_ub <= 100))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 100, &fm_emlrtBCI, sp);
        }
      }

      Prep_Preprocessing_size[0] = loop_ub;
      Prep_Preprocessing_size[1] = 2;
      for (i24 = 0; i24 < 2; i24++) {
        for (i25 = 0; i25 < loop_ub; i25++) {
          P_data[i25 + loop_ub * i24] = Prep_Preprocessing[i25 + 100 * i24];
        }
      }

      st.site = &pd_emlrtRSI;
      Calculate_Effective_Point(&st, P_data, Prep_Preprocessing_size, Prep_Cnt,
        PointLast, &b_Sina);
      *PL_Cnt = b_Sina;
      if (1.0 > b_Sina) {
        loop_ub = 0;
      } else {
        if (b_Sina != (int32_T)muDoubleScalarFloor(b_Sina)) {
          emlrtIntegerCheckR2012b(b_Sina, &x_emlrtDCI, sp);
        }

        loop_ub = (int32_T)b_Sina;
        if (!((loop_ub >= 1) && (loop_ub <= 100))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 100, &em_emlrtBCI, sp);
        }
      }

      PointLast_size[0] = loop_ub;
      PointLast_size[1] = 2;
      for (i24 = 0; i24 < 2; i24++) {
        for (i25 = 0; i25 < loop_ub; i25++) {
          P_data[i25 + loop_ub * i24] = PointLast[i25 + 100 * i24];
        }
      }

      st.site = &qd_emlrtRSI;
      Area = Calculate_Area(&st, P_data, PointLast_size, b_Sina);

      /*            %% */
      /* 此处只能解决L渐变的翻转情况 */
      if (Area < 20.0) {
        L -= 0.5;
      } else {
        t = 0;
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    if (Clock_Flag == 1.0) {
      if (1.0 > *PL_Cnt) {
        loop_ub = 0;
      } else {
        if (*PL_Cnt != (int32_T)muDoubleScalarFloor(*PL_Cnt)) {
          emlrtIntegerCheckR2012b(*PL_Cnt, &w_emlrtDCI, sp);
        }

        loop_ub = (int32_T)*PL_Cnt;
        if (!((loop_ub >= 1) && (loop_ub <= 100))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 100, &dm_emlrtBCI, sp);
        }
      }

      if (1.0 > *PL_Cnt) {
        b_loop_ub = 0;
      } else {
        if (*PL_Cnt != (int32_T)muDoubleScalarFloor(*PL_Cnt)) {
          emlrtIntegerCheckR2012b(*PL_Cnt, &v_emlrtDCI, sp);
        }

        b_loop_ub = (int32_T)*PL_Cnt;
      }

      for (i24 = 0; i24 < b_loop_ub; i24++) {
        tmp_data[i24] = i24;
      }

      tmp_size[0] = loop_ub;
      tmp_size[1] = 2;
      for (i24 = 0; i24 < 2; i24++) {
        for (i25 = 0; i25 < loop_ub; i25++) {
          b_tmp_data[i25 + loop_ub * i24] = PointLast[i25 + 100 * i24];
        }
      }

      flipud(b_tmp_data, tmp_size);
      b_tmp_size[0] = tmp_size[0];
      b_tmp_size[1] = 2;
      loop_ub = tmp_size[0] * tmp_size[1];
      for (i24 = 0; i24 < loop_ub; i24++) {
        c_tmp_data[i24] = b_tmp_data[i24];
      }

      iv35[0] = b_loop_ub;
      iv35[1] = 2;
      emlrtSubAssignSizeCheckR2012b(iv35, 2, b_tmp_size, 2, &ob_emlrtECI, sp);
      for (i24 = 0; i24 < 2; i24++) {
        loop_ub = b_tmp_size[0];
        for (i25 = 0; i25 < loop_ub; i25++) {
          PointLast[tmp_data[i25] + 100 * i24] = c_tmp_data[i25 + b_tmp_size[0] *
            i24];
        }
      }

      /* 转换成与初始输入时的时针顺序一致 */
    }
    break;

   case 1:
    if (1.0 > P_Cnt) {
      loop_ub = 0;
    } else {
      if (!(1 <= Point_size[0])) {
        emlrtDynamicBoundsCheckR2012b(1, 1, Point_size[0], &sm_emlrtBCI, sp);
      }

      loop_ub = (int32_T)P_Cnt;
      if (!((loop_ub >= 1) && (loop_ub <= Point_size[0]))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, Point_size[0], &sm_emlrtBCI,
          sp);
      }
    }

    P_size[0] = loop_ub;
    P_size[1] = 2;
    for (i24 = 0; i24 < 2; i24++) {
      for (i25 = 0; i25 < loop_ub; i25++) {
        d_Point_data[i25 + loop_ub * i24] = Point_data[i25 + Point_size[0] * i24];
      }
    }

    st.site = &md_emlrtRSI;
    CalculateNewPoint(&st, d_Point_data, P_size, P_Cnt, L, Theita, PointLast,
                      &b_Sina);
    *PL_Cnt = b_Sina;
    if (Clock_Flag == 0.0) {
      if (1.0 > b_Sina) {
        loop_ub = 0;
      } else {
        loop_ub = (int32_T)b_Sina;
        if (!((loop_ub >= 1) && (loop_ub <= 100))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 100, &rm_emlrtBCI, sp);
        }
      }

      if (1.0 > b_Sina) {
        b_loop_ub = 0;
      } else {
        b_loop_ub = (int32_T)b_Sina;
      }

      for (i24 = 0; i24 < b_loop_ub; i24++) {
        tmp_data[i24] = i24;
      }

      tmp_size[0] = loop_ub;
      tmp_size[1] = 2;
      for (i24 = 0; i24 < 2; i24++) {
        for (i25 = 0; i25 < loop_ub; i25++) {
          b_tmp_data[i25 + loop_ub * i24] = PointLast[i25 + 100 * i24];
        }
      }

      flipud(b_tmp_data, tmp_size);
      b_tmp_size[0] = tmp_size[0];
      b_tmp_size[1] = 2;
      loop_ub = tmp_size[0] * tmp_size[1];
      for (i24 = 0; i24 < loop_ub; i24++) {
        c_tmp_data[i24] = b_tmp_data[i24];
      }

      iv35[0] = b_loop_ub;
      iv35[1] = 2;
      emlrtSubAssignSizeCheckR2012b(iv35, 2, b_tmp_size, 2, &qb_emlrtECI, sp);
      for (i24 = 0; i24 < 2; i24++) {
        loop_ub = b_tmp_size[0];
        for (i25 = 0; i25 < loop_ub; i25++) {
          PointLast[tmp_data[i25] + 100 * i24] = c_tmp_data[i25 + b_tmp_size[0] *
            i24];
        }
      }

      /* %转换成与刚输入时的时针顺序一致 */
    }
    break;

   default:
    *f_error = 1.0;
    break;
  }

  emxFree_real_T(&NEdgevectorList);
  emxFree_real_T(&Sina);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Calculate_Map_Points.c) */
