## 题目

[3049. 标记所有下标的最早秒数 II](https://leetcode.cn/problems/earliest-second-to-mark-indices-ii/description/)

---

给你两个下标从 **1** 开始的整数数组 `nums` 和 `changeIndices` ，数组的长度分别为 `n` 和 `m` 。

一开始，`nums` 中所有下标都是未标记的，你的任务是标记 `nums` 中 **所有** 下标。

从第 `1` 秒到第 `m` 秒（**包括** 第 `m` 秒），对于每一秒 `s` ，你可以执行以下操作 **之一** ：

-   选择范围 `[1, n]` 中的一个下标 `i` ，并且将 `nums[i]` **减少** `1` 。
-   将 `nums[changeIndices[s]]` 设置成任意的 **非负** 整数。
-   选择范围 `[1, n]` 中的一个下标 `i` ， 满足 `nums[i]` **等于** `0`, 并 **标记** 下标 `i` 。
-   什么也不做。

请你返回范围 `[1, m]` 中的一个整数，表示最优操作下，标记 `nums` 中 **所有** 下标的 **最早秒数** ，如果无法标记所有下标，返回 `-1` 。

  

**示例 1：**

```txt
输入：nums = [3,2,3], changeIndices = [1,3,2,2,2,2,3]
输出：6
解释：这个例子中，我们总共有 7 秒。按照以下操作标记所有下标：
第 1 秒：将 nums[changeIndices[1]] 变为 0 。nums 变为 [0,2,3] 。
第 2 秒：将 nums[changeIndices[2]] 变为 0 。nums 变为 [0,2,0] 。
第 3 秒：将 nums[changeIndices[3]] 变为 0 。nums 变为 [0,0,0] 。
第 4 秒：标记下标 1 ，因为 nums[1] 等于 0 。
第 5 秒：标记下标 2 ，因为 nums[2] 等于 0 。
第 6 秒：标记下标 3 ，因为 nums[3] 等于 0 。
现在所有下标已被标记。
最早可以在第 6 秒标记所有下标。
所以答案是 6 。
```

**示例 2：**

```txt
输入：nums = [0,0,1,2], changeIndices = [1,2,1,2,1,2,1,2]
输出：7
解释：这个例子中，我们总共有 8 秒。按照以下操作标记所有下标：
第 1 秒：标记下标 1 ，因为 nums[1] 等于 0 。
第 2 秒：标记下标 2 ，因为 nums[2] 等于 0 。
第 3 秒：将 nums[4] 减少 1 。nums 变为 [0,0,1,1] 。
第 4 秒：将 nums[4] 减少 1 。nums 变为 [0,0,1,0] 。
第 5 秒：将 nums[3] 减少 1 。nums 变为 [0,0,0,0] 。
第 6 秒：标记下标 3 ，因为 nums[3] 等于 0 。
第 7 秒：标记下标 4 ，因为 nums[4] 等于 0 。
现在所有下标已被标记。
最早可以在第 7 秒标记所有下标。
所以答案是 7 。
```

**示例 3：**

```txt
输入：nums = [1,2,3], changeIndices = [1,2,3]
输出：-1
解释：这个例子中，无法标记所有下标，因为我们没有足够的秒数。
所以答案是 -1 。
```
  

**提示：**

-   `1 <= n == nums.length <= 5000`
-   `0 <= nums[i] <= 10^9`
-   `1 <= m == changeIndices.length <= 5000`
-   `1 <= changeIndices[i] <= n`

  

## 题解

### 方法一：

#### 思路

二分答案+反悔贪心

对于nums中每个数，都需要置为0后再标记，我们可以通过花费一步操作利用changeIndices快速将一个数置为0，或者花费`nums[i]`步将`nums[i]`置为0，最后花一步进行标记。

可知每个数被标记，最少需要两步操作，至多`nums[i]+1`步。

对于一个数如果确定它用两步操作，那么就可以不用"减1"的操作。并且要尽早的标记，也就是说选择changeIndices中较早出现的i，我们可以对`nums[i]`进行快速置0。于是我们可以在changeIndices中寻找每个数`i`最早出现的下标`fid[i]`。

我们二分答案，假设最少需要t秒，我们t-1到0遍历。当`changeIndices[i]`不是最早出现的，那么当前这一秒可以将操作记录为"可分配的操作"c；否则当前i位置直接将`nums[changeIndices[i]]`置为0，由于后续会将其标记，所以c--。如果c为0了，我们可以利用之前的快速置0操作中修改的`nums[j]`，（`nums[j]<nums[i]`）将`nums[j]`替换为暴力，返回两次"可分配操作"，显然`nums[j]`越小越好。我们可以用小根堆存储。可分配操作c的次数应当不小于未标记的nums所需的步数，那么t秒是可以完成的。



#### 代码

```C++
class Solution {
public:
    using ll = long long;
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& cid) {
        ll n = nums.size(), m = cid.size();
        for (auto& i:cid) i--;
        vector<int> fid(n, -1); // fid[i]，i在cid中第一次出现的位置。
        for (int i=m-1; i>=0; i--) {
            fid[cid[i]] = i;
        }
        ll mxopt = accumulate(nums.begin(), nums.end(), n); // 最多需要操作次数
        auto check = [&] (int x) {
            priority_queue<int, vector<int>, greater<>> q;
            ll c = 0; // 可任意分配的操作
            ll s = mxopt; //没有加速的节点 被标记需要的暴力操作次数
            for (int i=x; i>=0; i--) {
                int u = cid[i];
                int v = nums[u];
                if (v <= 1 || i != fid[u]) {
                    c++;
                    continue;
                }
                if (c == 0) {
                    if (q.empty() || v <= q.top()) {
                        c++;
                        continue;
                    }
                    s += q.top()+1;
                    q.pop();
                    c+=2;
                }
                q.emplace(v);
                s -= v+1;
                c--;
            }
            return c >= s;
        };
        int l = 0, r = m;
        while (l<r) {
            int t = l+r>>1;
            if (check(t)) {
                r = t;
            } else {
                l = t+1;
            }
        }
        return r==m?-1:r+1;
    }
};
```
