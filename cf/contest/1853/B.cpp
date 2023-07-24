#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, k, ans = 0;
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        ll cnt = 2, p = n, q = i;
        while (p - q >= 0 && p - q <= q && cnt < k) {
            cnt++;
            int t = p - q;
            p = q;
            q = t;
        }
        if (cnt >= k)
            ans++;
    }
    cout << ans << endl;
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