## 题目

[1403. 分割回文串 III](https://leetcode.cn/problems/palindrome-partitioning-iii/)


---


给你一个由小写字母组成的字符串 `s`，和一个整数 `k`。

请你按下面的要求分割字符串：

	- 首先，你可以将 `s` 中的部分字符修改为其他的小写英文字母。

	- 接着，你需要把 `s` 分割成 `k` 个非空且不相交的子串，并且每个子串都是回文串。

请返回以这种方式分割字符串所需修改的最少字符数。

 

**示例 1：**

**输入：**s = "abc", k = 2
**输出：**1
**解释：**你可以把字符串分割成 "ab" 和 "c"，并修改 "ab" 中的 1 个字符，将它变成回文串。

**示例 2：**

**输入：**s = "aabbc", k = 3
**输出：**0
**解释：**你可以把字符串分割成 "aa"、"bb" 和 "c"，它们都是回文串。

**示例 3：**

**输入：**s = "leetcode", k = 8
**输出：**0

 

**提示：**

	- `1 <= k <= s.length <= 100`

	- `s` 中只含有小写英文字母。


## 题解


### 思路

令`sp[i][j] 为子字符串i到j需要改变的字符`
令`dp[i][j] 前i个字符分成j段需要改变的最少字符数`
则`dp[i][j] = min(dp[i][j], dp[k][j-1]+sp[k][i-1], k∈[j-1, i-1]`
初始值, `dp[0][0] = 0`
时间复杂度$O(n^3)$


### 代码


```cpp
class Solution {
public:
    #define INF 0x3f3f3f3f
    int dp[105][105];
    string s;
    int pld(int l, int r) {
        int rt = 0;
        while (l<r) {
            rt += s[l++]!=s[r--];
        }
        return rt;
    }
    int dfs(int p, int k) {
        if (dp[p][k] != INF) return dp[p][k];
        if (k == 1) dp[p][k] = pld(0, p);
        else for (int i=k-2; i<p; i++) {
            dp[p][k] = min(dp[p][k], dfs(i, k-1)+pld(i+1, p));
        }
        return dp[p][k];
    }
    int palindromePartition(string s, int k) {
        this->s = s;
        memset(dp, 0x3f, sizeof(dp));
        dfs(s.size()-1, k);
        // for (int i=0; i<s.size(); i++) {
        //     for (int j=1; j<=k; j++) {
        //         cout << dp[i][j] << " ";
        //     } cout  << endl;
        // }
        return dfs(s.size()-1, k);
    }
};
```
