
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 605
#define MOD 998244353
using namespace std;

int a[N], b[N], f[N][N];

void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int j = 1; j <= m; j++) {
        f[1][a[1] & b[j]] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 1 << 9; j++) {
            if (f[i][j] == 1) {
                for (int k = 1; k <= m; k++) {
                    f[i + 1][j | a[i + 1] & b[k]] = 1;
                }
            }
        }
    }
    for (int i = 0; i < 1 << 9; i++) {
        if (f[n][i] == 1) {
            cout << i << "\n";
            return;
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
