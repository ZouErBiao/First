function [Points,Cnt] = CalculateNewPoint(Point,P_Cnt,L,Theita)
%{
计算外扩后点的边界点
输入：
Point：需要外扩的多边形的边界点，格式为多行两列的矩阵，单位为m
L：需要外扩的距离，单位为m
Theita：是否为锐角的划分边界，单位为°
输出：
Points：经过外扩后的多边形的边界点，格式为多行两列的矩阵，单位为m
Cnt:输出点集有效点的个数
%}
%%
PreprocessingData = zeros(100,2);
PD_Cnt = zeros(1,1);
Prep = Preprocess(Point(1:P_Cnt,1:2),P_Cnt);%对数据进行除重和删除同一点操作；
PreprocessingData(1:100,1:2) = Prep.Preprocessing;
PD_Cnt(1,1) = Prep.Cnt;

NEdgevectorList = zeros(100,2);
NEdgevectorList(1:PD_Cnt(1,1),1:2) = DPList(PreprocessingData(1:PD_Cnt(1,1),1:2),PD_Cnt(1,1));
NEdgevectorList(1:PD_Cnt(1,1),1:2) = NormalizeDPList(NEdgevectorList(1:PD_Cnt(1,1),1:2),PD_Cnt(1,1));%单位向量
Sina = zeros(1,PD_Cnt(1,1));
Cosa = zeros(1,PD_Cnt(1,1));
Sina(1,1:PD_Cnt(1,1)) = CalculateSina(NEdgevectorList(1:PD_Cnt(1,1),1:2),PD_Cnt(1,1));
Cosa(1,1:PD_Cnt(1,1)) = CalculateCosa(NEdgevectorList(1:PD_Cnt(1,1),1:2),PD_Cnt(1,1));

P = zeros(100,2);
[P(1:100,1:2),PD_Cnt(1,1)] = Reduce_Angle(PreprocessingData(1:PD_Cnt(1,1),1:2),PD_Cnt(1,1),L,Sina(1,1:PD_Cnt(1,1)),Cosa(1,1:PD_Cnt(1,1)),NEdgevectorList(1:PD_Cnt(1,1),1:2),Theita);
%%
PrepNew = Preprocess(P(1:PD_Cnt(1,1),1:2),PD_Cnt(1,1));
P(1:100,1:2) = zeros(100,2);
P(1:100,1:2) = PrepNew.Preprocessing;
PD_Cnt(1,1) = PrepNew.Cnt;

Points = zeros(100,2);
Cnt = zeros(1,1);
n = zeros(1,1);
n(1,1) = PD_Cnt(1,1);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%{
P(PD_Cnt(1,1)+1,1:2) = P(1,1:2);
subplot(1,2,1);
plot(P(1:PD_Cnt(1,1)+1,1).',P(1:PD_Cnt(1,1)+1,2).','ro-');
title('未删除无效环');
xlabel('x');
ylabel('y');
grid;
%}
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%10.9%%%%%%%%%%%%%%%%%%%%%%%%%%%
%[Points(1:100,1:2),Cnt(1,1)] = Calculate_Effective_Point(P(1:PD_Cnt(1,1),1:2),PD_Cnt(1,1));
%%

%以下是保留边界点的循环
Flag = zeros(1,1);
tt_j = zeros(1,1);
ff = zeros(1,1);
tt = 1;
while tt ==1
    if n < 4
        Points(1:100,1:2) = P(1:100,1:2);
        Cnt(1,1) = PD_Cnt(1,1);
        break;
    end
    ff(1,1) = 0;
    for i=3:n
        Points(1:100,1:2) = zeros(100,2);
        if i < n
            for j=1:i-2
                Flag(1,1) = Judge_Intersect(P(i,1),P(i,2),P(i+1,1),P(i+1,2),P(j,1),P(j,2),P(j+1,1),P(j+1,2));%0为不相交，非零为相交
                if Flag(1,1) ~= 0
                    Points(1:j,1:2) = P(1:j,:);
                    Points(j+1,1:2) = CalculateLineCrossover(P(i,1),P(i,2),P(i+1,1),P(i+1,2),P(j,1),P(j,2),P(j+1,1),P(j+1,2));
                    Points(j+2:j+1+n-i,1:2) = P(i+1:n,:);
                    Cnt(1,1) = j+1+n-i;
                    ff(1,1) = 1;
                    if j == n-3
                        tt_j(1,1) = 1;
                    end
                    break;
                else
                    Points(1:j,1:2) = P(1:j,:);
                    Cnt(1,1) = j;
                end
                if j == n-3%i最多等于n-1,故j最多等于n-3
                    Points(Cnt(1,1)+1:Cnt(1,1)+3,1:2) = P(n-2:n,:);
                    Cnt(1,1) = Cnt(1,1)+3;
                    tt =0;
                end
            end
            if ff(1,1) == 1
                P(1:Cnt(1,1),1:2) = Points(1:Cnt(1,1),1:2);
                PD_Cnt(1,1) = Cnt(1,1);
                if tt_j(1,1) == 1
                    tt =0;
                end
                break;
            end
        else
            for j=2:i-2
                Flag(1,1) = Judge_Intersect(P(i,1),P(i,2),P(1,1),P(1,2),P(j,1),P(j,2),P(j+1,1),P(j+1,2));%0为不相交，非零为相交
                if Flag(1,1) ~= 0
                    Points(1:j,1:2) = P(1:j,:);
                    Points(j+1,1:2) = CalculateLineCrossover(P(i,1),P(i,2),P(i+1,1),P(i+1,2),P(j,1),P(j,2),P(j+1,1),P(j+1,2));
                    %Points(j+2:j+1+n-i,1:2) = P(i+1:n,:);
                    Cnt(1,1) = j+1;
                    ff(1,1) = 1;
                    if j == n-2
                        tt_j(1,1) = 1;
                    end
                    break;
                else
                    Points(1:j,1:2) = P(1:j,:);
                    Cnt(1,1) = j;
                    if j == n-2%i最多等于n,故j最多等于n-2
                        Points(Cnt(1,1)+1:Cnt(1,1)+2,1:2) = P(n-1:n,:);
                        Cnt(1,1) = Cnt(1,1)+2;
                        tt =0;
                    end
                end
            end
            if ff(1,1) == 1
                P(1:Cnt(1,1),1:2) = Points(1:Cnt(1,1),1:2);
                PD_Cnt(1,1) = Cnt(1,1);
                if tt_j(1,1) == 1
                    tt =0;
                end
                break;
            end
        end
    end
    PrepNew = Preprocess(P(1:PD_Cnt(1,1),1:2),PD_Cnt(1,1));
    P(1:100,1:2) = PrepNew.Preprocessing;
    PD_Cnt(1,1) = PrepNew.Cnt;
    n(1,1) = PD_Cnt(1,1);
end