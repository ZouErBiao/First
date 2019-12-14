//
// File: Preprocess.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "Preprocess.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "DPList.h"

// Function Definitions

//
// 对输入数据进行预处理，排除重合和连续三点在同一条直线上的情况
// {
// 输入：
// Point为输入的边界点
// P_Cnt:边界点的个数
// 输出：
// Prep为经过去重和去连续连续操作后的点集的结构体，格式为50乘以2
// Prep.Preprocessing:格式为50乘以2
// Prep.Cnt:有效点的个数
// }
// %
// Arguments    : const double Point_data[]
//                const int Point_size[2]
//                double P_Cnt
//                double Prep_Preprocessing[200]
//                double *Prep_Cnt
// Return Type  : void
//
void Preprocess(const double Point_data[], const int Point_size[2], double P_Cnt,
                double Prep_Preprocessing[200], double *Prep_Cnt)
{
  emxArray_real_T *P_M;
  int i2;
  int ixstart;
  double Count;
  int ix;
  double mtmp;
  double varargin_1_idx_1;
  boolean_T exitg5;
  double x[3];
  double y[3];
  boolean_T b_y;
  boolean_T exitg4;
  int i;
  int j;
  boolean_T exitg1;
  boolean_T exitg3;
  boolean_T exitg2;
  emxArray_real_T *Point_map;
  int Cnt;
  emxArray_real_T *NEdgevectorList;
  emxArray_real_T *b_Point_map;
  emxArray_real_T *r0;
  emxArray_real_T *EdgevectorList;
  emxArray_real_T *IndexPrepro;
  double Index_Cnt;
  unsigned int m;
  memset(&Prep_Preprocessing[0], 0, 200U * sizeof(double));
  emxInit_real_T(&P_M, 2);
  i2 = P_M->size[0] * P_M->size[1];
  P_M->size[0] = (int)P_Cnt;
  P_M->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)P_M, i2, (int)sizeof(double));
  ixstart = (int)P_Cnt * 3;
  for (i2 = 0; i2 < ixstart; i2++) {
    P_M->data[i2] = 0.0;
  }

  Count = 0.0;
  if (1.0 > P_Cnt) {
    ixstart = -1;
  } else {
    ixstart = (int)P_Cnt - 1;
  }

  for (i2 = 0; i2 < 2; i2++) {
    for (ix = 0; ix <= ixstart; ix++) {
      P_M->data[ix + P_M->size[0] * i2] = Point_data[ix + Point_size[0] * i2];
    }
  }

  // P_M的第三列是标志位，为1的话则此行需删除
  mtmp = P_M->data[1] * 0.005;
  varargin_1_idx_1 = P_M->data[1 + P_M->size[0]] * 0.005;
  ixstart = 1;
  if (rtIsNaN(mtmp)) {
    ix = 2;
    exitg5 = false;
    while ((!exitg5) && (ix < 3)) {
      ixstart = 2;
      if (!rtIsNaN(varargin_1_idx_1)) {
        mtmp = varargin_1_idx_1;
        exitg5 = true;
      } else {
        ix = 3;
      }
    }
  }

  if ((ixstart < 2) && (varargin_1_idx_1 < mtmp)) {
    mtmp = varargin_1_idx_1;
  }

  // 工程上要求的千分之五
  for (i2 = 0; i2 < 3; i2++) {
    x[i2] = P_M->data[P_M->size[0] * i2] - P_M->data[1 + P_M->size[0] * i2];
  }

  for (ixstart = 0; ixstart < 3; ixstart++) {
    y[ixstart] = fabs(x[ixstart]);
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
    P_M->data[1 + (P_M->size[0] << 1)] = 1.0;

    // 为了占位给重复的地方替换为其他值，替换值要尽量不要跟数据采集点重复，采集点恰好与该值相等的概率极低（即：该值最好取地块的内部一点） 
    Count = 1.0;
  }

  for (i = 2; i - 2 <= (int)P_Cnt - 3; i++) {
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j <= i - 1)) {
      mtmp = P_M->data[i] * 0.005;
      varargin_1_idx_1 = P_M->data[i + P_M->size[0]] * 0.005;
      ixstart = 1;
      if (rtIsNaN(mtmp)) {
        ix = 2;
        exitg3 = false;
        while ((!exitg3) && (ix < 3)) {
          ixstart = 2;
          if (!rtIsNaN(varargin_1_idx_1)) {
            mtmp = varargin_1_idx_1;
            exitg3 = true;
          } else {
            ix = 3;
          }
        }
      }

      if ((ixstart < 2) && (varargin_1_idx_1 < mtmp)) {
        mtmp = varargin_1_idx_1;
      }

      // 工程上要求的千分之五
      for (i2 = 0; i2 < 3; i2++) {
        x[i2] = P_M->data[j + P_M->size[0] * i2] - P_M->data[i + P_M->size[0] *
          i2];
      }

      for (ixstart = 0; ixstart < 3; ixstart++) {
        y[ixstart] = fabs(x[ixstart]);
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
        P_M->data[i + (P_M->size[0] << 1)] = 1.0;
        Count++;
        exitg1 = true;
      } else {
        j++;
      }
    }
  }

  emxInit_real_T(&Point_map, 2);

  // %
  // 保留不重复的点
  i2 = Point_map->size[0] * Point_map->size[1];
  Point_map->size[0] = (int)(P_Cnt - Count);
  Point_map->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)Point_map, i2, (int)sizeof(double));
  ixstart = (int)(P_Cnt - Count) << 1;
  for (i2 = 0; i2 < ixstart; i2++) {
    Point_map->data[i2] = 0.0;
  }

  Cnt = 0;

  // 第一位用于下标计数
  for (i = 0; i < (int)P_Cnt; i++) {
    if (P_M->data[i + (P_M->size[0] << 1)] == 0.0) {
      Cnt++;
      for (i2 = 0; i2 < 2; i2++) {
        Point_map->data[(Cnt + Point_map->size[0] * i2) - 1] = P_M->data[i +
          P_M->size[0] * i2];
      }
    }
  }

  emxFree_real_T(&P_M);
  emxInit_real_T(&NEdgevectorList, 2);

  // 以上代码解决了点的重复问题
  // %
  // %以下代码解决连续三点在同一条直线上的问题
  i2 = NEdgevectorList->size[0] * NEdgevectorList->size[1];
  NEdgevectorList->size[0] = Cnt;
  NEdgevectorList->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)NEdgevectorList, i2, (int)sizeof(double));
  ixstart = Cnt << 1;
  for (i2 = 0; i2 < ixstart; i2++) {
    NEdgevectorList->data[i2] = 0.0;
  }

  if (1 > Cnt) {
    ixstart = 0;
  } else {
    ixstart = Cnt;
  }

  emxInit_real_T(&b_Point_map, 2);
  i2 = b_Point_map->size[0] * b_Point_map->size[1];
  b_Point_map->size[0] = ixstart;
  b_Point_map->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)b_Point_map, i2, (int)sizeof(double));
  for (i2 = 0; i2 < 2; i2++) {
    for (ix = 0; ix < ixstart; ix++) {
      b_Point_map->data[ix + b_Point_map->size[0] * i2] = Point_map->data[ix +
        Point_map->size[0] * i2];
    }
  }

  emxInit_real_T(&r0, 2);
  DPList(b_Point_map, (double)Cnt, r0);
  emxFree_real_T(&b_Point_map);
  for (i2 = 0; i2 < 2; i2++) {
    ixstart = r0->size[0];
    for (ix = 0; ix < ixstart; ix++) {
      NEdgevectorList->data[ix + NEdgevectorList->size[0] * i2] = r0->data[ix +
        r0->size[0] * i2];
    }
  }

  if (1 > Cnt) {
    ixstart = 0;
  } else {
    ixstart = Cnt;
  }

  emxInit_real_T(&EdgevectorList, 2);
  i2 = EdgevectorList->size[0] * EdgevectorList->size[1];
  EdgevectorList->size[0] = ixstart;
  EdgevectorList->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)EdgevectorList, i2, (int)sizeof(double));
  for (i2 = 0; i2 < 2; i2++) {
    for (ix = 0; ix < ixstart; ix++) {
      EdgevectorList->data[ix + EdgevectorList->size[0] * i2] =
        NEdgevectorList->data[ix + NEdgevectorList->size[0] * i2];
    }
  }

  // 单位化各边向量
  // n为行数
  i2 = r0->size[0] * r0->size[1];
  r0->size[0] = Cnt;
  r0->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)r0, i2, (int)sizeof(double));
  ixstart = Cnt << 1;
  for (i2 = 0; i2 < ixstart; i2++) {
    r0->data[i2] = 0.0;
  }

  for (i = 0; i < Cnt; i++) {
    varargin_1_idx_1 = sqrt(NEdgevectorList->data[i] * NEdgevectorList->data[i]
      + NEdgevectorList->data[i + NEdgevectorList->size[0]] *
      NEdgevectorList->data[i + NEdgevectorList->size[0]]);
    for (i2 = 0; i2 < 2; i2++) {
      r0->data[i + r0->size[0] * i2] = EdgevectorList->data[i +
        EdgevectorList->size[0] * i2] / varargin_1_idx_1;
    }
  }

  emxFree_real_T(&EdgevectorList);
  for (i2 = 0; i2 < 2; i2++) {
    ixstart = r0->size[0];
    for (ix = 0; ix < ixstart; ix++) {
      NEdgevectorList->data[ix + NEdgevectorList->size[0] * i2] = r0->data[ix +
        r0->size[0] * i2];
    }
  }

  emxFree_real_T(&r0);
  emxInit_real_T1(&IndexPrepro, 1);

  // 各边的单位向量
  i2 = IndexPrepro->size[0];
  IndexPrepro->size[0] = Cnt;
  emxEnsureCapacity((emxArray__common *)IndexPrepro, i2, (int)sizeof(double));
  for (i2 = 0; i2 < Cnt; i2++) {
    IndexPrepro->data[i2] = 0.0;
  }

  // 与前面单位向量相等的点的点号的存储,列向量
  Index_Cnt = 0.0;
  if ((NEdgevectorList->data[0] == NEdgevectorList->data[Cnt - 1]) &&
      (NEdgevectorList->data[NEdgevectorList->size[0]] == NEdgevectorList->data
       [(Cnt + NEdgevectorList->size[0]) - 1])) {
    IndexPrepro->data[0] = 1.0;

    // 与前面单位向量相等的点号
  } else {
    Index_Cnt = 1.0;
    IndexPrepro->data[0] = 0.0;
  }

  for (i = 0; i <= Cnt - 2; i++) {
    if ((NEdgevectorList->data[i + 1] == NEdgevectorList->data[i]) &&
        (NEdgevectorList->data[(i + NEdgevectorList->size[0]) + 1] ==
         NEdgevectorList->data[i + NEdgevectorList->size[0]])) {
      IndexPrepro->data[i + 1] = 2.0 + (double)i;

      // 与前面单位向量相等的点 号
    } else {
      Index_Cnt++;
      IndexPrepro->data[i + 1] = 0.0;
    }
  }

  i2 = NEdgevectorList->size[0] * NEdgevectorList->size[1];
  NEdgevectorList->size[0] = (int)Index_Cnt;
  NEdgevectorList->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)NEdgevectorList, i2, (int)sizeof(double));
  ixstart = (int)Index_Cnt << 1;
  for (i2 = 0; i2 < ixstart; i2++) {
    NEdgevectorList->data[i2] = 0.0;
  }

  m = 0U;
  for (i = 0; i < Cnt; i++) {
    if ((int)IndexPrepro->data[i] == 0) {
      m++;
      for (i2 = 0; i2 < 2; i2++) {
        NEdgevectorList->data[((int)m + NEdgevectorList->size[0] * i2) - 1] =
          Point_map->data[i + Point_map->size[0] * i2];
      }
    }
  }

  emxFree_real_T(&IndexPrepro);
  emxFree_real_T(&Point_map);
  if (1.0 > Index_Cnt) {
    ixstart = -1;
  } else {
    ixstart = (int)Index_Cnt - 1;
  }

  for (i2 = 0; i2 < 2; i2++) {
    for (ix = 0; ix <= ixstart; ix++) {
      Prep_Preprocessing[ix + 100 * i2] = NEdgevectorList->data[ix +
        NEdgevectorList->size[0] * i2];
    }
  }

  emxFree_real_T(&NEdgevectorList);
  *Prep_Cnt = Index_Cnt;
}

//
// File trailer for Preprocess.cpp
//
// [EOF]
//
