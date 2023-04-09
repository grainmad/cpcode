## 题目

[1201. 丑数 III](https://leetcode.cn/problems/ugly-number-iii/)

---

给你四个整数：`n` 、`a` 、`b` 、`c` ，请你设计一个算法来找出第 `n` 个丑数。

丑数是可以被 `a` **或** `b` **或** `c` 整除的 **正整数** 。

  

**示例 1：**

```txt
输入：n = 3, a = 2, b = 3, c = 5
输出：4
解释：丑数序列为 2, 3, 4, 5, 6, 8, 9, 10... 其中第 3 个是 4。
```

**示例 2：**

```txt
输入：n = 4, a = 2, b = 3, c = 4
输出：6
解释：丑数序列为 2, 3, 4, 6, 8, 9, 10, 12... 其中第 4 个是 6。
```

**示例 3：**

```txt
输入：n = 5, a = 2, b = 11, c = 13
输出：10
解释：丑数序列为 2, 4, 6, 8, 10, 11, 12, 13... 其中第 5 个是 10。
```

**示例 4：**

```txt
输入：n = 1000000000, a = 2, b = 217983653, c = 336916467
输出：1999999984
```
  

**提示：**

-   `1 <= n, a, b, c <= 10^9`
-   `1 <= a * b * c <= 10^18`
-   本题结果在 `[1, 2 * 10^9]` 的范围内

  

## 解题

### 方法一：

#### 思路

我们令函数f(x)为不大于x的丑数个数。可见x越大丑数不会减小，f(x)是非递减的。
于是可以对f(x)二分查找，找到第一个大于等于n的数便是答案。

但是如何寻找不大于x的丑数个数呢？

答案是$\lfloor \frac{x}{a} \rfloor + \lfloor \frac{x}{b} \rfloor + \lfloor \frac{x}{c} \rfloor - \lfloor \frac{x}{lcm(a,b)} \rfloor - \lfloor \frac{x}{lcm(b,c} \rfloor - \lfloor \frac{x}{lcm(a,c)} \rfloor + \lfloor \frac{x}{lcm(a,b,c)} \rfloor$, 在小于x的a的倍数和b的倍数中a和b的公倍数是重复的需要减去，b和c，a和c都同理。但是对于a，b和c的公倍数实际上a，b与c的倍数之和总共是加了三次，而两两之间的公倍数又恰好减去了三次，我们需要再加一次保证每个数都只出现一次。这就是容斥原理。

#### 代码

```cpp
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long l = 0, r = 2e9+7;
        while (l<r) {
            long m = l+r>>1;
            if (m/a+m/b+m/c-m/lcm(a,b)-m/lcm(a,c)-m/lcm(b,c)+m/lcm(a, lcm(b, c)) < n) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return r;
    }
};
```
