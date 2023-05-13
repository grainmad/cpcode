#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 1000000007
using namespace std;

vector<int> g[N];
int sz[N];  // cnt[i] i的子树节点个数

ll fac[N];  // fac[i] i!
ll inv[N];  // inv[i] i! 逆元

ll n, k;
ll ans = 0;

ll fpow(ll x, ll p) {
    ll rt = 1;
    while (p) {
        if (p & 1)
            rt = rt * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return rt;
}

ll C(ll n, ll m) {
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

void dfs(int u, int fa) {
    sz[u] = 1;
    for (int v : g[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
        if (sz[v] >= k / 2 && n - sz[v] >= k / 2) {
            ans += C(sz[v], k / 2) * C(n - sz[v], k / 2) % MOD;
            ans %= MOD;
        }
        sz[u] += sz[v];
    }
}

void sol() {
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if (k % 2) {
        cout << "1\n";
        return;
    }
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv[n] = fpow(fac[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
    dfs(1, 0);
    ans *= fac[n - k] * fac[k] % MOD;
    ans %= MOD;
    ans = ans * inv[n] % MOD;
    cout << (ans + 1) % MOD << "\n";
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