//
// File: Sort2.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "Sort2.h"

// Function Definitions

//
// 对L进行从小到大排序,Index为排序前凹边两端点信息，Mm为L中元素的个数
// Arguments    : double L[350]
//                double Mm
// Return Type  : void
//
void Sort(double L[350], double Mm)
{
  int i;
  int i21;
  int j;
  double b_j;
  double b_L[7];
  double l[7];
  int i22;
  for (i = 0; i < (int)Mm; i++) {
    i21 = (int)(Mm + (1.0 - ((1.0 + (double)i) + 1.0)));
    for (j = 0; j < i21; j++) {
      b_j = ((1.0 + (double)i) + 1.0) + (double)j;
      if (L[(int)b_j + 249] <= L[250 + i]) {
        for (i22 = 0; i22 < 7; i22++) {
          l[i22] = L[i + 50 * i22];
          b_L[i22] = L[((int)b_j + 50 * i22) - 1];
        }

        for (i22 = 0; i22 < 7; i22++) {
          L[i + 50 * i22] = b_L[i22];
        }

        for (i22 = 0; i22 < 7; i22++) {
          L[((int)b_j + 50 * i22) - 1] = l[i22];
        }
      }
    }
  }
}

//
// File trailer for Sort2.cpp
//
// [EOF]
//
