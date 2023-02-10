#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

vector<pair<int, int>> g[N];
int vis[N], role[N];

pair<int, int> dfs(int u) {
    int cnt = 1, good = role[u];
    for (auto [v, r] : g[u]) {
        if (vis[v]) {
            if (role[v] != (role[u] ^ r))
                return {-1, -1};
            continue;
        }
        role[v] = (role[u] ^ r);
        vis[v] = 1;
        auto [x, y] = dfs(v);
        if (x == -1)
            return {-1, -1};
        cnt += x;
        good += y;
    }
    return {cnt, good};
}

void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        vis[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        if (s[0] == 'i') {
            g[x].emplace_back(y, 1);
            g[y].emplace_back(x, 1);
        } else {
            g[x].emplace_back(y, 0);
            g[y].emplace_back(x, 0);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;
        vis[i] = role[i] = 1;
        auto [x, y] = dfs(i);
        if (x == -1) {
            cout << "-1\n";
            return;
        }
        ans += max(y, x - y);
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