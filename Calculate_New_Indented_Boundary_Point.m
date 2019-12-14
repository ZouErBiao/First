function [PP,PP_Cnt,PPP,PPP_Cnt] = Calculate_New_Indented_Boundary_Point(Point,P_Cnt)
%{
输入：
Point:内缩后的点集，格式为P_Cnt乘以2的矩阵
P_Cnt:点的数量
输出：
PP：各边的交点集，格式为n乘以7的矩阵
PPP：各边的顶点集，格式为n乘以7的矩阵
%}
PP_Cnt = zeros(1,1);
PPP_Cnt = zeros(1,1);
PPP_Cnt(1,1) = P_Cnt;

Pointss = zeros(P_Cnt,2);
Pointss(1:P_Cnt,1:2) = flipud(Point(1:P_Cnt,1:2));%倒置变成逆时针
Flag = zeros(1,1);
PPP = zeros(100,7);
%%此处把待处理的点集变成七列的矩阵
for i=1:P_Cnt
    PPP(i,1) = i;%原多边形顶点编号：1,2,3.......
    PPP(i,2:3) = [0 0];%第二列放该点是否被访问标记0为没访问，1代表被访问，第三列为是否是交点标记，1为是交点，0为不是交点
    PPP(i,4:5) = Pointss(i,:);%顶点坐标
    PPP(i,6:7) = [0 0];%第六列存放交点的小序号边的起点，第七咧存放交点的大序号边的起点，其他为零
end
PP = zeros(50,7);%用于记录交点信息，8列矩阵
k = zeros(1,1);
%PP为交点集
for i=3:P_Cnt
    if i < P_Cnt
        for j=1:i-2
            Flag(1,1) = Judge_Intersect(Pointss(i,1),Pointss(i,2),Pointss(i+1,1),Pointss(i+1,2),Pointss(j,1),Pointss(j,2),Pointss(j+1,1),Pointss(j+1,2));%0为不相交，非零为相交
            if Flag(1,1) ~= 0
                k(1,1) = k(1,1) + 1;
                PP(k(1,1),1:3) = [0,0,1];%序号位为零，访问标记位为0，是否交点位为1；
                PP(k(1,1),4:5)  = CalculateLineCrossover(Pointss(i,1),Pointss(i,2),Pointss(i+1,1),Pointss(i+1,2),Pointss(j,1),Pointss(j,2),Pointss(j+1,1),Pointss(j+1,2));
                PP(k(1,1),6:7) = [j,i];
            end
        end
    else
        for j=2:i-2
            Flag(1,1) = Judge_Intersect(Pointss(i,1),Pointss(i,2),Pointss(1,1),Pointss(1,2),Pointss(j,1),Pointss(j,2),Pointss(j+1,1),Pointss(j+1,2));%0为不相交，非零为相交
            if Flag(1,1) ~= 0
                k(1,1) = k(1,1) + 1;
                PP(k(1,1),1:3) = [0,0,1];%序号位为零，访问标记位为0，是否交点位为1；
                PP(k(1,1),4:5)  = CalculateLineCrossover(Pointss(i,1),Pointss(i,2),Pointss(1,1),Pointss(1,2),Pointss(j,1),Pointss(j,2),Pointss(j+1,1),Pointss(j+1,2));
                PP(k(1,1),6:7) = [j,i];
            end
        end
    end 
end
PP_Cnt(1,1) = k(1,1);