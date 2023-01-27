#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < 2 * k; i++) {
        int x, y;
        cin >> x >> y;
    }
    cout << m * n + m + n - 2 << "\n";
    for (int i = 1; i < m; i++) {
        cout << "L";
    }
    for (int i = 1; i < n; i++) {
        cout << "U";
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (i % 2)
                cout << "L";
            else
                cout << "R";
        }
        cout << "D";
    }
    cout << "\n";
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