//
// File: Calculate_Effective_Point.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "Calculate_Effective_Point.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "Calculate_Area.h"
#include "judgeClockWise.h"
#include "sum.h"
#include "CalculateIntersection.h"
#include "Sort2.h"
#include "Calculate_New_Indented_Boundary_Point.h"

// Function Definitions

//
// {
// 对经过内缩后的点集进行去无效环处理
// 输入：
// PointLast为经内缩后的点集，为多行两列的矩阵,顺时针排列的%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// 输出：
// YouXiao为经过处理后的保留下来的有效环的点集，为多行两列的矩阵
// }
// Arguments    : const double PointLast_data[]
//                const int PointLast_size[2]
//                double N
//                double YouXiao[200]
//                double *YX_Cnt
// Return Type  : void
//
void Calculate_Effective_Point(const double PointLast_data[], const int
  PointLast_size[2], double N, double YouXiao[200], double *YX_Cnt)
{
  int itmp;
  double b_PointLast_data[510];
  int b_PointLast_size[2];
  int i10;
  int idx;
  double d1;
  double PPP[700];
  double d2;
  double PP[350];
  int ii;
  double PPP_data[700];
  int PPP_size[2];
  double PP_data[350];
  int PP_size[2];
  double n;
  double PolygonList[700];
  signed char b[50];
  int nx;
  double C_Cnt[4];
  emxArray_real_T *ccc;
  emxArray_real_T *newPolygonList;
  emxArray_real_T *newPolygonListPP;
  double i;
  double tt;
  double newPolygonnum;
  emxArray_real_T *row;
  emxArray_real_T *mm;
  emxArray_boolean_T *x;
  emxArray_int32_T *b_ii;
  int exitg2;
  boolean_T guard1 = false;
  boolean_T tf_data[100];
  boolean_T rowmatch;
  boolean_T exitg5;
  double absxk;
  int exponent;
  boolean_T p;
  boolean_T exitg4;
  boolean_T guard2 = false;
  boolean_T exitg3;
  boolean_T exitg6;
  boolean_T guard3 = false;
  emxArray_real_T *Aera;
  unsigned int C_Aera;
  emxArray_real_T *r3;
  emxArray_real_T *b_newPolygonList;
  emxArray_real_T *c_newPolygonList;
  emxArray_real_T *b_ccc;
  emxArray_real_T *d_newPolygonList;
  emxArray_real_T *e_newPolygonList;
  double FFLOG0;
  double YouXiao_data[200];
  int YouXiao_size[2];
  double ct;
  int b_YouXiao_size[2];
  boolean_T exitg1;
  double b_Aera[3];
  emxArray_real_T *c_ccc;
  memset(&YouXiao[0], 0, 200U * sizeof(double));
  if (1.0 > N) {
    itmp = 0;
  } else {
    itmp = (int)N;
  }

  b_PointLast_size[0] = itmp;
  b_PointLast_size[1] = 2;
  for (i10 = 0; i10 < 2; i10++) {
    for (idx = 0; idx < itmp; idx++) {
      b_PointLast_data[idx + itmp * i10] = PointLast_data[idx + PointLast_size[0]
        * i10];
    }
  }

  c_Calculate_New_Indented_Bounda(b_PointLast_data, b_PointLast_size, N, PP, &d2,
    PPP, &d1);

  // PPP为经过倒置、加列处理后的的七列顶点集，~为原顶点集倒置后的点集，PP为无序的交点集矩阵，也经过处理变成了七列的矩阵 
  Sort(PP, d2);

  // 对交点进行小序号边的起点进行排序，方便插入原顶点集
  if (1.0 > d1) {
    itmp = 0;
  } else {
    itmp = (int)d1;
  }

  if (1.0 > d2) {
    ii = 0;
  } else {
    ii = (int)d2;
  }

  PPP_size[0] = itmp;
  PPP_size[1] = 7;
  PP_size[0] = ii;
  PP_size[1] = 7;
  for (i10 = 0; i10 < 7; i10++) {
    for (idx = 0; idx < itmp; idx++) {
      PPP_data[idx + itmp * i10] = PPP[idx + 100 * i10];
    }

    for (idx = 0; idx < ii; idx++) {
      PP_data[idx + ii * i10] = PP[idx + 50 * i10];
    }
  }

  CalculateIntersection(PPP_data, PPP_size, d1, PP_data, PP_size, d2,
                        PolygonList, &n);

  // 中和交点的顶点集
  // [PolygonList(1:100,1:7),n(1,1)] = Preprocessing(PolygonList(1:n(1,1),1:7),n(1,1));%去除交点和原顶点相同的点 
  // 经切割后，简单多边形的个数
  for (nx = 0; nx < 50; nx++) {
    b[nx] = 0;
  }

  for (i10 = 0; i10 < 4; i10++) {
    C_Cnt[i10] = 0.0;
  }

  emxInit_real_T1(&ccc, 1);

  // 用于下标计数用
  i10 = ccc->size[0];
  ccc->size[0] = (int)n;
  emxEnsureCapacity((emxArray__common *)ccc, i10, (int)sizeof(double));
  itmp = (int)n;
  for (i10 = 0; i10 < itmp; i10++) {
    ccc->data[i10] = 0.0;
  }

  emxInit_real_T(&newPolygonList, 2);
  i10 = newPolygonList->size[0] * newPolygonList->size[1];
  newPolygonList->size[0] = (int)n;
  newPolygonList->size[1] = 7;
  emxEnsureCapacity((emxArray__common *)newPolygonList, i10, (int)sizeof(double));
  itmp = (int)n * 7;
  for (i10 = 0; i10 < itmp; i10++) {
    newPolygonList->data[i10] = 0.0;
  }

  emxInit_real_T(&newPolygonListPP, 2);
  i = 1.0;
  tt = 1.0;
  newPolygonnum = 1.0;
  i10 = newPolygonListPP->size[0] * newPolygonListPP->size[1];
  newPolygonListPP->size[0] = (int)n;
  newPolygonListPP->size[1] = 7;
  emxEnsureCapacity((emxArray__common *)newPolygonListPP, i10, (int)sizeof
                    (double));
  itmp = (int)n * 7;
  for (i10 = 0; i10 < itmp; i10++) {
    newPolygonListPP->data[i10] = 0.0;
  }

  for (i10 = 0; i10 < 7; i10++) {
    newPolygonListPP->data[newPolygonListPP->size[0] * i10] = PolygonList[100 *
      i10];
  }

  emxInit_real_T1(&row, 1);

  // 每个新环的存储矩阵
  C_Cnt[1] = 1.0;
  PolygonList[100] = 1.0;
  i10 = row->size[0];
  row->size[0] = (int)n;
  emxEnsureCapacity((emxArray__common *)row, i10, (int)sizeof(double));
  itmp = (int)n;
  for (i10 = 0; i10 < itmp; i10++) {
    row->data[i10] = 0.0;
  }

  // 用于查找结果存储
  emxInit_real_T1(&mm, 1);
  emxInit_boolean_T(&x, 1);
  emxInit_int32_T(&b_ii, 1);
  do {
    exitg2 = 0;
    i++;

    // %step4
    if (i == n + 1.0) {
      i = 1.0;
    }

    guard1 = false;
    if ((PolygonList[(int)i + 199] == 1.0) && ((PolygonList[(int)i + 299] !=
          newPolygonListPP->data[newPolygonListPP->size[0] * 3]) ||
         (PolygonList[(int)i + 399] != newPolygonListPP->data
          [newPolygonListPP->size[0] << 2]))) {
      // 判断是否为交点
      C_Cnt[0]++;
      b[(int)C_Cnt[0] - 1] = (signed char)i;
      C_Cnt[1]++;
      for (i10 = 0; i10 < 7; i10++) {
        newPolygonListPP->data[((int)C_Cnt[1] + newPolygonListPP->size[0] * i10)
          - 1] = PolygonList[((int)i + 100 * i10) - 1];
      }

      // %以便此处添加一行
      if (1.0 > n) {
        itmp = 0;
      } else {
        itmp = (int)n;
      }

      for (i10 = 0; i10 < itmp; i10++) {
        tf_data[i10] = false;
      }

      for (ii = 0; ii + 1 <= itmp; ii++) {
        tf_data[ii] = false;
        rowmatch = true;
        nx = 0;
        exitg5 = false;
        while ((!exitg5) && (nx + 1 < 8)) {
          absxk = fabs(PolygonList[((int)i + 100 * nx) - 1] / 2.0);
          if ((!rtIsInf(absxk)) && (!rtIsNaN(absxk))) {
            if (absxk <= 2.2250738585072014E-308) {
              absxk = 4.94065645841247E-324;
            } else {
              frexp(absxk, &exponent);
              absxk = ldexp(1.0, exponent - 53);
            }
          } else {
            absxk = rtNaN;
          }

          if ((fabs(PolygonList[((int)i + 100 * nx) - 1] - PolygonList[ii + 100 *
                    nx]) < absxk) || (rtIsInf(PolygonList[ii + 100 * nx]) &&
               rtIsInf(PolygonList[((int)i + 100 * nx) - 1]) && ((PolygonList[ii
                 + 100 * nx] > 0.0) == (PolygonList[((int)i + 100 * nx) - 1] >
                 0.0)))) {
            p = true;
          } else {
            p = false;
          }

          if (!p) {
            rowmatch = false;
            exitg5 = true;
          } else {
            nx++;
          }
        }

        if (rowmatch) {
          tf_data[ii] = true;
        }
      }

      for (i10 = 0; i10 < itmp; i10++) {
        row->data[i10] = tf_data[i10];
      }

      if (1.0 > n) {
        itmp = 0;
      } else {
        itmp = (int)n;
      }

      i10 = x->size[0];
      x->size[0] = itmp;
      emxEnsureCapacity((emxArray__common *)x, i10, (int)sizeof(boolean_T));
      for (i10 = 0; i10 < itmp; i10++) {
        x->data[i10] = (row->data[i10] == 1.0);
      }

      nx = x->size[0];
      idx = 0;
      i10 = b_ii->size[0];
      b_ii->size[0] = x->size[0];
      emxEnsureCapacity((emxArray__common *)b_ii, i10, (int)sizeof(int));
      ii = 1;
      exitg4 = false;
      while ((!exitg4) && (ii <= nx)) {
        guard2 = false;
        if (x->data[ii - 1]) {
          idx++;
          b_ii->data[idx - 1] = ii;
          if (idx >= nx) {
            exitg4 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          ii++;
        }
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          i10 = b_ii->size[0];
          b_ii->size[0] = 0;
          emxEnsureCapacity((emxArray__common *)b_ii, i10, (int)sizeof(int));
        }
      } else {
        i10 = b_ii->size[0];
        if (1 > idx) {
          b_ii->size[0] = 0;
        } else {
          b_ii->size[0] = idx;
        }

        emxEnsureCapacity((emxArray__common *)b_ii, i10, (int)sizeof(int));
      }

      i10 = mm->size[0];
      mm->size[0] = b_ii->size[0];
      emxEnsureCapacity((emxArray__common *)mm, i10, (int)sizeof(double));
      itmp = b_ii->size[0];
      for (i10 = 0; i10 < itmp; i10++) {
        mm->data[i10] = b_ii->data[i10];
      }

      if (mm->size[0] == 1) {
        if (PolygonList[(int)i + 599] + 1.0 > d1) {
          // 经过加一处理后，m(1,3)可能超过了未插入交点前的点集的点数
          i = 0.0;
        } else {
          ii = 0;
          exitg3 = false;
          while ((!exitg3) && (ii <= (int)n - 1)) {
            if (PolygonList[ii] == PolygonList[(int)i + 599] + 1.0) {
              i = (1.0 + (double)ii) - 1.0;
              exitg3 = true;
            } else {
              ii++;
            }
          }

          // m(1,4) = find(PolygonList(1:n(1,1),1)==m(1,3));
          // i = m(1,4)-1;
        }
      } else {
        i = mm->data[1];
      }

      guard1 = true;
    } else {
      // %Step6
      if ((PolygonList[(int)i + 299] != newPolygonListPP->data
           [newPolygonListPP->size[0] * 3]) || ((PolygonList[(int)i + 399] !=
            newPolygonListPP->data[newPolygonListPP->size[0] << 2]) &&
           (PolygonList[(int)i + 99] == 0.0))) {
        C_Cnt[1]++;
        for (i10 = 0; i10 < 7; i10++) {
          newPolygonListPP->data[((int)C_Cnt[1] + newPolygonListPP->size[0] *
            i10) - 1] = PolygonList[((int)i + 100 * i10) - 1];
        }

        // %以便此处添加一行
        PolygonList[(int)i + 99] = 1.0;
        guard1 = true;
      } else {
        PolygonList[(int)i + 99] = 1.0;
        C_Cnt[2]++;
        ccc->data[(int)C_Cnt[2] - 1] = C_Cnt[1];

        // 存储每个环的顶点数
        i10 = b_ii->size[0];
        b_ii->size[0] = (int)(C_Cnt[1] - 1.0) + 1;
        emxEnsureCapacity((emxArray__common *)b_ii, i10, (int)sizeof(int));
        itmp = (int)(C_Cnt[1] - 1.0);
        for (i10 = 0; i10 <= itmp; i10++) {
          b_ii->data[i10] = (int)(C_Cnt[3] + (1.0 + (double)i10)) - 1;
        }

        itmp = (int)C_Cnt[1] - 1;
        for (i10 = 0; i10 < 7; i10++) {
          for (idx = 0; idx <= itmp; idx++) {
            newPolygonList->data[b_ii->data[idx] + newPolygonList->size[0] * i10]
              = newPolygonListPP->data[idx + newPolygonListPP->size[0] * i10];
          }
        }

        C_Cnt[3] += C_Cnt[1];
        newPolygonnum++;

        // 再次申请一个新的静态矩阵形式的空间
        i10 = newPolygonListPP->size[0] * newPolygonListPP->size[1];
        newPolygonListPP->size[0] = (int)n;
        newPolygonListPP->size[1] = 7;
        emxEnsureCapacity((emxArray__common *)newPolygonListPP, i10, (int)sizeof
                          (double));
        itmp = (int)n * 7;
        for (i10 = 0; i10 < itmp; i10++) {
          newPolygonListPP->data[i10] = 0.0;
        }

        if (1.0 > n) {
          itmp = 0;
        } else {
          itmp = (int)n;
        }

        i10 = x->size[0];
        x->size[0] = itmp;
        emxEnsureCapacity((emxArray__common *)x, i10, (int)sizeof(boolean_T));
        for (i10 = 0; i10 < itmp; i10++) {
          x->data[i10] = (PolygonList[100 + i10] == 0.0);
        }

        nx = x->size[0];
        idx = 0;
        i10 = b_ii->size[0];
        b_ii->size[0] = x->size[0];
        emxEnsureCapacity((emxArray__common *)b_ii, i10, (int)sizeof(int));
        ii = 1;
        exitg6 = false;
        while ((!exitg6) && (ii <= nx)) {
          guard3 = false;
          if (x->data[ii - 1]) {
            idx++;
            b_ii->data[idx - 1] = ii;
            if (idx >= nx) {
              exitg6 = true;
            } else {
              guard3 = true;
            }
          } else {
            guard3 = true;
          }

          if (guard3) {
            ii++;
          }
        }

        if (x->size[0] == 1) {
          if (idx == 0) {
            i10 = b_ii->size[0];
            b_ii->size[0] = 0;
            emxEnsureCapacity((emxArray__common *)b_ii, i10, (int)sizeof(int));
          }
        } else {
          i10 = b_ii->size[0];
          if (1 > idx) {
            b_ii->size[0] = 0;
          } else {
            b_ii->size[0] = idx;
          }

          emxEnsureCapacity((emxArray__common *)b_ii, i10, (int)sizeof(int));
        }

        // 判断是否访问完了
        if (b_ii->size[0] == 0) {
          exitg2 = 1;
        } else {
          for (i10 = 0; i10 < 7; i10++) {
            newPolygonListPP->data[newPolygonListPP->size[0] * i10] =
              PolygonList[(b[(int)(newPolygonnum - 1.0) - 1] + 100 * i10) - 1];
          }

          // 重新开始一个环循环
          PolygonList[b[(int)(newPolygonnum - 1.0) - 1] + 99] = 1.0;
          C_Cnt[1] = 1.0;
          i = b[(int)(newPolygonnum - 1.0) - 1];
          guard1 = true;
        }
      }
    }

    if (guard1) {
      tt++;
      if (tt >= 100.0 + d2 * 3.0) {
        exitg2 = 1;
      }
    }
  } while (exitg2 == 0);

  emxFree_int32_T(&b_ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&mm);
  emxFree_real_T(&row);
  emxFree_real_T(&newPolygonListPP);
  emxInit_real_T(&Aera, 2);

  // %
  i10 = Aera->size[0] * Aera->size[1];
  Aera->size[0] = (int)C_Cnt[2];
  Aera->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)Aera, i10, (int)sizeof(double));
  itmp = (int)C_Cnt[2] * 3;
  for (i10 = 0; i10 < itmp; i10++) {
    Aera->data[i10] = 0.0;
  }

  C_Aera = 0U;
  if (C_Cnt[2] == 1.0) {
    if (1.0 > C_Cnt[3]) {
      itmp = -1;
    } else {
      itmp = (int)C_Cnt[3] - 1;
    }

    for (i10 = 0; i10 < 2; i10++) {
      for (idx = 0; idx <= itmp; idx++) {
        YouXiao[idx + 100 * i10] = newPolygonList->data[idx +
          newPolygonList->size[0] * (3 + i10)];
      }
    }

    *YX_Cnt = C_Cnt[3];
  } else {
    nx = 0;
    emxInit_real_T(&r3, 2);
    emxInit_real_T1(&b_newPolygonList, 1);
    emxInit_real_T1(&c_newPolygonList, 1);
    emxInit_real_T1(&b_ccc, 1);
    emxInit_real_T1(&d_newPolygonList, 1);
    emxInit_real_T1(&e_newPolygonList, 1);
    while (nx <= (int)C_Cnt[2] - 1) {
      if (1.0 + (double)nx == 1.0) {
        if (1.0 > ccc->data[0]) {
          itmp = 0;
        } else {
          itmp = (int)ccc->data[0];
        }

        if (1.0 > ccc->data[0]) {
          ii = 0;
        } else {
          ii = (int)ccc->data[0];
        }

        i10 = d_newPolygonList->size[0];
        d_newPolygonList->size[0] = itmp;
        emxEnsureCapacity((emxArray__common *)d_newPolygonList, i10, (int)sizeof
                          (double));
        for (i10 = 0; i10 < itmp; i10++) {
          d_newPolygonList->data[i10] = newPolygonList->data[i10 +
            newPolygonList->size[0] * 3];
        }

        i10 = e_newPolygonList->size[0];
        e_newPolygonList->size[0] = ii;
        emxEnsureCapacity((emxArray__common *)e_newPolygonList, i10, (int)sizeof
                          (double));
        for (i10 = 0; i10 < ii; i10++) {
          e_newPolygonList->data[i10] = newPolygonList->data[i10 +
            (newPolygonList->size[0] << 2)];
        }

        FFLOG0 = judgeClockWise(d_newPolygonList, e_newPolygonList, ccc->data[0]);
        if (FFLOG0 == 0.0) {
          if (1.0 > ccc->data[0]) {
            itmp = -1;
          } else {
            itmp = (int)ccc->data[0] - 1;
          }

          for (i10 = 0; i10 < 2; i10++) {
            for (idx = 0; idx <= itmp; idx++) {
              YouXiao[idx + 100 * i10] = newPolygonList->data[idx +
                newPolygonList->size[0] * (3 + i10)];
            }
          }

          C_Aera++;
          if (1.0 > ccc->data[0]) {
            itmp = 0;
          } else {
            itmp = (int)ccc->data[0];
          }

          YouXiao_size[0] = itmp;
          YouXiao_size[1] = 2;
          for (i10 = 0; i10 < 2; i10++) {
            for (idx = 0; idx < itmp; idx++) {
              YouXiao_data[idx + itmp * i10] = YouXiao[idx + 100 * i10];
            }
          }

          d2 = Calculate_Area(YouXiao_data, YouXiao_size, ccc->data[0]);
          Aera->data[(int)C_Aera - 1] = d2;
          Aera->data[((int)C_Aera + Aera->size[0]) - 1] = ccc->data[0];
          Aera->data[((int)C_Aera + (Aera->size[0] << 1)) - 1] = 1.0;

          // Mianji = [Mianji;[CalculateMianji(YouXiao,ccc(i)),ccc(i),i]];
        }

        // FFLOGzong = [FFLOGzong;FFLOG0];
      } else {
        itmp = (int)((1.0 + (double)nx) - 1.0);
        i10 = b_ccc->size[0];
        b_ccc->size[0] = (int)((1.0 + (double)nx) - 1.0);
        emxEnsureCapacity((emxArray__common *)b_ccc, i10, (int)sizeof(double));
        for (i10 = 0; i10 < itmp; i10++) {
          b_ccc->data[i10] = ccc->data[i10];
        }

        ct = sum(b_ccc);
        d2 = ccc->data[nx];
        i10 = b_newPolygonList->size[0];
        b_newPolygonList->size[0] = (int)floor(d2 - 1.0) + 1;
        emxEnsureCapacity((emxArray__common *)b_newPolygonList, i10, (int)sizeof
                          (double));
        itmp = (int)floor(d2 - 1.0);
        for (i10 = 0; i10 <= itmp; i10++) {
          b_newPolygonList->data[i10] = newPolygonList->data[((int)(ct + (double)
            (i10 + 1)) + newPolygonList->size[0] * 3) - 1];
        }

        d2 = ccc->data[nx];
        i10 = c_newPolygonList->size[0];
        c_newPolygonList->size[0] = (int)floor(d2 - 1.0) + 1;
        emxEnsureCapacity((emxArray__common *)c_newPolygonList, i10, (int)sizeof
                          (double));
        itmp = (int)floor(d2 - 1.0);
        for (i10 = 0; i10 <= itmp; i10++) {
          c_newPolygonList->data[i10] = newPolygonList->data[((int)(ct + (double)
            (i10 + 1)) + (newPolygonList->size[0] << 2)) - 1];
        }

        FFLOG0 = judgeClockWise(b_newPolygonList, c_newPolygonList, ccc->data[nx]);
        if (FFLOG0 == 0.0) {
          d2 = ccc->data[nx];
          i10 = r3->size[0] * r3->size[1];
          r3->size[0] = (int)floor(d2 - 1.0) + 1;
          r3->size[1] = 2;
          emxEnsureCapacity((emxArray__common *)r3, i10, (int)sizeof(double));
          for (i10 = 0; i10 < 2; i10++) {
            itmp = (int)floor(d2 - 1.0);
            for (idx = 0; idx <= itmp; idx++) {
              r3->data[idx + r3->size[0] * i10] = newPolygonList->data[((int)(ct
                + (double)(idx + 1)) + newPolygonList->size[0] * (3 + i10)) - 1];
            }
          }

          for (i10 = 0; i10 < 2; i10++) {
            itmp = r3->size[0];
            for (idx = 0; idx < itmp; idx++) {
              YouXiao[idx + 100 * i10] = r3->data[idx + r3->size[0] * i10];
            }
          }

          C_Aera++;
          if (1.0 > ccc->data[nx]) {
            itmp = 0;
          } else {
            itmp = (int)ccc->data[nx];
          }

          b_YouXiao_size[0] = itmp;
          b_YouXiao_size[1] = 2;
          for (i10 = 0; i10 < 2; i10++) {
            for (idx = 0; idx < itmp; idx++) {
              YouXiao_data[idx + itmp * i10] = YouXiao[idx + 100 * i10];
            }
          }

          d2 = Calculate_Area(YouXiao_data, b_YouXiao_size, ccc->data[nx]);
          Aera->data[(int)C_Aera - 1] = d2;
          Aera->data[((int)C_Aera + Aera->size[0]) - 1] = ccc->data[nx];
          Aera->data[((int)C_Aera + (Aera->size[0] << 1)) - 1] = 1.0 + (double)
            nx;

          // Mianji = [Mianji;[CalculateMianji(YouXiao,ccc(i)),ccc(i),i]];
        }
      }

      nx++;
    }

    emxFree_real_T(&e_newPolygonList);
    emxFree_real_T(&d_newPolygonList);
    emxFree_real_T(&b_ccc);
    emxFree_real_T(&c_newPolygonList);
    emxFree_real_T(&b_newPolygonList);
    memset(&YouXiao[0], 0, 200U * sizeof(double));
    nx = 1;
    idx = Aera->size[0];
    absxk = Aera->data[0];
    itmp = 0;
    i10 = Aera->size[0];
    if (i10 > 1) {
      if (rtIsNaN(absxk)) {
        ii = 2;
        exitg1 = false;
        while ((!exitg1) && (ii <= idx)) {
          nx = ii;
          if (!rtIsNaN(Aera->data[ii - 1])) {
            absxk = Aera->data[ii - 1];
            itmp = ii - 1;
            exitg1 = true;
          } else {
            ii++;
          }
        }
      }

      i10 = Aera->size[0];
      if (nx < i10) {
        while (nx + 1 <= idx) {
          if (Aera->data[nx] > absxk) {
            absxk = Aera->data[nx];
            itmp = nx;
          }

          nx++;
        }
      }
    }

    // 找到第一列最大值的序号
    for (i10 = 0; i10 < 3; i10++) {
      b_Aera[i10] = Aera->data[itmp + Aera->size[0] * i10];
    }

    for (i10 = 0; i10 < 3; i10++) {
      Aera->data[Aera->size[0] * i10] = b_Aera[i10];
    }

    // 显示最大值所在的一行的元素
    if (Aera->data[Aera->size[0] << 1] == 1.0) {
      if (1.0 > Aera->data[Aera->size[0]]) {
        itmp = -1;
      } else {
        itmp = (int)Aera->data[Aera->size[0]] - 1;
      }

      for (i10 = 0; i10 < 2; i10++) {
        for (idx = 0; idx <= itmp; idx++) {
          YouXiao[idx + 100 * i10] = newPolygonList->data[idx +
            newPolygonList->size[0] * (3 + i10)];
        }
      }

      *YX_Cnt = Aera->data[Aera->size[0]];
    } else {
      if (1.0 > Aera->data[Aera->size[0] << 1] - 1.0) {
        itmp = 0;
      } else {
        itmp = (int)(Aera->data[Aera->size[0] << 1] - 1.0);
      }

      emxInit_real_T1(&c_ccc, 1);
      i10 = c_ccc->size[0];
      c_ccc->size[0] = itmp;
      emxEnsureCapacity((emxArray__common *)c_ccc, i10, (int)sizeof(double));
      for (i10 = 0; i10 < itmp; i10++) {
        c_ccc->data[i10] = ccc->data[i10];
      }

      ct = sum(c_ccc);
      emxFree_real_T(&c_ccc);
      d2 = Aera->data[Aera->size[0]];
      i10 = r3->size[0] * r3->size[1];
      r3->size[0] = (int)floor(d2 - 1.0) + 1;
      r3->size[1] = 2;
      emxEnsureCapacity((emxArray__common *)r3, i10, (int)sizeof(double));
      for (i10 = 0; i10 < 2; i10++) {
        itmp = (int)floor(d2 - 1.0);
        for (idx = 0; idx <= itmp; idx++) {
          r3->data[idx + r3->size[0] * i10] = newPolygonList->data[((int)(ct +
            (double)(idx + 1)) + newPolygonList->size[0] * (3 + i10)) - 1];
        }
      }

      for (i10 = 0; i10 < 2; i10++) {
        itmp = r3->size[0];
        for (idx = 0; idx < itmp; idx++) {
          YouXiao[idx + 100 * i10] = r3->data[idx + r3->size[0] * i10];
        }
      }

      *YX_Cnt = Aera->data[Aera->size[0]];
    }

    emxFree_real_T(&r3);
  }

  emxFree_real_T(&Aera);
  emxFree_real_T(&newPolygonList);
  emxFree_real_T(&ccc);
}

//
// File trailer for Calculate_Effective_Point.cpp
//
// [EOF]
//
