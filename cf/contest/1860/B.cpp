#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    ll x = m / k, y = m % k;
    ll ans1 = max(0LL, y - a1);
    ll t = max(0LL, (a1 - y) / k);
    ll ans2 = max(0LL, x - ak - t);
    cout << ans1 + ans2 << "\n";
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