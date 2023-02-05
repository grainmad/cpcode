#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 1000005
#define MOD 998244353
using namespace std;

ll a[N], b[N], c[N], d[N];

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

ll mi(ll x) {
    return (x % MOD + MOD) % MOD;
}

ll inv(ll x) {
    return fpow(mi(x), MOD - 2);
}

void sol() {
    ll n;
    cin >> n;
    string x, y;
    cin >> x >> y;
    int dif = 0;
    for (int i = 0; i < n; i++) {
        dif += x[i] != y[i];
    }
    if (dif == 0) {
        cout << "0\n";
        return;
    }
    a[1] = 1, b[1] = mi((n - 1) * inv(n)), c[n] = 1, d[n] = 1;
    for (int i = 2; i <= n; i++) {
        a[i] = mi(mi(n + i * a[i - 1]) * inv(n - i * b[i - 1]));
        b[i] = mi((n - i) * inv(n - i * b[i - 1]));
    }
    for (int i = n - 1; i >= 1; i--) {
        c[i] = mi(mi(n + (n - i) * c[i + 1]) * inv(n - (n - i) * d[i + 1]));
        d[i] = mi(i * inv(n - (n - i) * d[i + 1]));
    }
    cout << mi(mi(c[dif] + d[dif] * a[dif - 1]) * inv(1 - d[dif] * b[dif - 1]))
         << "\n";
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