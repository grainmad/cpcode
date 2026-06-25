## 题目

[1240. 石子游戏 II](https://leetcode.cn/problems/stone-game-ii/)


---


Alice 和 Bob 继续他们的石子游戏。许多堆石子 **排成一行**，每堆都有正整数颗石子 `piles[i]`。游戏以谁手中的石子最多来决出胜负。

Alice 和 Bob 轮流进行，Alice 先开始。最初，`M = 1`。

在每个玩家的回合中，该玩家可以拿走剩下的 **前** `X` 堆的所有石子，其中 `1 <= X <= 2M`。然后，令 `M = max(M, X)`。

游戏一直持续到所有石子都被拿走。

假设 Alice 和 Bob 都发挥出最佳水平，返回 Alice 可以得到的最大数量的石头。

 

**示例 1：**

**输入：**piles = [2,7,9,4,4]
**输出：**10
**解释：**如果一开始 Alice 取了一堆，Bob 取了两堆，然后 Alice 再取两堆。Alice 可以得到 2 + 4 + 4 = 10 堆。
如果 Alice 一开始拿走了两堆，那么 Bob 可以拿走剩下的三堆。在这种情况下，Alice 得到 2 + 7 = 9 堆。返回 10，因为它更大。

**示例 2:**

**输入：**piles = [1,2,3,4,5,100]
**输出：**104

 

**提示：**

	- `1 <= piles.length <= 100`

	- `1 <= piles[i] <= 10^4^`


## 题解


### 思路

`dp[i][j][k]` , 轮次i，剩余石子首位置j，最大可取2k，当前选手与另一位选手的最大差值。
博弈重要状态参数：轮次
但是这里也可以省去，只需要区分alice和bob就行，因为alice和bob可以遇到相同的剩余石头状态。但是同一玩家不会遇到两次剩余相同的石头状态。
所以优化后状态为：
`dp[i][j][k]` , 玩家i（i=0，alice，i=1，bob），剩余石子首位置j，最大可取2k，当前选手与另一位选手的最大差值。
实际上Alice和Bob都不用区分，由于M的存在，当Alice和bob面对相同数量剩余石子时，M必定不同，当Alice和Bob的M相同时剩余石子数不同。所以dp状态可以优化为：
dp[j][k] , 剩余石子首位置j，最大可取2k，当前选手与另一位选手的最大差值。这里的`dp[j][k]`两个玩家只有一个会遇到。

状态值=与对手的差值


### 代码


```cpp
class Solution {
public:
    const int INF = 0x3f3f3f3f;
    vector<int> s; int n;
    int dp[2][105][205]; // dp[i][j][k] 选手i面对剩余[j...n-1]堆石头时最多能拿k堆的最佳差值
    int dfs(int p, int l, int m) {
        if (l == n) return 0;
        if (dp[p][l][m] != INF) return dp[p][l][m];
        dp[p][l][m] = p?INF:-INF;
        int c = 0;
        for (int i=l; i<min(l+2*m, n); i++) {
            c += s[i];
            dp[p][l][m] = p?
            min(dp[p][l][m], dfs(0, i+1, max(m, i-l+1))-c)
            :max(dp[p][l][m], dfs(1, i+1, max(m, i-l+1))+c);
        }
        return dp[p][l][m];
    }
    int stoneGameII(vector<int>& piles) {
        s = piles; n = piles.size();
        memset(dp, 0x3f, sizeof(dp));
        int sum = accumulate(piles.begin(), piles.end(), 0);
        return (sum+dfs(0, 0, 1))/2;
    }
};
```
