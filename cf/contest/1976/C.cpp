#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll l, r;
    cin >> l >> r;
    ll k = 1, b = 1;
    while (b * 2 * l <= r) {
        k++;
        b *= 2;
    }
    ll mx = r / b,
       ans = (mx - l + 1 +
              max(0LL, min(mx, r / (b / 2 * 3)) - l + 1) * (k - 1) % MOD) %
             MOD;
    // ll mx = r / b, ans = 0;
    // for (ll i = l; i <= mx; i++) {
    //     ans++;
    //     if (i * b / 2 * 3 <= r)
    //         ans += k - 1;
    //     ans %= MOD;
    // }
    cout << k << " " << ans << "\n";
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