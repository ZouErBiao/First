/*
 * Calculate_Effective_Point.c
 *
 * Code generation for function 'Calculate_Effective_Point'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "Calculate_Effective_Point.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "Calculate_Area.h"
#include "judgeClockWise.h"
#include "sum.h"
#include "indexShapeCheck.h"
#include "CalculateIntersection.h"
#include "Sort2.h"
#include "Calculate_New_Indented_Boundary_Point.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRSInfo tb_emlrtRSI = { 149, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRSInfo ub_emlrtRSI = { 143, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRSInfo vb_emlrtRSI = { 137, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRSInfo wb_emlrtRSI = { 132, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRSInfo xb_emlrtRSI = { 131, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRSInfo yb_emlrtRSI = { 126, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRSInfo ac_emlrtRSI = { 122, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRSInfo bc_emlrtRSI = { 92, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRSInfo cc_emlrtRSI = { 54, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRSInfo dc_emlrtRSI = { 53, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRSInfo ec_emlrtRSI = { 21, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRSInfo fc_emlrtRSI = { 17, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRSInfo gc_emlrtRSI = { 16, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRSInfo mc_emlrtRSI = { 234, "find",
  "F:\\MatlabInstall\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" };

static emlrtRSInfo yc_emlrtRSI = { 38, "ismember",
  "F:\\MatlabInstall\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" };

static emlrtRSInfo ad_emlrtRSI = { 68, "ismember",
  "F:\\MatlabInstall\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m" };

static emlrtRSInfo ed_emlrtRSI = { 18, "max",
  "F:\\MatlabInstall\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" };

static emlrtRSInfo fd_emlrtRSI = { 15, "minOrMax",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo gd_emlrtRSI = { 97, "minOrMax",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo hd_emlrtRSI = { 308, "minOrMax",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRSInfo id_emlrtRSI = { 281, "minOrMax",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRTEInfo n_emlrtRTEI = { 1, 29, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRTEInfo p_emlrtRTEI = { 28, 1, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRTEInfo q_emlrtRTEI = { 29, 1, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRTEInfo r_emlrtRTEI = { 33, 1, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRTEInfo s_emlrtRTEI = { 39, 1, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRTEInfo t_emlrtRTEI = { 54, 13, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtRTEInfo u_emlrtRTEI = { 111, 1, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtBCInfo kh_emlrtBCI = { -1, -1, 151, 28, "Aera",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtECInfo w_emlrtECI = { -1, 150, 9, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtBCInfo lh_emlrtBCI = { 1, 100, 150, 17, "YouXiao",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtDCInfo p_emlrtDCI = { 150, 17, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m", 1 };

static emlrtBCInfo mh_emlrtBCI = { -1, -1, 150, 24, "Aera",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo nh_emlrtBCI = { -1, -1, 150, 74, "Aera",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo oh_emlrtBCI = { -1, -1, 149, 27, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtDCInfo q_emlrtDCI = { 149, 27, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m", 1 };

static emlrtBCInfo ph_emlrtBCI = { -1, -1, 149, 34, "Aera",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo qh_emlrtBCI = { -1, -1, 147, 28, "Aera",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtECInfo x_emlrtECI = { -1, 146, 9, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtBCInfo rh_emlrtBCI = { 1, 100, 146, 17, "YouXiao",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtDCInfo r_emlrtDCI = { 146, 17, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m", 1 };

static emlrtBCInfo sh_emlrtBCI = { -1, -1, 146, 24, "Aera",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo th_emlrtBCI = { -1, -1, 146, 51, "newPolygonList",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtDCInfo s_emlrtDCI = { 146, 51, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m", 1 };

static emlrtBCInfo uh_emlrtBCI = { -1, -1, 146, 58, "Aera",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo vh_emlrtBCI = { -1, -1, 145, 13, "Aera",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo wh_emlrtBCI = { -1, -1, 144, 10, "Aera",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo xh_emlrtBCI = { -1, -1, 144, 24, "Aera",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo yh_emlrtBCI = { -1, -1, 137, 22, "Aera",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo ai_emlrtBCI = { -1, -1, 126, 22, "Aera",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo bi_emlrtBCI = { 1, 100, 137, 65, "YouXiao",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo ci_emlrtBCI = { -1, -1, 137, 67, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtECInfo y_emlrtECI = { -1, 134, 17, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtBCInfo di_emlrtBCI = { 1, 100, 134, 25, "YouXiao",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo ei_emlrtBCI = { -1, -1, 134, 27, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo fi_emlrtBCI = { -1, -1, 131, 27, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo gi_emlrtBCI = { -1, -1, 126, 87, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo hi_emlrtBCI = { -1, -1, 126, 79, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo ii_emlrtBCI = { 1, 100, 126, 65, "YouXiao",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo ji_emlrtBCI = { -1, -1, 126, 67, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtECInfo ab_emlrtECI = { -1, 124, 17, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtBCInfo ki_emlrtBCI = { 1, 100, 124, 25, "YouXiao",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo li_emlrtBCI = { -1, -1, 124, 27, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtECInfo bb_emlrtECI = { -1, 117, 5, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtBCInfo mi_emlrtBCI = { 1, 100, 117, 13, "YouXiao",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo ni_emlrtBCI = { -1, -1, 124, 56, "newPolygonList",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo oi_emlrtBCI = { -1, -1, 124, 58, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo pi_emlrtBCI = { -1, -1, 122, 96, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo qi_emlrtBCI = { -1, -1, 122, 84, "newPolygonList",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo ri_emlrtBCI = { -1, -1, 122, 86, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo si_emlrtBCI = { -1, -1, 122, 57, "newPolygonList",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo ti_emlrtBCI = { -1, -1, 122, 59, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtRTEInfo wb_emlrtRTEI = { 120, 5, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtBCInfo ui_emlrtBCI = { -1, -1, 117, 48, "newPolygonList",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtECInfo cb_emlrtECI = { -1, 86, 17, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtBCInfo vi_emlrtBCI = { -1, -1, 98, 34, "newPolygonListPP",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo wi_emlrtBCI = { 1, 100, 98, 53, "PolygonList",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo xi_emlrtBCI = { 1, 100, 92, 39, "PolygonList",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo yi_emlrtBCI = { -1, -1, 86, 91, "newPolygonListPP",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo aj_emlrtBCI = { -1, -1, 78, 34, "newPolygonListPP",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo bj_emlrtBCI = { -1, -1, 75, 98, "newPolygonListPP",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo cj_emlrtBCI = { -1, -1, 75, 53, "newPolygonListPP",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo dj_emlrtBCI = { -1, -1, 72, 24, "mm",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtRTEInfo xb_emlrtRTEI = { 61, 21, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtBCInfo ej_emlrtBCI = { -1, -1, 54, 27, "row",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtECInfo db_emlrtECI = { -1, 53, 13, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m" };

static emlrtBCInfo fj_emlrtBCI = { -1, -1, 53, 17, "row",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo gj_emlrtBCI = { 1, 100, 53, 52, "PolygonList",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo hj_emlrtBCI = { -1, -1, 51, 30, "newPolygonListPP",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo ij_emlrtBCI = { -1, -1, 46, 118, "newPolygonListPP",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo jj_emlrtBCI = { -1, -1, 46, 73, "newPolygonListPP",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo kj_emlrtBCI = { -1, -1, 35, 18, "newPolygonListPP",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo lj_emlrtBCI = { 1, 50, 21, 97, "PP",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo mj_emlrtBCI = { 1, 100, 21, 61, "PPP",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo nj_emlrtBCI = { -1, -1, 16, 105, "PointLast",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtRTEInfo ac_emlrtRTEI = { 38, 19, "minOrMax",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtRTEInfo bc_emlrtRTEI = { 81, 19, "minOrMax",
  "F:\\MatlabInstall\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m" };

static emlrtBCInfo oj_emlrtBCI = { 1, 100, 46, 24, "PolygonList",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo pj_emlrtBCI = { -1, -1, 84, 21, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo qj_emlrtBCI = { -1, -1, 86, 32, "newPolygonList",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo rj_emlrtBCI = { 1, 50, 98, 55, "b",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo sj_emlrtBCI = { 1, 100, 99, 29, "PolygonList",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo tj_emlrtBCI = { 1, 50, 99, 31, "b",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo uj_emlrtBCI = { 1, 50, 101, 23, "b",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo vj_emlrtBCI = { 1, 50, 48, 15, "b",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo wj_emlrtBCI = { 1, 100, 62, 43, "PolygonList",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo xj_emlrtBCI = { -1, -1, 150, 51, "newPolygonList",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtDCInfo t_emlrtDCI = { 150, 51, "Calculate_Effective_Point",
  "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m", 1 };

static emlrtBCInfo yj_emlrtBCI = { -1, -1, 132, 75, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo ak_emlrtBCI = { -1, -1, 132, 57, "newPolygonList",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo bk_emlrtBCI = { -1, -1, 132, 118, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo ck_emlrtBCI = { -1, -1, 132, 100, "newPolygonList",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo dk_emlrtBCI = { -1, -1, 132, 128, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo ek_emlrtBCI = { -1, -1, 134, 74, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo fk_emlrtBCI = { -1, -1, 134, 56, "newPolygonList",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo gk_emlrtBCI = { -1, -1, 137, 79, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

static emlrtBCInfo hk_emlrtBCI = { -1, -1, 137, 87, "ccc",
  "Calculate_Effective_Point", "D:\\2.AgriMapZoom\\Calculate_Effective_Point.m",
  0 };

/* Function Definitions */
void Calculate_Effective_Point(const emlrtStack *sp, const real_T
  PointLast_data[], const int32_T PointLast_size[2], real_T N, real_T YouXiao
  [200], real_T *YX_Cnt)
{
  int32_T loop_ub;
  real_T b_PointLast_data[510];
  int32_T b_PointLast_size[2];
  int32_T i18;
  int32_T idx;
  real_T d1;
  real_T PPP[700];
  real_T d2;
  real_T PP[350];
  int32_T nx;
  real_T PPP_data[700];
  int32_T PPP_size[2];
  real_T PP_data[350];
  int32_T PP_size[2];
  real_T n;
  real_T PolygonList[700];
  int8_T b[50];
  int32_T i;
  real_T C_Cnt[4];
  emxArray_real_T *ccc;
  emxArray_real_T *newPolygonList;
  emxArray_real_T *newPolygonListPP;
  real_T b_i;
  real_T tt;
  real_T newPolygonnum;
  emxArray_real_T *row;
  emxArray_real_T *mm;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  emxArray_real_T *b_newPolygonListPP;
  int32_T exitg2;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  int32_T itmp;
  int32_T b_ii[2];
  int32_T c_ii;
  boolean_T exitg6;
  boolean_T guard6 = false;
  int32_T iv18[2];
  boolean_T tf_data[100];
  boolean_T overflow;
  boolean_T exitg5;
  real_T absxk;
  int32_T exponent;
  boolean_T p;
  int32_T tmp_size[1];
  int8_T tmp_data[100];
  int32_T d_ii[1];
  boolean_T exitg4;
  boolean_T guard5 = false;
  int32_T iv19[2];
  boolean_T exitg3;
  emxArray_real_T *Aera;
  uint32_T C_Aera;
  int32_T b_tmp_data[100];
  emxArray_real_T *b_newPolygonList;
  int32_T iv20[2];
  emxArray_real_T *r6;
  emxArray_real_T *c_newPolygonList;
  emxArray_real_T *d_newPolygonList;
  emxArray_real_T *b_ccc;
  emxArray_real_T *e_newPolygonList;
  emxArray_real_T *f_newPolygonList;
  emxArray_real_T *g_newPolygonList;
  emxArray_real_T *h_newPolygonList;
  real_T FFLOG0;
  int32_T iv21[2];
  real_T YouXiao_data[200];
  int32_T YouXiao_size[2];
  int32_T iv22[2];
  real_T ct;
  int32_T iv23[2];
  int32_T b_YouXiao_size[2];
  boolean_T b_guard1 = false;
  boolean_T exitg1;
  real_T b_Aera[3];
  emxArray_real_T *i_newPolygonList;
  emxArray_real_T *c_ccc;
  emxArray_real_T *j_newPolygonList;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* { */
  /* 对经过内缩后的点集进行去无效环处理 */
  /* 输入： */
  /* PointLast为经内缩后的点集，为多行两列的矩阵,顺时针排列的%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* 输出： */
  /* YouXiao为经过处理后的保留下来的有效环的点集，为多行两列的矩阵 */
  /* } */
  memset(&YouXiao[0], 0, 200U * sizeof(real_T));
  if (1.0 > N) {
    loop_ub = 0;
  } else {
    if (!(1 <= PointLast_size[0])) {
      emlrtDynamicBoundsCheckR2012b(1, 1, PointLast_size[0], &nj_emlrtBCI, sp);
    }

    loop_ub = (int32_T)N;
    if (!((loop_ub >= 1) && (loop_ub <= PointLast_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, PointLast_size[0], &nj_emlrtBCI,
        sp);
    }
  }

  b_PointLast_size[0] = loop_ub;
  b_PointLast_size[1] = 2;
  for (i18 = 0; i18 < 2; i18++) {
    for (idx = 0; idx < loop_ub; idx++) {
      b_PointLast_data[idx + loop_ub * i18] = PointLast_data[idx +
        PointLast_size[0] * i18];
    }
  }

  st.site = &gc_emlrtRSI;
  c_Calculate_New_Indented_Bounda(&st, b_PointLast_data, b_PointLast_size, N, PP,
    &d2, PPP, &d1);

  /* PPP为经过倒置、加列处理后的的七列顶点集，~为原顶点集倒置后的点集，PP为无序的交点集矩阵，也经过处理变成了七列的矩阵 */
  st.site = &fc_emlrtRSI;
  Sort(&st, PP, d2);

  /* 对交点进行小序号边的起点进行排序，方便插入原顶点集 */
  if (1.0 > d1) {
    loop_ub = 0;
  } else {
    loop_ub = (int32_T)d1;
    if (!((loop_ub >= 1) && (loop_ub <= 100))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 100, &mj_emlrtBCI, sp);
    }
  }

  if (1.0 > d2) {
    nx = 0;
  } else {
    nx = (int32_T)d2;
    if (!((nx >= 1) && (nx <= 50))) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, 50, &lj_emlrtBCI, sp);
    }
  }

  PPP_size[0] = loop_ub;
  PPP_size[1] = 7;
  PP_size[0] = nx;
  PP_size[1] = 7;
  for (i18 = 0; i18 < 7; i18++) {
    for (idx = 0; idx < loop_ub; idx++) {
      PPP_data[idx + loop_ub * i18] = PPP[idx + 100 * i18];
    }

    for (idx = 0; idx < nx; idx++) {
      PP_data[idx + nx * i18] = PP[idx + 50 * i18];
    }
  }

  st.site = &ec_emlrtRSI;
  CalculateIntersection(&st, PPP_data, PPP_size, d1, PP_data, PP_size, d2,
                        PolygonList, &n);

  /* 中和交点的顶点集 */
  /* [PolygonList(1:100,1:7),n(1,1)] = Preprocessing(PolygonList(1:n(1,1),1:7),n(1,1));%去除交点和原顶点相同的点 */
  /* 经切割后，简单多边形的个数 */
  for (i = 0; i < 50; i++) {
    b[i] = 0;
  }

  for (i18 = 0; i18 < 4; i18++) {
    C_Cnt[i18] = 0.0;
  }

  emxInit_real_T1(sp, &ccc, 1, &p_emlrtRTEI, true);

  /* 用于下标计数用 */
  i18 = ccc->size[0];
  ccc->size[0] = (int32_T)n;
  emxEnsureCapacity(sp, (emxArray__common *)ccc, i18, (int32_T)sizeof(real_T),
                    &n_emlrtRTEI);
  loop_ub = (int32_T)n;
  for (i18 = 0; i18 < loop_ub; i18++) {
    ccc->data[i18] = 0.0;
  }

  emxInit_real_T(sp, &newPolygonList, 2, &q_emlrtRTEI, true);
  i18 = newPolygonList->size[0] * newPolygonList->size[1];
  newPolygonList->size[0] = (int32_T)n;
  newPolygonList->size[1] = 7;
  emxEnsureCapacity(sp, (emxArray__common *)newPolygonList, i18, (int32_T)sizeof
                    (real_T), &n_emlrtRTEI);
  loop_ub = (int32_T)n * 7;
  for (i18 = 0; i18 < loop_ub; i18++) {
    newPolygonList->data[i18] = 0.0;
  }

  emxInit_real_T(sp, &newPolygonListPP, 2, &r_emlrtRTEI, true);
  b_i = 1.0;
  tt = 1.0;
  newPolygonnum = 1.0;
  i18 = newPolygonListPP->size[0] * newPolygonListPP->size[1];
  newPolygonListPP->size[0] = (int32_T)n;
  newPolygonListPP->size[1] = 7;
  emxEnsureCapacity(sp, (emxArray__common *)newPolygonListPP, i18, (int32_T)
                    sizeof(real_T), &n_emlrtRTEI);
  loop_ub = (int32_T)n * 7;
  for (i18 = 0; i18 < loop_ub; i18++) {
    newPolygonListPP->data[i18] = 0.0;
  }

  i18 = (int32_T)n;
  if (!(1 <= i18)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i18, &kj_emlrtBCI, sp);
  }

  for (i18 = 0; i18 < 7; i18++) {
    newPolygonListPP->data[newPolygonListPP->size[0] * i18] = PolygonList[100 *
      i18];
  }

  emxInit_real_T1(sp, &row, 1, &s_emlrtRTEI, true);

  /* 每个新环的存储矩阵 */
  C_Cnt[1] = 1.0;
  PolygonList[100] = 1.0;
  i18 = row->size[0];
  row->size[0] = (int32_T)n;
  emxEnsureCapacity(sp, (emxArray__common *)row, i18, (int32_T)sizeof(real_T),
                    &n_emlrtRTEI);
  loop_ub = (int32_T)n;
  for (i18 = 0; i18 < loop_ub; i18++) {
    row->data[i18] = 0.0;
  }

  /* 用于查找结果存储 */
  emxInit_real_T1(sp, &mm, 1, &t_emlrtRTEI, true);
  emxInit_boolean_T(sp, &x, 1, &n_emlrtRTEI, true);
  emxInit_int32_T(sp, &ii, 1, &v_emlrtRTEI, true);
  emxInit_real_T(sp, &b_newPolygonListPP, 2, &n_emlrtRTEI, true);
  do {
    exitg2 = 0;
    b_i++;

    /* %step4 */
    if (b_i == n + 1.0) {
      b_i = 1.0;
    }

    i18 = (int32_T)b_i;
    if (!((i18 >= 1) && (i18 <= 100))) {
      emlrtDynamicBoundsCheckR2012b(i18, 1, 100, &oj_emlrtBCI, sp);
    }

    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    if (PolygonList[i18 + 199] == 1.0) {
      i18 = newPolygonListPP->size[0];
      if (!(1 <= i18)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i18, &jj_emlrtBCI, sp);
      }

      if (PolygonList[(int32_T)b_i + 299] != newPolygonListPP->
          data[newPolygonListPP->size[0] * 3]) {
        guard3 = true;
      } else {
        i18 = newPolygonListPP->size[0];
        if (!(1 <= i18)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i18, &ij_emlrtBCI, sp);
        }

        if (PolygonList[(int32_T)b_i + 399] != newPolygonListPP->
            data[newPolygonListPP->size[0] << 2]) {
          guard3 = true;
        } else {
          guard4 = true;
        }
      }
    } else {
      guard4 = true;
    }

    if (guard4) {
      /* %Step6 */
      i18 = newPolygonListPP->size[0];
      if (!(1 <= i18)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i18, &cj_emlrtBCI, sp);
      }

      if (PolygonList[(int32_T)b_i + 299] != newPolygonListPP->
          data[newPolygonListPP->size[0] * 3]) {
        guard2 = true;
      } else {
        i18 = newPolygonListPP->size[0];
        if (!(1 <= i18)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i18, &bj_emlrtBCI, sp);
        }

        if ((PolygonList[(int32_T)b_i + 399] != newPolygonListPP->
             data[newPolygonListPP->size[0] << 2]) && (PolygonList[(int32_T)b_i
             + 99] == 0.0)) {
          guard2 = true;
        } else {
          PolygonList[(int32_T)b_i + 99] = 1.0;
          C_Cnt[2]++;
          i18 = ccc->size[0];
          idx = (int32_T)C_Cnt[2];
          if (!((idx >= 1) && (idx <= i18))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, i18, &pj_emlrtBCI, sp);
          }

          ccc->data[idx - 1] = C_Cnt[1];

          /* 存储每个环的顶点数 */
          i18 = newPolygonListPP->size[0];
          if (!(1 <= i18)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i18, &yi_emlrtBCI, sp);
          }

          i18 = newPolygonListPP->size[0];
          idx = (int32_T)C_Cnt[1];
          if (!((idx >= 1) && (idx <= i18))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, i18, &yi_emlrtBCI, sp);
          }

          itmp = newPolygonList->size[0];
          i18 = ii->size[0];
          ii->size[0] = (int32_T)(C_Cnt[1] - 1.0) + 1;
          emxEnsureCapacity(sp, (emxArray__common *)ii, i18, (int32_T)sizeof
                            (int32_T), &n_emlrtRTEI);
          loop_ub = (int32_T)(C_Cnt[1] - 1.0);
          for (i18 = 0; i18 <= loop_ub; i18++) {
            idx = (int32_T)(C_Cnt[3] + (1.0 + (real_T)i18));
            if (!((idx >= 1) && (idx <= itmp))) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, itmp, &qj_emlrtBCI, sp);
            }

            ii->data[i18] = idx - 1;
          }

          b_ii[0] = ii->size[0];
          b_ii[1] = 7;
          loop_ub = (int32_T)C_Cnt[1];
          i18 = b_newPolygonListPP->size[0] * b_newPolygonListPP->size[1];
          b_newPolygonListPP->size[0] = (int32_T)C_Cnt[1];
          b_newPolygonListPP->size[1] = 7;
          emxEnsureCapacity(sp, (emxArray__common *)b_newPolygonListPP, i18,
                            (int32_T)sizeof(real_T), &n_emlrtRTEI);
          for (i18 = 0; i18 < 7; i18++) {
            for (idx = 0; idx < loop_ub; idx++) {
              b_newPolygonListPP->data[idx + b_newPolygonListPP->size[0] * i18] =
                newPolygonListPP->data[idx + newPolygonListPP->size[0] * i18];
            }
          }

          for (i18 = 0; i18 < 2; i18++) {
            b_PointLast_size[i18] = b_newPolygonListPP->size[i18];
          }

          emlrtSubAssignSizeCheckR2012b(b_ii, 2, b_PointLast_size, 2,
            &cb_emlrtECI, sp);
          loop_ub = (int32_T)C_Cnt[1] - 1;
          for (i18 = 0; i18 < 7; i18++) {
            for (idx = 0; idx <= loop_ub; idx++) {
              newPolygonList->data[ii->data[idx] + newPolygonList->size[0] * i18]
                = newPolygonListPP->data[idx + newPolygonListPP->size[0] * i18];
            }
          }

          C_Cnt[3] += C_Cnt[1];
          newPolygonnum++;

          /* 再次申请一个新的静态矩阵形式的空间 */
          i18 = newPolygonListPP->size[0] * newPolygonListPP->size[1];
          newPolygonListPP->size[0] = (int32_T)n;
          newPolygonListPP->size[1] = 7;
          emxEnsureCapacity(sp, (emxArray__common *)newPolygonListPP, i18,
                            (int32_T)sizeof(real_T), &n_emlrtRTEI);
          loop_ub = (int32_T)n * 7;
          for (i18 = 0; i18 < loop_ub; i18++) {
            newPolygonListPP->data[i18] = 0.0;
          }

          if (1.0 > n) {
            loop_ub = 0;
          } else {
            loop_ub = (int32_T)n;
            if (!((loop_ub >= 1) && (loop_ub <= 100))) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 100, &xi_emlrtBCI, sp);
            }
          }

          st.site = &bc_emlrtRSI;
          i18 = x->size[0];
          x->size[0] = loop_ub;
          emxEnsureCapacity(&st, (emxArray__common *)x, i18, (int32_T)sizeof
                            (boolean_T), &n_emlrtRTEI);
          for (i18 = 0; i18 < loop_ub; i18++) {
            x->data[i18] = (PolygonList[100 + i18] == 0.0);
          }

          b_st.site = &lc_emlrtRSI;
          nx = x->size[0];
          idx = 0;
          i18 = ii->size[0];
          ii->size[0] = x->size[0];
          emxEnsureCapacity(&b_st, (emxArray__common *)ii, i18, (int32_T)sizeof
                            (int32_T), &n_emlrtRTEI);
          c_st.site = &mc_emlrtRSI;
          c_ii = 1;
          exitg6 = false;
          while ((!exitg6) && (c_ii <= nx)) {
            guard6 = false;
            if (x->data[c_ii - 1]) {
              idx++;
              ii->data[idx - 1] = c_ii;
              if (idx >= nx) {
                exitg6 = true;
              } else {
                guard6 = true;
              }
            } else {
              guard6 = true;
            }

            if (guard6) {
              c_ii++;
            }
          }

          if (idx <= x->size[0]) {
          } else {
            emlrtErrorWithMessageIdR2012b(&b_st, &yb_emlrtRTEI,
              "Coder:builtins:AssertionFailed", 0);
          }

          if (x->size[0] == 1) {
            if (idx == 0) {
              i18 = ii->size[0];
              ii->size[0] = 0;
              emxEnsureCapacity(&b_st, (emxArray__common *)ii, i18, (int32_T)
                                sizeof(int32_T), &n_emlrtRTEI);
            }
          } else {
            if (1 > idx) {
              i18 = 0;
            } else {
              i18 = idx;
            }

            iv18[0] = 1;
            iv18[1] = i18;
            c_st.site = &nc_emlrtRSI;
            indexShapeCheck(&c_st, ii->size[0], iv18);
            idx = ii->size[0];
            ii->size[0] = i18;
            emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)
                              sizeof(int32_T), &o_emlrtRTEI);
          }

          /* 判断是否访问完了 */
          if (ii->size[0] == 0) {
            exitg2 = 1;
          } else {
            i18 = (int32_T)n;
            if (!(1 <= i18)) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i18, &vi_emlrtBCI, sp);
            }

            i18 = (int32_T)(newPolygonnum - 1.0);
            if (!((i18 >= 1) && (i18 <= 50))) {
              emlrtDynamicBoundsCheckR2012b(i18, 1, 50, &rj_emlrtBCI, sp);
            }

            i18 = b[i18 - 1];
            if (!((i18 >= 1) && (i18 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i18, 1, 100, &wi_emlrtBCI, sp);
            }

            for (i18 = 0; i18 < 7; i18++) {
              newPolygonListPP->data[newPolygonListPP->size[0] * i18] =
                PolygonList[(b[(int32_T)(newPolygonnum - 1.0) - 1] + 100 * i18)
                - 1];
            }

            /* 重新开始一个环循环 */
            i18 = (int32_T)(newPolygonnum - 1.0);
            if (!((i18 >= 1) && (i18 <= 50))) {
              emlrtDynamicBoundsCheckR2012b(i18, 1, 50, &tj_emlrtBCI, sp);
            }

            i18 = b[i18 - 1];
            if (!((i18 >= 1) && (i18 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i18, 1, 100, &sj_emlrtBCI, sp);
            }

            PolygonList[i18 + 99] = 1.0;
            C_Cnt[1] = 1.0;
            i18 = (int32_T)(newPolygonnum - 1.0);
            if (!((i18 >= 1) && (i18 <= 50))) {
              emlrtDynamicBoundsCheckR2012b(i18, 1, 50, &uj_emlrtBCI, sp);
            }

            b_i = b[i18 - 1];
            guard1 = true;
          }
        }
      }
    }

    if (guard3) {
      /* 判断是否为交点 */
      C_Cnt[0]++;
      i18 = (int32_T)C_Cnt[0];
      if (!((i18 >= 1) && (i18 <= 50))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 50, &vj_emlrtBCI, sp);
      }

      b[i18 - 1] = (int8_T)b_i;
      C_Cnt[1]++;
      c_ii = newPolygonListPP->size[0];
      i18 = (int32_T)C_Cnt[1];
      if (!((i18 >= 1) && (i18 <= c_ii))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, c_ii, &hj_emlrtBCI, sp);
      }

      for (i18 = 0; i18 < 7; i18++) {
        newPolygonListPP->data[((int32_T)C_Cnt[1] + newPolygonListPP->size[0] *
          i18) - 1] = PolygonList[((int32_T)b_i + 100 * i18) - 1];
      }

      /* %以便此处添加一行 */
      if (1.0 > n) {
        loop_ub = 0;
      } else {
        loop_ub = (int32_T)n;
        if (!((loop_ub >= 1) && (loop_ub <= 100))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 100, &gj_emlrtBCI, sp);
        }
      }

      if (1.0 > n) {
        nx = 0;
      } else {
        i18 = row->size[0];
        if (!(1 <= i18)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i18, &fj_emlrtBCI, sp);
        }

        i18 = row->size[0];
        nx = (int32_T)n;
        if (!((nx >= 1) && (nx <= i18))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, i18, &fj_emlrtBCI, sp);
        }
      }

      i18 = ii->size[0];
      ii->size[0] = nx;
      emxEnsureCapacity(sp, (emxArray__common *)ii, i18, (int32_T)sizeof(int32_T),
                        &n_emlrtRTEI);
      for (i18 = 0; i18 < nx; i18++) {
        ii->data[i18] = i18;
      }

      st.site = &dc_emlrtRSI;
      b_st.site = &yc_emlrtRSI;
      for (i18 = 0; i18 < loop_ub; i18++) {
        tf_data[i18] = false;
      }

      c_st.site = &ad_emlrtRSI;
      for (c_ii = 0; c_ii + 1 <= loop_ub; c_ii++) {
        tf_data[c_ii] = false;
        overflow = true;
        nx = 0;
        exitg5 = false;
        while ((!exitg5) && (nx + 1 < 8)) {
          absxk = muDoubleScalarAbs(PolygonList[((int32_T)b_i + 100 * nx) - 1] /
            2.0);
          if ((!muDoubleScalarIsInf(absxk)) && (!muDoubleScalarIsNaN(absxk))) {
            if (absxk <= 2.2250738585072014E-308) {
              absxk = 4.94065645841247E-324;
            } else {
              frexp(absxk, &exponent);
              absxk = ldexp(1.0, exponent - 53);
            }
          } else {
            absxk = rtNaN;
          }

          if ((muDoubleScalarAbs(PolygonList[((int32_T)b_i + 100 * nx) - 1] -
                                 PolygonList[c_ii + 100 * nx]) < absxk) ||
              (muDoubleScalarIsInf(PolygonList[c_ii + 100 * nx]) &&
               muDoubleScalarIsInf(PolygonList[((int32_T)b_i + 100 * nx) - 1]) &&
               ((PolygonList[c_ii + 100 * nx] > 0.0) == (PolygonList[((int32_T)
                  b_i + 100 * nx) - 1] > 0.0)))) {
            p = true;
          } else {
            p = false;
          }

          if (!p) {
            overflow = false;
            exitg5 = true;
          } else {
            nx++;
          }
        }

        if (overflow) {
          tf_data[c_ii] = true;
        }
      }

      tmp_size[0] = loop_ub;
      for (i18 = 0; i18 < loop_ub; i18++) {
        tmp_data[i18] = (int8_T)tf_data[i18];
      }

      d_ii[0] = ii->size[0];
      emlrtSubAssignSizeCheckR2012b(d_ii, 1, tmp_size, 1, &db_emlrtECI, sp);
      for (i18 = 0; i18 < loop_ub; i18++) {
        row->data[ii->data[i18]] = tmp_data[i18];
      }

      if (1.0 > n) {
        loop_ub = 0;
      } else {
        i18 = row->size[0];
        if (!(1 <= i18)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i18, &ej_emlrtBCI, sp);
        }

        i18 = row->size[0];
        loop_ub = (int32_T)n;
        if (!((loop_ub >= 1) && (loop_ub <= i18))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i18, &ej_emlrtBCI, sp);
        }
      }

      st.site = &cc_emlrtRSI;
      i18 = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity(&st, (emxArray__common *)x, i18, (int32_T)sizeof
                        (boolean_T), &n_emlrtRTEI);
      for (i18 = 0; i18 < loop_ub; i18++) {
        x->data[i18] = (row->data[i18] == 1.0);
      }

      b_st.site = &lc_emlrtRSI;
      nx = x->size[0];
      idx = 0;
      i18 = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i18, (int32_T)sizeof
                        (int32_T), &n_emlrtRTEI);
      c_st.site = &mc_emlrtRSI;
      c_ii = 1;
      exitg4 = false;
      while ((!exitg4) && (c_ii <= nx)) {
        guard5 = false;
        if (x->data[c_ii - 1]) {
          idx++;
          ii->data[idx - 1] = c_ii;
          if (idx >= nx) {
            exitg4 = true;
          } else {
            guard5 = true;
          }
        } else {
          guard5 = true;
        }

        if (guard5) {
          c_ii++;
        }
      }

      if (idx <= x->size[0]) {
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &yb_emlrtRTEI,
          "Coder:builtins:AssertionFailed", 0);
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          i18 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity(&b_st, (emxArray__common *)ii, i18, (int32_T)sizeof
                            (int32_T), &n_emlrtRTEI);
        }
      } else {
        if (1 > idx) {
          i18 = 0;
        } else {
          i18 = idx;
        }

        iv19[0] = 1;
        iv19[1] = i18;
        c_st.site = &nc_emlrtRSI;
        indexShapeCheck(&c_st, ii->size[0], iv19);
        idx = ii->size[0];
        ii->size[0] = i18;
        emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                          (int32_T), &o_emlrtRTEI);
      }

      i18 = mm->size[0];
      mm->size[0] = ii->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)mm, i18, (int32_T)sizeof(real_T),
                        &n_emlrtRTEI);
      loop_ub = ii->size[0];
      for (i18 = 0; i18 < loop_ub; i18++) {
        mm->data[i18] = ii->data[i18];
      }

      if (mm->size[0] == 1) {
        if (PolygonList[(int32_T)b_i + 599] + 1.0 > d1) {
          /* 经过加一处理后，m(1,3)可能超过了未插入交点前的点集的点数 */
          b_i = 0.0;
        } else {
          emlrtForLoopVectorCheckR2012b(1.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)n,
            &xb_emlrtRTEI, sp);
          c_ii = 0;
          exitg3 = false;
          while ((!exitg3) && (c_ii <= (int32_T)n - 1)) {
            if (!((c_ii + 1 >= 1) && (c_ii + 1 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(c_ii + 1, 1, 100, &wj_emlrtBCI, sp);
            }

            if (PolygonList[c_ii] == PolygonList[(int32_T)b_i + 599] + 1.0) {
              b_i = (1.0 + (real_T)c_ii) - 1.0;
              exitg3 = true;
            } else {
              c_ii++;
              if (*emlrtBreakCheckR2012bFlagVar != 0) {
                emlrtBreakCheckR2012b(sp);
              }
            }
          }

          /* m(1,4) = find(PolygonList(1:n(1,1),1)==m(1,3)); */
          /* i = m(1,4)-1; */
        }
      } else {
        i18 = mm->size[0];
        if (!(2 <= i18)) {
          emlrtDynamicBoundsCheckR2012b(2, 1, i18, &dj_emlrtBCI, sp);
        }

        b_i = mm->data[1];
      }

      guard1 = true;
    }

    if (guard2) {
      C_Cnt[1]++;
      c_ii = newPolygonListPP->size[0];
      i18 = (int32_T)C_Cnt[1];
      if (!((i18 >= 1) && (i18 <= c_ii))) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, c_ii, &aj_emlrtBCI, sp);
      }

      for (i18 = 0; i18 < 7; i18++) {
        newPolygonListPP->data[((int32_T)C_Cnt[1] + newPolygonListPP->size[0] *
          i18) - 1] = PolygonList[((int32_T)b_i + 100 * i18) - 1];
      }

      /* %以便此处添加一行 */
      PolygonList[(int32_T)b_i + 99] = 1.0;
      guard1 = true;
    }

    if (guard1) {
      tt++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }

      if (tt >= 100.0 + d2 * 3.0) {
        exitg2 = 1;
      }
    }
  } while (exitg2 == 0);

  emxFree_real_T(&b_newPolygonListPP);
  emxFree_int32_T(&ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&mm);
  emxFree_real_T(&row);
  emxFree_real_T(&newPolygonListPP);
  emxInit_real_T(sp, &Aera, 2, &u_emlrtRTEI, true);

  /* % */
  i18 = Aera->size[0] * Aera->size[1];
  Aera->size[0] = (int32_T)C_Cnt[2];
  Aera->size[1] = 3;
  emxEnsureCapacity(sp, (emxArray__common *)Aera, i18, (int32_T)sizeof(real_T),
                    &n_emlrtRTEI);
  loop_ub = (int32_T)C_Cnt[2] * 3;
  for (i18 = 0; i18 < loop_ub; i18++) {
    Aera->data[i18] = 0.0;
  }

  C_Aera = 0U;
  if (C_Cnt[2] == 1.0) {
    if (1.0 > C_Cnt[3]) {
      loop_ub = -1;
    } else {
      i18 = newPolygonList->size[0];
      if (!(1 <= i18)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i18, &ui_emlrtBCI, sp);
      }

      i18 = newPolygonList->size[0];
      idx = (int32_T)C_Cnt[3];
      if (!((idx >= 1) && (idx <= i18))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i18, &ui_emlrtBCI, sp);
      }

      loop_ub = idx - 1;
    }

    if (1.0 > C_Cnt[3]) {
      nx = 0;
    } else {
      nx = (int32_T)C_Cnt[3];
      if (!((nx >= 1) && (nx <= 100))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, 100, &mi_emlrtBCI, sp);
      }
    }

    for (i18 = 0; i18 < nx; i18++) {
      b_tmp_data[i18] = i18;
    }

    emxInit_real_T(sp, &b_newPolygonList, 2, &n_emlrtRTEI, true);
    iv20[0] = nx;
    iv20[1] = 2;
    i18 = b_newPolygonList->size[0] * b_newPolygonList->size[1];
    b_newPolygonList->size[0] = loop_ub + 1;
    b_newPolygonList->size[1] = 2;
    emxEnsureCapacity(sp, (emxArray__common *)b_newPolygonList, i18, (int32_T)
                      sizeof(real_T), &n_emlrtRTEI);
    for (i18 = 0; i18 < 2; i18++) {
      for (idx = 0; idx <= loop_ub; idx++) {
        b_newPolygonList->data[idx + b_newPolygonList->size[0] * i18] =
          newPolygonList->data[idx + newPolygonList->size[0] * (3 + i18)];
      }
    }

    for (i18 = 0; i18 < 2; i18++) {
      b_PointLast_size[i18] = b_newPolygonList->size[i18];
    }

    emxFree_real_T(&b_newPolygonList);
    emlrtSubAssignSizeCheckR2012b(iv20, 2, b_PointLast_size, 2, &bb_emlrtECI, sp);
    for (i18 = 0; i18 < 2; i18++) {
      for (idx = 0; idx <= loop_ub; idx++) {
        YouXiao[b_tmp_data[idx] + 100 * i18] = newPolygonList->data[idx +
          newPolygonList->size[0] * (3 + i18)];
      }
    }

    *YX_Cnt = C_Cnt[3];
  } else {
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, C_Cnt[2], mxDOUBLE_CLASS, (int32_T)
      C_Cnt[2], &wb_emlrtRTEI, sp);
    i = 0;
    emxInit_real_T(sp, &r6, 2, &n_emlrtRTEI, true);
    emxInit_real_T1(sp, &c_newPolygonList, 1, &n_emlrtRTEI, true);
    emxInit_real_T1(sp, &d_newPolygonList, 1, &n_emlrtRTEI, true);
    emxInit_real_T1(sp, &b_ccc, 1, &n_emlrtRTEI, true);
    emxInit_real_T1(sp, &e_newPolygonList, 1, &n_emlrtRTEI, true);
    emxInit_real_T1(sp, &f_newPolygonList, 1, &n_emlrtRTEI, true);
    emxInit_real_T(sp, &g_newPolygonList, 2, &n_emlrtRTEI, true);
    emxInit_real_T(sp, &h_newPolygonList, 2, &n_emlrtRTEI, true);
    while (i <= (int32_T)C_Cnt[2] - 1) {
      if (1.0 + (real_T)i == 1.0) {
        i18 = ccc->size[0];
        idx = i + 1;
        if (!((idx >= 1) && (idx <= i18))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i18, &ti_emlrtBCI, sp);
        }

        if (1.0 > ccc->data[0]) {
          loop_ub = 0;
        } else {
          i18 = newPolygonList->size[0];
          if (!(1 <= i18)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i18, &si_emlrtBCI, sp);
          }

          i18 = newPolygonList->size[0];
          loop_ub = (int32_T)ccc->data[0];
          if (!((loop_ub >= 1) && (loop_ub <= i18))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i18, &si_emlrtBCI, sp);
          }
        }

        i18 = ccc->size[0];
        idx = i + 1;
        if (!((idx >= 1) && (idx <= i18))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i18, &ri_emlrtBCI, sp);
        }

        if (1.0 > ccc->data[0]) {
          nx = 0;
        } else {
          i18 = newPolygonList->size[0];
          if (!(1 <= i18)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i18, &qi_emlrtBCI, sp);
          }

          i18 = newPolygonList->size[0];
          nx = (int32_T)ccc->data[0];
          if (!((nx >= 1) && (nx <= i18))) {
            emlrtDynamicBoundsCheckR2012b(nx, 1, i18, &qi_emlrtBCI, sp);
          }
        }

        i18 = ccc->size[0];
        idx = i + 1;
        if (!((idx >= 1) && (idx <= i18))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i18, &pi_emlrtBCI, sp);
        }

        i18 = e_newPolygonList->size[0];
        e_newPolygonList->size[0] = loop_ub;
        emxEnsureCapacity(sp, (emxArray__common *)e_newPolygonList, i18,
                          (int32_T)sizeof(real_T), &n_emlrtRTEI);
        for (i18 = 0; i18 < loop_ub; i18++) {
          e_newPolygonList->data[i18] = newPolygonList->data[i18 +
            newPolygonList->size[0] * 3];
        }

        i18 = f_newPolygonList->size[0];
        f_newPolygonList->size[0] = nx;
        emxEnsureCapacity(sp, (emxArray__common *)f_newPolygonList, i18,
                          (int32_T)sizeof(real_T), &n_emlrtRTEI);
        for (i18 = 0; i18 < nx; i18++) {
          f_newPolygonList->data[i18] = newPolygonList->data[i18 +
            (newPolygonList->size[0] << 2)];
        }

        st.site = &ac_emlrtRSI;
        FFLOG0 = judgeClockWise(&st, e_newPolygonList, f_newPolygonList,
          ccc->data[0]);
        if (FFLOG0 == 0.0) {
          i18 = ccc->size[0];
          idx = i + 1;
          if (!((idx >= 1) && (idx <= i18))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, i18, &oi_emlrtBCI, sp);
          }

          if (1.0 > ccc->data[0]) {
            loop_ub = -1;
          } else {
            i18 = newPolygonList->size[0];
            if (!(1 <= i18)) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i18, &ni_emlrtBCI, sp);
            }

            i18 = newPolygonList->size[0];
            idx = (int32_T)ccc->data[0];
            if (!((idx >= 1) && (idx <= i18))) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, i18, &ni_emlrtBCI, sp);
            }

            loop_ub = idx - 1;
          }

          i18 = ccc->size[0];
          idx = i + 1;
          if (!((idx >= 1) && (idx <= i18))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, i18, &li_emlrtBCI, sp);
          }

          if (1.0 > ccc->data[0]) {
            nx = 0;
          } else {
            nx = (int32_T)ccc->data[0];
            if (!((nx >= 1) && (nx <= 100))) {
              emlrtDynamicBoundsCheckR2012b(nx, 1, 100, &ki_emlrtBCI, sp);
            }
          }

          for (i18 = 0; i18 < nx; i18++) {
            b_tmp_data[i18] = i18;
          }

          iv21[0] = nx;
          iv21[1] = 2;
          i18 = h_newPolygonList->size[0] * h_newPolygonList->size[1];
          h_newPolygonList->size[0] = loop_ub + 1;
          h_newPolygonList->size[1] = 2;
          emxEnsureCapacity(sp, (emxArray__common *)h_newPolygonList, i18,
                            (int32_T)sizeof(real_T), &n_emlrtRTEI);
          for (i18 = 0; i18 < 2; i18++) {
            for (idx = 0; idx <= loop_ub; idx++) {
              h_newPolygonList->data[idx + h_newPolygonList->size[0] * i18] =
                newPolygonList->data[idx + newPolygonList->size[0] * (3 + i18)];
            }
          }

          for (i18 = 0; i18 < 2; i18++) {
            b_PointLast_size[i18] = h_newPolygonList->size[i18];
          }

          emlrtSubAssignSizeCheckR2012b(iv21, 2, b_PointLast_size, 2,
            &ab_emlrtECI, sp);
          for (i18 = 0; i18 < 2; i18++) {
            for (idx = 0; idx <= loop_ub; idx++) {
              YouXiao[b_tmp_data[idx] + 100 * i18] = newPolygonList->data[idx +
                newPolygonList->size[0] * (3 + i18)];
            }
          }

          C_Aera++;
          i18 = ccc->size[0];
          idx = i + 1;
          if (!((idx >= 1) && (idx <= i18))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, i18, &ji_emlrtBCI, sp);
          }

          if (1.0 > ccc->data[0]) {
            loop_ub = 0;
          } else {
            loop_ub = (int32_T)ccc->data[0];
            if (!((loop_ub >= 1) && (loop_ub <= 100))) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 100, &ii_emlrtBCI, sp);
            }
          }

          i18 = ccc->size[0];
          idx = i + 1;
          if (!((idx >= 1) && (idx <= i18))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, i18, &hi_emlrtBCI, sp);
          }

          i18 = ccc->size[0];
          idx = i + 1;
          if (!((idx >= 1) && (idx <= i18))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, i18, &gi_emlrtBCI, sp);
          }

          YouXiao_size[0] = loop_ub;
          YouXiao_size[1] = 2;
          for (i18 = 0; i18 < 2; i18++) {
            for (idx = 0; idx < loop_ub; idx++) {
              YouXiao_data[idx + loop_ub * i18] = YouXiao[idx + 100 * i18];
            }
          }

          st.site = &yb_emlrtRSI;
          d2 = Calculate_Area(&st, YouXiao_data, YouXiao_size, ccc->data[0]);
          c_ii = Aera->size[0];
          i18 = (int32_T)C_Aera;
          if (!((i18 >= 1) && (i18 <= c_ii))) {
            emlrtDynamicBoundsCheckR2012b(i18, 1, c_ii, &ai_emlrtBCI, sp);
          }

          Aera->data[(int32_T)C_Aera - 1] = d2;
          Aera->data[((int32_T)C_Aera + Aera->size[0]) - 1] = ccc->data[0];
          Aera->data[((int32_T)C_Aera + (Aera->size[0] << 1)) - 1] = 1.0;

          /* Mianji = [Mianji;[CalculateMianji(YouXiao,ccc(i)),ccc(i),i]]; */
        }

        /* FFLOGzong = [FFLOGzong;FFLOG0]; */
      } else {
        i18 = ccc->size[0];
        if (!(1 <= i18)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i18, &fi_emlrtBCI, sp);
        }

        i18 = ccc->size[0];
        idx = (int32_T)((1.0 + (real_T)i) - 1.0);
        if (!((idx >= 1) && (idx <= i18))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i18, &fi_emlrtBCI, sp);
        }

        iv22[0] = 1;
        iv22[1] = (int32_T)((1.0 + (real_T)i) - 1.0);
        st.site = &xb_emlrtRSI;
        indexShapeCheck(&st, ccc->size[0], iv22);
        loop_ub = (int32_T)((1.0 + (real_T)i) - 1.0);
        i18 = b_ccc->size[0];
        b_ccc->size[0] = (int32_T)((1.0 + (real_T)i) - 1.0);
        emxEnsureCapacity(sp, (emxArray__common *)b_ccc, i18, (int32_T)sizeof
                          (real_T), &n_emlrtRTEI);
        for (i18 = 0; i18 < loop_ub; i18++) {
          b_ccc->data[i18] = ccc->data[i18];
        }

        st.site = &xb_emlrtRSI;
        ct = sum(&st, b_ccc);
        i18 = ccc->size[0];
        if (!((i + 1 >= 1) && (i + 1 <= i18))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i18, &yj_emlrtBCI, sp);
        }

        d2 = ccc->data[i];
        itmp = newPolygonList->size[0];
        i18 = c_newPolygonList->size[0];
        c_newPolygonList->size[0] = (int32_T)muDoubleScalarFloor(d2 - 1.0) + 1;
        emxEnsureCapacity(sp, (emxArray__common *)c_newPolygonList, i18,
                          (int32_T)sizeof(real_T), &n_emlrtRTEI);
        loop_ub = (int32_T)muDoubleScalarFloor(d2 - 1.0);
        for (i18 = 0; i18 <= loop_ub; i18++) {
          idx = (int32_T)(ct + (real_T)(i18 + 1));
          if (!((idx >= 1) && (idx <= itmp))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, itmp, &ak_emlrtBCI, sp);
          }

          c_newPolygonList->data[i18] = newPolygonList->data[(idx +
            newPolygonList->size[0] * 3) - 1];
        }

        i18 = ccc->size[0];
        if (!((i + 1 >= 1) && (i + 1 <= i18))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i18, &bk_emlrtBCI, sp);
        }

        d2 = ccc->data[i];
        itmp = newPolygonList->size[0];
        i18 = d_newPolygonList->size[0];
        d_newPolygonList->size[0] = (int32_T)muDoubleScalarFloor(d2 - 1.0) + 1;
        emxEnsureCapacity(sp, (emxArray__common *)d_newPolygonList, i18,
                          (int32_T)sizeof(real_T), &n_emlrtRTEI);
        loop_ub = (int32_T)muDoubleScalarFloor(d2 - 1.0);
        for (i18 = 0; i18 <= loop_ub; i18++) {
          idx = (int32_T)(ct + (real_T)(i18 + 1));
          if (!((idx >= 1) && (idx <= itmp))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, itmp, &ck_emlrtBCI, sp);
          }

          d_newPolygonList->data[i18] = newPolygonList->data[(idx +
            (newPolygonList->size[0] << 2)) - 1];
        }

        i18 = ccc->size[0];
        if (!((i + 1 >= 1) && (i + 1 <= i18))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, i18, &dk_emlrtBCI, sp);
        }

        st.site = &wb_emlrtRSI;
        FFLOG0 = judgeClockWise(&st, c_newPolygonList, d_newPolygonList,
          ccc->data[i]);
        if (FFLOG0 == 0.0) {
          i18 = ccc->size[0];
          idx = i + 1;
          if (!((idx >= 1) && (idx <= i18))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, i18, &ei_emlrtBCI, sp);
          }

          if (1.0 > ccc->data[i]) {
            loop_ub = 0;
          } else {
            loop_ub = (int32_T)ccc->data[i];
            if (!((loop_ub >= 1) && (loop_ub <= 100))) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 100, &di_emlrtBCI, sp);
            }
          }

          for (i18 = 0; i18 < loop_ub; i18++) {
            b_tmp_data[i18] = i18;
          }

          i18 = ccc->size[0];
          if (!((i + 1 >= 1) && (i + 1 <= i18))) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, i18, &ek_emlrtBCI, sp);
          }

          d2 = ccc->data[i];
          itmp = newPolygonList->size[0];
          i18 = r6->size[0] * r6->size[1];
          r6->size[0] = (int32_T)muDoubleScalarFloor(d2 - 1.0) + 1;
          r6->size[1] = 2;
          emxEnsureCapacity(sp, (emxArray__common *)r6, i18, (int32_T)sizeof
                            (real_T), &n_emlrtRTEI);
          for (i18 = 0; i18 < 2; i18++) {
            nx = (int32_T)muDoubleScalarFloor(d2 - 1.0);
            for (idx = 0; idx <= nx; idx++) {
              c_ii = (int32_T)(ct + (real_T)(idx + 1));
              if (!((c_ii >= 1) && (c_ii <= itmp))) {
                emlrtDynamicBoundsCheckR2012b(c_ii, 1, itmp, &fk_emlrtBCI, sp);
              }

              r6->data[idx + r6->size[0] * i18] = newPolygonList->data[(c_ii +
                newPolygonList->size[0] * (3 + i18)) - 1];
            }
          }

          iv23[0] = loop_ub;
          iv23[1] = 2;
          d2 = ccc->data[i];
          i18 = g_newPolygonList->size[0] * g_newPolygonList->size[1];
          g_newPolygonList->size[0] = (int32_T)muDoubleScalarFloor(d2 - 1.0) + 1;
          g_newPolygonList->size[1] = 2;
          emxEnsureCapacity(sp, (emxArray__common *)g_newPolygonList, i18,
                            (int32_T)sizeof(real_T), &n_emlrtRTEI);
          for (i18 = 0; i18 < 2; i18++) {
            loop_ub = (int32_T)muDoubleScalarFloor(d2 - 1.0);
            for (idx = 0; idx <= loop_ub; idx++) {
              g_newPolygonList->data[idx + g_newPolygonList->size[0] * i18] =
                newPolygonList->data[((int32_T)(ct + (real_T)(idx + 1)) +
                newPolygonList->size[0] * (3 + i18)) - 1];
            }
          }

          for (i18 = 0; i18 < 2; i18++) {
            b_PointLast_size[i18] = g_newPolygonList->size[i18];
          }

          emlrtSubAssignSizeCheckR2012b(iv23, 2, b_PointLast_size, 2,
            &y_emlrtECI, sp);
          for (i18 = 0; i18 < 2; i18++) {
            loop_ub = r6->size[0];
            for (idx = 0; idx < loop_ub; idx++) {
              YouXiao[b_tmp_data[idx] + 100 * i18] = r6->data[idx + r6->size[0] *
                i18];
            }
          }

          C_Aera++;
          i18 = ccc->size[0];
          idx = i + 1;
          if (!((idx >= 1) && (idx <= i18))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, i18, &ci_emlrtBCI, sp);
          }

          if (1.0 > ccc->data[i]) {
            loop_ub = 0;
          } else {
            loop_ub = (int32_T)ccc->data[i];
            if (!((loop_ub >= 1) && (loop_ub <= 100))) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 100, &bi_emlrtBCI, sp);
            }
          }

          b_YouXiao_size[0] = loop_ub;
          b_YouXiao_size[1] = 2;
          for (i18 = 0; i18 < 2; i18++) {
            for (idx = 0; idx < loop_ub; idx++) {
              YouXiao_data[idx + loop_ub * i18] = YouXiao[idx + 100 * i18];
            }
          }

          i18 = ccc->size[0];
          if (!((i + 1 >= 1) && (i + 1 <= i18))) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, i18, &gk_emlrtBCI, sp);
          }

          st.site = &vb_emlrtRSI;
          d2 = Calculate_Area(&st, YouXiao_data, b_YouXiao_size, ccc->data[i]);
          c_ii = Aera->size[0];
          i18 = (int32_T)C_Aera;
          if (!((i18 >= 1) && (i18 <= c_ii))) {
            emlrtDynamicBoundsCheckR2012b(i18, 1, c_ii, &yh_emlrtBCI, sp);
          }

          Aera->data[(int32_T)C_Aera - 1] = d2;
          i18 = ccc->size[0];
          if (!((i + 1 >= 1) && (i + 1 <= i18))) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, i18, &hk_emlrtBCI, sp);
          }

          Aera->data[((int32_T)C_Aera + Aera->size[0]) - 1] = ccc->data[i];
          Aera->data[((int32_T)C_Aera + (Aera->size[0] << 1)) - 1] = 1.0 +
            (real_T)i;

          /* Mianji = [Mianji;[CalculateMianji(YouXiao,ccc(i)),ccc(i),i]]; */
        }
      }

      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    emxFree_real_T(&h_newPolygonList);
    emxFree_real_T(&g_newPolygonList);
    emxFree_real_T(&f_newPolygonList);
    emxFree_real_T(&e_newPolygonList);
    emxFree_real_T(&b_ccc);
    emxFree_real_T(&d_newPolygonList);
    emxFree_real_T(&c_newPolygonList);
    memset(&YouXiao[0], 0, 200U * sizeof(real_T));
    st.site = &ub_emlrtRSI;
    b_st.site = &ed_emlrtRSI;
    c_st.site = &fd_emlrtRSI;
    i18 = Aera->size[0];
    b_guard1 = false;
    if (i18 == 1) {
      b_guard1 = true;
    } else {
      i18 = Aera->size[0];
      if (i18 != 1) {
        b_guard1 = true;
      } else {
        overflow = false;
      }
    }

    if (b_guard1) {
      overflow = true;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &ac_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    i18 = Aera->size[0];
    if (i18 > 0) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &bc_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    d_st.site = &gd_emlrtRSI;
    nx = 1;
    idx = Aera->size[0];
    absxk = Aera->data[0];
    itmp = 1;
    i18 = Aera->size[0];
    if (i18 > 1) {
      if (muDoubleScalarIsNaN(absxk)) {
        e_st.site = &id_emlrtRSI;
        i18 = Aera->size[0];
        if (2 > i18) {
          overflow = false;
        } else {
          i18 = Aera->size[0];
          overflow = (i18 > 2147483646);
        }

        if (overflow) {
          f_st.site = &t_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        c_ii = 2;
        exitg1 = false;
        while ((!exitg1) && (c_ii <= idx)) {
          nx = c_ii;
          if (!muDoubleScalarIsNaN(Aera->data[c_ii - 1])) {
            absxk = Aera->data[c_ii - 1];
            itmp = c_ii;
            exitg1 = true;
          } else {
            c_ii++;
          }
        }
      }

      i18 = Aera->size[0];
      if (nx < i18) {
        e_st.site = &hd_emlrtRSI;
        i18 = Aera->size[0];
        if (nx + 1 > i18) {
          overflow = false;
        } else {
          i18 = Aera->size[0];
          overflow = (i18 > 2147483646);
        }

        if (overflow) {
          f_st.site = &t_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while (nx + 1 <= idx) {
          if (Aera->data[nx] > absxk) {
            absxk = Aera->data[nx];
            itmp = nx + 1;
          }

          nx++;
        }
      }
    }

    /* 找到第一列最大值的序号 */
    i18 = Aera->size[0];
    if (!(1 <= i18)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i18, &wh_emlrtBCI, sp);
    }

    c_ii = Aera->size[0];
    if (!((itmp >= 1) && (itmp <= c_ii))) {
      emlrtDynamicBoundsCheckR2012b(itmp, 1, c_ii, &xh_emlrtBCI, sp);
    }

    for (i18 = 0; i18 < 3; i18++) {
      b_Aera[i18] = Aera->data[(itmp + Aera->size[0] * i18) - 1];
    }

    for (i18 = 0; i18 < 3; i18++) {
      Aera->data[Aera->size[0] * i18] = b_Aera[i18];
    }

    /* 显示最大值所在的一行的元素  */
    i18 = Aera->size[0];
    if (!(1 <= i18)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i18, &vh_emlrtBCI, sp);
    }

    if (Aera->data[Aera->size[0] << 1] == 1.0) {
      i18 = Aera->size[0];
      if (!(1 <= i18)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i18, &uh_emlrtBCI, sp);
      }

      if (1.0 > Aera->data[Aera->size[0]]) {
        loop_ub = -1;
      } else {
        i18 = newPolygonList->size[0];
        if (!(1 <= i18)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i18, &th_emlrtBCI, sp);
        }

        i18 = newPolygonList->size[0];
        d2 = Aera->data[Aera->size[0]];
        if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
          emlrtIntegerCheckR2012b(d2, &s_emlrtDCI, sp);
        }

        idx = (int32_T)d2;
        if (!((idx >= 1) && (idx <= i18))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i18, &th_emlrtBCI, sp);
        }

        loop_ub = idx - 1;
      }

      i18 = Aera->size[0];
      if (!(1 <= i18)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i18, &sh_emlrtBCI, sp);
      }

      if (1.0 > Aera->data[Aera->size[0]]) {
        nx = 0;
      } else {
        d2 = Aera->data[Aera->size[0]];
        if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
          emlrtIntegerCheckR2012b(d2, &r_emlrtDCI, sp);
        }

        nx = (int32_T)d2;
        if (!((nx >= 1) && (nx <= 100))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, 100, &rh_emlrtBCI, sp);
        }
      }

      for (i18 = 0; i18 < nx; i18++) {
        b_tmp_data[i18] = i18;
      }

      emxInit_real_T(sp, &i_newPolygonList, 2, &n_emlrtRTEI, true);
      iv20[0] = nx;
      iv20[1] = 2;
      i18 = i_newPolygonList->size[0] * i_newPolygonList->size[1];
      i_newPolygonList->size[0] = loop_ub + 1;
      i_newPolygonList->size[1] = 2;
      emxEnsureCapacity(sp, (emxArray__common *)i_newPolygonList, i18, (int32_T)
                        sizeof(real_T), &n_emlrtRTEI);
      for (i18 = 0; i18 < 2; i18++) {
        for (idx = 0; idx <= loop_ub; idx++) {
          i_newPolygonList->data[idx + i_newPolygonList->size[0] * i18] =
            newPolygonList->data[idx + newPolygonList->size[0] * (3 + i18)];
        }
      }

      for (i18 = 0; i18 < 2; i18++) {
        b_PointLast_size[i18] = i_newPolygonList->size[i18];
      }

      emxFree_real_T(&i_newPolygonList);
      emlrtSubAssignSizeCheckR2012b(iv20, 2, b_PointLast_size, 2, &x_emlrtECI,
        sp);
      for (i18 = 0; i18 < 2; i18++) {
        for (idx = 0; idx <= loop_ub; idx++) {
          YouXiao[b_tmp_data[idx] + 100 * i18] = newPolygonList->data[idx +
            newPolygonList->size[0] * (3 + i18)];
        }
      }

      i18 = Aera->size[0];
      if (!(1 <= i18)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i18, &qh_emlrtBCI, sp);
      }

      *YX_Cnt = Aera->data[Aera->size[0]];
    } else {
      i18 = Aera->size[0];
      if (!(1 <= i18)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i18, &ph_emlrtBCI, sp);
      }

      if (1.0 > Aera->data[Aera->size[0] << 1] - 1.0) {
        loop_ub = 0;
      } else {
        i18 = ccc->size[0];
        if (!(1 <= i18)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i18, &oh_emlrtBCI, sp);
        }

        i18 = ccc->size[0];
        d2 = Aera->data[Aera->size[0] << 1] - 1.0;
        if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
          emlrtIntegerCheckR2012b(d2, &q_emlrtDCI, sp);
        }

        loop_ub = (int32_T)d2;
        if (!((loop_ub >= 1) && (loop_ub <= i18))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i18, &oh_emlrtBCI, sp);
        }
      }

      emxInit_real_T1(sp, &c_ccc, 1, &n_emlrtRTEI, true);
      i18 = c_ccc->size[0];
      c_ccc->size[0] = loop_ub;
      emxEnsureCapacity(sp, (emxArray__common *)c_ccc, i18, (int32_T)sizeof
                        (real_T), &n_emlrtRTEI);
      for (i18 = 0; i18 < loop_ub; i18++) {
        c_ccc->data[i18] = ccc->data[i18];
      }

      st.site = &tb_emlrtRSI;
      ct = sum(&st, c_ccc);
      i18 = Aera->size[0];
      if (!(1 <= i18)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i18, &mh_emlrtBCI, sp);
      }

      emxFree_real_T(&c_ccc);
      if (1.0 > Aera->data[Aera->size[0]]) {
        loop_ub = 0;
      } else {
        d2 = Aera->data[Aera->size[0]];
        if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
          emlrtIntegerCheckR2012b(d2, &p_emlrtDCI, sp);
        }

        loop_ub = (int32_T)d2;
        if (!((loop_ub >= 1) && (loop_ub <= 100))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 100, &lh_emlrtBCI, sp);
        }
      }

      for (i18 = 0; i18 < loop_ub; i18++) {
        b_tmp_data[i18] = i18;
      }

      i18 = Aera->size[0];
      if (!(1 <= i18)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i18, &nh_emlrtBCI, sp);
      }

      d2 = Aera->data[Aera->size[0]];
      itmp = newPolygonList->size[0];
      i18 = r6->size[0] * r6->size[1];
      r6->size[0] = (int32_T)muDoubleScalarFloor(d2 - 1.0) + 1;
      r6->size[1] = 2;
      emxEnsureCapacity(sp, (emxArray__common *)r6, i18, (int32_T)sizeof(real_T),
                        &n_emlrtRTEI);
      for (i18 = 0; i18 < 2; i18++) {
        nx = (int32_T)muDoubleScalarFloor(d2 - 1.0);
        for (idx = 0; idx <= nx; idx++) {
          d1 = ct + (real_T)(idx + 1);
          if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
            emlrtIntegerCheckR2012b(d1, &t_emlrtDCI, sp);
          }

          c_ii = (int32_T)d1;
          if (!((c_ii >= 1) && (c_ii <= itmp))) {
            emlrtDynamicBoundsCheckR2012b(c_ii, 1, itmp, &xj_emlrtBCI, sp);
          }

          r6->data[idx + r6->size[0] * i18] = newPolygonList->data[(c_ii +
            newPolygonList->size[0] * (3 + i18)) - 1];
        }
      }

      emxInit_real_T(sp, &j_newPolygonList, 2, &n_emlrtRTEI, true);
      iv20[0] = loop_ub;
      iv20[1] = 2;
      d2 = Aera->data[Aera->size[0]];
      i18 = j_newPolygonList->size[0] * j_newPolygonList->size[1];
      j_newPolygonList->size[0] = (int32_T)muDoubleScalarFloor(d2 - 1.0) + 1;
      j_newPolygonList->size[1] = 2;
      emxEnsureCapacity(sp, (emxArray__common *)j_newPolygonList, i18, (int32_T)
                        sizeof(real_T), &n_emlrtRTEI);
      for (i18 = 0; i18 < 2; i18++) {
        loop_ub = (int32_T)muDoubleScalarFloor(d2 - 1.0);
        for (idx = 0; idx <= loop_ub; idx++) {
          j_newPolygonList->data[idx + j_newPolygonList->size[0] * i18] =
            newPolygonList->data[((int32_T)(ct + (real_T)(idx + 1)) +
            newPolygonList->size[0] * (3 + i18)) - 1];
        }
      }

      for (i18 = 0; i18 < 2; i18++) {
        b_PointLast_size[i18] = j_newPolygonList->size[i18];
      }

      emxFree_real_T(&j_newPolygonList);
      emlrtSubAssignSizeCheckR2012b(iv20, 2, b_PointLast_size, 2, &w_emlrtECI,
        sp);
      for (i18 = 0; i18 < 2; i18++) {
        loop_ub = r6->size[0];
        for (idx = 0; idx < loop_ub; idx++) {
          YouXiao[b_tmp_data[idx] + 100 * i18] = r6->data[idx + r6->size[0] *
            i18];
        }
      }

      i18 = Aera->size[0];
      if (!(1 <= i18)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i18, &kh_emlrtBCI, sp);
      }

      *YX_Cnt = Aera->data[Aera->size[0]];
    }

    emxFree_real_T(&r6);
  }

  emxFree_real_T(&Aera);
  emxFree_real_T(&newPolygonList);
  emxFree_real_T(&ccc);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Calculate_Effective_Point.c) */
