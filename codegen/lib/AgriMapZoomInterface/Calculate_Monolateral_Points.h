//
// File: Calculate_Monolateral_Points.h
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//
#ifndef __CALCULATE_MONOLATERAL_POINTS_H__
#define __CALCULATE_MONOLATERAL_POINTS_H__

// Include Files
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "AgriMapZoomInterface_types.h"

// Function Declarations
extern void Calculate_Monolateral_Points(double Points_data[], int Points_size[2],
  double n, double Monolateral, double Monolateral_L, double Monolateral_flag,
  double Clock_Flag, double Points_Monolateral[200], double *PM_Cnt, double
  *f_error);

#endif

//
// File trailer for Calculate_Monolateral_Points.h
//
// [EOF]
//
