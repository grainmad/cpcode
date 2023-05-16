
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 300005
#define MOD 998244353
using namespace std;

ll fpow(ll x, ll p) {
    ll rt = 1;
    while (p) {
        if (p & 1)
            rt = rt * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return rt;
}

ll fac[N], inv[N];

ll a[N];

void sol() {
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    if (a[n] % 2) {
        cout << fpow(m, n) << "\n";
        return;
    }

    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv[N - 1] = fpow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }

    ll k = 0;
    map<ll, int> mp;
    mp[0] = 0;
    for (int i = 1; i < n; i++) {
        if (mp.count(a[i] - a[n] / 2)) {
            k++;
        }
        mp[a[i]] = i;
    }

    ll ans = 0;
    for (ll x = 0; x <= min(m, k); x++) {
        ll r = 1;
        r = r * fac[k] % MOD;
        r = r * inv[k - x] % MOD;
        r = r * inv[x] % MOD;
        r = r * fac[m] % MOD;
        r = r * inv[m - x] % MOD;
        r = r * fpow((m - x) * (m - x - 1) % MOD, k - x) % MOD;
        r = r * fpow(m - x, n - 2 * k) % MOD;
        ans += r;
        ans %= MOD;
    }
    cout << ans << "\n";
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
