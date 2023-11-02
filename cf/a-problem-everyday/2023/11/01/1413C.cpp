
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    vector<ll> a(6);
    for (auto& i : a)
        cin >> i;
    sort(a.begin(), a.end());
    int n;
    cin >> n;
    vector<pair<ll, ll>> b;
    vector<int> c(n);
    int cnt = 0;
    // set<ll> st;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        for (int j = 0; j < 6; j++) {
            b.emplace_back(x - a[j], i);
        }
    }
    sort(b.begin(), b.end());
    int sz = b.size();
    // for (auto [i, j] : b) {
    //     cout << i << " " << j << endl;
    // }
    ll ans = 1e9 + 7;
    for (int l = 0, r = 0; l < sz; l++) {
        while (cnt < n && r < sz) {
            if (++c[b[r++].second] == 1)
                cnt++;
        }
        // cout << l << ' ' << r << endl;
        if (cnt == n)
            ans = min(ans, b[r - 1].first - b[l].first);
        if (--c[b[l].second] == 0)
            cnt--;
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
