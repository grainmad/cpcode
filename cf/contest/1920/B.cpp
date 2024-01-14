#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + a[i];
    }
    auto getval = [&](int L, int R) {
        if (L > R)
            return 0LL;
        return p[max(R - x, L)] - p[L] + p[max(R - x, L)] - p[R];
    };
    int l = 0, r = n;
    ll ans = getval(l, r);
    while (k) {
        // cout << k << " " << ans << "\n";
        if (getval(l, r - 1) > ans)
            ans = getval(l, r - 1);
        r--;
        k--;
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