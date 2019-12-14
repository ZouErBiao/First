/*
 * CalculateNewPoint.h
 *
 * Code generation for function 'CalculateNewPoint'
 *
 */

#ifndef __CALCULATENEWPOINT_H__
#define __CALCULATENEWPOINT_H__

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
extern void CalculateNewPoint(const emlrtStack *sp, const real_T Point_data[],
  const int32_T Point_size[2], real_T P_Cnt, real_T L, real_T Theita, real_T
  Points[200], real_T *Cnt);

#endif

/* End of code generation (CalculateNewPoint.h) */
