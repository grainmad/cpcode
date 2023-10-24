#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (auto& i : g)
        cin >> i;
    function<void(int, int)> dfs = [&](int x, int y) {
        vis[x][y] = 1;
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (i == 0 && i == j)
                    continue;
                int mx = x + i;
                int my = y + j;
                if (mx < 0 || mx >= n || my < 0 || my >= m ||
                    g[mx][my] == '.' || vis[mx][my] == 1)
                    continue;
                dfs(mx, my);
            }
        }
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '#' && vis[i][j] == 0) {
                dfs(i, j);
                ans++;
            }
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