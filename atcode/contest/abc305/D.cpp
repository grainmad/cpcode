#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll a[N];
ll p[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        p[i] += p[i - 1];
        if (i % 2 == 0) {
            p[i] += a[i] - a[i - 1];
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << i << " " << a[i] << " " << p[i] << "\n";
    // }
    int q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        ll x = upper_bound(a, a + n, l) - a - 1;
        ll y = upper_bound(a, a + n, r) - a - 1;
        // cout << x << " " << y << endl;
        ll ans = p[y] - p[x];
        if (x % 2)
            ans -= l - a[x];
        if (y % 2)
            ans += r - a[y];
        cout << ans << "\n";
    }
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