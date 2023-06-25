
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(n);
    for (auto& [i, j] : v)
        cin >> i >> j;
    vector<ll> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) {
        return v[x].first - v[x].second < v[y].first - v[y].second;
    });
    // for (int i : idx) {
    //     cout << v[i].first << " " << v[i].second << "\n";
    // }
    vector<ll> pre(n), suf(n);
    pre[0] = v[idx[0]].first;
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + v[idx[i]].first;
    }
    suf[n - 1] = v[idx[n - 1]].second;
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] + v[idx[i]].second;
    }
    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        ans[idx[i]] = (suf[i] - v[idx[i]].second) +
                      (n - i - 1) * v[idx[i]].first +
                      (pre[i] - v[idx[i]].first) + i * v[idx[i]].second;
    }
    // for (auto i : ans) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        ll sub = min(v[x].first + v[y].second, v[x].second + v[y].first);
        ans[x] -= sub;
        ans[y] -= sub;
    }
    for (auto i : ans) {
        cout << i << " ";
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
