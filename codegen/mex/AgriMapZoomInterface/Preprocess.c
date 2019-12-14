/*
 * Preprocess.c
 *
 * Code generation for function 'Preprocess'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "Preprocess.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "NormalizeDPList.h"
#include "DPList.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRSInfo p_emlrtRSI = { 51, "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m" };

static emlrtRSInfo q_emlrtRSI = { 52, "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m" };

static emlrtRTEInfo emlrtRTEI = { 1, 17, "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m" };

static emlrtRTEInfo b_emlrtRTEI = { 16, 1, "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m" };

static emlrtRTEInfo c_emlrtRTEI = { 38, 1, "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m" };

static emlrtRTEInfo d_emlrtRTEI = { 50, 1, "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m" };

static emlrtRTEInfo e_emlrtRTEI = { 54, 1, "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m" };

static emlrtDCInfo f_emlrtDCI = { 16, 13, "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 4 };

static emlrtDCInfo g_emlrtDCI = { 16, 13, "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 1 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 18, 26, "Point", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 18, 5, "P_M", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtECInfo l_emlrtECI = { -1, 18, 1, "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m" };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 21, 21, "P_M", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 21, 36, "P_M", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 22, 16, "P_M", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo ob_emlrtBCI = { -1, -1, 22, 25, "P_M", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo pb_emlrtBCI = { -1, -1, 23, 9, "P_M", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo qb_emlrtBCI = { -1, -1, 29, 24, "P_M", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo rb_emlrtBCI = { -1, -1, 29, 33, "P_M", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtDCInfo h_emlrtDCI = { 38, 19, "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 4 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 44, 39, "P_M", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 44, 19, "Point_map", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 51, 52, "Point_map", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtECInfo m_emlrtECI = { -1, 51, 1, "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m" };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 52, 67, "NEdgevectorList",
  "Preprocess", "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 52, 17, "NEdgevectorList",
  "Preprocess", "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtECInfo n_emlrtECI = { -1, 52, 1, "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m" };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 56, 23, "NEdgevectorList",
  "Preprocess", "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 56, 79, "NEdgevectorList",
  "Preprocess", "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 57, 17, "IndexPrepro", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 60, 17, "IndexPrepro", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 76, 44, "Point_map", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 76, 20, "Point_map1", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 79, 56, "Point_map1", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo fc_emlrtBCI = { 1, 100, 79, 20, "Prep.Preprocessing",
  "Preprocess", "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtECInfo o_emlrtECI = { -1, 79, 1, "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m" };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 56, 44, "NEdgevectorList",
  "Preprocess", "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 56, 100, "NEdgevectorList",
  "Preprocess", "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 74, 23, "IndexPrepro", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 63, 27, "NEdgevectorList",
  "Preprocess", "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 63, 48, "NEdgevectorList",
  "Preprocess", "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 63, 78, "NEdgevectorList",
  "Preprocess", "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 63, 99, "NEdgevectorList",
  "Preprocess", "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 67, 21, "IndexPrepro", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 64, 21, "IndexPrepro", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 42, 15, "P_M", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 28, 29, "P_M", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 28, 44, "P_M", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 30, 17, "P_M", "Preprocess",
  "D:\\2.AgriMapZoom\\Preprocess.m", 0 };

/* Function Definitions */
void Preprocess(const emlrtStack *sp, const real_T Point_data[], const int32_T
                Point_size[2], real_T P_Cnt, real_T Prep_Preprocessing[200],
                real_T *Prep_Cnt)
{
  emxArray_real_T *P_M;
  int32_T i1;
  real_T varargin_1_idx_1;
  int32_T loop_ub;
  real_T Count;
  int32_T ixstart;
  emxArray_int32_T *r0;
  int32_T NEdgevectorList[2];
  int32_T b_Point_size[2];
  int32_T Point[2];
  real_T mtmp;
  boolean_T exitg5;
  real_T x[3];
  real_T y[3];
  boolean_T b_y;
  boolean_T exitg4;
  int32_T i;
  int32_T j;
  boolean_T exitg1;
  boolean_T exitg3;
  boolean_T exitg2;
  emxArray_real_T *Point_map;
  int32_T Cnt;
  emxArray_real_T *b_NEdgevectorList;
  emxArray_real_T *b_Point_map;
  emxArray_real_T *r1;
  int32_T iv9[2];
  emxArray_real_T *c_NEdgevectorList;
  int32_T iv10[2];
  emxArray_real_T *IndexPrepro;
  real_T Index_Cnt;
  boolean_T guard2 = false;
  boolean_T guard1 = false;
  uint32_T m;
  int32_T tmp_data[100];
  emxArray_real_T *d_NEdgevectorList;
  int32_T iv11[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* 对输入数据进行预处理，排除重合和连续三点在同一条直线上的情况 */
  /* { */
  /* 输入： */
  /* Point为输入的边界点 */
  /* P_Cnt:边界点的个数 */
  /* 输出： */
  /* Prep为经过去重和去连续连续操作后的点集的结构体，格式为50乘以2 */
  /* Prep.Preprocessing:格式为50乘以2 */
  /* Prep.Cnt:有效点的个数 */
  /* } */
  /* % */
  memset(&Prep_Preprocessing[0], 0, 200U * sizeof(real_T));
  emxInit_real_T(sp, &P_M, 2, &b_emlrtRTEI, true);
  i1 = P_M->size[0] * P_M->size[1];
  if (!(P_Cnt > 0.0)) {
    emlrtNonNegativeCheckR2012b(P_Cnt, &f_emlrtDCI, sp);
  }

  if (P_Cnt != (int32_T)muDoubleScalarFloor(P_Cnt)) {
    emlrtIntegerCheckR2012b(P_Cnt, &g_emlrtDCI, sp);
  }

  P_M->size[0] = (int32_T)P_Cnt;
  P_M->size[1] = 3;
  emxEnsureCapacity(sp, (emxArray__common *)P_M, i1, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  if (!(P_Cnt > 0.0)) {
    emlrtNonNegativeCheckR2012b(P_Cnt, &f_emlrtDCI, sp);
  }

  varargin_1_idx_1 = P_Cnt;
  if (varargin_1_idx_1 != (int32_T)muDoubleScalarFloor(varargin_1_idx_1)) {
    emlrtIntegerCheckR2012b(varargin_1_idx_1, &g_emlrtDCI, sp);
  }

  loop_ub = (int32_T)varargin_1_idx_1 * 3;
  for (i1 = 0; i1 < loop_ub; i1++) {
    P_M->data[i1] = 0.0;
  }

  Count = 0.0;
  if (1.0 > P_Cnt) {
    loop_ub = -1;
  } else {
    if (!(1 <= Point_size[0])) {
      emlrtDynamicBoundsCheckR2012b(1, 1, Point_size[0], &jb_emlrtBCI, sp);
    }

    i1 = (int32_T)P_Cnt;
    if (!((i1 >= 1) && (i1 <= Point_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, Point_size[0], &jb_emlrtBCI, sp);
    }

    loop_ub = i1 - 1;
  }

  if (1.0 > P_Cnt) {
    ixstart = 0;
  } else {
    i1 = (int32_T)P_Cnt;
    ixstart = (int32_T)P_Cnt;
    if (!((ixstart >= 1) && (ixstart <= i1))) {
      emlrtDynamicBoundsCheckR2012b(ixstart, 1, i1, &kb_emlrtBCI, sp);
    }
  }

  emxInit_int32_T(sp, &r0, 1, &emlrtRTEI, true);
  i1 = r0->size[0];
  r0->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  for (i1 = 0; i1 < ixstart; i1++) {
    r0->data[i1] = i1;
  }

  NEdgevectorList[0] = r0->size[0];
  NEdgevectorList[1] = 2;
  b_Point_size[0] = loop_ub + 1;
  b_Point_size[1] = 2;
  for (i1 = 0; i1 < 2; i1++) {
    Point[i1] = b_Point_size[i1];
  }

  emlrtSubAssignSizeCheckR2012b(NEdgevectorList, 2, Point, 2, &l_emlrtECI, sp);
  for (i1 = 0; i1 < 2; i1++) {
    for (ixstart = 0; ixstart <= loop_ub; ixstart++) {
      P_M->data[r0->data[ixstart] + P_M->size[0] * i1] = Point_data[ixstart +
        Point_size[0] * i1];
    }
  }

  /* P_M的第三列是标志位，为1的话则此行需删除 */
  i1 = P_M->size[0];
  if (!(2 <= i1)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i1, &lb_emlrtBCI, sp);
  }

  i1 = P_M->size[0];
  if (!(2 <= i1)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i1, &mb_emlrtBCI, sp);
  }

  mtmp = P_M->data[1] * 0.005;
  varargin_1_idx_1 = P_M->data[1 + P_M->size[0]] * 0.005;
  ixstart = 1;
  if (muDoubleScalarIsNaN(mtmp)) {
    loop_ub = 2;
    exitg5 = false;
    while ((!exitg5) && (loop_ub < 3)) {
      ixstart = 2;
      if (!muDoubleScalarIsNaN(varargin_1_idx_1)) {
        mtmp = varargin_1_idx_1;
        exitg5 = true;
      } else {
        loop_ub = 3;
      }
    }
  }

  if ((ixstart < 2) && (varargin_1_idx_1 < mtmp)) {
    mtmp = varargin_1_idx_1;
  }

  /* 工程上要求的千分之五 */
  i1 = P_M->size[0];
  if (!(1 <= i1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i1, &nb_emlrtBCI, sp);
  }

  i1 = P_M->size[0];
  if (!(2 <= i1)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i1, &ob_emlrtBCI, sp);
  }

  for (i1 = 0; i1 < 3; i1++) {
    x[i1] = P_M->data[P_M->size[0] * i1] - P_M->data[1 + P_M->size[0] * i1];
  }

  for (ixstart = 0; ixstart < 3; ixstart++) {
    y[ixstart] = muDoubleScalarAbs(x[ixstart]);
  }

  b_y = true;
  ixstart = 0;
  exitg4 = false;
  while ((!exitg4) && (ixstart < 3)) {
    if (!(y[ixstart] <= mtmp)) {
      b_y = false;
      exitg4 = true;
    } else {
      ixstart++;
    }
  }

  if (b_y) {
    i1 = P_M->size[0];
    if (!(2 <= i1)) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i1, &pb_emlrtBCI, sp);
    }

    P_M->data[1 + (P_M->size[0] << 1)] = 1.0;

    /* 为了占位给重复的地方替换为其他值，替换值要尽量不要跟数据采集点重复，采集点恰好与该值相等的概率极低（即：该值最好取地块的内部一点） */
    Count = 1.0;
  }

  i = 3;
  while (i - 3 <= (int32_T)P_Cnt - 3) {
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j <= i - 2)) {
      i1 = P_M->size[0];
      if (!((i >= 1) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i1, &qc_emlrtBCI, sp);
      }

      mtmp = P_M->data[i - 1] * 0.005;
      i1 = P_M->size[0];
      if (!((i >= 1) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i1, &rc_emlrtBCI, sp);
      }

      varargin_1_idx_1 = P_M->data[(i + P_M->size[0]) - 1] * 0.005;
      ixstart = 1;
      if (muDoubleScalarIsNaN(mtmp)) {
        loop_ub = 2;
        exitg3 = false;
        while ((!exitg3) && (loop_ub < 3)) {
          ixstart = 2;
          if (!muDoubleScalarIsNaN(varargin_1_idx_1)) {
            mtmp = varargin_1_idx_1;
            exitg3 = true;
          } else {
            loop_ub = 3;
          }
        }
      }

      if ((ixstart < 2) && (varargin_1_idx_1 < mtmp)) {
        mtmp = varargin_1_idx_1;
      }

      /* 工程上要求的千分之五 */
      i1 = P_M->size[0];
      if (!((j + 1 >= 1) && (j + 1 <= i1))) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &qb_emlrtBCI, sp);
      }

      ixstart = j + 1;
      i1 = P_M->size[0];
      if (!((i >= 1) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i1, &rb_emlrtBCI, sp);
      }

      for (i1 = 0; i1 < 3; i1++) {
        x[i1] = P_M->data[(ixstart + P_M->size[0] * i1) - 1] - P_M->data[(i +
          P_M->size[0] * i1) - 1];
      }

      for (ixstart = 0; ixstart < 3; ixstart++) {
        y[ixstart] = muDoubleScalarAbs(x[ixstart]);
      }

      b_y = true;
      ixstart = 0;
      exitg2 = false;
      while ((!exitg2) && (ixstart < 3)) {
        if (!(y[ixstart] <= mtmp)) {
          b_y = false;
          exitg2 = true;
        } else {
          ixstart++;
        }
      }

      if (b_y) {
        i1 = P_M->size[0];
        if (!((i >= 1) && (i <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i1, &sc_emlrtBCI, sp);
        }

        P_M->data[(i + (P_M->size[0] << 1)) - 1] = 1.0;
        Count++;
        exitg1 = true;
      } else {
        j++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_real_T(sp, &Point_map, 2, &c_emlrtRTEI, true);

  /* % */
  /* 保留不重复的点 */
  i1 = Point_map->size[0] * Point_map->size[1];
  ixstart = (int32_T)(P_Cnt - Count);
  if (!(ixstart > 0)) {
    emlrtNonNegativeCheckR2012b(ixstart, &h_emlrtDCI, sp);
  }

  Point_map->size[0] = ixstart;
  Point_map->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)Point_map, i1, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  i1 = (int32_T)(P_Cnt - Count);
  if (!(i1 > 0)) {
    emlrtNonNegativeCheckR2012b(i1, &h_emlrtDCI, sp);
  }

  loop_ub = i1 << 1;
  for (i1 = 0; i1 < loop_ub; i1++) {
    Point_map->data[i1] = 0.0;
  }

  Cnt = 0;

  /* 第一位用于下标计数 */
  i = 1;
  while (i - 1 <= (int32_T)P_Cnt - 1) {
    i1 = P_M->size[0];
    if (!((i >= 1) && (i <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i1, &pc_emlrtBCI, sp);
    }

    if (P_M->data[(i + (P_M->size[0] << 1)) - 1] == 0.0) {
      Cnt++;
      i1 = P_M->size[0];
      if (!((i >= 1) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i1, &sb_emlrtBCI, sp);
      }

      ixstart = Point_map->size[0];
      if (!((Cnt >= 1) && (Cnt <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(Cnt, 1, ixstart, &tb_emlrtBCI, sp);
      }

      for (i1 = 0; i1 < 2; i1++) {
        Point_map->data[(Cnt + Point_map->size[0] * i1) - 1] = P_M->data[(i +
          P_M->size[0] * i1) - 1];
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&P_M);
  emxInit_real_T(sp, &b_NEdgevectorList, 2, &d_emlrtRTEI, true);

  /* 以上代码解决了点的重复问题 */
  /* % */
  /* %以下代码解决连续三点在同一条直线上的问题 */
  i1 = b_NEdgevectorList->size[0] * b_NEdgevectorList->size[1];
  b_NEdgevectorList->size[0] = Cnt;
  b_NEdgevectorList->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)b_NEdgevectorList, i1, (int32_T)
                    sizeof(real_T), &emlrtRTEI);
  loop_ub = Cnt << 1;
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_NEdgevectorList->data[i1] = 0.0;
  }

  if (1 > Cnt) {
    loop_ub = 0;
  } else {
    i1 = Point_map->size[0];
    if (!(1 <= i1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i1, &ub_emlrtBCI, sp);
    }

    i1 = Point_map->size[0];
    if (!(Cnt <= i1)) {
      emlrtDynamicBoundsCheckR2012b(Cnt, 1, i1, &ub_emlrtBCI, sp);
    }

    loop_ub = Cnt;
  }

  if (1 > Cnt) {
    ixstart = 0;
  } else {
    ixstart = Cnt;
  }

  i1 = r0->size[0];
  r0->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  for (i1 = 0; i1 < ixstart; i1++) {
    r0->data[i1] = i1;
  }

  emxInit_real_T(sp, &b_Point_map, 2, &emlrtRTEI, true);
  i1 = b_Point_map->size[0] * b_Point_map->size[1];
  b_Point_map->size[0] = loop_ub;
  b_Point_map->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)b_Point_map, i1, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  for (i1 = 0; i1 < 2; i1++) {
    for (ixstart = 0; ixstart < loop_ub; ixstart++) {
      b_Point_map->data[ixstart + b_Point_map->size[0] * i1] = Point_map->
        data[ixstart + Point_map->size[0] * i1];
    }
  }

  emxInit_real_T(sp, &r1, 2, &emlrtRTEI, true);
  st.site = &p_emlrtRSI;
  DPList(&st, b_Point_map, Cnt, r1);
  iv9[0] = r0->size[0];
  iv9[1] = 2;
  emlrtSubAssignSizeCheckR2012b(iv9, 2, *(int32_T (*)[2])r1->size, 2,
    &m_emlrtECI, sp);
  emxFree_real_T(&b_Point_map);
  for (i1 = 0; i1 < 2; i1++) {
    loop_ub = r1->size[0];
    for (ixstart = 0; ixstart < loop_ub; ixstart++) {
      b_NEdgevectorList->data[r0->data[ixstart] + b_NEdgevectorList->size[0] *
        i1] = r1->data[ixstart + r1->size[0] * i1];
    }
  }

  if (1 > Cnt) {
    loop_ub = 0;
  } else {
    i1 = b_NEdgevectorList->size[0];
    if (!(1 <= i1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i1, &vb_emlrtBCI, sp);
    }

    i1 = b_NEdgevectorList->size[0];
    if (!(Cnt <= i1)) {
      emlrtDynamicBoundsCheckR2012b(Cnt, 1, i1, &vb_emlrtBCI, sp);
    }

    loop_ub = Cnt;
  }

  if (1 > Cnt) {
    ixstart = 0;
  } else {
    i1 = b_NEdgevectorList->size[0];
    if (!(1 <= i1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i1, &wb_emlrtBCI, sp);
    }

    i1 = b_NEdgevectorList->size[0];
    if (!(Cnt <= i1)) {
      emlrtDynamicBoundsCheckR2012b(Cnt, 1, i1, &wb_emlrtBCI, sp);
    }

    ixstart = Cnt;
  }

  i1 = r0->size[0];
  r0->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  for (i1 = 0; i1 < ixstart; i1++) {
    r0->data[i1] = i1;
  }

  emxInit_real_T(sp, &c_NEdgevectorList, 2, &emlrtRTEI, true);
  i1 = c_NEdgevectorList->size[0] * c_NEdgevectorList->size[1];
  c_NEdgevectorList->size[0] = loop_ub;
  c_NEdgevectorList->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)c_NEdgevectorList, i1, (int32_T)
                    sizeof(real_T), &emlrtRTEI);
  for (i1 = 0; i1 < 2; i1++) {
    for (ixstart = 0; ixstart < loop_ub; ixstart++) {
      c_NEdgevectorList->data[ixstart + c_NEdgevectorList->size[0] * i1] =
        b_NEdgevectorList->data[ixstart + b_NEdgevectorList->size[0] * i1];
    }
  }

  st.site = &q_emlrtRSI;
  NormalizeDPList(&st, c_NEdgevectorList, Cnt, r1);
  iv10[0] = r0->size[0];
  iv10[1] = 2;
  emlrtSubAssignSizeCheckR2012b(iv10, 2, *(int32_T (*)[2])r1->size, 2,
    &n_emlrtECI, sp);
  emxFree_real_T(&c_NEdgevectorList);
  for (i1 = 0; i1 < 2; i1++) {
    loop_ub = r1->size[0];
    for (ixstart = 0; ixstart < loop_ub; ixstart++) {
      b_NEdgevectorList->data[r0->data[ixstart] + b_NEdgevectorList->size[0] *
        i1] = r1->data[ixstart + r1->size[0] * i1];
    }
  }

  emxFree_real_T(&r1);
  emxFree_int32_T(&r0);
  emxInit_real_T1(sp, &IndexPrepro, 1, &e_emlrtRTEI, true);

  /* 各边的单位向量 */
  i1 = IndexPrepro->size[0];
  IndexPrepro->size[0] = Cnt;
  emxEnsureCapacity(sp, (emxArray__common *)IndexPrepro, i1, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  for (i1 = 0; i1 < Cnt; i1++) {
    IndexPrepro->data[i1] = 0.0;
  }

  /* 与前面单位向量相等的点的点号的存储,列向量 */
  Index_Cnt = 0.0;
  i1 = b_NEdgevectorList->size[0];
  if (!(1 <= i1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i1, &xb_emlrtBCI, sp);
  }

  i1 = b_NEdgevectorList->size[0];
  if (!((Cnt >= 1) && (Cnt <= i1))) {
    emlrtDynamicBoundsCheckR2012b(Cnt, 1, i1, &gc_emlrtBCI, sp);
  }

  guard2 = false;
  if (b_NEdgevectorList->data[0] == b_NEdgevectorList->data[Cnt - 1]) {
    i1 = b_NEdgevectorList->size[0];
    if (!(1 <= i1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i1, &yb_emlrtBCI, sp);
    }

    i1 = b_NEdgevectorList->size[0];
    if (!((Cnt >= 1) && (Cnt <= i1))) {
      emlrtDynamicBoundsCheckR2012b(Cnt, 1, i1, &hc_emlrtBCI, sp);
    }

    if (b_NEdgevectorList->data[b_NEdgevectorList->size[0]] ==
        b_NEdgevectorList->data[(Cnt + b_NEdgevectorList->size[0]) - 1]) {
      if (!(1 <= Cnt)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, Cnt, &ac_emlrtBCI, sp);
      }

      IndexPrepro->data[0] = 1.0;

      /* 与前面单位向量相等的点号 */
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2) {
    Index_Cnt = 1.0;
    if (!(1 <= Cnt)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, Cnt, &bc_emlrtBCI, sp);
    }

    IndexPrepro->data[0] = 0.0;
  }

  i = 2;
  while (i - 2 <= Cnt - 2) {
    i1 = b_NEdgevectorList->size[0];
    if (!((i >= 1) && (i <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i1, &jc_emlrtBCI, sp);
    }

    i1 = b_NEdgevectorList->size[0];
    ixstart = i - 1;
    if (!((ixstart >= 1) && (ixstart <= i1))) {
      emlrtDynamicBoundsCheckR2012b(ixstart, 1, i1, &kc_emlrtBCI, sp);
    }

    guard1 = false;
    if (b_NEdgevectorList->data[i - 1] == b_NEdgevectorList->data[ixstart - 1])
    {
      i1 = b_NEdgevectorList->size[0];
      if (!((i >= 1) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i1, &lc_emlrtBCI, sp);
      }

      i1 = b_NEdgevectorList->size[0];
      ixstart = i - 1;
      if (!((ixstart >= 1) && (ixstart <= i1))) {
        emlrtDynamicBoundsCheckR2012b(ixstart, 1, i1, &mc_emlrtBCI, sp);
      }

      if (b_NEdgevectorList->data[(i + b_NEdgevectorList->size[0]) - 1] ==
          b_NEdgevectorList->data[(ixstart + b_NEdgevectorList->size[0]) - 1]) {
        i1 = IndexPrepro->size[0];
        if (!((i >= 1) && (i <= i1))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i1, &oc_emlrtBCI, sp);
        }

        IndexPrepro->data[i - 1] = 2.0 + (real_T)(i - 2);

        /* 与前面单位向量相等的点 号 */
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      Index_Cnt++;
      i1 = IndexPrepro->size[0];
      if (!((i >= 1) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i1, &nc_emlrtBCI, sp);
      }

      IndexPrepro->data[i - 1] = 0.0;
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  i1 = b_NEdgevectorList->size[0] * b_NEdgevectorList->size[1];
  b_NEdgevectorList->size[0] = (int32_T)Index_Cnt;
  b_NEdgevectorList->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)b_NEdgevectorList, i1, (int32_T)
                    sizeof(real_T), &emlrtRTEI);
  loop_ub = (int32_T)Index_Cnt << 1;
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_NEdgevectorList->data[i1] = 0.0;
  }

  m = 0U;
  i = 1;
  while (i - 1 <= Cnt - 1) {
    i1 = IndexPrepro->size[0];
    if (!((i >= 1) && (i <= i1))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i1, &ic_emlrtBCI, sp);
    }

    if ((int32_T)IndexPrepro->data[i - 1] == 0) {
      m++;
      i1 = Point_map->size[0];
      if (!((i >= 1) && (i <= i1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i1, &cc_emlrtBCI, sp);
      }

      ixstart = b_NEdgevectorList->size[0];
      i1 = (int32_T)m;
      if (!((i1 >= 1) && (i1 <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, ixstart, &dc_emlrtBCI, sp);
      }

      for (i1 = 0; i1 < 2; i1++) {
        b_NEdgevectorList->data[((int32_T)m + b_NEdgevectorList->size[0] * i1) -
          1] = Point_map->data[(i + Point_map->size[0] * i1) - 1];
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&IndexPrepro);
  emxFree_real_T(&Point_map);
  if (1.0 > Index_Cnt) {
    loop_ub = -1;
  } else {
    i1 = b_NEdgevectorList->size[0];
    if (!(1 <= i1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i1, &ec_emlrtBCI, sp);
    }

    i1 = b_NEdgevectorList->size[0];
    ixstart = (int32_T)Index_Cnt;
    if (!((ixstart >= 1) && (ixstart <= i1))) {
      emlrtDynamicBoundsCheckR2012b(ixstart, 1, i1, &ec_emlrtBCI, sp);
    }

    loop_ub = ixstart - 1;
  }

  if (1.0 > Index_Cnt) {
    ixstart = 0;
  } else {
    ixstart = (int32_T)Index_Cnt;
    if (!((ixstart >= 1) && (ixstart <= 100))) {
      emlrtDynamicBoundsCheckR2012b(ixstart, 1, 100, &fc_emlrtBCI, sp);
    }
  }

  for (i1 = 0; i1 < ixstart; i1++) {
    tmp_data[i1] = i1;
  }

  emxInit_real_T(sp, &d_NEdgevectorList, 2, &emlrtRTEI, true);
  iv11[0] = ixstart;
  iv11[1] = 2;
  i1 = d_NEdgevectorList->size[0] * d_NEdgevectorList->size[1];
  d_NEdgevectorList->size[0] = loop_ub + 1;
  d_NEdgevectorList->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)d_NEdgevectorList, i1, (int32_T)
                    sizeof(real_T), &emlrtRTEI);
  for (i1 = 0; i1 < 2; i1++) {
    for (ixstart = 0; ixstart <= loop_ub; ixstart++) {
      d_NEdgevectorList->data[ixstart + d_NEdgevectorList->size[0] * i1] =
        b_NEdgevectorList->data[ixstart + b_NEdgevectorList->size[0] * i1];
    }
  }

  for (i1 = 0; i1 < 2; i1++) {
    NEdgevectorList[i1] = d_NEdgevectorList->size[i1];
  }

  emxFree_real_T(&d_NEdgevectorList);
  emlrtSubAssignSizeCheckR2012b(iv11, 2, NEdgevectorList, 2, &o_emlrtECI, sp);
  for (i1 = 0; i1 < 2; i1++) {
    for (ixstart = 0; ixstart <= loop_ub; ixstart++) {
      Prep_Preprocessing[tmp_data[ixstart] + 100 * i1] = b_NEdgevectorList->
        data[ixstart + b_NEdgevectorList->size[0] * i1];
    }
  }

  emxFree_real_T(&b_NEdgevectorList);
  *Prep_Cnt = Index_Cnt;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Preprocess.c) */
