
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 1;
    auto check = [&](ll x) {
        int c = 0;
        for (ll i : a) {
            ll s = sqrt(i + x);
            if (s * s == x + i) {
                c++;
            }
        }
        ans = max(ans, c);
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll pq = a[j] - a[i];
            for (int k = 1; k * k <= pq; k++) {
                if (pq % k == 0) {
                    ll p = (k + pq / k) / 2;
                    if (p * p - a[j] >= 0) {
                        check(p * p - a[j]);
                    }
                }
            }
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
