#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define INF 0x3f3f3f3f
#define MOD 998244353
using namespace std;

int dp[105][10005];  // dp[i][j] 前i个行中选j个数的最小和。dp[i][j] =
                     // min(dp[i-1][j-c]+row[i][c]), c in [ 0, k[i] ]

int row[105][105];  // row[i][j] 第i行长度为j的子串中最小子段和。

int p[105];  // 临时前缀和

int k[105];  // k[i] 第i行的大小

void sol() {
    int n, m, sz = 0, sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        sz += k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> p[j];
            sum += p[j];
            row[i][j] = INF;
        }
        for (int j = 1; j <= k[i]; j++) {
            p[j] += p[j - 1];
        }
        for (int j = 1; j <= k[i]; j++) {
            for (int c = j; c <= k[i]; c++) {
                row[i][j] = min(row[i][j], p[c] - p[c - j]);
            }
        }
        // cout << i << " sz: " << k[i] << endl;
        // for (int j = 0; j <= k[i]; j++) {
        //     cout << j << " " << row[i][j] << ", ";
        // }
        // cout << endl;
    }
    int o = sz - m;  // 寻找o个最小的值
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= o; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= o; j++) {
            for (int c = 0; c <= k[i] && c <= j; c++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - c] + row[i][c]);
            }
            // cout << i << " " << j << "=" << dp[i][j] << endl;
        }
    }
    // cout << sum << endl;
    cout << sum - dp[n][o] << endl;
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