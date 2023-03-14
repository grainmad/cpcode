#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

int r = 0;
int vis[N];
vector<int> g[N];

int dfs(int u) {
    int rt = 1;
    vis[u] = 1;
    r = max(u, r);
    for (int v : g[u]) {
        if (vis[v])
            continue;
        rt += dfs(v);
    }
    return rt;
}

void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (i < r) {
                ans++;
            }
            cnt += dfs(i);
            // cout << i << " " << ans << endl;
        }
    }
    cout << ans << "\n";
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