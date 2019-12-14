function Mianji = Calculate_Area(Pxy,n)
sum = 0;
Pxy = [Pxy;Pxy(1,:)];
for i = 1:n
    sum = sum + Pxy(i,1) * Pxy(i+1,2) - Pxy(i,2) * Pxy(i+1,1);
end
Mianji = abs(sum / 2.0);