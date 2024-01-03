#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 800005
#define MOD 998244353
using namespace std;

ll BIT[N];

ll ask(int x) {
    ll rt = 0;
    for (int i = x; i > 0; i -= i & -i) {
        rt += BIT[i];
    }
    return rt;
}

void add(int x) {
    for (int i = x; i < N; i += i & -i) {
        BIT[i]++;
    }
}

void sol() {
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n), q(k);
    for (auto& i : p)
        cin >> i;
    for (auto& i : q)
        cin >> i;
    int sz = max(4 * n, k);

    for (int i = 0; i <= sz; i++) {
        BIT[i] = 0;
    }
    ll ans = 0;
    for (int i = k - 1; i >= 0; i--) {
        ans += ask(q[i] + 1);
        ans %= MOD;
        add(q[i] + 1);
    }
    ans = ans * n % MOD;
    for (int i = 0; i <= sz; i++) {
        BIT[i] = 0;
    }
    for (int i = n - 1; i >= 0; i--) {
        ll c = p[i];
        for (int j = 0; j < k && 0 < c; j++, c /= 2) {
            ans += ask(c) * (k - j) % MOD;
            ans %= MOD;
        }
        c = p[i] * 2;
        for (int j = 1; j < k; j++, c *= 2) {
            if (c > 2 * n) {
                // 1+..+k-j
                ans += (1 + k - j) * (k - j) / 2 % MOD * (n - i - 1) % MOD;
                ans %= MOD;
                break;
            }
            ans += ask(c) * (k - j) % MOD;
            ans %= MOD;
        }
        add(p[i]);
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