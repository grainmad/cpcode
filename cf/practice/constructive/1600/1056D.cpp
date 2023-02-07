#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
#define MOD 998244353
using namespace std;

// int deg[N], fa[N];
int leaf[N];

vector<int> g[N];

int dfs(int u) {
    if (g[u].empty()) {
        return leaf[u] = 1;
    }
    for (int i : g[u]) {
        leaf[u] += dfs(i);
    }
    return leaf[u];
}

void sol() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
        // fa[i] = x;
        // deg[x]++;
    }
    dfs(1);
    sort(leaf + 1, leaf + n + 1);
    for (int i = 1; i <= n; i++) {
        cout << leaf[i] << " ";
    }
    cout << "\n";
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    // for (int i = 1; i <= n; i++) {
    //     if (deg[i] == 0)
    //         q.emplace(1, i);
    // }
    // int cur = 1;
    // while (q.size()) {
    //     auto [i, j] = q.top();  // 子树所含叶子数，子树编号
    //     q.pop();
    //     if (--deg[fa[j]] == 0) {
    //         q.emplace(leaf[fa[j]], fa[j]);
    //     }
    //     cur = max(cur, i);
    //     cout << cur << " ";
    // }
    // cout << "\n";
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