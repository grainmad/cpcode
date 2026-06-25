## 题目

[938. 最大为 N 的数字组合](https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/)


---


给定一个按 **非递减顺序** 排列的数字数组 `digits` 。你可以用任意次数 `digits[i]` 来写的数字。例如，如果 `digits = ['1','3','5']`，我们可以写数字，如 `'13'`, `'551'`, 和 `'1351315'`。

返回 *可以生成的小于或等于给定整数 `n` 的正整数的个数* 。

 

**示例 1：**

**输入：**digits = ["1","3","5","7"], n = 100
**输出：**20
**解释：**
可写出的 20 个数字是：
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.

**示例 2：**

**输入：**digits = ["1","4","9"], n = 1000000000
**输出：**29523
**解释：**
我们可以写 3 个一位数字，9 个两位数字，27 个三位数字，
81 个四位数字，243 个五位数字，729 个六位数字，
2187 个七位数字，6561 个八位数字和 19683 个九位数字。
总共，可以使用D中的数字写出 29523 个整数。

**示例 3:**

**输入：**digits = ["7"], n = 8
**输出：**1

 

**提示：**

	- `1 <= digits.length <= 9`

	- `digits[i].length == 1`

	- `digits[i]` 是从 `'1'` 到 `'9'` 的数

	- `digits` 中的所有值都 **不同** 

	- `digits` 按 **非递减顺序** 排列

	- `1 <= n <= 10^9^`


## 题解


### 思路

数位dp，每一位的选值必须在digits中。
`dp[p][limit][zero]`代表符合条件的个数，其中p代表着0到p-1这前p位已经确定好了而p及之后的位数任意取合法的值，limit代表构造的前p位是否为n的一个前缀，zero代表构造的前p位是否都是0。


### 代码


```cpp
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n); 
        int dp[11][2][2]; memset(dp, -1, sizeof(dp));
        function<int(int,int,int)> dfs = [&](int p, int limit, int zero) {
            if (p == s.size()) return 1-zero;
            if (dp[p][limit][zero] != -1) return dp[p][limit][zero];
            dp[p][limit][zero] = 0;
            if (zero) dp[p][limit][zero] += dfs(p+1, 0, 1);
            int lb = (zero&&digits[0][0]=='0')?1:0, ub = -1;
            for (int i=0; i<digits.size(); i++) if (limit == 0 || digits[i][0] <= s[p]) ub = i;
            for (int i=lb; i<=ub; i++) {
                dp[p][limit][zero] += dfs(p+1, limit&&digits[i][0]==s[p], 0);
            }
            return dp[p][limit][zero];
        };
        return dfs(0, 1, 1);
    }
};
```
