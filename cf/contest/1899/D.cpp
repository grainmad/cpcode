#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll, int> mp;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        for (ll j = 31; j >= 1; j--) {
            if ((j + x) % x == 0 && (j + x) / x == (x << j) && mp.count(j + x))
                ans += mp[j + x];
        }
        if (x < 32) {
            for (ll j = x; j >= 1; j--) {
                if (x % j == 0 && x / j == (1LL << x - j) && mp.count(j)) {
                    ans += mp[j];
                }
            }
        }
        if (x >= 32)
            ans += mp[x];
        mp[x]++;
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