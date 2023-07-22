#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

/*
0 5
1 3 7 9
2 6 4 8
*/

void sol() {
    ll s, k;
    cin >> s >> k;
    ll ans = s * k;
    if (s % 10 == 5) {
        k--;
        s += s % 10;
        ans = max(ans, s * k);
    } else if (s % 10) {
        if (s % 2) {
            k--;
            s += s % 10;
            ans = max(ans, s * k);
        }
        for (int _ = 0; _ < 4; _++) {
            if (k > 0) {
                ll x = (5 * k - s) / 40;
                ans = max(ans, k * s);
                x = min(x, k / 4);
                if (x >= 0) {
                    ans = max(ans, (s + 20 * x) * (k - 4 * x));
                }
                x = min(x + 1, k / 4);
                if (x >= 0) {
                    ans = max(ans, (s + 20 * x) * (k - 4 * x));
                }
            }
            k--;
            s += s % 10;
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