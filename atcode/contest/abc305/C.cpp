#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 505
#define MOD 998244353
using namespace std;

string g[N];

void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    int a = N, b = N, c = 0, d = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '#') {
                a = min(a, i);
                c = max(c, i);
                b = min(b, j);
                d = max(d, j);
            }
        }
    }
    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.' && a <= i && i <= c && b <= j && j <= d) {
                x = i, y = j;
            }
        }
    }
    cout << x + 1 << " " << y + 1 << endl;
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