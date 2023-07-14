
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll& i : a)
        cin >> i;
    ll l = 1, r = 3e17;
    while (l < r) {
        ll m = (r - l) / 2 + l;
        ll cnt = 0;
        vector<ll> b = a;
        for (int i = 0; i < n; i++) {
            if (b[i] >= m) {
                cnt += b[i] / m;
                b[i] %= m;
            }
            if (i + 1 < n && b[i] + b[i + 1] >= m) {
                cnt++;
                b[i + 1] -= m - b[i];
                b[i] = 0;
            }
        }
        // cout << m << " " << cnt << endl;
        if (cnt >= k) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << (r - 1) * k << "\n";
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
