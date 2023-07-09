#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, k;
    cin >> n >> k;
    vector<ll> L(n), R(n);
    for (ll& i : L)
        cin >> i;
    for (ll& i : R)
        cin >> i;
    ll s = 0, c = 0, ans = 2e9 + 7;
    for (int i = 0; i < n; i++) {
        if (R[i] - L[i] == 0)
            c++;
        else
            s += R[i] - L[i] + 1;
        if (s >= k) {
            ans = min(ans, R[i] - (s - k) + 2 * (i + 1 - c));
        } else if (s + c >= k) {
            ans = min(ans, R[i] + 2 * (i + 1 - c + k - s));
        }
    }
    if (ans == 2e9 + 7) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
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