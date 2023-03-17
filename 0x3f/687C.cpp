#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 505
#define MOD 998244353
using namespace std;

int dp[2][N][N];  // dp[i][j][k] 前i个数能否构成和为j的子集，且子集的子集和为k。
int c[N];

void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        // memset(dp[i % 2], 0, sizeof(dp[i % 2]));
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i % 2][j][k] = dp[(i - 1) % 2][j][k];
                if (j >= c[i] && k >= c[i])
                    dp[i % 2][j][k] |= dp[(i - 1) % 2][j - c[i]][k - c[i]];
                if (j >= c[i])
                    dp[i % 2][j][k] |= dp[(i - 1) % 2][j - c[i]][k];
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i <= m; i++) {
        if (dp[n % 2][m][i])
            ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\n";
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