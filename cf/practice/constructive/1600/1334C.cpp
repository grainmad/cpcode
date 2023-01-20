#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 300005
#define MOD 998244353
using namespace std;

ll a[N], b[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    ll cur = a[0];
    for (int i = 1; i < n; i++) {
        cur += max(a[i] - b[i - 1], 0LL);
    }
    ll ans = cur;
    for (int i = 0; i < n - 1; i++) {
        cur = cur - min(b[(i - 1 + n) % n], a[i]) + min(b[i], a[i + 1]);
        ans = min(ans, cur);
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