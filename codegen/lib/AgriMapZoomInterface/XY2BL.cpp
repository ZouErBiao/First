//
// File: XY2BL.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "XY2BL.h"
#include "BL2XY_q.h"
#include "AgriMapZoomInterface_rtwutil.h"

// Function Definitions

//
// 此函数用于进行高斯反算
// Arguments    : double x
//                double y
//                double L0
//                double *B
//                double *L
// Return Type  : void
//
void XY2BL(double x, double y, double L0, double *B, double *L)
{
  double deltaB;
  double Bi;
  double Bf;
  double tf;
  double Vf;
  double Nf;
  double etaf;

  // L经度，B纬度
  //  CGCS2000椭球参数
  //  a=6378137;
  //  e=0.081819191042811;
  //  ee=0.0820944381518626;
  //  1975国际椭球参数
  //  a=6378140;
  //  e=0.0818192214555235;
  // 使用WGS-84椭球s
  //  e1=(sqrt(a^2-b^2))/b;
  //  计算底点的经度
  *B = x / 6.3674491458004639E+6;
  deltaB = 1000.0;
  while (deltaB > 1.0000000000000001E-20) {
    Bi = 0.99497289764476393 * (((((x / 6.3354393272027643E+6 +
      0.0025315543040037871 * sin(2.0 * *B)) - 2.656897550951634E-6 * sin(4.0 * *
      B)) + 3.4700630661423838E-9 * sin(6.0 * *B)) - 4.9154641589109507E-12 *
      sin(8.0 * *B)) + 6.5545478516430659E-15 * sin(10.0 * *B));
    deltaB = fabs(Bi - *B);
    *B = Bi;
  }

  Bf = *B;

  //  计算大地经纬度BL
  tf = tan(*B);
  Vf = sqrt(1.0 + 0.0067394967565869036 * cos(*B) * cos(*B));
  Nf = 6.378137E+6 / sqrt(1.0 - 0.0066943800042608276 * sin(*B) * sin(*B));
  etaf = 0.082094438036854261 * cos(*B);
  *B -= 0.5 * (Vf * Vf) * tf * ((y / Nf * (y / Nf) - 0.083333333333333329 *
    (((5.0 + 3.0 * (tf * tf)) + etaf * etaf) - 9.0 * (etaf * etaf) * (tf * tf)) *
    rt_powd_snf(y / Nf, 4.0)) + 0.0027777777777777779 * ((61.0 + 90.0 * (tf * tf))
    + 45.0 * rt_powd_snf(tf, 4.0)) * rt_powd_snf(y / Nf, 6.0));
  *B = *B / 3.1415926535897931 * 180.0;
  *L = L0 + 1.0 / cos(Bf) * ((y / Nf - 0.16666666666666666 * ((1.0 + 2.0 * (tf *
    tf)) + etaf * etaf) * rt_powd_snf(y / Nf, 3.0)) + 0.0083333333333333332 *
    ((((5.0 + 28.0 * (tf * tf)) + 24.0 * rt_powd_snf(tf, 4.0)) + 6.0 * (etaf *
    etaf)) + 8.0 * (etaf * etaf) * (tf * tf)) * rt_powd_snf(y / Nf, 5.0)) /
    3.1415926535897931 * 180.0;
}

//
// File trailer for XY2BL.cpp
//
// [EOF]
//
