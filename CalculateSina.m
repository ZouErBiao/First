function Sina = CalculateSina(NEdgevectorList,n)
%��������нǵ�sinֵ�����õ��ǵ�λ�����Ĳ�ˡ�nΪNEdgevectorList������
Sina = ones(1,n);
for i = 2:n
    Sina(1,i) = NEdgevectorList(i,1) * NEdgevectorList(i-1,2) - NEdgevectorList(i,2) * NEdgevectorList(i-1,1);
end
Sina(1,1) = NEdgevectorList(1,1) * NEdgevectorList(n,2) - NEdgevectorList(1,2) * NEdgevectorList(n,1);