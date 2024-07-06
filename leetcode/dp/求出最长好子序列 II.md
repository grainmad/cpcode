## 题目

[求出最长好子序列 II](https://leetcode.cn/problems/find-the-maximum-length-of-a-good-subsequence-ii/)

---

给你一个整数数组 `nums` 和一个 **非负**  整数 `k` 。如果一个整数序列 `seq` 满足在范围下标范围 `[0, seq.length -
2]` 中存在 **不超过**  `k` 个下标 `i` 满足 `seq[i] != seq[i + 1]` ，那么我们称这个整数序列为 **好**
序列。

请你返回 `nums` 中 **好** 子序列 的最长长度



**示例 1：**

**输入：** nums = [1,2,1,1,3], k = 2

**输出：** 4

**解释：**

最长好子序列为 `[_**1**_ ,_**2**_ ,**_1_** ,_**1**_ ,3]` 。

**示例 2：**

**输入：** nums = [1,2,3,4,5,1], k = 0

**输出：** 2

**解释：**

最长好子序列为 `[**_1_** ,2,3,4,5,**_1_**]` 。



**提示：**

  * `1 <= nums.length <= 5 * 10^3`
  * `1 <= nums[i] <= 10^9`
  * `0 <= k <= min(50, nums.length)`



## 题解

### 方法一:

#### 思路

划分型动态规划

设$f_{i,j}$为前i个数划出现j个不等的位置，包含了第i个数，最长的序列。

$f_{i,j} = \max \left \lbrace  \begin{array}{ll} f_{t,j-1}+1 & t<i \wedge nums_{i} \ne nums_{t} \\\\ f_{t,j}+1 & t<i \wedge nums_{i} = nums_{t} \end{array} \right .$

复杂度$O(n^2k)$，考虑优化。

我们维护前缀中的最大值$s_{i,j} = \max \lbrace s_{i-1,j}, f_{i, j} \rbrace$，对于$nums_i \ne nums_t$的情况，实际上可以从$s_{i-1, j-1}+1$转移。即使前缀中维护的最大值$f_{t,j}$其$nums_t = nums_i$，由于$f_{t,j-1} < f_{t,j}$，在$nums_i = nums_t$的情况下会得到更优的答案。而在$nums_i = nums_t$的情况，我们只需维护前缀中以$nums_i$结尾的最大值$mx_{nums_i, j}$。


$f_{i,j} = \max \left \lbrace  \begin{array}{l} s_{i-1,j-1}+1 \\\\ mx_{nums_i,j}+1  \end{array} \right .$

我们可以消去$f_{i,j}$，$s_{i,j}$的含义为前i个数划出现j个不等的位置，最长的序列。

$s_{i,j} = \max \left \lbrace  \begin{array}{l} s_{t,j-1}+1 \\\\ mx_{nums_i,j}+1 \\\\ s_{i-1,j} \end{array} \right .$

答案是$\max \limits_{0\le i\le k}s_{n, i}$

#### 代码

``` cpp

template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p) {
    return os<<'['<<p.first<<", "<<p.second<<']';
}
template<class t> ostream& operator<<(ostream& os,const vector<t>& v) {
    os<<'['; int s = 1;
    for(auto e:v) { if (s) s = 0; else os << ", "; os << e; }
    return os<<']';
}
template<class t,class u> ostream& operator<<(ostream& os,const map<t,u>& mp){
    os<<'{'; int s = 1;
    for(auto [x,y]:mp) { if (s) s = 0; else os << ", "; os<<x<<": "<<y; }
    return os<<'}';
}
class Solution {
public:
    const int NINF = 0xf3f3f3f3;
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        // vector f(n, vector<int>(k+1, NINF));
        int f[n][k+2], s[n][k+2];
        memset(f, 0xf3, sizeof(f));
        memset(s, 0xf3, sizeof(s));
        f[0][0] = s[0][0] = 1;
        vector mx(k+1, map<int,int>());
        mx[0][nums[0]] = 1;
        for (int i=1; i<n; i++) {
            for (int j=0; j<=k; j++) {
                f[i][j] = max(f[i][j], mx[j][nums[i]]+1);
                if (j>0) f[i][j] = max(f[i][j], s[i-1][j-1]+1);
                mx[j][nums[i]] = max(mx[j][nums[i]], f[i][j]);
                s[i][j] = max(s[i-1][j], f[i][j]);
            }
        }
        int ans = 0;
    
        for (int j=0; j<=k; j++) {
            // cout << i << ", " << j << " = " << f[i][j] << endl;
            ans = max(ans, s[n-1][j]);
        }
        // cout << f << endl;
        return ans;
    }
};
```

``` cpp

template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p) {
    return os<<'['<<p.first<<", "<<p.second<<']';
}
template<class t> ostream& operator<<(ostream& os,const vector<t>& v) {
    os<<'['; int s = 1;
    for(auto e:v) { if (s) s = 0; else os << ", "; os << e; }
    return os<<']';
}
template<class t,class u> ostream& operator<<(ostream& os,const map<t,u>& mp){
    os<<'{'; int s = 1;
    for(auto [x,y]:mp) { if (s) s = 0; else os << ", "; os<<x<<": "<<y; }
    return os<<'}';
}
class Solution {
public:
    const int NINF = 0xf3f3f3f3;
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        // vector f(n, vector<int>(k+1, NINF));
        int s[n][k+2];
        memset(s, 0xf3, sizeof(s));
        s[0][0] = 1;
        vector mx(k+1, map<int,int>());
        mx[0][nums[0]] = 1;
        for (int i=1; i<n; i++) {
            for (int j=0; j<=k; j++) {
                s[i][j] = max(s[i][j], mx[j][nums[i]]+1);
                if (j>0) s[i][j] = max(s[i][j], s[i-1][j-1]+1);
                mx[j][nums[i]] = max(mx[j][nums[i]], s[i][j]);
                s[i][j] = max(s[i-1][j], s[i][j]);
            }
        }
        int ans = 0;
    
        for (int j=0; j<=k; j++) {
            // cout << i << ", " << j << " = " << f[i][j] << endl;
            ans = max(ans, s[n-1][j]);
        }
        // cout << f << endl;
        return ans;
    }
};
```
