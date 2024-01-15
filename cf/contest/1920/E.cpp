#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, -1));
    function<ll(int, int)> dfs = [&](int x, int r) -> ll {
        // cout << x << " " << cur << endl;
        if (r < 0)
            return 0;
        if (r == 0)
            return dp[x][r] = 1;
        if (dp[x][r] != -1)
            return dp[x][r];
        // x+y+1<=k
        ll res = 0;
        for (int y = 0; y <= k - 1 - x && r >= (x + 1) * (y + 1); y++) {
            res += dfs(y, r - (x + 1) * (y + 1));
            res %= MOD;
        }
        return dp[x][r] = res;
    };
    for (int i = 0; i <= k; i++) {
        ans += dfs(i, n);
        ans %= MOD;
    }
    cout << ans << endl;
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