#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 200005
#define INF 0x3f3f3f3f
#define MOD 998244353
using namespace std;

vector<int> g[N];

void sol() {
    int n;
    cin >> n;
    vector<int> c(n), dis(n + 1, INF);
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = INF + 5;
    for (int i = 0; i < n; i++) {
        queue<int> q;
        vector<bool> vis(n + 1, 0);
        q.push(c[i]);
        vis[c[i]] = 1;
        dis[c[i]] = 0;
        while (q.size()) {
            int u = q.front();
            q.pop();
            if (dis[u] >= ans)
                continue;
            for (int x : g[u]) {
                if (dis[x] > dis[u] + 1) {
                    vis[x] = 1;
                    dis[x] = dis[u] + 1;
                    q.push(x);
                } else if (!vis[x]) {
                    ans = min(ans, dis[u] + 1 + dis[x]);
                }
            }
        }
        if (i > 0)
            cout << ans << " ";
    }
    cout << endl;
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