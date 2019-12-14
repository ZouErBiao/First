/*
 * CalculateIntersection.h
 *
 * Code generation for function 'CalculateIntersection'
 *
 */

#ifndef __CALCULATEINTERSECTION_H__
#define __CALCULATEINTERSECTION_H__

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
extern void CalculateIntersection(const emlrtStack *sp, const real_T
  PolygonList_data[], const int32_T PolygonList_size[2], real_T PL_Cnt, const
  real_T IntersectionPointList_data[], const int32_T IntersectionPointList_size
  [2], real_T IP_Cnt, real_T ppp[700], real_T *p_Cnt);

#endif

/* End of code generation (CalculateIntersection.h) */
