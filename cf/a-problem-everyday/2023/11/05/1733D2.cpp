
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    ll n, x, y;
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;
    vector<int> v;
    for (int i=0; i<n; i++) {
        if (a[i] != b[i]) v.push_back(i);
    }
    int sz = v.size();
    if (sz == 0) {
        cout << "0\n";
        return ;
    }
    if (sz%2) {
        cout << "-1\n";
        return ;
    }
    if (x >= y) {
        if (sz == 2) {
            cout << (v[0]+1 == v[1] ? min(2*y, x) : y) << "\n";
        } else {
            cout << sz/2*y << "\n";
        }
        return ;
    }
    ll INF = 1e18;
    vector<vector<ll>> dp(sz, vector<ll>(sz, INF));
    auto cost = [&](int l, int r)->ll {
        return v[l] + 1 == v[r] ? min(2*y, x) : min((v[r]-v[l])*x, y);
    };
    auto dfs = [&](auto self, int l, int r) {
        if (dp[l][r] != INF) return dp[l][r];
        if (l+1 == r) {
            return dp[l][r] = cost(l, r);
        }
        dp[l][r] = min({dp[l][r], 
                          cost(l,l+1)+self(self, l+2, r), 
                          cost(r-1, r)+self(self, l, r-2), 
                          cost(l, r)+self(self, l+1, r-1)});
        return dp[l][r];
    };
    cout << dfs(dfs, 0, sz-1) << "\n"; 
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
