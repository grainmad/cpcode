#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, x, y;
    cin >> n >> x >> y;
    ll t = lcm(x, y);
    ll ans = 0;
    // for (int i = 0; i < n / x - n / t; i++) {
    //     ans += n - i;
    // }
    ll u = n / x - n / t;
    ans += (2 * n - u + 1) * u / 2;
    // for (int i = 0; i < n / y - n / t; i++) {
    //     ans -= i + 1;
    // }
    u = n / y - n / t;
    ans -= (1 + u) * u / 2;
    cout << ans << "\n";
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