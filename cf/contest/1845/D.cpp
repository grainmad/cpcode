#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    ll ps = 0, mx = 0, d = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ps += x;
        mx = max(mx, ps);
        if (mx - ps > d) {
            d = mx - ps;
            ans = mx;
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