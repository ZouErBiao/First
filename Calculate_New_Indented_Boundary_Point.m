function [PP,PP_Cnt,PPP,PPP_Cnt] = Calculate_New_Indented_Boundary_Point(Point,P_Cnt)
%{
���룺
Point:������ĵ㼯����ʽΪP_Cnt����2�ľ���
P_Cnt:�������
�����
PP�����ߵĽ��㼯����ʽΪn����7�ľ���
PPP�����ߵĶ��㼯����ʽΪn����7�ľ���
%}
PP_Cnt = zeros(1,1);
PPP_Cnt = zeros(1,1);
PPP_Cnt(1,1) = P_Cnt;

Pointss = zeros(P_Cnt,2);
Pointss(1:P_Cnt,1:2) = flipud(Point(1:P_Cnt,1:2));%���ñ����ʱ��
Flag = zeros(1,1);
PPP = zeros(100,7);
%%�˴��Ѵ�����ĵ㼯������еľ���
for i=1:P_Cnt
    PPP(i,1) = i;%ԭ����ζ����ţ�1,2,3.......
    PPP(i,2:3) = [0 0];%�ڶ��зŸõ��Ƿ񱻷��ʱ��0Ϊû���ʣ�1�������ʣ�������Ϊ�Ƿ��ǽ����ǣ�1Ϊ�ǽ��㣬0Ϊ���ǽ���
    PPP(i,4:5) = Pointss(i,:);%��������
    PPP(i,6:7) = [0 0];%�����д�Ž����С��űߵ���㣬�����ִ�Ž���Ĵ���űߵ���㣬����Ϊ��
end
PP = zeros(50,7);%���ڼ�¼������Ϣ��8�о���
k = zeros(1,1);
%PPΪ���㼯
for i=3:P_Cnt
    if i < P_Cnt
        for j=1:i-2
            Flag(1,1) = Judge_Intersect(Pointss(i,1),Pointss(i,2),Pointss(i+1,1),Pointss(i+1,2),Pointss(j,1),Pointss(j,2),Pointss(j+1,1),Pointss(j+1,2));%0Ϊ���ཻ������Ϊ�ཻ
            if Flag(1,1) ~= 0
                k(1,1) = k(1,1) + 1;
                PP(k(1,1),1:3) = [0,0,1];%���λΪ�㣬���ʱ��λΪ0���Ƿ񽻵�λΪ1��
                PP(k(1,1),4:5)  = CalculateLineCrossover(Pointss(i,1),Pointss(i,2),Pointss(i+1,1),Pointss(i+1,2),Pointss(j,1),Pointss(j,2),Pointss(j+1,1),Pointss(j+1,2));
                PP(k(1,1),6:7) = [j,i];
            end
        end
    else
        for j=2:i-2
            Flag(1,1) = Judge_Intersect(Pointss(i,1),Pointss(i,2),Pointss(1,1),Pointss(1,2),Pointss(j,1),Pointss(j,2),Pointss(j+1,1),Pointss(j+1,2));%0Ϊ���ཻ������Ϊ�ཻ
            if Flag(1,1) ~= 0
                k(1,1) = k(1,1) + 1;
                PP(k(1,1),1:3) = [0,0,1];%���λΪ�㣬���ʱ��λΪ0���Ƿ񽻵�λΪ1��
                PP(k(1,1),4:5)  = CalculateLineCrossover(Pointss(i,1),Pointss(i,2),Pointss(1,1),Pointss(1,2),Pointss(j,1),Pointss(j,2),Pointss(j+1,1),Pointss(j+1,2));
                PP(k(1,1),6:7) = [j,i];
            end
        end
    end 
end
PP_Cnt(1,1) = k(1,1);