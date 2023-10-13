#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
#define NINF 0xf3f3f3f3
#define INF 0x3f3f3f3f
using namespace std;

void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> mk(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        mk[x - 1]++;
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> mx(n);
    function<int(int, int)> dfs = [&](int u, int fa) {
        int rt = NINF;
        if (mk[u])
            rt = 0;
        for (auto v : g[u]) {
            if (v == fa)
                continue;
            int t = dfs(v, u);
            rt = max(rt, t + 1);
        }
        return mx[u] = rt;
    };
    dfs(0, -1);
    // for (int i = 0; i < n; i++) {
    //     cout << i << " " << mx[i] << endl;
    // }
    int ans = INF;
    function<void(int, int, int)> dfs2 = [&](int u, int pre, int fa) {
        // cout << u << " - " << pre << " " << mx[u] << endl;
        int mx1 = NINF, mx2 = NINF, v1, v2;
        for (auto v : g[u]) {
            if (v == fa)
                continue;
            if (mx[v] > mx1) {
                mx2 = mx1;
                v2 = v1;
                mx1 = mx[v];
                v1 = v;
            } else if (mx[v] > mx2) {
                mx2 = mx[v];
                v2 = v;
            }
        }
        ans = min(ans, max(mx[u], pre + 1));
        int cur = mk[u] ? 0 : NINF;
        for (auto v : g[u]) {
            if (v == fa)
                continue;
            if (v == v1) {
                dfs2(v, max({pre + 1, mx2 + 1, cur}), u);
            } else {
                dfs2(v, max({pre + 1, mx1 + 1, cur}), u);
            }
        }
    };
    dfs2(0, NINF, -1);
    cout << ans << "\n";
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