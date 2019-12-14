/*
 * Preprocess.h
 *
 * Code generation for function 'Preprocess'
 *
 */

#ifndef __PREPROCESS_H__
#define __PREPROCESS_H__

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
extern void Preprocess(const emlrtStack *sp, const real_T Point_data[], const
  int32_T Point_size[2], real_T P_Cnt, real_T Prep_Preprocessing[200], real_T
  *Prep_Cnt);

#endif

/* End of code generation (Preprocess.h) */
