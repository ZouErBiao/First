function [P,P_Cnt] = Reduce_Angle(Point,n,L,Sina,Cosa,NEdgevectorList,Theita)
%对点Point进行去锐角化
%{
输入：
Point:需要锐角化的边界点集，格式为n乘以2
n：Point中点的个数
L：外扩的距离单位米
Sina：个顶点出的角的sin值
Cosa：个顶点出的角的cosa值
NEdgevectorList:各边的单位向量
Theita：锐角临界值
输出：
P：经去锐角化的点集，格式为P_Cnt乘以2
P_Cnt:经处理后的点集中点的个数
%}
P = zeros(100,2);
P_Cnt = zeros(1,1);

k = 0;
p0 = zeros(1,2);
a1 = zeros(1,1); 
a2 = zeros(1,1); 
if abs(Sina(1,1)) > sin(Theita*3.1415926/180)%0.3420
    P(1,1:2) = Point(1,1:2) - (NEdgevectorList(1,1:2) - NEdgevectorList(n,1:2)) * L / Sina(1,1);
    P_Cnt(1,1) = P_Cnt(1,1) + 1;
elseif abs(Sina(1,1)) <= sin(Theita*3.1415926/180)
    if Sina(1,1) > 0 && Cosa(1,1) < 0
        k= k+1;
        p0(1,1:2) = -NEdgevectorList(1,1:2) + NEdgevectorList(n,1:2);
        a1(1,1) = p0(1,1) / sqrt(p0(1,1)*p0(1,1)+p0(1,2)*p0(1,2));
        a2(1,1) = p0(1,2) / sqrt(p0(1,1)*p0(1,1)+p0(1,2)*p0(1,2));
        P(1+2*k-2,1) = Point(1,1) + L*(a1(1,1)*sqrt((1 + Cosa(1,1))/2) - a2(1,1)*sqrt((1 - Cosa(1,1))/2));
        P(1+2*k-2,2) = Point(1,2) + L*(a2(1,1)*sqrt((1 + Cosa(1,1))/2) + a1(1,1)*sqrt((1-Cosa(1,1))/2));
        
        P(1+2*k-1,1:2) = Point(1,1:2) + [a1(1,1) a2(1,1)]* L;
         
        P(1+2*k,1) = Point(1,1) + L*(a1(1,1)*sqrt((1 + Cosa(1,1))/2) + a2(1,1)*sqrt((1-Cosa(1,1))/2));
        P(1+2*k,2) = Point(1,2) + L*(a2(1,1)*sqrt((1 + Cosa(1,1))/2) - a1(1,1)*sqrt((1-Cosa(1,1))/2));
        P_Cnt(1,1) = P_Cnt(1,1) + 3;
    else
         P(1,1:2) = Point(1,1:2) - (NEdgevectorList(1,1:2) - NEdgevectorList(n,1:2)) * L / Sina(1,1);
         P_Cnt(1,1) = P_Cnt(1,1) + 1;
    end
end
for i=2:n
    if abs(Sina(1,i)) > sin(Theita*3.1415926/180) 
        P(i+2*k,:) = Point(i,:) - (NEdgevectorList(i,:) - NEdgevectorList(i-1,:)) * L / Sina(1,i);
        P_Cnt(1,1) = P_Cnt(1,1) + 1;
    elseif abs(Sina(1,i)) <= sin(Theita*3.1415926/180)
        if Sina(1,i) > 0 && Cosa(1,i) < 0
            k = k+1;
            p0(1,1:2) = -NEdgevectorList(i,1:2) + NEdgevectorList(i-1,1:2);
            a1(1,1) = p0(1,1) / sqrt(p0(1,1)*p0(1,1)+p0(1,2)*p0(1,2));
            a2(1,1) = p0(1,2) / sqrt(p0(1,1)*p0(1,1)+p0(1,2)*p0(1,2));
            P(i+2*k-2,1) = Point(i,1) + L*(a1(1,1)*sqrt((1 + Cosa(1,i))/2) - a2(1,1)*sqrt((1 - Cosa(1,i))/2));
            P(i+2*k-2,2) = Point(i,2) + L*(a2(1,1)*sqrt((1 + Cosa(1,i))/2) + a1(1,1)*sqrt((1 - Cosa(1,i))/2));
            
            P(i+2*k-1,:) = Point(i,:) + [a1(1,1) a2(1,1)] * L;
            
            P(i+2*k,1) = Point(i,1) + L*(a1(1,1)*sqrt((1 + Cosa(1,i))/2) + a2(1,1)*sqrt((1 - Cosa(1,i))/2));
            P(i+2*k,2) = Point(i,2) + L*(a2(1,1)*sqrt((1 + Cosa(1,i))/2) - a1(1,1)*sqrt((1 - Cosa(1,i))/2));  
           P_Cnt(1,1) = P_Cnt(1,1) + 3;
        else
            P(i+2*k,1:2) = Point(i,1:2) - (NEdgevectorList(i,1:2) - NEdgevectorList(i-1,1:2)) * L / Sina(1,i);
            P_Cnt(1,1) = P_Cnt(1,1) + 1;
        end
    end
end