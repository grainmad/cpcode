
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[j][i];
        }
    }
    sort(a.begin(), a.end(), [](auto& x, auto& y) {
        return *max_element(x.begin(), x.end()) > *max_element(y.begin(), y.end());
    });
    int sz = min(n,m), ans = 0;
    vector<int> c(sz);
    auto dfs = [&](auto self, int x) {
        if (x == sz) {
            int s = 0;
            for (int i=0; i<n; i++) {
                int mx = 0;
                for (int j=0; j<sz; j++) {
                    mx = max(mx, a[j][(i+c[j])%n]);
                }
                s += mx;
            }
            ans = max(ans, s);
            return ;
        }
        for (int i=0; i<n; i++) {
            c[x] = i;
            self(self, x+1);
        }
    };
    dfs(dfs, 0);
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
