#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353

using namespace std;

int ok(ll x, ll k) {
    int s = 0;
    while (x) {
        s += x % 10;
        x /= 10;
    }
    return s % k == 0;
}

void sol() {
    ll x, k;
    cin >> x >> k;
    while (!ok(x, k)) {
        x++;
    }
    cout << x << "\n";
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