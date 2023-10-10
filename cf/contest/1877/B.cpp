#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, p;
    cin >> n >> p;
    vector<pair<ll, ll>> ab(n);
    for (auto& [i, j] : ab)
        cin >> i;
    for (auto& [i, j] : ab)
        cin >> j;
    sort(ab.begin(), ab.end(),
         [&](auto& x, auto& y) { return x.second < y.second; });
    map<ll, int> mp;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        auto [x, y] = ab[i];
        if (mp.size()) {
            ans += mp.begin()->first;
            if (--(mp.begin()->second) == 0)
                mp.erase(mp.begin());
        } else {
            ans += p;
        }
        if (y < p)
            mp[y] += x;
        // cout << ans << " ";
    }
    // cout << ", ";
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