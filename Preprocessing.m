function [PreprocessDataTwo,PD] = Preprocessing(Point,P_Cnt)
%原顶点和交点中和后的点（处理交点和顶点相同的情况）
PreprocessDataTwo = zeros(100,7);
PointNew = zeros(100,2);
PointNew(1:P_Cnt,1:7) = Point(1:P_Cnt,1:7);
PD = zeros(1,1);
Eps = zeros(1,1);
i=1;
n = zeros(1,3);
n(1,1) = P_Cnt;
tt=1;
t = zeros(1,2);
while tt==1
    i = i+1;
    if i > n(1,1)
        break;
    end
    if i <= n(1,1)
        Eps(1,1) = min([PointNew(i,4)*0.005 PointNew(i,5)*0.005]);
        if all(abs(PointNew(i-1,4:5)-PointNew(i,4:5))<Eps(1,1)) == 1
            tf = zeros(n(1,1),1);
            if PointNew(i-1,3) == 1
                tf(1:n(1,1),1) = ismember(PointNew(1:n(1,1),3:5),PointNew(i-1,3:5),'rows');
                m = find(tf(1:n(1,1),1) == 1);
                [t(1,1),t(1,2)] = size(m);
                PointNew(m,:) = [];
            elseif PointNew(i,3) == 1
                tf(1:n(1,1),1) = ismember(PointNew(1:n(1,1),3:5),PointNew(i,3:5),'rows');
                m = find(tf(1:n(1,1),1) == 1);
                [t(1,1),t(1,2)] = size(m);
                PointNew(m,:) = [];
            end
        end
    end
    n(1,1) = n(1,1) - t(1,1);
end
PreprocessDataTwo(1:n(1,1),1:7) = PointNew(1:n(1,1),1:7);
PD(1,1) = n(1,1);