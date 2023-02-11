#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll a[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll mx = -1e9 - 7, p = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        p += a[i];
        if (mx < p) {
            cout << "NO\n";
            return;
        }
        if (p < 0) {
            mx = -1e9 - 7, p = 0;
        }
    }
    cout << "YES\n";
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