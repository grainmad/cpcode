#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    int mn = 1e9 + 7, mx = 0, len = 1e9 + 7;
    vector<pair<int, int>> itv;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        itv.emplace_back(l, r);
        mn = min(mn, r);
        mx = max(mx, l);
        len = min(len, r - l + 1);
    }
    // cout << mn << " " << mx << " " << len << endl;
    int ans = 0;
    for (auto [l, r] : itv) {
        ans =
            max({ans, r - max(l - 1, mn), min(r + 1, mx) - l, r - l + 1 - len});
    }
    cout << 2 * ans << "\n";
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