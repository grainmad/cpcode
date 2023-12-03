#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, p, l, t;
    cin >> n >> p >> l >> t;
    ll tsk = (n + 6) / 7;
    ll cur = 0;
    ll L = 0, R = n;
    while (L < R) {
        ll m = L + R >> 1;
        ll cur = m * l + min(m * 2 * t, tsk * t);
        if (cur >= p) {
            R = m;
        } else {
            L = m + 1;
        }
    }
    cout << n - R << "\n";
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