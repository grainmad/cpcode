#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 3005
#define MOD 998244353
using namespace std;

ll n, a, b, c, d;
ll x[N];
ll p[N];
ll f[2][N][N];

ll rs(ll l, ll r) {
    return p[r] - p[l];
}

ll dfs(int o, ll l, ll r) {
    if (f[o][l][r] != -1)
        return f[o][l][r];
    if (l == r)
        return f[o][l][r] = 0;
    return f[o][l][r] =
               max({rs(l, min(l + b, r)) - a - dfs(1 - o, min(l + b, r), r),
                    rs(max(l, r - b), r) - a - dfs(1 - o, l, max(l, r - b)),
                    rs(l, min(l + d, r)) - c - dfs(1 - o, min(l + d, r), r),
                    rs(max(l, r - d), r) - c - dfs(1 - o, l, max(l, r - d)),
                    rs(r - 1, r) - dfs(1 - o, l, r - 1),
                    rs(l, l + 1) - dfs(1 - o, l + 1, r)});
}

void sol() {
    memset(f, -1, sizeof(f));
    cin >> n >> a >> b >> c >> d;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + x[i - 1];
    }
    cout << dfs(0, 0, n) << "\n";
    // for (int _ = 0; _ < 2; _++) {
    //     for (int i = 0; i <= n; i++) {
    //         for (int j = 0; j <= n; j++) {
    //             cout << _ << ", " << i << ", " << j << ", " << f[_][i][j]
    //                  << endl;
    //         }
    //     }
    // }
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