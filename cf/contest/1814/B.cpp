#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll a, b;
    cin >> a >> b;
    ll ans = 1e10;
    for (ll i = 1, sz = 2 * sqrt(2 * max(a, b)); i <= sz; i++) {
        ans = min(ans, (a + i - 1) / i + (b + i - 1) / i + i - 1);
    }
    cout << ans << "\n";
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