//
// File: Reduce_Angle.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "Reduce_Angle.h"

// Function Definitions

//
// 对点Point进行去锐角化
// {
// 输入：
// Point:需要锐角化的边界点集，格式为n乘以2
// n：Point中点的个数
// L：外扩的距离单位米
// Sina：个顶点出的角的sin值
// Cosa：个顶点出的角的cosa值
// NEdgevectorList:各边的单位向量
// Theita：锐角临界值
// 输出：
// P：经去锐角化的点集，格式为P_Cnt乘以2
// P_Cnt:经处理后的点集中点的个数
// }
// Arguments    : const double Point_data[]
//                const int Point_size[2]
//                double n
//                double L
//                const emxArray_real_T *Sina
//                const emxArray_real_T *Cosa
//                const double NEdgevectorList_data[]
//                const int NEdgevectorList_size[2]
//                double Theita
//                double P[200]
//                double *P_Cnt
// Return Type  : void
//
void Reduce_Angle(const double Point_data[], const int Point_size[2], double n,
                  double L, const emxArray_real_T *Sina, const emxArray_real_T
                  *Cosa, const double NEdgevectorList_data[], const int
                  NEdgevectorList_size[2], double Theita, double P[200], double *
                  P_Cnt)
{
  double k;
  double b_Sina;
  int i19;
  double p0[2];
  double a1;
  double a2;
  double b_a1[2];
  int i;
  int i20;
  double c_a1[2];
  memset(&P[0], 0, 200U * sizeof(double));
  *P_Cnt = 0.0;
  k = 0.0;
  if (fabs(Sina->data[0]) > sin(Theita * 3.1415926 / 180.0)) {
    // 0.3420
    b_Sina = Sina->data[0];
    for (i19 = 0; i19 < 2; i19++) {
      P[100 * i19] = Point_data[Point_size[0] * i19] -
        (NEdgevectorList_data[NEdgevectorList_size[0] * i19] -
         NEdgevectorList_data[((int)n + NEdgevectorList_size[0] * i19) - 1]) * L
        / b_Sina;
    }

    *P_Cnt = 1.0;
  } else {
    if (fabs(Sina->data[0]) <= sin(Theita * 3.1415926 / 180.0)) {
      if ((Sina->data[0] > 0.0) && (Cosa->data[0] < 0.0)) {
        k = 1.0;
        for (i19 = 0; i19 < 2; i19++) {
          p0[i19] = -NEdgevectorList_data[NEdgevectorList_size[0] * i19] +
            NEdgevectorList_data[((int)n + NEdgevectorList_size[0] * i19) - 1];
        }

        a1 = p0[0] / sqrt(p0[0] * p0[0] + p0[1] * p0[1]);
        a2 = p0[1] / sqrt(p0[0] * p0[0] + p0[1] * p0[1]);
        P[0] = Point_data[0] + L * (a1 * sqrt((1.0 + Cosa->data[0]) / 2.0) - a2 *
          sqrt((1.0 - Cosa->data[0]) / 2.0));
        P[100] = Point_data[Point_size[0]] + L * (a2 * sqrt((1.0 + Cosa->data[0])
          / 2.0) + a1 * sqrt((1.0 - Cosa->data[0]) / 2.0));
        b_a1[0] = a1;
        b_a1[1] = a2;
        for (i19 = 0; i19 < 2; i19++) {
          P[1 + 100 * i19] = Point_data[Point_size[0] * i19] + b_a1[i19] * L;
        }

        P[2] = Point_data[0] + L * (a1 * sqrt((1.0 + Cosa->data[0]) / 2.0) + a2 *
          sqrt((1.0 - Cosa->data[0]) / 2.0));
        P[102] = Point_data[Point_size[0]] + L * (a2 * sqrt((1.0 + Cosa->data[0])
          / 2.0) - a1 * sqrt((1.0 - Cosa->data[0]) / 2.0));
        *P_Cnt = 3.0;
      } else {
        b_Sina = Sina->data[0];
        for (i19 = 0; i19 < 2; i19++) {
          P[100 * i19] = Point_data[Point_size[0] * i19] -
            (NEdgevectorList_data[NEdgevectorList_size[0] * i19] -
             NEdgevectorList_data[((int)n + NEdgevectorList_size[0] * i19) - 1])
            * L / b_Sina;
        }

        *P_Cnt = 1.0;
      }
    }
  }

  for (i = 1; i - 1 < (int)(n + -1.0); i++) {
    if (fabs(Sina->data[Sina->size[0] * i]) > sin(Theita * 3.1415926 / 180.0)) {
      b_Sina = Sina->data[Sina->size[0] * i];
      i19 = (int)((2.0 + (double)(i - 1)) + 2.0 * k);
      for (i20 = 0; i20 < 2; i20++) {
        P[(i19 + 100 * i20) - 1] = Point_data[i + Point_size[0] * i20] -
          (NEdgevectorList_data[i + NEdgevectorList_size[0] * i20] -
           NEdgevectorList_data[((int)((2.0 + (double)(i - 1)) - 1.0) +
            NEdgevectorList_size[0] * i20) - 1]) * L / b_Sina;
      }

      (*P_Cnt)++;
    } else {
      if (fabs(Sina->data[Sina->size[0] * i]) <= sin(Theita * 3.1415926 / 180.0))
      {
        if ((Sina->data[Sina->size[0] * i] > 0.0) && (Cosa->data[Cosa->size[0] *
             i] < 0.0)) {
          k++;
          for (i19 = 0; i19 < 2; i19++) {
            p0[i19] = -NEdgevectorList_data[i + NEdgevectorList_size[0] * i19] +
              NEdgevectorList_data[((int)((2.0 + (double)(i - 1)) - 1.0) +
              NEdgevectorList_size[0] * i19) - 1];
          }

          a1 = p0[0] / sqrt(p0[0] * p0[0] + p0[1] * p0[1]);
          a2 = p0[1] / sqrt(p0[0] * p0[0] + p0[1] * p0[1]);
          P[(int)(((2.0 + (double)(i - 1)) + 2.0 * k) - 2.0) - 1] = Point_data[i]
            + L * (a1 * sqrt((1.0 + Cosa->data[Cosa->size[0] * i]) / 2.0) - a2 *
                   sqrt((1.0 - Cosa->data[Cosa->size[0] * i]) / 2.0));
          P[(int)(((2.0 + (double)(i - 1)) + 2.0 * k) - 2.0) + 99] =
            Point_data[i + Point_size[0]] + L * (a2 * sqrt((1.0 + Cosa->
            data[Cosa->size[0] * i]) / 2.0) + a1 * sqrt((1.0 - Cosa->data
            [Cosa->size[0] * i]) / 2.0));
          c_a1[0] = a1;
          c_a1[1] = a2;
          i19 = (int)(((2.0 + (double)(i - 1)) + 2.0 * k) - 1.0);
          for (i20 = 0; i20 < 2; i20++) {
            P[(i19 + 100 * i20) - 1] = Point_data[i + Point_size[0] * i20] +
              c_a1[i20] * L;
          }

          P[(int)((2.0 + (double)(i - 1)) + 2.0 * k) - 1] = Point_data[i] + L *
            (a1 * sqrt((1.0 + Cosa->data[Cosa->size[0] * i]) / 2.0) + a2 * sqrt
             ((1.0 - Cosa->data[Cosa->size[0] * i]) / 2.0));
          P[(int)((2.0 + (double)(i - 1)) + 2.0 * k) + 99] = Point_data[i +
            Point_size[0]] + L * (a2 * sqrt((1.0 + Cosa->data[Cosa->size[0] * i])
            / 2.0) - a1 * sqrt((1.0 - Cosa->data[Cosa->size[0] * i]) / 2.0));
          *P_Cnt += 3.0;
        } else {
          b_Sina = Sina->data[Sina->size[0] * i];
          i19 = (int)((2.0 + (double)(i - 1)) + 2.0 * k);
          for (i20 = 0; i20 < 2; i20++) {
            P[(i19 + 100 * i20) - 1] = Point_data[i + Point_size[0] * i20] -
              (NEdgevectorList_data[i + NEdgevectorList_size[0] * i20] -
               NEdgevectorList_data[((int)((2.0 + (double)(i - 1)) - 1.0) +
                NEdgevectorList_size[0] * i20) - 1]) * L / b_Sina;
          }

          (*P_Cnt)++;
        }
      }
    }
  }
}

//
// File trailer for Reduce_Angle.cpp
//
// [EOF]
//
