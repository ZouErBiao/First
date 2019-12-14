/*
 * NormalizeDPList.h
 *
 * Code generation for function 'NormalizeDPList'
 *
 */

#ifndef __NORMALIZEDPLIST_H__
#define __NORMALIZEDPLIST_H__

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
extern void NormalizeDPList(const emlrtStack *sp, const emxArray_real_T
  *EdgevectorList, real_T n, emxArray_real_T *NEdgevectorList);

#endif

/* End of code generation (NormalizeDPList.h) */
