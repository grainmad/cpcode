#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(n);
    for (auto& i : a)
        cin >> i;
    ll p = -1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > q) {
            if (i - p - 1 >= k)
                ans += (i - p - k + 1) * (i - p - k) / 2;
            p = i;
        }
    }
    if (n - p - 1 >= k)
        ans += (n - p - k + 1) * (n - p - k) / 2;
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