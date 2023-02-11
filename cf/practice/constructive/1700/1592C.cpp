#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 100005
#define MOD 998244353
using namespace std;

vector<int> g[N];
int a[N];
int s;

vector<int> dfs(int u, int fa) {
    vector<int> rt = {u, fa, a[u]};
    for (int v : g[u]) {
        if (v == fa)
            continue;
        auto r = dfs(v, u);
        if (r[2] == s)
            return r;
        rt[2] ^= r[2];
    }
    return rt;
}

void sol() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++)
        g[i].clear();
    s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s ^= a[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if (s == 0) {
        cout << "YES\n";
        return;
    }
    if (k == 2) {
        cout << "NO\n";
        return;
    }
    auto r1 = dfs(1, 0);
    if (r1[0] == 1) {
        cout << "NO\n";
        return;
    }
    auto r2 = dfs(r1[1], r1[0]);
    if (r2[0] == r1[1]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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