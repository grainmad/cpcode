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
ll dis[2][N], vis[2][N];
void dijkstra(int n, int s) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[0][s] = dis[0][s] = 0;
    for (int i = 0; i < n; i++) {
        ll u = 0, mind = INF;
        for (int j = 0; j < n; j++)
            if (!vis[0][j] && dis[0][j] < mind)
                u = j, mind = dis[0][j];
        vis[0][u] = 1;
        for (int v = 0; v < n; v++) {
            if (v == u)
                continue;
            if (dis[0][v] > dis[0][u] + g[u][v] * a)
                dis[0][v] = dis[0][u] + g[u][v] * a;
            if (dis[1][v] > dis[0][u] + g[u][v] * b + c)
                dis[1][v] = dis[0][u] + g[u][v] * b + c;
        }
        u = 0, mind = INF;
        for (int j = 0; j < n; j++)
            if (!vis[1][j] && dis[1][j] < mind)
                u = j, mind = dis[1][j];
        vis[1][u] = 1;
        for (int v = 0; v < n; v++) {
            if (v == u)
                continue;
            if (dis[1][v] > dis[1][u] + g[u][v] * b + c)
                dis[1][v] = dis[1][u] + g[u][v] * b + c;
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
    cout << min(dis[0][n - 1], dis[1][n - 1]);
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