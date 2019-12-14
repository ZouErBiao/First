function Prep = Preprocess(Point,P_Cnt)
%对输入数据进行预处理，排除重合和连续三点在同一条直线上的情况
%{
输入：
%Point为输入的边界点
P_Cnt:边界点的个数
输出：
Prep为经过去重和去连续连续操作后的点集的结构体，格式为50乘以2
Prep.Preprocessing:格式为50乘以2
Prep.Cnt:有效点的个数
%}
%%
Prep.Preprocessing = zeros(100,2);
Prep.Cnt = zeros(1,1);

P_M = zeros(P_Cnt,3);
Count = zeros(1,1);
P_M(1:P_Cnt,1:2) = Point(1:P_Cnt,1:2);
%P_M的第三列是标志位，为1的话则此行需删除
Eps = zeros(1,1);
Eps(1,1) = min([P_M(2,1)*0.005 P_M(2,2)*0.005]);%工程上要求的千分之五
if all(abs(P_M(1,:)-P_M(2,:))<=Eps(1,1)) == 1
    P_M(2,3) = 1;%为了占位给重复的地方替换为其他值，替换值要尽量不要跟数据采集点重复，采集点恰好与该值相等的概率极低（即：该值最好取地块的内部一点）
    Count(1,1) = Count(1,1)+1;
end
for i=3:P_Cnt
    for j=1:i-1
        Eps(1,1) = min([P_M(i,1)*0.005 P_M(i,2)*0.005]);%工程上要求的千分之五
        if all(abs(P_M(j,:)-P_M(i,:)) <= Eps(1,1)) == 1 
            P_M(i,3) = 1;
            Count(1,1) = Count(1,1)+1;
            break;
        end
    end
end
%%
%保留不重复的点
Point_map = zeros(P_Cnt-Count(1,1),2);
Cnt = zeros(1,1);%第一位用于下标计数

for i =1:P_Cnt
    if eq(P_M(i,3),0)
        Cnt(1,1) = Cnt(1,1)+1;
        Point_map(Cnt(1,1),1:2) = P_M(i,1:2);
    end
end
%以上代码解决了点的重复问题
%%
%%以下代码解决连续三点在同一条直线上的问题
NEdgevectorList = zeros(Cnt(1,1),2);
NEdgevectorList(1:Cnt(1,1),1:2) = DPList(Point_map(1:Cnt(1,1),1:2),Cnt(1,1));
NEdgevectorList(1:Cnt(1,1),1:2) = NormalizeDPList(NEdgevectorList(1:Cnt(1,1),1:2),Cnt(1,1));%各边的单位向量

IndexPrepro = zeros(Cnt(1,1),1);%与前面单位向量相等的点的点号的存储,列向量
Index_Cnt = zeros(1,1);
if eq(NEdgevectorList(1,1),NEdgevectorList(Cnt(1,1),1)) && eq(NEdgevectorList(1,2),NEdgevectorList(Cnt(1,1),2))
    IndexPrepro(1,1) = 1;%与前面单位向量相等的点号
else
    Index_Cnt(1,1) = Index_Cnt(1,1)+1;
    IndexPrepro(1,1) = 0;
end
for i=2:Cnt(1,1)
    if eq(NEdgevectorList(i,1),NEdgevectorList(i-1,1)) && eq(NEdgevectorList(i,2),NEdgevectorList(i-1,2))
        IndexPrepro(i,1) = i;%与前面单位向量相等的点 号
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