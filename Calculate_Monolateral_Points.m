function [Points_Monolateral,PM_Cnt,f_error] = Calculate_Monolateral_Points(Points,n,Monolateral,Monolateral_L,Monolateral_flag,Clock_Flag)
%计算单边内缩的点
%{
输入：
n:多边形点的个数(数据类型：double 1x1)
Points：需要移动某边的多变形的边界点集，格式为多行两列的矩阵(数据类型：double nx2)
Monolateral：要移动的边的边号(数据类型：double 1x1)
Monolateral_L：某边要移动的距离,不能把某个边给缩没了(数据类型：double 1x1)
Monolateral_flag：某边要移动的方向(数据类型：double 1x1)
输出：
PM_Cnt：输出的有效点的个数(数据类型：double 1x1)
Points_Monolateral：经过移动某边后的多边形的边界点(数据类型：double 100x2)
f_error：错误标志，为零则无错误，为1为有错误(数据类型：double 1x1)
%}
Points_Monolateral = zeros(100,2);
PM_Cnt = zeros(1,1);

NEdgevectorList = zeros(n,2);
NEdgevectorList(1:n,1:2) = DPList(Points(1:n,1:2),n);
NEdgevectorList(1:n,1:2) = NormalizeDPList(NEdgevectorList(1:n,1:2),n);%单位向量
Sina = zeros(1,n);
Sina(1,1:n) = CalculateSina(NEdgevectorList(1:n,1:2),n);
f_error = zeros(1,1);

if Monolateral > n || Monolateral < 1
    f_error(1,1) = 1;
end
if eq(f_error(1,1),1)
    Points_Monolateral(1:n,1:2) = zeros(n,2);
else
    switch Monolateral_flag
        case 0%内移
            if Monolateral == 1
                Points(1,1:2) = Points(1,:)-NEdgevectorList(n,:)*Monolateral_L/Sina(1,1);
                Points(2,1:2) = NEdgevectorList(2,:)*Monolateral_L/Sina(1,2) + Points(2,1:2);
            elseif Monolateral < n
                Points(Monolateral,1:2) = Points(Monolateral,1:2)-NEdgevectorList(Monolateral-1,1:2)*Monolateral_L/Sina(1,Monolateral);
                Points(Monolateral+1,1:2) = Points(Monolateral+1,1:2)+NEdgevectorList(Monolateral+1,1:2)*Monolateral_L/Sina(1,Monolateral+1);
            else
                Points(Monolateral,1:2) = Points(Monolateral,1:2)-NEdgevectorList(Monolateral-1,1:2)*Monolateral_L/Sina(1,Monolateral);
                Points(1,1:2) = Points(1,1:2)+NEdgevectorList(1,1:2)*Monolateral_L/Sina(1,1);
            end
        case 1%外移
            if Monolateral == 1
                Points(1,1:2) = Points(1,1:2)+NEdgevectorList(n,1:2)*Monolateral_L/Sina(1,1);
                Points(2,1:2) = Points(2,1:2)-NEdgevectorList(2,1:2)*Monolateral_L/Sina(1,2);
            elseif Monolateral < n
                Points(Monolateral,1:2) = Points(Monolateral,1:2) + NEdgevectorList(Monolateral-1,1:2)*Monolateral_L/Sina(1,Monolateral);
                Points(Monolateral+1,1:2) = Points(Monolateral+1,1:2) - NEdgevectorList(Monolateral+1,1:2)*Monolateral_L/Sina(1,Monolateral+1);
            else
                Points(Monolateral,1:2) = Points(Monolateral,1:2) + NEdgevectorList(Monolateral-1,1:2)*Monolateral_L/Sina(1,Monolateral);
                Points(1,1:2) = Points(1,1:2) - NEdgevectorList(1,1:2)*Monolateral_L/Sina(1,1);
            end
        otherwise
            f_error(1,1) = 1;
            %warning('输入的平面坐标标志并非简单地0或1');
    end
    PointLast = zeros(100,2);
    PL_Cnt = zeros(1,1);
    [PointLast(1:100,1:2),PL_Cnt(1,1)] = Calculate_Effective_Point(Points(1:n,1:2),n);%去除无效环
    if eq(Clock_Flag,0)
        PM_Cnt(1,1) = PL_Cnt(1,1);
        Points_Monolateral(1:PM_Cnt(1,1),1:2) = PointLast(1:PL_Cnt(1,1),1:2);%把结果变成顺时针的
    else
        PM_Cnt(1,1) = PL_Cnt(1,1);
        Points_Monolateral(1:PM_Cnt(1,1),1:2) = flipud(PointLast(1:PL_Cnt(1,1),1:2));%把结果变成顺时针的
    end
end
