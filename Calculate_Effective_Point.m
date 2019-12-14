function [YouXiao,YX_Cnt] = Calculate_Effective_Point(PointLast,N)
%{
%对经过内缩后的点集进行去无效环处理
输入：
PointLast为经内缩后的点集，为多行两列的矩阵,顺时针排列的%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
输出：
YouXiao为经过处理后的保留下来的有效环的点集，为多行两列的矩阵
%}
YouXiao = zeros(100,2);
YX_Cnt = zeros(1,1);

PP = zeros(50,7);
PPP = zeros(100,7);
PP_Cnt = zeros(1,1);
PPP_Cnt = zeros(1,1);
[PP(1:50,1:7),PP_Cnt(1,1),PPP(1:100,1:7),PPP_Cnt(1,1)] =Calculate_New_Indented_Boundary_Point(PointLast(1:N,1:2),N);%PPP为经过倒置、加列处理后的的七列顶点集，~为原顶点集倒置后的点集，PP为无序的交点集矩阵，也经过处理变成了七列的矩阵
PP(1:50,1:7) = Sort(PP(1:50,1:7),PP_Cnt(1,1));%对交点进行小序号边的起点进行排序，方便插入原顶点集

PolygonList = zeros(100,7);
n = zeros(1,1);
[PolygonList(1:100,1:7),n(1,1)] = CalculateIntersection(PPP(1:PPP_Cnt(1,1),1:7),PPP_Cnt(1,1),PP(1:PP_Cnt(1,1),1:7),PP_Cnt(1,1));%中和交点的顶点集
%[PolygonList(1:100,1:7),n(1,1)] = Preprocessing(PolygonList(1:n(1,1),1:7),n(1,1));%去除交点和原顶点相同的点

newPolygonnum = zeros(1,1);%经切割后，简单多边形的个数
b = zeros(50,1);
C_Cnt = zeros(1,4);%用于下标计数用

ccc = zeros(n(1,1),1);
newPolygonList = zeros(n(1,1),7);
i=1;
tt = ones(1,1);
newPolygonnum(1,1) = newPolygonnum(1,1) +1;
newPolygonListPP = zeros(n(1,1),7);

newPolygonListPP(i,:) = PolygonList(i,:);%每个新环的存储矩阵
C_Cnt(1,2) = 1;
PolygonList(1,2) = 1;

row = zeros(n(1,1),1);%用于查找结果存储
m = zeros(1,4);
while tt(1,1) >= 1
    i=i+1;%%step4
    if i == n(1,1)+1
        i=1;
    end
        if PolygonList(i,3)==1 && (PolygonList(i,4) ~= newPolygonListPP(1,4) || PolygonList(i,5) ~= newPolygonListPP(1,5)) %判断是否为交点
            C_Cnt(1,1) = C_Cnt(1,1) + 1;
            b(C_Cnt(1,1),1) = i;
            
            C_Cnt(1,2) = C_Cnt(1,2) + 1;
            newPolygonListPP(C_Cnt(1,2),1:7) = PolygonList(i,1:7);%%以便此处添加一行
            
            row(1:n(1,1),1) = ismember(PolygonList(1:n(1,1),1:7),PolygonList(i,1:7),'rows');
            mm = find(row(1:n(1,1),1) == 1);
            [m(1,1),m(1,2)] = size(mm);
            if m(1,1)==1
                m(1,3) = PolygonList(i,7)+1;
                if m(1,3) > PPP_Cnt(1,1)%经过加一处理后，m(1,3)可能超过了未插入交点前的点集的点数
                    i = 0;
                else
                    for ii=1:n(1,1)
                        if eq(PolygonList(ii,1),m(1,3))
                            i = ii - 1;
                            break;
                        end
                    end
                    %m(1,4) = find(PolygonList(1:n(1,1),1)==m(1,3));
                    %i = m(1,4)-1;
                end
                
            else
                i = mm(2,1);
            end
        else%%Step6
            if PolygonList(i,4) ~= newPolygonListPP(1,4) || PolygonList(i,5) ~= newPolygonListPP(1,5) && PolygonList(i,2) == 0
                
                C_Cnt(1,2) = C_Cnt(1,2) + 1;
                newPolygonListPP(C_Cnt(1,2),:) = PolygonList(i,:);%%以便此处添加一行
                PolygonList(i,2) = 1;
            else
                PolygonList(i,2)=1;
                
                C_Cnt(1,3) = C_Cnt(1,3) + 1;
                ccc(C_Cnt(1,3),1) = C_Cnt(1,2);%存储每个环的顶点数
                
                newPolygonList(C_Cnt(1,4)+1:C_Cnt(1,4)+C_Cnt(1,2),1:7) = newPolygonListPP(1:C_Cnt(1,2),1:7);
                C_Cnt(1,4) = C_Cnt(1,4) + C_Cnt(1,2);
                
                newPolygonnum(1,1) = newPolygonnum(1,1) +1;%再次申请一个新的静态矩阵形式的空间
                newPolygonListPP = zeros(n(1,1),7);
                
                tttt=find(PolygonList(1:n(1,1),2)==0);%判断是否访问完了
                ttt = zeros(1,2);
                [ttt(1,1),ttt(1,2)]=size(tttt);
                if ttt(1,1) == 0
                    break;
                end
                newPolygonListPP(1,:) = PolygonList(b(newPolygonnum(1,1)-1,1),:);%重新开始一个环循环
                PolygonList(b(newPolygonnum(1,1)-1,1),2) = 1;
                C_Cnt(1,2) = 1;
                i = b(newPolygonnum(1,1)-1,1);
            end 
        end
        tt(1,1) = tt(1,1)+1;
        if tt(1,1) >= 100+PP_Cnt(1,1)*3
            break;
            %error('在处理无效环时陷入死循环！');
        end
