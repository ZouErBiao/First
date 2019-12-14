/*
 * Calculate_Effective_Point.h
 *
 * Code generation for function 'Calculate_Effective_Point'
 *
 */

#ifndef __CALCULATE_EFFECTIVE_POINT_H__
#define __CALCULATE_EFFECTIVE_POINT_H__

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
extern void Calculate_Effective_Point(const emlrtStack *sp, const real_T
  PointLast_data[], const int32_T PointLast_size[2], real_T N, real_T YouXiao
  [200], real_T *YX_Cnt);

#endif

/* End of code generation (Calculate_Effective_Point.h) */
