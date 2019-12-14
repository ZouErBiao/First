/*
 * AgriMapZoomInterface.c
 *
 * Code generation for function 'AgriMapZoomInterface'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "flipud.h"
#include "BL2XY_q.h"
#include "XY2BL.h"
#include "Calculate_Map_Points.h"
#include "Calculate_Monolateral_Points.h"
#include "Calculate_New_Indented_Boundary_Point.h"
#include "judgeClockWise.h"
#include "Preprocess.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 197, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m" };

static emlrtRSInfo b_emlrtRSI = { 169, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m" };

static emlrtRSInfo c_emlrtRSI = { 165, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m" };

static emlrtRSInfo d_emlrtRSI = { 148, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m" };

static emlrtRSInfo f_emlrtRSI = { 131, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m" };

static emlrtRSInfo g_emlrtRSI = { 119, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m" };

static emlrtRSInfo h_emlrtRSI = { 108, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m" };

static emlrtECInfo emlrtECI = { -1, 188, 5, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m" };

static emlrtDCInfo emlrtDCI = { 188, 21, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 1 };

static emlrtECInfo b_emlrtECI = { -1, 187, 5, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m" };

static emlrtDCInfo b_emlrtDCI = { 187, 21, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 1 };

static emlrtBCInfo emlrtBCI = { -1, -1, 188, 46, "PointOut",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtDCInfo c_emlrtDCI = { 188, 46, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 1 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 187, 46, "PointOut",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtDCInfo d_emlrtDCI = { 187, 46, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 1 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 169, 69, "PointOut",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtDCInfo e_emlrtDCI = { 169, 69, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 1 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 165, 86, "PreprocessingData",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 157, 30, "PreprocessingData",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 148, 114, "PreprocessingData",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtECInfo c_emlrtECI = { -1, 137, 5, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m" };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 137, 23, "PreprocessingData",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 137, 72, "PreprocessingData",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtECInfo d_emlrtECI = { -1, 133, 5, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m" };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 133, 23, "PreprocessingData",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 133, 79, "PreprocessingData",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 131, 87, "PreprocessingData",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 131, 42, "PreprocessingData",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtECInfo e_emlrtECI = { -1, 121, 5, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m" };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 121, 23, "PreprocessingData",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo n_emlrtBCI = { 1, 100, 121, 65, "Prep.Preprocessing",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 119, 37, "PreprocessingData",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtECInfo f_emlrtECI = { -1, 115, 1, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m" };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 115, 19, "PreprocessingData",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtECInfo g_emlrtECI = { -1, 114, 1, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m" };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 114, 19, "PreprocessingData",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 115, 42, "Points",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 114, 42, "Points",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtECInfo h_emlrtECI = { -1, 80, 1, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m" };

static emlrtECInfo i_emlrtECI = { -1, 79, 1, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m" };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 94, 10, "mapLon",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 93, 10, "mapLat",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 80, 24, "mapLon",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtECInfo j_emlrtECI = { -1, 78, 1, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m" };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 78, 10, "mapLon",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 79, 24, "mapLat",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtECInfo k_emlrtECI = { -1, 77, 1, "AgriMapZoomInterface",
  "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m" };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 77, 10, "mapLat",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo ab_emlrtBCI = { 1, 100, 78, 36, "mapB.mapLon",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo bb_emlrtBCI = { 1, 100, 77, 36, "mapB.mapLat",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 197, 63, "PointOut",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 197, 77, "PointOut",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo eb_emlrtBCI = { 1, 100, 197, 11, "mapOut.mapLat",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 108, 49, "mapLat",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 108, 59, "mapLon",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 108, 23, "Points",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 108, 35, "Points",
  "AgriMapZoomInterface", "D:\\2.AgriMapZoom\\AgriMapZoomInterface.m", 0 };

/* Function Definitions */
void AgriMapZoomInterface(const emlrtStack *sp, const struct0_T *mapB, const
  struct1_T *lineM, const struct2_T *params, int32_T *ver, struct3_T *out,
  struct4_T *mapOut)
{
  int32_T i0;
  int32_T Points_size_idx_1;
  int32_T loop_ub;
  real_T Points_data[510];
  int32_T PreprocessingData_size_idx_0;
  real_T PreprocessingData_data[510];
  real_T mapLat_data[255];
  real_T mapLon_data[255];
  int32_T b_loop_ub;
  int32_T tmp_data[255];
  int32_T mapLat[2];
  uint8_T mapB_size[2];
  int32_T b_mapB[2];
  int32_T iv0[2];
  uint8_T b_mapB_size[2];
  int32_T iv1[2];
  uint8_T mapLat_size[2];
  int32_T iv2[2];
  uint8_T mapLon_size[2];
  int32_T Monolateral;
  real_T L0;
  int32_T f_Warning0;
  int32_T i;
  real_T d0;
  int32_T tmp_size[1];
  real_T b_tmp_data[255];
  int32_T iv3[1];
  int32_T iv4[1];
  real_T b_PreprocessingData_data[510];
  int32_T PreprocessingData_size[2];
  real_T Prep_Cnt;
  real_T Prep_Preprocessing[200];
  int32_T iv5[2];
  int32_T Prep_Preprocessing_size[2];
  real_T c_PreprocessingData_data[255];
  int32_T b_PreprocessingData_size[1];
  real_T d_PreprocessingData_data[255];
  int32_T c_PreprocessingData_size[1];
  emxArray_real_T e_PreprocessingData_data;
  emxArray_real_T f_PreprocessingData_data;
  real_T FFLOG;
  int32_T PointOut_size[2];
  real_T PointOut_data[510];
  int32_T iv6[2];
  int32_T Clock_Flag;
  int32_T d_PreprocessingData_size[2];
  int32_T e_PreprocessingData_size[2];
  real_T P_Cnt;
  real_T dv0[700];
  real_T dv1[350];
  real_T b_P_Cnt;
  real_T f_Warning1;
  real_T f_Warning2;
  int32_T f_PreprocessingData_size[2];
  real_T PointOut[200];
  int32_T b_PointOut_size[2];
  uint8_T u0;
  int32_T c_tmp_data[100];
  int32_T b_mapLat_size[2];
  int32_T iv7[2];
  int32_T iv8[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /* % 接口函数---缩放算法 */
  /* { */
  /* 作用:进行坐标转换、单边内外平移、多边形整体外扩或内缩 */
  /* 输入: */
  /* 整体 */
  /* mapB.mapCnt:输入的点的个数(数据类型:uint8 1x1) */
  /* mapB.mapLat:点的横坐标(数据类型:double 1x100) */
  /* mapB.mapLon:点的纵坐标(数据类型:double 1x100) */
  /* mapB.mapAlt:高度(double-1*100) */
  /* mapB.L:缩放距离(数据类型：double 1x1)，只保证L值连续变化时的调用满足预期； */
  /* mapB.flag:缩放标志，内缩外扩标志位，0:内缩，1;外扩，若输入其他值，则会有相应的警告！(数据类型:double 1x1) */
  /*  */
  /* 单边 */
  /* LineM.Monolateral:单边移动边界号，形如;1,2,3,4,5,...nn(数据类型:double 1x1) */
  /* LineM.Monolateral_L:单边移动距离(数据类型:double 1x1) */
  /* LineM.Monolateral_flag:移动方向，0:内移，1:外移;(数据类型:double 1x1) */
  /*  */
  /* params.Theita: 被认为是小锐角的角度界限，格式如：“20”，代表各顶点小于或等于20°为小锐角，需要处理；范围为0°到90°(数据类型：double 1x1) */
  /* params.mapFlag:平面坐标标志,0为平面坐标，1为经纬度坐标(数据类型：double 1x1) */
  /* params.L0:所有地块点的经度平均值(double) */
  /*  */
  /* 输出: */
  /* mapOut.mapCnt */
  /* mapOut.mapLat */
  /* mapOut.mapLon:处理后的多边形边界点 */
  /* mapOut.mapAlt */
  /*  */
  /* out.error:（错误码） */
  /* -0正常 */
  /* -(-1)不予处理,边界交叉 */
  /*  */
  /* out.warn:警告码 */
  /* -0正常 */
  /* -1异常 */
  /* f_Warning0:经纬度转换标志无效 */
  /* f_Warning1:单边移动无效(所选边序号无效+移动标志无效) */
  /* f_Warning2:整体缩放无效(移动标志无效) */
  /*  */
  /* ver:版本号 */
  /* } */
  /* % 配置 */
  /* 经纬度转换算法 */
  /* % 初始化 */
  *ver = 201;
  out->warn = 0;
  mapOut->mapCnt = 0;
  for (i0 = 0; i0 < 100; i0++) {
    mapOut->mapLat[i0] = 0.0;
    mapOut->mapLon[i0] = 0.0;
    mapOut->mapAlt[i0] = 0.0;
  }

  /*  */
  Points_size_idx_1 = mapB->mapCnt;
  loop_ub = mapB->mapCnt << 1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    Points_data[i0] = 0.0;
  }

  /* Pointmap = zeros(mapCnt,2); */
  PreprocessingData_size_idx_0 = mapB->mapCnt;
  loop_ub = mapB->mapCnt << 1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    PreprocessingData_data[i0] = 0.0;
  }

  loop_ub = mapB->mapCnt;
  for (i0 = 0; i0 < loop_ub; i0++) {
    mapLat_data[i0] = 0.0;
  }

  loop_ub = mapB->mapCnt;
  for (i0 = 0; i0 < loop_ub; i0++) {
    mapLon_data[i0] = 0.0;
  }

  /* % 入参 */
  if (1 > mapB->mapCnt) {
    loop_ub = -1;
  } else {
    i0 = mapB->mapCnt;
    if (!(i0 <= 100)) {
      emlrtDynamicBoundsCheckR2012b(i0, 1, 100, &bb_emlrtBCI, sp);
    }

    loop_ub = i0 - 1;
  }

  if (1 > mapB->mapCnt) {
    b_loop_ub = 0;
  } else {
    i0 = mapB->mapCnt;
    b_loop_ub = mapB->mapCnt;
    if (!(b_loop_ub <= i0)) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i0, &y_emlrtBCI, sp);
    }
  }

  for (i0 = 0; i0 < b_loop_ub; i0++) {
    tmp_data[i0] = i0;
  }

  mapLat[0] = 1;
  mapLat[1] = b_loop_ub;
  mapB_size[0] = 1;
  mapB_size[1] = (uint8_T)(loop_ub + 1);
  for (i0 = 0; i0 < 2; i0++) {
    b_mapB[i0] = mapB_size[i0];
  }

  emlrtSubAssignSizeCheckR2012b(mapLat, 2, b_mapB, 2, &k_emlrtECI, sp);
  for (i0 = 0; i0 <= loop_ub; i0++) {
    mapLat_data[tmp_data[i0]] = mapB->mapLat[i0];
  }

  if (1 > mapB->mapCnt) {
    loop_ub = -1;
  } else {
    i0 = mapB->mapCnt;
    if (!(i0 <= 100)) {
      emlrtDynamicBoundsCheckR2012b(i0, 1, 100, &ab_emlrtBCI, sp);
    }

    loop_ub = i0 - 1;
  }

  if (1 > mapB->mapCnt) {
    b_loop_ub = 0;
  } else {
    i0 = mapB->mapCnt;
    b_loop_ub = mapB->mapCnt;
    if (!(b_loop_ub <= i0)) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i0, &w_emlrtBCI, sp);
    }
  }

  for (i0 = 0; i0 < b_loop_ub; i0++) {
    tmp_data[i0] = i0;
  }

  iv0[0] = 1;
  iv0[1] = b_loop_ub;
  b_mapB_size[0] = 1;
  b_mapB_size[1] = (uint8_T)(loop_ub + 1);
  for (i0 = 0; i0 < 2; i0++) {
    b_mapB[i0] = b_mapB_size[i0];
  }

  emlrtSubAssignSizeCheckR2012b(iv0, 2, b_mapB, 2, &j_emlrtECI, sp);
  for (i0 = 0; i0 <= loop_ub; i0++) {
    mapLon_data[tmp_data[i0]] = mapB->mapLon[i0];
  }

  if (1 > mapB->mapCnt) {
    loop_ub = -1;
  } else {
    i0 = mapB->mapCnt;
    b_loop_ub = mapB->mapCnt;
    if (!(b_loop_ub <= i0)) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i0, &x_emlrtBCI, sp);
    }

    loop_ub = b_loop_ub - 1;
  }

  b_loop_ub = mapB->mapCnt;
  for (i0 = 0; i0 < b_loop_ub; i0++) {
    tmp_data[i0] = i0;
  }

  iv1[0] = 1;
  iv1[1] = mapB->mapCnt;
  mapLat_size[0] = 1;
  mapLat_size[1] = (uint8_T)(loop_ub + 1);
  for (i0 = 0; i0 < 2; i0++) {
    mapLat[i0] = mapLat_size[i0];
  }

  emlrtSubAssignSizeCheckR2012b(iv1, 2, mapLat, 2, &i_emlrtECI, sp);
  for (i0 = 0; i0 <= loop_ub; i0++) {
    Points_data[tmp_data[i0] << 1] = mapLat_data[i0];
  }

  if (1 > mapB->mapCnt) {
    loop_ub = -1;
  } else {
    i0 = mapB->mapCnt;
    b_loop_ub = mapB->mapCnt;
    if (!(b_loop_ub <= i0)) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i0, &v_emlrtBCI, sp);
    }

    loop_ub = b_loop_ub - 1;
  }

  b_loop_ub = mapB->mapCnt;
  for (i0 = 0; i0 < b_loop_ub; i0++) {
    tmp_data[i0] = i0;
  }

  iv2[0] = 1;
  iv2[1] = mapB->mapCnt;
  mapLon_size[0] = 1;
  mapLon_size[1] = (uint8_T)(loop_ub + 1);
  for (i0 = 0; i0 < 2; i0++) {
    mapLat[i0] = mapLon_size[i0];
  }

  emlrtSubAssignSizeCheckR2012b(iv2, 2, mapLat, 2, &h_emlrtECI, sp);
  for (i0 = 0; i0 <= loop_ub; i0++) {
    Points_data[1 + (tmp_data[i0] << 1)] = mapLon_data[i0];
  }

  Monolateral = lineM->Monolateral;
  L0 = params->L0;

  /* % 预处理 */
  /* %进行转平面直角操作，并转变成两列坐标 */
  i0 = mapB->mapCnt;
  if (!(1 <= i0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, &u_emlrtBCI, sp);
  }

  i0 = mapB->mapCnt;
  if (!(1 <= i0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, &t_emlrtBCI, sp);
  }

  f_Warning0 = 0;
  if (params->mapFlag == 1) {
    /* 1为经纬度坐标，0为平面坐标 */
    /* 算法2 */
    i = 1;
    while (i - 1 <= mapB->mapCnt - 1) {
      i0 = mapB->mapCnt;
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, &fb_emlrtBCI, sp);
      }

      i0 = mapB->mapCnt;
      if (!((i >= 1) && (i <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i0, &gb_emlrtBCI, sp);
      }

      if (!((i >= 1) && (i <= Points_size_idx_1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, Points_size_idx_1, &hb_emlrtBCI, sp);
      }

      st.site = &h_emlrtRSI;
      BL2XY_q(&st, mapLat_data[i - 1], mapLon_data[i - 1], L0, &Points_data[(i -
               1) << 1], &d0);
      if (!((i >= 1) && (i <= Points_size_idx_1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, Points_size_idx_1, &ib_emlrtBCI, sp);
      }

      Points_data[1 + ((i - 1) << 1)] = d0;
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  }

  /* % */
  /* 除重和删除同一点操作 */
  if (1 > mapB->mapCnt) {
    loop_ub = 0;
  } else {
    i0 = mapB->mapCnt;
    loop_ub = mapB->mapCnt;
    if (!(loop_ub <= i0)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i0, &s_emlrtBCI, sp);
    }
  }

  if (1 > mapB->mapCnt) {
    b_loop_ub = 0;
  } else {
    i0 = mapB->mapCnt;
    b_loop_ub = mapB->mapCnt;
    if (!(b_loop_ub <= i0)) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i0, &q_emlrtBCI, sp);
    }
  }

  for (i0 = 0; i0 < b_loop_ub; i0++) {
    tmp_data[i0] = i0;
  }

  tmp_size[0] = loop_ub;
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_tmp_data[i0] = Points_data[i0 << 1];
  }

  iv3[0] = b_loop_ub;
  emlrtSubAssignSizeCheckR2012b(iv3, 1, tmp_size, 1, &g_emlrtECI, sp);
  for (i0 = 0; i0 < loop_ub; i0++) {
    PreprocessingData_data[tmp_data[i0]] = b_tmp_data[i0];
  }

  if (1 > mapB->mapCnt) {
    loop_ub = 0;
  } else {
    i0 = mapB->mapCnt;
    loop_ub = mapB->mapCnt;
    if (!(loop_ub <= i0)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i0, &r_emlrtBCI, sp);
    }
  }

  if (1 > mapB->mapCnt) {
    b_loop_ub = 0;
  } else {
    i0 = mapB->mapCnt;
    b_loop_ub = mapB->mapCnt;
    if (!(b_loop_ub <= i0)) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i0, &p_emlrtBCI, sp);
    }
  }

  for (i0 = 0; i0 < b_loop_ub; i0++) {
    tmp_data[i0] = i0;
  }

  tmp_size[0] = loop_ub;
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_tmp_data[i0] = Points_data[1 + (i0 << 1)];
  }

  iv4[0] = b_loop_ub;
  emlrtSubAssignSizeCheckR2012b(iv4, 1, tmp_size, 1, &f_emlrtECI, sp);
  for (i0 = 0; i0 < loop_ub; i0++) {
    PreprocessingData_data[tmp_data[i0] + PreprocessingData_size_idx_0] =
      b_tmp_data[i0];
  }

  /* 错误标志位 */
  if (1 > mapB->mapCnt) {
    loop_ub = 0;
  } else {
    i0 = mapB->mapCnt;
    loop_ub = mapB->mapCnt;
    if (!(loop_ub <= i0)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i0, &o_emlrtBCI, sp);
    }
  }

  PreprocessingData_size[0] = loop_ub;
  PreprocessingData_size[1] = 2;
  for (i0 = 0; i0 < 2; i0++) {
    for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
      b_PreprocessingData_data[b_loop_ub + loop_ub * i0] =
        PreprocessingData_data[b_loop_ub + PreprocessingData_size_idx_0 * i0];
    }
  }

  st.site = &g_emlrtRSI;
  Preprocess(&st, b_PreprocessingData_data, PreprocessingData_size, mapB->mapCnt,
             Prep_Preprocessing, &Prep_Cnt);
  if (Prep_Cnt >= 3.0) {
    i0 = (int32_T)Prep_Cnt;
    if (!((i0 >= 1) && (i0 <= 100))) {
      emlrtDynamicBoundsCheckR2012b(i0, 1, 100, &n_emlrtBCI, sp);
    }

    i0 = mapB->mapCnt;
    if (!(1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &m_emlrtBCI, sp);
    }

    i0 = mapB->mapCnt;
    b_loop_ub = (int32_T)Prep_Cnt;
    if (!((b_loop_ub >= 1) && (b_loop_ub <= i0))) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i0, &m_emlrtBCI, sp);
    }

    loop_ub = (int32_T)Prep_Cnt;
    for (i0 = 0; i0 < loop_ub; i0++) {
      tmp_data[i0] = i0;
    }

    iv5[0] = (int32_T)Prep_Cnt;
    iv5[1] = 2;
    Prep_Preprocessing_size[0] = (int32_T)Prep_Cnt;
    Prep_Preprocessing_size[1] = 2;
    for (i0 = 0; i0 < 2; i0++) {
      mapLat[i0] = Prep_Preprocessing_size[i0];
    }

    emlrtSubAssignSizeCheckR2012b(iv5, 2, mapLat, 2, &e_emlrtECI, sp);
    for (i0 = 0; i0 < 2; i0++) {
      loop_ub = (int32_T)Prep_Cnt;
      for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
        PreprocessingData_data[tmp_data[b_loop_ub] +
          PreprocessingData_size_idx_0 * i0] = Prep_Preprocessing[b_loop_ub +
          100 * i0];
      }
    }

    /* % */
    /* 判断顺逆时针并处理 */
    /* 顺逆时针标志位，0：逆时针，1：顺时针 */
    i0 = mapB->mapCnt;
    if (!(1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &l_emlrtBCI, sp);
    }

    i0 = mapB->mapCnt;
    b_loop_ub = (int32_T)Prep_Cnt;
    if (!((b_loop_ub >= 1) && (b_loop_ub <= i0))) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i0, &l_emlrtBCI, sp);
    }

    i0 = mapB->mapCnt;
    if (!(1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &k_emlrtBCI, sp);
    }

    i0 = mapB->mapCnt;
    b_loop_ub = (int32_T)Prep_Cnt;
    if (!((b_loop_ub >= 1) && (b_loop_ub <= i0))) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i0, &k_emlrtBCI, sp);
    }

    b_PreprocessingData_size[0] = (int32_T)Prep_Cnt;
    loop_ub = (int32_T)Prep_Cnt;
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_PreprocessingData_data[i0] = PreprocessingData_data[i0];
    }

    c_PreprocessingData_size[0] = (int32_T)Prep_Cnt;
    loop_ub = (int32_T)Prep_Cnt;
    for (i0 = 0; i0 < loop_ub; i0++) {
      d_PreprocessingData_data[i0] = PreprocessingData_data[i0 +
        PreprocessingData_size_idx_0];
    }

    e_PreprocessingData_data.data = (real_T *)&c_PreprocessingData_data;
    e_PreprocessingData_data.size = (int32_T *)&b_PreprocessingData_size;
    e_PreprocessingData_data.allocatedSize = 255;
    e_PreprocessingData_data.numDimensions = 1;
    e_PreprocessingData_data.canFreeData = false;
    f_PreprocessingData_data.data = (real_T *)&d_PreprocessingData_data;
    f_PreprocessingData_data.size = (int32_T *)&c_PreprocessingData_size;
    f_PreprocessingData_data.allocatedSize = 255;
    f_PreprocessingData_data.numDimensions = 1;
    f_PreprocessingData_data.canFreeData = false;
    st.site = &f_emlrtRSI;
    FFLOG = judgeClockWise(&st, &e_PreprocessingData_data,
      &f_PreprocessingData_data, Prep_Cnt);
    if (FFLOG == 0.0) {
      i0 = mapB->mapCnt;
      if (!(1 <= i0)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i0, &j_emlrtBCI, sp);
      }

      i0 = mapB->mapCnt;
      b_loop_ub = (int32_T)Prep_Cnt;
      if (!((b_loop_ub >= 1) && (b_loop_ub <= i0))) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i0, &j_emlrtBCI, sp);
      }

      i0 = mapB->mapCnt;
      if (!(1 <= i0)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i0, &i_emlrtBCI, sp);
      }

      i0 = mapB->mapCnt;
      b_loop_ub = (int32_T)Prep_Cnt;
      if (!((b_loop_ub >= 1) && (b_loop_ub <= i0))) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i0, &i_emlrtBCI, sp);
      }

      loop_ub = (int32_T)Prep_Cnt;
      for (i0 = 0; i0 < loop_ub; i0++) {
        tmp_data[i0] = i0;
      }

      PointOut_size[0] = (int32_T)Prep_Cnt;
      PointOut_size[1] = 2;
      for (i0 = 0; i0 < 2; i0++) {
        loop_ub = (int32_T)Prep_Cnt;
        for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
          PointOut_data[b_loop_ub + (int32_T)Prep_Cnt * i0] =
            PreprocessingData_data[b_loop_ub + PreprocessingData_size_idx_0 * i0];
        }
      }

      flipud(PointOut_data, PointOut_size);
      iv6[0] = (int32_T)Prep_Cnt;
      iv6[1] = 2;
      emlrtSubAssignSizeCheckR2012b(iv6, 2, PointOut_size, 2, &d_emlrtECI, sp);
      for (i0 = 0; i0 < 2; i0++) {
        loop_ub = PointOut_size[0];
        for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
          PreprocessingData_data[tmp_data[b_loop_ub] +
            PreprocessingData_size_idx_0 * i0] = PointOut_data[b_loop_ub +
            PointOut_size[0] * i0];
        }
      }

      Monolateral = (int32_T)Prep_Cnt - lineM->Monolateral;
      Clock_Flag = 0;
    } else {
      i0 = mapB->mapCnt;
      if (!(1 <= i0)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i0, &h_emlrtBCI, sp);
      }

      i0 = mapB->mapCnt;
      b_loop_ub = (int32_T)Prep_Cnt;
      if (!((b_loop_ub >= 1) && (b_loop_ub <= i0))) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i0, &h_emlrtBCI, sp);
      }

      i0 = mapB->mapCnt;
      if (!(1 <= i0)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i0, &g_emlrtBCI, sp);
      }

      i0 = mapB->mapCnt;
      b_loop_ub = (int32_T)Prep_Cnt;
      if (!((b_loop_ub >= 1) && (b_loop_ub <= i0))) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i0, &g_emlrtBCI, sp);
      }

      loop_ub = (int32_T)Prep_Cnt;
      for (i0 = 0; i0 < loop_ub; i0++) {
        tmp_data[i0] = i0;
      }

      iv6[0] = (int32_T)Prep_Cnt;
      iv6[1] = 2;
      d_PreprocessingData_size[0] = (int32_T)Prep_Cnt;
      d_PreprocessingData_size[1] = 2;
      for (i0 = 0; i0 < 2; i0++) {
        mapLat[i0] = d_PreprocessingData_size[i0];
      }

      emlrtSubAssignSizeCheckR2012b(iv6, 2, mapLat, 2, &c_emlrtECI, sp);
      for (i0 = 0; i0 < 2; i0++) {
        loop_ub = (int32_T)Prep_Cnt;
        for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
          b_PreprocessingData_data[b_loop_ub + (int32_T)Prep_Cnt * i0] =
            PreprocessingData_data[b_loop_ub + PreprocessingData_size_idx_0 * i0];
        }
      }

      for (i0 = 0; i0 < 2; i0++) {
        loop_ub = (int32_T)Prep_Cnt;
        for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
          PreprocessingData_data[tmp_data[b_loop_ub] +
            PreprocessingData_size_idx_0 * i0] =
            b_PreprocessingData_data[b_loop_ub + (int32_T)Prep_Cnt * i0];
        }
      }

      /* PreprocessingCnt(1,1) = PreprocessingCnt(1,1); */
      Clock_Flag = 1;
    }

    /* % 判断边界线相交,则退出算法 */
    /* 交点个数 */
    i0 = mapB->mapCnt;
    if (!(1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &f_emlrtBCI, sp);
    }

    i0 = mapB->mapCnt;
    b_loop_ub = (int32_T)Prep_Cnt;
    if (!((b_loop_ub >= 1) && (b_loop_ub <= i0))) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i0, &f_emlrtBCI, sp);
    }

    e_PreprocessingData_size[0] = (int32_T)Prep_Cnt;
    e_PreprocessingData_size[1] = 2;
    for (i0 = 0; i0 < 2; i0++) {
      loop_ub = (int32_T)Prep_Cnt;
      for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
        b_PreprocessingData_data[b_loop_ub + (int32_T)Prep_Cnt * i0] =
          PreprocessingData_data[b_loop_ub + PreprocessingData_size_idx_0 * i0];
      }
    }

    st.site = &d_emlrtRSI;
    c_Calculate_New_Indented_Bounda(&st, b_PreprocessingData_data,
      e_PreprocessingData_size, Prep_Cnt, dv1, &d0, dv0, &P_Cnt);
    if (d0 != 0.0) {
      /* 若此处为1，则程序应停止继续数据处理 */
      out->error = -1;
    } else {
      /* % 调用功能函数 */
      /* 经单边操作（内部已经进行了去除无效环和把点变成顺时针的形式） */
      i0 = mapB->mapCnt;
      if (!(1 <= i0)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i0, &e_emlrtBCI, sp);
      }

      i0 = mapB->mapCnt;
      b_loop_ub = (int32_T)Prep_Cnt;
      if (!((b_loop_ub >= 1) && (b_loop_ub <= i0))) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i0, &e_emlrtBCI, sp);
      }

      PointOut_size[0] = (int32_T)Prep_Cnt;
      for (i0 = 0; i0 < 2; i0++) {
        loop_ub = (int32_T)Prep_Cnt;
        for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
          PointOut_data[b_loop_ub + (int32_T)Prep_Cnt * i0] =
            PreprocessingData_data[b_loop_ub + PreprocessingData_size_idx_0 * i0];
        }
      }

      b_P_Cnt = Prep_Cnt;
      f_Warning1 = 0.0;
      f_Warning2 = 0.0;

      /*  */
      /* 单边移动 */
      if (lineM->Monolateral_L != 0.0) {
        i0 = mapB->mapCnt;
        if (!(1 <= i0)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i0, &d_emlrtBCI, sp);
        }

        i0 = mapB->mapCnt;
        b_loop_ub = (int32_T)Prep_Cnt;
        if (!((b_loop_ub >= 1) && (b_loop_ub <= i0))) {
          emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i0, &d_emlrtBCI, sp);
        }

        f_PreprocessingData_size[0] = (int32_T)Prep_Cnt;
        f_PreprocessingData_size[1] = 2;
        for (i0 = 0; i0 < 2; i0++) {
          loop_ub = (int32_T)Prep_Cnt;
          for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
            b_PreprocessingData_data[b_loop_ub + (int32_T)Prep_Cnt * i0] =
              PreprocessingData_data[b_loop_ub + PreprocessingData_size_idx_0 *
              i0];
          }
        }

        st.site = &c_emlrtRSI;
        Calculate_Monolateral_Points(&st, b_PreprocessingData_data,
          f_PreprocessingData_size, Prep_Cnt, Monolateral, lineM->Monolateral_L,
          lineM->Monolateral_flag, Clock_Flag, PointOut, &b_P_Cnt, &f_Warning1);
        PointOut_size[0] = 100;
        memcpy(&PointOut_data[0], &PointOut[0], 200U * sizeof(real_T));

        /* 但不可把某个便便给缩没了 */
      }

      /* 整体进行内缩外扩运算 */
      if (mapB->L != 0.0) {
        if (1.0 > b_P_Cnt) {
          loop_ub = 0;
        } else {
          if (b_P_Cnt != (int32_T)muDoubleScalarFloor(b_P_Cnt)) {
            emlrtIntegerCheckR2012b(b_P_Cnt, &e_emlrtDCI, sp);
          }

          loop_ub = (int32_T)b_P_Cnt;
          if (!((loop_ub >= 1) && (loop_ub <= PointOut_size[0]))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, PointOut_size[0],
              &c_emlrtBCI, sp);
          }
        }

        b_PointOut_size[0] = loop_ub;
        b_PointOut_size[1] = 2;
        for (i0 = 0; i0 < 2; i0++) {
          for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
            b_PreprocessingData_data[b_loop_ub + loop_ub * i0] =
              PointOut_data[b_loop_ub + PointOut_size[0] * i0];
          }
        }

        st.site = &b_emlrtRSI;
        Calculate_Map_Points(&st, b_PreprocessingData_data, b_PointOut_size,
                             b_P_Cnt, mapB->L, mapB->flag, params->Theita,
                             Clock_Flag, PointOut, &P_Cnt, &f_Warning2);
        PointOut_size[0] = 100;
        memcpy(&PointOut_data[0], &PointOut[0], 200U * sizeof(real_T));
        b_P_Cnt = P_Cnt;
      }

      /* % 画图 */
      /* % 平面转经纬度 */
      d0 = muDoubleScalarRound(b_P_Cnt);
      if (d0 < 256.0) {
        if (d0 >= 0.0) {
          u0 = (uint8_T)d0;
        } else {
          u0 = 0;
        }
      } else if (d0 >= 256.0) {
        u0 = MAX_uint8_T;
      } else {
        u0 = 0;
      }

      mapOut->mapCnt = u0;
      if (params->mapFlag == 0) {
        /* 1为经纬度坐标，0为平面坐标 */
        if (1.0 > b_P_Cnt) {
          loop_ub = 0;
        } else {
          if (b_P_Cnt != (int32_T)muDoubleScalarFloor(b_P_Cnt)) {
            emlrtIntegerCheckR2012b(b_P_Cnt, &d_emlrtDCI, sp);
          }

          loop_ub = (int32_T)b_P_Cnt;
          if (!((loop_ub >= 1) && (loop_ub <= PointOut_size[0]))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, PointOut_size[0],
              &b_emlrtBCI, sp);
          }
        }

        if (1.0 > b_P_Cnt) {
          b_loop_ub = 0;
        } else {
          if (b_P_Cnt != (int32_T)muDoubleScalarFloor(b_P_Cnt)) {
            emlrtIntegerCheckR2012b(b_P_Cnt, &b_emlrtDCI, sp);
          }

          b_loop_ub = (int32_T)b_P_Cnt;
        }

        for (i0 = 0; i0 < b_loop_ub; i0++) {
          c_tmp_data[i0] = i0;
        }

        b_mapLat_size[0] = 1;
        b_mapLat_size[1] = loop_ub;
        for (i0 = 0; i0 < loop_ub; i0++) {
          mapLat_data[i0] = PointOut_data[i0];
        }

        iv7[0] = 1;
        iv7[1] = b_loop_ub;
        emlrtSubAssignSizeCheckR2012b(iv7, 2, b_mapLat_size, 2, &b_emlrtECI, sp);
        for (i0 = 0; i0 < loop_ub; i0++) {
          mapOut->mapLat[c_tmp_data[i0]] = mapLat_data[i0];
        }

        if (1.0 > b_P_Cnt) {
          loop_ub = 0;
        } else {
          if (b_P_Cnt != (int32_T)muDoubleScalarFloor(b_P_Cnt)) {
            emlrtIntegerCheckR2012b(b_P_Cnt, &c_emlrtDCI, sp);
          }

          loop_ub = (int32_T)b_P_Cnt;
          if (!((loop_ub >= 1) && (loop_ub <= PointOut_size[0]))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, PointOut_size[0],
              &emlrtBCI, sp);
          }
        }

        if (1.0 > b_P_Cnt) {
          b_loop_ub = 0;
        } else {
          if (b_P_Cnt != (int32_T)muDoubleScalarFloor(b_P_Cnt)) {
            emlrtIntegerCheckR2012b(b_P_Cnt, &emlrtDCI, sp);
          }

          b_loop_ub = (int32_T)b_P_Cnt;
        }

        for (i0 = 0; i0 < b_loop_ub; i0++) {
          c_tmp_data[i0] = i0;
        }

        b_mapLat_size[0] = 1;
        b_mapLat_size[1] = loop_ub;
        for (i0 = 0; i0 < loop_ub; i0++) {
          mapLat_data[i0] = PointOut_data[i0 + PointOut_size[0]];
        }

        iv8[0] = 1;
        iv8[1] = b_loop_ub;
        emlrtSubAssignSizeCheckR2012b(iv8, 2, b_mapLat_size, 2, &emlrtECI, sp);
        for (i0 = 0; i0 < loop_ub; i0++) {
          mapOut->mapLon[c_tmp_data[i0]] = mapLat_data[i0];
        }
      } else if (params->mapFlag == 1) {
        i = 1;
        while (i - 1 <= mapOut->mapCnt - 1) {
          if (!((i >= 1) && (i <= PointOut_size[0]))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, PointOut_size[0], &cb_emlrtBCI,
              sp);
          }

          if (!((i >= 1) && (i <= PointOut_size[0]))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, PointOut_size[0], &db_emlrtBCI,
              sp);
          }

          if (!((i >= 1) && (i <= 100))) {
            emlrtDynamicBoundsCheckR2012b(i, 1, 100, &eb_emlrtBCI, sp);
          }

          st.site = &emlrtRSI;
          XY2BL(&st, PointOut_data[i - 1], PointOut_data[(i + PointOut_size[0])
                - 1], L0, &mapOut->mapLat[i - 1], &mapOut->mapLon[i - 1]);
          i++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }
      } else {
        f_Warning0 = 1;

        /* 警告标志位 */
      }

      /* % 输出赋值 */
      out->error = 0;
      if ((f_Warning0 != 0) || (f_Warning1 != 0.0) || (f_Warning2 == 1.0)) {
        out->warn = 1;
      }
    }
  } else {
    /* 若此处为1，则程序应停止继续数据处理 */
    out->error = -1;
  }
}

/* End of code generation (AgriMapZoomInterface.c) */
