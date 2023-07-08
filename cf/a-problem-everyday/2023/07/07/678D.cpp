
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 1000000007
using namespace std;

ll fpow(ll a, ll p) {
    ll rt = 1;
    while (p) {
        if (p & 1)
            rt *= a, rt %= MOD;
        a *= a;
        a %= MOD;
        p >>= 1;
    }
    return rt;
}

void sol() {
    ll a, b, n, x;
    cin >> a >> b >> n >> x;
    ll p1 = fpow(a, n % (MOD - 1)) * x % MOD;
    ll p2 = b;
    if (a == 1)
        p2 = n % MOD * p2 % MOD;
    else
        p2 = p2 * (fpow(a, n % (MOD - 1)) - 1) % MOD * fpow(a - 1, MOD - 2) %
             MOD;
    cout << (p1 + p2) % MOD << "\n";
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
