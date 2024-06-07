## 题目

[1959. K 次调整数组大小浪费的最小总空间](https://leetcode.cn/problems/minimum-total-space-wasted-with-k-resizing-operations/)

---

你正在设计一个动态数组。给你一个下标从 **0** 开始的整数数组 `nums` ，其中 `nums[i]` 是 `i` 时刻数组中的元素数目。除此以外，你还有一个整数 `k` ，表示你可以 **调整** 数组大小的 **最多** 次数（每次都可以调整成 **任意** 大小）。

`t` 时刻数组的大小 `sizet` 必须大于等于 `nums[t]` ，因为数组需要有足够的空间容纳所有元素。`t` 时刻 **浪费的空间** 为 `sizet - nums[t]` ，**总** 浪费空间为满足 `0 <= t < nums.length` 的每一个时刻 `t` 浪费的空间 **之和** 。

在调整数组大小不超过 `k` 次的前提下，请你返回 **最小总浪费空间** 。

**注意：**数组最开始时可以为 **任意大小** ，且 **不计入** 调整大小的操作次数。

  

**示例 1：**

```txt
输入：nums = [10,20], k = 0
输出：10
解释：size = [20,20].
我们可以让数组初始大小为 20 。
总浪费空间为 (20 - 10) + (20 - 20) = 10 。
```

**示例 2：**

```txt
输入：nums = [10,20,30], k = 1
输出：10
解释：size = [20,20,30].
我们可以让数组初始大小为 20 ，然后时刻 2 调整大小为 30 。
总浪费空间为 (20 - 10) + (20 - 20) + (30 - 30) = 10 。
```

**示例 3：**

```txt
输入：nums = [10,20,15,30,20], k = 2
输出：15
解释：size = [10,20,20,30,30].
我们可以让数组初始大小为 10 ，时刻 1 调整大小为 20 ，时刻 3 调整大小为 30 。
总浪费空间为 (10 - 10) + (20 - 20) + (20 - 15) + (30 - 30) + (30 - 20) = 15 。
```
  

**提示：**

-   `1 <= nums.length <= 200`
-   `1 <= nums[i] <= 10^6`
-   `0 <= k <= nums.length - 1`

  

## 题解

### 方法一：

#### 思路

动态规划做法，设$f_{i,j}$为`nums[0...i]`中可以调整j次最最少浪费的空间和

初始化$f_{i,j} = \infin$

由于初始为位置可以任意选，所以在不允许调节的情况下，我们选择`nums[0...i]`中最大值作为初始空间。所以有$f_{i,0} = \sum \limits_{j=0}^{i} max(nums[0...i])-nums[j]$

此外初始化$f_{0,i}=0$对于一个数而言，无论调节多少次结果都是0.

状态转移$f_{i,j} = max(f_{k,j-1}+(i-k+1)*max(nums[k...i])-sum(nums[k...i]))$

最后答案是$f_{n-1, k}$

#### 代码

```cpp
class Solution {
public:
    const int INF = 0x3f3f3f3f;
    int f[202][202];
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        memset(f, INF, sizeof(f));
        int n = nums.size();
        for (int i=0;i<=k; i++) {
            f[0][i] = 0;
        }
        int mx=0, sum=0;
        for (int i=0; i<n; i++) {
            mx = max(mx, nums[i]);
            sum += nums[i];
            f[i][0] = (i+1)*mx-sum;
        }
        for (int i=1; i<n; i++) {
            for (int j=1; j<=k; j++) {
                mx = sum = nums[i];
                for (int k=i-1; k>=0; k--) {
                    f[i][j] = min(f[i][j], f[k][j-1]+(i-k)*mx-sum);
                    mx = max(mx, nums[k]);
                    sum += nums[k];
                }
                // printf("[%d,%d]=%d\n",i,j,f[i][j]);
            }
        }
        return f[n-1][k];
    }
};
```
