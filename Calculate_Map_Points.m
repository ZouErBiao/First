function [PointLast,PL_Cnt,f_error] = Calculate_Map_Points(Point,P_Cnt,L,flag,Theita,Clock_Flag)
%{
���ã��Զ���ν�����������������
���룺
P_Cnt:Ϊ�㼯��ĸ���(�������ͣ�double 1x1)
Point:Ϊ��ʼ�����꼯(�������ͣ�double P_Cntx1)
L:Ϊ���ŵĿ��(�������ͣ�double 1x1)
flag: = 0��С��flag = 1,����(�������ͣ�double 1x1)
Theita:ΪС�Ƕȵ�����(�������ͣ�double 1x1)
Clock_Flag:ԭ����㼯��ʱ�뷽��δ��ת����˳ʱ��ǰ��
0-��ʱ��
1-˳ʱ��
�����
PL_Cnt:����㼯��ĸ���(�������ͣ�double 1x1)
PointLast�������ĵ㼯(�������ͣ�double PL_Cntx1)
f_error��0��������1�����ִ���(�������ͣ�double 1x1)
%}
n = zeros(1,1);
n(1,1) = P_Cnt;
Sina = zeros(1,n(1,1));
EList = zeros(n(1,1),2);
NEdgevectorList = zeros(n(1,1),2);
EList(1:n(1,1),1:2) = DPList(Point(1:n(1,1),1:2),n(1,1));
NEdgevectorList(1:n(1,1),1:2) = NormalizeDPList(EList(1:n(1,1),1:2),n(1,1));%��λ����
Sina(1,1:n(1,1)) = CalculateSina(NEdgevectorList(1:n(1,1),1:2),n(1,1));

P = zeros(100,2);
PP_Cnt = zeros(1,1);
PointLast = zeros(100,2);
PL_Cnt = zeros(1,1);
t = zeros(1,1);
Area = zeros(1,1);
Area_Limit = 20;%������Ķ���������СֵΪĳһ���������L��Ӧ�����������Area_Limit������L-0.5�׶�Ӧ��������ĵ�

f_error = zeros(1,1);
%%
switch flag %flag: = 0��С��flag = 1,����
    case 0
       t(1,1) = 1;
       while t(1,1)
           for i = 2:n(1,1)
               P(i,1:2) = Point(i,1:2) + (NEdgevectorList(i,1:2) - NEdgevectorList(i-1,1:2)) * L / Sina(1,i);
           end
           P(1,1:2) = Point(1,1:2) + (NEdgevectorList(1,1:2) - NEdgevectorList(n(1,1),1:2)) * L / Sina(1,1);
           
           Prep = Preprocess(P(1:n(1,1),1:2),n(1,1));
           P(1:100,1:2) = zeros(100,2);
           P(1:100,1:2) = Prep.Preprocessing(1:100,1:2);
           PP_Cnt(1,1) = Prep.Cnt(1,1);
           [PointLast(1:100,1:2),PL_Cnt(1,1)] = Calculate_Effective_Point(P(1:PP_Cnt(1,1),1:2),PP_Cnt(1,1));
           Area(1,1) = Calculate_Area(PointLast(1:PL_Cnt(1,1),1:2),PL_Cnt(1,1));
           %%
           %�˴�ֻ�ܽ��L����ķ�ת���
           if Area(1,1) < Area_Limit
               L = L - 0.5;
           else
               t(1,1) = 0;
           end
       end
        if eq(Clock_Flag,1)
            PointLast(1:PL_Cnt(1,1),1:2) = flipud(PointLast(1:PL_Cnt(1,1),1:2));%ת�������ʼ����ʱ��ʱ��˳��һ��
        end
    case 1
        [PointLast(1:100,1:2),PL_Cnt(1,1)]  = CalculateNewPoint(Point(1:P_Cnt,1:2),P_Cnt,L,Theita);
        if eq(Clock_Flag,0)
           PointLast(1:PL_Cnt(1,1),1:2) = flipud(PointLast(1:PL_Cnt(1,1),1:2));%%ת�����������ʱ��ʱ��˳��һ��
       end
    otherwise
        f_error(1,1) = 1;
end