#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

string s;

ll dp[20][2][2];

ll dfs(int p, int limit, int zero) {
    if (p == s.size())
        return 1LL - zero;
    if (dp[p][limit][zero] != -1)
        return dp[p][limit][zero];
    ll res = 0;

    if (zero == 1)
        res += dfs(p + 1, 0, 1);

    for (int i = (zero ? 1 : 0); i <= (limit ? s[p] - '0' : 9); i++) {
        if (i == 4)
            continue;
        res += dfs(p + 1, limit && (i == s[p] - '0'), 0);
    }
    return dp[p][limit][zero] = res;
}

ll cnt(ll n) {
    s = to_string(n);
    memset(dp, -1, sizeof(dp));
    return dfs(0, 1, 1);
}

void sol() {
    ll k;
    cin >> k;

    ll l = 1, r = 1e17;
    while (l < r) {
        ll m = (r - l) / 2 + l;
        // cout << cnt(m) << " " << k << endl;
        if (cnt(m) >= k) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << r << endl;
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