/*
 * File: _coder_AgriMapZoomInterface_api.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Oct-2019 15:55:51
 */

#ifndef ___CODER_AGRIMAPZOOMINTERFACE_API_H__
#define ___CODER_AGRIMAPZOOMINTERFACE_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_AgriMapZoomInterface_api.h"

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  uint8_T mapCnt;
  real_T mapLat[100];
  real_T mapLon[100];
  real_T mapAlt[100];
  real_T L;
  real_T flag;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  uint8_T Monolateral;
  real_T Monolateral_L;
  real_T Monolateral_flag;
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  real_T Theita;
  int8_T mapFlag;
  real_T L0;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  int32_T error;
  int32_T warn;
} struct3_T;

#endif                                 /*typedef_struct3_T*/

#ifndef typedef_struct4_T
#define typedef_struct4_T

typedef struct {
  uint8_T mapCnt;
  real_T mapLat[100];
  real_T mapLon[100];
  real_T mapAlt[100];
} struct4_T;

#endif                                 /*typedef_struct4_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void AgriMapZoomInterface(struct0_T *mapB, struct1_T *lineM, struct2_T
  *params, int32_T *ver, struct3_T *out, struct4_T *mapOut);
extern void AgriMapZoomInterface_api(const mxArray * const prhs[3], const
  mxArray *plhs[3]);
extern void AgriMapZoomInterface_atexit(void);
extern void AgriMapZoomInterface_initialize(void);
extern void AgriMapZoomInterface_terminate(void);
extern void AgriMapZoomInterface_xil_terminate(void);

#endif

/*
 * File trailer for _coder_AgriMapZoomInterface_api.h
 *
 * [EOF]
 */
