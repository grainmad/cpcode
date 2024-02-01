#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    ll a, b, r;
    cin >> a >> b >> r;
    ll ans = 0;
    if (a>b) swap(a, b);
    int fst = 1;
    for (int i=62; i>=0; i--) {
        ll x = a>>i&1;
        ll y = b>>i&1;
        if (x == y) continue;
        if (y) {
            if (!fst) {
                if ((1LL<<i) <= r) {
                    r -= (1LL<<i);
                    ans -= (1LL<<i);
                } else {
                    ans += (1LL<<i);
                }
            } else {
                ans += 1LL<<i;
                fst = 0;
            }
        } else {
            ans -= (1LL<<i);
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