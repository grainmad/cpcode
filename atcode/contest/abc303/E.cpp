#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

vector<int> g[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> ans;
    function<int(int, int)> dfs = [&](int u, int fa) {
        int rt = 0;
        for (int v : g[u]) {
            if (v == fa)
                continue;
            rt = dfs(v, u);
        }
        if (rt == 1) {
            ans.push_back(g[u].size());
        }
        return (rt + 1) % 3;
    };
    if (dfs(1, 0) == 1)
        ans.push_back(g[1].size());
    sort(ans.begin(), ans.end());
    for (int i : ans)
        cout << i << " ";
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