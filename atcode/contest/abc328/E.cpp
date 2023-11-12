#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> x(m), y(m), w(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i] >> w[i];
    }

    ll ans = 1e17;
    vector<ll> st;
    auto dfs = [&](auto self, int c) {
        if (st.size() == n - 1) {
            vector<vector<int>> g(n + 1);
            ll tans = 0;
            for (int i : st) {
                tans += w[i];
                // cout << w[i] << " ";
                tans %= k;
                g[x[i]].emplace_back(y[i]);
                g[y[i]].emplace_back(x[i]);
            }
            // cout << "\n";
            vector<int> vis(n + 1);
            auto check = [&](auto ck, int u, int fa) -> bool {
                vis[u] = 1;
                for (auto v : g[u]) {
                    if (v == fa)
                        continue;
                    if (vis[v] || !ck(ck, v, u))
                        return false;
                }
                return true;
            };
            if (check(check, x[st[0]], -1)) {
                // cout << tans << "\n";
                ans = min(ans, tans);
            }
            return;
        }
        if (c == m)
            return;
        st.push_back(c);
        self(self, c + 1);
        st.pop_back();
        self(self, c + 1);
    };
    dfs(dfs, 0);
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