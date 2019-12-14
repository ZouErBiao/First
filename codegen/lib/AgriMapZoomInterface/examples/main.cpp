//
// File: main.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

//***********************************************************************
// This automatically generated example C main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************
// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "main.h"
#include "AgriMapZoomInterface_terminate.h"
#include "AgriMapZoomInterface_initialize.h"

// Function Declarations
static void argInit_1x100_real_T(double result[100]);
static signed char argInit_int8_T();
static double argInit_real_T();
static void argInit_struct0_T(struct0_T *result);
static struct1_T argInit_struct1_T();
static struct2_T argInit_struct2_T();
static unsigned char argInit_uint8_T();
static void main_AgriMapZoomInterface();

// Function Definitions

//
// Arguments    : double result[100]
// Return Type  : void
//
static void argInit_1x100_real_T(double result[100])
{
  int idx1;

  // Loop over the array to initialize each element.
  for (idx1 = 0; idx1 < 100; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : signed char
//
static signed char argInit_int8_T()
{
  return 0;
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : struct0_T *result
// Return Type  : void
//
static void argInit_struct0_T(struct0_T *result)
{
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result->mapCnt = argInit_uint8_T();
  argInit_1x100_real_T(result->mapLat);
  argInit_1x100_real_T(result->mapLon);
  argInit_1x100_real_T(result->mapAlt);
  result->L = argInit_real_T();
  result->flag = argInit_real_T();
}

//
// Arguments    : void
// Return Type  : struct1_T
//
static struct1_T argInit_struct1_T()
{
  struct1_T result;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result.Monolateral = argInit_uint8_T();
  result.Monolateral_L = argInit_real_T();
  result.Monolateral_flag = argInit_real_T();
  return result;
}

//
// Arguments    : void
// Return Type  : struct2_T
//
static struct2_T argInit_struct2_T()
{
  struct2_T result;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result.Theita = argInit_real_T();
  result.mapFlag = argInit_int8_T();
  result.L0 = argInit_real_T();
  return result;
}

//
// Arguments    : void
// Return Type  : unsigned char
//
static unsigned char argInit_uint8_T()
{
  return 0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_AgriMapZoomInterface()
{
  struct0_T r9;
  struct1_T r10;
  struct2_T r11;
  struct4_T mapOut;
  struct3_T out;
  int ver;

  // Initialize function 'AgriMapZoomInterface' input arguments.
  // Initialize function input argument 'mapB'.
  // Initialize function input argument 'lineM'.
  // Initialize function input argument 'params'.
  // Call the entry-point 'AgriMapZoomInterface'.
  argInit_struct0_T(&r9);
  r10 = argInit_struct1_T();
  r11 = argInit_struct2_T();
  AgriMapZoomInterface(&r9, &r10, &r11, &ver, &out, &mapOut);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // Initialize the application.
  // You do not need to do this more than one time.
  AgriMapZoomInterface_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_AgriMapZoomInterface();

  // Terminate the application.
  // You do not need to do this more than one time.
  AgriMapZoomInterface_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
