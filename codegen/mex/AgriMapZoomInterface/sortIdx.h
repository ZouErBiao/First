/*
 * sortIdx.h
 *
 * Code generation for function 'sortIdx'
 *
 */

#ifndef __SORTIDX_H__
#define __SORTIDX_H__

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
extern void merge(const emlrtStack *sp, int32_T idx[4], real_T x[4], int32_T
                  offset, int32_T np, int32_T nq, int32_T iwork[4], real_T
                  xwork[4]);

#endif

/* End of code generation (sortIdx.h) */
