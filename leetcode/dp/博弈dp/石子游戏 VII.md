## 题目

[1808. 石子游戏 VII](https://leetcode.cn/problems/stone-game-vii/)


---


石子游戏中，爱丽丝和鲍勃轮流进行自己的回合，**爱丽丝先开始** 。

有 `n` 块石子排成一排。每个玩家的回合中，可以从行中 **移除** 最左边的石头或最右边的石头，并获得与该行中剩余石头值之 **和** 相等的得分。当没有石头可移除时，得分较高者获胜。

鲍勃发现他总是输掉游戏（可怜的鲍勃，他总是输），所以他决定尽力 **减小得分的差值** 。爱丽丝的目标是最大限度地 **扩大得分的差值** 。

给你一个整数数组 `stones` ，其中 `stones[i]` 表示 **从左边开始** 的第 `i` 个石头的值，如果爱丽丝和鲍勃都 **发挥出最佳水平** ，请返回他们 **得分的差值** 。

 

**示例 1：**

**输入：**stones = [5,3,1,4,2]
**输出：**6
**解释：**
- 爱丽丝移除 2 ，得分 5 + 3 + 1 + 4 = 13 。游戏情况：爱丽丝 = 13 ，鲍勃 = 0 ，石子 = [5,3,1,4] 。
- 鲍勃移除 5 ，得分 3 + 1 + 4 = 8 。游戏情况：爱丽丝 = 13 ，鲍勃 = 8 ，石子 = [3,1,4] 。
- 爱丽丝移除 3 ，得分 1 + 4 = 5 。游戏情况：爱丽丝 = 18 ，鲍勃 = 8 ，石子 = [1,4] 。
- 鲍勃移除 1 ，得分 4 。游戏情况：爱丽丝 = 18 ，鲍勃 = 12 ，石子 = [4] 。
- 爱丽丝移除 4 ，得分 0 。游戏情况：爱丽丝 = 18 ，鲍勃 = 12 ，石子 = [] 。
得分的差值 18 - 12 = 6 。

**示例 2：**

**输入：**stones = [7,90,5,1,100,10,10,2]
**输出：**122

 

**提示：**

	- `n == stones.length`

	- `2 <= n <= 1000`

	- `1 <= stones[i] <= 1000`


## 题解


### 思路

令`dp[l][r]` 代表`stones[l...r]`的alice的分数-bob的分数。
对于面对子段`stones[l...r]`是谁的回合？注意到alice的回合所面临剩余个数的奇偶性和初始个数的奇偶性相同。
用记忆化搜索求区间dp。
alice回合状态转移 `dp[l][r] = max(pre[r+1]-pre[l+1]+dfs(l+1, r), pre[r]-pre[l]+dfs(l, r-1))`
bob回合状态转移 `dp[l][r] = min(pre[l+1]-pre[r+1]+dfs(l+1, r), pre[l]-pre[r]+dfs(l, r-1))pre[i]` 为前i个数的和。


### 代码


```cpp
class Solution {
public:
    //dp[l][r] 石头起始l到终止r的alice与bob的最佳分差。
    int dp[1005][1005];
    int pre[1005];// s[l...r] = pre[r+1]-pre[l]
    int n;
    vector<int> s;
    int dfs(int l, int r) {
        if (dp[l][r] != -1) return dp[l][r];
        if (l == r) return dp[l][r] = 0;
        if ((r-l+1)%2 == n%2) { //alice 回合
            return dp[l][r] = max(pre[r+1]-pre[l+1]+dfs(l+1, r), pre[r]-pre[l]+dfs(l, r-1));
        } else { // bob 回合
            return dp[l][r] = min(pre[l+1]-pre[r+1]+dfs(l+1, r), pre[l]-pre[r]+dfs(l, r-1));
        }
    }
    int stoneGameVII(vector<int>& stones) {
        memset(dp, -1, sizeof(dp));
        s = stones;
        n = s.size();
        for (int i=1; i<=n; i++) {
            pre[i] = pre[i-1] + s[i-1];
        }
        return dfs(0, n-1);
    }
};
```
