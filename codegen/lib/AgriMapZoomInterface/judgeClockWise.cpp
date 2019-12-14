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
// ���:˳ʱ��Ϊ1����ʱ��Ϊ0
// �㷨˵����
//  ��ĳһ�������cross product = ((xi - xi-1),(yi - yi-1)) x ((xi+1 - xi),(yi+1 - yi)) = (xi - xi-1) * (yi+1 - yi) - (yi - yi-1) * (xi+1 - xi)
//  �����ʽ��ֵΪ������ʱ�룻Ϊ������˳ʱ��
//  ������һ��ļ򵥶���Σ�������ڶ���ε�ÿһ�����������ֵ�������ֵ�Ƚ϶࣬����ʱ�룻��ֵ�϶���Ϊ˳ʱ�롣
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

  // % �жϵؿ���˳ʱ�뻹����ʱ��
  // % �ж�
  CWAFlag = 0.0;
  if (len < 3.0) {
  } else {
    // % ��˱�������
    //
    // % Green �㷨
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
      // ��ʱ��
    } else {
      CWAFlag = 1.0;

      // ˳ʱ��
    }
  }

  return CWAFlag;
}

//
// File trailer for judgeClockWise.cpp
//
// [EOF]
//
