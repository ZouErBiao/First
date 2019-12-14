//
// File: Calculate_Map_Points.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "Calculate_Map_Points.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "flipud.h"
#include "CalculateNewPoint.h"
#include "Calculate_Area.h"
#include "Calculate_Effective_Point.h"
#include "Preprocess.h"
#include "CalculateSina.h"
#include "DPList.h"

// Function Definitions

//
// {
// 作用：对多边形进行整体内缩或外扩
// 输入：
// P_Cnt:为点集点的个数(数据类型：double 1x1)
// Point:为初始点坐标集(数据类型：double P_Cntx1)
// L:为缩放的宽度(数据类型：double 1x1)
// flag: = 0缩小，flag = 1,扩大(数据类型：double 1x1)
// Theita:为小角度的上限(数据类型：double 1x1)
// Clock_Flag:原输入点集的时针方向（未经转换成顺时针前）
// 0-逆时针
// 1-顺时针
// 输出：
// PL_Cnt:输出点集点的个数(数据类型：double 1x1)
// PointLast：处理后的点集(数据类型：double PL_Cntx1)
// f_error：0：正常；1：出现错误(数据类型：double 1x1)
// }
// Arguments    : const double Point_data[]
//                const int Point_size[2]
//                double P_Cnt
//                double L
//                double flag
//                double Theita
//                double Clock_Flag
//                double PointLast[200]
//                double *PL_Cnt
//                double *f_error
// Return Type  : void
//
void Calculate_Map_Points(const double Point_data[], const int Point_size[2],
  double P_Cnt, double L, double flag, double Theita, double Clock_Flag, double
  PointLast[200], double *PL_Cnt, double *f_error)
{
  emxArray_real_T *Sina;
  int i14;
  int loop_ub;
  emxArray_real_T *EList;
  emxArray_real_T *NEdgevectorList;
  double b_Point_data[510];
  int b_Point_size[2];
  int i15;
  emxArray_real_T *r5;
  emxArray_real_T c_Point_data;
  emxArray_real_T *EdgevectorList;
  int i;
  double b_Sina;
  emxArray_real_T *b_NEdgevectorList;
  emxArray_real_T *r6;
  double P[200];
  int t;
  double P_data[200];
  int P_size[2];
  double Prep_Cnt;
  double Prep_Preprocessing[200];
  int Prep_Preprocessing_size[2];
  int PointLast_size[2];
  double Area;
  int tmp_size[2];
  double tmp_data[510];
  int tmp_size_idx_0;
  double b_tmp_data[200];
  double d_Point_data[510];
  emxInit_real_T(&Sina, 2);
  i14 = Sina->size[0] * Sina->size[1];
  Sina->size[0] = 1;
  Sina->size[1] = (int)P_Cnt;
  emxEnsureCapacity((emxArray__common *)Sina, i14, (int)sizeof(double));
  loop_ub = (int)P_Cnt;
  for (i14 = 0; i14 < loop_ub; i14++) {
    Sina->data[i14] = 0.0;
  }

  emxInit_real_T(&EList, 2);
  i14 = EList->size[0] * EList->size[1];
  EList->size[0] = (int)P_Cnt;
  EList->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)EList, i14, (int)sizeof(double));
  loop_ub = (int)P_Cnt << 1;
  for (i14 = 0; i14 < loop_ub; i14++) {
    EList->data[i14] = 0.0;
  }

  emxInit_real_T(&NEdgevectorList, 2);
  i14 = NEdgevectorList->size[0] * NEdgevectorList->size[1];
  NEdgevectorList->size[0] = (int)P_Cnt;
  NEdgevectorList->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)NEdgevectorList, i14, (int)sizeof(double));
  loop_ub = (int)P_Cnt << 1;
  for (i14 = 0; i14 < loop_ub; i14++) {
    NEdgevectorList->data[i14] = 0.0;
  }

  if (1.0 > P_Cnt) {
    loop_ub = 0;
  } else {
    loop_ub = (int)P_Cnt;
  }

  b_Point_size[0] = loop_ub;
  b_Point_size[1] = 2;
  for (i14 = 0; i14 < 2; i14++) {
    for (i15 = 0; i15 < loop_ub; i15++) {
      b_Point_data[i15 + b_Point_size[0] * i14] = Point_data[i15 + Point_size[0]
        * i14];
    }
  }

  emxInit_real_T(&r5, 2);
  c_Point_data.data = (double *)&b_Point_data;
  c_Point_data.size = (int *)&b_Point_size;
  c_Point_data.allocatedSize = 510;
  c_Point_data.numDimensions = 2;
  c_Point_data.canFreeData = false;
  DPList(&c_Point_data, P_Cnt, r5);
  for (i14 = 0; i14 < 2; i14++) {
    loop_ub = r5->size[0];
    for (i15 = 0; i15 < loop_ub; i15++) {
      EList->data[i15 + EList->size[0] * i14] = r5->data[i15 + r5->size[0] * i14];
    }
  }

  if (1.0 > P_Cnt) {
    loop_ub = 0;
  } else {
    loop_ub = (int)P_Cnt;
  }

  emxInit_real_T(&EdgevectorList, 2);
  i14 = EdgevectorList->size[0] * EdgevectorList->size[1];
  EdgevectorList->size[0] = loop_ub;
  EdgevectorList->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)EdgevectorList, i14, (int)sizeof(double));
  for (i14 = 0; i14 < 2; i14++) {
    for (i15 = 0; i15 < loop_ub; i15++) {
      EdgevectorList->data[i15 + EdgevectorList->size[0] * i14] = EList->
        data[i15 + EList->size[0] * i14];
    }
  }

  // 单位化各边向量
  // n为行数
  i14 = r5->size[0] * r5->size[1];
  r5->size[0] = (int)P_Cnt;
  r5->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)r5, i14, (int)sizeof(double));
  loop_ub = (int)P_Cnt << 1;
  for (i14 = 0; i14 < loop_ub; i14++) {
    r5->data[i14] = 0.0;
  }

  for (i = 0; i < (int)P_Cnt; i++) {
    b_Sina = sqrt(EList->data[i] * EList->data[i] + EList->data[i + EList->size
                  [0]] * EList->data[i + EList->size[0]]);
    for (i14 = 0; i14 < 2; i14++) {
      r5->data[i + r5->size[0] * i14] = EdgevectorList->data[i +
        EdgevectorList->size[0] * i14] / b_Sina;
    }
  }

  emxFree_real_T(&EdgevectorList);
  emxFree_real_T(&EList);
  for (i14 = 0; i14 < 2; i14++) {
    loop_ub = r5->size[0];
    for (i15 = 0; i15 < loop_ub; i15++) {
      NEdgevectorList->data[i15 + NEdgevectorList->size[0] * i14] = r5->data[i15
        + r5->size[0] * i14];
    }
  }

  emxFree_real_T(&r5);

  // 单位向量
  if (1.0 > P_Cnt) {
    loop_ub = 0;
  } else {
    loop_ub = (int)P_Cnt;
  }

  emxInit_real_T(&b_NEdgevectorList, 2);
  i14 = b_NEdgevectorList->size[0] * b_NEdgevectorList->size[1];
  b_NEdgevectorList->size[0] = loop_ub;
  b_NEdgevectorList->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)b_NEdgevectorList, i14, (int)sizeof
                    (double));
  for (i14 = 0; i14 < 2; i14++) {
    for (i15 = 0; i15 < loop_ub; i15++) {
      b_NEdgevectorList->data[i15 + b_NEdgevectorList->size[0] * i14] =
        NEdgevectorList->data[i15 + NEdgevectorList->size[0] * i14];
    }
  }

  emxInit_real_T(&r6, 2);
  CalculateSina(b_NEdgevectorList, P_Cnt, r6);
  loop_ub = r6->size[1];
  emxFree_real_T(&b_NEdgevectorList);
  for (i14 = 0; i14 < loop_ub; i14++) {
    Sina->data[Sina->size[0] * i14] = r6->data[r6->size[0] * i14];
  }

  emxFree_real_T(&r6);
  for (i14 = 0; i14 < 200; i14++) {
    P[i14] = 0.0;
    PointLast[i14] = 0.0;
  }

  *PL_Cnt = 0.0;

  // 内缩后的多变行面积最小值为某一常数，如果L对应的内缩面积是Area_Limit，则保留L-0.5米对应的内缩后的点 
  *f_error = 0.0;

  // %
  switch ((int)flag) {
   case 0:
    // flag: = 0缩小，flag = 1,扩大
    t = 1;
    while (t != 0) {
      for (i = 1; i - 1 <= (int)P_Cnt - 2; i++) {
        b_Sina = Sina->data[Sina->size[0] * i];
        for (i14 = 0; i14 < 2; i14++) {
          P[i + 100 * i14] = Point_data[i + Point_size[0] * i14] +
            (NEdgevectorList->data[i + NEdgevectorList->size[0] * i14] -
             NEdgevectorList->data[(i + NEdgevectorList->size[0] * i14) - 1]) *
            L / b_Sina;
        }
      }

      b_Sina = Sina->data[0];
      for (i14 = 0; i14 < 2; i14++) {
        P[100 * i14] = Point_data[Point_size[0] * i14] + (NEdgevectorList->
          data[NEdgevectorList->size[0] * i14] - NEdgevectorList->data[((int)
          P_Cnt + NEdgevectorList->size[0] * i14) - 1]) * L / b_Sina;
      }

      if (1.0 > P_Cnt) {
        loop_ub = 0;
      } else {
        loop_ub = (int)P_Cnt;
      }

      P_size[0] = loop_ub;
      P_size[1] = 2;
      for (i14 = 0; i14 < 2; i14++) {
        for (i15 = 0; i15 < loop_ub; i15++) {
          P_data[i15 + loop_ub * i14] = P[i15 + 100 * i14];
        }
      }

      Preprocess(P_data, P_size, P_Cnt, Prep_Preprocessing, &Prep_Cnt);
      memcpy(&P[0], &Prep_Preprocessing[0], 200U * sizeof(double));
      if (1.0 > Prep_Cnt) {
        loop_ub = 0;
      } else {
        loop_ub = (int)Prep_Cnt;
      }

      Prep_Preprocessing_size[0] = loop_ub;
      Prep_Preprocessing_size[1] = 2;
      for (i14 = 0; i14 < 2; i14++) {
        for (i15 = 0; i15 < loop_ub; i15++) {
          P_data[i15 + loop_ub * i14] = Prep_Preprocessing[i15 + 100 * i14];
        }
      }

      Calculate_Effective_Point(P_data, Prep_Preprocessing_size, Prep_Cnt,
        PointLast, &b_Sina);
      *PL_Cnt = b_Sina;
      if (1.0 > b_Sina) {
        loop_ub = 0;
      } else {
        loop_ub = (int)b_Sina;
      }

      PointLast_size[0] = loop_ub;
      PointLast_size[1] = 2;
      for (i14 = 0; i14 < 2; i14++) {
        for (i15 = 0; i15 < loop_ub; i15++) {
          P_data[i15 + loop_ub * i14] = PointLast[i15 + 100 * i14];
        }
      }

      Area = Calculate_Area(P_data, PointLast_size, b_Sina);

      //            %%
      // 此处只能解决L渐变的翻转情况
      if (Area < 20.0) {
        L -= 0.5;
      } else {
        t = 0;
      }
    }

    if (Clock_Flag == 1.0) {
      if (1.0 > *PL_Cnt) {
        loop_ub = 0;
      } else {
        loop_ub = (int)*PL_Cnt;
      }

      tmp_size[0] = loop_ub;
      tmp_size[1] = 2;
      for (i14 = 0; i14 < 2; i14++) {
        for (i15 = 0; i15 < loop_ub; i15++) {
          tmp_data[i15 + loop_ub * i14] = PointLast[i15 + 100 * i14];
        }
      }

      flipud(tmp_data, tmp_size);
      tmp_size_idx_0 = tmp_size[0];
      loop_ub = tmp_size[0] * tmp_size[1];
      for (i14 = 0; i14 < loop_ub; i14++) {
        b_tmp_data[i14] = tmp_data[i14];
      }

      for (i14 = 0; i14 < 2; i14++) {
        for (i15 = 0; i15 < tmp_size_idx_0; i15++) {
          PointLast[i15 + 100 * i14] = b_tmp_data[i15 + tmp_size_idx_0 * i14];
        }
      }

      // 转换成与初始输入时的时针顺序一致
    }
    break;

   case 1:
    if (1.0 > P_Cnt) {
      loop_ub = 0;
    } else {
      loop_ub = (int)P_Cnt;
    }

    P_size[0] = loop_ub;
    P_size[1] = 2;
    for (i14 = 0; i14 < 2; i14++) {
      for (i15 = 0; i15 < loop_ub; i15++) {
        d_Point_data[i15 + loop_ub * i14] = Point_data[i15 + Point_size[0] * i14];
      }
    }

    CalculateNewPoint(d_Point_data, P_size, P_Cnt, L, Theita, PointLast, &b_Sina);
    *PL_Cnt = b_Sina;
    if (Clock_Flag == 0.0) {
      if (1.0 > b_Sina) {
        loop_ub = 0;
      } else {
        loop_ub = (int)b_Sina;
      }

      tmp_size[0] = loop_ub;
      tmp_size[1] = 2;
      for (i14 = 0; i14 < 2; i14++) {
        for (i15 = 0; i15 < loop_ub; i15++) {
          tmp_data[i15 + loop_ub * i14] = PointLast[i15 + 100 * i14];
        }
      }

      flipud(tmp_data, tmp_size);
      tmp_size_idx_0 = tmp_size[0];
      loop_ub = tmp_size[0] * tmp_size[1];
      for (i14 = 0; i14 < loop_ub; i14++) {
        b_tmp_data[i14] = tmp_data[i14];
      }

      for (i14 = 0; i14 < 2; i14++) {
        for (i15 = 0; i15 < tmp_size_idx_0; i15++) {
          PointLast[i15 + 100 * i14] = b_tmp_data[i15 + tmp_size_idx_0 * i14];
        }
      }

      // %转换成与刚输入时的时针顺序一致
    }
    break;

   default:
    *f_error = 1.0;
    break;
  }

  emxFree_real_T(&NEdgevectorList);
  emxFree_real_T(&Sina);
}

//
// File trailer for Calculate_Map_Points.cpp
//
// [EOF]
//
