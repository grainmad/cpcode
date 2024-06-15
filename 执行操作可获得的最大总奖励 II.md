## 题目

[执行操作可获得的最大总奖励 II](https://leetcode.cn/problems/maximum-total-reward-using-operations-ii/)

---

给你一个整数数组 `rewardValues`，长度为 `n`，代表奖励的值。

最初，你的总奖励 `x` 为 0，所有下标都是**未标记** 的。你可以执行以下操作 **任意次** ：

  * 从区间 `[0, n - 1]` 中选择一个 **未标记** 的下标 `i`。
  * 如果 `rewardValues[i]` **大于** 你当前的总奖励 `x`，则将 `rewardValues[i]` 加到 `x` 上（即 `x = x + rewardValues[i]`），并**标记** 下标 `i`。

以整数形式返回执行最优操作能够获得的**最大**总奖励。



**示例 1：**

**输入：** rewardValues = [1,1,3,3]

**输出：** 4

**解释：**

依次标记下标 0 和 2，总奖励为 4，这是可获得的最大值。

**示例 2：**

**输入：** rewardValues = [1,6,4,3,2]

**输出：** 11

**解释：**

依次标记下标 0、2 和 1。总奖励为 11，这是可获得的最大值。



**提示：**

  * `1 <= rewardValues.length <= 5 * 10^4`
  * `1 <= rewardValues[i] <= 5 * 10^4`



## 题解

### 方法一:

#### 思路

01背包，bitset优化

~~这个数据范围根本就没向背包dp上想~~

设`rewardValues`中最大值为`mx`，可知奖励值最大`2mx-1 < 10^5`

设$f_{i,j}$为前i个数中能否达到奖励值为j。

初始$f_{0,0} = 1$

$f_{i,j} = \max \left \lbrace  \begin{array}{ll} f_{i-1,j} \\\\ f_{i-1,j-reward_i} & reward_i \le j < 2\times reward_i \end{array} \right .$

时间复杂度$O(mx\cdot n)$，给出的数据范围，状态数可以达到5e9，利用滚动数组可以优化空间复杂度，但是时间复杂度仍然无法通过此题。

利用bitset， 时间复杂度可以降低至$O(\frac{mx\cdot n}{w})$ ，其中 w=64（计算机的位数），一个长整型可以存储64个状态，当两个长整型进行二进制或操作时，可以一次性转移64个状态。


#### 代码

``` cpp
class Solution {
public:
    const int NINF = 0xf3f3f3f3;
    int maxTotalReward(vector<int>& rew) {
        sort(rew.begin(), rew.end());
        rew.erase(unique(rew.begin(), rew.end()), rew.end());
        int n = rew.size();
        int mx = rew[n-1]*2;
        bitset<100005> f;
        f[0] = 1;
        for (int i:rew) {
            int s = 100005-i;
            f |= f<<s>>(s-i);
        }
        for (int j=mx; j>=0; j--) if (f[j]) return j;
        return 0;
    }
};
```
