//
// File: CalculateNewPoint.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "CalculateNewPoint.h"
#include "Preprocess.h"
#include "CalculateLineCrossover.h"
#include "Judge_Intersect.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "Reduce_Angle.h"
#include "CalculateCosa.h"
#include "CalculateSina.h"
#include "NormalizeDPList.h"
#include "DPList.h"

// Function Definitions

//
// {
// 计算外扩后点的边界点
// 输入：
// Point：需要外扩的多边形的边界点，格式为多行两列的矩阵，单位为m
// L：需要外扩的距离，单位为m
// Theita：是否为锐角的划分边界，单位为°
// 输出：
// Points：经过外扩后的多边形的边界点，格式为多行两列的矩阵，单位为m
// Cnt:输出点集有效点的个数
// }
// %
// Arguments    : const double Point_data[]
//                const int Point_size[2]
//                double P_Cnt
//                double L
//                double Theita
//                double Points[200]
//                double *Cnt
// Return Type  : void
//
void CalculateNewPoint(const double Point_data[], const int Point_size[2],
  double P_Cnt, double L, double Theita, double Points[200], double *Cnt)
{
  int loop_ub;
  double b_Point_data[510];
  int b_Point_size[2];
  int i16;
  int i17;
  double Prep_Cnt;
  double Prep_Preprocessing[200];
  double NEdgevectorList[200];
  double Prep_Preprocessing_data[200];
  int Prep_Preprocessing_size[2];
  emxArray_real_T *r7;
  emxArray_real_T b_Prep_Preprocessing_data;
  double NEdgevectorList_data[200];
  int NEdgevectorList_size[2];
  emxArray_real_T b_NEdgevectorList_data;
  emxArray_real_T *Sina;
  emxArray_real_T *Cosa;
  double c_NEdgevectorList_data[200];
  int b_NEdgevectorList_size[2];
  emxArray_real_T *r8;
  emxArray_real_T d_NEdgevectorList_data;
  double e_NEdgevectorList_data[200];
  int c_NEdgevectorList_size[2];
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  double c_Prep_Preprocessing_data[200];
  int b_Prep_Preprocessing_size[2];
  emxArray_real_T *b_Sina;
  emxArray_real_T *b_Cosa;
  int d_NEdgevectorList_size[2];
  double d3;
  double P[200];
  int P_size[2];
  double PD_Cnt;
  double n;
  int tt_j;
  int tt;
  boolean_T exitg1;
  int ff;
  int i;
  boolean_T exitg2;
  boolean_T guard1 = false;
  int j;
  boolean_T exitg3;
  double dv3[2];
  boolean_T exitg4;
  int b_P_size[2];
  if (1.0 > P_Cnt) {
    loop_ub = 0;
  } else {
    loop_ub = (int)P_Cnt;
  }

  b_Point_size[0] = loop_ub;
  b_Point_size[1] = 2;
  for (i16 = 0; i16 < 2; i16++) {
    for (i17 = 0; i17 < loop_ub; i17++) {
      b_Point_data[i17 + loop_ub * i16] = Point_data[i17 + Point_size[0] * i16];
    }
  }

  Preprocess(b_Point_data, b_Point_size, P_Cnt, Prep_Preprocessing, &Prep_Cnt);

  // 对数据进行除重和删除同一点操作；
  memset(&NEdgevectorList[0], 0, 200U * sizeof(double));
  if (1.0 > Prep_Cnt) {
    loop_ub = 0;
  } else {
    loop_ub = (int)Prep_Cnt;
  }

  Prep_Preprocessing_size[0] = loop_ub;
  Prep_Preprocessing_size[1] = 2;
  for (i16 = 0; i16 < 2; i16++) {
    for (i17 = 0; i17 < loop_ub; i17++) {
      Prep_Preprocessing_data[i17 + Prep_Preprocessing_size[0] * i16] =
        Prep_Preprocessing[i17 + 100 * i16];
    }
  }

  emxInit_real_T(&r7, 2);
  b_Prep_Preprocessing_data.data = (double *)&Prep_Preprocessing_data;
  b_Prep_Preprocessing_data.size = (int *)&Prep_Preprocessing_size;
  b_Prep_Preprocessing_data.allocatedSize = 200;
  b_Prep_Preprocessing_data.numDimensions = 2;
  b_Prep_Preprocessing_data.canFreeData = false;
  DPList(&b_Prep_Preprocessing_data, Prep_Cnt, r7);
  for (i16 = 0; i16 < 2; i16++) {
    loop_ub = r7->size[0];
    for (i17 = 0; i17 < loop_ub; i17++) {
      NEdgevectorList[i17 + 100 * i16] = r7->data[i17 + r7->size[0] * i16];
    }
  }

  if (1.0 > Prep_Cnt) {
    loop_ub = 0;
  } else {
    loop_ub = (int)Prep_Cnt;
  }

  NEdgevectorList_size[0] = loop_ub;
  NEdgevectorList_size[1] = 2;
  for (i16 = 0; i16 < 2; i16++) {
    for (i17 = 0; i17 < loop_ub; i17++) {
      NEdgevectorList_data[i17 + NEdgevectorList_size[0] * i16] =
        NEdgevectorList[i17 + 100 * i16];
    }
  }

  b_NEdgevectorList_data.data = (double *)&NEdgevectorList_data;
  b_NEdgevectorList_data.size = (int *)&NEdgevectorList_size;
  b_NEdgevectorList_data.allocatedSize = 200;
  b_NEdgevectorList_data.numDimensions = 2;
  b_NEdgevectorList_data.canFreeData = false;
  NormalizeDPList(&b_NEdgevectorList_data, Prep_Cnt, r7);
  for (i16 = 0; i16 < 2; i16++) {
    loop_ub = r7->size[0];
    for (i17 = 0; i17 < loop_ub; i17++) {
      NEdgevectorList[i17 + 100 * i16] = r7->data[i17 + r7->size[0] * i16];
    }
  }

  emxFree_real_T(&r7);
  emxInit_real_T(&Sina, 2);

  // 单位向量
  i16 = Sina->size[0] * Sina->size[1];
  Sina->size[0] = 1;
  Sina->size[1] = (int)Prep_Cnt;
  emxEnsureCapacity((emxArray__common *)Sina, i16, (int)sizeof(double));
  loop_ub = (int)Prep_Cnt;
  for (i16 = 0; i16 < loop_ub; i16++) {
    Sina->data[i16] = 0.0;
  }

  emxInit_real_T(&Cosa, 2);
  i16 = Cosa->size[0] * Cosa->size[1];
  Cosa->size[0] = 1;
  Cosa->size[1] = (int)Prep_Cnt;
  emxEnsureCapacity((emxArray__common *)Cosa, i16, (int)sizeof(double));
  loop_ub = (int)Prep_Cnt;
  for (i16 = 0; i16 < loop_ub; i16++) {
    Cosa->data[i16] = 0.0;
  }

  if (1.0 > Prep_Cnt) {
    loop_ub = 0;
  } else {
    loop_ub = (int)Prep_Cnt;
  }

  b_NEdgevectorList_size[0] = loop_ub;
  b_NEdgevectorList_size[1] = 2;
  for (i16 = 0; i16 < 2; i16++) {
    for (i17 = 0; i17 < loop_ub; i17++) {
      c_NEdgevectorList_data[i17 + b_NEdgevectorList_size[0] * i16] =
        NEdgevectorList[i17 + 100 * i16];
    }
  }

  emxInit_real_T(&r8, 2);
  d_NEdgevectorList_data.data = (double *)&c_NEdgevectorList_data;
  d_NEdgevectorList_data.size = (int *)&b_NEdgevectorList_size;
  d_NEdgevectorList_data.allocatedSize = 200;
  d_NEdgevectorList_data.numDimensions = 2;
  d_NEdgevectorList_data.canFreeData = false;
  CalculateSina(&d_NEdgevectorList_data, Prep_Cnt, r8);
  loop_ub = r8->size[1];
  for (i16 = 0; i16 < loop_ub; i16++) {
    Sina->data[Sina->size[0] * i16] = r8->data[r8->size[0] * i16];
  }

  if (1.0 > Prep_Cnt) {
    loop_ub = 0;
  } else {
    loop_ub = (int)Prep_Cnt;
  }

  c_NEdgevectorList_size[0] = loop_ub;
  c_NEdgevectorList_size[1] = 2;
  for (i16 = 0; i16 < 2; i16++) {
    for (i17 = 0; i17 < loop_ub; i17++) {
      e_NEdgevectorList_data[i17 + loop_ub * i16] = NEdgevectorList[i17 + 100 *
        i16];
    }
  }

  CalculateCosa(e_NEdgevectorList_data, c_NEdgevectorList_size, Prep_Cnt, r8);
  loop_ub = r8->size[1];
  for (i16 = 0; i16 < loop_ub; i16++) {
    Cosa->data[Cosa->size[0] * i16] = r8->data[r8->size[0] * i16];
  }

  emxFree_real_T(&r8);
  if (1.0 > Prep_Cnt) {
    loop_ub = 0;
  } else {
    loop_ub = (int)Prep_Cnt;
  }

  if (1.0 > Prep_Cnt) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = (int)Prep_Cnt;
  }

  if (1.0 > Prep_Cnt) {
    c_loop_ub = 0;
  } else {
    c_loop_ub = (int)Prep_Cnt;
  }

  if (1.0 > Prep_Cnt) {
    d_loop_ub = 0;
  } else {
    d_loop_ub = (int)Prep_Cnt;
  }

  b_Prep_Preprocessing_size[0] = loop_ub;
  b_Prep_Preprocessing_size[1] = 2;
  for (i16 = 0; i16 < 2; i16++) {
    for (i17 = 0; i17 < loop_ub; i17++) {
      c_Prep_Preprocessing_data[i17 + loop_ub * i16] = Prep_Preprocessing[i17 +
        100 * i16];
    }
  }

  emxInit_real_T(&b_Sina, 2);
  i16 = b_Sina->size[0] * b_Sina->size[1];
  b_Sina->size[0] = 1;
  b_Sina->size[1] = b_loop_ub;
  emxEnsureCapacity((emxArray__common *)b_Sina, i16, (int)sizeof(double));
  for (i16 = 0; i16 < b_loop_ub; i16++) {
    b_Sina->data[b_Sina->size[0] * i16] = Sina->data[Sina->size[0] * i16];
  }

  emxFree_real_T(&Sina);
  emxInit_real_T(&b_Cosa, 2);
  i16 = b_Cosa->size[0] * b_Cosa->size[1];
  b_Cosa->size[0] = 1;
  b_Cosa->size[1] = c_loop_ub;
  emxEnsureCapacity((emxArray__common *)b_Cosa, i16, (int)sizeof(double));
  for (i16 = 0; i16 < c_loop_ub; i16++) {
    b_Cosa->data[b_Cosa->size[0] * i16] = Cosa->data[Cosa->size[0] * i16];
  }

  emxFree_real_T(&Cosa);
  d_NEdgevectorList_size[0] = d_loop_ub;
  d_NEdgevectorList_size[1] = 2;
  for (i16 = 0; i16 < 2; i16++) {
    for (i17 = 0; i17 < d_loop_ub; i17++) {
      e_NEdgevectorList_data[i17 + d_loop_ub * i16] = NEdgevectorList[i17 + 100 *
        i16];
    }
  }

  Reduce_Angle(c_Prep_Preprocessing_data, b_Prep_Preprocessing_size, Prep_Cnt, L,
               b_Sina, b_Cosa, e_NEdgevectorList_data, d_NEdgevectorList_size,
               Theita, P, &d3);

  // %
  emxFree_real_T(&b_Cosa);
  emxFree_real_T(&b_Sina);
  if (1.0 > d3) {
    loop_ub = 0;
  } else {
    loop_ub = (int)d3;
  }

  P_size[0] = loop_ub;
  P_size[1] = 2;
  for (i16 = 0; i16 < 2; i16++) {
    for (i17 = 0; i17 < loop_ub; i17++) {
      e_NEdgevectorList_data[i17 + loop_ub * i16] = P[i17 + 100 * i16];
    }
  }

  Preprocess(e_NEdgevectorList_data, P_size, d3, Prep_Preprocessing, &Prep_Cnt);
  PD_Cnt = Prep_Cnt;
  for (i16 = 0; i16 < 200; i16++) {
    P[i16] = Prep_Preprocessing[i16];
    Points[i16] = 0.0;
  }

  *Cnt = 0.0;
  n = Prep_Cnt;

  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
  // {
  // P(PD_Cnt(1,1)+1,1:2) = P(1,1:2);
  // subplot(1,2,1);
  // plot(P(1:PD_Cnt(1,1)+1,1).',P(1:PD_Cnt(1,1)+1,2).','ro-');
  // title('未删除无效环');
  // xlabel('x');
  // ylabel('y');
  // grid;
  // }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%10.9%%%%%%%%%%%%%%%%%%%%%%%%%%% 
  // [Points(1:100,1:2),Cnt(1,1)] = Calculate_Effective_Point(P(1:PD_Cnt(1,1),1:2),PD_Cnt(1,1)); 
  // %
  // 以下是保留边界点的循环
  tt_j = 0;
  tt = 1;
  exitg1 = false;
  while ((!exitg1) && (tt == 1)) {
    if (n < 4.0) {
      memcpy(&Points[0], &P[0], 200U * sizeof(double));
      *Cnt = PD_Cnt;
      exitg1 = true;
    } else {
      ff = 0;
      i = 0;
      exitg2 = false;
      while ((!exitg2) && (i <= (int)(n + -2.0) - 1)) {
        memset(&Points[0], 0, 200U * sizeof(double));
        guard1 = false;
        if (3.0 + (double)i < n) {
          j = 0;
          exitg3 = false;
          while ((!exitg3) && (j <= (int)((3.0 + (double)i) - 2.0) - 1)) {
            // 0为不相交，非零为相交
            if (Judge_Intersect(P[i + 2], P[i + 102], P[(int)((3.0 + (double)i)
                  + 1.0) - 1], P[(int)((3.0 + (double)i) + 1.0) + 99], P[j], P
                                [100 + j], P[(int)((1.0 + (double)j) + 1.0) - 1],
                                P[(int)((1.0 + (double)j) + 1.0) + 99]) != 0.0)
            {
              for (i16 = 0; i16 < 2; i16++) {
                for (i17 = 0; i17 <= j; i17++) {
                  Points[i17 + 100 * i16] = P[i17 + 100 * i16];
                }
              }

              CalculateLineCrossover(P[i + 2], P[i + 102], P[(int)((3.0 +
                (double)i) + 1.0) - 1], P[(int)((3.0 + (double)i) + 1.0) + 99],
                P[j], P[100 + j], P[(int)((1.0 + (double)j) + 1.0) - 1], P[(int)
                ((1.0 + (double)j) + 1.0) + 99], dv3);
              for (i16 = 0; i16 < 2; i16++) {
                Points[((int)((1.0 + (double)j) + 1.0) + 100 * i16) - 1] =
                  dv3[i16];
              }

              if ((3.0 + (double)i) + 1.0 > n) {
                i16 = 1;
                i17 = 0;
              } else {
                i16 = (int)((3.0 + (double)i) + 1.0);
                i17 = (int)n;
              }

              if ((1.0 + (double)j) + 2.0 > (((1.0 + (double)j) + 1.0) + n) -
                  (3.0 + (double)i)) {
                b_loop_ub = 0;
              } else {
                b_loop_ub = (int)((1.0 + (double)j) + 2.0) - 1;
              }

              for (c_loop_ub = 0; c_loop_ub < 2; c_loop_ub++) {
                loop_ub = i17 - i16;
                for (d_loop_ub = 0; d_loop_ub <= loop_ub; d_loop_ub++) {
                  Points[(b_loop_ub + d_loop_ub) + 100 * c_loop_ub] = P[((i16 +
                    d_loop_ub) + 100 * c_loop_ub) - 1];
                }
              }

              *Cnt = (((1.0 + (double)j) + 1.0) + n) - (3.0 + (double)i);
              ff = 1;
              if (1.0 + (double)j == n - 3.0) {
                tt_j = 1;
              }

              exitg3 = true;
            } else {
              for (i16 = 0; i16 < 2; i16++) {
                for (i17 = 0; i17 <= j; i17++) {
                  Points[i17 + 100 * i16] = P[i17 + 100 * i16];
                }
              }

              *Cnt = 1.0 + (double)j;
              if (1.0 + (double)j == n - 3.0) {
                // i最多等于n-1,故j最多等于n-3
                for (i16 = 0; i16 < 2; i16++) {
                  for (i17 = 0; i17 < 3; i17++) {
                    Points[((int)((1.0 + (double)j) + (1.0 + (double)i17)) + 100
                            * i16) - 1] = P[((int)(n + (-2.0 + (double)i17)) +
                      100 * i16) - 1];
                  }
                }

                *Cnt = (1.0 + (double)j) + 3.0;
                tt = 0;
              }

              j++;
            }
          }

          if (ff == 1) {
            if (1.0 > *Cnt) {
              loop_ub = -1;
            } else {
              loop_ub = (int)*Cnt - 1;
            }

            for (i16 = 0; i16 < 2; i16++) {
              for (i17 = 0; i17 <= loop_ub; i17++) {
                P[i17 + 100 * i16] = Points[i17 + 100 * i16];
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
          while ((!exitg4) && (j <= (int)(((3.0 + (double)i) - 2.0) + -1.0) - 1))
          {
            // 0为不相交，非零为相交
            if (Judge_Intersect(P[i + 2], P[i + 102], P[0], P[100], P[j + 1],
                                P[j + 101], P[(int)((2.0 + (double)j) + 1.0) - 1],
                                P[(int)((2.0 + (double)j) + 1.0) + 99]) != 0.0)
            {
              loop_ub = (int)(2.0 + (double)j) - 1;
              for (i16 = 0; i16 < 2; i16++) {
                for (i17 = 0; i17 <= loop_ub; i17++) {
                  Points[i17 + 100 * i16] = P[i17 + 100 * i16];
                }
              }

              CalculateLineCrossover(P[i + 2], P[i + 102], P[(int)((3.0 +
                (double)i) + 1.0) - 1], P[(int)((3.0 + (double)i) + 1.0) + 99],
                P[j + 1], P[j + 101], P[(int)((2.0 + (double)j) + 1.0) - 1], P
                [(int)((2.0 + (double)j) + 1.0) + 99], dv3);
              for (i16 = 0; i16 < 2; i16++) {
                Points[((int)((2.0 + (double)j) + 1.0) + 100 * i16) - 1] =
                  dv3[i16];
              }

              // Points(j+2:j+1+n-i,1:2) = P(i+1:n,:);
              *Cnt = (2.0 + (double)j) + 1.0;
              ff = 1;
              if (2.0 + (double)j == n - 2.0) {
                tt_j = 1;
              }

              exitg4 = true;
            } else {
              loop_ub = (int)(2.0 + (double)j) - 1;
              for (i16 = 0; i16 < 2; i16++) {
                for (i17 = 0; i17 <= loop_ub; i17++) {
                  Points[i17 + 100 * i16] = P[i17 + 100 * i16];
                }
              }

              *Cnt = 2.0 + (double)j;
              if (2.0 + (double)j == n - 2.0) {
                // i最多等于n,故j最多等于n-2
                for (i16 = 0; i16 < 2; i16++) {
                  for (i17 = 0; i17 < 2; i17++) {
                    Points[((int)((2.0 + (double)j) + (1.0 + (double)i17)) + 100
                            * i16) - 1] = P[((int)(n + (-1.0 + (double)i17)) +
                      100 * i16) - 1];
                  }
                }

                *Cnt = (2.0 + (double)j) + 2.0;
                tt = 0;
              }

              j++;
            }
          }

          if (ff == 1) {
            if (1.0 > *Cnt) {
              loop_ub = -1;
            } else {
              loop_ub = (int)*Cnt - 1;
            }

            for (i16 = 0; i16 < 2; i16++) {
              for (i17 = 0; i17 <= loop_ub; i17++) {
                P[i17 + 100 * i16] = Points[i17 + 100 * i16];
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
        }
      }

      if (1.0 > PD_Cnt) {
        loop_ub = 0;
      } else {
        loop_ub = (int)PD_Cnt;
      }

      b_P_size[0] = loop_ub;
      b_P_size[1] = 2;
      for (i16 = 0; i16 < 2; i16++) {
        for (i17 = 0; i17 < loop_ub; i17++) {
          e_NEdgevectorList_data[i17 + loop_ub * i16] = P[i17 + 100 * i16];
        }
      }

      Preprocess(e_NEdgevectorList_data, b_P_size, PD_Cnt, Prep_Preprocessing,
                 &Prep_Cnt);
      memcpy(&P[0], &Prep_Preprocessing[0], 200U * sizeof(double));
      PD_Cnt = Prep_Cnt;
      n = Prep_Cnt;
    }
  }
}

//
// File trailer for CalculateNewPoint.cpp
//
// [EOF]
//
