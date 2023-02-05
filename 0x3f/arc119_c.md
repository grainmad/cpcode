# C - ARC Wrecker 2

https://atcoder.jp/contests/arc119/tasks/arc119_c

## 题意

给出n个数，多少个满足的区间`[l,r]`。

区间`[l,r]`中的数可以操作任意次：选择两个相邻的数同时+1或-1。最终需要满足区间`[l,r]`全为0.

## 题解

我们发现在区间`[l,r]`上如果可以全为0，则奇数位置的数之和与偶数位置的数之和相等。
我们不妨让n个数奇数位置赋值为相反数。
接下来就是转化成求区间和为0的子区间。
哈希表记录前缀和即可。

## 代码

``` cpp
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 300005
#define MOD 998244353
using namespace std;

int a[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 2)
            a[i] = -a[i];
    }
    map<ll, int> mp;
    mp[0] = 1;
    ll ans = 0;
    for (ll i = 0, p = 0; i < n; i++) {
        p += a[i];
        if (mp.count(p))
            ans += mp[p];
        mp[p]++;
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef SINGLE_INPUT
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
#else
    sol();
#endif
    return 0;
}
```