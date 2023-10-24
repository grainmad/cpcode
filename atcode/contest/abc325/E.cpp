#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define MOD 998244353
using namespace std;

ll n, a, b, c;
// 邻接矩阵
#define N 1005
#define INF 0x3f3f3f3f3f3f3f3f
ll g[N][N];  // memset(g, 0x3f, sizeof(g));
ll dis[N], vis[N];
void dijkstra(int n, int s) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        ll u = 0, mind = INF;
        for (int j = 0; j < n; j++)
            if (!vis[j] && dis[j] < mind)
                u = j, mind = dis[j];
        vis[u] = 1;
        for (int v = 0; v < n; v++) {
            if (v == u)
                continue;
            if (dis[v] > dis[u] + min(g[u][v] * a, g[u][v] * b + c))
                dis[v] = dis[u] + min(g[u][v] * a, g[u][v] * b + c);
        }
    }
}

void sol() {
    cin >> n >> a >> b >> c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    dijkstra(n, 0);
    cout << dis[n - 1];
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