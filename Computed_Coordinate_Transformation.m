function [map,FFLOG] = Computed_Coordinate_Transformation(mapLat,mapLon,mapCnt,mapPointFlag)
%% 经纬度转换为平面坐标
%{
输入：
mapLat:输入边界点的横坐标(数据类型：double 1xmapCnt)
mapLon:输入边界点的纵坐标(数据类型：double 1xmapCnt)
mapCnt:输入的点的个数(数据类型：double 1x1)
mapPointFlag：输入的坐标是否为经纬度坐标，1为经纬度坐标，0为否(数据类型：double 1x1)
输出：
map：转化为平面直角坐标系的坐标
FFLOG：0为逆时针，1为顺时针
%}
FFLOG = zeros(1,1);
map = zeros(mapCnt,2);
%mapLon经度坐标，坐标个数mapCnt
if mapPointFlag == 1
    refLat = mapLat(1,1);
    refLon = mapLon(1,1);
    earthR = 6371393;
    latR = 6371393*cos(refLat*pi/180);
    for i=2:mapCnt
        map(i,1) = earthR*(mapLat(1,i)-refLat)*pi/180;
        map(i,2) = latR*(mapLon(1,i)-refLon)*pi/180;
    end
    map(1,1)=0;
    map(1,2)=0;
    FFLOG(1,1) = judgeClockWise(map(:,1),map(:,2),mapCnt);
end