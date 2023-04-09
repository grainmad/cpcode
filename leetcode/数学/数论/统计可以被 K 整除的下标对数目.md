## 题目

[2183. 统计可以被 K 整除的下标对数目](https://leetcode.cn/problems/count-array-pairs-divisible-by-k/)

---

给你一个下标从 **0** 开始、长度为 `n` 的整数数组 `nums` 和一个整数 `k` ，返回满足下述条件的下标对 `(i, j)` 的数目：

-   `0 <= i < j <= n - 1` 且
-   `nums[i] * nums[j]` 能被 `k` 整除。

  

**示例 1：**

```txt
输入：nums = [1,2,3,4,5], k = 2
输出：7
解释：
共有 7 对下标的对应积可以被 2 整除：
(0, 1)、(0, 3)、(1, 2)、(1, 3)、(1, 4)、(2, 3) 和 (3, 4)
它们的积分别是 2、4、6、8、10、12 和 20 。
其他下标对，例如 (0, 2) 和 (2, 4) 的乘积分别是 3 和 15 ，都无法被 2 整除。
```

**示例 2：**

```txt
输入：nums = [1,2,3,4], k = 5
输出：0
解释：不存在对应积可以被 5 整除的下标对。
```
  

**提示：**

-   `1 <= nums.length <= 10^5`
-   `1 <= nums[i], k <= 10^5`

  

## 解题

一个经典问题
已知正整数`a`，`b`，求正整数`c`，使得`a*b`被`c`整除。`b`一定是`c/gcd(c,a)`的倍数。

### 方法一：

#### 思路


我们求所有`nums[j]（j<n）`结尾的数对数量之和便是答案。

假设当前遍历到`nums[j]`，且以`j`作为数对的第二关键字，那么有多少`i（i<=j）`作为第一关键字呢？

我们知道这样的`i`满足条件：`nums[i]`是`k/gcd(nums[j],k)`的倍数。

因此可以在遍历时维护哈希表`cnt`，`cnt[i]`表示`i`的倍数的个数。

以`nums[j]`结尾的数对个数有`cnt[k/gcd(nums[j], k)]`个，然后将`nums[j]`的因子在哈希表中记录。

求`nums[j]`的因子的时间复杂度为$O(\sqrt{nums[j]})$，总时间复杂度为$O(n^{\frac{3}{2}})$

当然我们也预处理出所有数的因子然后存储起来。

#### 代码

``` cpp
class Solution {
public:
    #define N 100005
    long long cnt[N];
    long long countPairs(vector<int>& nums, int k) {
        long long ans = 0;
        for (int i:nums) {
            ans += cnt[k/gcd(i, k)];
            for (int j=1; j*j<=i; j++) {
                if (i%j == 0) {
                    cnt[j]++;
                    if (i/j != j) cnt[i/j]++;
                }
            }
        }
        return ans;
    }
};
```
### 方法二：

#### 思路

每次我们将`k/gcd(nums[j], k)`记录到哈希表，以`nums[j]`结尾的数对个数就是哈希表中为`nums[j]`的因子出现次数。

#### 代码
``` cpp
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int,long long> mp;
        for (int i:nums) {
            for (auto [a, b]:mp) {
                if (i%a == 0) ans += b;
            }
            mp[k/gcd(i, k)]++;
        }
        return ans;
    }
};
```

### 方法三：

#### 思路

我们知道这样的`i`满足条件：`nums[i]`是`k/gcd(nums[j],k)`的倍数。实际上就是k因子的倍数。

在遍历时维护哈希表`cnt`，`cnt[i]`表示`i`的倍数的个数。

以`nums[j]`结尾的数对个数有`cnt[k/gcd(nums[j], k)]`个，然后将能除尽`nums[j]`的k因子在哈希表中记录。

#### 代码

``` cpp
class Solution {
public:
    #define N 100005
    long long cnt[N];
    long long countPairs(vector<int>& nums, int k) {
        vector<int> p;
        for (int i=1; i*i<=k; i++) {
            if (k%i == 0) {
                p.push_back(i);
                if (k/i != i) p.push_back(k/i);
            }
        }
        long long ans = 0;
        for (int i:nums) {
            ans += cnt[k/gcd(i, k)];
            for (int j:p) {
                if (i%j == 0) cnt[j]++;
            }
        }
        return ans;
    }
};
```

### 方法四：

#### 思路

用哈希表统计每个数`i`出现的次数`cnt[i]`

然后类似筛选法统计`i`的倍数的个数`times[i]`。

对于`nums[j]`，满足`nums[i]*nums[j]（0<=i<n）`被`k`整除的个数有`times[k/gcd(nums[j],k)]`个。统计到答案中。

排除掉`i!=j`的`nums[i]`，那就是满足条件：`nums[j]`为`k/gcd(nums[j],k)]`的倍数。在统计答案中减去1。

剩余情况由于任意`0<=i,j<n, i!=j`的`nums[i]*nums[j]`都一一对应`nums[j]*nums[i]`，于是所有统计数除以2便是答案。

#### 代码

``` cpp
#define ll long long
#define N 100005
class Solution {
public:
    ll cnt[N];
    ll times[N];
    long long countPairs(vector<int>& nums, int k) {
        ll ans = 0;
        for (int i:nums) cnt[i]++;
        for (int i=1; i<N; i++) {
            for (int j=i; j<N; j+=i) {
                times[i] += cnt[j];
            }
        }
        for (int i:nums) {
            int t = k/gcd(i, k);
            ans += times[t];
            if (i%t == 0) ans--;
        }
        return ans/2;
    }
};
```
