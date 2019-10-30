%% �ӿں���---�����㷨
function [ver,out,mapOut] = AgriMapZoomInterface(mapB,lineM,params)
%{
����:��������ת������������ƽ�ơ��������������������
����:
����
mapB.mapCnt:����ĵ�ĸ���(��������:uint8 1x1)
mapB.mapLat:��ĺ�����(��������:double 1x100)
mapB.mapLon:���������(��������:double 1x100)
mapB.mapAlt:�߶�(double-1*100)
mapB.L:���ž���(�������ͣ�double 1x1)��ֻ��֤Lֵ�����仯ʱ�ĵ�������Ԥ�ڣ�
mapB.flag:���ű�־������������־λ��0:������1;����������������ֵ���������Ӧ�ľ��棡(��������:double 1x1)

����
LineM.Monolateral:�����ƶ��߽�ţ�����;1,2,3,4,5,...nn(��������:double 1x1)
LineM.Monolateral_L:�����ƶ�����(��������:double 1x1)
LineM.Monolateral_flag:�ƶ�����0:���ƣ�1:����;(��������:double 1x1)

params.Theita: ����Ϊ��С��ǵĽǶȽ��ޣ���ʽ�磺��20�������������С�ڻ����20��ΪС��ǣ���Ҫ������ΧΪ0�㵽90��(�������ͣ�double 1x1)
params.mapFlag:ƽ�������־,0Ϊƽ�����꣬1Ϊ��γ������(�������ͣ�double 1x1)
params.L0:���еؿ��ľ���ƽ��ֵ(double)

���:
mapOut.mapCnt
mapOut.mapLat
mapOut.mapLon:�����Ķ���α߽��
mapOut.mapAlt

out.error:�������룩
-0����
-(-1)���账��,�߽罻��

out.warn:������
-0����
-1�쳣
f_Warning0:��γ��ת����־��Ч
f_Warning1:�����ƶ���Ч(��ѡ�������Ч+�ƶ���־��Ч)
f_Warning2:����������Ч(�ƶ���־��Ч)

ver:�汾��
%}
%% ����
mapTransfMethod = 0;%��γ��ת���㷨

%% ��ʼ��
ver = int32(201);
out.error = int32(0);
out.warn = int32(0);

MAX_MAP_POINTS = 100;
mapOut.mapCnt = uint8(0);
mapOut.mapLat = zeros(1,MAX_MAP_POINTS);
mapOut.mapLon = zeros(1,MAX_MAP_POINTS);
mapOut.mapAlt = zeros(1,MAX_MAP_POINTS);
%
mapCnt = double(mapB.mapCnt);
Points = zeros(2,mapCnt);
%Pointmap = zeros(mapCnt,2);

PreprocessingData = zeros(mapCnt,2);
PreprocessingCnt = zeros(1,1);

mapLat = zeros(1,mapCnt);
mapLon = zeros(1,mapCnt);
L = zeros(1,1);
flag = zeros(1,1);

Monolateral = zeros(1,1);
Monolateral_L = zeros(1,1);
Monolateral_flag = zeros(1,1);

Theita = zeros(1,1);
mapFlag = zeros(1,1);
L0 = zeros(1,1);

%% ���
mapLat(1,1:mapCnt) = mapB.mapLat(1,1:mapCnt);
mapLon(1,1:mapCnt) = mapB.mapLon(1,1:mapCnt);
Points(1,:) = mapLat(1,1:mapCnt);
Points(2,:) = mapLon(1,1:mapCnt);
L(1,1) = mapB.L;
flag(1,1) = mapB.flag;

Monolateral(1,1) = lineM.Monolateral;
Monolateral_L(1,1) = lineM.Monolateral_L;
Monolateral_flag(1,1) = lineM.Monolateral_flag;

Theita(1,1) = params.Theita;
mapFlag(1,1) = params.mapFlag;
L0(1,1) = params.L0;
%% Ԥ����
%%����תƽ��ֱ�ǲ�������ת�����������
refLat = mapLat(1);
refLon = mapLon(1);
earthR = 6371393;
latR = 6371393*cos(refLat*pi/180);
f_Warning0 = zeros(1,1);
if mapFlag(1,1) == 1%1Ϊ��γ�����꣬0Ϊƽ������
    if mapTransfMethod == 1%�㷨1
        for i=2:mapCnt
            Points(1,i) = earthR*(Points(1,i)-refLat)*pi/180;
            Points(2,i) = latR*(Points(2,i)-refLon)*pi/180;
        end
        Points(1,1)=0;
        Points(2,1)=0;
    else %�㷨2
        for i=1:mapCnt
            [Points(1,i),Points(2,i)] = BL2XY_q(mapLat(i),mapLon(i),L0);
        end
    end
end
%%
%���غ�ɾ��ͬһ�����
PreprocessingData(1:mapCnt,1) = Points(1,1:mapCnt)';
PreprocessingData(1:mapCnt,2) = Points(2,1:mapCnt)';
PreprocessingCnt(1,1) = mapCnt;
f_error0 = zeros(1,1);%�����־λ

