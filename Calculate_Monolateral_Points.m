function [Points_Monolateral,PM_Cnt,f_error] = Calculate_Monolateral_Points(Points,n,Monolateral,Monolateral_L,Monolateral_flag,Clock_Flag)
%���㵥�������ĵ�
%{
���룺
n:����ε�ĸ���(�������ͣ�double 1x1)
Points����Ҫ�ƶ�ĳ�ߵĶ���εı߽�㼯����ʽΪ�������еľ���(�������ͣ�double nx2)
Monolateral��Ҫ�ƶ��ıߵıߺ�(�������ͣ�double 1x1)
Monolateral_L��ĳ��Ҫ�ƶ��ľ���,���ܰ�ĳ���߸���û��(�������ͣ�double 1x1)
Monolateral_flag��ĳ��Ҫ�ƶ��ķ���(�������ͣ�double 1x1)
�����
PM_Cnt���������Ч��ĸ���(�������ͣ�double 1x1)
Points_Monolateral�������ƶ�ĳ�ߺ�Ķ���εı߽��(�������ͣ�double 100x2)
f_error�������־��Ϊ�����޴���Ϊ1Ϊ�д���(�������ͣ�double 1x1)
%}
Points_Monolateral = zeros(100,2);
PM_Cnt = zeros(1,1);

NEdgevectorList = zeros(n,2);
NEdgevectorList(1:n,1:2) = DPList(Points(1:n,1:2),n);
NEdgevectorList(1:n,1:2) = NormalizeDPList(NEdgevectorList(1:n,1:2),n);%��λ����
Sina = zeros(1,n);
Sina(1,1:n) = CalculateSina(NEdgevectorList(1:n,1:2),n);
f_error = zeros(1,1);

if Monolateral > n || Monolateral < 1
    f_error(1,1) = 1;
end
if eq(f_error(1,1),1)
    Points_Monolateral(1:n,1:2) = zeros(n,2);
else
    switch Monolateral_flag
        case 0%����
            if Monolateral == 1
                Points(1,1:2) = Points(1,:)-NEdgevectorList(n,:)*Monolateral_L/Sina(1,1);
                Points(2,1:2) = NEdgevectorList(2,:)*Monolateral_L/Sina(1,2) + Points(2,1:2);
            elseif Monolateral < n
                Points(Monolateral,1:2) = Points(Monolateral,1:2)-NEdgevectorList(Monolateral-1,1:2)*Monolateral_L/Sina(1,Monolateral);
                Points(Monolateral+1,1:2) = Points(Monolateral+1,1:2)+NEdgevectorList(Monolateral+1,1:2)*Monolateral_L/Sina(1,Monolateral+1);
            else
                Points(Monolateral,1:2) = Points(Monolateral,1:2)-NEdgevectorList(Monolateral-1,1:2)*Monolateral_L/Sina(1,Monolateral);
                Points(1,1:2) = Points(1,1:2)+NEdgevectorList(1,1:2)*Monolateral_L/Sina(1,1);
            end
        case 1%����
            if Monolateral == 1
                Points(1,1:2) = Points(1,1:2)+NEdgevectorList(n,1:2)*Monolateral_L/Sina(1,1);
                Points(2,1:2) = Points(2,1:2)-NEdgevectorList(2,1:2)*Monolateral_L/Sina(1,2);
            elseif Monolateral < n
                Points(Monolateral,1:2) = Points(Monolateral,1:2) + NEdgevectorList(Monolateral-1,1:2)*Monolateral_L/Sina(1,Monolateral);
                Points(Monolateral+1,1:2) = Points(Monolateral+1,1:2) - NEdgevectorList(Monolateral+1,1:2)*Monolateral_L/Sina(1,Monolateral+1);
            else
                Points(Monolateral,1:2) = Points(Monolateral,1:2) + NEdgevectorList(Monolateral-1,1:2)*Monolateral_L/Sina(1,Monolateral);
                Points(1,1:2) = Points(1,1:2) - NEdgevectorList(1,1:2)*Monolateral_L/Sina(1,1);
            end
        otherwise
            f_error(1,1) = 1;
            %warning('�����ƽ�������־���Ǽ򵥵�0��1');
    end
    PointLast = zeros(100,2);
    PL_Cnt = zeros(1,1);
    [PointLast(1:100,1:2),PL_Cnt(1,1)] = Calculate_Effective_Point(Points(1:n,1:2),n);%ȥ����Ч��
    if eq(Clock_Flag,0)
        PM_Cnt(1,1) = PL_Cnt(1,1);
        Points_Monolateral(1:PM_Cnt(1,1),1:2) = PointLast(1:PL_Cnt(1,1),1:2);%�ѽ�����˳ʱ���
    else
        PM_Cnt(1,1) = PL_Cnt(1,1);
        Points_Monolateral(1:PM_Cnt(1,1),1:2) = flipud(PointLast(1:PL_Cnt(1,1),1:2));%�ѽ�����˳ʱ���
    end
end
