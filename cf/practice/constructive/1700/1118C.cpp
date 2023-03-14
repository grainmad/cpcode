#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 1005
#define MOD 998244353
using namespace std;

int st[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        int x;
        cin >> x;
        st[x]++;
    }
    vector<vector<int>> g(n, vector<int>(n));
    int p1 = 0, p2 = 0, p3 = 0, o = n % 2, sz = n / 2;
    for (int i = 1; i <= 1000; i++) {
        while (st[i] >= 4 && p1 < sz * sz) {
            // g[p1 / sz][p1 % sz] = i;
            // g[p1 % sz][n - 1 - p1 / sz] = i;
            // g[n - 1 - p1 % sz][p1 / sz] = i;
            // g[n - 1 - p1 / sz][n - 1 - p1 % sz] = i;
            g[p1 / sz][p1 % sz] = i;
            g[p1 / sz][n - 1 - p1 % sz] = i;
            g[n - 1 - p1 / sz][p1 % sz] = i;
            g[n - 1 - p1 / sz][n - 1 - p1 % sz] = i;
            p1++;
            st[i] -= 4;
        }
        while (st[i] >= 2 && p2 < sz) {
            g[sz][p2] = g[sz][n - 1 - p2] = i;
            p2++;
            st[i] -= 2;
        }
        while (st[i] >= 2 && p3 < sz) {
            g[p3][sz] = g[n - 1 - p3][sz] = i;
            p3++;
            st[i] -= 2;
        }
        if (st[i] == 1 && o) {
            g[sz][sz] = i;
            st[i]--;
            o--;
        }
        // if (st[i]) {
        //     cout << "NO\n";
        //     return;
        // }
    }
    // check
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] != g[n - 1 - i][j] || g[i][j] != g[i][n - 1 - j] ||
                g[i][j] == 0) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for (auto& i : g) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << "\n";
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