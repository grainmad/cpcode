#include <bits/stdc++.h>
// #define LOCAL
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

int dx[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[8] = {1, 0, -1, 0, -1, -1, 1, 1};
int n, m;
string g[200];

string dfs(int x, int y, int d, int cnt) {
    if (cnt == 0)
        return "";
    if (x < 0 || x >= n || y < 0 || y >= m)
        return "";
    return g[x][y] + dfs(x + dx[d], y + dy[d], d, cnt - 1);
}

void pr(int x, int y, int d, int cnt) {
    if (cnt == 0)
        return;
    cout << x + 1 << " " << y + 1 << "\n";
    pr(x + dx[d], y + dy[d], d, cnt - 1);
}

void sol() {
    cin >> n >> m;
    for (string& i : g)
        cin >> i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 8; k++) {
                if (dfs(i, j, k, 5) == "snuke") {
                    pr(i, j, k, 5);
                    return;
                }
            }
        }
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