
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
    vector<vector<int>> a(n, vector<int>(m));
    for (auto& i : a) {
        for (auto& j : i) {
            cin >> j;
        }
    }
    int ans1, ans2;
    ll l = 0, r = 1e9 + 7;
    while (l < r) {
        // cout << l << ' ' << r << endl;
        ll mid = l + r >> 1;
        vector<int> st(1 << m);
        for (int i = 0; i < n; i++) {
            int u = 0;
            for (int j = 0; j < m; j++) {
                u <<= 1;
                if (a[i][j] >= mid)
                    u |= 1;
            }
            st[u] = i + 1;
        }
        int ok = 0;
        for (int i = 0; i < (1 << m); i++) {
            for (int j = 0; j < (1 << m); j++) {
                if (st[i] && st[j] && (i | j) == (1 << m) - 1) {
                    ans1 = st[i], ans2 = st[j];
                    ok = 1;
                }
            }
        }
        if (ok)
            l = mid + 1;
        else
            r = mid;
    }
    cout << ans1 << " " << ans2 << "\n";
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
