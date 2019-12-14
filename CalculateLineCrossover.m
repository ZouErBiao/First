function LineCrossover = CalculateLineCrossover(x1,y1,x2,y2,x3,y3,x4,y4)
%���������ཻ�߶�֮��Ľ���
LineCrossover = [0 0];
Middle = zeros(1,4);
if (x1~=x2 && y1==y2)&&(y2 == y3 && x3~=x4 && y3==y4)%�����߶ζ���x��ƽ��
    Middle = sort([x1 x2 x3 x4]);
    LineCrossover(1,1) = Middle(1,3);
    LineCrossover(1,2) = y1;
elseif (x1~=x2 && y1==y2) && (x3==x4 && y3~=y4 )%��һ����x��ƽ�У��ڶ�����y��ƽ��
    LineCrossover(1,1) = x3;
    LineCrossover(1,2) = y1;
elseif (x1~=x2 && y1==y2) && (x3~=x4 && y3~=y4)%��һ����x��ƽ�У��ڶ�������������ƽ��
    LineCrossover(1,1) = (y1-y3)*(x4-x3)/(y4-y3)+x3;
    LineCrossover(1,2) = y1;
elseif (x1 == x2 && y1~=y2) && (x3~=x4 && y3==y4)%��һ��ƽ����y�ᣬ�ڶ���ƽ����x��
    LineCrossover(1,1) = x1;
    LineCrossover(1,2) = y3;
elseif (x1 == x2 && y1~=y2) && (x1 == x3 && x3 == x4 && y3~=y4)%��һ��ƽ����y�ᣬ�ڶ���ƽ����y��
    LineCrossover(1,1) = x1;
    Middle = sort([y1 y2 y3 y4]);
    LineCrossover(1,2) = Middle(1,3);
elseif (x1 == x2 && y1~=y2) && (x1~=x3 && y3~=y4)%��һ��ƽ����y�ᣬ�ڶ��������κ���ƽ��
    LineCrossover(1,1) = x1;
    LineCrossover(1,2) = (y4-y3)*(x1-x3)/(x4-x3)+y3;
elseif (x1~=x2 && y1~=y2) && (x3~=x4 && y3==y4)%��һ�������κ���ƽ�У��ڶ�����x��ƽ��
    LineCrossover(1,1) = (y3-y1)*(x2-x1)/(y2-y1)+x1;
    LineCrossover(1,2) = y3;
elseif (x1~=x2 && y1~=y2) && (x3 == x4 && y3~=y4)
    LineCrossover(1,1) = x3;
    LineCrossover(1,2) = (y2-y1)*(x3-x1)/(x2-x1)+y1;
else
    a = (y4-y3)/(x4-x3);
    b= (y2-y1)/(x2-x1);
    if a ~= b %���߶���б�ʲ���ͬ
        LineCrossover(1,1) = (y1-y3 + a*x3-b*x1)/(a-b);
        LineCrossover(1,2) = (a*b*x1-a*b*x3+b*y3-a*y1)/(b-a);
    else%���߶�б����ͬ
        Middle = sort([x1 x2 x3 x4]);
        LineCrossover(1,1) = Middle(1,3);
        LineCrossover(1,2) = b*(Middle(1,3)-x1) + y1;
    end
end