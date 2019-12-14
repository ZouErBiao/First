%% 接口函数---缩放算法
function [ver,out,mapOut] = AgriMapZoomInterface(mapB,lineM,params)
%{
作用:进行坐标转换、单边内外平移、多边形整体外扩或内缩
输入:
整体
mapB.mapCnt:输入的点的个数(数据类型:uint8 1x1)
mapB.mapLat:点的横坐标(数据类型:double 1x100)
mapB.mapLon:点的纵坐标(数据类型:double 1x100)
mapB.mapAlt:高度(double-1*100)
mapB.L:缩放距离(数据类型：double 1x1)，只保证L值连续变化时的调用满足预期；
mapB.flag:缩放标志，内缩外扩标志位，0:内缩，1;外扩，若输入其他值，则会有相应的警告！(数据类型:double 1x1)

单边
LineM.Monolateral:单边移动边界号，形如;1,2,3,4,5,...nn(数据类型:double 1x1)
LineM.Monolateral_L:单边移动距离(数据类型:double 1x1)
LineM.Monolateral_flag:移动方向，0:内移，1:外移;(数据类型:double 1x1)

params.Theita: 被认为是小锐角的角度界限，格式如：“20”，代表各顶点小于或等于20°为小锐角，需要处理；范围为0°到90°(数据类型：double 1x1)
params.mapFlag:平面坐标标志,0为平面坐标，1为经纬度坐标(数据类型：double 1x1)
params.L0:所有地块点的经度平均值(double)

输出:
mapOut.mapCnt
mapOut.mapLat
mapOut.mapLon:处理后的多边形边界点
mapOut.mapAlt

out.error:（错误码）
-0正常
-(-1)不予处理,边界交叉

out.warn:警告码
-0正常
-1异常
f_Warning0:经纬度转换标志无效
f_Warning1:单边移动无效(所选边序号无效+移动标志无效)
f_Warning2:整体缩放无效(移动标志无效)

ver:版本号
%}
%% 配置
mapTransfMethod = 0;%经纬度转换算法

%% 初始化
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

%% 入参
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
%% 预处理
%%进行转平面直角操作，并转变成两列坐标
refLat = mapLat(1);
refLon = mapLon(1);
earthR = 6371393;
latR = 6371393*cos(refLat*pi/180);
f_Warning0 = zeros(1,1);
if mapFlag(1,1) == 1%1为经纬度坐标，0为平面坐标
    if mapTransfMethod == 1%算法1
        for i=2:mapCnt
            Points(1,i) = earthR*(Points(1,i)-refLat)*pi/180;
            Points(2,i) = latR*(Points(2,i)-refLon)*pi/180;
        end
        Points(1,1)=0;
        Points(2,1)=0;
    else %算法2
        for i=1:mapCnt
            [Points(1,i),Points(2,i)] = BL2XY_q(mapLat(i),mapLon(i),L0);
        end
    end
end
%%
%除重和删除同一点操作
PreprocessingData(1:mapCnt,1) = Points(1,1:mapCnt)';
PreprocessingData(1:mapCnt,2) = Points(2,1:mapCnt)';
PreprocessingCnt(1,1) = mapCnt;
f_error0 = zeros(1,1);%错误标志位

Prep = Preprocess(PreprocessingData(1:mapCnt,1:2),mapCnt);
if Prep.Cnt >= 3
    PreprocessingData(1:Prep.Cnt(1,1),1:2) = Prep.Preprocessing(1:Prep.Cnt(1,1),1:2);
    PreprocessingCnt(1,1) = Prep.Cnt;
else
    f_error0(1,1) = int32(-1);%若此处为1，则程序应停止继续数据处理
    out.error = int32(f_error0);
    return;
end
%%
%判断顺逆时针并处理
Clock_Flag = zeros(1,1);%顺逆时针标志位，0：逆时针，1：顺时针
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
%% 判断边界线相交,则退出算法
PP = zeros(MAX_MAP_POINTS/2,7);
PPP = zeros(MAX_MAP_POINTS,7);
PP_Cnt = zeros(1,1);%交点个数
PPP_Cnt = zeros(1,1);


[PP(1:50,1:7),PP_Cnt(1,1),PPP(1:100,1:7),PPP_Cnt(1,1)] = Calculate_New_Indented_Boundary_Point(PreprocessingData(1:PreprocessingCnt,1:2),PreprocessingCnt);

if PP_Cnt(1,1) ~= 0
    f_error0(1,1) = int32(-1);%若此处为1，则程序应停止继续数据处理
    out.error = int32(f_error0);
    return;
end
%% 调用功能函数
%经单边操作（内部已经进行了去除无效环和把点变成顺时针的形式）
PointOut = PreprocessingData(1:PreprocessingCnt,1:2);
P_Cnt = PreprocessingCnt;
if eq(f_error0(1,1),0)
    f_Warning1 = zeros(1,1);
    f_Warning2 = zeros(1,1);
    %
    %单边移动
    if Monolateral_L ~= 0
        [PointOut,P_Cnt,f_Warning1] = Calculate_Monolateral_Points(PreprocessingData(1:PreprocessingCnt,1:2),PreprocessingCnt,Monolateral,Monolateral_L,Monolateral_flag,Clock_Flag(1,1));%但不可把某个便便给缩没了
    end
    %整体进行内缩外扩运算
    if L ~= 0
        [PointOut,P_Cnt,f_Warning2] = Calculate_Map_Points(PointOut(1:P_Cnt,1:2),P_Cnt,L,flag,Theita,Clock_Flag(1,1));
    end
else
    f_Warning1 = zeros(1,1);
    f_Warning2 = zeros(1,1);
end

%% 画图
if 0
    figure
    hold on;
    plot([PreprocessingData(1:PreprocessingCnt,1)], [PreprocessingData(1:PreprocessingCnt,2)],'*-');
    plot([PointOut(1:P_Cnt,1)], [PointOut(1:P_Cnt,2)],'*-');
end

%% 平面转经纬度
mapOut.mapCnt = uint8(P_Cnt(1,1));
if mapFlag(1,1) == 0%1为经纬度坐标，0为平面坐标
    mapOut.mapLat(1,1:P_Cnt(1,1)) = PointOut(1:P_Cnt(1,1),1)';
    mapOut.mapLon(1,1:P_Cnt(1,1)) = PointOut(1:P_Cnt(1,1),2)';
elseif mapFlag(1,1) == 1
    if mapTransfMethod == 1%算法1
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
    f_Warning0(1,1) = 1;%警告标志位
end

%% 输出赋值
out.error = int32(f_error0);

if f_Warning0 || f_Warning1 || f_Warning2 == 1
    out.warn = int32(1);
end

