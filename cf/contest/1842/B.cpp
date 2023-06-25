#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353

using namespace std;

bool check(ll a, ll b) {
    for (int i = 0; i < 32; i++) {
        if ((a >> i & 1) && !(b >> i & 1))
            return false;
    }
    return true;
}

void sol() {
    ll n, x;
    cin >> n >> x;
    ll c = 0;
    for (int _ = 0; _ < 3; _++) {
        int b = 0;
        for (int i = 0; i < n; i++) {
            ll v;
            cin >> v;
            if (b)
                continue;
            if (check(v | c, x))
                c |= v;
            else
                b = 1;
        }
    }
    cout << (c == x ? "YES\n" : "NO\n");
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