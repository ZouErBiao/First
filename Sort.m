function LPaiXu = Sort(L,Mm)
%��L���д�С��������,IndexΪ����ǰ�������˵���Ϣ��MmΪL��Ԫ�صĸ���
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