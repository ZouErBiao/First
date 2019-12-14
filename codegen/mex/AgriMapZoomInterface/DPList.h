/*
 * DPList.h
 *
 * Code generation for function 'DPList'
 *
 */

#ifndef __DPLIST_H__
#define __DPLIST_H__

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
extern void DPList(const emlrtStack *sp, const emxArray_real_T *Point, real_T n,
                   emxArray_real_T *EdgevectorList);

#endif

/* End of code generation (DPList.h) */
