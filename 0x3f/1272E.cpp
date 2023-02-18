#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
#define INF 0x3f3f3f3f
using namespace std;

int n;
int a[N], f[N];
vector<int> g[N];
void bfs(vector<int>& s, vector<int>& e) {
    queue<int> q;
    vector<int> dis(n + 1, INF);
    for (int i : s) {
        dis[i] = 0;
        q.push(i);
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i : g[u]) {
            if (dis[i] == INF) {
                dis[i] = dis[u] + 1;
                q.push(i);
            }
        }
    }
    for (int i : e) {
        if (dis[i] != INF) {
            f[i] = dis[i];
        }
    }
}

void sol() {
    cin >> n;
    vector<int> o, e;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = -1;
        if (a[i] % 2)
            o.push_back(i);
        else
            e.push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (i - a[i] >= 1)
            g[i - a[i]].push_back(i);
        if (i + a[i] <= n)
            g[i + a[i]].push_back(i);
    }
    bfs(o, e);
    bfs(e, o);
    for (int i = 1; i <= n; i++) {
        cout << f[i] << " ";
    }
    cout << "\n";
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