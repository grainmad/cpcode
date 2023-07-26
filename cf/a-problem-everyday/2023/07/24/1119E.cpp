
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    ll ans = 0, p = 0, u = 0;
    for (int i = 0; i < n; i++) {
        cin >> u;
        if (u >= 2 * p) {
            ans += p;
            u -= 2 * p;
            ans += u / 3;
            p = u % 3;
        } else {
            ans += u / 2;
            p -= u / 2;
            p += u % 2;
        }
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
