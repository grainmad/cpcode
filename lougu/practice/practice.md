# p6835
期望dp
设$dp_i$为从点i到i+1的期望, $S_i$为i点的返祖边所连接的点集合, $S_i$的大小为$size_i$。
求$dp_i$要考虑i点有多少条出边。 
每条出边被选择的概率都为$\frac{1}{size_i}$。
转移式
$dp_i = \frac{1}{size_i+1} \times 1 + \frac{1}{size_i+1} \sum \limits_{j \in S_i}(1+ \sum \limits_{k=j}^idp_k)$
这里的$\sum \limits_{k=j}^idp_k$是从返祖边指向的点j到i+1的期望，其实就是$dp_j+dp_{j+1}+\cdots+dp_i$
对这个式子变形：
$dp_i = 1 + \frac{1}{size_i+1} \sum \limits_{j \in S_i}\sum \limits_{k=j}^idp_k$
将dp的区间和改为前缀和的差，便于计算。
$dp_i = 1 + \frac{1}{size_i+1} \sum \limits_{j \in S_i}(\sum \limits_{k=1}^idp_k-\sum \limits_{k=1}^{j-1}dp_k)$
将等号右边的$dp_i$移到左边。
$dp_i = size_i+1 + \sum \limits_{j \in S_i}(\sum \limits_{k=1}^{i-1}dp_k-\sum \limits_{k=1}^{j-1}dp_k)$

# 