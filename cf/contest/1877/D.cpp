#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 100005
#define MOD 998244353
using namespace std;

vector<int> g[N];

ll fpow(ll x, ll p) {
    ll rt = 1;
    while (p) {
        if (p & 1)
            rt *= x, rt %= MOD;
        x *= x;
        x %= MOD;
        p >>= 1;
    }
    return rt;
}

void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1), idx(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g[a[i]].push_back(i);
    }
    ll ans = 0;
    ll c = 0, pc = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (g[i].empty())
            continue;
        for (int x : g[i]) {
            vector<int> fac;
            for (int y = 1; y * y <= x; y++) {
                if (x % y == 0) {
                    fac.push_back(y);
                    fac.push_back(x / y);
                    if (idx[y] == 0)
                        c++, idx[y] = 1;
                    if (idx[x / y] == 0)
                        c++, idx[x / y] = 1;
                }
            }
        }
        // cout << i << " " << c << endl;
        // for (int i : idx) {
        //     cout << i << " ";
        // }
        // cout << endl;
        ans += (fpow(2, n - c) * (fpow(2, c - pc) - 1 + MOD) % MOD) * i % MOD;
        ans %= MOD;
        pc = c;
    }
    cout << ans << endl;
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