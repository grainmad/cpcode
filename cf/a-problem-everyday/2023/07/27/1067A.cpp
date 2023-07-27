
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 100005
#define MOD 998244353
using namespace std;

// f[i][j][k] 前i个以k结尾，a[i-1]和a[i]的大小关系为j的方案数。
ll f[N][3][202];
int a[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 2) {
        if (a[1] != -1 && a[2] != -1)
            cout << "0\n";
        if (a[1] == -1 && a[2] != -1)
            cout << "1\n";
        if (a[1] != -1 && a[2] == -1)
            cout << "1\n";
        if (a[1] == -1 && a[2] == -1)
            cout << "200\n";
        return;
    }
    if (a[1] != -1 && a[2] != -1) {
        f[2][a[1] < a[2] ? 0 : (a[1] == a[2] ? 1 : 2)][a[2]] = 1;
    } else if (a[1] != -1 && a[2] == -1) {
        for (int i = 1; i <= 200; i++) {
            if (a[1] < i)
                f[2][0][i]++;
            if (a[1] == i)
                f[2][1][i]++;
            if (a[1] > i)
                f[2][2][i]++;
        }
    } else if (a[1] == -1 && a[2] != -1) {
        for (int i = 1; i <= 200; i++) {
            if (i < a[2])
                f[2][0][a[2]]++;
            if (i == a[2])
                f[2][1][a[2]]++;
            if (i > a[2])
                f[2][2][a[2]]++;
        }
    } else {
        for (int i = 1; i <= 200; i++) {
            for (int j = 1; j <= 200; j++) {
                if (i < j)
                    f[2][0][j]++;
                if (i == j)
                    f[2][1][j]++;
                if (i > j)
                    f[2][2][j]++;
            }
        }
    }
    for (int i = 3; i <= n; i++) {
        vector<vector<int>> prf(3, vector<int>(202, 0)),
            suf(3, vector<int>(202, 0));
        for (int j = 0; j < 3; j++) {
            for (int k = 1; k <= 200; k++) {
                prf[j][k] += prf[j][k - 1] + f[i - 1][j][k];
            }
            for (int k = 200; k >= 1; k--) {
                suf[j][k] += suf[j][k + 1] + f[i - 1][j][k];
            }
        }
        if (a[i] == -1) {
            for (int j = 1; j <= 200; j++) {
                f[i][0][j] += prf[0][j - 1] + prf[1][j - 1] + prf[2][j - 1];
                f[i][1][j] += f[i - 1][0][j] + f[i - 1][1][j] + f[i - 1][2][j];
                f[i][2][j] += suf[1][i - 1] + suf[2][i - 1];
            }
        } else {
            int j = a[i];
            f[i][0][j] += prf[0][j - 1] + prf[1][j - 1] + prf[2][j - 1];
            f[i][1][j] += f[i - 1][0][j] + f[i - 1][1][j] + f[i - 1][2][j];
            f[i][2][j] += suf[1][i - 1] + suf[2][i - 1];
        }
    }
    ll ans = 0;
    if (a[n] == -1) {
        for (int i = 1; i <= 200; i++) {
            ans += f[n][1][i] + f[n][2][i];
        }
    } else {
        ans = f[n][1][a[n]] + f[n][2][a[n]];
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
