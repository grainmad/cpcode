#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 105
#define MOD 998244353
using namespace std;

int f[2][N][N * N];

void sol() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int u = i % 2, v = 1 - i % 2;
        memset(f[v], 0x3f, sizeof(f[v]));
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= j * (i - j); k++) {
                f[v][j + 1][k] =
                    min(f[v][j + 1][k], f[u][j][k] + (s[i] == '1'));
                f[v][j][k + j] =
                    min(f[v][j][k + j], f[u][j][k] + (s[i] == '0'));
            }
        }
    }
    int c0 = count(s.begin(), s.end(), '0');
    // all n*(n-1)/2
    // 00 c0*(c0-1)/2
    // 11 c1*(c1-1)/2, c1 = n-c0
    // 01 or 10 c0*c1/2
    cout << f[n % 2][c0][c0 * (n - c0) / 2] / 2 << "\n";
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