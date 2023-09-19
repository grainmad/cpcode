#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    map<int, int> mp;
    auto add = [&](int left, int right) {
        for (auto it = mp.lower_bound(left);
             it != mp.end() && it->second <= right; mp.erase(it++)) {
            int l = it->second, r = it->first;
            left = min(left, l);
            right = max(right, r);
        }
        mp[right] = left;
    };
    int n;
    cin >> n;
    vector<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        s.emplace_back(l, b);
        add(l, b);
    }
    // cout << "------\n";
    // for (auto [i, j] : mp) {
    //     cout << i << " " << j << endl;
    // }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        auto it = mp.lower_bound(x);
        cout << (it != mp.end() && it->second <= x ? it->first : x) << " ";
    }
    cout << "\n";
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