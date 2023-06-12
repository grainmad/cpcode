
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 1005
#define MOD 998244353
using namespace std;

int vis[N][N];

ll g[N][N];

ll n, m, k;

int st[N * N];

ll cnt = 0;

void uf_init() {
    memset(st, -1, sizeof(st));
}

int uf_find(int x) {
    return st[x] < 0 ? x : st[x] = uf_find(st[x]);
}

bool uf_union(int x, int y) {
    int fx = uf_find(x), fy = uf_find(y);
    if (fx != fy) {
        st[fx] += st[fy];
        st[fy] = fx;
        return true;
    }
    return false;
}

void dfs(int x, int y, int id) {
    if (cnt == 0)
        return;
    cnt--;
    vis[x][y] = 1;
    for (int d = 0; d < 4; d++) {
        int mx = x + (d - 1) % 2;
        int my = y + (d - 2) % 2;
        if (mx < 0 || mx >= n || my < 0 || my >= m ||
            uf_find(mx * m + my) != id || vis[mx][my])
            continue;
        dfs(mx, my, id);
    }
}

void sol() {
    uf_init();
    vector<pair<ll, ll>> idx;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            idx.emplace_back(i, j);
        }
    }
    sort(idx.begin(), idx.end(), [&](auto& a, auto& b) {
        return g[a.first][a.second] > g[b.first][b.second];
    });
    for (auto [ix, iy] : idx) {
        for (int d = 0; d < 4; d++) {
            int mx = ix + (d - 1) % 2;
            int my = iy + (d - 2) % 2;
            if (mx < 0 || mx >= n || my < 0 || my >= m || g[mx][my] < g[ix][iy])
                continue;
            uf_union(ix * m + iy, mx * m + my);
        }
        if (k % g[ix][iy] == 0 && -st[uf_find(ix * m + iy)] >= k / g[ix][iy]) {
            cnt = k / g[ix][iy];
            dfs(ix, iy, uf_find(ix * m + iy));
            cout << "YES\n";
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < m; c++) {
                    cout << (vis[r][c] ? g[ix][iy] : 0) << " ";
                }
                cout << "\n";
            }
            return;
        }
    }
    cout << "NO\n";
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
