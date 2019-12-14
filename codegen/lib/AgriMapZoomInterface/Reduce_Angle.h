//
// File: Reduce_Angle.h
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//
#ifndef __REDUCE_ANGLE_H__
#define __REDUCE_ANGLE_H__

// Include Files
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "AgriMapZoomInterface_types.h"

// Function Declarations
extern void Reduce_Angle(const double Point_data[], const int Point_size[2],
  double n, double L, const emxArray_real_T *Sina, const emxArray_real_T *Cosa,
  const double NEdgevectorList_data[], const int NEdgevectorList_size[2], double
  Theita, double P[200], double *P_Cnt);

#endif

//
// File trailer for Reduce_Angle.h
//
// [EOF]
//
