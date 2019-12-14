%% �жϵؿ���˳ʱ�뻹����ʱ��
function CWAFlag = judgeClockWise(lat_in,lon_in,len)
%���:˳ʱ��Ϊ1����ʱ��Ϊ0
%�㷨˵����
% ��ĳһ�������cross product = ((xi - xi-1),(yi - yi-1)) x ((xi+1 - xi),(yi+1 - yi)) = (xi - xi-1) * (yi+1 - yi) - (yi - yi-1) * (xi+1 - xi)
% �����ʽ��ֵΪ������ʱ�룻Ϊ������˳ʱ��
% ������һ��ļ򵥶���Σ�������ڶ���ε�ÿһ�����������ֵ�������ֵ�Ƚ϶࣬����ʱ�룻��ֵ�϶���Ϊ˳ʱ�롣
% lat_in:x,lon_in:y
%%
if 0
    figure
    plot(lat_in(1:len),lon_in(1:len),'*-');
    hold on
    plot(lat_in(1),lon_in(1),'r*','lineWidth',8);
    plot(lat_in(2),lon_in(2),'*','lineWidth',8);
end
%% �ж�
CWAFlag = 0;
if len < 3
   return; 
end
%% ��˱�������
count = 0;
z = 0;
for i=1:len
    % �ҵ���������
    j = mod(i+1,len+1);
    if j == 0
        j = 1;%len;
    end
    k = mod(i+2,len+1);
    if (i+2) > (len+1)
        k = 2;
    elseif k == 0
        k = 1;%len;
    end

    % ������
    z = (lat_in(j) - lat_in(i)) * (lon_in(k) - lon_in(j));
    z = z - (lon_in(j) - lon_in(i)) * (lat_in(k) - lat_in(j));
    if z < 0
        count = count - 1;
    elseif z > 0
        count = count + 1;
    end
end
%
if count >= 0
    CWAFlag = 0;%��ʱ��
else
    CWAFlag = 1;%˳ʱ��
end
%% Green �㷨
d = 0;
for i=1:len-1
    %d += - 0.5 * ( y[i + 1] + y[i]) * (x[i + 1] - x[i]);
    d = d - 0.5 * (lon_in(i + 1) + lon_in(i)) * (lat_in(i + 1) - lat_in(i));
end
d = d - 0.5 * (lon_in(1) + lon_in(len)) * (lat_in(1) - lat_in(len));
%
if d >= 0
    CWAFlag = 0;%��ʱ��
else
    CWAFlag = 1;%˳ʱ��
end
