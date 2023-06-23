#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<ll> leaf(n + 1);
    function<ll(int, int)> dfs = [&](int u, int fa) {
        int cnt = 0;
        for (auto v : g[u]) {
            if (v == fa)
                continue;
            cnt++;
            leaf[u] += dfs(v, u);
        }
        if (cnt == 0)
            return leaf[u] = 1;
        return leaf[u];
    };
    dfs(1, 0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << leaf[x] * leaf[y] << "\n";
    }
}

int main() {
    cout << setprecision(15) << fixed;
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