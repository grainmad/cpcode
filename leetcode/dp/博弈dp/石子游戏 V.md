## 题目

[1685. 石子游戏 V](https://leetcode.cn/problems/stone-game-v/)


---


几块石子 **排成一行** ，每块石子都有一个关联值，关联值为整数，由数组 `stoneValue` 给出。

游戏中的每一轮：Alice 会将这行石子分成两个 **非空行**（即，左侧行和右侧行）；Bob 负责计算每一行的值，即此行中所有石子的值的总和。Bob 会丢弃值最大的行，Alice 的得分为剩下那行的值（每轮累加）。如果两行的值相等，Bob 让 Alice 决定丢弃哪一行。下一轮从剩下的那一行开始。

只 **剩下一块石子** 时，游戏结束。Alice 的分数最初为 **`0`** 。

返回 **Alice 能够获得的最大分数*** 。*

 

**示例 1：**

**输入：**stoneValue = [6,2,3,4,5,5]
**输出：**18
**解释：**在第一轮中，Alice 将行划分为 [6，2，3]，[4，5，5] 。左行的值是 11 ，右行的值是 14 。Bob 丢弃了右行，Alice 的分数现在是 11 。
在第二轮中，Alice 将行分成 [6]，[2，3] 。这一次 Bob 扔掉了左行，Alice 的分数变成了 16（11 + 5）。
最后一轮 Alice 只能将行分成 [2]，[3] 。Bob 扔掉右行，Alice 的分数现在是 18（16 + 2）。游戏结束，因为这行只剩下一块石头了。

**示例 2：**

**输入：**stoneValue = [7,7,7,7,7,7,7]
**输出：**28

**示例 3：**

**输入：**stoneValue = [4]
**输出：**0

 

**提示：**

	- `1 <= stoneValue.length <= 500`

	- `1 <= stoneValue[i] <= 10^6^`


## 题解


### 思路

动态规划
`O(n^3)`做法
定义状态`dp[l][r]`为面对区间`[l...r]`的Alice能获取的最大值。
我们枚举分割线i，当`sum[l...i]>sum[i+1...r]`时选择从右侧的子问题转移，即`dp[l][r] = max(dp[l][r], dfs(i+1, r)+sum[i+1...r]`；当`sum[l...i]<sum[i+1...r]`时选择从左侧的子问题转移，即`dp[l][r] = max(dp[l][r], dfs(l, i)+sum[l...i]`；当`sum[l...i]=sum[i+1...r]`时选择最小的左右侧的子问题转移，即`dp[l][r] = max(dp[l][r], dfs(l, i)+sum[l...i]，dfs(i+1, r)+sum[i+1...r])`；


### 代码


```cpp
class Solution {
public:
    int dp[505][505];//dp[l][r] 为区间[l,r]的最大值
    int p[505];
    int n;
    vector<int> stoneValue;
    int dfs(int l, int r) {
        if (dp[l][r] != -1) return dp[l][r];
        if (l==r) return dp[l][r] = 0;
        if (l+1==r) return dp[l][r] = min(stoneValue[l], stoneValue[r]);
        dp[l][r] = 0;
        for (int i=l; i<r; i++) {
            if (p[i+1]-p[l] > p[r+1]-p[i+1]) {
                dp[l][r] = max(dp[l][r], dfs(i+1, r)+p[r+1]-p[i+1]);
            } else if (p[i+1]-p[l] < p[r+1]-p[i+1]) {
                dp[l][r] = max(dp[l][r], dfs(l, i)+p[i+1]-p[l]);
            } else if (p[i+1]-p[l] == p[r+1]-p[i+1]) {
                dp[l][r] = max({dp[l][r], dfs(i+1, r)+p[r+1]-p[i+1], dfs(l, i)+p[i+1]-p[l]});
             }
        }
        return dp[l][r];
    }
    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();
        for (int i=1; i<=n; i++) p[i] = p[i-1] + stoneValue[i-1];
        memset(dp, -1, sizeof(dp));
        this->stoneValue = stoneValue;
        
        return dfs(0, n-1);
    }
};
```
