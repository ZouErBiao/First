function NEdgevectorList = NormalizeDPList(EdgevectorList,n)
%��λ����������
%nΪ����
NEdgevectorList = zeros(n,2);
for i = 1:n,
    NEdgevectorList(i,:) = EdgevectorList(i,:)/sqrt(EdgevectorList(i,1)*EdgevectorList(i,1) + EdgevectorList(i,2)*EdgevectorList(i,2));
end;
