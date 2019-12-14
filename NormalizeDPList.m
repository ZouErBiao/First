function NEdgevectorList = NormalizeDPList(EdgevectorList,n)
%单位化各边向量
%n为行数
NEdgevectorList = zeros(n,2);
for i = 1:n,
    NEdgevectorList(i,:) = EdgevectorList(i,:)/sqrt(EdgevectorList(i,1)*EdgevectorList(i,1) + EdgevectorList(i,2)*EdgevectorList(i,2));
end;
