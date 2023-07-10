
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        g[i].push_back(i);
    }
    for (int i = n + 1; i <= n + m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(i);
        g[y].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << g[i].size() << "\n";
        for (int j : g[i]) {
            cout << j << " " << i << "\n";
        }
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
