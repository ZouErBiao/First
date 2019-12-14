//
// File: Calculate_Area.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "Calculate_Area.h"

// Function Definitions

//
// Arguments    : double Pxy_data[]
//                int Pxy_size[2]
//                double n
// Return Type  : double
//
double Calculate_Area(double Pxy_data[], int Pxy_size[2], double n)
{
  double b_sum;
  double b_Pxy_data[202];
  int Pxy_size_idx_0;
  int i12;
  int loop_ub;
  int i13;
  int i;
  b_sum = 0.0;
  Pxy_size_idx_0 = Pxy_size[0] + 1;
  for (i12 = 0; i12 < 2; i12++) {
    loop_ub = Pxy_size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      b_Pxy_data[i13 + Pxy_size_idx_0 * i12] = Pxy_data[i13 + Pxy_size[0] * i12];
    }
  }

  for (i12 = 0; i12 < 2; i12++) {
    b_Pxy_data[Pxy_size[0] + Pxy_size_idx_0 * i12] = Pxy_data[Pxy_size[0] * i12];
  }

  Pxy_size[0]++;
  for (i12 = 0; i12 < 2; i12++) {
    for (i13 = 0; i13 < Pxy_size_idx_0; i13++) {
      Pxy_data[i13 + Pxy_size[0] * i12] = b_Pxy_data[i13 + Pxy_size_idx_0 * i12];
    }
  }

  for (i = 0; i < (int)n; i++) {
    b_sum = (b_sum + Pxy_data[i] * Pxy_data[((int)((1.0 + (double)i) + 1.0) +
              Pxy_size[0]) - 1]) - Pxy_data[i + Pxy_size[0]] * Pxy_data[(int)
      ((1.0 + (double)i) + 1.0) - 1];
  }

  return fabs(b_sum / 2.0);
}

//
// File trailer for Calculate_Area.cpp
//
// [EOF]
//
