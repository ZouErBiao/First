/*
 * flipud.c
 *
 * Code generation for function 'flipud'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "flipud.h"
#include "AgriMapZoomInterface_mexutil.h"

/* Function Definitions */
void flipud(real_T x_data[], int32_T x_size[2])
{
  int32_T m;
  int32_T md2;
  int32_T j;
  int32_T i;
  real_T xtmp;
  m = x_size[0];
  md2 = asr_s32(x_size[0], 1U);
  for (j = 0; j < 2; j++) {
    for (i = 1; i <= md2; i++) {
      xtmp = x_data[(i + x_size[0] * j) - 1];
      x_data[(i + x_size[0] * j) - 1] = x_data[(m - i) + x_size[0] * j];
      x_data[(m - i) + x_size[0] * j] = xtmp;
    }
  }
}

/* End of code generation (flipud.c) */
