## 题目

[6987. 使数组和小于等于 x 的最少时间](https://leetcode.cn/problems/minimum-time-to-make-array-sum-at-most-x/)

---

给你两个长度相等下标从 **0** 开始的整数数组 `nums1` 和 `nums2` 。每一秒，对于所有下标 `0 <= i < nums1.length` ，`nums1[i]` 的值都增加 `nums2[i]` 。操作 **完成后** ，你可以进行如下操作：

-   选择任一满足 `0 <= i < nums1.length` 的下标 `i` ，并使 `nums1[i] = 0` 。

同时给你一个整数 `x` 。

请你返回使 `nums1` 中所有元素之和 **小于等于** `x` 所需要的 **最少** 时间，如果无法实现，那么返回 `-1` 。

  

**示例 1：**

```txt
输入：nums1 = [1,2,3], nums2 = [1,2,3], x = 4
输出：3
解释：
第 1 秒，我们对 i = 0 进行操作，得到 nums1 = [0,2+2,3+3] = [0,4,6] 。
第 2 秒，我们对 i = 1 进行操作，得到 nums1 = [0+1,0,6+3] = [1,0,9] 。
第 3 秒，我们对 i = 2 进行操作，得到 nums1 = [1+1,0+2,0] = [2,2,0] 。
现在 nums1 的和为 4 。不存在更少次数的操作，所以我们返回 3 。
```

**示例 2：**

```txt
输入：nums1 = [1,2,3], nums2 = [3,3,3], x = 4
输出：-1
解释：不管如何操作，nums1 的和总是会超过 x 。
```
  

**提示：**

-   `1 <= nums1.length <= 10^3`
-   `1 <= nums1[i] <= 10^3`
-   `0 <= nums2[i] <= 10^3`
-   `nums1.length == nums2.length`
-   `0 <= x <= 10^6`

  

## 解题

### 方法一：

#### 思路

设两个数组的大小为n，s1为nums1的总和，s2为nums2的总和。

如果n次操作后都没有使得nums1数组和小于等于x，那么没有答案。超过n次说明某个数会归零多次，实际上只会保留最后一次归零。

假设确定只需要t次操作，如果没有进行归零操作，那么总和是`s1+t*s2`，我们需要将t次归零进行分配，进而减小总和。那么根据排序不等式，nums2越小的要越早分配归零操作，才能使得减少部分最大化，总和最小化。

我们将nums1和nums2同时以以nums2升序排序。

对于假设对第i个数在第j次操作时进行归零，那么会对总和减少`nums1[i]+nums2[i]*j`。

我们可以用01背包求解n个数在第i操作时的减少值的最大值。

定义$f_{i,j}$为前i个数中选择j个数进行归零操作得到的最大和。

显然对于每个i我们可以选与不选，若不选，则从前i-1个数中选j个；若选，则从前i-1个数中选j-1个然后加上`nums1[i]+nums2[i]*j`。选与不选两种情况取最大值。

所以状态转移为$f_{i,j} = max(f_{i-1, j}, f_{i-1,j-1}+nums1_i+nums2_i\times j)$

答案就是是第一个满足$s1+s2*i-f_{n,i}\le x$的$i$。没有满足的i答案就是-1.


#### 代码

```cpp
class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int x, int y) {
            return nums2[x] < nums2[y];
        });
        
        /*
        vector<vector<int>> f(n+1, vector<int>(n+1, 0)); // f[i][j] 前i个数中选j个的最大值。
        for (int i=1; i<=n; i++) { // 320 ms	123.7 MB
            for (int j=1; j<=n; j++) {
                f[i][j] = max(f[i-1][j], f[i-1][j-1]+nums1[idx[i-1]]+nums2[idx[i-1]]*j);
            }
        }
        */

        /*
        vector<int> f(n+1, 0); // f[i][j] 前i个数中选j个的最大值。
        for (int i=1; i<=n; i++) { // 228 ms	61 MB
            for (int j=n; j>=1; j--) {
                f[j] = max(f[j], f[j-1]+nums1[idx[i-1]]+nums2[idx[i-1]]*j);
            }
        }
        */
       /*
        vector<int> f(n+1, 0); // f[i][j] 前i个数中选j个的最大值。
        for (int i=1; i<=n; i++) { // 136 ms	60.8 MB
            for (int j=i; j>=1; j--) {
                f[j] = max(f[j], f[j-1]+nums1[idx[i-1]]+nums2[idx[i-1]]*j);
            }
        }
       */

        vector<int> f(n+1, 0); // f[i][j] 前i个数中选j个的最大值。
        for (int i:idx) { // 176 ms	60.7 MB
            for (int j=n; j>=1; j--) {
                f[j] = max(f[j], f[j-1]+nums1[i]+nums2[i]*j);
            }
        }
        
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        for (int i=0; i<=n; i++) {
            if (s1 + i*s2 - f[i] <= x) return i;
        }
        return -1;
    }
};
```
