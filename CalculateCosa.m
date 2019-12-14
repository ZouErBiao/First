function Cosa = CalculateCosa(NEdgevectorList,n)
Cosa = zeros(1,n);
for i = 2:n,
    Cosa(i) = NEdgevectorList(i,1)*NEdgevectorList(i-1,1) + NEdgevectorList(i,2)*NEdgevectorList(i-1,2);
end;
Cosa(1) = NEdgevectorList(1,1)*NEdgevectorList(n,1) + NEdgevectorList(1,2)*NEdgevectorList(n,2);