/*
 * Calculate_New_Indented_Boundary_Point.c
 *
 * Code generation for function 'Calculate_New_Indented_Boundary_Point'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "Calculate_New_Indented_Boundary_Point.h"
#include "flipud.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "CalculateLineCrossover.h"
#include "Judge_Intersect.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtRSInfo v_emlrtRSI = { 35, "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m" };

static emlrtRSInfo w_emlrtRSI = { 45, "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m" };

static emlrtRTEInfo h_emlrtRTEI = { 1, 36,
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m" };

static emlrtRTEInfo i_emlrtRTEI = { 14, 1,
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m" };

static emlrtBCInfo be_emlrtBCI = { -1, -1, 15, 37, "Point",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtRTEInfo tb_emlrtRTEI = { 19, 1,
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m" };

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 15, 9, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtECInfo p_emlrtECI = { -1, 15, 1,
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m" };

static emlrtBCInfo de_emlrtBCI = { -1, -1, 22, 26, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtRTEInfo ub_emlrtRTEI = { 28, 1,
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m" };

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 31, 49, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo fe_emlrtBCI = { -1, -1, 31, 62, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo ge_emlrtBCI = { -1, -1, 31, 75, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo he_emlrtBCI = { -1, -1, 31, 90, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo ie_emlrtBCI = { -1, -1, 31, 105, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo je_emlrtBCI = { -1, -1, 31, 118, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo ke_emlrtBCI = { -1, -1, 31, 131, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo le_emlrtBCI = { -1, -1, 31, 146, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo me_emlrtBCI = { -1, -1, 41, 49, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo ne_emlrtBCI = { -1, -1, 41, 62, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo oe_emlrtBCI = { -1, -1, 41, 75, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo pe_emlrtBCI = { -1, -1, 41, 88, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo qe_emlrtBCI = { -1, -1, 41, 101, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo re_emlrtBCI = { -1, -1, 41, 114, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo se_emlrtBCI = { -1, -1, 41, 127, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo te_emlrtBCI = { -1, -1, 41, 142, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo ue_emlrtBCI = { -1, -1, 45, 92, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo ve_emlrtBCI = { -1, -1, 45, 105, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo we_emlrtBCI = { 1, 50, 34, 20, "PP",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo xe_emlrtBCI = { 1, 50, 44, 20, "PP",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo ye_emlrtBCI = { 1, 100, 20, 9, "PPP",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo af_emlrtBCI = { -1, -1, 45, 66, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo bf_emlrtBCI = { -1, -1, 45, 79, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo cf_emlrtBCI = { -1, -1, 45, 118, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo df_emlrtBCI = { -1, -1, 45, 131, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo ef_emlrtBCI = { -1, -1, 45, 144, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo ff_emlrtBCI = { -1, -1, 45, 159, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo gf_emlrtBCI = { -1, -1, 35, 66, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo hf_emlrtBCI = { -1, -1, 35, 79, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo if_emlrtBCI = { -1, -1, 35, 92, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo jf_emlrtBCI = { -1, -1, 35, 107, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo kf_emlrtBCI = { -1, -1, 35, 122, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo lf_emlrtBCI = { -1, -1, 35, 135, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo mf_emlrtBCI = { -1, -1, 35, 148, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

static emlrtBCInfo nf_emlrtBCI = { -1, -1, 35, 163, "Pointss",
  "Calculate_New_Indented_Boundary_Point",
  "D:\\2.AgriMapZoom\\Calculate_New_Indented_Boundary_Point.m", 0 };

/* Function Definitions */
void c_Calculate_New_Indented_Bounda(const emlrtStack *sp, const real_T
  Point_data[], const int32_T Point_size[2], real_T P_Cnt, real_T PP[350],
  real_T *PP_Cnt, real_T PPP[700], real_T *PPP_Cnt)
{
  emxArray_real_T *Pointss;
  int32_T i7;
  int32_T loop_ub;
  int32_T b_loop_ub;
  emxArray_int32_T *r2;
  int32_T tmp_size[2];
  int32_T i8;
  real_T tmp_data[510];
  int32_T iv12[2];
  int32_T i;
  int32_T k;
  int32_T j;
  static const int8_T iv13[3] = { 0, 0, 1 };

  int32_T i9;
  int32_T i10;
  int32_T i11;
  real_T dv2[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &Pointss, 2, &i_emlrtRTEI, true);

  /* { */
  /* 输入： */
  /* Point:内缩后的点集，格式为P_Cnt乘以2的矩阵 */
  /* P_Cnt:点的数量 */
  /* 输出： */
  /* PP：各边的交点集，格式为n乘以7的矩阵 */
  /* PPP：各边的顶点集，格式为n乘以7的矩阵 */
  /* } */
  *PPP_Cnt = P_Cnt;
  i7 = Pointss->size[0] * Pointss->size[1];
  Pointss->size[0] = (int32_T)P_Cnt;
  Pointss->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)Pointss, i7, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  loop_ub = (int32_T)P_Cnt << 1;
  for (i7 = 0; i7 < loop_ub; i7++) {
    Pointss->data[i7] = 0.0;
  }

  if (1.0 > P_Cnt) {
    loop_ub = 0;
  } else {
    if (!(1 <= Point_size[0])) {
      emlrtDynamicBoundsCheckR2012b(1, 1, Point_size[0], &be_emlrtBCI, sp);
    }

    loop_ub = (int32_T)P_Cnt;
    if (!((loop_ub >= 1) && (loop_ub <= Point_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, Point_size[0], &be_emlrtBCI, sp);
    }
  }

  if (1.0 > P_Cnt) {
    b_loop_ub = 0;
  } else {
    i7 = (int32_T)P_Cnt;
    b_loop_ub = (int32_T)P_Cnt;
    if (!((b_loop_ub >= 1) && (b_loop_ub <= i7))) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i7, &ce_emlrtBCI, sp);
    }
  }

  emxInit_int32_T(sp, &r2, 1, &h_emlrtRTEI, true);
  i7 = r2->size[0];
  r2->size[0] = b_loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)r2, i7, (int32_T)sizeof(int32_T),
                    &h_emlrtRTEI);
  for (i7 = 0; i7 < b_loop_ub; i7++) {
    r2->data[i7] = i7;
  }

  tmp_size[0] = loop_ub;
  tmp_size[1] = 2;
  for (i7 = 0; i7 < 2; i7++) {
    for (i8 = 0; i8 < loop_ub; i8++) {
      tmp_data[i8 + loop_ub * i7] = Point_data[i8 + Point_size[0] * i7];
    }
  }

  flipud(tmp_data, tmp_size);
  iv12[0] = r2->size[0];
  iv12[1] = 2;
  emlrtSubAssignSizeCheckR2012b(iv12, 2, tmp_size, 2, &p_emlrtECI, sp);
  for (i7 = 0; i7 < 2; i7++) {
    loop_ub = tmp_size[0];
    for (i8 = 0; i8 < loop_ub; i8++) {
      Pointss->data[r2->data[i8] + Pointss->size[0] * i7] = tmp_data[i8 +
        tmp_size[0] * i7];
    }
  }

  emxFree_int32_T(&r2);

  /* 倒置变成逆时针 */
  memset(&PPP[0], 0, 700U * sizeof(real_T));

  /* %此处把待处理的点集变成七列的矩阵 */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, P_Cnt, mxDOUBLE_CLASS, (int32_T)P_Cnt,
    &tb_emlrtRTEI, sp);
  i = 0;
  while (i <= (int32_T)P_Cnt - 1) {
    if (!((i + 1 >= 1) && (i + 1 <= 100))) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, 100, &ye_emlrtBCI, sp);
    }

    PPP[i] = 1.0 + (real_T)i;

    /* 原多边形顶点编号：1,2,3....... */
    for (i7 = 0; i7 < 2; i7++) {
      PPP[i + 100 * (1 + i7)] = 0.0;
    }

    /* 第二列放该点是否被访问标记0为没访问，1代表被访问，第三列为是否是交点标记，1为是交点，0为不是交点 */
    i7 = Pointss->size[0];
    if (!((i + 1 >= 1) && (i + 1 <= i7))) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, i7, &de_emlrtBCI, sp);
    }

    b_loop_ub = i + 1;
    for (i7 = 0; i7 < 2; i7++) {
      PPP[i + 100 * (3 + i7)] = Pointss->data[(b_loop_ub + Pointss->size[0] * i7)
        - 1];
    }

    /* 顶点坐标 */
    for (i7 = 0; i7 < 2; i7++) {
      PPP[i + 100 * (5 + i7)] = 0.0;
    }

    /* 第六列存放交点的小序号边的起点，第七咧存放交点的大序号边的起点，其他为零 */
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  memset(&PP[0], 0, 350U * sizeof(real_T));

  /* 用于记录交点信息，8列矩阵 */
  k = -1;

  /* PP为交点集 */
  emlrtForLoopVectorCheckR2012b(3.0, 1.0, P_Cnt, mxDOUBLE_CLASS, (int32_T)(P_Cnt
    + -2.0), &ub_emlrtRTEI, sp);
  i = 0;
  while (i <= (int32_T)(P_Cnt + -2.0) - 1) {
    if (3.0 + (real_T)i < P_Cnt) {
      j = 0;
      while (j <= (int32_T)((3.0 + (real_T)i) - 2.0) - 1) {
        i7 = Pointss->size[0];
        i8 = (int32_T)(3.0 + (real_T)i);
        if (!((i8 >= 1) && (i8 <= i7))) {
          emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &ee_emlrtBCI, sp);
        }

        i7 = Pointss->size[0];
        i8 = (int32_T)(3.0 + (real_T)i);
        if (!((i8 >= 1) && (i8 <= i7))) {
          emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &fe_emlrtBCI, sp);
        }

        i7 = Pointss->size[0];
        i8 = (int32_T)((3.0 + (real_T)i) + 1.0);
        if (!((i8 >= 1) && (i8 <= i7))) {
          emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &ge_emlrtBCI, sp);
        }

        i7 = Pointss->size[0];
        i8 = (int32_T)((3.0 + (real_T)i) + 1.0);
        if (!((i8 >= 1) && (i8 <= i7))) {
          emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &he_emlrtBCI, sp);
        }

        i7 = Pointss->size[0];
        i8 = j + 1;
        if (!((i8 >= 1) && (i8 <= i7))) {
          emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &ie_emlrtBCI, sp);
        }

        i7 = Pointss->size[0];
        i8 = j + 1;
        if (!((i8 >= 1) && (i8 <= i7))) {
          emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &je_emlrtBCI, sp);
        }

        i7 = Pointss->size[0];
        i8 = (int32_T)((1.0 + (real_T)j) + 1.0);
        if (!((i8 >= 1) && (i8 <= i7))) {
          emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &ke_emlrtBCI, sp);
        }

        i7 = Pointss->size[0];
        i8 = (int32_T)((1.0 + (real_T)j) + 1.0);
        if (!((i8 >= 1) && (i8 <= i7))) {
          emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &le_emlrtBCI, sp);
        }

        /* 0为不相交，非零为相交 */
        if (Judge_Intersect(Pointss->data[i + 2], Pointss->data[(i +
              Pointss->size[0]) + 2], Pointss->data[(int32_T)((3.0 + (real_T)i)
              + 1.0) - 1], Pointss->data[((int32_T)((3.0 + (real_T)i) + 1.0) +
              Pointss->size[0]) - 1], Pointss->data[j], Pointss->data[j +
                            Pointss->size[0]], Pointss->data[(int32_T)((1.0 +
               (real_T)j) + 1.0) - 1], Pointss->data[((int32_T)((1.0 + (real_T)j)
               + 1.0) + Pointss->size[0]) - 1]) != 0.0) {
          k++;
          if (!((k + 1 >= 1) && (k + 1 <= 50))) {
            emlrtDynamicBoundsCheckR2012b(k + 1, 1, 50, &we_emlrtBCI, sp);
          }

          for (i7 = 0; i7 < 3; i7++) {
            PP[k + 50 * i7] = iv13[i7];
          }

          /* 序号位为零，访问标记位为0，是否交点位为1； */
          i7 = Pointss->size[0];
          i8 = (int32_T)(3.0 + (real_T)i);
          if (!((i8 >= 1) && (i8 <= i7))) {
            emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &gf_emlrtBCI, sp);
          }

          i7 = Pointss->size[0];
          b_loop_ub = (int32_T)(3.0 + (real_T)i);
          if (!((b_loop_ub >= 1) && (b_loop_ub <= i7))) {
            emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i7, &hf_emlrtBCI, sp);
          }

          i7 = Pointss->size[0];
          loop_ub = (int32_T)((3.0 + (real_T)i) + 1.0);
          if (!((loop_ub >= 1) && (loop_ub <= i7))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, &if_emlrtBCI, sp);
          }

          i7 = Pointss->size[0];
          i9 = (int32_T)((3.0 + (real_T)i) + 1.0);
          if (!((i9 >= 1) && (i9 <= i7))) {
            emlrtDynamicBoundsCheckR2012b(i9, 1, i7, &jf_emlrtBCI, sp);
          }

          i7 = Pointss->size[0];
          if (!((j + 1 >= 1) && (j + 1 <= i7))) {
            emlrtDynamicBoundsCheckR2012b(j + 1, 1, i7, &kf_emlrtBCI, sp);
          }

          i7 = Pointss->size[0];
          if (!((j + 1 >= 1) && (j + 1 <= i7))) {
            emlrtDynamicBoundsCheckR2012b(j + 1, 1, i7, &lf_emlrtBCI, sp);
          }

          i7 = Pointss->size[0];
          i10 = (int32_T)((1.0 + (real_T)j) + 1.0);
          if (!((i10 >= 1) && (i10 <= i7))) {
            emlrtDynamicBoundsCheckR2012b(i10, 1, i7, &mf_emlrtBCI, sp);
          }

          i7 = Pointss->size[0];
          i11 = (int32_T)((1.0 + (real_T)j) + 1.0);
          if (!((i11 >= 1) && (i11 <= i7))) {
            emlrtDynamicBoundsCheckR2012b(i11, 1, i7, &nf_emlrtBCI, sp);
          }

          st.site = &v_emlrtRSI;
          CalculateLineCrossover(&st, Pointss->data[i8 - 1], Pointss->data
            [(b_loop_ub + Pointss->size[0]) - 1], Pointss->data[loop_ub - 1],
            Pointss->data[(i9 + Pointss->size[0]) - 1], Pointss->data[j],
            Pointss->data[j + Pointss->size[0]], Pointss->data[i10 - 1],
            Pointss->data[(i11 + Pointss->size[0]) - 1], dv2);
          for (i7 = 0; i7 < 2; i7++) {
            PP[k + 50 * (3 + i7)] = dv2[i7];
          }

          PP[250 + k] = 1.0 + (real_T)j;
          PP[300 + k] = 3.0 + (real_T)i;
        }

        j++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }
    } else {
      j = 0;
      while (j <= (int32_T)(((3.0 + (real_T)i) - 2.0) + -1.0) - 1) {
        i7 = Pointss->size[0];
        if (!(1 <= i7)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i7, &oe_emlrtBCI, sp);
        }

        i7 = Pointss->size[0];
        if (!(1 <= i7)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i7, &pe_emlrtBCI, sp);
        }

        i7 = Pointss->size[0];
        i8 = (int32_T)(3.0 + (real_T)i);
        if (!((i8 >= 1) && (i8 <= i7))) {
          emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &me_emlrtBCI, sp);
        }

        i7 = Pointss->size[0];
        i8 = (int32_T)(3.0 + (real_T)i);
        if (!((i8 >= 1) && (i8 <= i7))) {
          emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &ne_emlrtBCI, sp);
        }

        i7 = Pointss->size[0];
        i8 = (int32_T)(2.0 + (real_T)j);
        if (!((i8 >= 1) && (i8 <= i7))) {
          emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &qe_emlrtBCI, sp);
        }

        i7 = Pointss->size[0];
        i8 = (int32_T)(2.0 + (real_T)j);
        if (!((i8 >= 1) && (i8 <= i7))) {
          emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &re_emlrtBCI, sp);
        }

        i7 = Pointss->size[0];
        i8 = (int32_T)((2.0 + (real_T)j) + 1.0);
        if (!((i8 >= 1) && (i8 <= i7))) {
          emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &se_emlrtBCI, sp);
        }

        i7 = Pointss->size[0];
        i8 = (int32_T)((2.0 + (real_T)j) + 1.0);
        if (!((i8 >= 1) && (i8 <= i7))) {
          emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &te_emlrtBCI, sp);
        }

        /* 0为不相交，非零为相交 */
        if (Judge_Intersect(Pointss->data[i + 2], Pointss->data[(i +
              Pointss->size[0]) + 2], Pointss->data[0], Pointss->data
                            [Pointss->size[0]], Pointss->data[j + 1],
                            Pointss->data[(j + Pointss->size[0]) + 1],
                            Pointss->data[(int32_T)((2.0 + (real_T)j) + 1.0) - 1],
                            Pointss->data[((int32_T)((2.0 + (real_T)j) + 1.0) +
              Pointss->size[0]) - 1]) != 0.0) {
          k++;
          if (!((k + 1 >= 1) && (k + 1 <= 50))) {
            emlrtDynamicBoundsCheckR2012b(k + 1, 1, 50, &xe_emlrtBCI, sp);
          }

          for (i7 = 0; i7 < 3; i7++) {
            PP[k + 50 * i7] = iv13[i7];
          }

          /* 序号位为零，访问标记位为0，是否交点位为1； */
          i7 = Pointss->size[0];
          if (!(1 <= i7)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i7, &ue_emlrtBCI, sp);
          }

          i7 = Pointss->size[0];
          if (!(1 <= i7)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i7, &ve_emlrtBCI, sp);
          }

          i7 = Pointss->size[0];
          i8 = (int32_T)(3.0 + (real_T)i);
          if (!((i8 >= 1) && (i8 <= i7))) {
            emlrtDynamicBoundsCheckR2012b(i8, 1, i7, &af_emlrtBCI, sp);
          }

          i7 = Pointss->size[0];
          b_loop_ub = (int32_T)(3.0 + (real_T)i);
          if (!((b_loop_ub >= 1) && (b_loop_ub <= i7))) {
            emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i7, &bf_emlrtBCI, sp);
          }

          i7 = Pointss->size[0];
          loop_ub = (int32_T)(2.0 + (real_T)j);
          if (!((loop_ub >= 1) && (loop_ub <= i7))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i7, &cf_emlrtBCI, sp);
          }

          i7 = Pointss->size[0];
          i9 = (int32_T)(2.0 + (real_T)j);
          if (!((i9 >= 1) && (i9 <= i7))) {
            emlrtDynamicBoundsCheckR2012b(i9, 1, i7, &df_emlrtBCI, sp);
          }

          i7 = Pointss->size[0];
          i10 = (int32_T)((2.0 + (real_T)j) + 1.0);
          if (!((i10 >= 1) && (i10 <= i7))) {
            emlrtDynamicBoundsCheckR2012b(i10, 1, i7, &ef_emlrtBCI, sp);
          }

          i7 = Pointss->size[0];
          i11 = (int32_T)((2.0 + (real_T)j) + 1.0);
          if (!((i11 >= 1) && (i11 <= i7))) {
            emlrtDynamicBoundsCheckR2012b(i11, 1, i7, &ff_emlrtBCI, sp);
          }

          st.site = &w_emlrtRSI;
          CalculateLineCrossover(&st, Pointss->data[i8 - 1], Pointss->data
            [(b_loop_ub + Pointss->size[0]) - 1], Pointss->data[0],
            Pointss->data[Pointss->size[0]], Pointss->data[loop_ub - 1],
            Pointss->data[(i9 + Pointss->size[0]) - 1], Pointss->data[i10 - 1],
            Pointss->data[(i11 + Pointss->size[0]) - 1], dv2);
          for (i7 = 0; i7 < 2; i7++) {
            PP[k + 50 * (3 + i7)] = dv2[i7];
          }

          PP[250 + k] = 2.0 + (real_T)j;
          PP[300 + k] = 3.0 + (real_T)i;
        }

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

  emxFree_real_T(&Pointss);
  *PP_Cnt = k + 1;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Calculate_New_Indented_Boundary_Point.c) */
