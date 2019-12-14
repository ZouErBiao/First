function [PointLast,PL_Cnt,f_error] = Calculate_Map_Points(Point,P_Cnt,L,flag,Theita,Clock_Flag)
%{
作用：对多边形进行整体内缩或外扩
输入：
P_Cnt:为点集点的个数(数据类型：double 1x1)
Point:为初始点坐标集(数据类型：double P_Cntx1)
L:为缩放的宽度(数据类型：double 1x1)
flag: = 0缩小，flag = 1,扩大(数据类型：double 1x1)
Theita:为小角度的上限(数据类型：double 1x1)
Clock_Flag:原输入点集的时针方向（未经转换成顺时针前）
0-逆时针
1-顺时针
输出：
PL_Cnt:输出点集点的个数(数据类型：double 1x1)
PointLast：处理后的点集(数据类型：double PL_Cntx1)
f_error：0：正常；1：出现错误(数据类型：double 1x1)
%}
n = zeros(1,1);
n(1,1) = P_Cnt;
Sina = zeros(1,n(1,1));
EList = zeros(n(1,1),2);
NEdgevectorList = zeros(n(1,1),2);
EList(1:n(1,1),1:2) = DPList(Point(1:n(1,1),1:2),n(1,1));
NEdgevectorList(1:n(1,1),1:2) = NormalizeDPList(EList(1:n(1,1),1:2),n(1,1));%单位向量
Sina(1,1:n(1,1)) = CalculateSina(NEdgevectorList(1:n(1,1),1:2),n(1,1));

P = zeros(100,2);
PP_Cnt = zeros(1,1);
PointLast = zeros(100,2);
PL_Cnt = zeros(1,1);
t = zeros(1,1);
Area = zeros(1,1);
Area_Limit = 20;%内缩后的多变行面积最小值为某一常数，如果L对应的内缩面积是Area_Limit，则保留L-0.5米对应的内缩后的点

f_error = zeros(1,1);
%%
switch flag %flag: = 0缩小，flag = 1,扩大
    case 0
       t(1,1) = 1;
       while t(1,1)
           for i = 2:n(1,1)
               P(i,1:2) = Point(i,1:2) + (NEdgevectorList(i,1:2) - NEdgevectorList(i-1,1:2)) * L / Sina(1,i);
           end
           P(1,1:2) = Point(1,1:2) + (NEdgevectorList(1,1:2) - NEdgevectorList(n(1,1),1:2)) * L / Sina(1,1);
           
           Prep = Preprocess(P(1:n(1,1),1:2),n(1,1));
           P(1:100,1:2) = zeros(100,2);
           P(1:100,1:2) = Prep.Preprocessing(1:100,1:2);
           PP_Cnt(1,1) = Prep.Cnt(1,1);
           [PointLast(1:100,1:2),PL_Cnt(1,1)] = Calculate_Effective_Point(P(1:PP_Cnt(1,1),1:2),PP_Cnt(1,1));
           Area(1,1) = Calculate_Area(PointLast(1:PL_Cnt(1,1),1:2),PL_Cnt(1,1));
           %%
           %此处只能解决L渐变的翻转情况
           if Area(1,1) < Area_Limit
               L = L - 0.5;
           else
               t(1,1) = 0;
           end
       end
        if eq(Clock_Flag,1)
            PointLast(1:PL_Cnt(1,1),1:2) = flipud(PointLast(1:PL_Cnt(1,1),1:2));%转换成与初始输入时的时针顺序一致
        end
    case 1
        [PointLast(1:100,1:2),PL_Cnt(1,1)]  = CalculateNewPoint(Point(1:P_Cnt,1:2),P_Cnt,L,Theita);
        if eq(Clock_Flag,0)
           PointLast(1:PL_Cnt(1,1),1:2) = flipud(PointLast(1:PL_Cnt(1,1),1:2));%%转换成与刚输入时的时针顺序一致
       end
    otherwise
        f_error(1,1) = 1;
end