function [YouXiao,YX_Cnt] = Calculate_Effective_Point(PointLast,N)
%{
%�Ծ���������ĵ㼯����ȥ��Ч������
���룺
PointLastΪ��������ĵ㼯��Ϊ�������еľ���,˳ʱ�����е�%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
�����
YouXiaoΪ���������ı�����������Ч���ĵ㼯��Ϊ�������еľ���
%}
YouXiao = zeros(100,2);
YX_Cnt = zeros(1,1);

PP = zeros(50,7);
PPP = zeros(100,7);
PP_Cnt = zeros(1,1);
PPP_Cnt = zeros(1,1);
[PP(1:50,1:7),PP_Cnt(1,1),PPP(1:100,1:7),PPP_Cnt(1,1)] =Calculate_New_Indented_Boundary_Point(PointLast(1:N,1:2),N);%PPPΪ�������á����д����ĵ����ж��㼯��~Ϊԭ���㼯���ú�ĵ㼯��PPΪ����Ľ��㼯����Ҳ���������������еľ���
PP(1:50,1:7) = Sort(PP(1:50,1:7),PP_Cnt(1,1));%�Խ������С��űߵ����������򣬷������ԭ���㼯

PolygonList = zeros(100,7);
n = zeros(1,1);
[PolygonList(1:100,1:7),n(1,1)] = CalculateIntersection(PPP(1:PPP_Cnt(1,1),1:7),PPP_Cnt(1,1),PP(1:PP_Cnt(1,1),1:7),PP_Cnt(1,1));%�кͽ���Ķ��㼯
%[PolygonList(1:100,1:7),n(1,1)] = Preprocessing(PolygonList(1:n(1,1),1:7),n(1,1));%ȥ�������ԭ������ͬ�ĵ�

newPolygonnum = zeros(1,1);%���и�󣬼򵥶���εĸ���
b = zeros(50,1);
C_Cnt = zeros(1,4);%�����±������

ccc = zeros(n(1,1),1);
newPolygonList = zeros(n(1,1),7);
i=1;
tt = ones(1,1);
newPolygonnum(1,1) = newPolygonnum(1,1) +1;
newPolygonListPP = zeros(n(1,1),7);

newPolygonListPP(i,:) = PolygonList(i,:);%ÿ���»��Ĵ洢����
C_Cnt(1,2) = 1;
PolygonList(1,2) = 1;

row = zeros(n(1,1),1);%���ڲ��ҽ���洢
m = zeros(1,4);
while tt(1,1) >= 1
    i=i+1;%%step4
    if i == n(1,1)+1
        i=1;
    end
        if PolygonList(i,3)==1 && (PolygonList(i,4) ~= newPolygonListPP(1,4) || PolygonList(i,5) ~= newPolygonListPP(1,5)) %�ж��Ƿ�Ϊ����
            C_Cnt(1,1) = C_Cnt(1,1) + 1;
            b(C_Cnt(1,1),1) = i;
            
            C_Cnt(1,2) = C_Cnt(1,2) + 1;
            newPolygonListPP(C_Cnt(1,2),1:7) = PolygonList(i,1:7);%%�Ա�˴����һ��
            
            row(1:n(1,1),1) = ismember(PolygonList(1:n(1,1),1:7),PolygonList(i,1:7),'rows');
            mm = find(row(1:n(1,1),1) == 1);
            [m(1,1),m(1,2)] = size(mm);
            if m(1,1)==1
                m(1,3) = PolygonList(i,7)+1;
                if m(1,3) > PPP_Cnt(1,1)%������һ�����m(1,3)���ܳ�����δ���뽻��ǰ�ĵ㼯�ĵ���
                    i = 0;
                else
                    for ii=1:n(1,1)
                        if eq(PolygonList(ii,1),m(1,3))
                            i = ii - 1;
                            break;
                        end
                    end
                    %m(1,4) = find(PolygonList(1:n(1,1),1)==m(1,3));
                    %i = m(1,4)-1;
                end
                
            else
                i = mm(2,1);
            end
        else%%Step6
            if PolygonList(i,4) ~= newPolygonListPP(1,4) || PolygonList(i,5) ~= newPolygonListPP(1,5) && PolygonList(i,2) == 0
                
                C_Cnt(1,2) = C_Cnt(1,2) + 1;
                newPolygonListPP(C_Cnt(1,2),:) = PolygonList(i,:);%%�Ա�˴����һ��
                PolygonList(i,2) = 1;
            else
                PolygonList(i,2)=1;
                
                C_Cnt(1,3) = C_Cnt(1,3) + 1;
                ccc(C_Cnt(1,3),1) = C_Cnt(1,2);%�洢ÿ�����Ķ�����
                
                newPolygonList(C_Cnt(1,4)+1:C_Cnt(1,4)+C_Cnt(1,2),1:7) = newPolygonListPP(1:C_Cnt(1,2),1:7);
                C_Cnt(1,4) = C_Cnt(1,4) + C_Cnt(1,2);
                
                newPolygonnum(1,1) = newPolygonnum(1,1) +1;%�ٴ�����һ���µľ�̬������ʽ�Ŀռ�
                newPolygonListPP = zeros(n(1,1),7);
                
                tttt=find(PolygonList(1:n(1,1),2)==0);%�ж��Ƿ��������
                ttt = zeros(1,2);
                [ttt(1,1),ttt(1,2)]=size(tttt);
                if ttt(1,1) == 0
                    break;
                end
                newPolygonListPP(1,:) = PolygonList(b(newPolygonnum(1,1)-1,1),:);%���¿�ʼһ����ѭ��
                PolygonList(b(newPolygonnum(1,1)-1,1),2) = 1;
                C_Cnt(1,2) = 1;
                i = b(newPolygonnum(1,1)-1,1);
            end 
        end
        tt(1,1) = tt(1,1)+1;
        if tt(1,1) >= 100+PP_Cnt(1,1)*3
            break;
            %error('�ڴ�����Ч��ʱ������ѭ����');
        end
