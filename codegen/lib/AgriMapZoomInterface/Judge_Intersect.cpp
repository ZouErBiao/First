//
// File: Judge_Intersect.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "Judge_Intersect.h"

// Function Definitions

//
// �˺����������ж������߶��Ƿ��ཻ
// �����0Ϊ���ཻ������Ϊ�ཻ
// Arguments    : double x1
//                double b_y1
//                double x2
//                double y2
//                double x3
//                double y3
//                double x4
//                double y4
// Return Type  : double
//
double Judge_Intersect(double x1, double b_y1, double x2, double y2, double x3,
  double y3, double x4, double y4)
{
  double Flag;
  double abac;
  double abad;
  double cdcb;
  double cdca;
  double A_idx_0;
  double A_idx_1;
  double B_idx_0;
  double B_idx_1;
  double C_idx_0;
  double C_idx_1;
  double D_idx_0;
  double D_idx_1;

  // ����������
  abac = (x2 - x1) * (y3 - b_y1) - (y2 - b_y1) * (x3 - x1);

  // ����������
  abad = (x2 - x1) * (y4 - b_y1) - (y2 - b_y1) * (x4 - x1);

  // ����������
  cdcb = (x4 - x3) * (y2 - y3) - (y4 - y3) * (x2 - x3);

  // ����������
  cdca = (x4 - x3) * (b_y1 - y3) - (y4 - y3) * (x1 - x3);
  if ((abac * abad < 0.0) && (cdcb * cdca < 0.0)) {
    Flag = 1.0;

    // �ཻ,�޵����߶���
  } else if (((abac == 0.0) || (abad == 0.0)) && (cdcb * cdca < 0.0)) {
    Flag = 2.0;
  } else if (((cdcb == 0.0) || (cdca == 0.0)) && (abac * abad < 0.0)) {
    Flag = 2.0;

    // ��һ���˵����߶���
  } else {
    if (x1 < x2) {
      A_idx_0 = x1;
      A_idx_1 = b_y1;
      B_idx_0 = x2;
      B_idx_1 = y2;
    } else if (x1 > x2) {
      A_idx_0 = x2;
      A_idx_1 = y2;
      B_idx_0 = x1;
      B_idx_1 = b_y1;
    } else if (b_y1 > y2) {
      A_idx_0 = x2;
      A_idx_1 = y2;
      B_idx_0 = x1;
      B_idx_1 = b_y1;
    } else if (b_y1 < y2) {
      A_idx_0 = x1;
      A_idx_1 = b_y1;
      B_idx_0 = x2;
      B_idx_1 = y2;
    } else {
      // warning('���������߶��Ƿ��ཻʱ��ͬһ�߶�AB������ͬ������������');
      A_idx_0 = x1;
      A_idx_1 = b_y1;
      B_idx_0 = x2;
      B_idx_1 = y2;
    }

    if (x3 < x4) {
      C_idx_0 = x3;
      C_idx_1 = y3;
      D_idx_0 = x4;
      D_idx_1 = y4;
    } else if (x3 > x4) {
      C_idx_0 = x4;
      C_idx_1 = y4;
      D_idx_0 = x3;
      D_idx_1 = y3;
    } else if (y3 > y4) {
      C_idx_0 = x4;
      C_idx_1 = y4;
      D_idx_0 = x3;
      D_idx_1 = y3;
    } else if (y3 < y4) {
      C_idx_0 = x3;
      C_idx_1 = y3;
      D_idx_0 = x4;
      D_idx_1 = y4;
    } else {
      // warning('���������߶��Ƿ��ཻʱ��ͬһ�߶�CD������ͬ������������');
      C_idx_0 = x3;
      C_idx_1 = y3;
      D_idx_0 = x4;
      D_idx_1 = y4;
    }

    // ����������
    if ((B_idx_0 - A_idx_0) * (D_idx_1 - C_idx_1) - (B_idx_1 - A_idx_1) *
        (D_idx_0 - C_idx_0) == 0.0) {
      // ˵�����߶�ƽ��
      // ����������
      if ((C_idx_0 - B_idx_0) * (D_idx_1 - C_idx_1) - (C_idx_1 - B_idx_1) *
          (D_idx_0 - C_idx_0) == 0.0) {
        // ˵�����߶ι���
        if ((C_idx_0 - A_idx_0 > 0.0) && (B_idx_0 - C_idx_0 >= 0.0)) {
          Flag = 3.0;
        } else if ((C_idx_0 - A_idx_0 < 0.0) && (D_idx_0 - A_idx_0 >= 0.0)) {
          Flag = 3.0;
        } else if ((C_idx_0 - A_idx_0 == 0.0) && (B_idx_0 - A_idx_0 != 0.0)) {
          Flag = 3.0;
        } else if ((C_idx_0 - A_idx_0 == 0.0) && (B_idx_0 - A_idx_0 == 0.0)) {
          if ((B_idx_1 - C_idx_1 < 0.0) || (D_idx_1 - A_idx_1 < 0.0)) {
            Flag = 0.0;
          } else {
            Flag = 3.0;
          }
        } else {
          Flag = 0.0;
        }
      } else {
        Flag = 0.0;
      }
    } else {
      Flag = 0.0;
    }
  }

  return Flag;
}

//
// File trailer for Judge_Intersect.cpp
//
// [EOF]
//
