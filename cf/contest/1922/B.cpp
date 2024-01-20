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
    vector<ll> a(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    ll c = 0, ans = 0;
    for (int i = 0; i <= n; i++) {
        if (a[i] > 2) {
            ans += a[i] * (a[i] - 1) * (a[i] - 2) / 6;
        }
        if (a[i] > 1) {
            ans += (a[i] - 1) * a[i] / 2 * c;
        }
        c += a[i];
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