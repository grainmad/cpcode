#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m, k;
    cin >> n >> m >> k;
    if (n % 2) {
        if (m / 2 <= k && k <= m * n / 2 && (k - m / 2) % 2 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        if (k % 2 == 0 && 0 <= k && k <= m / 2 * n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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