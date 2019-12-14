//
// File: CalculateSina.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "CalculateSina.h"
#include "AgriMapZoomInterface_emxutil.h"

// Function Definitions

//
// 计算各个夹角的sin值，利用的是单位向量的叉乘、n为NEdgevectorList的列数
// Arguments    : const emxArray_real_T *NEdgevectorList
//                double n
//                emxArray_real_T *Sina
// Return Type  : void
//
void CalculateSina(const emxArray_real_T *NEdgevectorList, double n,
                   emxArray_real_T *Sina)
{
  int i9;
  int loop_ub;
  int i;
  i9 = Sina->size[0] * Sina->size[1];
  Sina->size[0] = 1;
  Sina->size[1] = (int)n;
  emxEnsureCapacity((emxArray__common *)Sina, i9, (int)sizeof(double));
  loop_ub = (int)n;
  for (i9 = 0; i9 < loop_ub; i9++) {
    Sina->data[i9] = 1.0;
  }

  for (i = 1; i - 1 < (int)(n + -1.0); i++) {
    Sina->data[Sina->size[0] * i] = NEdgevectorList->data[i] *
      NEdgevectorList->data[((int)((2.0 + (double)(i - 1)) - 1.0) +
      NEdgevectorList->size[0]) - 1] - NEdgevectorList->data[i +
      NEdgevectorList->size[0]] * NEdgevectorList->data[(int)((2.0 + (double)(i
      - 1)) - 1.0) - 1];
  }

  Sina->data[0] = NEdgevectorList->data[0] * NEdgevectorList->data[((int)n +
    NEdgevectorList->size[0]) - 1] - NEdgevectorList->data[NEdgevectorList->
    size[0]] * NEdgevectorList->data[(int)n - 1];
}

//
// File trailer for CalculateSina.cpp
//
// [EOF]
//
