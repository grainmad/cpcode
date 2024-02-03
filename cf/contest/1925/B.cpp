#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    ll x, n;
    cin >> x >> n;
    ll ans = 0;
    for (ll i=1; i*i<=x; i++) {
        if (x%i == 0) {
            if (i>=n) ans = max(ans, x/i);
            if (x/i>=n) ans = max(ans, i);
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