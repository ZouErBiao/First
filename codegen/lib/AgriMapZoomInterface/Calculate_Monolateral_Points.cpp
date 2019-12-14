//
// File: Calculate_Monolateral_Points.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "Calculate_Monolateral_Points.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "flipud.h"
#include "Calculate_Effective_Point.h"
#include "CalculateSina.h"
#include "DPList.h"

// Function Definitions

//
// 计算单边内缩的点
// {
// 输入：
// n:多边形点的个数(数据类型：double 1x1)
// Points：需要移动某边的多变形的边界点集，格式为多行两列的矩阵(数据类型：double nx2)
// Monolateral：要移动的边的边号(数据类型：double 1x1)
// Monolateral_L：某边要移动的距离,不能把某个边给缩没了(数据类型：double 1x1)
// Monolateral_flag：某边要移动的方向(数据类型：double 1x1)
// 输出：
// PM_Cnt：输出的有效点的个数(数据类型：double 1x1)
// Points_Monolateral：经过移动某边后的多边形的边界点(数据类型：double 100x2)
// f_error：错误标志，为零则无错误，为1为有错误(数据类型：double 1x1)
// }
// Arguments    : double Points_data[]
//                int Points_size[2]
//                double n
//                double Monolateral
//                double Monolateral_L
//                double Monolateral_flag
//                double Clock_Flag
//                double Points_Monolateral[200]
//                double *PM_Cnt
//                double *f_error
// Return Type  : void
//
void Calculate_Monolateral_Points(double Points_data[], int Points_size[2],
  double n, double Monolateral, double Monolateral_L, double Monolateral_flag,
  double Clock_Flag, double Points_Monolateral[200], double *PM_Cnt, double
  *f_error)
{
  emxArray_real_T *NEdgevectorList;
  int i7;
  int loop_ub;
  double b_Points_data[510];
  int b_Points_size[2];
  int i8;
  emxArray_real_T *r1;
  emxArray_real_T c_Points_data;
  emxArray_real_T *EdgevectorList;
  int i;
  double Sina;
  emxArray_real_T *b_Sina;
  emxArray_real_T *b_NEdgevectorList;
  emxArray_real_T *r2;
  double d_Points_data[510];
  int c_Points_size[2];
  double PointLast[200];
  int tmp_size[2];
  double tmp_data[510];
  int tmp_size_idx_0;
  double b_tmp_data[200];
  memset(&Points_Monolateral[0], 0, 200U * sizeof(double));
  emxInit_real_T(&NEdgevectorList, 2);
  *PM_Cnt = 0.0;
  i7 = NEdgevectorList->size[0] * NEdgevectorList->size[1];
  NEdgevectorList->size[0] = (int)n;
  NEdgevectorList->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)NEdgevectorList, i7, (int)sizeof(double));
  loop_ub = (int)n << 1;
  for (i7 = 0; i7 < loop_ub; i7++) {
    NEdgevectorList->data[i7] = 0.0;
  }

  b_Points_size[0] = (int)n;
  b_Points_size[1] = 2;
  for (i7 = 0; i7 < 2; i7++) {
    loop_ub = (int)n;
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_Points_data[i8 + b_Points_size[0] * i7] = Points_data[i8 + Points_size[0]
        * i7];
    }
  }

  emxInit_real_T(&r1, 2);
  c_Points_data.data = (double *)&b_Points_data;
  c_Points_data.size = (int *)&b_Points_size;
  c_Points_data.allocatedSize = 510;
  c_Points_data.numDimensions = 2;
  c_Points_data.canFreeData = false;
  DPList(&c_Points_data, n, r1);
  for (i7 = 0; i7 < 2; i7++) {
    loop_ub = r1->size[0];
    for (i8 = 0; i8 < loop_ub; i8++) {
      NEdgevectorList->data[i8 + NEdgevectorList->size[0] * i7] = r1->data[i8 +
        r1->size[0] * i7];
    }
  }

  emxInit_real_T(&EdgevectorList, 2);
  i7 = EdgevectorList->size[0] * EdgevectorList->size[1];
  EdgevectorList->size[0] = (int)n;
  EdgevectorList->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)EdgevectorList, i7, (int)sizeof(double));
  for (i7 = 0; i7 < 2; i7++) {
    loop_ub = (int)n;
    for (i8 = 0; i8 < loop_ub; i8++) {
      EdgevectorList->data[i8 + EdgevectorList->size[0] * i7] =
        NEdgevectorList->data[i8 + NEdgevectorList->size[0] * i7];
    }
  }

  // 单位化各边向量
  // n为行数
  i7 = r1->size[0] * r1->size[1];
  r1->size[0] = (int)n;
  r1->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)r1, i7, (int)sizeof(double));
  loop_ub = (int)n << 1;
  for (i7 = 0; i7 < loop_ub; i7++) {
    r1->data[i7] = 0.0;
  }

  for (i = 0; i < (int)n; i++) {
    Sina = sqrt(NEdgevectorList->data[i] * NEdgevectorList->data[i] +
                NEdgevectorList->data[i + NEdgevectorList->size[0]] *
                NEdgevectorList->data[i + NEdgevectorList->size[0]]);
    for (i7 = 0; i7 < 2; i7++) {
      r1->data[i + r1->size[0] * i7] = EdgevectorList->data[i +
        EdgevectorList->size[0] * i7] / Sina;
    }
  }

  emxFree_real_T(&EdgevectorList);
  for (i7 = 0; i7 < 2; i7++) {
    loop_ub = r1->size[0];
    for (i8 = 0; i8 < loop_ub; i8++) {
      NEdgevectorList->data[i8 + NEdgevectorList->size[0] * i7] = r1->data[i8 +
        r1->size[0] * i7];
    }
  }

  emxFree_real_T(&r1);
  emxInit_real_T(&b_Sina, 2);

  // 单位向量
  i7 = b_Sina->size[0] * b_Sina->size[1];
  b_Sina->size[0] = 1;
  b_Sina->size[1] = (int)n;
  emxEnsureCapacity((emxArray__common *)b_Sina, i7, (int)sizeof(double));
  loop_ub = (int)n;
  for (i7 = 0; i7 < loop_ub; i7++) {
    b_Sina->data[i7] = 0.0;
  }

  emxInit_real_T(&b_NEdgevectorList, 2);
  i7 = b_NEdgevectorList->size[0] * b_NEdgevectorList->size[1];
  b_NEdgevectorList->size[0] = (int)n;
  b_NEdgevectorList->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)b_NEdgevectorList, i7, (int)sizeof
                    (double));
  for (i7 = 0; i7 < 2; i7++) {
    loop_ub = (int)n;
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_NEdgevectorList->data[i8 + b_NEdgevectorList->size[0] * i7] =
        NEdgevectorList->data[i8 + NEdgevectorList->size[0] * i7];
    }
  }

  emxInit_real_T(&r2, 2);
  CalculateSina(b_NEdgevectorList, n, r2);
  loop_ub = r2->size[1];
  emxFree_real_T(&b_NEdgevectorList);
  for (i7 = 0; i7 < loop_ub; i7++) {
    b_Sina->data[b_Sina->size[0] * i7] = r2->data[r2->size[0] * i7];
  }

  emxFree_real_T(&r2);
  *f_error = 0.0;
  if ((Monolateral > n) || (Monolateral < 1.0)) {
    *f_error = 1.0;
  }

  if (*f_error == 1.0) {
    for (i7 = 0; i7 < 2; i7++) {
      loop_ub = (int)n;
      for (i8 = 0; i8 < loop_ub; i8++) {
        Points_Monolateral[i8 + 100 * i7] = 0.0;
      }
    }
  } else {
    switch ((int)Monolateral_flag) {
     case 0:
      // 内移
      if (Monolateral == 1.0) {
        Sina = b_Sina->data[0];
        for (i7 = 0; i7 < 2; i7++) {
          Points_data[Points_size[0] * i7] -= NEdgevectorList->data[((int)n +
            NEdgevectorList->size[0] * i7) - 1] * Monolateral_L / Sina;
        }

        Sina = b_Sina->data[b_Sina->size[0]];
        for (i7 = 0; i7 < 2; i7++) {
          Points_data[1 + Points_size[0] * i7] += NEdgevectorList->data[1 +
            NEdgevectorList->size[0] * i7] * Monolateral_L / Sina;
        }
      } else if (Monolateral < n) {
        Sina = b_Sina->data[b_Sina->size[0] * ((int)Monolateral - 1)];
        for (i7 = 0; i7 < 2; i7++) {
          Points_data[((int)Monolateral + Points_size[0] * i7) - 1] -=
            NEdgevectorList->data[((int)Monolateral + NEdgevectorList->size[0] *
            i7) - 2] * Monolateral_L / Sina;
        }

        Sina = b_Sina->data[b_Sina->size[0] * (int)Monolateral];
        for (i7 = 0; i7 < 2; i7++) {
          Points_data[(int)Monolateral + Points_size[0] * i7] +=
            NEdgevectorList->data[(int)Monolateral + NEdgevectorList->size[0] *
            i7] * Monolateral_L / Sina;
        }
      } else {
        Sina = b_Sina->data[b_Sina->size[0] * ((int)Monolateral - 1)];
        for (i7 = 0; i7 < 2; i7++) {
          Points_data[((int)Monolateral + Points_size[0] * i7) - 1] -=
            NEdgevectorList->data[((int)Monolateral + NEdgevectorList->size[0] *
            i7) - 2] * Monolateral_L / Sina;
        }

        Sina = b_Sina->data[0];
        for (i7 = 0; i7 < 2; i7++) {
          Points_data[Points_size[0] * i7] += NEdgevectorList->
            data[NEdgevectorList->size[0] * i7] * Monolateral_L / Sina;
        }
      }
      break;

     case 1:
      // 外移
      if (Monolateral == 1.0) {
        Sina = b_Sina->data[0];
        for (i7 = 0; i7 < 2; i7++) {
          Points_data[Points_size[0] * i7] += NEdgevectorList->data[((int)n +
            NEdgevectorList->size[0] * i7) - 1] * Monolateral_L / Sina;
        }

        Sina = b_Sina->data[b_Sina->size[0]];
        for (i7 = 0; i7 < 2; i7++) {
          Points_data[1 + Points_size[0] * i7] -= NEdgevectorList->data[1 +
            NEdgevectorList->size[0] * i7] * Monolateral_L / Sina;
        }
      } else if (Monolateral < n) {
        Sina = b_Sina->data[b_Sina->size[0] * ((int)Monolateral - 1)];
        for (i7 = 0; i7 < 2; i7++) {
          Points_data[((int)Monolateral + Points_size[0] * i7) - 1] +=
            NEdgevectorList->data[((int)Monolateral + NEdgevectorList->size[0] *
            i7) - 2] * Monolateral_L / Sina;
        }

        Sina = b_Sina->data[b_Sina->size[0] * (int)Monolateral];
        for (i7 = 0; i7 < 2; i7++) {
          Points_data[(int)Monolateral + Points_size[0] * i7] -=
            NEdgevectorList->data[(int)Monolateral + NEdgevectorList->size[0] *
            i7] * Monolateral_L / Sina;
        }
      } else {
        Sina = b_Sina->data[b_Sina->size[0] * ((int)Monolateral - 1)];
        for (i7 = 0; i7 < 2; i7++) {
          Points_data[((int)Monolateral + Points_size[0] * i7) - 1] +=
            NEdgevectorList->data[((int)Monolateral + NEdgevectorList->size[0] *
            i7) - 2] * Monolateral_L / Sina;
        }

        Sina = b_Sina->data[0];
        for (i7 = 0; i7 < 2; i7++) {
          Points_data[Points_size[0] * i7] -= NEdgevectorList->
            data[NEdgevectorList->size[0] * i7] * Monolateral_L / Sina;
        }
      }
      break;

     default:
      *f_error = 1.0;

      // warning('输入的平面坐标标志并非简单地0或1');
      break;
    }

    c_Points_size[0] = (int)n;
    c_Points_size[1] = 2;
    for (i7 = 0; i7 < 2; i7++) {
      loop_ub = (int)n;
      for (i8 = 0; i8 < loop_ub; i8++) {
        d_Points_data[i8 + (int)n * i7] = Points_data[i8 + Points_size[0] * i7];
      }
    }

    Calculate_Effective_Point(d_Points_data, c_Points_size, n, PointLast, &Sina);

    // 去除无效环
    if (Clock_Flag == 0.0) {
      *PM_Cnt = Sina;
      if (1.0 > Sina) {
        loop_ub = -1;
      } else {
        loop_ub = (int)Sina - 1;
      }

      for (i7 = 0; i7 < 2; i7++) {
        for (i8 = 0; i8 <= loop_ub; i8++) {
          Points_Monolateral[i8 + 100 * i7] = PointLast[i8 + 100 * i7];
        }
      }

      // 把结果变成顺时针的
    } else {
      *PM_Cnt = Sina;
      if (1.0 > Sina) {
        loop_ub = 0;
      } else {
        loop_ub = (int)Sina;
      }

      tmp_size[0] = loop_ub;
      tmp_size[1] = 2;
      for (i7 = 0; i7 < 2; i7++) {
        for (i8 = 0; i8 < loop_ub; i8++) {
          tmp_data[i8 + loop_ub * i7] = PointLast[i8 + 100 * i7];
        }
      }

      flipud(tmp_data, tmp_size);
      tmp_size_idx_0 = tmp_size[0];
      loop_ub = tmp_size[0] * tmp_size[1];
      for (i7 = 0; i7 < loop_ub; i7++) {
        b_tmp_data[i7] = tmp_data[i7];
      }

      for (i7 = 0; i7 < 2; i7++) {
        for (i8 = 0; i8 < tmp_size_idx_0; i8++) {
          Points_Monolateral[i8 + 100 * i7] = b_tmp_data[i8 + tmp_size_idx_0 *
            i7];
        }
      }

      // 把结果变成顺时针的
    }
  }

  emxFree_real_T(&b_Sina);
  emxFree_real_T(&NEdgevectorList);
}

//
// File trailer for Calculate_Monolateral_Points.cpp
//
// [EOF]
//
