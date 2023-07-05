#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    ll ans = 1;
    if (xb < xa && xc < xa || xb > xa && xc > xa) {
        ans += min(abs(xb - xa), abs(xc - xa));
    }
    if (yb < ya && yc < ya || yb > ya && yc > ya) {
        ans += min(abs(yb - ya), abs(yc - ya));
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