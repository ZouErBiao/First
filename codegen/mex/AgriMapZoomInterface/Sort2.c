/*
 * Sort2.c
 *
 * Code generation for function 'Sort2'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "Sort2.h"
#include "AgriMapZoomInterface_data.h"

/* Variable Definitions */
static emlrtBCInfo kr_emlrtBCI = { 1, 50, 6, 14, "L", "Sort",
  "D:\\2.AgriMapZoom\\Sort.m", 0 };

/* Function Definitions */
void Sort(const emlrtStack *sp, real_T L[350], real_T Mm)
{
  int32_T i;
  int32_T i36;
  int32_T j;
  real_T b_j;
  int32_T i37;
  real_T b_L[7];
  real_T l[7];

  /* 对L进行从小到大排序,Index为排序前凹边两端点信息，Mm为L中元素的个数 */
  i = 0;
  while (i <= (int32_T)Mm - 1) {
    i36 = (int32_T)(Mm + (1.0 - ((1.0 + (real_T)i) + 1.0)));
    j = 0;
    while (j <= i36 - 1) {
      b_j = ((1.0 + (real_T)i) + 1.0) + (real_T)j;
      i37 = (int32_T)b_j;
      if (!((i37 >= 1) && (i37 <= 50))) {
        emlrtDynamicBoundsCheckR2012b(i37, 1, 50, &kr_emlrtBCI, sp);
      }

      if (L[i37 + 249] <= L[250 + i]) {
        for (i37 = 0; i37 < 7; i37++) {
          l[i37] = L[i + 50 * i37];
          b_L[i37] = L[((int32_T)b_j + 50 * i37) - 1];
        }

        for (i37 = 0; i37 < 7; i37++) {
          L[i + 50 * i37] = b_L[i37];
        }

        for (i37 = 0; i37 < 7; i37++) {
          L[((int32_T)b_j + 50 * i37) - 1] = l[i37];
        }
      }

      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

/* End of code generation (Sort2.c) */
