
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m, 0)), mn(n, vector<int>(m, 1e9)),
        mx(n, vector<int>(m, -1e9));
    for (auto& i : g) {
        for (auto& j : i)
            cin >> j;
    }
    if ((n + m - 1) % 2) {
        cout << "NO\n";
        return;
    }
    mx[0][0] = mn[0][0] = g[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0) {
                mx[i][j] = max(mx[i][j], mx[i - 1][j] + g[i][j]);
                mn[i][j] = min(mn[i][j], mn[i - 1][j] + g[i][j]);
            }
            if (j > 0) {
                mx[i][j] = max(mx[i][j], mx[i][j - 1] + g[i][j]);
                mn[i][j] = min(mn[i][j], mn[i][j - 1] + g[i][j]);
            }
        }
    }
    if (mn[n - 1][m - 1] > 0 || mx[n - 1][m - 1] < 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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
