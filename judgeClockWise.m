%% 判断地块是顺时针还是逆时针
function CWAFlag = judgeClockWise(lat_in,lon_in,len)
%输出:顺时针为1，逆时针为0
%算法说明：
% 对某一个点计算cross product = ((xi - xi-1),(yi - yi-1)) x ((xi+1 - xi),(yi+1 - yi)) = (xi - xi-1) * (yi+1 - yi) - (yi - yi-1) * (xi+1 - xi)
% 如果上式的值为正，逆时针；为负则是顺时针
% 而对于一般的简单多边形，则需对于多边形的每一个点计算上述值，如果正值比较多，是逆时针；负值较多则为顺时针。
% lat_in:x,lon_in:y
%%
if 0
    figure
    plot(lat_in(1:len),lon_in(1:len),'*-');
    hold on
    plot(lat_in(1),lon_in(1),'r*','lineWidth',8);
    plot(lat_in(2),lon_in(2),'*','lineWidth',8);
end
%% 判断
CWAFlag = 0;
if len < 3
   return; 
end
%% 叉乘遍历计算
count = 0;
z = 0;
for i=1:len
    % 找到相邻两点
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

    % 计算叉乘
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
    CWAFlag = 0;%逆时针
else
    CWAFlag = 1;%顺时针
end
%% Green 算法
d = 0;
for i=1:len-1
    %d += - 0.5 * ( y[i + 1] + y[i]) * (x[i + 1] - x[i]);
    d = d - 0.5 * (lon_in(i + 1) + lon_in(i)) * (lat_in(i + 1) - lat_in(i));
end
d = d - 0.5 * (lon_in(1) + lon_in(len)) * (lat_in(1) - lat_in(len));
%
if d >= 0
    CWAFlag = 0;%逆时针
else
    CWAFlag = 1;%顺时针
end
