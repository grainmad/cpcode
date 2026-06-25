## 题目

[1034. K 个不同整数的子数组](https://leetcode.cn/problems/subarrays-with-k-different-integers/)


---


给定一个正整数数组 `nums`和一个整数 `k`，返回 `nums` 中 「**好子数组」*** *的数目。

如果 `nums` 的某个子数组中不同整数的个数恰好为 `k`，则称 `nums` 的这个连续、不一定不同的子数组为 **「****好子数组 」**。

	- 例如，`[1,2,3,1,2]` 中有 `3` 个不同的整数：`1`，`2`，以及 `3`。

**子数组** 是数组的 **连续** 部分。

 

**示例 1：**

**输入：**nums = [1,2,1,2,3], k = 2
**输出：**7
**解释：**恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].

**示例 2：**

**输入：**nums = [1,2,1,3,4], k = 3
**输出：**3
**解释：**恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].

 

**提示：**

	- `1 <= nums.length <= 2 * 10^4^`

	- `1 <= nums[i], k <= nums.length`


## 题解


### 思路

转化恰好k=至多k 减 至多k-1**

滑动窗口，可以解决求窗口内至多为k个不同数的子数组个数，设为$f(k)$
那么$f(k)-f(k-1)$得恰好为k个不同数的子数组个数。
巧妙的转化


### 代码


```cpp
class Solution {
public:
    int f(vector<int>& nums, int k) {
        vector<int> h(nums.size()+1);
        int tot = 0, l = 0, ans = 0;
        for (int i:nums) {
            if (h[i]++ == 0) tot++;
            while (tot>k) {
                if (--h[nums[l]] == 0) tot--;
                l++;
            }
            ans += i-l+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};
```
