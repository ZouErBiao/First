/*
 * XY2BL.h
 *
 * Code generation for function 'XY2BL'
 *
 */

#ifndef __XY2BL_H__
#define __XY2BL_H__

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
extern void XY2BL(const emlrtStack *sp, real_T x, real_T y, real_T L0, real_T *B,
                  real_T *L);

#endif

/* End of code generation (XY2BL.h) */
