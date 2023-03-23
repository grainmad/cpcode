#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<int> d(n);
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0 && s[j][i] == s[j][i - 1]) {
                d[j]++;
            } else {
                d[j] = 1;
            }
        }
        // for (int i : d)
        //     cout << i << " ";
        // cout << endl;
        for (int j = 0, k; j < n; j = k) {
            k = j;
            int mn = d[j];
            while (k < n && s[k][i] == s[j][i])
                mn = min(mn, d[k++]);
            int sz = k - j;
            // cout << j << " " << k << endl;
            if (j - sz < 0 || k + sz > n)
                continue;
            bool ok = 1;
            for (int u = j - sz; u < j; u++) {
                if (s[j - sz][i] != s[u][i])
                    ok = 0;
                mn = min(mn, d[u]);
            }
            for (int u = k; u < k + sz; u++) {
                if (s[k][i] != s[u][i])
                    ok = 0;
                mn = min(mn, d[u]);
            }
            if (ok)
                ans += mn;
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