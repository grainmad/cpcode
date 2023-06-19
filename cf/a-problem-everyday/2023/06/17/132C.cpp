
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    string s;
    int n;
    cin >> s;
    cin >> n;
    int sz = count(s.begin(), s.end(), 'T');
    if (n >= sz) {
        cout << s.size() - (n - sz) % 2 << "\n";
        return;
    }
    s.push_back('T');
    vector<int> a(2, 0);
    for (char i : s) {
        if (i == 'T')
            a.push_back(0);
        else
            a.back()++;
    }
    vector<int> p(a.size());
    for (int i = 1; i < p.size(); i++) {
        p[i] = p[i - 1] + a[i];
    }
    // for (auto i : p) {
    //     cout << i << " ";
    // }
    // cout << endl;
    int tsz = sz + 1;
    vector<vector<int>> f(a.size(), vector<int>(a.size()));
    for (int i = 1; i <= tsz; i++) {
        f[i][0] = f[i - 1][0];
        if (i % 2) {
            f[i][0] += p[i] - p[i - 1];
        } else {
            f[i][0] -= p[i] - p[i - 1];
        }
    }
    vector<vector<int>> g = f;
    for (int i = 1; i <= tsz; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k <= j; k++) {
                f[i][j] = max(f[i][j], f[i - 1 - k][j - k] +
                                           ((i - 1 - j) % 2 ? -1 : 1) *
                                               (p[i] - p[i - k - 1] + k));
                g[i][j] = min(g[i][j], g[i - 1 - k][j - k] +
                                           ((i - 1 - j) % 2 ? -1 : 1) *
                                               (p[i] - p[i - k - 1] + k));
            }
        }
    }
    // for (int i = 1; i <= tsz; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << i << " " << j << " " << f[i][j] << " " << g[i][j] <<
    //         "\n";
    //     }
    //     cout << "\n";
    // }
    // for (int i = 1; i <= tsz; i++) {
    //     cout << i << " " << n << " " << f[i][n] << " " << g[i][n] << "\n";
    // }
    // cout << s << "\n";
    int ans = 0;
    for (int i = n; i >= 0; i -= 2) {
        ans = max({ans, f[tsz][i], -g[tsz][i]});
    }
    for (int i = n - 1; i >= 0; i -= 2) {
        ans = max({ans, f[tsz][i] - 1, -g[tsz][i] + 1});
    }
    cout << ans << "\n";
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
