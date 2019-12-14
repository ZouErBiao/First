//
// File: sortLE.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "sortLE.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *v
//                int irow1
//                int irow2
// Return Type  : boolean_T
//
boolean_T sortLE(const emxArray_real_T *v, int irow1, int irow2)
{
  boolean_T p;
  boolean_T b0;
  p = true;
  if ((v->data[irow1 - 1] == v->data[irow2 - 1]) || (rtIsNaN(v->data[irow1 - 1])
       && rtIsNaN(v->data[irow2 - 1]))) {
    b0 = true;
  } else {
    b0 = false;
  }

  if (!b0) {
    if ((v->data[irow1 - 1] <= v->data[irow2 - 1]) || rtIsNaN(v->data[irow2 - 1]))
    {
      p = true;
    } else {
      p = false;
    }
  }

  return p;
}

//
// File trailer for sortLE.cpp
//
// [EOF]
//
