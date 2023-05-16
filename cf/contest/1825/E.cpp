#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
#define MOD 998244353
using namespace std;

vector<int> g[N];
int val[N];
map<int, int> f[N];  // f[x] 从 根节点 到 点x的所有儿子 的异或和 的有重集合

int ans = 0;

void dfs(int u, int fa) {
    int mx = 1;  // 子树中最大值 精妙的初始值1
    int sz = 0;  // u为根的树的节点数
    for (int v : g[u]) {
        if (v == fa)
            continue;
        val[v] ^= val[u];
        sz++;
        dfs(v, u);
        // 启发式合并
        if (f[u].size() < f[v].size())
            swap(f[u], f[v]);
        for (auto [i, j] : f[v]) {
            f[u][i] += j;
            mx = max(mx, f[u][i]);
        }
    }
    if (mx != 1)
        for (auto it = f[u].begin(); it != f[u].end();) {
            if (it->second != mx) {
                f[u].erase(it++);
            } else {
                it->second = 1;
                it++;
            }
        }
    if (sz == 0)
        f[u][val[u]] = 1;
    else
        ans += sz - mx;
    // cout << u << " val " << val[u] << " sz " << sz << " mx " << mx << "\n";
    // for (auto [i, j] : f[u]) {
    //     cout << i << " -- " << j << "\n";
    // }
    if (u == 1)
        cout << ans + (!f[1].count(0)) << "\n";
}

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
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