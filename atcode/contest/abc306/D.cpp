#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 300005
#define MOD 998244353
#define NINF 0xf3f3f3f3f3f3f3f3
using namespace std;

ll dp[N][2][2];  // dp[i][j][k] j 不选与选，k 健康与不适

void sol() {
    int n;
    cin >> n;
    memset(dp, 0xf3, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        ll x, y;
        cin >> x >> y;
        dp[i][0][0] = max(dp[i - 1][1][0], dp[i - 1][0][0]);
        dp[i][0][1] = max(dp[i - 1][1][1], dp[i - 1][0][1]);
        if (x) {  // 有毒
            dp[i][1][1] = max(dp[i - 1][0][0], dp[i - 1][1][0]) + y;
        } else {  // 解毒
            dp[i][1][0] = max({dp[i - 1][0][1], dp[i - 1][1][1],
                               dp[i - 1][0][0], dp[i - 1][1][0]}) +
                          y;
        }
        // cout << i << " " << dp[i][0][0] << " " << dp[i][0][1] << " "
        //      << dp[i][1][0] << " " << dp[i][1][1] << endl;
    }
    cout << max({dp[n][0][0], dp[n][1][0], dp[n][0][1], dp[n][1][1]}) << "\n";
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