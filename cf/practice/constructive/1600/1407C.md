# C. Chocolate Bunny 1407C
https://codeforces.com/problemset/problem/1407/C



## 题意

交互题，有一个隐藏的排列p，最多`2n`次查询，每次查询选择i和j，（1<=i,j<=n）,可以得到$p_i\%p_j$的值，求p。

## 题解

一个重要的性质就是若$a < b$，则$a\%b > b\%a$。
由此我们可以`2n-2`次找到最大值的下标`mx`，显然$P_{mx} = n$。
在求mx过程中，若$p_i < p_j$，可以让$p_i=p_i\%p_j$

## 代码

``` cpp
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

/*
a<b
a%b > b%a
get a

*/

void sol() {
    int n;
    cin >> n;
    vector<int> p(n + 1, n);
    int mx = 1;
    for (int i = 2; i <= n; i++) {
        int x, y;
        cout << "? " << mx << " " << i << endl;
        cin >> x;  // x = p[mx]%p[i]
        cout << "? " << i << " " << mx << endl;
        cin >> y;     // y = p[i]%p[mx]
        if (x > y) {  // p[mx] < p[i]
            p[mx] = x;
            mx = i;
        } else {  // p[mx] > p[i]
            p[i] = y;
        }
    }
    cout << "!";
    for (int i = 1; i <= n; i++)
        cout << " " << p[i];
    cout << "\n";
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