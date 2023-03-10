#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

ll a[N];

ll ask(int x) {
    ll rt = 0;
    for (int i = x; i; i = i & (i - 1)) {
        rt += a[i];
    }
    return rt;
}

void add(int x) {
    for (int i = x; i < N; i += i & -i) {
        a[i]++;
    }
}

void sol() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    map<int, int> id;
    for (auto& [i, j] : v) {
        cin >> i >> j;
        id[j];
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) { return v[a] < v[b]; });
    // for (int i : idx) {
    //     cout << i << endl;
    //     cout << v[i].first << " " << v[i].second << endl;
    // }
    int sz = 1;
    for (auto& [i, j] : id) {
        j = sz++;
    }
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        auto [x, y] = v[idx[i]];
        ans[idx[i]] = ask(id[y]);
        add(id[y]);
    }
    for (int i : ans)
        cout << i << "\n";
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