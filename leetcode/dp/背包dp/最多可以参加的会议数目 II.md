## 题目

[1851. 最多可以参加的会议数目 II](https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended-ii/)


---


给你一个 `events` 数组，其中 `events[i] = [startDay_i_, endDay_i_, value_i_]` ，表示第 `i` 个会议在 `startDay_i_`_ _天开始，第 `endDay_i_` 天结束，如果你参加这个会议，你能得到价值 `value_i_` 。同时给你一个整数 `k` 表示你能参加的最多会议数目。

你同一时间只能参加一个会议。如果你选择参加某个会议，那么你必须 **完整** 地参加完这个会议。会议结束日期是包含在会议内的，也就是说你不能同时参加一个开始日期与另一个结束日期相同的两个会议。

请你返回能得到的会议价值 **最大和** 。

 

**示例 1：**

[]

**输入：**events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
**输出：**7
**解释：**选择绿色的活动会议 0 和 1，得到总价值和为 4 + 3 = 7 。

**示例 2：**

[]

**输入：**events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
**输出：**10
**解释：**参加会议 2 ，得到价值和为 10 。
你没法再参加别的会议了，因为跟会议 2 有重叠。你 **不** 需要参加满 k 个会议。

**示例 3：**

**[]**

**输入：**events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
**输出：**9
**解释：**尽管会议互不重叠，你只能参加 3 个会议，所以选择价值最大的 3 个会议。

 

**提示：**

	- `1 <= k <= events.length`

	- `1 <= k * events.length <= 10^6^`

	- `1 <= startDay_i_ <= endDay_i_ <= 10^9^`

	- `1 <= value_i_ <= 10^6^`


## 题解


### 思路

二分优化**

我们可以将事件按照结束时间升序排序，令`begin[i]`是第`i`个事件的开始时间，`end[i]`是第`i`个时间的结束时间，`val[i]` 是第`i`个事件的价值。
这样可以利用01背包的状态模型，`dp[i][j]`代表着前i个事件中选j个的最大价值。
对于第`i`个事件的选取有选和不选两种：

- 不选第`i`个事件则最大价值为`dp[i-1][j]`
- 选择第`i`个事件则最大价值为`dp[p][j-1]+val[i]`, 其中`p`是最后一个小于`begin[i]`的位置
初始化状态`dp[0][] = dp[][0] = 0`
最后我们需要求的便是`dp[n][k]`


### 代码


```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](auto& a, auto& b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        int n = events.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        vector<int> ed(n+1, 0);
        for (int i=1; i<=n; i++) {
            ed[i] = events[i-1][1];
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=k; j++) {
                int p = lower_bound(ed.begin(), ed.end(), events[i-1][0])-ed.begin()-1;
                // cout << i << ' ' << j << " " << p << endl;
                dp[i][j] = max(dp[i-1][j], dp[p][j-1]+events[i-1][2]);
            }
        }
        return dp[n][k];
    }
};
```
