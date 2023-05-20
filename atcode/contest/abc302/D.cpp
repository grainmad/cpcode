#include <bits/stdc++.h>
// #define LOCAL
#define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

ll a[N], b[N];

void sol() {
    ll n, m, d;
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    ll ans = -1;
    for (int i = 0; i < n; i++) {
        ll r = upper_bound(b, b + m, a[i] + d) - b;
        ll l = lower_bound(b, b + m, a[i] - d) - b;
        if (r > l) {
            ans = max(ans, a[i] + b[r - 1]);
        }
    }
    cout << ans << "\n";
}
int main() {
#ifdef LOCAL
    auto start_time = clock();
    cerr << setprecision(3) << fixed;
#endif
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
#ifdef LOCAL
    auto end_time = clock();
    cerr << "Execution time: "
         << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}