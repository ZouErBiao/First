%% 测试反馈用例脚本
clc,
clear;
%% 设置用例
mapLat = zeros(1,100);
mapLon = zeros(1,100);
Test_case = 1;
switch Test_case
    case 1%指定边与操作边不符合（逆时针排列）
        mapCnt = 4;
        mapLat(1,1:4) = [41.70092932156389, 41.69450940886637, 41.69152002409264, 41.69932776081517];
        mapLon(1,1:4) =[123.43873771042526, 123.43890712258859, 123.43170409914063, 123.43095388447335];
        boundHeight =[0.0, 0.0, 0.0, 0.0];
    case 2%输入点集交叉但不报错
        mapCnt = 5;
        mapLat(1,1:5) = [41.703040311544676, 41.702972571783974, 41.70019286002173, 41.69921976898997, 41.69943841512079];
        mapLon(1,1:5) =[123.42369883399843, 123.42681452705284, 123.42669463747903, 123.42376394309348, 123.42578215742878];
        boundHeight =[0.0, 0.0, 0.0, 0.0, 0.0];
    case 3%内缩足够大距离，面积突破零值
        mapCnt = 4;
        mapLat(1,1:4) = [41.70092932156389, 41.69450940886637, 41.69152002409264, 41.69932776081517];
        mapLon(1,1:4) =[123.43873771042526, 123.43890712258859, 123.43170409914063, 123.43095388447335];
        boundHeight =[0.0, 0.0, 0.0, 0.0];
    case 4%（顺时针排列）
        mapCnt = 4;
        mapLat(1,1:4) = [41.69932776081517, 41.69152002409264, 41.69450940886637, 41.70092932156389];
        mapLon(1,1:4) =[123.43095388447335, 123.43170409914063, 123.43890712258859, 123.43873771042526];
        boundHeight =[0.0, 0.0, 0.0, 0.0];
end
%% 画图显示
%%
%地块点
mapB.mapCnt = uint8(mapCnt);
mapB.mapLat = mapLat;
mapB.mapLon = mapLon;
mapB.mapAlt = zeros(1,100);
switch Test_case
    case 1
        mapB.L = 0;%单位为米
        mapB.flag = 1;%0内缩，1外扩
        lineM.Monolateral = uint8(1);%要单独移动的边号
        lineM.Monolateral_L = 10;
        lineM.Monolateral_flag = 1;%0内移,1外移；
        
        params.Theita = 15;
        params.mapFlag = int8(1);%0为平面坐标，1为经纬度坐标
        params.L0 = 123.43507570415696;
    case 2
        mapB.L = 10;%单位为米
        mapB.flag = 1.0;%0内缩，1外扩
        lineM.Monolateral = uint8(-1);%要单独移动的边号
        lineM.Monolateral_L = 0.0;
        lineM.Monolateral_flag = 1;%0内移,1外移；
        
        params.Theita = 15;
        params.mapFlag = int8(1);%0为平面坐标，1为经纬度坐标
        params.L0 = 123.4253508198105;
    case 3
        mapB.L = 20;%单位为米，此例L最大为318
        mapB.flag = 0;%0内缩，1外扩
        lineM.Monolateral = uint8(1);%要单独移动的边号
        lineM.Monolateral_L = 0;
        lineM.Monolateral_flag = 1;%0内移,1外移；
        
        params.Theita = 15;
        params.mapFlag = int8(1);%0为平面坐标，1为经纬度坐标
        params.L0 = 123.43507570415696;
    case 4
        mapB.L = 50;%单位为米，此例L最大为318
        mapB.flag = 0;%0内缩，1外扩
        lineM.Monolateral = uint8(1);%要单独移动的边号
        lineM.Monolateral_L = 0;
        lineM.Monolateral_flag = 1;%0内移,1外移；
        
        params.Theita = 15;
        params.mapFlag = int8(1);%0为平面坐标，1为经纬度坐标
        params.L0 = 123.43507570415696;
end
%% 调用接口函数
[ver,out,mapOut] = AgriMapZoomInterface(mapB,lineM,params);
out

PointLast(1:mapOut.mapCnt,1) = mapOut.mapLat(1,1:mapOut.mapCnt)';
PointLast(1:mapOut.mapCnt,2) = mapOut.mapLon(1,1:mapOut.mapCnt)';
%% 画图显示
figure
hold on;
plot([mapLat(1:mapCnt),mapLat(1)],[mapLon(1:mapCnt),mapLon(1)],'*-');%原图
%
if mapOut.mapCnt > 0
PointLast = [PointLast;PointLast(1,:)];%新图
plot(PointLast(:,1).',PointLast(:,2).','ro-');
end
title('经缩放边处理后的图，蓝色为原图，红色为新图');
xlabel('x');
ylabel('y');
grid;
