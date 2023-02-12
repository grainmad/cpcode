#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, x, y;
    cin >> x >> y;
    cout << 2 * (x - y) << endl;
    ll u = x;
    for (ll i = x; i >= y; i--) {
        cout << i << " ";
    }
    for (ll i = y + 1; i <= x - 1; i++) {
        cout << i << " ";
    }
    cout << endl;
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
