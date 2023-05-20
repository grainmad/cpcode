#include <bits/stdc++.h>
// #define LOCAL
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (string& i : g)
        cin >> i;
    vector<int> vis(n);
    auto dis = [&](int a, int b) {
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt += g[a][i] != g[b][i];
        }
        return cnt;
    };
    function<void(int)> dfs = [&](int x) {
        vis[x] = 1;
        for (int i = 0; i < n; i++) {
            if (vis[i])
                continue;
            if (dis(x, i) == 1)
                dfs(i);
        }
    };
    dfs(0);
    // for (int i = 0; i < n; i++) {
    //     cout << i << " " << vis[i] << "\n";
    // }
    if (count(vis.begin(), vis.end(), 1) == n) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
int main() {
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