## 题目

[1788. 石子游戏 VI](https://leetcode.cn/problems/stone-game-vi/)


---


Alice 和 Bob 轮流玩一个游戏，Alice 先手。

一堆石子里总共有 `n` 个石子，轮到某个玩家时，他可以 **移出** 一个石子并得到这个石子的价值。Alice 和 Bob 对石子价值有 **不一样的的评判标准** 。双方都知道对方的评判标准。

给你两个长度为 `n` 的整数数组 `aliceValues` 和 `bobValues` 。`aliceValues[i]` 和 `bobValues[i]` 分别表示 Alice 和 Bob 认为第 `i` 个石子的价值。

所有石子都被取完后，得分较高的人为胜者。如果两个玩家得分相同，那么为平局。两位玩家都会采用 **最优策略** 进行游戏。

请你推断游戏的结果，用如下的方式表示：

	- 如果 Alice 赢，返回 `1` 。

	- 如果 Bob 赢，返回 `-1` 。

	- 如果游戏平局，返回 `0` 。

 

**示例 1：**

**输入：**aliceValues = [1,3], bobValues = [2,1]
**输出：**1
**解释：**
如果 Alice 拿石子 1 （下标从 0开始），那么 Alice 可以得到 3 分。
Bob 只能选择石子 0 ，得到 2 分。
Alice 获胜。

**示例 2：**

**输入：**aliceValues = [1,2], bobValues = [3,1]
**输出：**0
**解释：**
Alice 拿石子 0 ， Bob 拿石子 1 ，他们得分都为 1 分。
打平。

**示例 3：**

**输入：**aliceValues = [2,4,3], bobValues = [1,6,7]
**输出：**-1
**解释：**
不管 Alice 怎么操作，Bob 都可以得到比 Alice 更高的得分。
比方说，Alice 拿石子 1 ，Bob 拿石子 2 ， Alice 拿石子 0 ，Alice 会得到 6 分而 Bob 得分为 7 分。
Bob 会获胜。

 

**提示：**

	- `n == aliceValues.length == bobValues.length`

	- `1 <= n <= 10^5^`

	- `1 <= aliceValues[i], bobValues[i] <= 100`


## 题解


### 思路

考虑任意两个石头$x, y$。
$x$对Alice的价值是$a_x$, 对Bob的价值是$b_x$
$y$对Alice的价值是$a_y$, 对Bob的价值是$b_y$
当Alice选择$x$，Bob选择$y$，差价为$a_x-b_y$。
当Alice选择$y$，Bob选择$x$，差价为$a_y-b_x$。
Alice先手，Alice会选择差价最大的方案。也就是$(a_x-b_y)-(a_y-b_x)$最大的。
由于$(a_x-b_y)-(a_y-b_x) = (a_x+b_x)-(a_y+b_y)$，可以按照$a_i+b_i$由大到小排序。
选取越靠前的石头堆越能最大化各个选手价值，所以Alice和Bob轮流选取即可。


### 代码


```cpp
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<int> idx(n);
        for (int i=0; i<n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return aliceValues[a]+bobValues[a] > aliceValues[b]+bobValues[b];
        });
        int x = 0, y = 0;
        for (int i=0; i<n; i++) {
            if (i%2) y += bobValues[idx[i]];
            else x += aliceValues[idx[i]];
        }
        if (x>y) return 1;
        if (x<y) return -1;
        return 0;
    }
};
```
