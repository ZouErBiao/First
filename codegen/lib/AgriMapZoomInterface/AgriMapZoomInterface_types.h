//
// File: AgriMapZoomInterface_types.h
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//
#ifndef __AGRIMAPZOOMINTERFACE_TYPES_H__
#define __AGRIMAPZOOMINTERFACE_TYPES_H__

// Include Files
#include "rtwtypes.h"

// Type Definitions
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray__common

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray_boolean_T

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray_int32_T

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray_real_T

typedef struct {
  unsigned char mapCnt;
  double mapLat[100];
  double mapLon[100];
  double mapAlt[100];
  double L;
  double flag;
} struct0_T;

typedef struct {
  unsigned char Monolateral;
  double Monolateral_L;
  double Monolateral_flag;
} struct1_T;

typedef struct {
  double Theita;
  signed char mapFlag;
  double L0;
} struct2_T;

typedef struct {
  int error;
  int warn;
} struct3_T;

typedef struct {
  unsigned char mapCnt;
  double mapLat[100];
  double mapLon[100];
  double mapAlt[100];
} struct4_T;

#endif

//
// File trailer for AgriMapZoomInterface_types.h
//
// [EOF]
//
