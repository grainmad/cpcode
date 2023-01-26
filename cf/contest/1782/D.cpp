#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 55
#define MOD 998244353
using namespace std;

ll a[N];

void sol() {
    map<ll, set<ll>> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll v = a[j] - a[i];
            for (ll x = 1; x * x <= v; x++) {
                if (v % x)
                    continue;
                ll y = v / x;
                if ((x + y) % 2 == 0 && a[j] <= (x + y) / 2 * (x + y) / 2) {
                    mp[(x + y) / 2 * (x + y) / 2 - a[j]].insert(a[i]);
                    mp[(x + y) / 2 * (x + y) / 2 - a[j]].insert(a[j]);
                }
            }
        }
    }
    int ans = 1;
    for (auto [i, j] : mp) {
        ans = max(ans, (int)j.size());
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