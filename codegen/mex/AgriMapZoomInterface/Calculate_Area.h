/*
 * Calculate_Area.h
 *
 * Code generation for function 'Calculate_Area'
 *
 */

#ifndef __CALCULATE_AREA_H__
#define __CALCULATE_AREA_H__

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
extern real_T Calculate_Area(const emlrtStack *sp, real_T Pxy_data[], int32_T
  Pxy_size[2], real_T n);

#ifdef __WATCOMC__

#pragma aux Calculate_Area value [8087];

#endif
#endif

/* End of code generation (Calculate_Area.h) */
