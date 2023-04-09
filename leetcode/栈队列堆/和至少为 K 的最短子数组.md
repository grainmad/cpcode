## 题目

[862. 和至少为 K 的最短子数组](https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/)

---

给你一个整数数组 `nums` 和一个整数 `k` ，找出 `nums` 中和至少为 `k` 的 **最短非空子数组** ，并返回该子数组的长度。如果不存在这样的 **子数组** ，返回 `-1` 。

**子数组** 是数组中 **连续** 的一部分。

  

**示例 1：**

```txt
输入：nums = [1], k = 1
输出：1
```

**示例 2：**

```txt
输入：nums = [1,2], k = 4
输出：-1
```

**示例 3：**

```txt
输入：nums = [2,-1,2], k = 3
输出：3
```
  

**提示：**

-   `1 <= nums.length <= 10^5`
-   `-10^5 <= nums[i] <= 10^5`
-   `1 <= k <= 10^9`

  

## 解题

### 方法一：

#### 思路
[1124. 表现良好的最长时间段](https://leetcode.cn/problems/longest-well-performing-interval/)求最大区间。
本题求最小区间。

同样用前缀和`p[i]`表示前i个数的和，`p[0] = 0, p[i] = p[i-1] + nums[i-1]`

考虑区间右端点j的最优左端点i是满足`p[j]-k>=p[i]`最大的i。

将离散化的前缀和作为树状数组的下标，前缀数组的下标作为树状数组的值，维护最大值。即可。

#### 代码

```cpp
class Solution {
public:
    using ll = long long;
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        map<ll,int> id;
        vector<ll> p(n+1);
        for (int i=1; i<=n; i++) {
            p[i] = p[i-1] + nums[i-1];
        }
        for (int i=0; i<=n; i++) {
            id[p[i]];
            id[p[i]-k];
        }
        int sz = 1;
        for (auto& [i,j]:id) j = sz++;

        vector<int> a(sz, -1);
        auto ask = [&](int x) {
            int rt = -1;
            for (int i=x; i; i-=i&-i) {
                rt = max(rt, a[i]);
            }
            return rt;
        };
        auto add = [&](int x, int val) {
            for (int i=x; i<sz; i+=i&-i) {
                a[i] = max(a[i], val);
            }
        };
        add(id[0], 0);
        int ans = n+1;
        for (int i=1; i<=n; i++) {
            int j = ask(id[p[i]-k]);
            if (j != -1) ans = min(ans, i-j);
            add(id[p[i]], i);
        }
        return ans==n+1?-1:ans;
    }
};

```
### 方法二：

#### 思路

单调队列

设$s_i$是`s[0...i]`的和。

我们需要对每个`i`找到最大的j使得$s_i-s_j\ge k$，然后维护最小的`i-j`作为答案。

对于前缀和的选择，肯定需要选择较长的且值较小的。

那么不大于前缀和$s_i$的$s_j, j < i$ 可以直接排除。这类似于一个递增单调栈，接下来需要在这个有序的栈内找到最大的`j`使得$s_j \le s_i-k$, 理论上每次可以用二分法找到这个$s_j$, 但是此后的$s_j'$一定不会比$s_j$小，所以可以用滑动窗口移除满足$s_j \le s_i-k$的$s_j$并维护最小的`i-j`.


#### 代码

```cpp
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long,int>> q;
        q.emplace_back(0, -1);
        int n = nums.size(), ans = n+1;
        long p = 0;
        for (int i=0; i<n; i++) {
            p += nums[i];
            while (q.size() && q.back().first>=p) q.pop_back();
            q.emplace_back(p, i);
            while (q.size() && q.front().first + k <= p) {
                ans = min(ans, i-q.front().second);
                q.pop_front();
            }
        }
        return ans==n+1?-1:ans;
    }
};
```
