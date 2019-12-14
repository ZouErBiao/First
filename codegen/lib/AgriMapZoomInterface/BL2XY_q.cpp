//
// File: BL2XY_q.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "BL2XY_q.h"
#include "AgriMapZoomInterface_rtwutil.h"

// Function Definitions

//
// 此函数用于进行高斯正算
// Arguments    : double B
//                double L
//                double L0
//                double *x
//                double *y
// Return Type  : void
//
void BL2XY_q(double B, double L, double L0, double *x, double *y)
{
  double N;
  double eta;
  double t;
  double m;

  // L经度，B纬度
  // 采用任意带，任意带的中心经线L0，由用户输入
  // 使用WGS-84椭球
  //  e1=(sqrt(a^2-b^2))/b;
  // k=3;%使用3度带
  //  计算中央子午线经度
  //  if k==6
  //      L0=6*(fix(L/6)+1)-3;
  //  elseif k==3
  //      L0=3*(fix((L-1.5)/3)+1);
  //  end
  // 采用任意带，任意带的中心经线L0，由用户输入
  B = B / 180.0 * 3.1415926535897931;

  //  计算子午圈弧长
  //  计算高斯平面坐标
  N = 6.378137E+6 / sqrt(1.0 - 0.0066943800042608276 * sin(B) * sin(B));
  eta = 0.082094438036854261 * cos(B);
  t = tan(B);
  m = cos(B) * ((L - L0) / 180.0 * 3.1415926535897931);
  *x = 6.3354393272027643E+6 * (((((1.0050525017989294 * B -
    0.0025315543040037871 * sin(2.0 * B)) + 2.656897550951634E-6 * sin(4.0 * B))
    - 3.4700630661423838E-9 * sin(6.0 * B)) + 4.9154641589109507E-12 * sin(8.0 *
    B)) - 6.5545478516430659E-15 * sin(10.0 * B)) + N * t * ((0.5 * (m * m) +
    0.041666666666666664 * (((5.0 - t * t) + 9.0 * (eta * eta)) + 4.0 *
    rt_powd_snf(eta, 4.0)) * rt_powd_snf(m, 4.0)) + 0.0013888888888888889 *
    ((61.0 - 58.0 * (t * t)) + rt_powd_snf(t, 4.0)) * rt_powd_snf(m, 6.0));
  *y = N * ((m + 0.16666666666666666 * ((1.0 - t * t) + eta * eta) * rt_powd_snf
             (m, 3.0)) + 0.0083333333333333332 * ((((5.0 - 18.0 * (t * t)) +
    rt_powd_snf(t, 4.0)) + 14.0 * (eta * eta)) - 58.0 * (eta * eta) * (t * t)) *
            rt_powd_snf(m, 5.0));
}

//
// File trailer for BL2XY_q.cpp
//
// [EOF]
//
