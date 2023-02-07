#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 505
#define MOD 998244353
using namespace std;

int a[N][N];

void sol() {
    int n, m;
    cin >> n >> m;
    int x = -1, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        int d = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] != a[i][0])
                d = j + 1;
        }
        if (d)
            x = i, y = d;
    }
    int s = 0;
    for (int i = 0; i < n; i++)
        s ^= a[i][0];
    if (s > 0) {
        cout << "TAK\n";
        for (int i = 0; i < n; i++)
            cout << "1 ";
        cout << "\n";
        return;
    }
    if (x >= 0) {
        cout << "TAK\n";
        for (int i = 0; i < x; i++) {
            cout << "1 ";
        }
        cout << y << " ";
        for (int i = x + 1; i < n; i++) {
            cout << "1 ";
        }
        cout << "\n";
        return;
    }
    cout << "NIE\n";
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