#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 1000000007
using namespace std;

ll p[N];
ll a[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * 2 % MOD;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll d = a[j] - a[i];
            ll lcnt = lower_bound(a, a + n, a[i] - d) - a;
            ll rcnt = n - (lower_bound(a, a + n, a[j] + d) - a);
            ans += p[lcnt] * p[rcnt] % MOD;
            ans %= MOD;
        }
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