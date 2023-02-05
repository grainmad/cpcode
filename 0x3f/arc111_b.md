# B - Reversible Cards
https://atcoder.jp/contests/arc111/tasks/arc111_b

## 题意

有n对数，每次只能从中选取一个数。求最多能多少个不同的数。

## 题解

数对之间的视为建立一条边。

考虑每个连通块的贡献，检查每个连通块是否有环。

有环则连通块中的节点数是贡献。

无环则连通块中点数-1为贡献。

## 代码

``` cpp
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 400005
#define MOD 998244353
using namespace std;

vector<int> g[N];
int vis[N];

bool is_circle(int u, int fa) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (v == fa)
            continue;
        if (vis[v] == 1)
            return true;
        if (is_circle(v, u))
            return true;
    }
    return false;
}

int cnt(int u) {
    vis[u] = 2;
    int rt = 1;
    for (int v : g[u]) {
        if (vis[v] == 2)
            continue;
        rt += cnt(v);
    }
    return rt;
}

void sol() {
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        st.insert(x);
        st.insert(y);
    }
    int ans = 0;
    for (int i : st) {
        if (vis[i])
            continue;
        ans += cnt(i);
        if (!is_circle(i, -1))
            ans--;
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