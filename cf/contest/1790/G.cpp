#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

vector<int> g[N];
int T[N], B[N];
int n, m, p, q;
map<int, ll> stp;  // stp[i] 编号为i的token可以操控的次数0，1，INF
int dis[N];        // dis[i] 编号为i的token到1节点的距离

void dfs(int u) {
    for (int x : g[u]) {
        if (dis[x] > dis[u] + 1) {
            dis[x] = dis[u] + 1;
            if (B[x])
                dfs(x);
        }
    }
};

void sol() {
    cin >> n >> m >> p >> q;
    stp.clear();
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        T[i] = B[i] = 0;
        dis[i] = N;
    }
    dis[1] = 0;
    for (int i = 0; i < p; i++) {
        int x;
        cin >> x;
        T[x] = 1;
    }
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        B[x] = 1;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    if (T[1]) {
        cout << "YES\n";
        return;
    }
    for (int x : g[1]) {
        if (T[x]) {
            cout << "YES\n";
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (B[i]) {
            ll con = 1;
            for (int x : g[i]) {
                if (B[x])
                    con = N;
            }
            // if (T[i]) 傻逼了，草。。。若i的bouns连通块为1，没有可行步数。
            //     stp[i] = max(stp[i], con);
            for (int x : g[i]) {
                if (T[x])
                    stp[x] = max(stp[x], con);
            }
        }
    }
    dfs(1);
    ll s = 0;
    for (auto& [i, j] : stp)
        s += j;
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        if (dis[i] == N || !T[i])
            continue;
        if (s - stp[i] >= dis[i] - 1) {  // i先行，其余只需dis[i]-1步
            ok = true;
            break;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
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