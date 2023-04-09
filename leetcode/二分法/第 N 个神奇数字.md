## 题目

[878. 第 N 个神奇数字](https://leetcode.cn/problems/nth-magical-number/)

---

一个正整数如果能被 `a` 或 `b` 整除，那么它是神奇的。

给定三个整数 `n` , `a` , `b` ，返回第 `n` 个神奇的数字。因为答案可能很大，所以返回答案 **对** `10^9 + 7` **取模** 后的值。

  

**示例 1：**

```txt
输入：n = 1, a = 2, b = 3
输出：2
```

**示例 2：**

```txt
输入：n = 4, a = 2, b = 3
输出：6
```
  

**提示：**

-   `1 <= n <= 10^9`
-   `2 <= a, b <= 4 * 10^4`

  

## 解题

### 方法一：

#### 思路

现在枚举一个数x

对于小于等于x的a的倍数有$p1=\lfloor \frac{x}{a} \rfloor$

对于小于等于x的b的倍数有$p2=\lfloor \frac{x}{b} \rfloor$

对于小于等于x的既是a的倍数也是b的倍数有$p3=\lfloor \frac{x}{lcm(a,b)} \rfloor$

p1+p2重复计算了一次p3

所以令f(x)为小于等于x的a或b的倍数的个数。f(x)=p1+p2-p3。

显然f(x)具有单调性。

我们可以二分找到第一个满足f(x)>=n的x。

#### 代码

```cpp
class Solution {
public:
    using ll = long long;
    int nthMagicalNumber(int n, int a, int b) {
        ll l = 1, r = 1e18;
        while (l<r) {
            ll m = (r-l)/2+l;
            ll k = m/a+m/b-m/lcm(a,b);
            if (k<n) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return r%(int(1e9+7));
    }
};
```
