#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    map<char, int> mp;
    for (char i : s)
        mp[i]++;
    vector<pair<char, int>> cnt(mp.begin(), mp.end());
    sort(cnt.begin(), cnt.end(),
         [](auto& a, auto& b) { return a.second > b.second; });
    // for (auto [i, j] : cnt)
    //     cout << i << " " << j << "\n";
    int sz = cnt.size();
    int mn = 1e9, p = 0;
    for (int i = 1; i <= 26; i++) {
        if (n % i == 0) {
            int r = 0;
            for (int j = 0; j < min(i, sz); j++) {
                r += min(cnt[j].second, n / i);
            }
            if (n - r < mn) {
                mn = n - r;
                p = i;
            }
        }
    }
    cout << mn << endl;
    map<char, int> v;
    for (int i = 0; i < min(sz, p); i++)
        v[cnt[i].first];
    if (p > sz) {
        int t = sz;
        for (char i = 'a'; i <= 'z'; i++) {
            if (!v.count(i))
                v[i], t++;
            if (t == p)
                break;
        }
    }
    // for (auto [i, j] : v)
    //     cout << i << " " << j << " ";
    // cout << endl;
    vector<int> vis(n);
    for (int i = 0; i < n; i++) {
        if (v.count(s[i]) && v[s[i]] < n / p) {
            v[s[i]]++;
            vis[i] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        // cout << vis[i] << " ";
        if (vis[i])
            continue;
        for (auto [x, y] : v) {
            if (y < n / p) {
                s[i] = x;
                v[x]++;
                break;
            }
        }
    }
    // cout << endl;
    cout << s << '\n';
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