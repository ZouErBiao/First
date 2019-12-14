/*
 * mpower.c
 *
 * Code generation for function 'mpower'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "mpower.h"

/* Function Definitions */
real_T b_mpower(real_T a)
{
  return muDoubleScalarPower(a, 4.0);
}

real_T c_mpower(real_T a)
{
  return muDoubleScalarPower(a, 6.0);
}

real_T d_mpower(real_T a)
{
  return muDoubleScalarPower(a, 3.0);
}

real_T e_mpower(real_T a)
{
  return muDoubleScalarPower(a, 5.0);
}

real_T mpower(real_T a)
{
  return a * a;
}

/* End of code generation (mpower.c) */
