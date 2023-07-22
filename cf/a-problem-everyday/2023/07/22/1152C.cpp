
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    ll x = b - a, mn = a * b / gcd(a, b), ans = 0;
    auto upd = [&](ll f) {
        ll k = f - a % f;
        if ((a + k) * (b + k) / f < mn) {
            mn = (a + k) * (b + k) / f;
            ans = k;
        }
    };
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            upd(i);
            upd(x / i);
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
