function Prep = Preprocess(Point,P_Cnt)
%���������ݽ���Ԥ�����ų��غϺ�����������ͬһ��ֱ���ϵ����
%{
���룺
%PointΪ����ı߽��
P_Cnt:�߽��ĸ���
�����
PrepΪ����ȥ�غ�ȥ��������������ĵ㼯�Ľṹ�壬��ʽΪ50����2
Prep.Preprocessing:��ʽΪ50����2
Prep.Cnt:��Ч��ĸ���
%}
%%
Prep.Preprocessing = zeros(100,2);
Prep.Cnt = zeros(1,1);

P_M = zeros(P_Cnt,3);
Count = zeros(1,1);
P_M(1:P_Cnt,1:2) = Point(1:P_Cnt,1:2);
%P_M�ĵ������Ǳ�־λ��Ϊ1�Ļ��������ɾ��
Eps = zeros(1,1);
Eps(1,1) = min([P_M(2,1)*0.005 P_M(2,2)*0.005]);%������Ҫ���ǧ��֮��
if all(abs(P_M(1,:)-P_M(2,:))<=Eps(1,1)) == 1
    P_M(2,3) = 1;%Ϊ��ռλ���ظ��ĵط��滻Ϊ����ֵ���滻ֵҪ������Ҫ�����ݲɼ����ظ����ɼ���ǡ�����ֵ��ȵĸ��ʼ��ͣ�������ֵ���ȡ�ؿ���ڲ�һ�㣩
    Count(1,1) = Count(1,1)+1;
end
for i=3:P_Cnt
    for j=1:i-1
        Eps(1,1) = min([P_M(i,1)*0.005 P_M(i,2)*0.005]);%������Ҫ���ǧ��֮��
        if all(abs(P_M(j,:)-P_M(i,:)) <= Eps(1,1)) == 1 
            P_M(i,3) = 1;
            Count(1,1) = Count(1,1)+1;
            break;
        end
    end
end
%%
%�������ظ��ĵ�
Point_map = zeros(P_Cnt-Count(1,1),2);
Cnt = zeros(1,1);%��һλ�����±����

for i =1:P_Cnt
    if eq(P_M(i,3),0)
        Cnt(1,1) = Cnt(1,1)+1;
        Point_map(Cnt(1,1),1:2) = P_M(i,1:2);
    end
end
%���ϴ������˵���ظ�����
%%
%%���´���������������ͬһ��ֱ���ϵ�����
NEdgevectorList = zeros(Cnt(1,1),2);
NEdgevectorList(1:Cnt(1,1),1:2) = DPList(Point_map(1:Cnt(1,1),1:2),Cnt(1,1));
NEdgevectorList(1:Cnt(1,1),1:2) = NormalizeDPList(NEdgevectorList(1:Cnt(1,1),1:2),Cnt(1,1));%���ߵĵ�λ����

IndexPrepro = zeros(Cnt(1,1),1);%��ǰ�浥λ������ȵĵ�ĵ�ŵĴ洢,������
Index_Cnt = zeros(1,1);
if eq(NEdgevectorList(1,1),NEdgevectorList(Cnt(1,1),1)) && eq(NEdgevectorList(1,2),NEdgevectorList(Cnt(1,1),2))
    IndexPrepro(1,1) = 1;%��ǰ�浥λ������ȵĵ��
else
    Index_Cnt(1,1) = Index_Cnt(1,1)+1;
    IndexPrepro(1,1) = 0;
end
for i=2:Cnt(1,1)
    if eq(NEdgevectorList(i,1),NEdgevectorList(i-1,1)) && eq(NEdgevectorList(i,2),NEdgevectorList(i-1,2))
        IndexPrepro(i,1) = i;%��ǰ�浥λ������ȵĵ� ��
    else
        Index_Cnt(1,1) = Index_Cnt(1,1)+1;
        IndexPrepro(i,1) = 0;
    end
end

Point_map1 = zeros(Index_Cnt(1,1),2);
m = zeros(1,1);
for i =1:Cnt(1,1)
    if eq(IndexPrepro(i,1),0)
        m(1,1) = m(1,1)+1;
        Point_map1(m(1,1),1:2) = Point_map(i,1:2);
    end
end
Prep.Preprocessing(1:Index_Cnt(1,1),1:2) =  Point_map1(1:Index_Cnt(1,1),1:2);
Prep.Cnt(1,1) = Index_Cnt(1,1);