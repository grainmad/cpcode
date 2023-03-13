#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 55
#define MOD 998244353
using namespace std;

int n, m, ans = 0;
int g[N][N];
set<int> st;

void dfs(int x, int y) {
    if (x > n || y > m || st.count(g[x][y]))
        return;
    if (x == n && y == m) {
        ans++;
        return;
    }
    st.insert(g[x][y]);
    dfs(x + 1, y);
    dfs(x, y + 1);
    st.erase(g[x][y]);
}

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    dfs(1, 1);
    cout << ans << endl;
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