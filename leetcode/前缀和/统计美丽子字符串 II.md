## 题目

[2949. 统计美丽子字符串 II](https://leetcode.cn/problems/count-beautiful-substrings-ii/)

---

给你一个字符串 `s` 和一个正整数 `k` 。

用 `vowels` 和 `consonants` 分别表示字符串中元音字母和辅音字母的数量。

如果某个字符串满足以下条件，则称其为 **美丽字符串** ：

	- `vowels == consonants`，即元音字母和辅音字母的数量相等。

	- `(vowels * consonants) % k == 0`，即元音字母和辅音字母的数量的乘积能被 `k` 整除。

返回字符串 `s` 中 **非空美丽子字符串** 的数量。

子字符串是字符串中的一个连续字符序列。

英语中的** 元音字母 **为 `'a'`、`'e'`、`'i'`、`'o'` 和 `'u'` 。

英语中的** 辅音字母 **为除了元音字母之外的所有字母。

 

示例 1：

**输入：**s = "baeyh", k = 2
**输出：**2
**解释：**字符串 s 中有 2 个美丽子字符串。
- 子字符串 "b**aeyh**"，vowels = 2（["a","e"]），consonants = 2（["y","h"]）。
可以看出字符串 "aeyh" 是美丽字符串，因为 vowels == consonants 且 vowels * consonants % k == 0 。
- 子字符串 "**baey**h"，vowels = 2（["a","e"]），consonants = 2（["b","y"]）。
可以看出字符串 "baey" 是美丽字符串，因为 vowels == consonants 且 vowels * consonants % k == 0 。
可以证明字符串 s 中只有 2 个美丽子字符串。

示例 2：

**输入：**s = "abba", k = 1
**输出：**3
**解释：**字符串 s 中有 3 个美丽子字符串。
- 子字符串 "**ab**ba"，vowels = 1（["a"]），consonants = 1（["b"]）。
- 子字符串 "ab**ba**"，vowels = 1（["a"]），consonants = 1（["b"]）。
- 子字符串 "**abba**"，vowels = 2（["a","a"]），consonants = 2（["b","b"]）。
可以证明字符串 s 中只有 3 个美丽子字符串。

示例 3：

**输入：**s = "bcdf", k = 1
**输出：**0
**解释：**字符串 s 中没有美丽子字符串。

 

**提示：**

	- `1 <= s.length <= 5 * 10^4^`

	- `1 <= k <= 1000`

	- `s` 仅由小写英文字母组成。

## 题解

### 方法一：

#### 思路

符合条件的子串满足：
* 子串元音辅音字符个数都相同。这一点可以将元音设为1，辅音设为-1。求前缀和数组$ps$，当$ps_i = ps_j, i<j$时，$[i+1,j]$这个子串元辅音个数相同，所以只需要哈希统计前缀和出现的次数。
* 元辅音字符乘积是$k$的倍数。由于元辅音个数相同，对于合法子串长度为$L$，$rac{L^2}{4} mod k = 0 \Rightarrow L^2 mod 4k = 0 \Rightarrow L mod r = 0$，对于$r$的计算，将$4k$进行质因数分解得到$4k = p_1^{e_{1}}p_2^{e_{2}}\cdots p_n^{e_{n}}$，$p_i$是第$i$个质数，$e_i$是$p_i$出现次数。$r = p_1^{\lceil rac{e_{1}}{2} ceil}p_2^{\lceil rac{e_{2}}{2} ceil}\cdots p_n^{\lceil rac{e_{n}}{2} ceil}$。我们记录当前下标$imod r$，当存在$i mod r = j mod r, i<j$时，说明$[i+1,j]$子串长度是$r$的倍数，所以只需要哈希统计$imod r$出现的次数。

我们需要哈希表同时统计前缀和与下标模$r$。

若当前遍历到下标$i$，查询以$i$作为右端点的所有合法子串数目，只需在哈希表中查找二元组$(ps_i, i mod k)$的个数。i下标也可做左端点，所以$(ps_i, i mod k)$在哈希表中的统计次数加1。

#### 代码

```C++
class Solution {
public:
    using ll = long long;
    long long beautifulSubstrings(string s, int k) {
        vector<int> c(256, -1);
        for (char i:"aeiou"s) c[i] = 1;
        map<pair<int,int>,int> mp;
        int r = 1;
        k *= 4;
        for (int i=2; i*i<=k; i++) {
            int cnt = 0;
            while (k%i == 0) k/=i, cnt++;
            for (int j=0; j<(cnt+1)/2; j++) r *= i;
        }
        r *= k;
        long long ans = 0;
        int ps = 0, idx = 0;
        mp[{r-1, 0}] = 1;
        for (char i:s) {
            ps += c[i];
            ans += mp[{idx%r, ps}]++;
            idx++;
        }
        return ans;
    }
};
```
