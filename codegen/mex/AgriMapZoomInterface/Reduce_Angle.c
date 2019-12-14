/*
 * Reduce_Angle.c
 *
 * Code generation for function 'Reduce_Angle'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "Reduce_Angle.h"
#include "error.h"
#include "sqrt.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRSInfo de_emlrtRSI = { 30, "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m" };

static emlrtRSInfo ee_emlrtRSI = { 31, "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m" };

static emlrtRSInfo fe_emlrtRSI = { 32, "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m" };

static emlrtRSInfo ge_emlrtRSI = { 33, "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m" };

static emlrtRSInfo he_emlrtRSI = { 37, "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m" };

static emlrtRSInfo ie_emlrtRSI = { 38, "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m" };

static emlrtRSInfo je_emlrtRSI = { 53, "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m" };

static emlrtRSInfo ke_emlrtRSI = { 54, "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m" };

static emlrtRSInfo le_emlrtRSI = { 55, "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m" };

static emlrtRSInfo me_emlrtRSI = { 56, "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m" };

static emlrtRSInfo ne_emlrtRSI = { 60, "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m" };

static emlrtRSInfo oe_emlrtRSI = { 61, "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m" };

static emlrtBCInfo yo_emlrtBCI = { 1, 100, 64, 15, "P", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo ap_emlrtBCI = { 1, 100, 58, 15, "P", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo bp_emlrtBCI = { 1, 100, 47, 11, "P", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo cp_emlrtBCI = { -1, -1, 64, 108, "Sina", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo dp_emlrtBCI = { -1, -1, 64, 85, "NEdgevectorList",
  "Reduce_Angle", "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo ep_emlrtBCI = { -1, -1, 64, 60, "NEdgevectorList",
  "Reduce_Angle", "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo fp_emlrtBCI = { -1, -1, 64, 34, "Point", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo gp_emlrtBCI = { -1, -1, 61, 101, "Cosa", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo hp_emlrtBCI = { -1, -1, 61, 67, "Cosa", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo ip_emlrtBCI = { -1, -1, 60, 101, "Cosa", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo jp_emlrtBCI = { -1, -1, 60, 67, "Cosa", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo kp_emlrtBCI = { -1, -1, 58, 34, "Point", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo lp_emlrtBCI = { -1, -1, 56, 103, "Cosa", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo mp_emlrtBCI = { -1, -1, 56, 69, "Cosa", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo np_emlrtBCI = { -1, -1, 55, 103, "Cosa", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo op_emlrtBCI = { -1, -1, 55, 69, "Cosa", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo pp_emlrtBCI = { -1, -1, 52, 67, "NEdgevectorList",
  "Reduce_Angle", "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo qp_emlrtBCI = { -1, -1, 52, 42, "NEdgevectorList",
  "Reduce_Angle", "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo rp_emlrtBCI = { -1, -1, 49, 23, "Sina", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo sp_emlrtBCI = { -1, -1, 47, 96, "Sina", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo tp_emlrtBCI = { -1, -1, 47, 75, "NEdgevectorList",
  "Reduce_Angle", "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo up_emlrtBCI = { -1, -1, 47, 52, "NEdgevectorList",
  "Reduce_Angle", "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo vp_emlrtBCI = { -1, -1, 47, 28, "Point", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo wp_emlrtBCI = { -1, -1, 46, 19, "Sina", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtRTEInfo kc_emlrtRTEI = { 45, 1, "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m" };

static emlrtBCInfo xp_emlrtBCI = { -1, -1, 41, 99, "Sina", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo yp_emlrtBCI = { -1, -1, 41, 78, "NEdgevectorList",
  "Reduce_Angle", "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo aq_emlrtBCI = { -1, -1, 41, 53, "NEdgevectorList",
  "Reduce_Angle", "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo bq_emlrtBCI = { -1, -1, 41, 27, "Point", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo cq_emlrtBCI = { -1, -1, 38, 95, "Cosa", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo dq_emlrtBCI = { -1, -1, 38, 63, "Cosa", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo eq_emlrtBCI = { -1, -1, 38, 28, "Point", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo fq_emlrtBCI = { -1, -1, 37, 95, "Cosa", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo gq_emlrtBCI = { -1, -1, 37, 63, "Cosa", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo hq_emlrtBCI = { -1, -1, 37, 28, "Point", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo iq_emlrtBCI = { -1, -1, 35, 32, "Point", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo jq_emlrtBCI = { -1, -1, 33, 97, "Cosa", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo kq_emlrtBCI = { -1, -1, 33, 65, "Cosa", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo lq_emlrtBCI = { -1, -1, 33, 30, "Point", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo mq_emlrtBCI = { -1, -1, 32, 99, "Cosa", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo nq_emlrtBCI = { -1, -1, 32, 65, "Cosa", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo oq_emlrtBCI = { -1, -1, 32, 30, "Point", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo pq_emlrtBCI = { -1, -1, 29, 63, "NEdgevectorList",
  "Reduce_Angle", "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo qq_emlrtBCI = { -1, -1, 29, 38, "NEdgevectorList",
  "Reduce_Angle", "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo rq_emlrtBCI = { -1, -1, 27, 32, "Cosa", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo sq_emlrtBCI = { -1, -1, 27, 15, "Sina", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo tq_emlrtBCI = { -1, -1, 26, 19, "Sina", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo uq_emlrtBCI = { -1, -1, 24, 94, "Sina", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo vq_emlrtBCI = { -1, -1, 24, 73, "NEdgevectorList",
  "Reduce_Angle", "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo wq_emlrtBCI = { -1, -1, 24, 48, "NEdgevectorList",
  "Reduce_Angle", "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo xq_emlrtBCI = { -1, -1, 24, 22, "Point", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo yq_emlrtBCI = { -1, -1, 23, 15, "Sina", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo ar_emlrtBCI = { -1, -1, 50, 19, "Sina", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo br_emlrtBCI = { -1, -1, 50, 36, "Cosa", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo cr_emlrtBCI = { -1, -1, 55, 34, "Point", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo dr_emlrtBCI = { 1, 100, 55, 15, "P", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo er_emlrtBCI = { -1, -1, 56, 34, "Point", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo fr_emlrtBCI = { 1, 100, 56, 15, "P", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo gr_emlrtBCI = { -1, -1, 60, 32, "Point", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo hr_emlrtBCI = { 1, 100, 60, 15, "P", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo ir_emlrtBCI = { -1, -1, 61, 32, "Point", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

static emlrtBCInfo jr_emlrtBCI = { 1, 100, 61, 15, "P", "Reduce_Angle",
  "D:\\2.AgriMapZoom\\Reduce_Angle.m", 0 };

/* Function Definitions */
void Reduce_Angle(const emlrtStack *sp, const real_T Point_data[], const int32_T
                  Point_size[2], real_T n, real_T L, const emxArray_real_T *Sina,
                  const emxArray_real_T *Cosa, const real_T
                  NEdgevectorList_data[], const int32_T NEdgevectorList_size[2],
                  real_T Theita, real_T P[200], real_T *P_Cnt)
{
  real_T k;
  int32_T i33;
  real_T b_Sina;
  boolean_T guard2 = false;
  real_T p0[2];
  real_T a1;
  real_T a2;
  real_T x;
  real_T b_a1[2];
  int32_T i;
  int32_T i34;
  boolean_T guard1 = false;
  real_T c_a1[2];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /* 对点Point进行去锐角化 */
  /* { */
  /* 输入： */
  /* Point:需要锐角化的边界点集，格式为n乘以2 */
  /* n：Point中点的个数 */
  /* L：外扩的距离单位米 */
  /* Sina：个顶点出的角的sin值 */
  /* Cosa：个顶点出的角的cosa值 */
  /* NEdgevectorList:各边的单位向量 */
  /* Theita：锐角临界值 */
  /* 输出： */
  /* P：经去锐角化的点集，格式为P_Cnt乘以2 */
  /* P_Cnt:经处理后的点集中点的个数 */
  /* } */
  memset(&P[0], 0, 200U * sizeof(real_T));
  *P_Cnt = 0.0;
  k = 0.0;
  i33 = Sina->size[1];
  if (!(1 <= i33)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i33, &yq_emlrtBCI, sp);
  }

  if (muDoubleScalarAbs(Sina->data[0]) > muDoubleScalarSin(Theita * 3.1415926 /
       180.0)) {
    /* 0.3420 */
    if (!(1 <= Point_size[0])) {
      emlrtDynamicBoundsCheckR2012b(1, 1, Point_size[0], &xq_emlrtBCI, sp);
    }

    if (!(1 <= NEdgevectorList_size[0])) {
      emlrtDynamicBoundsCheckR2012b(1, 1, NEdgevectorList_size[0], &wq_emlrtBCI,
        sp);
    }

    i33 = Sina->size[1];
    if (!(1 <= i33)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i33, &uq_emlrtBCI, sp);
    }

    i33 = (int32_T)n;
    if (!((i33 >= 1) && (i33 <= NEdgevectorList_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(i33, 1, NEdgevectorList_size[0],
        &vq_emlrtBCI, sp);
    }

    b_Sina = Sina->data[0];
    for (i33 = 0; i33 < 2; i33++) {
      P[100 * i33] = Point_data[Point_size[0] * i33] -
        (NEdgevectorList_data[NEdgevectorList_size[0] * i33] -
         NEdgevectorList_data[((int32_T)n + NEdgevectorList_size[0] * i33) - 1])
        * L / b_Sina;
    }

    *P_Cnt = 1.0;
  } else {
    i33 = Sina->size[1];
    if (!(1 <= i33)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i33, &tq_emlrtBCI, sp);
    }

    if (muDoubleScalarAbs(Sina->data[0]) <= muDoubleScalarSin(Theita * 3.1415926
         / 180.0)) {
      i33 = Sina->size[1];
      if (!(1 <= i33)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i33, &sq_emlrtBCI, sp);
      }

      guard2 = false;
      if (Sina->data[0] > 0.0) {
        i33 = Cosa->size[1];
        if (!(1 <= i33)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i33, &rq_emlrtBCI, sp);
        }

        if (Cosa->data[0] < 0.0) {
          k = 1.0;
          if (!(1 <= NEdgevectorList_size[0])) {
            emlrtDynamicBoundsCheckR2012b(1, 1, NEdgevectorList_size[0],
              &qq_emlrtBCI, sp);
          }

          i33 = (int32_T)n;
          if (!((i33 >= 1) && (i33 <= NEdgevectorList_size[0]))) {
            emlrtDynamicBoundsCheckR2012b(i33, 1, NEdgevectorList_size[0],
              &pq_emlrtBCI, sp);
          }

          for (i33 = 0; i33 < 2; i33++) {
            p0[i33] = -NEdgevectorList_data[NEdgevectorList_size[0] * i33] +
              NEdgevectorList_data[((int32_T)n + NEdgevectorList_size[0] * i33)
              - 1];
          }

          b_Sina = p0[0] * p0[0] + p0[1] * p0[1];
          st.site = &de_emlrtRSI;
          b_sqrt(&st, &b_Sina);
          a1 = p0[0] / b_Sina;
          st.site = &ee_emlrtRSI;
          b_Sina = p0[0] * p0[0] + p0[1] * p0[1];
          if (b_Sina < 0.0) {
            b_st.site = &o_emlrtRSI;
            error(&b_st);
          }

          a2 = p0[1] / muDoubleScalarSqrt(b_Sina);
          if (!(1 <= Point_size[0])) {
            emlrtDynamicBoundsCheckR2012b(1, 1, Point_size[0], &oq_emlrtBCI, sp);
          }

          i33 = Cosa->size[1];
          if (!(1 <= i33)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i33, &nq_emlrtBCI, sp);
          }

          i33 = Cosa->size[1];
          if (!(1 <= i33)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i33, &mq_emlrtBCI, sp);
          }

          b_Sina = (1.0 + Cosa->data[0]) / 2.0;
          x = (1.0 - Cosa->data[0]) / 2.0;
          st.site = &fe_emlrtRSI;
          if (b_Sina < 0.0) {
            b_st.site = &o_emlrtRSI;
            error(&b_st);
          }

          st.site = &fe_emlrtRSI;
          if (x < 0.0) {
            b_st.site = &o_emlrtRSI;
            error(&b_st);
          }

          P[0] = Point_data[0] + L * (a1 * muDoubleScalarSqrt(b_Sina) - a2 *
            muDoubleScalarSqrt(x));
          if (!(1 <= Point_size[0])) {
            emlrtDynamicBoundsCheckR2012b(1, 1, Point_size[0], &lq_emlrtBCI, sp);
          }

          i33 = Cosa->size[1];
          if (!(1 <= i33)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i33, &kq_emlrtBCI, sp);
          }

          i33 = Cosa->size[1];
          if (!(1 <= i33)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i33, &jq_emlrtBCI, sp);
          }

          b_Sina = (1.0 + Cosa->data[0]) / 2.0;
          x = (1.0 - Cosa->data[0]) / 2.0;
          st.site = &ge_emlrtRSI;
          if (b_Sina < 0.0) {
            b_st.site = &o_emlrtRSI;
            error(&b_st);
          }

          st.site = &ge_emlrtRSI;
          if (x < 0.0) {
            b_st.site = &o_emlrtRSI;
            error(&b_st);
          }

          P[100] = Point_data[Point_size[0]] + L * (a2 * muDoubleScalarSqrt
            (b_Sina) + a1 * muDoubleScalarSqrt(x));
          if (!(1 <= Point_size[0])) {
            emlrtDynamicBoundsCheckR2012b(1, 1, Point_size[0], &iq_emlrtBCI, sp);
          }

          b_a1[0] = a1;
          b_a1[1] = a2;
          for (i33 = 0; i33 < 2; i33++) {
            P[1 + 100 * i33] = Point_data[Point_size[0] * i33] + b_a1[i33] * L;
          }

          if (!(1 <= Point_size[0])) {
            emlrtDynamicBoundsCheckR2012b(1, 1, Point_size[0], &hq_emlrtBCI, sp);
          }

          i33 = Cosa->size[1];
          if (!(1 <= i33)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i33, &gq_emlrtBCI, sp);
          }

          i33 = Cosa->size[1];
          if (!(1 <= i33)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i33, &fq_emlrtBCI, sp);
          }

          b_Sina = (1.0 + Cosa->data[0]) / 2.0;
          x = (1.0 - Cosa->data[0]) / 2.0;
          st.site = &he_emlrtRSI;
          if (b_Sina < 0.0) {
            b_st.site = &o_emlrtRSI;
            error(&b_st);
          }

          st.site = &he_emlrtRSI;
          if (x < 0.0) {
            b_st.site = &o_emlrtRSI;
            error(&b_st);
          }

          P[2] = Point_data[0] + L * (a1 * muDoubleScalarSqrt(b_Sina) + a2 *
            muDoubleScalarSqrt(x));
          if (!(1 <= Point_size[0])) {
            emlrtDynamicBoundsCheckR2012b(1, 1, Point_size[0], &eq_emlrtBCI, sp);
          }

          i33 = Cosa->size[1];
          if (!(1 <= i33)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i33, &dq_emlrtBCI, sp);
          }

          i33 = Cosa->size[1];
          if (!(1 <= i33)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i33, &cq_emlrtBCI, sp);
          }

          b_Sina = (1.0 + Cosa->data[0]) / 2.0;
          x = (1.0 - Cosa->data[0]) / 2.0;
          st.site = &ie_emlrtRSI;
          if (b_Sina < 0.0) {
            b_st.site = &o_emlrtRSI;
            error(&b_st);
          }

          st.site = &ie_emlrtRSI;
          if (x < 0.0) {
            b_st.site = &o_emlrtRSI;
            error(&b_st);
          }

          P[102] = Point_data[Point_size[0]] + L * (a2 * muDoubleScalarSqrt
            (b_Sina) - a1 * muDoubleScalarSqrt(x));
          *P_Cnt = 3.0;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2) {
        if (!(1 <= Point_size[0])) {
          emlrtDynamicBoundsCheckR2012b(1, 1, Point_size[0], &bq_emlrtBCI, sp);
        }

        if (!(1 <= NEdgevectorList_size[0])) {
          emlrtDynamicBoundsCheckR2012b(1, 1, NEdgevectorList_size[0],
            &aq_emlrtBCI, sp);
        }

        i33 = Sina->size[1];
        if (!(1 <= i33)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i33, &xp_emlrtBCI, sp);
        }

        i33 = (int32_T)n;
        if (!((i33 >= 1) && (i33 <= NEdgevectorList_size[0]))) {
          emlrtDynamicBoundsCheckR2012b(i33, 1, NEdgevectorList_size[0],
            &yp_emlrtBCI, sp);
        }

        b_Sina = Sina->data[0];
        for (i33 = 0; i33 < 2; i33++) {
          P[100 * i33] = Point_data[Point_size[0] * i33] -
            (NEdgevectorList_data[NEdgevectorList_size[0] * i33] -
             NEdgevectorList_data[((int32_T)n + NEdgevectorList_size[0] * i33) -
             1]) * L / b_Sina;
        }

        *P_Cnt = 1.0;
      }
    }
  }

  emlrtForLoopVectorCheckR2012b(2.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)(n + -1.0),
    &kc_emlrtRTEI, sp);
  i = 0;
  while (i <= (int32_T)(n + -1.0) - 1) {
    i33 = Sina->size[1];
    i34 = (int32_T)(2.0 + (real_T)i);
    if (!((i34 >= 1) && (i34 <= i33))) {
      emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &wp_emlrtBCI, sp);
    }

    if (muDoubleScalarAbs(Sina->data[Sina->size[0] * (i + 1)]) >
        muDoubleScalarSin(Theita * 3.1415926 / 180.0)) {
      i33 = (int32_T)(2.0 + (real_T)i);
      if (!((i33 >= 1) && (i33 <= NEdgevectorList_size[0]))) {
        emlrtDynamicBoundsCheckR2012b(i33, 1, NEdgevectorList_size[0],
          &up_emlrtBCI, sp);
      }

      i33 = (int32_T)((2.0 + (real_T)i) - 1.0);
      if (!((i33 >= 1) && (i33 <= NEdgevectorList_size[0]))) {
        emlrtDynamicBoundsCheckR2012b(i33, 1, NEdgevectorList_size[0],
          &tp_emlrtBCI, sp);
      }

      i33 = Sina->size[1];
      i34 = (int32_T)(2.0 + (real_T)i);
      if (!((i34 >= 1) && (i34 <= i33))) {
        emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &sp_emlrtBCI, sp);
      }

      i33 = (int32_T)(2.0 + (real_T)i);
      if (!((i33 >= 1) && (i33 <= Point_size[0]))) {
        emlrtDynamicBoundsCheckR2012b(i33, 1, Point_size[0], &vp_emlrtBCI, sp);
      }

      b_Sina = Sina->data[Sina->size[0] * (i + 1)];
      i33 = (int32_T)((2.0 + (real_T)i) + 2.0 * k);
      if (!((i33 >= 1) && (i33 <= 100))) {
        emlrtDynamicBoundsCheckR2012b(i33, 1, 100, &bp_emlrtBCI, sp);
      }

      for (i34 = 0; i34 < 2; i34++) {
        P[(i33 + 100 * i34) - 1] = Point_data[((i + 2) + Point_size[0] * i34) -
          1] - (NEdgevectorList_data[(i + NEdgevectorList_size[0] * i34) + 1] -
                NEdgevectorList_data[((int32_T)((2.0 + (real_T)i) - 1.0) +
                 NEdgevectorList_size[0] * i34) - 1]) * L / b_Sina;
      }

      (*P_Cnt)++;
    } else {
      i33 = Sina->size[1];
      i34 = (int32_T)(2.0 + (real_T)i);
      if (!((i34 >= 1) && (i34 <= i33))) {
        emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &rp_emlrtBCI, sp);
      }

      if (muDoubleScalarAbs(Sina->data[Sina->size[0] * (i + 1)]) <=
          muDoubleScalarSin(Theita * 3.1415926 / 180.0)) {
        i33 = Sina->size[1];
        i34 = (int32_T)(2.0 + (real_T)i);
        if (!((i34 >= 1) && (i34 <= i33))) {
          emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &ar_emlrtBCI, sp);
        }

        guard1 = false;
        if (Sina->data[Sina->size[0] * (i34 - 1)] > 0.0) {
          i33 = Cosa->size[1];
          i34 = (int32_T)(2.0 + (real_T)i);
          if (!((i34 >= 1) && (i34 <= i33))) {
            emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &br_emlrtBCI, sp);
          }

          if (Cosa->data[Cosa->size[0] * (i34 - 1)] < 0.0) {
            k++;
            i33 = (int32_T)(2.0 + (real_T)i);
            if (!((i33 >= 1) && (i33 <= NEdgevectorList_size[0]))) {
              emlrtDynamicBoundsCheckR2012b(i33, 1, NEdgevectorList_size[0],
                &qp_emlrtBCI, sp);
            }

            i33 = (int32_T)((2.0 + (real_T)i) - 1.0);
            if (!((i33 >= 1) && (i33 <= NEdgevectorList_size[0]))) {
              emlrtDynamicBoundsCheckR2012b(i33, 1, NEdgevectorList_size[0],
                &pp_emlrtBCI, sp);
            }

            for (i33 = 0; i33 < 2; i33++) {
              p0[i33] = -NEdgevectorList_data[((i + 2) + NEdgevectorList_size[0]
                * i33) - 1] + NEdgevectorList_data[((int32_T)((2.0 + (real_T)i)
                - 1.0) + NEdgevectorList_size[0] * i33) - 1];
            }

            st.site = &je_emlrtRSI;
            b_Sina = p0[0] * p0[0] + p0[1] * p0[1];
            if (b_Sina < 0.0) {
              b_st.site = &o_emlrtRSI;
              error(&b_st);
            }

            a1 = p0[0] / muDoubleScalarSqrt(b_Sina);
            st.site = &ke_emlrtRSI;
            b_Sina = p0[0] * p0[0] + p0[1] * p0[1];
            if (b_Sina < 0.0) {
              b_st.site = &o_emlrtRSI;
              error(&b_st);
            }

            a2 = p0[1] / muDoubleScalarSqrt(b_Sina);
            i33 = Cosa->size[1];
            i34 = (int32_T)(2.0 + (real_T)i);
            if (!((i34 >= 1) && (i34 <= i33))) {
              emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &op_emlrtBCI, sp);
            }

            b_Sina = (1.0 + Cosa->data[Cosa->size[0] * (i + 1)]) / 2.0;
            i33 = Cosa->size[1];
            i34 = (int32_T)(2.0 + (real_T)i);
            if (!((i34 >= 1) && (i34 <= i33))) {
              emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &np_emlrtBCI, sp);
            }

            x = (1.0 - Cosa->data[Cosa->size[0] * (i + 1)]) / 2.0;
            st.site = &le_emlrtRSI;
            if (b_Sina < 0.0) {
              b_st.site = &o_emlrtRSI;
              error(&b_st);
            }

            st.site = &le_emlrtRSI;
            if (x < 0.0) {
              b_st.site = &o_emlrtRSI;
              error(&b_st);
            }

            i33 = (int32_T)(2.0 + (real_T)i);
            if (!((i33 >= 1) && (i33 <= Point_size[0]))) {
              emlrtDynamicBoundsCheckR2012b(i33, 1, Point_size[0], &cr_emlrtBCI,
                sp);
            }

            i34 = (int32_T)(((2.0 + (real_T)i) + 2.0 * k) - 2.0);
            if (!((i34 >= 1) && (i34 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i34, 1, 100, &dr_emlrtBCI, sp);
            }

            P[i34 - 1] = Point_data[i33 - 1] + L * (a1 * muDoubleScalarSqrt
              (b_Sina) - a2 * muDoubleScalarSqrt(x));
            i33 = Cosa->size[1];
            i34 = (int32_T)(2.0 + (real_T)i);
            if (!((i34 >= 1) && (i34 <= i33))) {
              emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &mp_emlrtBCI, sp);
            }

            b_Sina = (1.0 + Cosa->data[Cosa->size[0] * (i + 1)]) / 2.0;
            i33 = Cosa->size[1];
            i34 = (int32_T)(2.0 + (real_T)i);
            if (!((i34 >= 1) && (i34 <= i33))) {
              emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &lp_emlrtBCI, sp);
            }

            x = (1.0 - Cosa->data[Cosa->size[0] * (i + 1)]) / 2.0;
            st.site = &me_emlrtRSI;
            if (b_Sina < 0.0) {
              b_st.site = &o_emlrtRSI;
              error(&b_st);
            }

            st.site = &me_emlrtRSI;
            if (x < 0.0) {
              b_st.site = &o_emlrtRSI;
              error(&b_st);
            }

            i33 = (int32_T)(2.0 + (real_T)i);
            if (!((i33 >= 1) && (i33 <= Point_size[0]))) {
              emlrtDynamicBoundsCheckR2012b(i33, 1, Point_size[0], &er_emlrtBCI,
                sp);
            }

            i34 = (int32_T)(((2.0 + (real_T)i) + 2.0 * k) - 2.0);
            if (!((i34 >= 1) && (i34 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i34, 1, 100, &fr_emlrtBCI, sp);
            }

            P[i34 + 99] = Point_data[(i33 + Point_size[0]) - 1] + L * (a2 *
              muDoubleScalarSqrt(b_Sina) + a1 * muDoubleScalarSqrt(x));
            i33 = (int32_T)(2.0 + (real_T)i);
            if (!((i33 >= 1) && (i33 <= Point_size[0]))) {
              emlrtDynamicBoundsCheckR2012b(i33, 1, Point_size[0], &kp_emlrtBCI,
                sp);
            }

            c_a1[0] = a1;
            c_a1[1] = a2;
            i33 = (int32_T)(((2.0 + (real_T)i) + 2.0 * k) - 1.0);
            if (!((i33 >= 1) && (i33 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i33, 1, 100, &ap_emlrtBCI, sp);
            }

            for (i34 = 0; i34 < 2; i34++) {
              P[(i33 + 100 * i34) - 1] = Point_data[((i + 2) + Point_size[0] *
                i34) - 1] + c_a1[i34] * L;
            }

            i33 = Cosa->size[1];
            i34 = (int32_T)(2.0 + (real_T)i);
            if (!((i34 >= 1) && (i34 <= i33))) {
              emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &jp_emlrtBCI, sp);
            }

            b_Sina = (1.0 + Cosa->data[Cosa->size[0] * (i + 1)]) / 2.0;
            i33 = Cosa->size[1];
            i34 = (int32_T)(2.0 + (real_T)i);
            if (!((i34 >= 1) && (i34 <= i33))) {
              emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &ip_emlrtBCI, sp);
            }

            x = (1.0 - Cosa->data[Cosa->size[0] * (i + 1)]) / 2.0;
            st.site = &ne_emlrtRSI;
            if (b_Sina < 0.0) {
              b_st.site = &o_emlrtRSI;
              error(&b_st);
            }

            st.site = &ne_emlrtRSI;
            if (x < 0.0) {
              b_st.site = &o_emlrtRSI;
              error(&b_st);
            }

            i33 = (int32_T)(2.0 + (real_T)i);
            if (!((i33 >= 1) && (i33 <= Point_size[0]))) {
              emlrtDynamicBoundsCheckR2012b(i33, 1, Point_size[0], &gr_emlrtBCI,
                sp);
            }

            i34 = (int32_T)((2.0 + (real_T)i) + 2.0 * k);
            if (!((i34 >= 1) && (i34 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i34, 1, 100, &hr_emlrtBCI, sp);
            }

            P[i34 - 1] = Point_data[i33 - 1] + L * (a1 * muDoubleScalarSqrt
              (b_Sina) + a2 * muDoubleScalarSqrt(x));
            i33 = Cosa->size[1];
            i34 = (int32_T)(2.0 + (real_T)i);
            if (!((i34 >= 1) && (i34 <= i33))) {
              emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &hp_emlrtBCI, sp);
            }

            b_Sina = (1.0 + Cosa->data[Cosa->size[0] * (i + 1)]) / 2.0;
            i33 = Cosa->size[1];
            i34 = (int32_T)(2.0 + (real_T)i);
            if (!((i34 >= 1) && (i34 <= i33))) {
              emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &gp_emlrtBCI, sp);
            }

            x = (1.0 - Cosa->data[Cosa->size[0] * (i + 1)]) / 2.0;
            st.site = &oe_emlrtRSI;
            if (b_Sina < 0.0) {
              b_st.site = &o_emlrtRSI;
              error(&b_st);
            }

            st.site = &oe_emlrtRSI;
            if (x < 0.0) {
              b_st.site = &o_emlrtRSI;
              error(&b_st);
            }

            i33 = (int32_T)(2.0 + (real_T)i);
            if (!((i33 >= 1) && (i33 <= Point_size[0]))) {
              emlrtDynamicBoundsCheckR2012b(i33, 1, Point_size[0], &ir_emlrtBCI,
                sp);
            }

            i34 = (int32_T)((2.0 + (real_T)i) + 2.0 * k);
            if (!((i34 >= 1) && (i34 <= 100))) {
              emlrtDynamicBoundsCheckR2012b(i34, 1, 100, &jr_emlrtBCI, sp);
            }

            P[i34 + 99] = Point_data[(i33 + Point_size[0]) - 1] + L * (a2 *
              muDoubleScalarSqrt(b_Sina) - a1 * muDoubleScalarSqrt(x));
            *P_Cnt += 3.0;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          i33 = (int32_T)(2.0 + (real_T)i);
          if (!((i33 >= 1) && (i33 <= NEdgevectorList_size[0]))) {
            emlrtDynamicBoundsCheckR2012b(i33, 1, NEdgevectorList_size[0],
              &ep_emlrtBCI, sp);
          }

          i33 = (int32_T)((2.0 + (real_T)i) - 1.0);
          if (!((i33 >= 1) && (i33 <= NEdgevectorList_size[0]))) {
            emlrtDynamicBoundsCheckR2012b(i33, 1, NEdgevectorList_size[0],
              &dp_emlrtBCI, sp);
          }

          i33 = Sina->size[1];
          i34 = (int32_T)(2.0 + (real_T)i);
          if (!((i34 >= 1) && (i34 <= i33))) {
            emlrtDynamicBoundsCheckR2012b(i34, 1, i33, &cp_emlrtBCI, sp);
          }

          i33 = (int32_T)(2.0 + (real_T)i);
          if (!((i33 >= 1) && (i33 <= Point_size[0]))) {
            emlrtDynamicBoundsCheckR2012b(i33, 1, Point_size[0], &fp_emlrtBCI,
              sp);
          }

          b_Sina = Sina->data[Sina->size[0] * (i + 1)];
          i33 = (int32_T)((2.0 + (real_T)i) + 2.0 * k);
          if (!((i33 >= 1) && (i33 <= 100))) {
            emlrtDynamicBoundsCheckR2012b(i33, 1, 100, &yo_emlrtBCI, sp);
          }

          for (i34 = 0; i34 < 2; i34++) {
            P[(i33 + 100 * i34) - 1] = Point_data[((i + 2) + Point_size[0] * i34)
              - 1] - (NEdgevectorList_data[(i + NEdgevectorList_size[0] * i34) +
                      1] - NEdgevectorList_data[((int32_T)((2.0 + (real_T)i) -
                        1.0) + NEdgevectorList_size[0] * i34) - 1]) * L / b_Sina;
          }

          (*P_Cnt)++;
        }
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

/* End of code generation (Reduce_Angle.c) */
