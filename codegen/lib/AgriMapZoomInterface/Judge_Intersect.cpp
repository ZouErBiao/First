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
// 此函数仅用来判断两条线段是否相交
// 输出：0为不相交，非零为相交
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

  // 计算两点叉乘
  abac = (x2 - x1) * (y3 - b_y1) - (y2 - b_y1) * (x3 - x1);

  // 计算两点叉乘
  abad = (x2 - x1) * (y4 - b_y1) - (y2 - b_y1) * (x4 - x1);

  // 计算两点叉乘
  cdcb = (x4 - x3) * (y2 - y3) - (y4 - y3) * (x2 - x3);

  // 计算两点叉乘
  cdca = (x4 - x3) * (b_y1 - y3) - (y4 - y3) * (x1 - x3);
  if ((abac * abad < 0.0) && (cdcb * cdca < 0.0)) {
    Flag = 1.0;

    // 相交,无点在线段上
  } else if (((abac == 0.0) || (abad == 0.0)) && (cdcb * cdca < 0.0)) {
    Flag = 2.0;
  } else if (((cdcb == 0.0) || (cdca == 0.0)) && (abac * abad < 0.0)) {
    Flag = 2.0;

    // 有一个端点在线段上
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
      // warning('计算两个线段是否相交时，同一线段AB出现相同点输入的情况！');
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
      // warning('计算两个线段是否相交时，同一线段CD出现相同点输入的情况！');
      C_idx_0 = x3;
      C_idx_1 = y3;
      D_idx_0 = x4;
      D_idx_1 = y4;
    }

    // 计算两点叉乘
    if ((B_idx_0 - A_idx_0) * (D_idx_1 - C_idx_1) - (B_idx_1 - A_idx_1) *
        (D_idx_0 - C_idx_0) == 0.0) {
      // 说明两线段平行
      // 计算两点叉乘
      if ((C_idx_0 - B_idx_0) * (D_idx_1 - C_idx_1) - (C_idx_1 - B_idx_1) *
          (D_idx_0 - C_idx_0) == 0.0) {
        // 说明两线段共线
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