end
%%
Aera = zeros(C_Cnt(1,3),3);
C_Aera = zeros(1,1);
FFLOG0 = zeros(1,1);
ct = zeros(1,1);
ind = zeros(1,2);
if C_Cnt(1,3)==1
    YouXiao(1:C_Cnt(1,4),1:2) = newPolygonList(1:C_Cnt(1,4),4:5);
    YX_Cnt(1,1) = C_Cnt(1,4);
else
    for i=1:C_Cnt(1,3)
        if i==1
            FFLOG0(1,1) = judgeClockWise(newPolygonList(1:ccc(i),4),newPolygonList(1:ccc(i),5),ccc(i));
            if FFLOG0(1,1) == 0
                YouXiao(1:ccc(i),1:2) = newPolygonList(1:ccc(i),4:5);
                C_Aera(1,1) = C_Aera(1,1) + 1;
                Aera(C_Aera(1,1),1:3) = [Calculate_Area(YouXiao(1:ccc(i),1:2),ccc(i)),ccc(i),i];
                %Mianji = [Mianji;[CalculateMianji(YouXiao,ccc(i)),ccc(i),i]];
            end
            %FFLOGzong = [FFLOGzong;FFLOG0];
        else
            ct(1,1) = sum(ccc(1:i-1));
            FFLOG0(1,1) = judgeClockWise(newPolygonList(ct(1,1)+1:ct(1,1)+ccc(i),4),newPolygonList(ct(1,1)+1:ct(1,1)+ccc(i),5),ccc(i));
            if FFLOG0(1,1)==0
                YouXiao(1:ccc(i),1:2) = newPolygonList(ct(1,1)+1:ct(1,1)+ccc(i),4:5);
                
                C_Aera(1,1) = C_Aera(1,1) + 1;
                Aera(C_Aera(1,1),1:3) = [Calculate_Area(YouXiao(1:ccc(i),1:2),ccc(i)),ccc(i),i];
                %Mianji = [Mianji;[CalculateMianji(YouXiao,ccc(i)),ccc(i),i]];
            end
        end
    end
    YouXiao(1:100,1:2) = zeros(100,2);
    [ind(1,1), ind(1,2)] = max(Aera(:,1)); %�ҵ���һ�����ֵ�����
    Aera(1,1:3) = Aera(ind(1,2),1:3); %��ʾ���ֵ���ڵ�һ�е�Ԫ�� 
    if Aera(1,3) == 1
        YouXiao(1:Aera(1,2),1:2) = newPolygonList(1:Aera(1,2),4:5);
        YX_Cnt(1,1) = Aera(1,2);
    else
        ct(1,1) = sum(ccc(1:Aera(1,3)-1,1));
        YouXiao(1:Aera(1,2),1:2) = newPolygonList(ct(1,1)+1:ct(1,1)+Aera(1,2),4:5);
        YX_Cnt(1,1) = Aera(1,2);
    end
end
