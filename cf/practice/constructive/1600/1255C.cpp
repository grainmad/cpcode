#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
#define MOD 998244353
using namespace std;

vector<int> g[N];
int vis[N];

void sol() {
    int n;
    cin >> n;
    vector<vector<int>> a(n - 2, vector<int>(3, 0));
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
            g[a[i][j]].push_back(i);
        }
    }
    int x, y;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) {
            x = i;
            for (int j : a[g[i][0]]) {
                if (g[j].size() == 2) {
                    y = j;
                }
            }
            break;
        }
    }
    vis[x] = vis[y] = 1;
    cout << x << " " << y;
    auto nxt = [&](int u, int v) -> int {
        for (int i : g[v]) {
            int rt, cnt = 0;
            for (int j : a[i]) {
                if (vis[j])
                    cnt++;
                else
                    rt = j;
            }
            if (cnt == 2) {
                vis[rt] = 1;
                return rt;
            }
        }
        return -1;
    };
    for (int i = 0; i < n - 2; i++) {
        int z = nxt(x, y);
        cout << " " << z;
        x = y;
        y = z;
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