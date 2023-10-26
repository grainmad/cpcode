#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n;
    cin >> n;
    vector<int> a(n), c(n + 1), v(n + 1);
    for (auto& i : a)
        cin >> i, c[i]++, v[i] = 1;

    vector<ll> s(n + 1), dp(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            s[i] += c[j];
            v[j] |= v[i];
        }
    }
    function<ll(ll)> dfs = [&](ll x) {
        if (x > n || dp[x] != -1)
            return dp[x];
        dp[x] = s[x] * (s[x] - 1) / 2;
        for (int i = 2 * x; i <= n; i += x) {
            dp[x] -= dfs(i);
        }
        return dp[x];
    };
    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += (1 - v[i]) * dfs(i);
    }
    // for (auto i : c) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    cout << ans << "\n";
    // vector<ll> dp(n + 1);
    // ll ans = 0;
    // for (int i = n; i >= 1; i--) {
    //     ll sz = 0;
    //     for (int j = i; j <= n; j += i) {
    //         sz += c[j];
    //         dp[i] -= dp[j];
    //         v[j] |= v[i];
    //     }
    //     dp[i] += sz * (sz - 1) / 2;
    // }
    // for (int i = 1; i <= n; i++)
    //     ans += v[i] * dp[i];
    // cout << n * (n + 1) / 2 - n - ans << "\n";
    // // for (int i = 1; i <= n; i++)
    // //     ans += (1 - v[i]) * dp[i];
    // // cout << ans << "\n";
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