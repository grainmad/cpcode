
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
    vector<vector<int>> a(n);
    map<int, int> id;
    for (int i = 0; i < n; i++) {
        int k, mx = 0;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            if (x > mx) {
                a[i].push_back(x);
                id[x];
                mx = x;
            }
        }
    }
    // for (auto& i : a) {
    //     for (auto& j : i) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    int sz = 0;
    for (auto& [i, j] : id) {
        j = ++sz;
        // cout << i << " -- " << j << "\n";
    }

    map<int, vector<pair<int, int>>> mp;
    for (auto& i : a) {
        int isz = i.size();
        for (int j = 0; j < isz; j++) {
            mp[id[i[j]]].emplace_back(id[i.back()], isz - j);
        }
    }
    vector<int> dp(sz + 1);
    for (int i = 1; i <= sz; i++) {
        for (auto& [x, y] : mp[i]) {
            dp[x] = max(dp[x], dp[i - 1] + y);
        }
        dp[i] = max(dp[i - 1], dp[i]);
    }
    // for (int i = 0; i <= sz; i++) {
    //     cout << dp[i] << ", ";
    // }
    cout << dp[sz] << "\n";
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
