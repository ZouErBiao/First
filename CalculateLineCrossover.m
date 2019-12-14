function LineCrossover = CalculateLineCrossover(x1,y1,x2,y2,x3,y3,x4,y4)
%计算两条相交线段之间的交点
LineCrossover = [0 0];
Middle = zeros(1,4);
if (x1~=x2 && y1==y2)&&(y2 == y3 && x3~=x4 && y3==y4)%两条线段都与x轴平行
    Middle = sort([x1 x2 x3 x4]);
    LineCrossover(1,1) = Middle(1,3);
    LineCrossover(1,2) = y1;
elseif (x1~=x2 && y1==y2) && (x3==x4 && y3~=y4 )%第一条鱼x轴平行，第二条与y轴平行
    LineCrossover(1,1) = x3;
    LineCrossover(1,2) = y1;
elseif (x1~=x2 && y1==y2) && (x3~=x4 && y3~=y4)%第一条鱼x轴平行，第二条不与坐标轴平行
    LineCrossover(1,1) = (y1-y3)*(x4-x3)/(y4-y3)+x3;
    LineCrossover(1,2) = y1;
elseif (x1 == x2 && y1~=y2) && (x3~=x4 && y3==y4)%第一条平行于y轴，第二条平行于x轴
    LineCrossover(1,1) = x1;
    LineCrossover(1,2) = y3;
elseif (x1 == x2 && y1~=y2) && (x1 == x3 && x3 == x4 && y3~=y4)%第一条平行于y轴，第二条平行于y轴
    LineCrossover(1,1) = x1;
    Middle = sort([y1 y2 y3 y4]);
    LineCrossover(1,2) = Middle(1,3);
elseif (x1 == x2 && y1~=y2) && (x1~=x3 && y3~=y4)%第一条平行于y轴，第二条不与任何轴平行
    LineCrossover(1,1) = x1;
    LineCrossover(1,2) = (y4-y3)*(x1-x3)/(x4-x3)+y3;
elseif (x1~=x2 && y1~=y2) && (x3~=x4 && y3==y4)%第一条不与任何轴平行，第二条与x轴平行
    LineCrossover(1,1) = (y3-y1)*(x2-x1)/(y2-y1)+x1;
    LineCrossover(1,2) = y3;
elseif (x1~=x2 && y1~=y2) && (x3 == x4 && y3~=y4)
    LineCrossover(1,1) = x3;
    LineCrossover(1,2) = (y2-y1)*(x3-x1)/(x2-x1)+y1;
else
    a = (y4-y3)/(x4-x3);
    b= (y2-y1)/(x2-x1);
    if a ~= b %两线段线斜率不相同
        LineCrossover(1,1) = (y1-y3 + a*x3-b*x1)/(a-b);
        LineCrossover(1,2) = (a*b*x1-a*b*x3+b*y3-a*y1)/(b-a);
    else%两线段斜率相同
        Middle = sort([x1 x2 x3 x4]);
        LineCrossover(1,1) = Middle(1,3);
        LineCrossover(1,2) = b*(Middle(1,3)-x1) + y1;
    end
end