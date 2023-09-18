
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 1000000007
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& i : a)
        cin >> i;
    vector<int> sf(61);
    for (int j = 0; j <= 60; j++) {
        for (ll i : a) {
            sf[j] += (i >> j & 1);
        }
    }
    // f(x, c) = x>>c&1
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll p = 1, x = 0, y = 0;
        for (int j = 0; j <= 60; j++) {
            ll b = a[i] >> j & 1;
            x += p * b % MOD * sf[j] % MOD;
            x %= MOD;
            y += p * (n - (1 - b) * (n - sf[j]) % MOD) % MOD;
            y %= MOD;
            p *= 2;
            p %= MOD;
        }
        ans += x * y % MOD;
        ans %= MOD;
    }
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
