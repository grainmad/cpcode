#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 100005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(m);
    for (auto& [i, j] : v) {
        cin >> i >> j;
    }
    sort(v.begin(), v.end());
    vector<ll> p(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        p[i] = p[i - 1] + v[i - 1].first;
    }
    vector<ll> a;
    for (auto& [i, j] : v)
        a.push_back(i);
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ll pos = upper_bound(a.begin(), a.end(), v[i].second) - a.begin();
        pos = max(pos, m - n);
        if (m - pos == n) {
            ans = max(p[m] - p[pos], ans);
        } else {
            ans =
                max(ans, p[m] - p[pos] + (pos > i ? a[i] : 0) +
                             (n - (m - pos) - (pos > i ? 1 : 0)) * v[i].second);
        }
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