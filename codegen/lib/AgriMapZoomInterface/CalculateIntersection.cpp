//
// File: CalculateIntersection.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "CalculateIntersection.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "sortrows.h"

// Function Definitions

//
// 插入矩阵
// {
// 输入：
// PolygonList：被插入点集，格式为：PL_Cnt乘以7
// PL_Cnt：PolygonList的点个数
// IntersectionPointList：插入点的点集，格式为IP_Cnt乘以7
// IP_Cnt：IntersectionPointList的点的个数
// 输出：
// ppp：合并后的点集
// }
// Arguments    : const double PolygonList_data[]
//                const int PolygonList_size[2]
//                double PL_Cnt
//                const double IntersectionPointList_data[]
//                const int IntersectionPointList_size[2]
//                double IP_Cnt
//                double ppp[700]
//                double *p_Cnt
// Return Type  : void
//
void CalculateIntersection(const double PolygonList_data[], const int
  PolygonList_size[2], double PL_Cnt, const double IntersectionPointList_data[],
  const int IntersectionPointList_size[2], double IP_Cnt, double ppp[700],
  double *p_Cnt)
{
  int idx;
  int i11;
  int nx;
  double Count;
  int i;
  emxArray_real_T *cc;
  emxArray_real_T *dd;
  emxArray_real_T *r4;
  emxArray_real_T *b_i;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  emxArray_real_T *c_i;
  int b_ii;
  boolean_T exitg3;
  boolean_T guard3 = false;
  int m0_size_idx_0;
  int m0_data[50];
  boolean_T exitg2;
  boolean_T guard2 = false;
  int m1_data[50];
  double mm_data[100];
  double mc_idx_4;
  double mM_data[100];
  int j;
  double i_data[50];
  boolean_T exitg1;
  boolean_T guard1 = false;
  int mc_idx_3;
  int tt;
  memset(&ppp[0], 0, 700U * sizeof(double));
  *p_Cnt = 0.0;
  if (IP_Cnt == 0.0) {
    if (1.0 > PL_Cnt) {
      idx = -1;
    } else {
      idx = (int)PL_Cnt - 1;
    }

    for (i11 = 0; i11 < 7; i11++) {
      for (nx = 0; nx <= idx; nx++) {
        ppp[nx + 100 * i11] = PolygonList_data[nx + PolygonList_size[0] * i11];
      }
    }

    *p_Cnt = PL_Cnt;
  } else {
    Count = 0.0;
    i = 0;
    emxInit_real_T(&cc, 2);
    emxInit_real_T(&dd, 2);
    emxInit_real_T(&r4, 2);
    emxInit_real_T1(&b_i, 1);
    emxInit_boolean_T(&x, 1);
    emxInit_int32_T(&ii, 1);
    emxInit_real_T1(&c_i, 1);
    while (i <= (int)PL_Cnt - 1) {
      idx = IntersectionPointList_size[0];
      i11 = x->size[0];
      x->size[0] = IntersectionPointList_size[0];
      emxEnsureCapacity((emxArray__common *)x, i11, (int)sizeof(boolean_T));
      for (i11 = 0; i11 < idx; i11++) {
        x->data[i11] = (IntersectionPointList_data[i11 +
                        IntersectionPointList_size[0] * 5] == 1.0 + (double)i);
      }

      nx = x->size[0];
      idx = 0;
      i11 = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity((emxArray__common *)ii, i11, (int)sizeof(int));
      b_ii = 1;
      exitg3 = false;
      while ((!exitg3) && (b_ii <= nx)) {
        guard3 = false;
        if (x->data[b_ii - 1]) {
          idx++;
          ii->data[idx - 1] = b_ii;
          if (idx >= nx) {
            exitg3 = true;
          } else {
            guard3 = true;
          }
        } else {
          guard3 = true;
        }

        if (guard3) {
          b_ii++;
        }
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          i11 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity((emxArray__common *)ii, i11, (int)sizeof(int));
        }
      } else {
        i11 = ii->size[0];
        if (1 > idx) {
          ii->size[0] = 0;
        } else {
          ii->size[0] = idx;
        }

        emxEnsureCapacity((emxArray__common *)ii, i11, (int)sizeof(int));
      }

      i11 = b_i->size[0];
      b_i->size[0] = ii->size[0];
      emxEnsureCapacity((emxArray__common *)b_i, i11, (int)sizeof(double));
      idx = ii->size[0];
      for (i11 = 0; i11 < idx; i11++) {
        b_i->data[i11] = ii->data[i11];
      }

      m0_size_idx_0 = ii->size[0];
      idx = ii->size[0];
      for (i11 = 0; i11 < idx; i11++) {
        m0_data[i11] = ii->data[i11];
      }

      idx = IntersectionPointList_size[0];
      i11 = x->size[0];
      x->size[0] = IntersectionPointList_size[0];
      emxEnsureCapacity((emxArray__common *)x, i11, (int)sizeof(boolean_T));
      for (i11 = 0; i11 < idx; i11++) {
        x->data[i11] = (IntersectionPointList_data[i11 +
                        IntersectionPointList_size[0] * 6] == 1.0 + (double)i);
      }

      nx = x->size[0];
      idx = 0;
      i11 = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity((emxArray__common *)ii, i11, (int)sizeof(int));
      b_ii = 1;
      exitg2 = false;
      while ((!exitg2) && (b_ii <= nx)) {
        guard2 = false;
        if (x->data[b_ii - 1]) {
          idx++;
          ii->data[idx - 1] = b_ii;
          if (idx >= nx) {
            exitg2 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          b_ii++;
        }
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          i11 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity((emxArray__common *)ii, i11, (int)sizeof(int));
        }
      } else {
        i11 = ii->size[0];
        if (1 > idx) {
          ii->size[0] = 0;
        } else {
          ii->size[0] = idx;
        }

        emxEnsureCapacity((emxArray__common *)ii, i11, (int)sizeof(int));
      }

      i11 = c_i->size[0];
      c_i->size[0] = ii->size[0];
      emxEnsureCapacity((emxArray__common *)c_i, i11, (int)sizeof(double));
      idx = ii->size[0];
      for (i11 = 0; i11 < idx; i11++) {
        c_i->data[i11] = ii->data[i11];
      }

      b_ii = ii->size[0];
      idx = ii->size[0];
      for (i11 = 0; i11 < idx; i11++) {
        m1_data[i11] = ii->data[i11];
      }

      // 找到各交点所在边的起始顶点，并排续
      if ((c_i->size[0] == 0) && (b_i->size[0] == 0)) {
        Count++;
        for (i11 = 0; i11 < 7; i11++) {
          ppp[((int)Count + 100 * i11) - 1] = PolygonList_data[i +
            PolygonList_size[0] * i11];
        }
      } else {
        if (b_i->size[0] == 0) {
          idx = c_i->size[0];
          for (i11 = 0; i11 < idx; i11++) {
            mm_data[i11] = 0.0;
          }

          if (1 > b_ii) {
            idx = -1;
          } else {
            idx = b_ii - 1;
          }

          for (i11 = 0; i11 <= idx; i11++) {
            mm_data[i11] = m1_data[i11];
          }

          mc_idx_4 = c_i->size[0];
        } else {
          idx = c_i->size[0] + b_i->size[0];
          for (i11 = 0; i11 < idx; i11++) {
            mm_data[i11] = 0.0;
          }

          idx = c_i->size[0] + b_i->size[0];
          for (i11 = 0; i11 < idx; i11++) {
            mM_data[i11] = 0.0;
          }

          idx = m0_size_idx_0 - 1;
          for (i11 = 0; i11 <= idx; i11++) {
            mm_data[i11] = m0_data[i11];
          }

          mc_idx_4 = b_i->size[0];
          for (j = 0; j < c_i->size[0]; j++) {
            idx = (int)mc_idx_4;
            b_ii = c_i->size[0];
            for (i11 = 0; i11 < b_ii; i11++) {
              i_data[i11] = c_i->data[i11];
            }

            i11 = x->size[0];
            x->size[0] = (int)mc_idx_4;
            emxEnsureCapacity((emxArray__common *)x, i11, (int)sizeof(boolean_T));
            for (i11 = 0; i11 < idx; i11++) {
              x->data[i11] = (mm_data[i11] < i_data[j]);
            }

            nx = x->size[0];
            idx = 0;
            i11 = ii->size[0];
            ii->size[0] = x->size[0];
            emxEnsureCapacity((emxArray__common *)ii, i11, (int)sizeof(int));
            b_ii = 1;
            exitg1 = false;
            while ((!exitg1) && (b_ii <= nx)) {
              guard1 = false;
              if (x->data[b_ii - 1]) {
                idx++;
                ii->data[idx - 1] = b_ii;
                if (idx >= nx) {
                  exitg1 = true;
                } else {
                  guard1 = true;
                }
              } else {
                guard1 = true;
              }

              if (guard1) {
                b_ii++;
              }
            }

            if (x->size[0] == 1) {
              if (idx == 0) {
                i11 = ii->size[0];
                ii->size[0] = 0;
                emxEnsureCapacity((emxArray__common *)ii, i11, (int)sizeof(int));
              }
            } else {
              i11 = ii->size[0];
              if (1 > idx) {
                ii->size[0] = 0;
              } else {
                ii->size[0] = idx;
              }

              emxEnsureCapacity((emxArray__common *)ii, i11, (int)sizeof(int));
            }

            i11 = b_i->size[0];
            b_i->size[0] = ii->size[0];
            emxEnsureCapacity((emxArray__common *)b_i, i11, (int)sizeof(double));
            idx = ii->size[0];
            for (i11 = 0; i11 < idx; i11++) {
              b_i->data[i11] = ii->data[i11];
            }

            b_ii = ii->size[0];
            mc_idx_3 = ii->size[0];
            if (b_i->size[0] > 0) {
              idx = mc_idx_3 - 1;
              for (i11 = 0; i11 <= idx; i11++) {
                mM_data[i11] = mm_data[i11];
              }

              idx = c_i->size[0];
              for (i11 = 0; i11 < idx; i11++) {
                i_data[i11] = c_i->data[i11];
              }

              mM_data[b_i->size[0]] = i_data[j];
              if ((double)mc_idx_3 + 1.0 > mc_idx_4) {
                i11 = 1;
                nx = 0;
              } else {
                i11 = b_ii + 1;
                nx = (int)mc_idx_4;
              }

              if ((double)mc_idx_3 + 2.0 > mc_idx_4 + 1.0) {
                b_ii = 1;
              } else {
                b_ii += 2;
              }

              idx = nx - i11;
              for (nx = 0; nx <= idx; nx++) {
                mM_data[(b_ii + nx) - 1] = mm_data[(i11 + nx) - 1];
              }

              mc_idx_4++;
              idx = (int)mc_idx_4 - 1;
              for (i11 = 0; i11 <= idx; i11++) {
                mm_data[i11] = mM_data[i11];
              }
            } else {
              idx = c_i->size[0];
              for (i11 = 0; i11 < idx; i11++) {
                i_data[i11] = c_i->data[i11];
              }

              mM_data[0] = i_data[j];
              idx = (int)mc_idx_4 - 1;
              for (i11 = 0; i11 <= idx; i11++) {
                mM_data[1 + i11] = mm_data[i11];
              }

              mc_idx_4++;
              idx = (int)mc_idx_4 - 1;
              for (i11 = 0; i11 <= idx; i11++) {
                mm_data[i11] = mM_data[i11];
              }

              // 在开头处插入一个值
            }
          }

          // m0为以i为起始点的边上有几个交点
        }

        i11 = cc->size[0] * cc->size[1];
        cc->size[0] = (int)mc_idx_4;
        cc->size[1] = 2;
        emxEnsureCapacity((emxArray__common *)cc, i11, (int)sizeof(double));
        idx = (int)mc_idx_4 << 1;
        for (i11 = 0; i11 < idx; i11++) {
          cc->data[i11] = 1.0;
        }

        i11 = dd->size[0] * dd->size[1];
        dd->size[0] = (int)mc_idx_4;
        dd->size[1] = 2;
        emxEnsureCapacity((emxArray__common *)dd, i11, (int)sizeof(double));
        idx = (int)mc_idx_4 << 1;
        for (i11 = 0; i11 < idx; i11++) {
          dd->data[i11] = 0.0;
        }

        for (tt = 0; tt < (int)mc_idx_4; tt++) {
          cc->data[tt] = (IntersectionPointList_data[((int)mm_data[tt] +
            IntersectionPointList_size[0] * 3) - 1] - PolygonList_data[i +
                          PolygonList_size[0] * 3]) *
            (IntersectionPointList_data[((int)mm_data[tt] +
              IntersectionPointList_size[0] * 3) - 1] - PolygonList_data[i +
             PolygonList_size[0] * 3]) + (IntersectionPointList_data[((int)
            mm_data[tt] + (IntersectionPointList_size[0] << 2)) - 1] -
            PolygonList_data[i + (PolygonList_size[0] << 2)]) *
            (IntersectionPointList_data[((int)mm_data[tt] +
              (IntersectionPointList_size[0] << 2)) - 1] - PolygonList_data[i +
             (PolygonList_size[0] << 2)]);
          cc->data[tt + cc->size[0]] = mm_data[tt];
        }

        sortrows(cc);
        for (i11 = 0; i11 < 2; i11++) {
          idx = cc->size[0];
          for (nx = 0; nx < idx; nx++) {
            dd->data[nx + dd->size[0] * i11] = cc->data[nx + cc->size[0] * i11];
          }
        }

        // 对矩阵cc进行按第一列升序排列
        for (i11 = 0; i11 < 7; i11++) {
          ppp[((int)(Count + 1.0) + 100 * i11) - 1] = PolygonList_data[i +
            PolygonList_size[0] * i11];
        }

        Count++;
        i11 = ii->size[0];
        ii->size[0] = (int)(mc_idx_4 - 1.0) + 1;
        emxEnsureCapacity((emxArray__common *)ii, i11, (int)sizeof(int));
        idx = (int)(mc_idx_4 - 1.0);
        for (i11 = 0; i11 <= idx; i11++) {
          ii->data[i11] = (int)(Count + (1.0 + (double)i11)) - 1;
        }

        idx = dd->size[0];
        i11 = r4->size[0] * r4->size[1];
        r4->size[0] = idx;
        r4->size[1] = 7;
        emxEnsureCapacity((emxArray__common *)r4, i11, (int)sizeof(double));
        for (i11 = 0; i11 < 7; i11++) {
          for (nx = 0; nx < idx; nx++) {
            r4->data[nx + r4->size[0] * i11] = IntersectionPointList_data[((int)
              dd->data[nx + dd->size[0]] + IntersectionPointList_size[0] * i11)
              - 1];
          }
        }

        for (i11 = 0; i11 < 7; i11++) {
          idx = r4->size[0];
          for (nx = 0; nx < idx; nx++) {
            ppp[ii->data[nx] + 100 * i11] = r4->data[nx + r4->size[0] * i11];
          }
        }

        Count += mc_idx_4;
      }

      *p_Cnt = Count;
      i++;
    }

    emxFree_real_T(&c_i);
    emxFree_int32_T(&ii);
    emxFree_boolean_T(&x);
    emxFree_real_T(&b_i);
    emxFree_real_T(&r4);
    emxFree_real_T(&dd);
    emxFree_real_T(&cc);
  }
}

//
// File trailer for CalculateIntersection.cpp
//
// [EOF]
//
