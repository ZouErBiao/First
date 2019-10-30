%% ���Է��������ű�
clc,
clear;
%% ��������
mapLat = zeros(1,100);
mapLon = zeros(1,100);
Test_case = 1;
switch Test_case
    case 1%ָ����������߲����ϣ���ʱ�����У�
        mapCnt = 4;
        mapLat(1,1:4) = [41.70092932156389, 41.69450940886637, 41.69152002409264, 41.69932776081517];
        mapLon(1,1:4) =[123.43873771042526, 123.43890712258859, 123.43170409914063, 123.43095388447335];
        boundHeight =[0.0, 0.0, 0.0, 0.0];
    case 2%����㼯���浫������
        mapCnt = 5;
        mapLat(1,1:5) = [41.703040311544676, 41.702972571783974, 41.70019286002173, 41.69921976898997, 41.69943841512079];
        mapLon(1,1:5) =[123.42369883399843, 123.42681452705284, 123.42669463747903, 123.42376394309348, 123.42578215742878];
        boundHeight =[0.0, 0.0, 0.0, 0.0, 0.0];
    case 3%�����㹻����룬���ͻ����ֵ
        mapCnt = 4;
        mapLat(1,1:4) = [41.70092932156389, 41.69450940886637, 41.69152002409264, 41.69932776081517];
        mapLon(1,1:4) =[123.43873771042526, 123.43890712258859, 123.43170409914063, 123.43095388447335];
        boundHeight =[0.0, 0.0, 0.0, 0.0];
    case 4%��˳ʱ�����У�
        mapCnt = 4;
        mapLat(1,1:4) = [41.69932776081517, 41.69152002409264, 41.69450940886637, 41.70092932156389];
        mapLon(1,1:4) =[123.43095388447335, 123.43170409914063, 123.43890712258859, 123.43873771042526];
        boundHeight =[0.0, 0.0, 0.0, 0.0];
end
%% ��ͼ��ʾ
%%
%�ؿ��
mapB.mapCnt = uint8(mapCnt);
mapB.mapLat = mapLat;
mapB.mapLon = mapLon;
mapB.mapAlt = zeros(1,100);
switch Test_case
    case 1
        mapB.L = 0;%��λΪ��
        mapB.flag = 1;%0������1����
        lineM.Monolateral = uint8(1);%Ҫ�����ƶ��ıߺ�
        lineM.Monolateral_L = 10;
        lineM.Monolateral_flag = 1;%0����,1���ƣ�
        
        params.Theita = 15;
        params.mapFlag = int8(1);%0Ϊƽ�����꣬1Ϊ��γ������
        params.L0 = 123.43507570415696;
    case 2
        mapB.L = 10;%��λΪ��
        mapB.flag = 1.0;%0������1����
        lineM.Monolateral = uint8(-1);%Ҫ�����ƶ��ıߺ�
        lineM.Monolateral_L = 0.0;
        lineM.Monolateral_flag = 1;%0����,1���ƣ�
        
        params.Theita = 15;
        params.mapFlag = int8(1);%0Ϊƽ�����꣬1Ϊ��γ������
        params.L0 = 123.4253508198105;
    case 3
        mapB.L = 20;%��λΪ�ף�����L���Ϊ318
        mapB.flag = 0;%0������1����
        lineM.Monolateral = uint8(1);%Ҫ�����ƶ��ıߺ�
        lineM.Monolateral_L = 0;
        lineM.Monolateral_flag = 1;%0����,1���ƣ�
        
        params.Theita = 15;
        params.mapFlag = int8(1);%0Ϊƽ�����꣬1Ϊ��γ������
        params.L0 = 123.43507570415696;
    case 4
        mapB.L = 50;%��λΪ�ף�����L���Ϊ318
        mapB.flag = 0;%0������1����
        lineM.Monolateral = uint8(1);%Ҫ�����ƶ��ıߺ�
        lineM.Monolateral_L = 0;
        lineM.Monolateral_flag = 1;%0����,1���ƣ�
        
        params.Theita = 15;
        params.mapFlag = int8(1);%0Ϊƽ�����꣬1Ϊ��γ������
        params.L0 = 123.43507570415696;
end
%% ���ýӿں���
[ver,out,mapOut] = AgriMapZoomInterface(mapB,lineM,params);
out

PointLast(1:mapOut.mapCnt,1) = mapOut.mapLat(1,1:mapOut.mapCnt)';
PointLast(1:mapOut.mapCnt,2) = mapOut.mapLon(1,1:mapOut.mapCnt)';
%% ��ͼ��ʾ
figure
hold on;
plot([mapLat(1:mapCnt),mapLat(1)],[mapLon(1:mapCnt),mapLon(1)],'*-');%ԭͼ
%
if mapOut.mapCnt > 0
PointLast = [PointLast;PointLast(1,:)];%��ͼ
plot(PointLast(:,1).',PointLast(:,2).','ro-');
end
title('�����űߴ�����ͼ����ɫΪԭͼ����ɫΪ��ͼ');
xlabel('x');
ylabel('y');
grid;
