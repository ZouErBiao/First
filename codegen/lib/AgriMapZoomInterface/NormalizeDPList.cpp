//
// File: NormalizeDPList.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "NormalizeDPList.h"
#include "AgriMapZoomInterface_emxutil.h"

// Function Definitions

//
// 单位化各边向量
// n为行数
// Arguments    : const emxArray_real_T *EdgevectorList
//                double n
//                emxArray_real_T *NEdgevectorList
// Return Type  : void
//
void NormalizeDPList(const emxArray_real_T *EdgevectorList, double n,
                     emxArray_real_T *NEdgevectorList)
{
  int i4;
  int loop_ub;
  int i;
  double x;
  i4 = NEdgevectorList->size[0] * NEdgevectorList->size[1];
  NEdgevectorList->size[0] = (int)n;
  NEdgevectorList->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)NEdgevectorList, i4, (int)sizeof(double));
  loop_ub = (int)n << 1;
  for (i4 = 0; i4 < loop_ub; i4++) {
    NEdgevectorList->data[i4] = 0.0;
  }

  for (i = 0; i < (int)n; i++) {
    x = sqrt(EdgevectorList->data[i] * EdgevectorList->data[i] +
             EdgevectorList->data[i + EdgevectorList->size[0]] *
             EdgevectorList->data[i + EdgevectorList->size[0]]);
    for (i4 = 0; i4 < 2; i4++) {
      NEdgevectorList->data[i + NEdgevectorList->size[0] * i4] =
        EdgevectorList->data[i + EdgevectorList->size[0] * i4] / x;
    }
  }
}

//
// File trailer for NormalizeDPList.cpp
//
// [EOF]
//
