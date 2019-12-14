function [ppp,p_Cnt] = CalculateIntersection(PolygonList,PL_Cnt,IntersectionPointList,IP_Cnt)
%�������
%{
���룺
PolygonList��������㼯����ʽΪ��PL_Cnt����7
PL_Cnt��PolygonList�ĵ����
IntersectionPointList�������ĵ㼯����ʽΪIP_Cnt����7
IP_Cnt��IntersectionPointList�ĵ�ĸ���
�����
ppp���ϲ���ĵ㼯
%}
ppp = zeros(100,7);
p_Cnt = zeros(1,1);

if IP_Cnt == 0
    ppp(1:PL_Cnt,1:7) = PolygonList(1:PL_Cnt,1:7);
    p_Cnt(1,1) = PL_Cnt;
else
    Count = zeros(1,1);
    for i=1:PL_Cnt
        mc = zeros(1,5);
        m0 = find(IntersectionPointList(:,6)==i);
        m1 = find(IntersectionPointList(:,7)==i);%�ҵ����������ڱߵ���ʼ���㣬������
        
        [mc(1,1),mc(1,2)] =size(m1);
        [mc(1,3),mc(1,2)] =size(m0);
        if mc(1,1) == 0 && mc(1,3) ==0
            Count(1,1) = Count(1,1) + 1;
            ppp(Count(1,1),1:7) = PolygonList(i,1:7);
        else
            if mc(1,3) ==0
                mm = zeros(mc(1,1),1);
                mm(1:mc(1,1),1) = m1(1:mc(1,1),1);
                mc(1,5) = mc(1,1);
            else
                mm = zeros(mc(1,1)+mc(1,3),1);
                mM = zeros(mc(1,1)+mc(1,3),1);
                mm(1:mc(1,3),1) = m0(1:mc(1,3),1);
                mc(1,5) = mc(1,3);
                for j=1:mc(1,1),
                    a = find(mm(1:mc(1,5),1) < m1(j,1));
                    [mc(1,4),mc(1,2)]=size(a);
                    if mc(1,4)>0
                        mM(1:mc(1,4),1) = mm(1:mc(1,4),1);
                        mM(mc(1,4)+1,1) = m1(j,1);
                        mM(mc(1,4)+2:mc(1,5)+1,1) = mm(mc(1,4)+1:mc(1,5),:);
                        mc(1,5) = mc(1,5)+1;
                        mm(1:mc(1,5),1) =  mM(1:mc(1,5),1);
                    else
                        mM(1,1) = m1(j,1);
                        mM(2:mc(1,5)+1,1) = mm(1:mc(1,5),:);
                        mc(1,5) = mc(1,5)+1;
                        mm(1:mc(1,5),1) =  mM(1:mc(1,5),1);%�ڿ�ͷ������һ��ֵ
                    end
                end%m0Ϊ��iΪ��ʼ��ı����м�������
            end
            cc = ones(mc(1,5),2);
            dd = zeros(mc(1,5),2);
            for tt=1:mc(1,5),
                cc(tt,:)=[(IntersectionPointList(mm(tt,1),4)-PolygonList(i,4))*(IntersectionPointList(mm(tt,1),4)-PolygonList(i,4))+...
                    (IntersectionPointList(mm(tt,1),5)-PolygonList(i,5))*(IntersectionPointList(mm(tt,1),5)-PolygonList(i,5)) mm(tt,1)];
            end
            dd(1:mc(1,5),1:2)=sortrows(cc,1);%�Ծ���cc���а���һ����������
            ppp(Count(1,1)+1,:) = PolygonList(i,:);
            Count(1,1) = Count(1,1) + 1;
            ppp((Count(1,1)+1):(Count(1,1)+mc(1,5)),:) = IntersectionPointList(dd(:,2),:);
            Count(1,1) = Count(1,1) + mc(1,5);
        end
        p_Cnt(1,1) = Count(1,1);
    end
end