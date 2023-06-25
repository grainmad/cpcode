#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353

using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    ll a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a += x;
    }
    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        b += x;
    }
    if (a > b) {
        cout << "Tsondu\n";
    } else if (a < b) {
        cout << "Tenzing\n";
    } else {
        cout << "Draw\n";
    }
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