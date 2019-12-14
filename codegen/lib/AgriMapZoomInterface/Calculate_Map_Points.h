//
// File: Calculate_Map_Points.h
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//
#ifndef __CALCULATE_MAP_POINTS_H__
#define __CALCULATE_MAP_POINTS_H__

// Include Files
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "AgriMapZoomInterface_types.h"

// Function Declarations
extern void Calculate_Map_Points(const double Point_data[], const int
  Point_size[2], double P_Cnt, double L, double flag, double Theita, double
  Clock_Flag, double PointLast[200], double *PL_Cnt, double *f_error);

#endif

//
// File trailer for Calculate_Map_Points.h
//
// [EOF]
//
