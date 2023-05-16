#include <bits/stdc++.h>
// #define LOCAL
#define SINGLE_INPUT
#define ll long long
#define N 10000005
#define MOD 998244353
using namespace std;

ll a[N], b[N];

void sol() {
    int n, x, y, m, k;
    cin >> n >> a[1] >> x >> y >> m >> k;
    for (int i = 2; i <= n; i++) {
        a[i] = (a[i - 1] * x + y) % m;
    }
    for (int i = 0; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            b[j] = b[j - 1] + a[j];
            b[j] %= MOD;
        }
        swap(b, a);
    }
    ll ans = 0;
    for (int i = 1; i <= n - k + 1; i++) {
        ans ^= a[i] * (k + i - 1);
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