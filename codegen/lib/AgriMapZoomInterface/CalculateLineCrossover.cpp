//
// File: CalculateLineCrossover.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "CalculateLineCrossover.h"
#include "sort1.h"

// Function Definitions

//
// 计算两条相交线段之间的交点
// Arguments    : double x1
//                double b_y1
//                double x2
//                double y2
//                double x3
//                double y3
//                double x4
//                double y4
//                double LineCrossover[2]
// Return Type  : void
//
void CalculateLineCrossover(double x1, double b_y1, double x2, double y2, double
  x3, double y3, double x4, double y4, double LineCrossover[2])
{
  double Middle[4];
  double a;
  double b;
  if ((x1 != x2) && (b_y1 == y2) && (y2 == y3) && (x3 != x4) && (y3 == y4)) {
    // 两条线段都与x轴平行
    Middle[0] = x1;
    Middle[1] = x2;
    Middle[2] = x3;
    Middle[3] = x4;
    sort(Middle);
    LineCrossover[0] = Middle[2];
    LineCrossover[1] = b_y1;
  } else if ((x1 != x2) && (b_y1 == y2) && (x3 == x4) && (y3 != y4)) {
    // 第一条鱼x轴平行，第二条与y轴平行
    LineCrossover[0] = x3;
    LineCrossover[1] = b_y1;
  } else if ((x1 != x2) && (b_y1 == y2) && (x3 != x4) && (y3 != y4)) {
    // 第一条鱼x轴平行，第二条不与坐标轴平行
    LineCrossover[0] = (b_y1 - y3) * (x4 - x3) / (y4 - y3) + x3;
    LineCrossover[1] = b_y1;
  } else if ((x1 == x2) && (b_y1 != y2) && (x3 != x4) && (y3 == y4)) {
    // 第一条平行于y轴，第二条平行于x轴
    LineCrossover[0] = x1;
    LineCrossover[1] = y3;
  } else if ((x1 == x2) && (b_y1 != y2) && (x1 == x3) && (x3 == x4) && (y3 != y4))
  {
    // 第一条平行于y轴，第二条平行于y轴
    LineCrossover[0] = x1;
    Middle[0] = b_y1;
    Middle[1] = y2;
    Middle[2] = y3;
    Middle[3] = y4;
    sort(Middle);
    LineCrossover[1] = Middle[2];
  } else if ((x1 == x2) && (b_y1 != y2) && (x1 != x3) && (y3 != y4)) {
    // 第一条平行于y轴，第二条不与任何轴平行
    LineCrossover[0] = x1;
    LineCrossover[1] = (y4 - y3) * (x1 - x3) / (x4 - x3) + y3;
  } else if ((x1 != x2) && (b_y1 != y2) && (x3 != x4) && (y3 == y4)) {
    // 第一条不与任何轴平行，第二条与x轴平行
    LineCrossover[0] = (y3 - b_y1) * (x2 - x1) / (y2 - b_y1) + x1;
    LineCrossover[1] = y3;
  } else if ((x1 != x2) && (b_y1 != y2) && (x3 == x4) && (y3 != y4)) {
    LineCrossover[0] = x3;
    LineCrossover[1] = (y2 - b_y1) * (x3 - x1) / (x2 - x1) + b_y1;
  } else {
    a = (y4 - y3) / (x4 - x3);
    b = (y2 - b_y1) / (x2 - x1);
    if (a != b) {
      // 两线段线斜率不相同
      LineCrossover[0] = (((b_y1 - y3) + a * x3) - b * x1) / (a - b);
      LineCrossover[1] = (((a * b * x1 - a * b * x3) + b * y3) - a * b_y1) / (b
        - a);
    } else {
      // 两线段斜率相同
      Middle[0] = x1;
      Middle[1] = x2;
      Middle[2] = x3;
      Middle[3] = x4;
      sort(Middle);
      LineCrossover[0] = Middle[2];
      LineCrossover[1] = b * (Middle[2] - x1) + b_y1;
    }
  }
}

//
// File trailer for CalculateLineCrossover.cpp
//
// [EOF]
//
