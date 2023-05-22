#include <bits/stdc++.h>
// #define LOCAL
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
#define INF 0x3f3f3f3f
using namespace std;

vector<pair<int, int>> g[N];

void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        while (c--) {
            int x;
            cin >> x;
            g[x].emplace_back(m + i, 1);
            g[m + i].emplace_back(x, 0);
        }
    }
    vector<int> dis(n + m + 1, INF), vis(n + m + 1, 0);
    dis[1] = 0;
    deque<int> q;
    q.push_back(1);
    while (q.size()) {
        int u = q.front();
        q.pop_front();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto [v, e] : g[u]) {
            if (dis[v] > dis[u] + e) {
                dis[v] = dis[u] + e;
                e ? q.push_back(v) : q.push_front(v);
            }
        }
    }
    if (dis[m] == INF)
        cout << "-1\n";
    else
        cout << dis[m] - 1 << "\n";
}
int main() {
    cout << "\n\nExecution time: 655360 ms\n\n";
#ifdef LOCAL
    auto start_time = clock();
    cerr << setprecision(3) << fixed;
#endif
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
#ifdef LOCAL
    auto end_time = clock();
    cerr << "Execution time: "
         << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}