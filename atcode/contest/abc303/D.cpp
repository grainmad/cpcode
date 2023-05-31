#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 300005
#define MOD 998244353
using namespace std;

ll dp[2][N];

void sol() {
    ll x, y, z;
    cin >> x >> y >> z;
    string s;
    cin >> s;
    int n = s.size();
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'a') {
            dp[0][i] = min({dp[0][i], dp[1][i - 1] + z + x,
                            dp[1][i - 1] + y + z});        // on -> off
            dp[0][i] = min({dp[0][i], dp[0][i - 1] + x});  // off -> off
            dp[1][i] = min({dp[1][i], dp[1][i - 1] + y});  // on -> on
            dp[1][i] = min({dp[1][i], dp[0][i - 1] + x + z,
                            dp[0][i - 1] + z + y});  // off -> on
        } else {
            dp[0][i] = min({dp[0][i], dp[1][i - 1] + x + z,
                            dp[1][i - 1] + z + y});        // on -> off
            dp[0][i] = min({dp[0][i], dp[0][i - 1] + y});  // off -> off
            dp[1][i] = min({dp[1][i], dp[1][i - 1] + x});  // on -> on
            dp[1][i] = min({dp[1][i], dp[0][i - 1] + z + x,
                            dp[0][i - 1] + y + z});  // off -> on
        }
    }
    cout << min(dp[0][n], dp[1][n]) << "\n";
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