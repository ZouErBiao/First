function LPaiXu = Sort(L,Mm)
%对L进行从小到大排序,Index为排序前凹边两端点信息，Mm为L中元素的个数
LPaiXu = zeros(50,7);
for i =1:Mm,
    for j = i+1:Mm,
        if L(j,6) <= L(i,6)
            l = L(i,:);
            L(i,:) = L(j,:);
            L(j,:) = l;
        end
    end
end
LPaiXu(1:50,1:7) = L(1:50,1:7);