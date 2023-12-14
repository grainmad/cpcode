
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n+1);
    vector<ll> c(n+1);
    vector<vector<pair<int,ll>>> h(n+1);
    for (int i=2; i<=n; i++) {
        int x; cin >> x;
        g[x].push_back(i);
    }
    for (int i=1; i<=n; i++) {
        cin >> c[i];
    }
    auto dfs = [&](auto self, int x, int k) {
        for (auto [i,j]:h[x]) {
            if (i == k) return j;
        }
        int sz = g[x].size();
        ll res = k*c[x];
        if (sz == 0) {
            h[x].emplace_back(k, res);
            return res;
        }
        int a = k/sz, b = k%sz;
        if (b == 0) {
            for (auto y:g[x]) {
                res += self(self, y, a);
            }
        } else {
            vector<ll> t1, t2, t3;
            for (auto y:g[x]) {
                t1.push_back(self(self, y, a));
            }
            for (auto y:g[x]) {
                t2.push_back(self(self, y, a+1));
            }
            for (int i=0; i<sz; i++) {
                t3.push_back(t2[i]-t1[i]);
            }
            sort(t3.rbegin(), t3.rend());
            for (int i=0; i<sz; i++) {
                res += t1[i];
                if (i<b) res += t3[i];
            }
        }
        h[x].emplace_back(k, res);
        return res;
    };
    cout << dfs(dfs, 1, k) << endl;
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
