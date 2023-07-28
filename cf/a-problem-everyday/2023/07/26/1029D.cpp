#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, k;
    cin >> n >> k;
    vector<ll> len(n), a(n);
    map<int, int> r[11];

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = x;
        while (x)
            len[i]++, x /= 10;
        r[len[i]][a[i] % k]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll x = a[i];
        for (int j = 1; j < 11; j++) {
            x *= 10;
            x %= k;
            ll t = (k - x) % k;
            if (r[j].count(t))
                ans += r[j][t];
            if (len[i] == j && (x + a[i] % k) % k == 0)
                ans--;
        }
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