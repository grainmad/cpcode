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
    for (ll& i : a)
        cin >> i;
    auto dif = [&](int k) {
        ll mx = 0, mn = 1e18, cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += a[i];
            if (i % k == k - 1) {
                mx = max(mx, cnt);
                mn = min(mn, cnt);
                cnt = 0;
            }
        }
        return mx - mn;
    };
    ll ans = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i)
            continue;
        ans = max(ans, dif(i));
        ans = max(ans, dif(n / i));
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