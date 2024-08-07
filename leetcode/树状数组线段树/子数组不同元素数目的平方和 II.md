## 题目

[2916. 子数组不同元素数目的平方和 II](https://leetcode.cn/problems/subarrays-distinct-element-sum-of-squares-ii/description/)

---

给你一个下标从 **0** 开始的整数数组 `nums` 。

定义 `nums` 一个子数组的 **不同计数** 值如下：

-   令 `nums[i..j]` 表示 `nums` 中所有下标在 `i` 到 `j` 范围内的元素构成的子数组（满足 `0 <= i <= j < nums.length` ），那么我们称子数组 `nums[i..j]` 中不同值的数目为 `nums[i..j]` 的不同计数。

请你返回 `nums` 中所有子数组的 **不同计数** 的 **平方** 和。

由于答案可能会很大，请你将它对 `10^9 + 7` **取余** 后返回。

子数组指的是一个数组里面一段连续 **非空** 的元素序列。

  

**示例 1：**

```txt
输入：nums = [1,2,1]
输出：15
解释：六个子数组分别为：
[1]: 1 个互不相同的元素。
[2]: 1 个互不相同的元素。
[1]: 1 个互不相同的元素。
[1,2]: 2 个互不相同的元素。
[2,1]: 2 个互不相同的元素。
[1,2,1]: 2 个互不相同的元素。
所有不同计数的平方和为 12 + 12 + 12 + 22 + 22 + 22 = 15 。
```

**示例 2：**

```txt
输入：nums = [2,2]
输出：3
解释：三个子数组分别为：
[2]: 1 个互不相同的元素。
[2]: 1 个互不相同的元素。
[2,2]: 1 个互不相同的元素。
所有不同计数的平方和为 12 + 12 + 12 = 3 。
```
  

**提示：**

-   `1 <= nums.length <= 10^5`
-   `1 <= nums[i] <= 10^5`

  

## 题解

### 方法一：

#### 思路


对于子数组中值不同的个数为x，求所有子数组的x的平方和。

设$f_{l,r}$为区间`[l,r]`中不同值的个数。答案是$\sum \limits_{r=0}^{n-1}\sum \limits_{l=0}^{r} f_{l,r}^2$。

我们先考虑简单的版本$\sum \limits_{r=0}^{n-1}\sum \limits_{l=0}^{r} f_{l,r}$

我们考虑固定右端点的所有子数组不同值的个数。看右端点增大时有什么规律。

已知$\sum \limits_{i=0}^{r} f_{i,r}$，求$\sum \limits_{i=0}^{r+1} f_{i,r+1}$

假设`nums[r+1]`最近出现的下标是`t`，我们发现从下标`t+1`到`r+1`作为子数组的左端点，`r+1`作为右端点。相对于`r`作为右端点，都新增了一个从未出现的数。

对于下标`r+1`只需要用线段树让区间`[t+1, r+1]`的增长1，然后求区间`[0,r+1]`的总和。这就是以`r+1`作为右端点的贡献。所有下标作为右端点的贡献累加起来就得到了$\sum \limits_{r=0}^{n-1}\sum \limits_{l=0}^{r} f_{l,r}$。

我们要求$\sum \limits_{r=0}^{n-1}\sum \limits_{l=0}^{r} f_{l,r}^2$。

对于一个区间内的数都增长k，其平方和如何计算呢？
$\sum \limits_{i=l}^{r} (a_i+k)^2 = \sum \limits_{i=l}^{r} a_i^2 + 2k\sum \limits_{i=l}^{r} a_i + (r-l+1) k^2$

我们只需用线段树维护区间和以及区间平方和，利用以上公式进行更新即可。

#### 代码

```C++

class Solution {
public:
    #define N 100005
    #define ll long long
    const ll MOD = 1e9+7;
    int lst[N];

    struct Seg{
        int l, r;
        ll val1, val2, tag;
    } seg[N<<2];

    void push_up(Seg& u, const Seg& l, const Seg& r) {
        u.val1 = l.val1 + r.val1;
        u.val2 = l.val2 + r.val2;
    }

    void opt(Seg& u, ll k) {
        ll len = u.r-u.l+1;
        u.val2 += 2*k*u.val1%MOD + k*k%MOD*len%MOD;
        u.val2 %= MOD;
        u.val1 += len*k%MOD;
        u.val1 %= MOD;
    }

    // 将当前区间的懒标记，作用到左右区间（改变区间值），并将标记传递给子区间（累加，子区间可能存在未传递的懒标记），删除当前区间的懒标记。
    void push_down(Seg& u, Seg& l, Seg& r) { 
        opt(l, u.tag);
        opt(r, u.tag);
        l.tag += u.tag; l.tag %= MOD;
        r.tag += u.tag; r.tag %= MOD;
        u.tag = 0;
    }

    void seg_build(int id, int l, int r) {
        seg[id].l = l; seg[id].r = r;
        seg[id].val1 = seg[id].val2 = seg[id].tag = 0;
        if (l == r) {
            // seg[id].val = a[l];
            // cin >> seg[id].val;
            return ;
        }
        int m = l+r>>1;
        seg_build(id<<1, l, m);
        seg_build(id<<1|1, m+1, r);
        push_up(seg[id], seg[id<<1], seg[id<<1|1]);
    }

    void seg_update(int id, int l, int r, ll val) {
        if (l <= seg[id].l && seg[id].r <= r) {
            opt(seg[id], val);
            seg[id].tag += val; seg[id].tag %= MOD;
            return ;
        }
        push_down(seg[id], seg[id<<1], seg[id<<1|1]);
        int m = seg[id].l + seg[id].r >> 1;
        if (l <= m) seg_update(id<<1, l, r, val);
        if (m < r) seg_update(id<<1|1, l, r, val);
        push_up(seg[id], seg[id<<1], seg[id<<1|1]);
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        seg_build(1, 0, n-1);
        memset(lst, -1, sizeof(lst));
        ll ans = 0;
        for (int i=0; i<n; i++) {
            seg_update(1, lst[nums[i]]+1, i, 1);
            lst[nums[i]] = i;
            ans += seg[1].val2;
            ans %= MOD;
        }
        return ans;
    }
};
```
