/*
 * Calculate_Map_Points.h
 *
 * Code generation for function 'Calculate_Map_Points'
 *
 */

#ifndef __CALCULATE_MAP_POINTS_H__
#define __CALCULATE_MAP_POINTS_H__

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "AgriMapZoomInterface_types.h"

/* Function Declarations */
extern void Calculate_Map_Points(const emlrtStack *sp, const real_T Point_data[],
  const int32_T Point_size[2], real_T P_Cnt, real_T L, real_T flag, real_T
  Theita, real_T Clock_Flag, real_T PointLast[200], real_T *PL_Cnt, real_T
  *f_error);

#endif

/* End of code generation (Calculate_Map_Points.h) */
