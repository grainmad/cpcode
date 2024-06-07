## 题目

[1040. 移动石子直到连续 II](https://leetcode.cn/problems/moving-stones-until-consecutive-ii/)

---

在一个长度 **无限** 的数轴上，第 `i` 颗石子的位置为 `stones[i]`。如果一颗石子的位置最小/最大，那么该石子被称作 **端点石子** 。

每个回合，你可以将一颗端点石子拿起并移动到一个未占用的位置，使得该石子不再是一颗端点石子。

值得注意的是，如果石子像 `stones = [1,2,5]` 这样，你将 **无法** 移动位于位置 5 的端点石子，因为无论将它移动到任何位置（例如 0 或 3），该石子都仍然会是端点石子。

当你无法进行任何移动时，即，这些石子的位置连续时，游戏结束。

要使游戏结束，你可以执行的最小和最大移动次数分别是多少？ 以长度为 2 的数组形式返回答案：`answer = [minimum_moves, maximum_moves]` 。

  

**示例 1：**

```txt
输入：[7,4,9]
输出：[1,2]
解释：
我们可以移动一次，4 -> 8，游戏结束。
或者，我们可以移动两次 9 -> 5，4 -> 6，游戏结束。
```

**示例 2：**

```txt
输入：[6,5,4,3,10]
输出：[2,3]
解释：
我们可以移动 3 -> 8，接着是 10 -> 7，游戏结束。
或者，我们可以移动 3 -> 7, 4 -> 8, 5 -> 9，游戏结束。
注意，我们无法进行 10 -> 2 这样的移动来结束游戏，因为这是不合要求的移动。
```

**示例 3：**

```txt
输入：[100,101,104,102,103]
输出：[0,0]
```
  

**提示：**

-   `3 <= stones.length <= 10^4`
-   `1 <= stones[i] <= 10^9`
-   `stones[i]` 的值各不相同。

  

## 题解

### 方法一：

#### 思路

假设共有n个石头，我们先将原先的石头位置排序。

对于最大移动步数，**几乎**就是相邻两个石头之间的空缺的位置数目。
由于每一次移动必定会使得移动的石头变为非端点，所以需要减去首两个石头之间的空缺数和末两个石头之间的空缺数的最小值。

对于最小移动步数，我们可以考虑每个长度为n的区间中已经存在了几个石头，空缺的石头数就是需要移动的步数，所有区间中需要移动的步数的最小值就是我们需要的答案。这里需要注意特殊情况，如果考虑每个石头作为区间的左端点，且区间中已存在n-1个位置且区间最右端的位置不存在，那么这种情况需要排除。

#### 代码

```cpp
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        set<int> st(stones.begin(), stones.end());
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int mx = 0;
        for (int i=1; i<n; i++) {
            mx += stones[i]-stones[i-1]-1;
        }
        mx -= min(stones[1]-stones[0]-1, stones[n-1]-stones[n-2]-1);
        int mn = n;
        for (int i=0; i<n; i++) {
            int p = lower_bound(stones.begin(), stones.end(), stones[i]+n)-stones.begin();
            //在[stones[i], stones[i]+n)间已有p-i个数，
            // cout << i << " " << p << endl;
            if (n-(p-i) != 1 || st.count(stones[i]+n-1)) mn = min(mn, n-(p-i));
        }
        return {mn, mx};
    }
};
```
