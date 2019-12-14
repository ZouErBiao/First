//
// File: Calculate_New_Indented_Boundary_Point.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "Calculate_New_Indented_Boundary_Point.h"
#include "CalculateLineCrossover.h"
#include "Judge_Intersect.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "flipud.h"

// Function Definitions

//
// {
// ���룺
// Point:������ĵ㼯����ʽΪP_Cnt����2�ľ���
// P_Cnt:�������
// �����
// PP�����ߵĽ��㼯����ʽΪn����7�ľ���
// PPP�����ߵĶ��㼯����ʽΪn����7�ľ���
// }
// Arguments    : const double Point_data[]
//                const int Point_size[2]
//                double P_Cnt
//                double PP[350]
//                double *PP_Cnt
//                double PPP[700]
//                double *PPP_Cnt
// Return Type  : void
//
void c_Calculate_New_Indented_Bounda(const double Point_data[], const int
  Point_size[2], double P_Cnt, double PP[350], double *PP_Cnt, double PPP[700],
  double *PPP_Cnt)
{
  emxArray_real_T *Pointss;
  int i5;
  int loop_ub;
  int tmp_size[2];
  int i6;
  double tmp_data[510];
  int i;
  int k;
  int j;
  static const signed char iv0[3] = { 0, 0, 1 };

  double dv2[2];
  emxInit_real_T(&Pointss, 2);
  *PPP_Cnt = P_Cnt;
  i5 = Pointss->size[0] * Pointss->size[1];
  Pointss->size[0] = (int)P_Cnt;
  Pointss->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)Pointss, i5, (int)sizeof(double));
  loop_ub = (int)P_Cnt << 1;
  for (i5 = 0; i5 < loop_ub; i5++) {
    Pointss->data[i5] = 0.0;
  }

  if (1.0 > P_Cnt) {
    loop_ub = 0;
  } else {
    loop_ub = (int)P_Cnt;
  }

  tmp_size[0] = loop_ub;
  tmp_size[1] = 2;
  for (i5 = 0; i5 < 2; i5++) {
    for (i6 = 0; i6 < loop_ub; i6++) {
      tmp_data[i6 + loop_ub * i5] = Point_data[i6 + Point_size[0] * i5];
    }
  }

  flipud(tmp_data, tmp_size);
  for (i5 = 0; i5 < 2; i5++) {
    loop_ub = tmp_size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      Pointss->data[i6 + Pointss->size[0] * i5] = tmp_data[i6 + tmp_size[0] * i5];
    }
  }

  // ���ñ����ʱ��
  memset(&PPP[0], 0, 700U * sizeof(double));

  // %�˴��Ѵ�����ĵ㼯������еľ���
  for (i = 0; i < (int)P_Cnt; i++) {
    PPP[i] = 1.0 + (double)i;

    // ԭ����ζ����ţ�1,2,3.......
    for (i5 = 0; i5 < 2; i5++) {
      PPP[i + 100 * (1 + i5)] = 0.0;
    }

    // �ڶ��зŸõ��Ƿ񱻷��ʱ��0Ϊû���ʣ�1�������ʣ�������Ϊ�Ƿ��ǽ����ǣ�1Ϊ�ǽ��㣬0Ϊ���ǽ��� 
    for (i5 = 0; i5 < 2; i5++) {
      PPP[i + 100 * (3 + i5)] = Pointss->data[i + Pointss->size[0] * i5];
    }

    // ��������
    for (i5 = 0; i5 < 2; i5++) {
      PPP[i + 100 * (5 + i5)] = 0.0;
    }

    // �����д�Ž����С��űߵ���㣬�����ִ�Ž���Ĵ���űߵ���㣬����Ϊ��
  }

  memset(&PP[0], 0, 350U * sizeof(double));

  // ���ڼ�¼������Ϣ��8�о���
  k = -1;

  // PPΪ���㼯
  for (i = 0; i < (int)(P_Cnt + -2.0); i++) {
    if (3.0 + (double)i < P_Cnt) {
      for (j = 0; j < (int)((3.0 + (double)i) - 2.0); j++) {
        // 0Ϊ���ཻ������Ϊ�ཻ
        if (Judge_Intersect(Pointss->data[i + 2], Pointss->data[(i +
              Pointss->size[0]) + 2], Pointss->data[(int)((3.0 + (double)i) +
              1.0) - 1], Pointss->data[((int)((3.0 + (double)i) + 1.0) +
              Pointss->size[0]) - 1], Pointss->data[j], Pointss->data[j +
                            Pointss->size[0]], Pointss->data[(int)((1.0 +
               (double)j) + 1.0) - 1], Pointss->data[((int)((1.0 + (double)j) +
               1.0) + Pointss->size[0]) - 1]) != 0.0) {
          k++;
          for (i5 = 0; i5 < 3; i5++) {
            PP[k + 50 * i5] = iv0[i5];
          }

          // ���λΪ�㣬���ʱ��λΪ0���Ƿ񽻵�λΪ1��
          CalculateLineCrossover(Pointss->data[i + 2], Pointss->data[(i +
            Pointss->size[0]) + 2], Pointss->data[(int)((3.0 + (double)i) + 1.0)
            - 1], Pointss->data[((int)((3.0 + (double)i) + 1.0) + Pointss->size
            [0]) - 1], Pointss->data[j], Pointss->data[j + Pointss->size[0]],
            Pointss->data[(int)((1.0 + (double)j) + 1.0) - 1], Pointss->data
            [((int)((1.0 + (double)j) + 1.0) + Pointss->size[0]) - 1], dv2);
          for (i5 = 0; i5 < 2; i5++) {
            PP[k + 50 * (3 + i5)] = dv2[i5];
          }

          PP[250 + k] = 1.0 + (double)j;
          PP[300 + k] = 3.0 + (double)i;
        }
      }
    } else {
      for (j = 0; j < (int)(((3.0 + (double)i) - 2.0) + -1.0); j++) {
        // 0Ϊ���ཻ������Ϊ�ཻ
        if (Judge_Intersect(Pointss->data[i + 2], Pointss->data[(i +
              Pointss->size[0]) + 2], Pointss->data[0], Pointss->data
                            [Pointss->size[0]], Pointss->data[j + 1],
                            Pointss->data[(j + Pointss->size[0]) + 1],
                            Pointss->data[(int)((2.0 + (double)j) + 1.0) - 1],
                            Pointss->data[((int)((2.0 + (double)j) + 1.0) +
              Pointss->size[0]) - 1]) != 0.0) {
          k++;
          for (i5 = 0; i5 < 3; i5++) {
            PP[k + 50 * i5] = iv0[i5];
          }

          // ���λΪ�㣬���ʱ��λΪ0���Ƿ񽻵�λΪ1��
          CalculateLineCrossover(Pointss->data[i + 2], Pointss->data[(i +
            Pointss->size[0]) + 2], Pointss->data[0], Pointss->data
            [Pointss->size[0]], Pointss->data[j + 1], Pointss->data[(j +
            Pointss->size[0]) + 1], Pointss->data[(int)((2.0 + (double)j) + 1.0)
            - 1], Pointss->data[((int)((2.0 + (double)j) + 1.0) + Pointss->size
            [0]) - 1], dv2);
          for (i5 = 0; i5 < 2; i5++) {
            PP[k + 50 * (3 + i5)] = dv2[i5];
          }

          PP[250 + k] = 2.0 + (double)j;
          PP[300 + k] = 3.0 + (double)i;
        }
      }
    }
  }

  emxFree_real_T(&Pointss);
  *PP_Cnt = k + 1;
}

//
// File trailer for Calculate_New_Indented_Boundary_Point.cpp
//
// [EOF]
//
