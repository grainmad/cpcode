
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 5005
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

ll a[N], cold[N], hot[N];
ll f[N][N], g[N][N];

void sol() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> cold[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> hot[i];
    }
    // 每组数据都按照最坏的情况初始化 超时
    // memset(f, 0x3f, sizeof(f));
    // memset(g, 0x3f, sizeof(g));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            g[i][j] = f[i][j] = INF;
        }
    }
    g[1][0] = f[1][0] = cold[a[1]];
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            f[i][j] =
                min(f[i][j],
                    f[i - 1][j] + (a[i] == a[i - 1] ? hot[a[i]] : cold[a[i]]));
            f[i][a[i - 1]] =
                min(f[i][a[i - 1]],
                    g[i - 1][j] + (a[i] == j ? hot[a[i]] : cold[a[i]]));
            g[i][j] =
                min(g[i][j],
                    g[i - 1][j] + (a[i] == a[i - 1] ? hot[a[i]] : cold[a[i]]));
            g[i][a[i - 1]] =
                min(g[i][a[i - 1]],
                    f[i - 1][j] + (a[i] == j ? hot[a[i]] : cold[a[i]]));
        }
    }
    ll mn = g[0][0];
    for (int i = 0; i <= k; i++) {
        mn = min({mn, f[n][i], g[n][i]});
    }
    cout << mn << "\n";
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
