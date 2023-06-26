#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll f[105][105];

void sol() {
    int n, m;
    cin >> n >> m;

    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i < n; i++)
        f[i][i] = 0;
    for (int i = 0; i < m; i++) {
        ll x, y, k;
        cin >> x >> y >> k;
        f[x][y] = f[y][x] = min(f[x][y], k);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    if (f[1][n] > 1e18) {
        cout << "inf\n";
        return;
    }
    vector<pair<string, ll>> ans;
    vector<pair<ll, ll>> v;
    for (int i = 1; i < n; i++) {
        v.emplace_back(min(f[1][n], f[i][n]), i);
    }
    sort(v.begin(), v.end());
    ll pre = 0;
    for (int i = 0; i < v.size(); i++) {
        auto [x, y] = v[i];
        ll dif = x - pre;
        pre = x;
        if (dif == 0)
            continue;
        string s(n, '0');
        for (int j = i; j < v.size(); j++) {
            s[v[j].second - 1] = '1';
        }
        ans.emplace_back(s, dif);
    }
    cout << f[1][n] << " " << ans.size() << "\n";
    for (auto& [i, j] : ans) {
        cout << i << " " << j << "\n";
    }
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
