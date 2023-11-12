#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

int fa[N];

int getfa(int x) {
    if (fa[x] == -1)
        return x;
    return getfa(fa[x]);
}

void sol() {
    memset(fa, -1, sizeof(fa));
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> x(m), y(m), w(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i] >> w[i];
    }

    ll ans = 1e17;
    ll tans = 0;
    auto dfs = [&](auto self, int c, int cnt) {
        if (cnt == n - 1) {
            ans = min(ans, tans % k);
            return;
        }
        if (c == m)
            return;
        int u = getfa(x[c]), v = getfa(y[c]);
        if (u != v) {
            fa[u] = v;
            tans += w[c];
            self(self, c + 1, cnt + 1);
            tans -= w[c];
            fa[u] = -1;
        }
        self(self, c + 1, cnt);
    };
    dfs(dfs, 0, 0);
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