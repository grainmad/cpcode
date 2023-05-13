#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll& i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    vector<ll> p(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + a[i - 1];
    }
    ll ans = p[n] - p[2 * k];
    for (int i = 1; i <= k; i++) {
        ans = max(ans, p[n - i] - p[2 * (k - i)]);
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