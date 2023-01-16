#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 105
using namespace std;

string g[N];
vector<vector<int>> ans;
int n, m;
int d[4][2] = {{0, 0}, {0, 1}, {1, 1}, {1, 0}};

char rev(char i) {
    return i == '0' ? '1' : '0';
}

void opt(int s, int x, int y) {
    ans.push_back({});
    for (int i = 0; i < 3; i++) {
        int idx = (i + s) % 4;
        int mx = x + d[idx][0];
        int my = y + d[idx][1];
        g[mx][my] = rev(g[mx][my]);
        ans.back().push_back(mx + 1);
        ans.back().push_back(my + 1);
        // cout << mx+1 << " " << my+1 << " ";
    }
    // cout << "\n";
}

void row_opt(int r) {
    for (int j = 0; j < m - 2; j++) {
        if (g[r][j] == '1' && g[r + 1][j] == '1') {
            opt(3, r, j);
        } else if (g[r][j] == '1') {
            opt(0, r, j);
        } else if (g[r + 1][j] == '1') {
            opt(1, r, j);
        }
    }
}

void clo_opt(int c) {
    for (int j = 0; j < n - 2; j++) {
        if (g[j][c] == '1' && g[j][c + 1] == '1') {
            opt(0, j, c);
        } else if (g[j][c] == '1') {
            opt(2, j, c);
        } else if (g[j][c + 1] == '1') {
            opt(1, j, c);
        }
    }
}

int dfs(int lev) {
    if (lev > 4) {
        return 0;
    }
    int ok = 1;
    for (int i = 0; i < 4; i++) {
        int x = d[i][0] + n - 2;
        int y = d[i][1] + m - 2;
        if (g[x][y] == '1') {
            ok = 0;
            break;
        }
    }
    if (ok) {
        return 1;
    }
    // for (int i=n-2; i<n; i++) {
    // 	for (int j=m-2; j<m; j++) {
    // 		cout << g[i][j];
    // 	}
    // 	cout << "\n";
    // }
    for (int i = 0; i < 4; i++) {
        ans.push_back({});
        for (int j = 0; j < 3; j++) {
            int x = d[(i + j) % 4][0] + n - 2;
            int y = d[(i + j) % 4][1] + m - 2;
            g[x][y] = rev(g[x][y]);
            ans.back().push_back(x + 1);
            ans.back().push_back(y + 1);
        }
        if (dfs(lev + 1))
            return 1;
        for (int j = 0; j < 3; j++) {
            int x = d[(i + j) % 4][0] + n - 2;
            int y = d[(i + j) % 4][1] + m - 2;
            g[x][y] = rev(g[x][y]);
            ans.back().pop_back();
            ans.back().pop_back();
        }
        ans.pop_back();
    }
    return 0;
}

void sol() {
    ans.clear();
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> g[i];
    for (int i = 0; i < n - 1; i += 2) {
        row_opt(i);
    }
    if (n % 2) {
        row_opt(n - 2);
    }
    clo_opt(m - 2);
    // cout << ans.size() << "\n";
    dfs(0);
    cout << ans.size() << "\n";
    for (auto& i : ans) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
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