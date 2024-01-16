#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll fun(vector<string>& g, int k) {
    int n = g.size(), m = g[0].size();
    vector<vector<ll>> dp1(n, vector<ll>(m, -1));
    vector<vector<ll>> dp2(n, vector<ll>(m, -1));
    vector<vector<ll>> dp3(n, vector<ll>(m, -1));
    vector<vector<ll>> dp4(n, vector<ll>(m, -1));
    // [0...x,y]
    function<ll(ll, ll)> dfs1 = [&](ll x, ll y) {
        if (x >= n)
            return dfs1(n - 1, y);
        if (x < 0)
            return 0LL;
        if (dp1[x][y] != -1)
            return dp1[x][y];
        return dp1[x][y] = (g[x][y] == '#') + dfs1(x - 1, y);
    };
    // [x, 0...y]
    function<ll(ll, ll)> dfs2 = [&](ll x, ll y) {
        if (y >= m)
            return dfs2(x, m - 1);
        if (y < 0)
            return 0LL;
        if (dp2[x][y] != -1)
            return dp2[x][y];
        return dp2[x][y] = (g[x][y] == '#') + dfs2(x, y - 1);
    };
    // [0...x, 0...y]
    function<ll(ll, ll)> dfs3 = [&](ll x, ll y) {
        if (-(m - 1) > x - y || x - y > n - 1) {
            return 0LL;
        }
        if (y >= m)
            return dfs3(x - (y - m + 1), m - 1);
        if (x < 0)
            return 0LL;

        if (dp3[x][y] != -1)
            return dp3[x][y];
        return dp3[x][y] = (g[x][y] == '#') + dfs3(x - 1, y - 1);
    };
    ll rt = 0;
    for (ll x1 = -1, y1 = 0, c1 = 0; x1 + 1 < n; x1++) {
        c1 += (dfs2(x1 + 1, y1 + k) - dfs2(x1 + 1, y1 - 1)) -
              (dfs3(x1, y1 + k) - dfs3(x1 - k - 1, y1 - 1));  // 下移
        for (ll x2 = x1 + 1, y2 = y1, c2 = c1; y2 < m; y2++) {
            rt = max(c2, rt);
            c2 += dfs3(x2, y2 + k + 1) - dfs3(x2 - k - 1, y2) -
                  (dfs1(x2, y2) - dfs1(x2 - k - 1, y2));
        }
    }
    return rt;
}

void sol() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> g(n);
    for (auto& i : g)
        cin >> i;

    auto swap_ud = [&]() {
        int l = 0, r = n - 1;
        while (l < r) {
            swap(g[l], g[r]);
            l++;
            r--;
        }
    };
    auto swap_lr = [&]() {
        for (auto& i : g) {
            reverse(i.begin(), i.end());
        }
    };

    ll ans = fun(g, k);
    swap_lr();
    ans = max(ans, fun(g, k));  // lr
    swap_lr();
    swap_ud();
    ans = max(ans, fun(g, k));  // ud
    swap_lr();
    ans = max(ans, fun(g, k));  // ud lr
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