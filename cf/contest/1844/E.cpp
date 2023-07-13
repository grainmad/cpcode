#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n + m);
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        g[min(x1, x2)].emplace_back(n - 1 + min(y1, y2), x1 + y1 != x2 + y2);
        g[n - 1 + min(y1, y2)].emplace_back(min(x1, x2), x1 + y1 != x2 + y2);
    }
    int ok = 1;
    vector<int> color(n + m, -1);
    function<void(int, int)> dfs = [&](int u, int c) {
        color[u] = c;
        for (auto [v, e] : g[u]) {
            if (color[v] != -1) {
                if (color[v] != (c ^ e))
                    ok = 0;
                continue;
            }
            dfs(v, c ^ e);
        }
    };
    for (int i = 1; i <= n + m - 2; i++) {
        if (color[i] == -1) {
            dfs(i, 0);
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
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