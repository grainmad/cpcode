#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll x;
    cin >> x;
    if (x % 2) {
        cout << "-1\n";
        return;
    }
    // ll a = 0, b = 0;
    for (int i = 1; i < 33; i++) {
        if (x >> i & 1) {
            if (x >> (i - 1) & 1) {
                cout << "-1\n";
                return;
            }
            // a |= 1 << (i - 1);
            // a |= 1 << i;
            // b |= 1 << (i - 1);
        }
    }
    // cout << a << " " << b << "\n";
    cout << (x >> 1 | x) << " " << (x >> 1) << "\n";
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