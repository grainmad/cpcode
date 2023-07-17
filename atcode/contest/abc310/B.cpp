#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    vector<vector<int>> f(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x;
            x--;
            f[i][x] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || p[i] < p[j])
                continue;
            int okj = 1;
            for (int k = 0; k < m; k++) {
                if (f[i][k] && !f[j][k])
                    okj = 0;
            }
            if (okj == 0)
                continue;
            if (p[i] > p[j] || count(f[i].begin(), f[i].end(), 1) <
                                   count(f[j].begin(), f[j].end(), 1)) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
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