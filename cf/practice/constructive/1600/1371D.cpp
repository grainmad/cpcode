#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 305
#define MOD 998244353
using namespace std;

int a[N][N];

void sol() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            a[i][j] = 0;
    }
    int x = 0, y = 0;
    while (k--) {
        a[x][y] = 1;
        x = (x + 1) % n;
        y = (y + 1) % n;
        if (x == 0)
            y = (y + 1) % n;
    }
    int rmx = 0, rmn = n, cmx = 0, cmn = n;
    for (int i = 0; i < n; i++) {
        int r = 0, c = 0;
        for (int j = 0; j < n; j++) {
            r += a[i][j];
            c += a[j][i];
        }
        rmx = max(rmx, r);
        rmn = min(rmn, r);
        cmx = max(cmx, c);
        cmn = min(cmn, c);
    }
    cout << (rmx - rmn) * (rmx - rmn) + (cmx - cmn) * (cmx - cmn) << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
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