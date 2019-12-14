/*
 * Reduce_Angle.h
 *
 * Code generation for function 'Reduce_Angle'
 *
 */

#ifndef __REDUCE_ANGLE_H__
#define __REDUCE_ANGLE_H__

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
extern void Reduce_Angle(const emlrtStack *sp, const real_T Point_data[], const
  int32_T Point_size[2], real_T n, real_T L, const emxArray_real_T *Sina, const
  emxArray_real_T *Cosa, const real_T NEdgevectorList_data[], const int32_T
  NEdgevectorList_size[2], real_T Theita, real_T P[200], real_T *P_Cnt);

#endif

/* End of code generation (Reduce_Angle.h) */
