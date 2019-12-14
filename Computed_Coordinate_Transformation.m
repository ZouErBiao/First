function [map,FFLOG] = Computed_Coordinate_Transformation(mapLat,mapLon,mapCnt,mapPointFlag)
%% ��γ��ת��Ϊƽ������
%{
���룺
mapLat:����߽��ĺ�����(�������ͣ�double 1xmapCnt)
mapLon:����߽���������(�������ͣ�double 1xmapCnt)
mapCnt:����ĵ�ĸ���(�������ͣ�double 1x1)
mapPointFlag������������Ƿ�Ϊ��γ�����꣬1Ϊ��γ�����꣬0Ϊ��(�������ͣ�double 1x1)
�����
map��ת��Ϊƽ��ֱ������ϵ������
FFLOG��0Ϊ��ʱ�룬1Ϊ˳ʱ��
%}
FFLOG = zeros(1,1);
map = zeros(mapCnt,2);
%mapLon�������꣬�������mapCnt
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