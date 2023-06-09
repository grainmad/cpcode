#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m, r;
    cin >> n >> m >> r;
    set<tuple<int, int, int>> st;
    for (int i = 0; i < r; i++) {
        int t, d, c;
        cin >> t >> d >> c;
        st.insert({t, d, c});
    }
    int vis[n + 1][m + 1][r + 1];
    memset(vis, 0, sizeof(vis));
    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);
    int stp = 0;
    while (q.size()) {
        int sz = q.size();
        // cout << stp << ":" << endl;
        for (int i = 0; i < sz; i++) {
            auto [x, y, w] = q.front();
            q.pop();
            // cout << x << " " << y << " " << w << endl;
            if (st.count({stp, 1, x}) || st.count({stp, 2, y})) {
                continue;
            }
            if (x == n && y == m) {
                cout << stp << "\n";
                return;
            }
            if (x + 1 <= n && vis[x + 1][y][w] != stp + 1)
                q.emplace(x + 1, y, w), vis[x + 1][y][w] = stp + 1;
            if (y + 1 <= m && vis[x][y + 1][w] != stp + 1)
                q.emplace(x, y + 1, w), vis[x][y + 1][w] = stp + 1;
            if (w + 1 <= r && vis[x][y][w + 1] != stp + 1)
                q.emplace(x, y, w + 1), vis[x][y][w + 1] = stp + 1;
        }
        stp++;
    }
    cout << "-1\n";
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