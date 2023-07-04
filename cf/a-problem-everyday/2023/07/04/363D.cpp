
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, m, a;
    cin >> n >> m >> a;
    vector<ll> b(n), p(m);
    for (auto& i : b)
        cin >> i;
    for (auto& i : p)
        cin >> i;
    sort(b.rbegin(), b.rend());
    sort(p.rbegin(), p.rend());
    int l = 1, r = min(n, m) + 1;
    while (l < r) {
        int c = l + r >> 1;
        // cout << l << " " << r << " " << c << endl;
        ll pub = a, pri = 0;
        for (int i = m - c, j = 0; i < m; i++, j++) {
            pri += min(b[j], p[i]);
            if (b[j] < p[i])
                pub -= p[i] - b[j];
        }
        if (pub < 0) {
            r = c;
        } else {
            l = c + 1;
        }
    }
    int c = l - 1;
    cout << c << " ";
    ll pub = a, pri = 0;
    for (int i = m - c, j = 0; i < m; i++, j++) {
        pri += min(b[j], p[i]);
        if (b[j] < p[i])
            pub -= p[i] - b[j];
    }
    cout << max(pri - pub, 0LL) << "\n";
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
