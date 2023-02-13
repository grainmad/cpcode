#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

vector<int> g[N];
int val[N];
int n;

int dfs(int x, int fa) {
    int cnt = 1;
    for (int y : g[x]) {
        if (y == fa)
            continue;
        int cur = dfs(y, x);
        cnt += cur;
        val[x] = max(val[x], cur);
    }
    val[x] = max(val[x], n - cnt);
    return cnt;
}

void sol() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        val[i] = 0;
    }

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    // for (int i = 1; i <= n; i++) {
    //     cout << val[i] << " --- ";
    // }
    // cout << endl;
    int mn = *min_element(val + 1, val + n + 1);
    if (count(val + 1, val + n + 1, mn) == 1) {
        cout << "1 " << g[1][0] << "\n";
        cout << "1 " << g[1][0] << "\n";
        return;
    }
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        if (val[i] == mn) {
            y = x;
            x = i;
        }
    }

    vector<int> vis(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) {
            q.push(i);
            vis[i] = 1;
            cout << i << " " << g[i][0] << "\n";
            cout << i << " ";
            break;
        }
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i : g[u]) {
            if (vis[i])
                continue;
            if (i == x) {
                cout << y << "\n";
                return;
            } else if (i == y) {
                cout << x << "\n";
                return;
            }
            vis[i] = 1;
            q.push(i);
        }
    }
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