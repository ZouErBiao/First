//
// File: CalculateCosa.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "CalculateCosa.h"
#include "AgriMapZoomInterface_emxutil.h"

// Function Definitions

//
// Arguments    : const double NEdgevectorList_data[]
//                const int NEdgevectorList_size[2]
//                double n
//                emxArray_real_T *Cosa
// Return Type  : void
//
void CalculateCosa(const double NEdgevectorList_data[], const int
                   NEdgevectorList_size[2], double n, emxArray_real_T *Cosa)
{
  int i18;
  int loop_ub;
  int i;
  i18 = Cosa->size[0] * Cosa->size[1];
  Cosa->size[0] = 1;
  Cosa->size[1] = (int)n;
  emxEnsureCapacity((emxArray__common *)Cosa, i18, (int)sizeof(double));
  loop_ub = (int)n;
  for (i18 = 0; i18 < loop_ub; i18++) {
    Cosa->data[i18] = 0.0;
  }

  for (i = 1; i - 1 < (int)(n + -1.0); i++) {
    Cosa->data[i] = NEdgevectorList_data[i] * NEdgevectorList_data[(int)((2.0 +
      (double)(i - 1)) - 1.0) - 1] + NEdgevectorList_data[i +
      NEdgevectorList_size[0]] * NEdgevectorList_data[((int)((2.0 + (double)(i -
      1)) - 1.0) + NEdgevectorList_size[0]) - 1];
  }

  Cosa->data[0] = NEdgevectorList_data[0] * NEdgevectorList_data[(int)n - 1] +
    NEdgevectorList_data[NEdgevectorList_size[0]] * NEdgevectorList_data[((int)n
    + NEdgevectorList_size[0]) - 1];
}

//
// File trailer for CalculateCosa.cpp
//
// [EOF]
//
