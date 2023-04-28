
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, m;
    cin >> n >> m;
    if (m >= n) {
        cout << n << "\n";
    } else {
        ll l = 0, r = 2e9;
        while (l < r) {
            ll x = (r - l) / 2 + l;
            if (n - m <= (1LL + x) * x / 2) {
                r = x;
            } else {
                l = x + 1;
            }
        }
        cout << r + m << "\n";
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
