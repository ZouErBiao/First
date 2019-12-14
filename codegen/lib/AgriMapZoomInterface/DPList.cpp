//
// File: DPList.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "DPList.h"
#include "AgriMapZoomInterface_emxutil.h"

// Function Definitions

//
// 计算指定数组中两点之间的向量、n为行数
// Arguments    : const emxArray_real_T *Point
//                double n
//                emxArray_real_T *EdgevectorList
// Return Type  : void
//
void DPList(const emxArray_real_T *Point, double n, emxArray_real_T
            *EdgevectorList)
{
  int i3;
  int loop_ub;
  int i;
  i3 = EdgevectorList->size[0] * EdgevectorList->size[1];
  EdgevectorList->size[0] = (int)n;
  EdgevectorList->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)EdgevectorList, i3, (int)sizeof(double));
  loop_ub = (int)n << 1;
  for (i3 = 0; i3 < loop_ub; i3++) {
    EdgevectorList->data[i3] = 0.0;
  }

  for (i = 0; i < (int)(n - 1.0); i++) {
    EdgevectorList->data[i] = Point->data[(int)((1.0 + (double)i) + 1.0) - 1] -
      Point->data[i];
    EdgevectorList->data[i + EdgevectorList->size[0]] = Point->data[((int)((1.0
      + (double)i) + 1.0) + Point->size[0]) - 1] - Point->data[i + Point->size[0]];
  }

  EdgevectorList->data[(int)n - 1] = Point->data[0] - Point->data[(int)n - 1];
  EdgevectorList->data[((int)n + EdgevectorList->size[0]) - 1] = Point->
    data[Point->size[0]] - Point->data[((int)n + Point->size[0]) - 1];
}

//
// File trailer for DPList.cpp
//
// [EOF]
//
