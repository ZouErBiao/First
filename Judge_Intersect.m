function Flag = Judge_Intersect(x1,y1,x2,y2,x3,y3,x4,y4)
%�˺����������ж������߶��Ƿ��ཻ
%�����0Ϊ���ཻ������Ϊ�ཻ
A = zeros(1,2);
B = zeros(1,2);
C = zeros(1,2);
D = zeros(1,2);

Flag = zeros(1,1);
abac = zeros(1,1);
abad = zeros(1,1);
cdcb = zeros(1,1);
cdca = zeros(1,1);

ABXCD = zeros(1,1);
BCXCD = zeros(1,1);

abac(1,1) = Mult([x2-x1 y2-y1],[x3-x1 y3-y1]);
abad(1,1) = Mult([x2-x1 y2-y1],[x4-x1 y4-y1]);
cdcb(1,1) = Mult([x4-x3 y4-y3],[x2-x3 y2-y3]);
cdca(1,1) = Mult([x4-x3 y4-y3],[x1-x3 y1-y3]);
if abac(1,1)*abad(1,1) < 0 && cdcb(1,1)*cdca(1,1) < 0
    Flag(1,1) = 1;%�ཻ,�޵����߶���
elseif (abac(1,1) == 0||abad(1,1) == 0) && cdcb(1,1)*cdca(1,1) < 0
    Flag(1,1) = 2;
elseif (cdcb(1,1) == 0||cdca(1,1) == 0) && abac(1,1)*abad(1,1) < 0
    Flag(1,1) = 2;%��һ���˵����߶���
else 
    if x1 < x2
        A(1,1:2) = [x1 y1];
        B(1,1:2) = [x2 y2];
    elseif x1 > x2
        A(1,1:2) = [x2 y2];
        B(1,1:2) = [x1 y1];
    else
        if y1 > y2
            A(1,1:2) = [x2 y2];
            B(1,1:2) = [x1 y1];
        elseif y1 < y2
            A(1,1:2) = [x1 y1];
            B(1,1:2) = [x2 y2];
        else
            %warning('���������߶��Ƿ��ཻʱ��ͬһ�߶�AB������ͬ������������');
            A(1,1:2) = [x1 y1];
            B(1,1:2) = [x2 y2];
        end
    end
    if x3 < x4
        C(1,1:2) = [x3 y3];
        D(1,1:2) = [x4 y4];
    elseif x3 > x4
        C(1,1:2) = [x4 y4];
        D(1,1:2) = [x3 y3];
    else
        if y3 > y4
            C(1,1:2) = [x4 y4];
            D(1,1:2) = [x3 y3];
        elseif y3 < y4
            C(1,1:2) = [x3 y3];
            D(1,1:2) = [x4 y4];
        else
            %warning('���������߶��Ƿ��ཻʱ��ͬһ�߶�CD������ͬ������������');
            C(1,1:2) = [x3 y3];
            D(1,1:2) = [x4 y4];
        end
    end
    ABXCD(1,1) = Mult([B(1,1)-A(1,1) B(1,2)-A(1,2)],[D(1,1)-C(1,1) D(1,2)-C(1,2)]);
    if ABXCD(1,1) == 0%˵�����߶�ƽ��
        BCXCD(1,1) = Mult([C(1,1)-B(1,1) C(1,2)-B(1,2)],[D(1,1)-C(1,1) D(1,2)-C(1,2)]);
        if BCXCD(1,1) == 0%˵�����߶ι���
            if C(1,1)-A(1,1) > 0 && B(1,1)-C(1,1) >= 0
                Flag(1,1) = 3;
            elseif (C(1,1) - A(1,1) < 0) && D(1,1)-A(1,1) >= 0
                Flag(1,1) = 3;
            elseif (C(1,1) - A(1,1) == 0) && (B(1,1) - A(1,1) ~= 0)
                Flag(1,1) = 3;
            elseif (C(1,1) - A(1,1) == 0) && (B(1,1) - A(1,1) == 0)
                if B(1,2)-C(1,2) < 0 || D(1,2)-A(1,2) < 0
                    Flag(1,1) = 0;
                else
                    Flag(1,1) = 3;
                end
            else
                Flag(1,1) = 0;
            end
        else
            Flag(1,1) = 0;
        end
    else
        Flag(1,1) = 0;
    end
end