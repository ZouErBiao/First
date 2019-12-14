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
// ���������ݽ���Ԥ�����ų��غϺ�����������ͬһ��ֱ���ϵ����
// {
// ���룺
// PointΪ����ı߽��
// P_Cnt:�߽��ĸ���
// �����
// PrepΪ����ȥ�غ�ȥ��������������ĵ㼯�Ľṹ�壬��ʽΪ50����2
// Prep.Preprocessing:��ʽΪ50����2
// Prep.Cnt:��Ч��ĸ���
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

  // P_M�ĵ������Ǳ�־λ��Ϊ1�Ļ��������ɾ��
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

  // ������Ҫ���ǧ��֮��
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

    // Ϊ��ռλ���ظ��ĵط��滻Ϊ����ֵ���滻ֵҪ������Ҫ�����ݲɼ����ظ����ɼ���ǡ�����ֵ��ȵĸ��ʼ��ͣ�������ֵ���ȡ�ؿ���ڲ�һ�㣩 
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

      // ������Ҫ���ǧ��֮��
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
  // �������ظ��ĵ�
  i2 = Point_map->size[0] * Point_map->size[1];
  Point_map->size[0] = (int)(P_Cnt - Count);
  Point_map->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)Point_map, i2, (int)sizeof(double));
  ixstart = (int)(P_Cnt - Count) << 1;
  for (i2 = 0; i2 < ixstart; i2++) {
    Point_map->data[i2] = 0.0;
  }

  Cnt = 0;

  // ��һλ�����±����
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

  // ���ϴ������˵���ظ�����
  // %
  // %���´���������������ͬһ��ֱ���ϵ�����
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

  // ��λ����������
  // nΪ����
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

  // ���ߵĵ�λ����
  i2 = IndexPrepro->size[0];
  IndexPrepro->size[0] = Cnt;
  emxEnsureCapacity((emxArray__common *)IndexPrepro, i2, (int)sizeof(double));
  for (i2 = 0; i2 < Cnt; i2++) {
    IndexPrepro->data[i2] = 0.0;
  }

  // ��ǰ�浥λ������ȵĵ�ĵ�ŵĴ洢,������
  Index_Cnt = 0.0;
  if ((NEdgevectorList->data[0] == NEdgevectorList->data[Cnt - 1]) &&
      (NEdgevectorList->data[NEdgevectorList->size[0]] == NEdgevectorList->data
       [(Cnt + NEdgevectorList->size[0]) - 1])) {
    IndexPrepro->data[0] = 1.0;

    // ��ǰ�浥λ������ȵĵ��
  } else {
    Index_Cnt = 1.0;
    IndexPrepro->data[0] = 0.0;
  }

  for (i = 0; i <= Cnt - 2; i++) {
    if ((NEdgevectorList->data[i + 1] == NEdgevectorList->data[i]) &&
        (NEdgevectorList->data[(i + NEdgevectorList->size[0]) + 1] ==
         NEdgevectorList->data[i + NEdgevectorList->size[0]])) {
      IndexPrepro->data[i + 1] = 2.0 + (double)i;

      // ��ǰ�浥λ������ȵĵ� ��
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
