## 题目

[2940. 找到 Alice 和 Bob 可以相遇的建筑](https://leetcode.cn/problems/find-building-where-alice-and-bob-can-meet/description/)

---

给你一个下标从 **0** 开始的正整数数组 `heights` ，其中 `heights[i]` 表示第 `i` 栋建筑的高度。

如果一个人在建筑 `i` ，且存在 `i < j` 的建筑 `j` 满足 `heights[i] < heights[j]` ，那么这个人可以移动到建筑 `j` 。

给你另外一个数组 `queries` ，其中 `queries[i] = [ai, bi]` 。第 `i` 个查询中，Alice 在建筑 `ai` ，Bob 在建筑 `bi` 。

请你能返回一个数组 `ans` ，其中 `ans[i]` 是第 `i` 个查询中，Alice 和 Bob 可以相遇的 **最左边的建筑** 。如果对于查询 `i` ，Alice 和 Bob 不能相遇，令 `ans[i]` 为 `-1` 。

  

**示例 1：**

```txt
输入：heights = [6,4,8,5,2,7], queries = [[0,1],[0,3],[2,4],[3,4],[2,2]]
输出：[2,5,-1,5,2]
解释：第一个查询中，Alice 和 Bob 可以移动到建筑 2 ，因为 heights[0] < heights[2] 且 heights[1] < heights[2] 。
第二个查询中，Alice 和 Bob 可以移动到建筑 5 ，因为 heights[0] < heights[5] 且 heights[3] < heights[5] 。
第三个查询中，Alice 无法与 Bob 相遇，因为 Alice 不能移动到任何其他建筑。
第四个查询中，Alice 和 Bob 可以移动到建筑 5 ，因为 heights[3] < heights[5] 且 heights[4] < heights[5] 。
第五个查询中，Alice 和 Bob 已经在同一栋建筑中。
对于 ans[i] != -1 ，ans[i] 是 Alice 和 Bob 可以相遇的建筑中最左边建筑的下标。
对于 ans[i] == -1 ，不存在 Alice 和 Bob 可以相遇的建筑。
```

**示例 2：**

```txt
输入：heights = [5,3,8,2,6,1,4,6], queries = [[0,7],[3,5],[5,2],[3,0],[1,6]]
输出：[7,6,-1,4,6]
解释：第一个查询中，Alice 可以直接移动到 Bob 的建筑，因为 heights[0] < heights[7] 。
第二个查询中，Alice 和 Bob 可以移动到建筑 6 ，因为 heights[3] < heights[6] 且 heights[5] < heights[6] 。
第三个查询中，Alice 无法与 Bob 相遇，因为 Bob 不能移动到任何其他建筑。
第四个查询中，Alice 和 Bob 可以移动到建筑 4 ，因为 heights[3] < heights[4] 且 heights[0] < heights[4] 。
第五个查询中，Alice 可以直接移动到 Bob 的建筑，因为 heights[1] < heights[6] 。
对于 ans[i] != -1 ，ans[i] 是 Alice 和 Bob 可以相遇的建筑中最左边建筑的下标。
对于 ans[i] == -1 ，不存在 Alice 和 Bob 可以相遇的建筑。
```
  

**提示：**

-   `1 <= heights.length <= 5 * 10^4`
-   `1 <= heights[i] <= 10^9`
-   `1 <= queries.length <= 5 * 10^4`
-   `queries[i] = [ai, bi]`
-   `0 <= ai, bi <= heights.length - 1`

  

## 题解

### 方法一：

#### 思路

对于查询$[a,b]$不妨设$a\le b$，在$a=b$或$heights_a < heights_b$可以直接得到答案$b$

在除去这种特殊情况后，我们的问题变为了对于每个查询$[a,b]$，寻找最小$i$使得$b<i, heights_a \ge heights_i$

我们可以由小到大遍历$i$，找到所有查询中以$i$作为答案的查询。由于$i$是由小到大遍历的，所以对于每个查询找到的答案是最小的。

如何找到所有查询中以$i$作为答案的查询？只需要在所有右端点b小于i的查询中找到左端点a其值$heights_a < heights_i$的查询索引$idx$，得到答案$ans_{idx} = i$

维护一个$(heights_a, idx)$二元组的集合即可。能够高效查出最小值。可以用堆或平衡树等。


#### 代码

```C++
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        // 由小到大遍历i，找到所有查询中以i作为答案的查询，
        // 这样的查询[a,b]满足a<b, heights[i] > heights[a] > heights[b]
        // 由于i是由小到大遍历的，所以对于每个查询找到的答案是最小的。
        // 如何找到所有查询中以i作为答案的查询？
        // 对于查询[a,b]不妨设a<=b，在a=b或heights[a] < heights[b]可以直接得到答案b。
        // 否则只需要在所有右端点b小于i的查询中找到左端点a其值heights[a] < heights[i]的查询索引idx，让答案数组ans[idx] = i
        // 维护一个(heights[a], idx)二元组的集合即可。能够高效查出最小值。可以用堆或平衡树等。
        priority_queue<pair<int,int>> pq;
        int hsz = heights.size(), qsz = queries.size();
        vector<vector<pair<int,int>>> h(hsz);
        vector<int> ans(qsz, -1);
        for (int i=0; i<qsz; i++) {
            int a = queries[i][0], b = queries[i][1];
            if (a>b) swap(a, b);
            if (a==b || heights[a] < heights[b]) ans[i] = b;
            else h[b].emplace_back(-heights[a], i);
        }
        for (int i=0; i<hsz; i++) {
            while (pq.size() && -pq.top().first < heights[i]) {
                ans[pq.top().second] = i;
                pq.pop();
            }
            for (auto x:h[i]) {
                pq.emplace(x);
            }
        }
        return ans;
    }
};
```


### 方法二：

#### 思路

对于查询$[a,b]$不妨设$a\le b$，在$a=b$或$heights_a < heights_b$可以直接得到答案$b$

在除去这种特殊情况后，我们的问题变为了对于每个查询$[a,b]$，寻找最小$i$使得$b < i, heights_a \ge heights_i$

线段树维护heights区间最小值。每次查询$heights[b...n-1]$中大于$heights_a$的最小下标。可以线段树上二叉搜索。

#### 代码

```C++
#define ls id<<1
#define rs id<<1|1
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int hsz = heights.size();
        vector<int> mx(4*(hsz+5), 0);
        function<void(int,int,int)> build = [&](int id, int l, int r) {
            if (l==r) {
                mx[id] = heights[l];
                return ;
            }
            int m = l+r>>1;
            build(ls, l, m);
            build(rs, m+1, r);
            mx[id] = max(mx[ls], mx[rs]);
        };
        build(1, 0, hsz-1);
        // 查询[ql, n]中大于v的最小下标，没有为-1
        function<int(int,int,int,int,int)> ask = [&](int id, int l, int r, int ql, int v) {
            if (mx[id] <= v) return -1; // 当前区间最大值不大于v，所以返回-1
            if (l == r) return l; // 到达最小区间直接返回索引
            int m = l+r>>1; 
            if (ql <= m) { // ql是落在左区间，左区间找不到则去右区间找
                int lrt = ask(ls, l, m, ql, v);
                if (lrt != -1) return lrt;
                return ask(rs, m+1, r, ql, v);
            } else { // 左区间不含大于等于ql的索引，只要遍历右区间
                return ask(rs, m+1, r, ql, v);
            }
        };
        vector<int> ans;
        for (auto x:queries) {
            int i = x[0], j = x[1];
            if (i>j) swap(i,j);
            if (i==j || heights[i] < heights[j]) ans.push_back(j);
            else ans.push_back(ask(1, 0, hsz-1, j, heights[i]));
        }
        return ans;
    }
};
```

### 方法三：

#### 思路

二维偏序

对于查询$[a,b]$不妨设$a\le b$，在$a=b$或$heights_a < heights_b$可以直接得到答案$b$

在除去这种特殊情况后，我们的问题变为了对于每个查询$[a,b]$，寻找最小$i$使得$b < i, heights_a \ge heights_i$

考虑所有查询点$(heighs_a,b)$和数据点$(heights_i,i)$
为了保证查询点和数据点相同的情况下，查询点在数据点后面，并且能得到原查询的次序。对于第k次查询$[a_k, b_k]$，用三元组$(heighs_a,b,-k)$表示查询点，并用$(heighs_i, i, 1)$表示数据点。

将这些点的集合排序，按照第一关键字降序，第二关键字降序，第三关键字降序排序。

此时遍历点集合，对于当前点$(x,y,z)$，之前遍历过的点$(x',y',z')$。$x\ge x'$。
如果当前z非0说明是查询点，我们只需要找到大于$z$的最小$z'$；
如果当前z为0说明是数据点，更新后缀$[y, \dots]$中的最小值为y。
树状数组可单点修改，求前缀最小值。可用树状数组维护$[1,N-y]$最小值。

#### 代码

```C++
class Solution {
public:
    const int INF = 0x3f3f3f3f;
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int N = n+5;
        int BIT[N+5];
        memset(BIT, 0x3f, sizeof(BIT));
        auto ask = [&](int x) {
            int rt = INF;
            for (int i=x; i; i-=i&-i) {
                rt = min(rt, BIT[i]);
            }
            return rt;
        };
        auto add = [&](int x, int v) {
            for (int i=x; i<N; i+=i&-i) {
                BIT[i] = min(BIT[i], v);
            }
        };
        vector<int> ans(queries.size(), -1);
        vector<vector<int>> p;
        int id = 0;
        for (auto& i:queries) {
            int a = min(i[0], i[1]), b = max(i[0], i[1]);
            if (a==b || heights[a] < heights[b]) ans[id] = b;
            else p.push_back({heights[a]+1, b, -id}); 
            id++;
        }
        for (int i=0; i<n; i++) {
            p.push_back({heights[i], i, 1});
        }
        sort(p.rbegin(), p.rend());
        for (auto& i:p) {
            int a = i[0], b = i[1], c = i[2];
            if (c <= 0) {
                int rt = ask(N-b);
                if (rt != INF) ans[-c] = rt;
                else ans[-c] = -1;
            } else {
                add(N-b, b);
            }
        }
        return ans;
    }
};
```