Prep = Preprocess(PreprocessingData(1:mapCnt,1:2),mapCnt);
if Prep.Cnt >= 3
    PreprocessingData(1:Prep.Cnt(1,1),1:2) = Prep.Preprocessing(1:Prep.Cnt(1,1),1:2);
    PreprocessingCnt(1,1) = Prep.Cnt;
else
    f_error0(1,1) = int32(-1);%���˴�Ϊ1�������Ӧֹͣ�������ݴ���
    out.error = int32(f_error0);
    return;
end
%%
%�ж�˳��ʱ�벢����
Clock_Flag = zeros(1,1);%˳��ʱ���־λ��0����ʱ�룬1��˳ʱ��
FFLOG = judgeClockWise(PreprocessingData(1:PreprocessingCnt(1,1),1),PreprocessingData(1:PreprocessingCnt(1,1),2),PreprocessingCnt(1,1));
if FFLOG(1,1) == 0
    PreprocessingData(1:PreprocessingCnt(1,1),1:2) = flipud(PreprocessingData(1:PreprocessingCnt(1,1),1:2));
    Monolateral(1,1) = PreprocessingCnt(1,1) - Monolateral(1,1);
    Clock_Flag(1,1) = 0;
else
    PreprocessingData(1:PreprocessingCnt(1,1),1:2) = PreprocessingData(1:PreprocessingCnt(1,1),1:2);
    %PreprocessingCnt(1,1) = PreprocessingCnt(1,1);
    Clock_Flag(1,1) = 1;
end
%% �жϱ߽����ཻ,���˳��㷨
PP = zeros(MAX_MAP_POINTS/2,7);
PPP = zeros(MAX_MAP_POINTS,7);
PP_Cnt = zeros(1,1);%�������
PPP_Cnt = zeros(1,1);


[PP(1:50,1:7),PP_Cnt(1,1),PPP(1:100,1:7),PPP_Cnt(1,1)] = Calculate_New_Indented_Boundary_Point(PreprocessingData(1:PreprocessingCnt,1:2),PreprocessingCnt);

if PP_Cnt(1,1) ~= 0
    f_error0(1,1) = int32(-1);%���˴�Ϊ1�������Ӧֹͣ�������ݴ���
    out.error = int32(f_error0);
    return;
end
%% ���ù��ܺ���
%�����߲������ڲ��Ѿ�������ȥ����Ч���Ͱѵ���˳ʱ�����ʽ��
PointOut = PreprocessingData(1:PreprocessingCnt,1:2);
P_Cnt = PreprocessingCnt;
if eq(f_error0(1,1),0)
    f_Warning1 = zeros(1,1);
    f_Warning2 = zeros(1,1);
    %
    %�����ƶ�
    if Monolateral_L ~= 0
        [PointOut,P_Cnt,f_Warning1] = Calculate_Monolateral_Points(PreprocessingData(1:PreprocessingCnt,1:2),PreprocessingCnt,Monolateral,Monolateral_L,Monolateral_flag,Clock_Flag(1,1));%�����ɰ�ĳ��������û��
    end
    %�������������������
    if L ~= 0
        [PointOut,P_Cnt,f_Warning2] = Calculate_Map_Points(PointOut(1:P_Cnt,1:2),P_Cnt,L,flag,Theita,Clock_Flag(1,1));
    end
else
    f_Warning1 = zeros(1,1);
    f_Warning2 = zeros(1,1);
end

%% ��ͼ
if 0
    figure
    hold on;
    plot([PreprocessingData(1:PreprocessingCnt,1)], [PreprocessingData(1:PreprocessingCnt,2)],'*-');
    plot([PointOut(1:P_Cnt,1)], [PointOut(1:P_Cnt,2)],'*-');
end

%% ƽ��ת��γ��
mapOut.mapCnt = uint8(P_Cnt(1,1));
if mapFlag(1,1) == 0%1Ϊ��γ�����꣬0Ϊƽ������
    mapOut.mapLat(1,1:P_Cnt(1,1)) = PointOut(1:P_Cnt(1,1),1)';
    mapOut.mapLon(1,1:P_Cnt(1,1)) = PointOut(1:P_Cnt(1,1),2)';
elseif mapFlag(1,1) == 1
    if mapTransfMethod == 1%�㷨1
        for i=1:sum(mapOut.mapCnt)
             mapOut.mapLat(i) = PointOut(i,1)*180/pi/earthR + refLat;
             mapOut.mapLon(i) = PointOut(i,2)*180/pi/latR + refLon;
        end
    else
        for i=1:sum(mapOut.mapCnt)
         [mapOut.mapLat(i),mapOut.mapLon(i)] = XY2BL(PointOut(i,1),PointOut(i,2),L0);
       end
    end
else
    f_Warning0(1,1) = 1;%�����־λ
end

%% �����ֵ
out.error = int32(f_error0);

if f_Warning0 || f_Warning1 || f_Warning2 == 1
    out.warn = int32(1);
end

