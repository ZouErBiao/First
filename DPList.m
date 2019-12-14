function EdgevectorList = DPList(Point,n)
%计算指定数组中两点之间的向量、n为行数
EdgevectorList= zeros(n,2);
for i = 1:n-1
    EdgevectorList(i,1:2) = [Point(i+1,1)-Point(i,1) Point(i+1,2)-Point(i,2)];
end
EdgevectorList(n,:) = [Point(1,1)-Point(n,1) Point(1,2)-Point(n,2)];