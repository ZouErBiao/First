/*
 * CalculateLineCrossover.h
 *
 * Code generation for function 'CalculateLineCrossover'
 *
 */

#ifndef __CALCULATELINECROSSOVER_H__
#define __CALCULATELINECROSSOVER_H__

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
extern void CalculateLineCrossover(const emlrtStack *sp, real_T x1, real_T b_y1,
  real_T x2, real_T y2, real_T x3, real_T y3, real_T x4, real_T y4, real_T
  LineCrossover[2]);

#endif

/* End of code generation (CalculateLineCrossover.h) */
