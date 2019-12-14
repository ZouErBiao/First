/*
 * CalculateNewPoint.c
 *
 * Code generation for function 'CalculateNewPoint'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "CalculateNewPoint.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "Preprocess.h"
#include "CalculateLineCrossover.h"
#include "Judge_Intersect.h"
#include "Reduce_Angle.h"
#include "CalculateCosa.h"
#include "CalculateSina.h"
#include "NormalizeDPList.h"
#include "DPList.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRSInfo sd_emlrtRSI = { 131, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtRSInfo td_emlrtRSI = { 103, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtRSInfo ud_emlrtRSI = { 72, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtRSInfo vd_emlrtRSI = { 30, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtRSInfo wd_emlrtRSI = { 28, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtRSInfo xd_emlrtRSI = { 25, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtRSInfo yd_emlrtRSI = { 24, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtRSInfo ae_emlrtRSI = { 21, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtRSInfo be_emlrtRSI = { 20, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtRSInfo ce_emlrtRSI = { 15, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtRTEInfo fb_emlrtRTEI = { 1, 25, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtRTEInfo gb_emlrtRTEI = { 22, 1, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtRTEInfo hb_emlrtRTEI = { 23, 1, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtBCInfo ym_emlrtBCI = { 1, 100, 131, 28, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtECInfo tb_emlrtECI = { -1, 122, 17, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtBCInfo an_emlrtBCI = { 1, 100, 122, 44, "Points",
  "CalculateNewPoint", "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtECInfo ub_emlrtECI = { -1, 112, 21, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtBCInfo bn_emlrtBCI = { 1, 100, 103, 28, "Points",
  "CalculateNewPoint", "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtECInfo vb_emlrtECI = { -1, 102, 21, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtBCInfo cn_emlrtBCI = { 1, 100, 100, 98, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo dn_emlrtBCI = { 1, 100, 100, 89, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo en_emlrtBCI = { 1, 100, 100, 82, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo fn_emlrtBCI = { 1, 100, 100, 75, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo gn_emlrtBCI = { 1, 100, 100, 54, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo hn_emlrtBCI = { 1, 100, 100, 47, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtECInfo wb_emlrtECI = { -1, 91, 17, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtBCInfo in_emlrtBCI = { 1, 100, 91, 44, "Points", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtECInfo xb_emlrtECI = { -1, 81, 21, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtECInfo yb_emlrtECI = { -1, 73, 21, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtBCInfo jn_emlrtBCI = { 1, 100, 73, 28, "Points", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo kn_emlrtBCI = { 1, 100, 72, 28, "Points", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtECInfo ac_emlrtECI = { -1, 71, 21, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtBCInfo ln_emlrtBCI = { 1, 100, 73, 49, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo mn_emlrtBCI = { 1, 100, 69, 102, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo nn_emlrtBCI = { 1, 100, 69, 93, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo on_emlrtBCI = { 1, 100, 69, 86, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo pn_emlrtBCI = { 1, 100, 69, 79, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo qn_emlrtBCI = { 1, 100, 69, 70, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo rn_emlrtBCI = { 1, 100, 69, 61, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo sn_emlrtBCI = { 1, 100, 69, 54, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo tn_emlrtBCI = { 1, 100, 69, 47, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtRTEInfo ic_emlrtRTEI = { 65, 5, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtBCInfo un_emlrtBCI = { 1, 100, 30, 24, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo vn_emlrtBCI = { -1, -1, 28, 123, "Cosa", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtECInfo bc_emlrtECI = { -1, 25, 1, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtBCInfo wn_emlrtBCI = { -1, -1, 25, 8, "Cosa", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo xn_emlrtBCI = { -1, -1, 28, 101, "Sina", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtECInfo cc_emlrtECI = { -1, 24, 1, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtBCInfo yn_emlrtBCI = { -1, -1, 24, 8, "Sina", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtECInfo dc_emlrtECI = { -1, 21, 1, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtECInfo ec_emlrtECI = { -1, 20, 1, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m" };

static emlrtBCInfo ao_emlrtBCI = { 1, 100, 20, 63, "PreprocessingData",
  "CalculateNewPoint", "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo bo_emlrtBCI = { -1, -1, 15, 25, "Point", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtDCInfo cb_emlrtDCI = { 15, 25, "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 1 };

static emlrtBCInfo co_emlrtBCI = { 1, 100, 115, 63, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo do_emlrtBCI = { 1, 100, 115, 32, "Points",
  "CalculateNewPoint", "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo eo_emlrtBCI = { 1, 100, 103, 78, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo fo_emlrtBCI = { 1, 100, 103, 87, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo go_emlrtBCI = { 1, 100, 103, 110, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo ho_emlrtBCI = { 1, 100, 103, 119, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo io_emlrtBCI = { 1, 100, 85, 59, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo jo_emlrtBCI = { 1, 100, 85, 28, "Points", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo ko_emlrtBCI = { 1, 100, 72, 78, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo lo_emlrtBCI = { 1, 100, 72, 87, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo mo_emlrtBCI = { 1, 100, 72, 110, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

static emlrtBCInfo no_emlrtBCI = { 1, 100, 72, 119, "P", "CalculateNewPoint",
  "D:\\2.AgriMapZoom\\CalculateNewPoint.m", 0 };

/* Function Definitions */
void CalculateNewPoint(const emlrtStack *sp, const real_T Point_data[], const
  int32_T Point_size[2], real_T P_Cnt, real_T L, real_T Theita, real_T Points
  [200], real_T *Cnt)
{
  int32_T loop_ub;
  real_T b_Point_data[510];
  int32_T b_Point_size[2];
  int32_T i26;
  int32_T i27;
  real_T Prep_Cnt;
  real_T Prep_Preprocessing[200];
  real_T NEdgevectorList[200];
  int32_T b_loop_ub;
  int32_T tmp_data[100];
  real_T Prep_Preprocessing_data[200];
  int32_T Prep_Preprocessing_size[2];
  emxArray_real_T *r11;
  emxArray_real_T b_Prep_Preprocessing_data;
  int32_T iv36[2];
  real_T NEdgevectorList_data[200];
  int32_T NEdgevectorList_size[2];
  emxArray_real_T b_NEdgevectorList_data;
  int32_T iv37[2];
  emxArray_real_T *Sina;
  emxArray_real_T *Cosa;
  emxArray_int32_T *r12;
  real_T c_NEdgevectorList_data[200];
  int32_T b_NEdgevectorList_size[2];
  emxArray_real_T *r13;
  emxArray_real_T d_NEdgevectorList_data;
  int32_T iv38[2];
  real_T e_NEdgevectorList_data[200];
  int32_T c_NEdgevectorList_size[2];
  int32_T iv39[2];
  int32_T c_loop_ub;
  int32_T d_loop_ub;
  real_T c_Prep_Preprocessing_data[200];
  int32_T b_Prep_Preprocessing_size[2];
  emxArray_real_T *b_Sina;
  emxArray_real_T *b_Cosa;
  int32_T d_NEdgevectorList_size[2];
  real_T d3;
  real_T P[200];
  int32_T P_size[2];
  real_T PD_Cnt;
  real_T n;
  int32_T tt_j;
  int32_T tt;
  boolean_T exitg1;
  int32_T ff;
  int32_T i;
  boolean_T exitg2;
  boolean_T guard1 = false;
  int32_T j;
  boolean_T exitg3;
  int32_T iv40[2];
  int32_T b_P_size[2];
  real_T dv3[2];
  int32_T iv41[2];
  int32_T c_P_size[2];
  int32_T iv42[2];
  int32_T d_P_size[2];
  int32_T iv43[2];
  int32_T Points_size[2];
  boolean_T exitg4;
  int32_T iv44[2];
  int32_T e_P_size[2];
  int32_T iv45[2];
  int32_T f_P_size[2];
  int32_T iv46[2];
  int32_T b_Points_size[2];
  int32_T g_P_size[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* { */
  /* 计算外扩后点的边界点 */
  /* 输入： */
  /* Point：需要外扩的多边形的边界点，格式为多行两列的矩阵，单位为m */
  /* L：需要外扩的距离，单位为m */
  /* Theita：是否为锐角的划分边界，单位为° */
  /* 输出： */
  /* Points：经过外扩后的多边形的边界点，格式为多行两列的矩阵，单位为m */
  /* Cnt:输出点集有效点的个数 */
  /* } */
  /* % */
  if (1.0 > P_Cnt) {
    loop_ub = 0;
  } else {
    if (!(1 <= Point_size[0])) {
      emlrtDynamicBoundsCheckR2012b(1, 1, Point_size[0], &bo_emlrtBCI, sp);
    }

    if (P_Cnt != (int32_T)muDoubleScalarFloor(P_Cnt)) {
      emlrtIntegerCheckR2012b(P_Cnt, &cb_emlrtDCI, sp);
    }

    loop_ub = (int32_T)P_Cnt;
    if (!((loop_ub >= 1) && (loop_ub <= Point_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, Point_size[0], &bo_emlrtBCI, sp);
    }
  }

  b_Point_size[0] = loop_ub;
  b_Point_size[1] = 2;
  for (i26 = 0; i26 < 2; i26++) {
    for (i27 = 0; i27 < loop_ub; i27++) {
      b_Point_data[i27 + loop_ub * i26] = Point_data[i27 + Point_size[0] * i26];
    }
  }

  st.site = &ce_emlrtRSI;
  Preprocess(&st, b_Point_data, b_Point_size, P_Cnt, Prep_Preprocessing,
             &Prep_Cnt);

  /* 对数据进行除重和删除同一点操作； */
  memset(&NEdgevectorList[0], 0, 200U * sizeof(real_T));
  if (1.0 > Prep_Cnt) {
    loop_ub = 0;
  } else {
    loop_ub = (int32_T)Prep_Cnt;
    if (!((loop_ub >= 1) && (loop_ub <= 100))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 100, &ao_emlrtBCI, sp);
    }
  }

  if (1.0 > Prep_Cnt) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = (int32_T)Prep_Cnt;
  }

  for (i26 = 0; i26 < b_loop_ub; i26++) {
    tmp_data[i26] = i26;
  }

  Prep_Preprocessing_size[0] = loop_ub;
  Prep_Preprocessing_size[1] = 2;
  for (i26 = 0; i26 < 2; i26++) {
    for (i27 = 0; i27 < loop_ub; i27++) {
      Prep_Preprocessing_data[i27 + Prep_Preprocessing_size[0] * i26] =
        Prep_Preprocessing[i27 + 100 * i26];
    }
  }

  emxInit_real_T(sp, &r11, 2, &fb_emlrtRTEI, true);
  b_Prep_Preprocessing_data.data = (real_T *)&Prep_Preprocessing_data;
  b_Prep_Preprocessing_data.size = (int32_T *)&Prep_Preprocessing_size;
  b_Prep_Preprocessing_data.allocatedSize = 200;
  b_Prep_Preprocessing_data.numDimensions = 2;
  b_Prep_Preprocessing_data.canFreeData = false;
  st.site = &be_emlrtRSI;
  DPList(&st, &b_Prep_Preprocessing_data, Prep_Cnt, r11);
  iv36[0] = b_loop_ub;
  iv36[1] = 2;
  emlrtSubAssignSizeCheckR2012b(iv36, 2, *(int32_T (*)[2])r11->size, 2,
    &ec_emlrtECI, sp);
  for (i26 = 0; i26 < 2; i26++) {
    loop_ub = r11->size[0];
    for (i27 = 0; i27 < loop_ub; i27++) {
      NEdgevectorList[tmp_data[i27] + 100 * i26] = r11->data[i27 + r11->size[0] *
        i26];
    }
  }

  if (1.0 > Prep_Cnt) {
    loop_ub = 0;
  } else {
    loop_ub = (int32_T)Prep_Cnt;
  }

  if (1.0 > Prep_Cnt) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = (int32_T)Prep_Cnt;
  }

  for (i26 = 0; i26 < b_loop_ub; i26++) {
    tmp_data[i26] = i26;
  }

  NEdgevectorList_size[0] = loop_ub;
  NEdgevectorList_size[1] = 2;
  for (i26 = 0; i26 < 2; i26++) {
    for (i27 = 0; i27 < loop_ub; i27++) {
      NEdgevectorList_data[i27 + NEdgevectorList_size[0] * i26] =
        NEdgevectorList[i27 + 100 * i26];
    }
  }

  b_NEdgevectorList_data.data = (real_T *)&NEdgevectorList_data;
  b_NEdgevectorList_data.size = (int32_T *)&NEdgevectorList_size;
  b_NEdgevectorList_data.allocatedSize = 200;
  b_NEdgevectorList_data.numDimensions = 2;
  b_NEdgevectorList_data.canFreeData = false;
  st.site = &ae_emlrtRSI;
  NormalizeDPList(&st, &b_NEdgevectorList_data, Prep_Cnt, r11);
  iv37[0] = b_loop_ub;
  iv37[1] = 2;
  emlrtSubAssignSizeCheckR2012b(iv37, 2, *(int32_T (*)[2])r11->size, 2,
    &dc_emlrtECI, sp);
  for (i26 = 0; i26 < 2; i26++) {
    loop_ub = r11->size[0];
    for (i27 = 0; i27 < loop_ub; i27++) {
      NEdgevectorList[tmp_data[i27] + 100 * i26] = r11->data[i27 + r11->size[0] *
        i26];
    }
  }

  emxFree_real_T(&r11);
  emxInit_real_T(sp, &Sina, 2, &gb_emlrtRTEI, true);

  /* 单位向量 */
  i26 = Sina->size[0] * Sina->size[1];
  Sina->size[0] = 1;
  Sina->size[1] = (int32_T)Prep_Cnt;
  emxEnsureCapacity(sp, (emxArray__common *)Sina, i26, (int32_T)sizeof(real_T),
                    &fb_emlrtRTEI);
  loop_ub = (int32_T)Prep_Cnt;
  for (i26 = 0; i26 < loop_ub; i26++) {
    Sina->data[i26] = 0.0;
  }

  emxInit_real_T(sp, &Cosa, 2, &hb_emlrtRTEI, true);
  i26 = Cosa->size[0] * Cosa->size[1];
  Cosa->size[0] = 1;
  Cosa->size[1] = (int32_T)Prep_Cnt;
  emxEnsureCapacity(sp, (emxArray__common *)Cosa, i26, (int32_T)sizeof(real_T),
                    &fb_emlrtRTEI);
  loop_ub = (int32_T)Prep_Cnt;
  for (i26 = 0; i26 < loop_ub; i26++) {
    Cosa->data[i26] = 0.0;
  }

  if (1.0 > Prep_Cnt) {
    loop_ub = 0;
  } else {
    loop_ub = (int32_T)Prep_Cnt;
  }

  if (1.0 > Prep_Cnt) {
    b_loop_ub = 0;
  } else {
    i26 = (int32_T)Prep_Cnt;
    if (!(1 <= i26)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i26, &yn_emlrtBCI, sp);
    }

    i26 = (int32_T)Prep_Cnt;
    b_loop_ub = (int32_T)Prep_Cnt;
    if (!((b_loop_ub >= 1) && (b_loop_ub <= i26))) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i26, &yn_emlrtBCI, sp);
    }
  }

  emxInit_int32_T(sp, &r12, 1, &fb_emlrtRTEI, true);
  i26 = r12->size[0];
  r12->size[0] = b_loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)r12, i26, (int32_T)sizeof(int32_T),
                    &fb_emlrtRTEI);
  for (i26 = 0; i26 < b_loop_ub; i26++) {
    r12->data[i26] = i26;
  }

  b_NEdgevectorList_size[0] = loop_ub;
  b_NEdgevectorList_size[1] = 2;
  for (i26 = 0; i26 < 2; i26++) {
    for (i27 = 0; i27 < loop_ub; i27++) {
      c_NEdgevectorList_data[i27 + b_NEdgevectorList_size[0] * i26] =
        NEdgevectorList[i27 + 100 * i26];
    }
  }

  emxInit_real_T(sp, &r13, 2, &fb_emlrtRTEI, true);
  d_NEdgevectorList_data.data = (real_T *)&c_NEdgevectorList_data;
  d_NEdgevectorList_data.size = (int32_T *)&b_NEdgevectorList_size;
  d_NEdgevectorList_data.allocatedSize = 200;
  d_NEdgevectorList_data.numDimensions = 2;
  d_NEdgevectorList_data.canFreeData = false;
  st.site = &yd_emlrtRSI;
  CalculateSina(&st, &d_NEdgevectorList_data, Prep_Cnt, r13);
  iv38[0] = 1;
  iv38[1] = r12->size[0];
  emlrtSubAssignSizeCheckR2012b(iv38, 2, *(int32_T (*)[2])r13->size, 2,
    &cc_emlrtECI, sp);
  loop_ub = r13->size[1];
  for (i26 = 0; i26 < loop_ub; i26++) {
    Sina->data[Sina->size[0] * r12->data[i26]] = r13->data[r13->size[0] * i26];
  }

  if (1.0 > Prep_Cnt) {
    loop_ub = 0;
  } else {
    loop_ub = (int32_T)Prep_Cnt;
  }

  if (1.0 > Prep_Cnt) {
    b_loop_ub = 0;
  } else {
    i26 = (int32_T)Prep_Cnt;
    b_loop_ub = (int32_T)Prep_Cnt;
    if (!((b_loop_ub >= 1) && (b_loop_ub <= i26))) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i26, &wn_emlrtBCI, sp);
    }
  }

  i26 = r12->size[0];
  r12->size[0] = b_loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)r12, i26, (int32_T)sizeof(int32_T),
                    &fb_emlrtRTEI);
  for (i26 = 0; i26 < b_loop_ub; i26++) {
    r12->data[i26] = i26;
  }

  c_NEdgevectorList_size[0] = loop_ub;
  c_NEdgevectorList_size[1] = 2;
  for (i26 = 0; i26 < 2; i26++) {
    for (i27 = 0; i27 < loop_ub; i27++) {
      e_NEdgevectorList_data[i27 + loop_ub * i26] = NEdgevectorList[i27 + 100 *
        i26];
    }
  }

  st.site = &xd_emlrtRSI;
  CalculateCosa(&st, e_NEdgevectorList_data, c_NEdgevectorList_size, Prep_Cnt,
                r13);
  iv39[0] = 1;
  iv39[1] = r12->size[0];
  emlrtSubAssignSizeCheckR2012b(iv39, 2, *(int32_T (*)[2])r13->size, 2,
    &bc_emlrtECI, sp);
  loop_ub = r13->size[1];
  for (i26 = 0; i26 < loop_ub; i26++) {
    Cosa->data[Cosa->size[0] * r12->data[i26]] = r13->data[r13->size[0] * i26];
  }

  emxFree_real_T(&r13);
  emxFree_int32_T(&r12);
  if (1.0 > Prep_Cnt) {
    loop_ub = 0;
  } else {
    loop_ub = (int32_T)Prep_Cnt;
  }

  if (1.0 > Prep_Cnt) {
    b_loop_ub = 0;
  } else {
    i26 = Sina->size[1];
    if (!(1 <= i26)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i26, &xn_emlrtBCI, sp);
    }

    i26 = Sina->size[1];
    b_loop_ub = (int32_T)Prep_Cnt;
    if (!((b_loop_ub >= 1) && (b_loop_ub <= i26))) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i26, &xn_emlrtBCI, sp);
    }
  }

  if (1.0 > Prep_Cnt) {
    c_loop_ub = 0;
  } else {
    i26 = Cosa->size[1];
    if (!(1 <= i26)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i26, &vn_emlrtBCI, sp);
    }

    i26 = Cosa->size[1];
    c_loop_ub = (int32_T)Prep_Cnt;
    if (!((c_loop_ub >= 1) && (c_loop_ub <= i26))) {
      emlrtDynamicBoundsCheckR2012b(c_loop_ub, 1, i26, &vn_emlrtBCI, sp);
    }
  }

  if (1.0 > Prep_Cnt) {
    d_loop_ub = 0;
  } else {
    d_loop_ub = (int32_T)Prep_Cnt;
  }

  b_Prep_Preprocessing_size[0] = loop_ub;
  b_Prep_Preprocessing_size[1] = 2;
  for (i26 = 0; i26 < 2; i26++) {
    for (i27 = 0; i27 < loop_ub; i27++) {
      c_Prep_Preprocessing_data[i27 + loop_ub * i26] = Prep_Preprocessing[i27 +
        100 * i26];
    }
  }

  emxInit_real_T(sp, &b_Sina, 2, &fb_emlrtRTEI, true);
  i26 = b_Sina->size[0] * b_Sina->size[1];
  b_Sina->size[0] = 1;
  b_Sina->size[1] = b_loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)b_Sina, i26, (int32_T)sizeof(real_T),
                    &fb_emlrtRTEI);
  for (i26 = 0; i26 < b_loop_ub; i26++) {
    b_Sina->data[b_Sina->size[0] * i26] = Sina->data[Sina->size[0] * i26];
  }

  emxFree_real_T(&Sina);
  emxInit_real_T(sp, &b_Cosa, 2, &fb_emlrtRTEI, true);
  i26 = b_Cosa->size[0] * b_Cosa->size[1];
  b_Cosa->size[0] = 1;
  b_Cosa->size[1] = c_loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)b_Cosa, i26, (int32_T)sizeof(real_T),
                    &fb_emlrtRTEI);
  for (i26 = 0; i26 < c_loop_ub; i26++) {
    b_Cosa->data[b_Cosa->size[0] * i26] = Cosa->data[Cosa->size[0] * i26];
  }

  emxFree_real_T(&Cosa);
  d_NEdgevectorList_size[0] = d_loop_ub;
  d_NEdgevectorList_size[1] = 2;
  for (i26 = 0; i26 < 2; i26++) {
    for (i27 = 0; i27 < d_loop_ub; i27++) {
      e_NEdgevectorList_data[i27 + d_loop_ub * i26] = NEdgevectorList[i27 + 100 *
        i26];
    }
  }

  st.site = &wd_emlrtRSI;
  Reduce_Angle(&st, c_Prep_Preprocessing_data, b_Prep_Preprocessing_size,
               Prep_Cnt, L, b_Sina, b_Cosa, e_NEdgevectorList_data,
               d_NEdgevectorList_size, Theita, P, &d3);

  /* % */
  emxFree_real_T(&b_Cosa);
  emxFree_real_T(&b_Sina);
  if (1.0 > d3) {
    loop_ub = 0;
  } else {
    loop_ub = (int32_T)d3;
    if (!((loop_ub >= 1) && (loop_ub <= 100))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 100, &un_emlrtBCI, sp);
    }
  }

  P_size[0] = loop_ub;
  P_size[1] = 2;
  for (i26 = 0; i26 < 2; i26++) {
    for (i27 = 0; i27 < loop_ub; i27++) {
      e_NEdgevectorList_data[i27 + loop_ub * i26] = P[i27 + 100 * i26];
    }
  }

  st.site = &vd_emlrtRSI;
  Preprocess(&st, e_NEdgevectorList_data, P_size, d3, Prep_Preprocessing,
             &Prep_Cnt);
  PD_Cnt = Prep_Cnt;
  for (i26 = 0; i26 < 200; i26++) {
    P[i26] = Prep_Preprocessing[i26];
    Points[i26] = 0.0;
  }

  *Cnt = 0.0;
  n = Prep_Cnt;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* { */
  /* P(PD_Cnt(1,1)+1,1:2) = P(1,1:2); */
  /* subplot(1,2,1); */
  /* plot(P(1:PD_Cnt(1,1)+1,1).',P(1:PD_Cnt(1,1)+1,2).','ro-'); */
  /* title('未删除无效环'); */
  /* xlabel('x'); */
  /* ylabel('y'); */
  /* grid; */
  /* } */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%10.9%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* [Points(1:100,1:2),Cnt(1,1)] = Calculate_Effective_Point(P(1:PD_Cnt(1,1),1:2),PD_Cnt(1,1)); */
  /* % */
  /* 以下是保留边界点的循环 */
  tt_j = 0;
  tt = 1;
  exitg1 = false;
  while ((!exitg1) && (tt == 1)) {
    if (n < 4.0) {
      memcpy(&Points[0], &P[0], 200U * sizeof(real_T));
      *Cnt = PD_Cnt;
      exitg1 = true;
    } else {
      ff = 0;
      emlrtForLoopVectorCheckR2012b(3.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)(n +
        -2.0), &ic_emlrtRTEI, sp);
      i = 0;
      exitg2 = false;
      while ((!exitg2) && (i <= (int32_T)(n + -2.0) - 1)) {
        memset(&Points[0], 0, 200U * sizeof(real_T));
        guard1 = false;
        if (3.0 + (real_T)i < n) {
          j = 0;
          exitg3 = false;
          while ((!exitg3) && (j <= (int32_T)((3.0 + (real_T)i) - 2.0) - 1)) {
            i26 = (int32_T)(3.0 + (real_T)i);
            if (!((i26 >= 1) && (i26 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &tn_emlrtBCI, sp);
            }

            i26 = (int32_T)(3.0 + (real_T)i);
            if (!((i26 >= 1) && (i26 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &sn_emlrtBCI, sp);
            }

            i26 = (int32_T)((3.0 + (real_T)i) + 1.0);
            if (!((i26 >= 1) && (i26 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &rn_emlrtBCI, sp);
            }

            i26 = (int32_T)((3.0 + (real_T)i) + 1.0);
            if (!((i26 >= 1) && (i26 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &qn_emlrtBCI, sp);
            }

            i26 = j + 1;
            if (!((i26 >= 1) && (i26 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &pn_emlrtBCI, sp);
            }

            i26 = j + 1;
            if (!((i26 >= 1) && (i26 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &on_emlrtBCI, sp);
            }

            i26 = (int32_T)((1.0 + (real_T)j) + 1.0);
            if (!((i26 >= 1) && (i26 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &nn_emlrtBCI, sp);
            }

            i26 = (int32_T)((1.0 + (real_T)j) + 1.0);
            if (!((i26 >= 1) && (i26 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &mn_emlrtBCI, sp);
            }

            /* 0为不相交，非零为相交 */
            if (Judge_Intersect(P[i + 2], P[i + 102], P[(int32_T)((3.0 + (real_T)
                   i) + 1.0) - 1], P[(int32_T)((3.0 + (real_T)i) + 1.0) + 99],
                                P[j], P[100 + j], P[(int32_T)((1.0 + (real_T)j)
                  + 1.0) - 1], P[(int32_T)((1.0 + (real_T)j) + 1.0) + 99]) !=
                0.0) {
              for (i26 = 0; i26 <= j; i26++) {
                tmp_data[i26] = i26;
              }

              iv40[0] = j + 1;
              iv40[1] = 2;
              b_P_size[0] = j + 1;
              b_P_size[1] = 2;
              for (i26 = 0; i26 < 2; i26++) {
                b_Point_size[i26] = b_P_size[i26];
              }

              emlrtSubAssignSizeCheckR2012b(iv40, 2, b_Point_size, 2,
                &ac_emlrtECI, sp);
              for (i26 = 0; i26 < 2; i26++) {
                for (i27 = 0; i27 <= j; i27++) {
                  Points[tmp_data[i27] + 100 * i26] = P[i27 + 100 * i26];
                }
              }

              i26 = (int32_T)((3.0 + (real_T)i) + 1.0);
              if (!((i26 >= 1) && (i26 <= 100))) {
                emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &ko_emlrtBCI, sp);
              }

              i27 = (int32_T)((3.0 + (real_T)i) + 1.0);
              if (!((i27 >= 1) && (i27 <= 100))) {
                emlrtDynamicBoundsCheckR2012b(i27, 1, 100, &lo_emlrtBCI, sp);
              }

              d_loop_ub = (int32_T)((1.0 + (real_T)j) + 1.0);
              if (!((d_loop_ub >= 1) && (d_loop_ub <= 100))) {
                emlrtDynamicBoundsCheckR2012b(d_loop_ub, 1, 100, &mo_emlrtBCI,
                  sp);
              }

              b_loop_ub = (int32_T)((1.0 + (real_T)j) + 1.0);
              if (!((b_loop_ub >= 1) && (b_loop_ub <= 100))) {
                emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, 100, &no_emlrtBCI,
                  sp);
              }

              st.site = &ud_emlrtRSI;
              CalculateLineCrossover(&st, P[i + 2], P[i + 102], P[i26 - 1],
                P[i27 + 99], P[j], P[100 + j], P[d_loop_ub - 1], P[b_loop_ub +
                99], dv3);
              i26 = (int32_T)((1.0 + (real_T)j) + 1.0);
              if (!((i26 >= 1) && (i26 <= 100))) {
                emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &kn_emlrtBCI, sp);
              }

              for (i26 = 0; i26 < 2; i26++) {
                Points[((int32_T)((1.0 + (real_T)j) + 1.0) + 100 * i26) - 1] =
                  dv3[i26];
              }

              if ((3.0 + (real_T)i) + 1.0 > n) {
                i26 = 0;
                i27 = -1;
              } else {
                i26 = (int32_T)((3.0 + (real_T)i) + 1.0);
                if (!((i26 >= 1) && (i26 <= 100))) {
                  emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &ln_emlrtBCI, sp);
                }

                i26--;
                i27 = (int32_T)n;
                if (!((i27 >= 1) && (i27 <= 100))) {
                  emlrtDynamicBoundsCheckR2012b(i27, 1, 100, &ln_emlrtBCI, sp);
                }

                i27--;
              }

              d3 = (((1.0 + (real_T)j) + 1.0) + n) - (3.0 + (real_T)i);
              if ((1.0 + (real_T)j) + 2.0 > d3) {
                d_loop_ub = 0;
                b_loop_ub = 0;
              } else {
                d_loop_ub = (int32_T)((1.0 + (real_T)j) + 2.0);
                if (!((d_loop_ub >= 1) && (d_loop_ub <= 100))) {
                  emlrtDynamicBoundsCheckR2012b(d_loop_ub, 1, 100, &jn_emlrtBCI,
                    sp);
                }

                d_loop_ub--;
                b_loop_ub = (int32_T)d3;
                if (!((b_loop_ub >= 1) && (b_loop_ub <= 100))) {
                  emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, 100, &jn_emlrtBCI,
                    sp);
                }
              }

              loop_ub = b_loop_ub - d_loop_ub;
              for (c_loop_ub = 0; c_loop_ub < loop_ub; c_loop_ub++) {
                tmp_data[c_loop_ub] = d_loop_ub + c_loop_ub;
              }

              iv41[0] = b_loop_ub - d_loop_ub;
              iv41[1] = 2;
              c_P_size[0] = (i27 - i26) + 1;
              c_P_size[1] = 2;
              for (d_loop_ub = 0; d_loop_ub < 2; d_loop_ub++) {
                b_Point_size[d_loop_ub] = c_P_size[d_loop_ub];
              }

              emlrtSubAssignSizeCheckR2012b(iv41, 2, b_Point_size, 2,
                &yb_emlrtECI, sp);
              for (d_loop_ub = 0; d_loop_ub < 2; d_loop_ub++) {
                loop_ub = i27 - i26;
                for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
                  Points[tmp_data[b_loop_ub] + 100 * d_loop_ub] = P[(i26 +
                    b_loop_ub) + 100 * d_loop_ub];
                }
              }

              *Cnt = (((1.0 + (real_T)j) + 1.0) + n) - (3.0 + (real_T)i);
              ff = 1;
              if (1.0 + (real_T)j == n - 3.0) {
                tt_j = 1;
              }

              exitg3 = true;
            } else {
              for (i26 = 0; i26 <= j; i26++) {
                tmp_data[i26] = i26;
              }

              iv42[0] = j + 1;
              iv42[1] = 2;
              d_P_size[0] = j + 1;
              d_P_size[1] = 2;
              for (i26 = 0; i26 < 2; i26++) {
                b_Point_size[i26] = d_P_size[i26];
              }

              emlrtSubAssignSizeCheckR2012b(iv42, 2, b_Point_size, 2,
                &xb_emlrtECI, sp);
              for (i26 = 0; i26 < 2; i26++) {
                for (i27 = 0; i27 <= j; i27++) {
                  Points[tmp_data[i27] + 100 * i26] = P[i27 + 100 * i26];
                }
              }

              *Cnt = 1.0 + (real_T)j;
              if (1.0 + (real_T)j == n - 3.0) {
                /* i最多等于n-1,故j最多等于n-3 */
                for (i26 = 0; i26 < 2; i26++) {
                  for (i27 = 0; i27 < 3; i27++) {
                    d_loop_ub = (int32_T)(n + (-2.0 + (real_T)i27));
                    if (!((d_loop_ub >= 1) && (d_loop_ub <= 100))) {
                      emlrtDynamicBoundsCheckR2012b(d_loop_ub, 1, 100,
                        &io_emlrtBCI, sp);
                    }

                    b_loop_ub = (int32_T)((1.0 + (real_T)j) + (1.0 + (real_T)i27));
                    if (!((b_loop_ub >= 1) && (b_loop_ub <= 100))) {
                      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, 100,
                        &jo_emlrtBCI, sp);
                    }

                    Points[(b_loop_ub + 100 * i26) - 1] = P[(d_loop_ub + 100 *
                      i26) - 1];
                  }
                }

                *Cnt = (1.0 + (real_T)j) + 3.0;
                tt = 0;
              }

              j++;
              if (*emlrtBreakCheckR2012bFlagVar != 0) {
                emlrtBreakCheckR2012b(sp);
              }
            }
          }

          if (ff == 1) {
            if (1.0 > *Cnt) {
              loop_ub = -1;
            } else {
              i26 = (int32_T)*Cnt;
              if (!((i26 >= 1) && (i26 <= 100))) {
                emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &in_emlrtBCI, sp);
              }

              loop_ub = i26 - 1;
            }

            if (1.0 > *Cnt) {
              b_loop_ub = 0;
            } else {
              b_loop_ub = (int32_T)*Cnt;
            }

            for (i26 = 0; i26 < b_loop_ub; i26++) {
              tmp_data[i26] = i26;
            }

            iv43[0] = b_loop_ub;
            iv43[1] = 2;
            Points_size[0] = loop_ub + 1;
            Points_size[1] = 2;
            for (i26 = 0; i26 < 2; i26++) {
              b_Point_size[i26] = Points_size[i26];
            }

            emlrtSubAssignSizeCheckR2012b(iv43, 2, b_Point_size, 2, &wb_emlrtECI,
              sp);
            for (i26 = 0; i26 < 2; i26++) {
              for (i27 = 0; i27 <= loop_ub; i27++) {
                P[tmp_data[i27] + 100 * i26] = Points[i27 + 100 * i26];
              }
            }

            PD_Cnt = *Cnt;
            if (tt_j == 1) {
              tt = 0;
            }

            exitg2 = true;
          } else {
            guard1 = true;
          }
        } else {
          j = 0;
          exitg4 = false;
          while ((!exitg4) && (j <= (int32_T)(((3.0 + (real_T)i) - 2.0) + -1.0)
                               - 1)) {
            i26 = (int32_T)(3.0 + (real_T)i);
            if (!((i26 >= 1) && (i26 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &hn_emlrtBCI, sp);
            }

            i26 = (int32_T)(3.0 + (real_T)i);
            if (!((i26 >= 1) && (i26 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &gn_emlrtBCI, sp);
            }

            i26 = (int32_T)(2.0 + (real_T)j);
            if (!((i26 >= 1) && (i26 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &fn_emlrtBCI, sp);
            }

            i26 = (int32_T)(2.0 + (real_T)j);
            if (!((i26 >= 1) && (i26 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &en_emlrtBCI, sp);
            }

            i26 = (int32_T)((2.0 + (real_T)j) + 1.0);
            if (!((i26 >= 1) && (i26 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &dn_emlrtBCI, sp);
            }

            i26 = (int32_T)((2.0 + (real_T)j) + 1.0);
            if (!((i26 >= 1) && (i26 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &cn_emlrtBCI, sp);
            }

            /* 0为不相交，非零为相交 */
            if (Judge_Intersect(P[i + 2], P[i + 102], P[0], P[100], P[j + 1],
                                P[j + 101], P[(int32_T)((2.0 + (real_T)j) + 1.0)
                                - 1], P[(int32_T)((2.0 + (real_T)j) + 1.0) + 99])
                != 0.0) {
              loop_ub = (int32_T)(2.0 + (real_T)j);
              for (i26 = 0; i26 < loop_ub; i26++) {
                tmp_data[i26] = i26;
              }

              iv44[0] = (int32_T)(2.0 + (real_T)j);
              iv44[1] = 2;
              e_P_size[0] = (int32_T)(2.0 + (real_T)j);
              e_P_size[1] = 2;
              for (i26 = 0; i26 < 2; i26++) {
                b_Point_size[i26] = e_P_size[i26];
              }

              emlrtSubAssignSizeCheckR2012b(iv44, 2, b_Point_size, 2,
                &vb_emlrtECI, sp);
              loop_ub = (int32_T)(2.0 + (real_T)j) - 1;
              for (i26 = 0; i26 < 2; i26++) {
                for (i27 = 0; i27 <= loop_ub; i27++) {
                  Points[tmp_data[i27] + 100 * i26] = P[i27 + 100 * i26];
                }
              }

              i26 = (int32_T)((3.0 + (real_T)i) + 1.0);
              if (!((i26 >= 1) && (i26 <= 100))) {
                emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &eo_emlrtBCI, sp);
              }

              i27 = (int32_T)((3.0 + (real_T)i) + 1.0);
              if (!((i27 >= 1) && (i27 <= 100))) {
                emlrtDynamicBoundsCheckR2012b(i27, 1, 100, &fo_emlrtBCI, sp);
              }

              d_loop_ub = (int32_T)((2.0 + (real_T)j) + 1.0);
              if (!((d_loop_ub >= 1) && (d_loop_ub <= 100))) {
                emlrtDynamicBoundsCheckR2012b(d_loop_ub, 1, 100, &go_emlrtBCI,
                  sp);
              }

              b_loop_ub = (int32_T)((2.0 + (real_T)j) + 1.0);
              if (!((b_loop_ub >= 1) && (b_loop_ub <= 100))) {
                emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, 100, &ho_emlrtBCI,
                  sp);
              }

              st.site = &td_emlrtRSI;
              CalculateLineCrossover(&st, P[i + 2], P[i + 102], P[i26 - 1],
                P[i27 + 99], P[j + 1], P[j + 101], P[d_loop_ub - 1], P[b_loop_ub
                + 99], dv3);
              i26 = (int32_T)((2.0 + (real_T)j) + 1.0);
              if (!((i26 >= 1) && (i26 <= 100))) {
                emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &bn_emlrtBCI, sp);
              }

              for (i26 = 0; i26 < 2; i26++) {
                Points[((int32_T)((2.0 + (real_T)j) + 1.0) + 100 * i26) - 1] =
                  dv3[i26];
              }

              /* Points(j+2:j+1+n-i,1:2) = P(i+1:n,:); */
              *Cnt = (2.0 + (real_T)j) + 1.0;
              ff = 1;
              if (2.0 + (real_T)j == n - 2.0) {
                tt_j = 1;
              }

              exitg4 = true;
            } else {
              loop_ub = (int32_T)(2.0 + (real_T)j);
              for (i26 = 0; i26 < loop_ub; i26++) {
                tmp_data[i26] = i26;
              }

              iv45[0] = (int32_T)(2.0 + (real_T)j);
              iv45[1] = 2;
              f_P_size[0] = (int32_T)(2.0 + (real_T)j);
              f_P_size[1] = 2;
              for (i26 = 0; i26 < 2; i26++) {
                b_Point_size[i26] = f_P_size[i26];
              }

              emlrtSubAssignSizeCheckR2012b(iv45, 2, b_Point_size, 2,
                &ub_emlrtECI, sp);
              loop_ub = (int32_T)(2.0 + (real_T)j) - 1;
              for (i26 = 0; i26 < 2; i26++) {
                for (i27 = 0; i27 <= loop_ub; i27++) {
                  Points[tmp_data[i27] + 100 * i26] = P[i27 + 100 * i26];
                }
              }

              *Cnt = 2.0 + (real_T)j;
              if (2.0 + (real_T)j == n - 2.0) {
                /* i最多等于n,故j最多等于n-2 */
                for (i26 = 0; i26 < 2; i26++) {
                  for (i27 = 0; i27 < 2; i27++) {
                    d_loop_ub = (int32_T)(n + (-1.0 + (real_T)i27));
                    if (!((d_loop_ub >= 1) && (d_loop_ub <= 100))) {
                      emlrtDynamicBoundsCheckR2012b(d_loop_ub, 1, 100,
                        &co_emlrtBCI, sp);
                    }

                    b_loop_ub = (int32_T)((2.0 + (real_T)j) + (1.0 + (real_T)i27));
                    if (!((b_loop_ub >= 1) && (b_loop_ub <= 100))) {
                      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, 100,
                        &do_emlrtBCI, sp);
                    }

                    Points[(b_loop_ub + 100 * i26) - 1] = P[(d_loop_ub + 100 *
                      i26) - 1];
                  }
                }

                *Cnt = (2.0 + (real_T)j) + 2.0;
                tt = 0;
              }

              j++;
              if (*emlrtBreakCheckR2012bFlagVar != 0) {
                emlrtBreakCheckR2012b(sp);
              }
            }
          }

          if (ff == 1) {
            if (1.0 > *Cnt) {
              loop_ub = -1;
            } else {
              i26 = (int32_T)*Cnt;
              if (!((i26 >= 1) && (i26 <= 100))) {
                emlrtDynamicBoundsCheckR2012b(i26, 1, 100, &an_emlrtBCI, sp);
              }

              loop_ub = i26 - 1;
            }

            if (1.0 > *Cnt) {
              b_loop_ub = 0;
            } else {
              b_loop_ub = (int32_T)*Cnt;
            }

            for (i26 = 0; i26 < b_loop_ub; i26++) {
              tmp_data[i26] = i26;
            }

            iv46[0] = b_loop_ub;
            iv46[1] = 2;
            b_Points_size[0] = loop_ub + 1;
            b_Points_size[1] = 2;
            for (i26 = 0; i26 < 2; i26++) {
              b_Point_size[i26] = b_Points_size[i26];
            }

            emlrtSubAssignSizeCheckR2012b(iv46, 2, b_Point_size, 2, &tb_emlrtECI,
              sp);
            for (i26 = 0; i26 < 2; i26++) {
              for (i27 = 0; i27 <= loop_ub; i27++) {
                P[tmp_data[i27] + 100 * i26] = Points[i27 + 100 * i26];
              }
            }

            PD_Cnt = *Cnt;
            if (tt_j == 1) {
              tt = 0;
            }

            exitg2 = true;
          } else {
            guard1 = true;
          }
        }

        if (guard1) {
          i++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }
      }

      if (1.0 > PD_Cnt) {
        loop_ub = 0;
      } else {
        loop_ub = (int32_T)PD_Cnt;
        if (!((loop_ub >= 1) && (loop_ub <= 100))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 100, &ym_emlrtBCI, sp);
        }
      }

      g_P_size[0] = loop_ub;
      g_P_size[1] = 2;
      for (i26 = 0; i26 < 2; i26++) {
        for (i27 = 0; i27 < loop_ub; i27++) {
          e_NEdgevectorList_data[i27 + loop_ub * i26] = P[i27 + 100 * i26];
        }
      }

      st.site = &sd_emlrtRSI;
      Preprocess(&st, e_NEdgevectorList_data, g_P_size, PD_Cnt,
                 Prep_Preprocessing, &Prep_Cnt);
      memcpy(&P[0], &Prep_Preprocessing[0], 200U * sizeof(real_T));
      PD_Cnt = Prep_Cnt;
      n = Prep_Cnt;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (CalculateNewPoint.c) */
