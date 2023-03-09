#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll a[N];
ll f[N][25][2];

void sol() {
    int n, k, x;
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= x;
        // cout << i << " " << a[i] << ", ";
        memset(f[i], 0, sizeof(f[i]));
    }
    // cout << endl;
    ll ans = a[0];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j) {
                f[i][j][1] =
                    max({f[i - 1][j - 1][0], f[i - 1][j - 1][1], 0LL}) + a[i] +
                    2 * x;
                if (k - j <= n - i)
                    ans = max(ans, f[i][j][1]);
            }
            if (i - 1 >= j) {
                f[i][j][0] = max({f[i - 1][j][1], f[i - 1][j][0], 0LL}) + a[i];
                if (k - j <= n - i)
                    ans = max(ans, f[i][j][0]);
            }
            // cout << i << " " << j << " 1 " << f[i][j][1] << endl;
            // cout << i << " " << j << " 0 " << f[i][j][0] << endl;
        }
    }
    cout << ans << endl;
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