#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& i : a)
        cin >> i;
    ll ans = 0, p = 0;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            ll t = a[i];
            while (a[i - 1] > t) {
                t *= 2;
                p++;
            }
        } else {
            ll t = a[i];
            while (a[i - 1] <= t / 2) {
                t /= 2;
                p--;
            }
            p = max(0LL, p);
        }
        // cout << p << ", ";
        ans += p;
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