## 题目

[3013. 将数组分成最小总代价的子数组 II](https://leetcode.cn/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/description/)

---

给你一个下标从 **0** 开始长度为 `n` 的整数数组 `nums` 和两个 **正** 整数 `k` 和 `dist` 。

一个数组的 **代价** 是数组中的 **第一个** 元素。比方说，`[1,2,3]` 的代价为 `1` ，`[3,4,1]` 的代价为 `3` 。

你需要将 `nums` 分割成 `k` 个 **连续且互不相交** 的子数组，满足 **第二** 个子数组与第 `k` 个子数组中第一个元素的下标距离 **不超过** `dist` 。换句话说，如果你将 `nums` 分割成子数组 `nums[0..(i1 - 1)], nums[i1..(i2 - 1)], ..., nums[ik-1..(n - 1)]` ，那么它需要满足 `ik-1 - i1 <= dist` 。

请你返回这些子数组的 **最小** 总代价。

  

**示例 1：**

```txt
输入：nums = [1,3,2,6,4,2], k = 3, dist = 3
输出：5
解释：将数组分割成 3 个子数组的最优方案是：[1,3] ，[2,6,4] 和 [2] 。这是一个合法分割，因为 ik-1 - i1 等于 5 - 2 = 3 ，等于 dist 。总代价为 nums[0] + nums[2] + nums[5] ，也就是 1 + 2 + 2 = 5 。
5 是分割成 3 个子数组的最小总代价。
```

**示例 2：**

```txt
输入：nums = [10,1,2,2,2,1], k = 4, dist = 3
输出：15
解释：将数组分割成 4 个子数组的最优方案是：[10] ，[1] ，[2] 和 [2,2,1] 。这是一个合法分割，因为 ik-1 - i1 等于 3 - 1 = 2 ，小于 dist 。总代价为 nums[0] + nums[1] + nums[2] + nums[3] ，也就是 10 + 1 + 2 + 2 = 15 。
分割 [10] ，[1] ，[2,2,2] 和 [1] 不是一个合法分割，因为 ik-1 和 i1 的差为 5 - 1 = 4 ，大于 dist 。
15 是分割成 4 个子数组的最小总代价。
```

**示例 3：**

```txt
输入：nums = [10,8,18,9], k = 3, dist = 1
输出：36
解释：将数组分割成 4 个子数组的最优方案是：[10] ，[8] 和 [18,9] 。这是一个合法分割，因为 ik-1 - i1 等于 2 - 1 = 1 ，等于 dist 。总代价为 nums[0] + nums[1] + nums[2] ，也就是 10 + 8 + 18 = 36 。
分割 [10] ，[8,18] 和 [9] 不是一个合法分割，因为 ik-1 和 i1 的差为 3 - 1 = 2 ，大于 dist 。
36 是分割成 3 个子数组的最小总代价。
```
  

**提示：**

-   `3 <= n <= 10^5`
-   `1 <= nums[i] <= 10^9`
-   `3 <= k <= n`
-   `k - 2 <= dist <= n - 2`

  

## 题解

### 方法一：

#### 思路

用multiset维护两个多重集合A和B，A维护着区间中k个最小值，B维护着区间中剩余的值

无论是插入还是删除x，首先判断x所属集合。然后从所属集合中添加或删除。再判断A集合大小是否为k：大于k则移动一个最大值到B中，小于k则移动B中的最小值到A中。

题目可以转化为维护滑动窗口大小为dist+1，求`区间内k-1小的数的和+nums[0]`的最小值。


#### 代码

```C++
struct Kmin {
    int K;
    long long s;
    // st1 保存前 K 小值，st2 保存其它值
    multiset<long long> st1, st2;

    Kmin(int K): K(K), s(0){}

    void adjust() {
        while (st1.size() < K && st2.size() > 0) {
            long long t = *(st2.begin());
            s += t;
            st1.insert(t);
            st2.erase(st2.begin());
        }
        while (st1.size() > K) {
            long long t = *st1.rbegin();
            s -= t;
            st2.insert(t);
            st1.erase(st1.find(t));
        }
    }

    // 插入元素 x
    void add(long long x) {
        // x大于k，放第二个集合
        if (!st2.empty() && x >= *(st2.begin())) st2.insert(x);
        // x小于k，放第一个集合
        else st1.insert(x), s += x;
        adjust();
        
    }

    // 删除元素 x
    void del(long long x) {
        auto it = st1.find(x);
        if (it != st1.end()) st1.erase(it), s -= x;
        else st2.erase(st2.find(x));
        adjust();
    }
    long long getK() {
        return *st1.rbegin();
    }
    long long getKsum() {
        return s;
    }
};
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        // 区间大小为dist+1，求区间内k-1小的数的和
        long long ans = accumulate(nums.begin(), nums.begin()+dist+2, 0LL);
        int n = nums.size();
        Kmin km(k-1);
        for (int i=1; i<n; i++) {
            km.add(nums[i]);
            if (i-(dist+1)>=1) km.del(nums[i-dist-1]);
            if (i-dist>=1) {
                ans = min(ans, nums[0]+km.getKsum()); 
                // cout << i << " " << km.getKsum() << "\n";
            }
        }
        return ans;
    }
};
```
