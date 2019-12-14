/*
 * Calculate_Monolateral_Points.h
 *
 * Code generation for function 'Calculate_Monolateral_Points'
 *
 */

#ifndef __CALCULATE_MONOLATERAL_POINTS_H__
#define __CALCULATE_MONOLATERAL_POINTS_H__

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
extern void Calculate_Monolateral_Points(const emlrtStack *sp, real_T
  Points_data[], int32_T Points_size[2], real_T n, real_T Monolateral, real_T
  Monolateral_L, real_T Monolateral_flag, real_T Clock_Flag, real_T
  Points_Monolateral[200], real_T *PM_Cnt, real_T *f_error);

#endif

/* End of code generation (Calculate_Monolateral_Points.h) */
