#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll& i : a)
        cin >> i;
    sort(a.rbegin(), a.rend());
    auto check = [&](ll m, ll k) {
        // cout << "m: " << m << endl;
        ll nd = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < m)
                nd++;
        }
        if (nd > k)
            return false;
        ll c = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] >= m) {
                c = min(c + 2 * (a[i] - m), k - nd + 1);
            } else {
                ll u = max(0LL, 2 * (m - a[i] - c));
                if (c + u / 2 > k)
                    return false;
                c = c + u + 1;
            }
            // cout << c << " -- ";
        }
        // cout << "\n";
        return true;
    };
    while (q--) {
        int k;
        cin >> k;
        ll l = 0, r = 1e9 + 7;
        while (l < r) {
            ll m = l + r >> 1;
            if (check(m, k)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        cout << r - 1 << " ";
    }
    cout << "\n";
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