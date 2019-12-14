//
// File: AgriMapZoomInterface.cpp
//
// MATLAB Coder version            : 3.0
// C/C++ source code generated on  : 16-Oct-2019 15:55:51
//

// Include Files
#include "rt_nonfinite.h"
#include "AgriMapZoomInterface.h"
#include "BL2XY_q.h"
#include "XY2BL.h"
#include "Calculate_Map_Points.h"
#include "Calculate_Monolateral_Points.h"
#include "Calculate_New_Indented_Boundary_Point.h"
#include "flipud.h"
#include "judgeClockWise.h"
#include "Preprocess.h"

// Function Declarations
static double rt_roundd_snf(double u);

// Function Definitions

//
// Arguments    : double u
// Return Type  : double
//
static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

//
// {
// ����:��������ת������������ƽ�ơ��������������������
// ����:
// ����
// mapB.mapCnt:����ĵ�ĸ���(��������:uint8 1x1)
// mapB.mapLat:��ĺ�����(��������:double 1x100)
// mapB.mapLon:���������(��������:double 1x100)
// mapB.mapAlt:�߶�(double-1*100)
// mapB.L:���ž���(�������ͣ�double 1x1)��ֻ��֤Lֵ�����仯ʱ�ĵ�������Ԥ�ڣ�
// mapB.flag:���ű�־������������־λ��0:������1;����������������ֵ���������Ӧ�ľ��棡(��������:double 1x1)
//
// ����
// LineM.Monolateral:�����ƶ��߽�ţ�����;1,2,3,4,5,...nn(��������:double 1x1)
// LineM.Monolateral_L:�����ƶ�����(��������:double 1x1)
// LineM.Monolateral_flag:�ƶ�����0:���ƣ�1:����;(��������:double 1x1)
//
// params.Theita: ����Ϊ��С��ǵĽǶȽ��ޣ���ʽ�磺��20�������������С�ڻ����20��ΪС��ǣ���Ҫ������ΧΪ0�㵽90��(�������ͣ�double 1x1)
// params.mapFlag:ƽ�������־,0Ϊƽ�����꣬1Ϊ��γ������(�������ͣ�double 1x1)
// params.L0:���еؿ��ľ���ƽ��ֵ(double)
//
// ���:
// mapOut.mapCnt
// mapOut.mapLat
// mapOut.mapLon:�����Ķ���α߽��
// mapOut.mapAlt
//
// out.error:�������룩
// -0����
// -(-1)���账��,�߽罻��
//
// out.warn:������
// -0����
// -1�쳣
// f_Warning0:��γ��ת����־��Ч
// f_Warning1:�����ƶ���Ч(��ѡ�������Ч+�ƶ���־��Ч)
// f_Warning2:����������Ч(�ƶ���־��Ч)
//
// ver:�汾��
// }
// % ����
// Arguments    : const struct0_T *mapB
//                const struct1_T *lineM
//                const struct2_T *params
//                int *ver
//                struct3_T *out
//                struct4_T *mapOut
// Return Type  : void
//
void AgriMapZoomInterface(const struct0_T *mapB, const struct1_T *lineM, const
  struct2_T *params, int *ver, struct3_T *out, struct4_T *mapOut)
{
  int i0;
  int loop_ub;
  double Points_data[510];
  int PreprocessingData_size_idx_0;
  double PreprocessingData_data[510];
  double mapLat_data[255];
  double mapLon_data[255];
  int Monolateral;
  double L0;
  int f_Warning0;
  int i;
  double d0;
  double b_PreprocessingData_data[510];
  int PreprocessingData_size[2];
  int i1;
  double Prep_Cnt;
  double Prep_Preprocessing[200];
  double c_PreprocessingData_data[255];
  int b_PreprocessingData_size[1];
  double d_PreprocessingData_data[255];
  int c_PreprocessingData_size[1];
  emxArray_real_T e_PreprocessingData_data;
  emxArray_real_T f_PreprocessingData_data;
  double FFLOG;
  int PointOut_size[2];
  double PointOut_data[510];
  int Clock_Flag;
  int d_PreprocessingData_size[2];
  double P_Cnt;
  double dv0[700];
  double dv1[350];
  double b_P_Cnt;
  double f_Warning1;
  double f_Warning2;
  int e_PreprocessingData_size[2];
  double PointOut[200];
  int b_PointOut_size[2];
  unsigned char u0;

  // % �ӿں���---�����㷨
  // ��γ��ת���㷨
  // % ��ʼ��
  *ver = 201;
  out->warn = 0;
  mapOut->mapCnt = 0;
  for (i0 = 0; i0 < 100; i0++) {
    mapOut->mapLat[i0] = 0.0;
    mapOut->mapLon[i0] = 0.0;
    mapOut->mapAlt[i0] = 0.0;
  }

  //
  loop_ub = mapB->mapCnt << 1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    Points_data[i0] = 0.0;
  }

  // Pointmap = zeros(mapCnt,2);
  PreprocessingData_size_idx_0 = mapB->mapCnt;
  loop_ub = mapB->mapCnt << 1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    PreprocessingData_data[i0] = 0.0;
  }

  loop_ub = mapB->mapCnt;
  for (i0 = 0; i0 < loop_ub; i0++) {
    mapLat_data[i0] = 0.0;
  }

  loop_ub = mapB->mapCnt;
  for (i0 = 0; i0 < loop_ub; i0++) {
    mapLon_data[i0] = 0.0;
  }

  // % ���
  if (1 > mapB->mapCnt) {
    loop_ub = -1;
  } else {
    loop_ub = mapB->mapCnt - 1;
  }

  for (i0 = 0; i0 <= loop_ub; i0++) {
    mapLat_data[i0] = mapB->mapLat[i0];
  }

  if (1 > mapB->mapCnt) {
    loop_ub = -1;
  } else {
    loop_ub = mapB->mapCnt - 1;
  }

  for (i0 = 0; i0 <= loop_ub; i0++) {
    mapLon_data[i0] = mapB->mapLon[i0];
  }

  if (1 > mapB->mapCnt) {
    loop_ub = -1;
  } else {
    loop_ub = mapB->mapCnt - 1;
  }

  for (i0 = 0; i0 <= loop_ub; i0++) {
    Points_data[i0 << 1] = mapLat_data[i0];
  }

  if (1 > mapB->mapCnt) {
    loop_ub = -1;
  } else {
    loop_ub = mapB->mapCnt - 1;
  }

  for (i0 = 0; i0 <= loop_ub; i0++) {
    Points_data[1 + (i0 << 1)] = mapLon_data[i0];
  }

  Monolateral = lineM->Monolateral;
  L0 = params->L0;

  // % Ԥ����
  // %����תƽ��ֱ�ǲ�������ת�����������
  f_Warning0 = 0;
  if (params->mapFlag == 1) {
    // 1Ϊ��γ�����꣬0Ϊƽ������
    // �㷨2
    for (i = 0; i < mapB->mapCnt; i++) {
      BL2XY_q(mapLat_data[i], mapLon_data[i], L0, &Points_data[i << 1], &d0);
      Points_data[1 + (i << 1)] = d0;
    }
  }

  // %
  // ���غ�ɾ��ͬһ�����
  if (1 > mapB->mapCnt) {
    loop_ub = -1;
  } else {
    loop_ub = mapB->mapCnt - 1;
  }

  for (i0 = 0; i0 <= loop_ub; i0++) {
    PreprocessingData_data[i0] = Points_data[i0 << 1];
  }

  if (1 > mapB->mapCnt) {
    loop_ub = -1;
  } else {
    loop_ub = mapB->mapCnt - 1;
  }

  for (i0 = 0; i0 <= loop_ub; i0++) {
    PreprocessingData_data[i0 + PreprocessingData_size_idx_0] = Points_data[1 +
      (i0 << 1)];
  }

  // �����־λ
  if (1 > mapB->mapCnt) {
    loop_ub = 0;
  } else {
    loop_ub = mapB->mapCnt;
  }

  PreprocessingData_size[0] = loop_ub;
  PreprocessingData_size[1] = 2;
  for (i0 = 0; i0 < 2; i0++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_PreprocessingData_data[i1 + loop_ub * i0] = PreprocessingData_data[i1 +
        PreprocessingData_size_idx_0 * i0];
    }
  }

  Preprocess(b_PreprocessingData_data, PreprocessingData_size, (double)
             mapB->mapCnt, Prep_Preprocessing, &Prep_Cnt);
  if (Prep_Cnt >= 3.0) {
    for (i0 = 0; i0 < 2; i0++) {
      loop_ub = (int)Prep_Cnt;
      for (i1 = 0; i1 < loop_ub; i1++) {
        PreprocessingData_data[i1 + PreprocessingData_size_idx_0 * i0] =
          Prep_Preprocessing[i1 + 100 * i0];
      }
    }

    // %
    // �ж�˳��ʱ�벢����
    // ˳��ʱ���־λ��0����ʱ�룬1��˳ʱ��
    b_PreprocessingData_size[0] = (int)Prep_Cnt;
    loop_ub = (int)Prep_Cnt;
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_PreprocessingData_data[i0] = PreprocessingData_data[i0];
    }

    c_PreprocessingData_size[0] = (int)Prep_Cnt;
    loop_ub = (int)Prep_Cnt;
    for (i0 = 0; i0 < loop_ub; i0++) {
      d_PreprocessingData_data[i0] = PreprocessingData_data[i0 +
        PreprocessingData_size_idx_0];
    }

    e_PreprocessingData_data.data = (double *)&c_PreprocessingData_data;
    e_PreprocessingData_data.size = (int *)&b_PreprocessingData_size;
    e_PreprocessingData_data.allocatedSize = 255;
    e_PreprocessingData_data.numDimensions = 1;
    e_PreprocessingData_data.canFreeData = false;
    f_PreprocessingData_data.data = (double *)&d_PreprocessingData_data;
    f_PreprocessingData_data.size = (int *)&c_PreprocessingData_size;
    f_PreprocessingData_data.allocatedSize = 255;
    f_PreprocessingData_data.numDimensions = 1;
    f_PreprocessingData_data.canFreeData = false;
    FFLOG = judgeClockWise(&e_PreprocessingData_data, &f_PreprocessingData_data,
      Prep_Cnt);
    if (FFLOG == 0.0) {
      PointOut_size[0] = (int)Prep_Cnt;
      PointOut_size[1] = 2;
      for (i0 = 0; i0 < 2; i0++) {
        loop_ub = (int)Prep_Cnt;
        for (i1 = 0; i1 < loop_ub; i1++) {
          PointOut_data[i1 + (int)Prep_Cnt * i0] = PreprocessingData_data[i1 +
            PreprocessingData_size_idx_0 * i0];
        }
      }

      flipud(PointOut_data, PointOut_size);
      for (i0 = 0; i0 < 2; i0++) {
        loop_ub = PointOut_size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          PreprocessingData_data[i1 + PreprocessingData_size_idx_0 * i0] =
            PointOut_data[i1 + PointOut_size[0] * i0];
        }
      }

      Monolateral = (int)Prep_Cnt - lineM->Monolateral;
      Clock_Flag = 0;
    } else {
      // PreprocessingCnt(1,1) = PreprocessingCnt(1,1);
      Clock_Flag = 1;
    }

    // % �жϱ߽����ཻ,���˳��㷨
    // �������
    d_PreprocessingData_size[0] = (int)Prep_Cnt;
    d_PreprocessingData_size[1] = 2;
    for (i0 = 0; i0 < 2; i0++) {
      loop_ub = (int)Prep_Cnt;
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_PreprocessingData_data[i1 + (int)Prep_Cnt * i0] =
          PreprocessingData_data[i1 + PreprocessingData_size_idx_0 * i0];
      }
    }

    c_Calculate_New_Indented_Bounda(b_PreprocessingData_data,
      d_PreprocessingData_size, Prep_Cnt, dv1, &d0, dv0, &P_Cnt);
    if (d0 != 0.0) {
      // ���˴�Ϊ1�������Ӧֹͣ�������ݴ���
      out->error = -1;
    } else {
      // % ���ù��ܺ���
      // �����߲������ڲ��Ѿ�������ȥ����Ч���Ͱѵ���˳ʱ�����ʽ��
      PointOut_size[0] = (int)Prep_Cnt;
      for (i0 = 0; i0 < 2; i0++) {
        loop_ub = (int)Prep_Cnt;
        for (i1 = 0; i1 < loop_ub; i1++) {
          PointOut_data[i1 + (int)Prep_Cnt * i0] = PreprocessingData_data[i1 +
            PreprocessingData_size_idx_0 * i0];
        }
      }

      b_P_Cnt = Prep_Cnt;
      f_Warning1 = 0.0;
      f_Warning2 = 0.0;

      //
      // �����ƶ�
      if (lineM->Monolateral_L != 0.0) {
        e_PreprocessingData_size[0] = (int)Prep_Cnt;
        e_PreprocessingData_size[1] = 2;
        for (i0 = 0; i0 < 2; i0++) {
          loop_ub = (int)Prep_Cnt;
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_PreprocessingData_data[i1 + (int)Prep_Cnt * i0] =
              PreprocessingData_data[i1 + PreprocessingData_size_idx_0 * i0];
          }
        }

        Calculate_Monolateral_Points(b_PreprocessingData_data,
          e_PreprocessingData_size, Prep_Cnt, (double)Monolateral,
          lineM->Monolateral_L, lineM->Monolateral_flag, (double)Clock_Flag,
          PointOut, &b_P_Cnt, &f_Warning1);
        PointOut_size[0] = 100;
        memcpy(&PointOut_data[0], &PointOut[0], 200U * sizeof(double));

        // �����ɰ�ĳ��������û��
      }

      // �������������������
      if (mapB->L != 0.0) {
        if (1.0 > b_P_Cnt) {
          loop_ub = 0;
        } else {
          loop_ub = (int)b_P_Cnt;
        }

        b_PointOut_size[0] = loop_ub;
        b_PointOut_size[1] = 2;
        for (i0 = 0; i0 < 2; i0++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_PreprocessingData_data[i1 + loop_ub * i0] = PointOut_data[i1 +
              PointOut_size[0] * i0];
          }
        }

        Calculate_Map_Points(b_PreprocessingData_data, b_PointOut_size, b_P_Cnt,
                             mapB->L, mapB->flag, params->Theita, (double)
                             Clock_Flag, PointOut, &P_Cnt, &f_Warning2);
        PointOut_size[0] = 100;
        memcpy(&PointOut_data[0], &PointOut[0], 200U * sizeof(double));
        b_P_Cnt = P_Cnt;
      }

      // % ��ͼ
      // % ƽ��ת��γ��
      d0 = rt_roundd_snf(b_P_Cnt);
      if (d0 < 256.0) {
        if (d0 >= 0.0) {
          u0 = (unsigned char)d0;
        } else {
          u0 = 0;
        }
      } else if (d0 >= 256.0) {
        u0 = MAX_uint8_T;
      } else {
        u0 = 0;
      }

      mapOut->mapCnt = u0;
      if (params->mapFlag == 0) {
        // 1Ϊ��γ�����꣬0Ϊƽ������
        if (1.0 > b_P_Cnt) {
          loop_ub = -1;
        } else {
          loop_ub = (int)b_P_Cnt - 1;
        }

        for (i0 = 0; i0 <= loop_ub; i0++) {
          mapOut->mapLat[i0] = PointOut_data[i0];
        }

        if (1.0 > b_P_Cnt) {
          loop_ub = -1;
        } else {
          loop_ub = (int)b_P_Cnt - 1;
        }

        for (i0 = 0; i0 <= loop_ub; i0++) {
          mapOut->mapLon[i0] = PointOut_data[i0 + PointOut_size[0]];
        }
      } else if (params->mapFlag == 1) {
        for (i = 0; i < mapOut->mapCnt; i++) {
          XY2BL(PointOut_data[i], PointOut_data[i + PointOut_size[0]], L0,
                &mapOut->mapLat[i], &mapOut->mapLon[i]);
        }
      } else {
        f_Warning0 = 1;

        // �����־λ
      }

      // % �����ֵ
      out->error = 0;
      if ((f_Warning0 != 0) || (f_Warning1 != 0.0) || (f_Warning2 == 1.0)) {
        out->warn = 1;
      }
    }
  } else {
    // ���˴�Ϊ1�������Ӧֹͣ�������ݴ���
    out->error = -1;
  }
}

//
// File trailer for AgriMapZoomInterface.cpp
//
// [EOF]
//
