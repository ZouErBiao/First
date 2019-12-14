/*
 * judgeClockWise.h
 *
 * Code generation for function 'judgeClockWise'
 *
 */

#ifndef __JUDGECLOCKWISE_H__
#define __JUDGECLOCKWISE_H__

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
extern real_T judgeClockWise(const emlrtStack *sp, const emxArray_real_T *lat_in,
  const emxArray_real_T *lon_in, real_T len);

#ifdef __WATCOMC__

#pragma aux judgeClockWise value [8087];

#endif
#endif

/* End of code generation (judgeClockWise.h) */
