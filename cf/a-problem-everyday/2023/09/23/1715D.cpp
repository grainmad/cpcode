
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    int n, q;
    cin >> n >> q;
    vector<vector<pair<ll, ll>>> g(n+1);
    vector<ll> ans(n+1, (1LL<<31)-1);
    for (int i=0; i<q; i++) {
        ll x, y, v;
        cin >> x >> y >> v;
        g[x].emplace_back(y, v);
        g[y].emplace_back(x, v);
        ans[x] &= v;
        ans[y] &= v;
    }
    for (int i=1; i<=n; i++) {
        int res = 0;
        for (auto [j, v]: g[i]) {
            if (j == i) {
                res = v;
                break;
            }
            res |= ans[j]^v;
        }
        ans[i] = res;
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    } cout << endl;
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