end
%%
Aera = zeros(C_Cnt(1,3),3);
C_Aera = zeros(1,1);
FFLOG0 = zeros(1,1);
ct = zeros(1,1);
ind = zeros(1,2);
if C_Cnt(1,3)==1
    YouXiao(1:C_Cnt(1,4),1:2) = newPolygonList(1:C_Cnt(1,4),4:5);
    YX_Cnt(1,1) = C_Cnt(1,4);
else
    for i=1:C_Cnt(1,3)
        if i==1
            FFLOG0(1,1) = judgeClockWise(newPolygonList(1:ccc(i),4),newPolygonList(1:ccc(i),5),ccc(i));
            if FFLOG0(1,1) == 0
                YouXiao(1:ccc(i),1:2) = newPolygonList(1:ccc(i),4:5);
                C_Aera(1,1) = C_Aera(1,1) + 1;
                Aera(C_Aera(1,1),1:3) = [Calculate_Area(YouXiao(1:ccc(i),1:2),ccc(i)),ccc(i),i];
                %Mianji = [Mianji;[CalculateMianji(YouXiao,ccc(i)),ccc(i),i]];
            end
            %FFLOGzong = [FFLOGzong;FFLOG0];
        else
            ct(1,1) = sum(ccc(1:i-1));
            FFLOG0(1,1) = judgeClockWise(newPolygonList(ct(1,1)+1:ct(1,1)+ccc(i),4),newPolygonList(ct(1,1)+1:ct(1,1)+ccc(i),5),ccc(i));
            if FFLOG0(1,1)==0
                YouXiao(1:ccc(i),1:2) = newPolygonList(ct(1,1)+1:ct(1,1)+ccc(i),4:5);
                
                C_Aera(1,1) = C_Aera(1,1) + 1;
                Aera(C_Aera(1,1),1:3) = [Calculate_Area(YouXiao(1:ccc(i),1:2),ccc(i)),ccc(i),i];
                %Mianji = [Mianji;[CalculateMianji(YouXiao,ccc(i)),ccc(i),i]];
            end
        end
    end
    YouXiao(1:100,1:2) = zeros(100,2);
    [ind(1,1), ind(1,2)] = max(Aera(:,1)); %找到第一列最大值的序号
    Aera(1,1:3) = Aera(ind(1,2),1:3); %显示最大值所在的一行的元素 
    if Aera(1,3) == 1
        YouXiao(1:Aera(1,2),1:2) = newPolygonList(1:Aera(1,2),4:5);
        YX_Cnt(1,1) = Aera(1,2);
    else
        ct(1,1) = sum(ccc(1:Aera(1,3)-1,1));
        YouXiao(1:Aera(1,2),1:2) = newPolygonList(ct(1,1)+1:ct(1,1)+Aera(1,2),4:5);
        YX_Cnt(1,1) = Aera(1,2);
    end
end
