#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

vector<int> g[N];
vector<pair<int, int>> q[N];
int vis[N], ans[N];

int fa[N];

int ufind(int x) {
    return fa[x] < 0 ? x : fa[x] = ufind(fa[x]);
}

void tarjan(int u) {
    vis[u] = 1;
    for (auto v : g[u]) {
        if (vis[v])
            continue;
        tarjan(v);
        fa[v] = u;
    }
    for (auto [v, i] : q[u]) {
        if (vis[v])
            ans[i] = ufind(v);
    }
}

void sol() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        q[x].emplace_back(y, i);
        q[y].emplace_back(x, i);
    }
    memset(fa, -1, sizeof(fa));
    tarjan(s);
    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
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