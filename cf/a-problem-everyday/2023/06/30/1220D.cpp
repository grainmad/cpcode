
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n;
    cin >> n;
    vector<ll> cnt(100), a(n);
    ll mx = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        ll c = 0;
        for (ll j = a[i]; j % 2 == 0; j >>= 1)
            c++;
        mx = max(mx, ++cnt[c]);
    }
    cout << n - mx << "\n";
    int p = 0;
    for (ll i : a) {
        ll c = 0;
        for (ll j = i; j % 2 == 0; j >>= 1)
            c++;
        if (cnt[c] == mx) {
            p = c;
            break;
        }
    }
    for (ll i : a) {
        ll c = 0;
        for (ll j = i; j % 2 == 0; j >>= 1)
            c++;
        if (c != p) {
            cout << i << " ";
        }
    }
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
