#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 55
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    int g[n][n];
    memset(g, 0, sizeof(g));
    for (int i = 0; i < m; i++) {
        int p = -1, x;
        for (int j = 0; j < n; j++) {
            cin >> x;
            x--;
            if (p != -1)
                g[x][p] = g[p][x] = 1;
            p = x;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (g[i][j] == 0)
                ans++;
        }
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