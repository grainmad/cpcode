#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<pair<int, int>> v(mp.begin(), mp.end());

    int ans = v.back().second;
    for (int i = 1; i < v.size(); i++) {
        if (v[i - 1].first + 1 < v[i].first) {
            ans += v[i - 1].second;
        } else if (v[i - 1].second > v[i].second) {
            ans += v[i - 1].second - v[i].second;
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