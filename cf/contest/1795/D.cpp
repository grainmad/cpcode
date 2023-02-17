#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
#define MOD 998244353
using namespace std;

int v[3];
ll C(ll n, ll m) {  // n个里选m个
    ll inv[n + 1];
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    ll rt = 1;
    for (int i = m; i > 0; i--) {
        rt = rt * (n - i + 1) % MOD * inv[i] % MOD;
    }
    return rt;
}
void sol() {
    int n;
    cin >> n;
    ll ans = 1;
    for (int i = 0; i < n / 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[j];
        }
        sort(v, v + 3);
        if (v[0] == v[1] && v[0] == v[2]) {
            ans *= 3;
            ans %= MOD;
        } else if (v[1] == v[0]) {
            ans *= 2;
            ans %= MOD;
        }
    }
    cout << ans * C(n / 3, n / 6) % MOD << endl;
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