#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 100005
#define MOD 998244353
using namespace std;

// f[i][j][k] 前i个以k结尾，a[i-1]和a[i]的大小关系为j的方案数。0 小于 1大于等于
int f[N][2][202];
int a[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (a[1] != -1 && a[2] != -1) {
        if (a[1] > a[2]) {
            cout << "0\n";
            return;
        }
        if (a[1] == a[2]) {
            f[2][1][a[2]] = 1;
        } else {
            f[2][0][a[2]] = 1;
        }
    } else if (a[1] != -1 && a[2] == -1) {
        f[2][1][a[1]] = 1;
        for (int i = a[1] + 1; i <= 200; i++) {
            f[2][0][i] = 1;
        }
    } else if (a[1] == -1 && a[2] != -1) {
        f[2][1][a[2]] = 1;
        // for (int i = 1; i < a[2]; i++) {
        //     f[2][0][a[2]]++;
        // }
        f[2][0][a[2]] = a[2] - 1;
    } else {
        for (int i = 1; i <= 200; i++) {
            f[2][1][i] = 1;
            f[2][0][i] = i - 1;
        }
    }
    for (int i = 3; i <= n; i++) {
        vector<vector<ll>> prf(2, vector<ll>(202, 0)),
            suf(2, vector<ll>(202, 0));
        for (int j = 0; j < 2; j++) {
            for (int k = 1; k <= 200; k++) {
                prf[j][k] = (prf[j][k - 1] + f[i - 1][j][k]) % MOD;
                prf[j][k] %= MOD;
            }
            for (int k = 200; k >= 1; k--) {
                suf[j][k] = (suf[j][k + 1] + f[i - 1][j][k]) % MOD;
                suf[j][k] %= MOD;
            }
        }
        if (a[i] == -1) {
            for (int j = 1; j <= 200; j++) {
                f[i][0][j] = (prf[0][j - 1] + prf[1][j - 1]) % MOD;
                f[i][0][j] %= MOD;
                f[i][1][j] = (suf[1][j] + f[i - 1][0][j]) % MOD;
                f[i][1][j] %= MOD;
            }
        } else {
            int j = a[i];
            f[i][0][j] = (prf[0][j - 1] + prf[1][j - 1]) % MOD;
            f[i][0][j] %= MOD;
            f[i][1][j] = (suf[1][j] + f[i - 1][0][j]) % MOD;
            f[i][1][j] %= MOD;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= 200; i++) {
        ans += f[n][1][i];
        ans %= MOD;
    }
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