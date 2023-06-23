
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
const ll MOD = 1e9 + 7;
using namespace std;

ll fac[N], inv_fac[N];
ll fpow(ll x, ll p, ll m) {
    ll rt = 1;
    while (p) {
        if (p & 1)
            rt *= x, rt %= m;
        x *= x;
        x %= m;
        p >>= 1;
    }
    return rt;
}
void pre() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv_fac[N - 1] = fpow(fac[N - 1], MOD - 2, MOD);
    for (int i = N - 2; i >= 0; i--) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
    }
}

void sol() {
    pre();
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        int x;
        cin >> x;
        if (x) {
            ans += fac[i + x] * inv_fac[i + 1] % MOD * inv_fac[x - 1] % MOD;
            ans %= MOD;
        }
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
