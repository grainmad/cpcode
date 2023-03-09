#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 1000005
#define MOD 998244353
using namespace std;

ll fac[5000], inv_fac[5000];
vector<int> a, b;
bool nprime[N];

ll f[5000][5000];

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

void get_prime() {
    memset(nprime, 0, sizeof(nprime));
    nprime[1] = true;
    int n = (int)sqrt(N + 0.5);
    for (int i = 2; i < n; i++) {
        if (!nprime[i]) {
            for (int j = i * i; j < N; j += i) {
                nprime[j] = true;
            }
        }
    }
}

ll dfs(int x, int y) {  // [0...x]中选y个, 考虑x选不选
    if (x == -1) {
        return (y == 0);
    }
    if (f[x][y] != -1)
        return f[x][y];
    f[x][y] = dfs(x - 1, y) * inv_fac[b[x]] % MOD;
    if (y > 0) {
        f[x][y] += dfs(x - 1, y - 1) * inv_fac[b[x] - 1] % MOD;
        f[x][y] %= MOD;
    }
    // cout << x << " " << y << "=" << f[x][y] << endl;
    return f[x][y];
}

void sol() {
    get_prime();
    int n;
    cin >> n;
    fac[0] = 1;
    map<int, int> p, np;
    for (int i = 1; i <= 2 * n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        int x;
        cin >> x;
        if (nprime[x]) {
            np[x]++;
        } else {
            p[x]++;
        }
    }
    if (p.size() < n) {
        cout << "0\n";
        return;
    }
    for (auto [i, j] : np) {
        a.push_back(j);
    }
    for (auto [i, j] : p) {
        b.push_back(j);
    }
    inv_fac[2 * n] = fpow(fac[2 * n], MOD - 2);
    for (int i = 2 * n; i > 0; i--) {
        inv_fac[i - 1] = inv_fac[i] * i % MOD;
    }
    for (int i = 0; i <= b.size(); i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] = -1;
        }
    }
    // cout << dfs(b.size() - 1, n) << endl;
    ll ans = fac[n] * dfs(b.size() - 1, n) % MOD;
    for (int i = 0; i < a.size(); i++) {
        ans = ans * inv_fac[a[i]] % MOD;
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