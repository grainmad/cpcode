
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 1000000007
using namespace std;

ll fpow(ll a, ll p, ll m) {
    ll rt = 1;
    while (p) {
        if (p & 1)
            rt *= a, rt %= m;
        a = a * a % m;
        p >>= 1;
    }
    return rt;
}

void sol() {
    int k;
    cin >> k;
    vector<ll> v(k);
    int o = 1;
    ll res = 2, mod3 = 2;
    for (ll& i : v) {
        cin >> i;
        res = fpow(res, i, MOD);
        mod3 = fpow(mod3, i, 3);
        if (i % 2 == 0)
            o = 0;
    }
    res = res * fpow(2, MOD - 2, MOD) % MOD;
    mod3 = mod3 * fpow(2, 1, 3) % MOD;
    if (o) {
        if ((mod3 + 2) % 3 == 0)  // p = 2^{k-1}-1 / 3  q = 2^{k-1}
            cout << (res - 1 + MOD) % MOD * fpow(3, MOD - 2, MOD) % MOD << "/"
                 << res << "\n";
        else  // p = 2^{k-1}-1  q = 2^{k-1}*3
            cout << (res - 1 + MOD) % MOD << "/" << res * 3 % MOD << "\n";
    } else {
        if ((mod3 + 1) % 3 == 0)  // p = 2^{k-1}+1 / 3  q= 2^{k-1}
            cout << (res + 1) % MOD * fpow(3, MOD - 2, MOD) % MOD << "/" << res
                 << "\n";
        else  // p = 2^{k-1}+1  q= 2^{k-1}*3
            cout << (res + 1) % MOD << "/" << res * 3 % MOD << "\n";
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
