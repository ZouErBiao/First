/*
 * Judge_Intersect.c
 *
 * Code generation for function 'Judge_Intersect'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "Judge_Intersect.h"

/* Function Definitions */
real_T Judge_Intersect(real_T x1, real_T b_y1, real_T x2, real_T y2, real_T x3,
  real_T y3, real_T x4, real_T y4)
{
  real_T Flag;
  real_T abac;
  real_T abad;
  real_T cdcb;
  real_T cdca;
  real_T A_idx_0;
  real_T A_idx_1;
  real_T B_idx_0;
  real_T B_idx_1;
  real_T C_idx_0;
  real_T C_idx_1;
  real_T D_idx_0;
  real_T D_idx_1;

  /* �˺����������ж������߶��Ƿ��ཻ */
  /* �����0Ϊ���ཻ������Ϊ�ཻ */
  /* ���������� */
  abac = (x2 - x1) * (y3 - b_y1) - (y2 - b_y1) * (x3 - x1);

  /* ���������� */
  abad = (x2 - x1) * (y4 - b_y1) - (y2 - b_y1) * (x4 - x1);

  /* ���������� */
  cdcb = (x4 - x3) * (y2 - y3) - (y4 - y3) * (x2 - x3);

  /* ���������� */
  cdca = (x4 - x3) * (b_y1 - y3) - (y4 - y3) * (x1 - x3);
  if ((abac * abad < 0.0) && (cdcb * cdca < 0.0)) {
    Flag = 1.0;

    /* �ཻ,�޵����߶��� */
  } else if (((abac == 0.0) || (abad == 0.0)) && (cdcb * cdca < 0.0)) {
    Flag = 2.0;
  } else if (((cdcb == 0.0) || (cdca == 0.0)) && (abac * abad < 0.0)) {
    Flag = 2.0;

    /* ��һ���˵����߶��� */
  } else {
    if (x1 < x2) {
      A_idx_0 = x1;
      A_idx_1 = b_y1;
      B_idx_0 = x2;
      B_idx_1 = y2;
    } else if (x1 > x2) {
      A_idx_0 = x2;
      A_idx_1 = y2;
      B_idx_0 = x1;
      B_idx_1 = b_y1;
    } else if (b_y1 > y2) {
      A_idx_0 = x2;
      A_idx_1 = y2;
      B_idx_0 = x1;
      B_idx_1 = b_y1;
    } else if (b_y1 < y2) {
      A_idx_0 = x1;
      A_idx_1 = b_y1;
      B_idx_0 = x2;
      B_idx_1 = y2;
    } else {
      /* warning('���������߶��Ƿ��ཻʱ��ͬһ�߶�AB������ͬ������������'); */
      A_idx_0 = x1;
      A_idx_1 = b_y1;
      B_idx_0 = x2;
      B_idx_1 = y2;
    }

    if (x3 < x4) {
      C_idx_0 = x3;
      C_idx_1 = y3;
      D_idx_0 = x4;
      D_idx_1 = y4;
    } else if (x3 > x4) {
      C_idx_0 = x4;
      C_idx_1 = y4;
      D_idx_0 = x3;
      D_idx_1 = y3;
    } else if (y3 > y4) {
      C_idx_0 = x4;
      C_idx_1 = y4;
      D_idx_0 = x3;
      D_idx_1 = y3;
    } else if (y3 < y4) {
      C_idx_0 = x3;
      C_idx_1 = y3;
      D_idx_0 = x4;
      D_idx_1 = y4;
    } else {
      /* warning('���������߶��Ƿ��ཻʱ��ͬһ�߶�CD������ͬ������������'); */
      C_idx_0 = x3;
      C_idx_1 = y3;
      D_idx_0 = x4;
      D_idx_1 = y4;
    }

    /* ���������� */
    if ((B_idx_0 - A_idx_0) * (D_idx_1 - C_idx_1) - (B_idx_1 - A_idx_1) *
        (D_idx_0 - C_idx_0) == 0.0) {
      /* ˵�����߶�ƽ�� */
      /* ���������� */
      if ((C_idx_0 - B_idx_0) * (D_idx_1 - C_idx_1) - (C_idx_1 - B_idx_1) *
          (D_idx_0 - C_idx_0) == 0.0) {
        /* ˵�����߶ι��� */
        if ((C_idx_0 - A_idx_0 > 0.0) && (B_idx_0 - C_idx_0 >= 0.0)) {
          Flag = 3.0;
        } else if ((C_idx_0 - A_idx_0 < 0.0) && (D_idx_0 - A_idx_0 >= 0.0)) {
          Flag = 3.0;
        } else if ((C_idx_0 - A_idx_0 == 0.0) && (B_idx_0 - A_idx_0 != 0.0)) {
          Flag = 3.0;
        } else if ((C_idx_0 - A_idx_0 == 0.0) && (B_idx_0 - A_idx_0 == 0.0)) {
          if ((B_idx_1 - C_idx_1 < 0.0) || (D_idx_1 - A_idx_1 < 0.0)) {
            Flag = 0.0;
          } else {
            Flag = 3.0;
          }
        } else {
          Flag = 0.0;
        }
      } else {
        Flag = 0.0;
      }
    } else {
      Flag = 0.0;
    }
  }

  return Flag;
}

/* End of code generation (Judge_Intersect.c) */
