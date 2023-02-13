#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a, ans(n), cnt(n + 1), idx(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx = max(mx, ++cnt[x]);
    }
    if (mx > (n + 1) / 2) {
        cout << "0\n";
        return;
    }
    iota(idx.begin(), idx.end(), 1);
    sort(idx.begin(), idx.end(), [&](int x, int y) { return cnt[x] > cnt[y]; });
    for (int i = 0; i < n; i++) {
        // cout << idx[i] << " " << cnt[idx[i]] << endl;
        if (cnt[idx[i]]) {
            for (int j = 0; j < cnt[idx[i]]; j++)
                a.push_back(idx[i]);
        }
    }
    int l = 1, r = n;
    while (l < r) {
        int m = l + r >> 1;
        int p = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i; j < n; j += m) {
                ans[j] = a[p++];
            }
        }
        int ok = 1;
        for (int i = 1; i < n; i++) {
            if (ans[i] == ans[i - 1])
                ok = 0;
        }
        if (ok) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << r - 2 << "\n";
    // for (int i : a) {
    //     cout << i << " ";
    // }
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