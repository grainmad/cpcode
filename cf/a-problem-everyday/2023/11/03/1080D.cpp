
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll opt[32] = {0};
    opt[1] = 1;
    for (int i = 2; i < 32; i++) {
        opt[i] = (opt[i - 1]) * 4 + 1;
        // cout << i << " " << opt[i] << endl;
    }
    ll n, k;
    cin >> n >> k;
    if (n > 31) {
        cout << "YES " << n - 1 << "\n";
        return;
    }
    ll c = 0, a = 1;
    for (int i = n - 1; i >= 0; i--) {
        k -= a;
        c += (a * 2 - 1) * opt[i];
        // cout << i << " " << k << " " << c << endl;
        if (0 <= k && k <= c) {
            cout << "YES " << i << "\n";
            return;
        }
        a = a * 2 + 1;
    }
    cout << "NO\n";
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
