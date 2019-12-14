//
// File: judgeClockWise.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "judgeClockWise.h"

// Function Definitions

//
// 输出:顺时针为1，逆时针为0
// 算法说明：
//  对某一个点计算cross product = ((xi - xi-1),(yi - yi-1)) x ((xi+1 - xi),(yi+1 - yi)) = (xi - xi-1) * (yi+1 - yi) - (yi - yi-1) * (xi+1 - xi)
//  如果上式的值为正，逆时针；为负则是顺时针
//  而对于一般的简单多边形，则需对于多边形的每一个点计算上述值，如果正值比较多，是逆时针；负值较多则为顺时针。
//  lat_in:x,lon_in:y
// %
// Arguments    : const emxArray_real_T *lat_in
//                const emxArray_real_T *lon_in
//                double len
// Return Type  : double
//
double judgeClockWise(const emxArray_real_T *lat_in, const emxArray_real_T
                      *lon_in, double len)
{
  double CWAFlag;
  double d;
  int i;

  // % 判断地块是顺时针还是逆时针
  // % 判断
  CWAFlag = 0.0;
  if (len < 3.0) {
  } else {
    // % 叉乘遍历计算
    //
    // % Green 算法
    d = 0.0;
    for (i = 0; i < (int)(len - 1.0); i++) {
      // d += - 0.5 * ( y[i + 1] + y[i]) * (x[i + 1] - x[i]);
      d -= 0.5 * (lon_in->data[(int)((1.0 + (double)i) + 1.0) - 1] +
                  lon_in->data[i]) * (lat_in->data[(int)((1.0 + (double)i) + 1.0)
        - 1] - lat_in->data[i]);
    }

    d -= 0.5 * (lon_in->data[0] + lon_in->data[(int)len - 1]) * (lat_in->data[0]
      - lat_in->data[(int)len - 1]);

    //
    if (d >= 0.0) {
      // 逆时针
    } else {
      CWAFlag = 1.0;

      // 顺时针
    }
  }

  return CWAFlag;
}

//
// File trailer for judgeClockWise.cpp
//
// [EOF]
//
