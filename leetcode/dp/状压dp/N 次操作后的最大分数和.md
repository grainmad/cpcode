## 题目

[1906. N 次操作后的最大分数和](https://leetcode.cn/problems/maximize-score-after-n-operations/)


---


给你 `nums` ，它是一个大小为 `2 * n` 的正整数数组。你必须对这个数组执行 `n` 次操作。

在第 `i` 次操作时（操作编号从 **1** 开始），你需要：

	- 选择两个元素 `x` 和 `y` 。

	- 获得分数 `i * gcd(x, y)` 。

	- 将 `x` 和 `y` 从 `nums` 中删除。

请你返回 `n` 次操作后你能获得的分数和最大为多少。

函数 `gcd(x, y)` 是 `x` 和 `y` 的最大公约数。

 

**示例 1：**

**输入：**nums = [1,2]
**输出：**1
**解释：**最优操作是：
(1 * gcd(1, 2)) = 1

**示例 2：**

**输入：**nums = [3,4,6,8]
**输出：**11
**解释：**最优操作是：
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11

**示例 3：**

**输入：**nums = [1,2,3,4,5,6]
**输出：**14
**解释：**最优操作是：
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14

 

**提示：**

	- `1 <= n <= 7`

	- `nums.length == 2 * n`

	- `1 <= nums[i] <= 10^6^`


## 题解


### 思路

二进制技巧**

状态压缩dp
设`dp[i][j]`为第i次选择后，所选的`2*i`个数的集合为j。
对于已知的`dp[i][j]`考虑从当前向后转移，那么选择两个不在j集合中的数x和y加入到j中得到集合c，状态转移`dp[i+1][c] = max(dp[i+1][c], dp[i][j]+i*gcd(x,y)`

由于j集合中含有数的个数/2=i，所以可以去掉一维数组。需要计算转移时是第几次转移。


### 代码


```cpp
class Solution {
public:
    int cntbits(int x) {
        int rt = 0;
        for (;x;x=x&(x-1)) rt++;
        return rt;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(1<<n, 0);
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                dp[1<<i|1<<j] = __gcd(nums[i], nums[j]);
            }
        }
        for (int i=0; i<1<<n; i++) {
            int b = cntbits(i);
            if (b%2) continue;
            for (int j=i; j; j=i&(j-1)) {//枚举子集
                if (b == cntbits(j)+2) {
                    dp[i] = max(dp[j]+b/2*dp[i^j], dp[i]);
                }
            }
        }
        return dp[(1<<n)-1];
    }
};
```
