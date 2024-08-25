## 题目

[K 次乘运算后的最终数组 II](https://leetcode.cn/problems/final-array-state-after-k-multiplication-operations-ii/)

---

给你一个整数数组 `nums` ，一个整数 `k`  和一个整数 `multiplier` 。

你需要对 `nums` 执行 `k` 次操作，每次操作中：

  * 找到 `nums` 中的 **最小**  值 `x` ，如果存在多个最小值，选择最 **前面**  的一个。
  * 将 `x` 替换为 `x * multiplier` 。

`k` 次操作以后，你需要将 `nums` 中每一个数值对 `109 + 7` 取余。

请你返回执行完 `k` 次乘运算以及取余运算之后，最终的 `nums` 数组。



**示例 1：**

**输入：** nums = [2,1,3,5,6], k = 5, multiplier = 2

**输出：** [8,4,6,5,6]

**解释：**

操作 | 结果  
---|---  
1 次操作后 | [2, 2, 3, 5, 6]  
2 次操作后 | [4, 2, 3, 5, 6]  
3 次操作后 | [4, 4, 3, 5, 6]  
4 次操作后 | [4, 4, 6, 5, 6]  
5 次操作后 | [8, 4, 6, 5, 6]  
取余操作后 | [8, 4, 6, 5, 6]  
  
**示例 2：**

**输入：** nums = [100000,2000], k = 2, multiplier = 1000000

**输出：** [999999307,999999993]

**解释：**

操作 | 结果  
---|---  
1 次操作后 | [100000, 2000000000]  
2 次操作后 | [100000000000, 2000000000]  
取余操作后 | [999999307, 999999993]  
  


**提示：**

  * `1 <= nums.length <= 104`
  * `1 <= nums[i] <= 109`
  * `1 <= k <= 109`
  * `1 <= multiplier <= 106`



## 题解

### 方法一:

#### 思路

每次优先选择最小的乘以`multiplier`。

当所有数都至少乘以过一次`multiplier`，接下来的选择是n个数中轮流选择乘以`multiplier`。

先记录`nums`中最大值的下标mx。然后用优先队列不断选择取出最小值乘以`multiplier`再放回，并减少k一次。直到下标为mx的数也乘以过一次`multiplier`。这个过程在`multiplier != 1`情况下只需要$min(nlog(n), k)$次堆操作。`multiplier = 1`则可以直接将原数组作为答案。

此后每个数至少需要再乘以$multiplier^{\lfloor \frac{k}{n} \rfloor}$

另外优先队列中最小的$k \mod n$个数需要再多乘以一次`multiplier`。

#### 代码

``` cpp
class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9+7;
    ll fpow(ll x, ll p) {
        ll rt = 1;
        while (p) {
            if (p&1) rt = x * rt % MOD;
            p>>=1;
            x = x * x % MOD;
        }
        return rt;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) return nums;
        int n = nums.size();
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
        int mx = 0;
        for (int i=0; i<n; i++) {
            if (nums[i] > nums[mx]) mx = i;
            pq.emplace(nums[i], i);
        }
        while (k>0) {
            k--;
            auto [x, y] = pq.top(); pq.pop();
            pq.emplace(x*multiplier, y);
            if (y == mx) break;
        }
        int t = k/n, r = k%n;
        vector<ll> v(n);
        for (int i=0; i<n; i++) {
            auto [x, y] = pq.top(); pq.pop();
            v[y] = x%MOD*fpow(multiplier, t+(i<r))%MOD;
        }
        vector<int> ans;
        for (auto i:v) ans.push_back(i);
        return ans;
    }
};
```
