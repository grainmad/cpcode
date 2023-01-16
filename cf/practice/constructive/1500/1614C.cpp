// 16:30
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

ll M = 1e9 + 7;

void sol() {
    int n, m;
    cin >> n >> m;
    ll s = 0;
    for (int i = 0; i < m; i++) {
        ll l, r, x;
        cin >> l >> r >> x;
        s |= x;
    }
    ll p = 1;
    for (int i = 1; i < n; i++) {
        p <<= 1;
        p %= M;
    }
    cout << s * p % M << "\n";
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