#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll p, q;
    cin >> p >> q;
    if (p % q) {
        cout << p << "\n";
    } else {
        ll ans = 0;
        ll t = q;
        for (ll i = 2; i * i <= q; i++) {
            if (t % i)
                continue;
            ll c = 1;
            while (t % i == 0)
                c *= i, t /= i;
            ll u = p;
            while (u % i == 0)
                u /= i;
            ans = max(ans, u * c / i);
        }
        if (t != 1) {
            ll u = p;
            while (u % t == 0)
                u /= t;
            ans = max(ans, u);
        }
        cout << ans << "\n";
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