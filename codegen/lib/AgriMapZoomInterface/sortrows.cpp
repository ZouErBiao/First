//
// File: sortrows.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "sortrows.h"
#include "AgriMapZoomInterface_emxutil.h"
#include "sortLE.h"

// Function Definitions

//
// Arguments    : emxArray_real_T *y
// Return Type  : void
//
void sortrows(emxArray_real_T *y)
{
  emxArray_int32_T *idx;
  int i2;
  int k;
  emxArray_int32_T *iwork;
  int n;
  int i;
  int j;
  int pEnd;
  int p;
  int q;
  int qEnd;
  int kEnd;
  emxArray_real_T *ycol;
  emxInit_int32_T(&idx, 1);
  i2 = idx->size[0];
  idx->size[0] = y->size[0];
  emxEnsureCapacity((emxArray__common *)idx, i2, (int)sizeof(int));
  k = y->size[0];
  for (i2 = 0; i2 < k; i2++) {
    idx->data[i2] = 0;
  }

  if (y->size[0] == 0) {
    for (k = 1; k <= y->size[0]; k++) {
      idx->data[k - 1] = k;
    }
  } else {
    emxInit_int32_T(&iwork, 1);
    n = y->size[0] + 1;
    k = y->size[0];
    i2 = iwork->size[0];
    iwork->size[0] = k;
    emxEnsureCapacity((emxArray__common *)iwork, i2, (int)sizeof(int));
    for (k = 1; k <= n - 2; k += 2) {
      if (sortLE(y, k, k + 1)) {
        idx->data[k - 1] = k;
        idx->data[k] = k + 1;
      } else {
        idx->data[k - 1] = k + 1;
        idx->data[k] = k;
      }
    }

    if ((y->size[0] & 1) != 0) {
      idx->data[y->size[0] - 1] = y->size[0];
    }

    i = 2;
    while (i < n - 1) {
      i2 = i << 1;
      j = 1;
      for (pEnd = 1 + i; pEnd < n; pEnd = qEnd + i) {
        p = j;
        q = pEnd;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }

        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          if (sortLE(y, idx->data[p - 1], idx->data[q - 1])) {
            iwork->data[k] = idx->data[p - 1];
            p++;
            if (p == pEnd) {
              while (q < qEnd) {
                k++;
                iwork->data[k] = idx->data[q - 1];
                q++;
              }
            }
          } else {
            iwork->data[k] = idx->data[q - 1];
            q++;
            if (q == qEnd) {
              while (p < pEnd) {
                k++;
                iwork->data[k] = idx->data[p - 1];
                p++;
              }
            }
          }

          k++;
        }

        for (k = 0; k + 1 <= kEnd; k++) {
          idx->data[(j + k) - 1] = iwork->data[k];
        }

        j = qEnd;
      }

      i = i2;
    }

    emxFree_int32_T(&iwork);
  }

  emxInit_real_T1(&ycol, 1);
  pEnd = y->size[0];
  k = y->size[0];
  i2 = ycol->size[0];
  ycol->size[0] = k;
  emxEnsureCapacity((emxArray__common *)ycol, i2, (int)sizeof(double));
  for (j = 0; j < 2; j++) {
    for (i = 0; i + 1 <= pEnd; i++) {
      ycol->data[i] = y->data[(idx->data[i] + y->size[0] * j) - 1];
    }

    for (i = 0; i + 1 <= pEnd; i++) {
      y->data[i + y->size[0] * j] = ycol->data[i];
    }
  }

  emxFree_real_T(&ycol);
  emxFree_int32_T(&idx);
}

//
// File trailer for sortrows.cpp
//
// [EOF]
//
