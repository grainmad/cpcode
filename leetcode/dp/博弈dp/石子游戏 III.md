## 题目

[1522. 石子游戏 III](https://leetcode.cn/problems/stone-game-iii/)


---


Alice 和 Bob 继续他们的石子游戏。几堆石子 **排成一行** ，每堆石子都对应一个得分，由数组 `stoneValue` 给出。

Alice 和 Bob 轮流取石子，**Alice** 总是先开始。在每个玩家的回合中，该玩家可以拿走剩下石子中的的前 **1、2 或 3 堆石子** 。比赛一直持续到所有石头都被拿走。

每个玩家的最终得分为他所拿到的每堆石子的对应得分之和。每个玩家的初始分数都是 **0** 。

比赛的目标是决出最高分，得分最高的选手将会赢得比赛，比赛也可能会出现平局。

假设 Alice 和 Bob 都采取 **最优策略** 。

如果 Alice 赢了就返回 `"Alice"` *，*Bob 赢了就返回* *`"Bob"`*，*分数相同返回 `"Tie"` 。

 

**示例 1：**

**输入：**values = [1,2,3,7]
**输出：**"Bob"
**解释：**Alice 总是会输，她的最佳选择是拿走前三堆，得分变成 6 。但是 Bob 的得分为 7，Bob 获胜。

**示例 2：**

**输入：**values = [1,2,3,-9]
**输出：**"Alice"
**解释：**Alice 要想获胜就必须在第一个回合拿走前三堆石子，给 Bob 留下负分。
如果 Alice 只拿走第一堆，那么她的得分为 1，接下来 Bob 拿走第二、三堆，得分为 5 。之后 Alice 只能拿到分数 -9 的石子堆，输掉比赛。
如果 Alice 拿走前两堆，那么她的得分为 3，接下来 Bob 拿走第三堆，得分为 3 。之后 Alice 只能拿到分数 -9 的石子堆，同样会输掉比赛。
注意，他们都应该采取 **最优策略 **，所以在这里 Alice 将选择能够使她获胜的方案。

**示例 3：**

**输入：**values = [1,2,3,6]
**输出：**"Tie"
**解释：**Alice 无法赢得比赛。如果她决定选择前三堆，她可以以平局结束比赛，否则她就会输。

 

**提示：**

	- `1 <= stoneValue.length <= 5 * 10^4^`

	- `-1000 <= stoneValue[i] <= 1000`


## 题解


### 思路

令`dp[i][j]`为从`s[i...n-1]`且j先手的**最佳分差**(Alice分数-Bob分数，Alice会努力使分数大，Bob会努力使分数小)
若j=0为Alice
`dp[i][0] = max(dp[i][0], dp[i+k+1][1]+sum(s[i..i+k])`
若j=1为Bob
`dp[i][1] = min(dp[i][1], dp[i+k+1][0]-sum(s[i..i+k])`


### 代码


```cpp
class Solution {
public:
    const int INF = 0x3f3f3f3f;
    vector<int> s;
    int n;
    int dp[50005][2];
    int dfs(int pos, int who) {
        if (dp[pos][who] != INF) return dp[pos][who];
        if (pos == n) return dp[pos][who] = 0;
        if (who) { //bob
            for (int i=0, c=0; i<3 && i+pos<n; i++) {
                c += s[i+pos];
                dp[pos][who] = min(dp[pos][who], dfs(pos+i+1, 0)-c);
            }
        } else { //alice 
            dp[pos][who] = -dp[pos][who];
            for (int i=0, c=0; i<3 && i+pos<n; i++) {
                c += s[i+pos];
                dp[pos][who] = max(dp[pos][who], dfs(pos+i+1, 1)+c);
            }
        }
        return dp[pos][who];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        s = stoneValue;
        n = s.size();
        memset(dp, 0x3f, sizeof(dp));
        int dif = dfs(0, 0);
        if (dif > 0) return "Alice";
        if (dif < 0) return "Bob";
        return "Tie";
    }
};
```
