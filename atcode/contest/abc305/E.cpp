#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

int vis[N];
int dis[N];
vector<int> g[N];

void sol() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    priority_queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
        dis[i] = -1;
    for (int i = 0; i < k; i++) {
        int p, h;
        cin >> p >> h;
        dis[p] = h;
        q.emplace(h, p);
    }
    while (q.size()) {
        auto [h, u] = q.top();
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int v : g[u]) {
            if (dis[u] - 1 > dis[v]) {
                dis[v] = dis[u] - 1;
                q.emplace(dis[v], v);
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (dis[i] != -1)
            ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
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