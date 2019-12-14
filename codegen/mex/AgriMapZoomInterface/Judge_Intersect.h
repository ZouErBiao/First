/*
 * Judge_Intersect.h
 *
 * Code generation for function 'Judge_Intersect'
 *
 */

#ifndef __JUDGE_INTERSECT_H__
#define __JUDGE_INTERSECT_H__

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
extern real_T Judge_Intersect(real_T x1, real_T b_y1, real_T x2, real_T y2,
  real_T x3, real_T y3, real_T x4, real_T y4);

#ifdef __WATCOMC__

#pragma aux Judge_Intersect value [8087];

#endif
#endif

/* End of code generation (Judge_Intersect.h) */
