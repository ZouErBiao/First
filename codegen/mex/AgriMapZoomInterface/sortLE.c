/*
 * sortLE.c
 *
 * Code generation for function 'sortLE'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "sortLE.h"

/* Function Definitions */
boolean_T sortLE(const emxArray_real_T *v, int32_T irow1, int32_T irow2)
{
  boolean_T p;
  boolean_T b0;
  p = true;
  if ((v->data[irow1 - 1] == v->data[irow2 - 1]) || (muDoubleScalarIsNaN(v->
        data[irow1 - 1]) && muDoubleScalarIsNaN(v->data[irow2 - 1]))) {
    b0 = true;
  } else {
    b0 = false;
  }

  if (!b0) {
    if ((v->data[irow1 - 1] <= v->data[irow2 - 1]) || muDoubleScalarIsNaN
        (v->data[irow2 - 1])) {
      p = true;
    } else {
      p = false;
    }
  }

  return p;
}

/* End of code generation (sortLE.c) */
