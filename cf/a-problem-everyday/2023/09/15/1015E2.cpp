
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 1005
#define MOD 998244353
using namespace std;

int n, m;
string g[N];

int rd[N][N], cd[N][N];

int f[4][N][N];

int dfs(int d, int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '.')
        return 0;
    if (f[d][x][y])
        return f[d][x][y];
    return f[d][x][y] = dfs(d, x + (d - 1) % 2, y + (d - 2) % 2) + 1;
}

void sol() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '*') {
                int mn = N;
                for (int k = 0; k < 4; k++) {
                    mn = min(mn, dfs(k, i, j));
                }
                // [i,j] [i-mn+1, i+mn-1] [j-mn+1, j+mn-1]
                if (mn > 1) {
                    rd[i][j - mn + 1]++;
                    rd[i][j + mn]--;
                    cd[j][i - mn + 1]++;
                    cd[j][i + mn]--;
                    // cout << i << " " << j << " " << mn << "\n";
                    ans.push_back({i + 1, j + 1, mn - 1});
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            rd[i][j] += rd[i][j - 1];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            cd[i][j] += cd[i][j - 1];
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << rd[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << cd[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    int ok = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.' || rd[i][j] || cd[j][i])
                continue;
            ok = 0;
        }
    }
    if (ok) {
        cout << ans.size() << "\n";
        for (auto& i : ans) {
            cout << i[0] << " " << i[1] << " " << i[2] << "\n";
        }
    } else {
        cout << "-1\n";
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
